/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2020 Acid Rain Studios LLC
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 3.0 of the License, or (at your option)
* any later version.
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
* details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* @author Maxim Serebrennik
*/

#include <trManager/SystemManager.h>

#include <trManager/MessageEntityUnregistered.h>
#include <trManager/MessageEntityRegistered.h>
#include <trManager/DirectorBase.h>
#include <trManager/EntityType.h>
#include <trManager/Invokable.h>
#include <trUtil/ExceptionInvalidParameter.cpp.h>
#include <trUtil/Logging/Log.h>
#include <trBase/SmrtPtr.h>


#include <string>

namespace trManager
{
    const trUtil::RefStr SystemManager::CLASS_TYPE = trUtil::RefStr("trManager::SystemManager");

    // System Manager singleton holder
    trBase::SmrtPtr<trManager::SystemManager> SystemManager::mInstance = nullptr;
    

    //////////////////////////////////////////////////////////////////////////
    SystemManager::SystemManager(const std::string name) : BaseClass(name)
    {
    }

    //////////////////////////////////////////////////////////////////////////
    SystemManager::~SystemManager()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    trManager::SystemManager& SystemManager::GetInstance()
    {
        if (!mInstance.Valid())
        {
            mInstance = new SystemManager();
        }
        return *mInstance;
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& SystemManager::GetType() const
    {
        return CLASS_TYPE;
    }

    //////////////////////////////////////////////////////////////////////////
    bool SystemManager::SendMessage(const trManager::MessageBase& message)
    {
        mMessageQueue.push(trBase::SmrtPtr<const trManager::MessageBase>(&message));
        return true;
    }

    //////////////////////////////////////////////////////////////////////////
    bool SystemManager::SendNetworkMessage(const trManager::MessageBase& message)
    {
        mNetworkMessageQueue.push(trBase::SmrtPtr<const trManager::MessageBase>(&message));
        return true;
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::ProcessMessage(const trManager::MessageBase& message)
    {
        //Send messages to Directors
        SendMessageToDirectors(message);

        //Sends the passed in message to appropriate actors
        SendMessageToActors(message);

        //Sends the passed in message to Entities that are listening for intercepts. 
        SendMessageToListeners(message);
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::ProcessMessages()
    {
        //Go through all stored messages and send them out...
        while (!mMessageQueue.empty())
        {
            ProcessMessage(*mMessageQueue.front().Get());            

            //Removed the handled message
            mMessageQueue.pop();
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::ProcessNetworkMessages()
    {
        //Go through all stored messages and send them out...
        while (!mNetworkMessageQueue.empty())
        {
            //Send messages to Directors
            SendMessageToDirectors(*mNetworkMessageQueue.front().Get());

            //Removed the handled message
            mNetworkMessageQueue.pop();
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::RegisterForMessage(const std::string& messageType, EntityBase& listeningActor, const std::string& invokableName)
    {
        //Determine what kind of entity we are dealing with. 
        if (listeningActor.GetEntityType() == EntityType::ACTOR)
        {
            RegisterMsgWithMsgVectorMap(messageType, listeningActor, invokableName, mEntityGlobalMsgRegistrationMap);
        }
        else if (listeningActor.GetEntityType() == EntityType::ACTOR_MODULE)
        {
            RegisterMsgWithMsgVectorMap(messageType, listeningActor, invokableName, mEntityGlobalMsgRegistrationMap);
        }
        else if (listeningActor.GetEntityType() == EntityType::DIRECTOR)
        {
            RegisterMsgWithMsgMap(messageType, listeningActor, invokableName, mDirectorGlobalMsgRegistrationMap);
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::UnregisterFromMessage(const std::string& messageType, EntityBase& listeningActor)
    {
        //Determine what kind of entity we are dealing with. 
        if (listeningActor.GetEntityType() == EntityType::ACTOR)
        {
            UnregisterMsgFromMsgVectorMap(messageType, listeningActor, mEntityGlobalMsgRegistrationMap);
        }
        else if (listeningActor.GetEntityType() == EntityType::ACTOR_MODULE)
        {
            UnregisterMsgFromMsgVectorMap(messageType, listeningActor, mEntityGlobalMsgRegistrationMap);
        }
        else if (listeningActor.GetEntityType() == EntityType::DIRECTOR)
        {
            UnregisterMsgFromMsgMap(messageType, listeningActor, mDirectorGlobalMsgRegistrationMap);
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::RegisterForMessagesAboutEntity(EntityBase& listeningEntity, const trBase::UniqueId& aboutEntityId, const std::string & invokableName)
    {
        //Find the vector with message registrations, or create a new one
        std::vector<EntityInvokablePair>* msgRegistrantsPtr = &mListenerRegistrationMap[aboutEntityId];

        //Check if we already have this entity with this invokable registered
        bool registrantFound = false;
        for (unsigned int i = 0; i < msgRegistrantsPtr->size(); ++i)
        {
            if (msgRegistrantsPtr->at(i).first == &listeningEntity)
            {
                registrantFound = true;
                LOG_W("The Entity: " + listeningEntity.GetName() + " attempted to register for messages about an actor through invokable: " + invokableName + ". It is already registered through invokable: " + msgRegistrantsPtr->at(i).second)
                    break;
            }
        }

        //If the registration does not exist, make one and create an Invokable
        if (!registrantFound)
        {
            //Register the Entity-Invokable pair
            msgRegistrantsPtr->push_back(EntityInvokablePair(trBase::SmrtPtr<EntityBase>(&listeningEntity), invokableName));
            LOG_D("Registering Entity: " + listeningEntity.GetName() + " for messages about an actor through invokable: " + invokableName)
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::UnregisterFromMessagesAboutEntity(EntityBase& listeningEntity, const trBase::UniqueId& aboutEntityId)
    {
        //Find if this actor has listeners
        UUIDRegistrationVectorMap::iterator it = mListenerRegistrationMap.find(aboutEntityId);
        if (it != mListenerRegistrationMap.end())
        {
            //Find if the entity  is registered
            std::vector<EntityInvokablePair>* msgRegistrantsPtr = &it->second;
            for (unsigned int i = 0; i < msgRegistrantsPtr->size(); ++i)
            {
                //Unregister the entity
                if (msgRegistrantsPtr->at(i).first == &listeningEntity)
                {
                    msgRegistrantsPtr->erase(msgRegistrantsPtr->begin() + i);
                    LOG_D("Unregistered Entity: " + listeningEntity.GetName() + " from listening to messages about an actor.")
                    break;
                }
            }

            //If no more entities are registered for this message, remove message entry
            if (msgRegistrantsPtr->size() == 0)
            {
                mListenerRegistrationMap.erase(it);
            }
        }
        else
        {
            LOG_W("Invalid attempt to unregister the Entity: " + listeningEntity.GetName() + " from listening to messages about an actor.")
        }
    }

    //////////////////////////////////////////////////////////////////////////
    bool SystemManager::RegisterActor(trManager::EntityBase& actor)
    {
        //Check if the actor is already registered
        if (FindActor(actor.GetUUID()) != nullptr)
        {
            std::string errorText = "An actor/actor module with the same ID is already registered with the System Manager.";
            LOG_E(errorText);
            throw trUtil::ExceptionInvalidParameter(errorText, __FILE__, __LINE__);
            return false;
        }

        //Add the actor to the storage containers.
        trBase::SmrtPtr<trManager::EntityBase> newActor = &actor;

        mActorList.push_back(newActor);
        mActorIDMap[actor.GetUUID()] = newActor;
        
        //Set the director registration status
        actor.SetSystemManager(this);
        actor.SetRegistration(true);

        //Call the OnAddedToSysMan callback. 
        actor.OnAddedToSysMan();

        //Notify everyone that a new Entity was added
        SendMessage(*new trManager::MessageEntityRegistered(&GetUUID(), &actor.GetUUID(), &actor.GetType(), &actor.GetName()));
        LOG_D("Registered " + actor.GetName() + " of type: " + actor.GetType() + " with System Manager.")

        return true;
    }

    //////////////////////////////////////////////////////////////////////////
    bool SystemManager::UnregisterActor(trManager::EntityBase& actor)
    {
        //Find the Actor instance with the same passed in reference
        ActorList::iterator found;
        for (found = mActorList.begin(); found != mActorList.end(); ++found)
        {
            if (found->Get() == &actor)
            {
                //We found the actor we need
                break;
            }
        }

        if (found != mActorList.end())
        {
            //Add the entity to the delete list.
            mEntityDeleteList.push_back(trBase::SmrtPtr<trManager::EntityBase>(static_cast<trManager::EntityBase*>(found->Get())));

            UnregisterActorFromGlobalMessages(*found->Get());   // Unregister the entity from all messages
            UnregisterEntityFromAboutMessages(*found->Get());   // Unregister the entity from all About messages
            
            mActorIDMap.erase((*found)->GetUUID());             // Erase the node from the list by ID key
            mActorList.erase(found);                            // Erase the node from the list
        
            //Notify everyone that an Entity was removed
            SendMessage(*new trManager::MessageEntityUnregistered(&GetUUID(), &actor.GetUUID(), &actor.GetType(), &actor.GetName()));
            LOG_D("Unregistered " + actor.GetName() + " of type: " + actor.GetType() + " from System Manager.")

            return true;
        }
        else
        {
            LOG_W("Attempted to unregister a none registered Actor: " + actor.GetName())
            return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    bool SystemManager::UnregisterActor(const trBase::UniqueId& id)
    {
        return UnregisterActor(*FindActor(id));
    }

    //////////////////////////////////////////////////////////////////////////
    bool SystemManager::UnregisterAllActors()
    {
        while (!mActorList.empty())
        {
            UnregisterActor(*mActorList.back());
        }
        return true;
    }

    //////////////////////////////////////////////////////////////////////////
    trManager::EntityBase* SystemManager::FindActor(const trBase::UniqueId& id)
    {
        ActorIDMap::const_iterator it = mActorIDMap.find(id);
        if (it != mActorIDMap.end()) //Make sure we have a found value and are not at the end
        {
            //Return the stored value
            return it->second.Get();
        }
        else
        {
            return nullptr;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    std::vector<trManager::EntityBase*> SystemManager::FindActorsByType(const std::string& actorType)
    {
        std::vector<trManager::EntityBase*> actorList;

        for (trBase::SmrtPtr<trManager::EntityBase> i : mActorList)
        {            
            if (i->GetType() == actorType)
            {
                if (i->GetEntityType() == EntityType::ACTOR)
                {
                    actorList.push_back(i);
                }
            }
        }

        return actorList;
    }

    //////////////////////////////////////////////////////////////////////////
    std::vector<trManager::EntityBase*> SystemManager::FindActorsByName(const std::string& actorName)
    {
        std::vector<trManager::EntityBase*> actorList;

        for (trBase::SmrtPtr<trManager::EntityBase> i : mActorList)
        {            
            if (i->GetName() == actorName)
            {
                if (i->GetEntityType() == EntityType::ACTOR)
                {
                    actorList.push_back(i);
                }
            }
        }

        return actorList;
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::SendMessageToDirectors(const trManager::MessageBase& message)
    {
        //Check to see if we need to skip the Directors
        if (!message.GetIsDirect())
        {
            EntityInvokableMap* entityInvokableMapPtr = nullptr;
            EntityInvokableMap::iterator entityInvokableIt;

            //Find this messages listener list
            MessageRegistrationMap::iterator listenerIt;
            listenerIt = mDirectorGlobalMsgRegistrationMap.find(const_cast<std::string*>(&message.GetMessageType()));

            //Send messages to all Directors in the list
            trBase::SmrtPtr<trManager::EntityBase> directorRef;
            for (trBase::SmrtPtr<trManager::EntityBase> dir : mDirectorList)
            {
                //Make sure the director is not sending a message to itself
                if (dir->GetUUID() != *message.GetFromActorID())
                {                   
                    directorRef = static_cast<trManager::EntityBase*>(dir.Get());

                    //If the listener list is not empty
                    if (listenerIt != mDirectorGlobalMsgRegistrationMap.end())
                    {
                        //Find if the entity is registered
                        entityInvokableMapPtr = &listenerIt->second;

                        //Check if the Director is in the listener list         
                        entityInvokableIt = entityInvokableMapPtr->find(directorRef);
                        if (entityInvokableIt != entityInvokableMapPtr->end())
                        {
                            //If the director is on the list, send the message to the registered Invokable                           
                            CallInvokable(message, entityInvokableIt->second, *directorRef);
                        }
                        else
                        {
                            //If the Director is not in the listener list, send the message to the default OnMessage function
                            CallInvokable(message, EntityBase::ON_MESSAGE_INVOKABLE, *directorRef);
                        }
                    }
                    else
                    {
                        //If the messages listener list is empty, use the directors default OnMessage function
                        CallInvokable(message, EntityBase::ON_MESSAGE_INVOKABLE, *directorRef);
                    }
                }
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::SendMessageToActors(const trManager::MessageBase& message)
    {
        //Find this messages listener list
        MessageRegistrationVectorMap::iterator listenerIt = mEntityGlobalMsgRegistrationMap.find(const_cast<std::string*>(&message.GetMessageType()));

        //Check if anyone registered for this message
        if (listenerIt != mEntityGlobalMsgRegistrationMap.end())
        {
            //Go through the listener list, and send the message to each listening actor 
            std::vector<EntityInvokablePair>* listenerList = &listenerIt->second;
            for (EntityInvokablePair ent : *listenerList)
            {
                //Make sure the entity is not sending a message to itself
                if (ent.first->GetUUID() != *message.GetFromActorID())
                {
                    CallInvokable(message, ent.second, *ent.first.Get());
                }                
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::SendMessageToListeners(const trManager::MessageBase& message)
    {
        if (message.GetAboutActorID() != nullptr)
        {
            //Find this messages listener list
            UUIDRegistrationVectorMap::iterator listenerIt = mListenerRegistrationMap.find(*message.GetAboutActorID());

            //Check if anyone registered for this message
            if (listenerIt != mListenerRegistrationMap.end())
            {
                //Go through the listener list, and send the message to each listening actor 
                std::vector<EntityInvokablePair>* listenerList = &listenerIt->second;
                for (EntityInvokablePair ent : *listenerList)
                {
                    //Make sure the entity is not sending a message to itself
                    if (ent.first->GetUUID() != *message.GetFromActorID())
                    {
                        CallInvokable(message, ent.second, *ent.first.Get());
                    }
                }
            }
        }        
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::SendGlobalyRegisteredMessage(const trManager::MessageBase & message)
    {
        MessageRegistrationVectorMap::iterator it;

        //Find if this message has listeners
        it = mEntityGlobalMsgRegistrationMap.find(const_cast<std::string*>(&message.GetMessageType()));
        if (it != mEntityGlobalMsgRegistrationMap.end())
        {
            //Create an invokable pointer
            trManager::Invokable* invokablePtr = nullptr;
           
            //Get the vector of registered Entities for the message <entity, invokableName>
            std::vector<EntityInvokablePair>* msgRegistrantsPtr = &it->second;

            for (unsigned int i = 0; i < msgRegistrantsPtr->size(); ++i)
            {
                //Grab a hold of the entity in a smart pointer
                trBase::SmrtPtr<trManager::EntityBase> actor = msgRegistrantsPtr->at(i).first;

                if (actor->IsRegistered())
                {
                    //Get the Invokable from the Entity by passing the Invokables name. 
                    invokablePtr = actor->GetInvokable(msgRegistrantsPtr->at(i).second);

                    if (invokablePtr != nullptr)
                    {
                        invokablePtr->Invoke(message);
                    }
                }

            }
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::CallInvokable(const trManager::MessageBase& message, const std::string& invokableName, trManager::EntityBase& entity)
    {
        Invokable* invokablePtr = entity.GetInvokable(invokableName);

        //Check if requested Invokable exists
        if (invokablePtr != nullptr)
        {
            LOG_D("Calling Invokable: " + invokablePtr->GetName() + " on " + entity.GetName())
            invokablePtr->Invoke(message);
        }
        else
        {
            LOG_E("Invokable: " + invokableName + " was called, but the Entity: " + entity.GetName() + " does not have an invokable by that name.")
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::UnregisterActorFromGlobalMessages(trManager::EntityBase& actor)
    {
        std::vector<EntityInvokablePair>* msgRegistrantsPtr = nullptr;

        //Iterate through the Message-EntityInvokablePair registration map for each message type
        //MessageRegistrationVectorMap::iterator listenerIt
        for (auto&& listenerIt = mEntityGlobalMsgRegistrationMap.begin(); listenerIt != mEntityGlobalMsgRegistrationMap.end();)
        {
            //Iterate through the vector of Entities-Invokables
            msgRegistrantsPtr = &listenerIt->second;
            for (unsigned int i = 0; i<msgRegistrantsPtr->size(); ++i)
            {
                //If we found a matching entity registration, delete it
                if (msgRegistrantsPtr->at(i).first == &actor)
                {
                    msgRegistrantsPtr->erase(msgRegistrantsPtr->begin() + i);
                    break;
                }
            }

            //If the Entities-Invokables vector is empty, the message registration should be removed. 
            if (msgRegistrantsPtr->empty())
            {
                listenerIt = mEntityGlobalMsgRegistrationMap.erase(listenerIt);
            }
            else
            {
                ++listenerIt;
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::UnregisterDirectorFromGlobalMessages(trManager::EntityBase& director)
    {
        if (director.GetEntityType() == EntityType::DIRECTOR)
        {
            //Iterate through the Message-Entity registration map
            //MessageRegistrationMap::iterator listenerIt
            for (auto&& listenerIt = mDirectorGlobalMsgRegistrationMap.begin(); listenerIt != mDirectorGlobalMsgRegistrationMap.end();)
            {
                //Iterate through Entity-Invokable map that relates to the given message
                //EntityInvokableMap::iterator directorIt
                for (auto&& directorIt = listenerIt->second.begin(); directorIt != listenerIt->second.end();)
                {
                    //If we found a matching director registration, delete it
                    if (directorIt->first->GetUUID() == director.GetUUID())
                    {
                        //Delete the registration, and exit the loop since there should be only one entity registration per message
                        directorIt = listenerIt->second.erase(directorIt);
                        break;
                    }
                    else
                    {
                        ++directorIt;
                    }
                }

                //If we just deleted the last registrant for this message, delete the message registration
                if (listenerIt->second.empty())
                {
                    listenerIt = mDirectorGlobalMsgRegistrationMap.erase(listenerIt);
                }
                else
                {
                    ++listenerIt;
                }
            }
        }
        else
        {
            LOG_E("The Entity: " + director.GetName() + " is not a Director.")
        }        
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::UnregisterEntityFromAboutMessages(trManager::EntityBase& listeningEntity)
    {
        std::vector<EntityInvokablePair>* msgRegistrantsPtr = nullptr;

        //Iterate through all Entities one by one to access their listener lists. 
        for (auto&& listenerIt = mListenerRegistrationMap.begin(); listenerIt != mListenerRegistrationMap.end();)
        {
            //Iterate through the vector of Entities-Invokables
            msgRegistrantsPtr = &listenerIt->second;
            for (unsigned int i = 0; i<msgRegistrantsPtr->size(); ++i)
            {
                //If we found a matching entity registration, delete it
                if (msgRegistrantsPtr->at(i).first == &listeningEntity)
                {
                    msgRegistrantsPtr->erase(msgRegistrantsPtr->begin() + i);
                    break;
                }
            }

            //If the Entities-Invokables vector is empty, the message registration should be removed. 
            if (msgRegistrantsPtr->empty())
            {
                listenerIt = mListenerRegistrationMap.erase(listenerIt);
            }
            else
            {
                ++listenerIt;
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::RegisterMsgWithMsgVectorMap(const std::string& messageType, EntityBase& listeningEntity, const std::string& invokableName, MessageRegistrationVectorMap& messageMap)
    {
        //Find the vector with message registrations, or create a new one
        std::vector<EntityInvokablePair>* msgRegistrantsPtr = &messageMap[const_cast<std::string*>(&messageType)];

        //Check if we already have this entity with this invokable registered
        bool registrantFound = false;
        for (unsigned int i = 0; i < msgRegistrantsPtr->size(); ++i)
        {
            if (msgRegistrantsPtr->at(i).first == &listeningEntity)
            {
                registrantFound = true;
                LOG_W("The Entity: " + listeningEntity.GetName() + " attempted to register for message: " + messageType + " through invokable: " + invokableName + ". It is already registered through invokable: " + msgRegistrantsPtr->at(i).second)
                break;
            }
        }

        //If the registration does not exist, make one and create an Invokable
        if (!registrantFound)
        {            
            //Register the Entity-Invokable pair
            msgRegistrantsPtr->push_back(EntityInvokablePair(trBase::SmrtPtr<EntityBase>(&listeningEntity), invokableName));
            LOG_D("Registering Entity: " + listeningEntity.GetName() + " for message: " + messageType + " through invokable: " + invokableName)
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::UnregisterMsgFromMsgVectorMap(const std::string& messageType, EntityBase& listeningEntity, MessageRegistrationVectorMap& messageMap)
    {
        //Find if this message has listeners
        MessageRegistrationVectorMap::iterator it = messageMap.find(const_cast<std::string*>(&messageType));
        if (it != messageMap.end())
        {
            //Find if the entity  is registered
            std::vector<EntityInvokablePair>* msgRegistrantsPtr = &it->second;
            for (unsigned int i = 0; i < msgRegistrantsPtr->size(); ++i)
            {
                //Unregister the entity
                if (msgRegistrantsPtr->at(i).first == &listeningEntity)
                {
                    msgRegistrantsPtr->erase(msgRegistrantsPtr->begin() + i);
                    LOG_D("Unregistered Entity: " + listeningEntity.GetName() + " from message: " + messageType)
                    break;
                }
            }

            //If no more entities are registered for this message, remove message entry
            if (msgRegistrantsPtr->size() == 0)
            {
                messageMap.erase(it);
            }
        }
        else
        {
            LOG_W("Invalid attempt to unregister the Entity: " + listeningEntity.GetName() + " from message: " + messageType)
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::RegisterMsgWithMsgMap(const std::string& messageType, EntityBase& listeningEntity, const std::string& invokableName, MessageRegistrationMap& messageMap)
    {
        //Find the map with message registrations, or create a new one
        EntityInvokableMap* entityInvokableMapPtr = &messageMap[const_cast<std::string*>(&messageType)];

        //Check if we already have this entity with this invokable registered
        trBase::SmrtPtr<trManager::EntityBase> listeningEnt = &listeningEntity;
        EntityInvokableMap::iterator it = entityInvokableMapPtr->find(listeningEnt);
        if (it == entityInvokableMapPtr->end())
        {
            //If the registration does not exist, make one.
            entityInvokableMapPtr->insert(std::make_pair(listeningEnt, invokableName));
            LOG_D("Registering Entity: " + listeningEnt->GetName() + " for message: " + messageType + " through invokable: " + invokableName)
        }
        else
        {
            LOG_W("The Entity: " + listeningEnt->GetName() + " attempted to register for message: " + messageType + " through invokable: " + invokableName + ". It is already registered through invokable: " + it->second)
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::UnregisterMsgFromMsgMap(const std::string& messageType, EntityBase& listeningEntity, MessageRegistrationMap& messageMap)
    {
        //Find the map with message registrations
        MessageRegistrationMap::iterator it = messageMap.find(const_cast<std::string*>(&messageType));
        if (it != messageMap.end())
        {
            //If message registration exists, check if the given Entity is registered
            EntityInvokableMap* entityMap = &it->second;
            for (EntityInvokableMap::iterator i = entityMap->begin(); i != entityMap->end(); ++i)
            {
                if (i->first == &listeningEntity)
                {
                    //If the given entity is registered, delete it
                    entityMap->erase(i);
                    LOG_D("Unregistered Entity: " + listeningEntity.GetName() + " from message: " + messageType)

                    //If this was the last registration in the map, delete the whole map
                    if (entityMap->empty())
                    {
                        messageMap.erase(it);
                    }
                    break;
                }
                else
                {
                    LOG_W("Invalid attempt to unregister the Entity: " + listeningEntity.GetName() + " from message: " + messageType)
                }
            }
        }
        else
        {
            LOG_W("Invalid attempt to unregister the Entity: " + listeningEntity.GetName() + " from message: " + messageType)
        }
    }

    //////////////////////////////////////////////////////////////////////////
    bool SystemManager::RegisterDirector(trManager::EntityBase& director, trManager::DirectorPriority& priority)
    {
        if (director.GetEntityType() == EntityType::DIRECTOR)
        {
            //Check if the director is already registered
            if (FindDirector(director.GetName()) != nullptr)
            {
                std::string errorText = "A director with the name: " + director.GetName() + " is already registered with the System Manager.";
                LOG_E(errorText);
                throw trUtil::ExceptionInvalidParameter(errorText, __FILE__, __LINE__);
                return false;
            }

            //Set the director Priority, overwriting anything that was there. 
            static_cast<trManager::DirectorBase*>(&director)->SetDirectorPriority(&priority);

            //Add the director to the storage containers.
            trBase::SmrtPtr<trManager::EntityBase> newDirector = &director;

            mDirectorList.push_back(newDirector);
            mDirectorIDMap[director.GetUUID()] = newDirector;
            mDirectorNameMap[director.GetName()] = newDirector;

            mDirectorList.sort(DirectorBase::CompareComponentPriority); //Sort the Director List

                                                                        // Set the director registration status
            director.SetSystemManager(this);
            director.SetRegistration(true);

            //Call the OnAddedToSysMan callback. 
            director.OnAddedToSysMan();

            //Notify everyone that a new Entity was added
            SendMessage(*new trManager::MessageEntityRegistered(&GetUUID(), &director.GetUUID(), &director.GetType(), &director.GetName()));
            LOG_D("Registered " + director.GetName() + " of type: " + director.GetType() + " with System Manager.")

            return true;
        }
        else
        {
            LOG_E("The Entity: " + director.GetName() + " is not a Director.")
            return false;
        }        
    }

    //////////////////////////////////////////////////////////////////////////
    bool SystemManager::UnregisterDirector(trManager::EntityBase &director)
    {
        if (director.GetEntityType() == EntityType::DIRECTOR)
        {
            // Find the Director instance with the same passed in reference
            //DirectorList::iterator found = std::find(mDirectorList.end(), mDirectorList.begin(), &director);
            DirectorList::iterator found;
            for (found = mDirectorList.begin(); found != mDirectorList.end(); ++found)
            {
                if (found->Get() == &director)
                {
                    //We found the director we need
                    break;
                }
            }

            if (found != mDirectorList.end())
            {
                //Add the entity to the delete list.
                mEntityDeleteList.push_back(trBase::SmrtPtr<trManager::EntityBase>(static_cast<trManager::EntityBase*>(found->Get())));

                UnregisterDirectorFromGlobalMessages(*found->Get());// Unregister the director from all messages
                UnregisterEntityFromAboutMessages(*found->Get());   // Unregister the director from all About messages

                mDirectorIDMap.erase((*found)->GetUUID());          // Erase the node from the list by ID key
                mDirectorNameMap.erase((*found)->GetName());        // Erase the node from the list by Name key
                mDirectorList.erase(found);                         // Erase the node from the list            

                                                                    //Notify everyone that an Entity was removed
                SendMessage(*new trManager::MessageEntityUnregistered(&GetUUID(), &director.GetUUID(), &director.GetType(), &director.GetName()));
                LOG_D("Unregistered " + director.GetName() + " of type: " + director.GetType() + " from System Manager.")

                return true;
            }
            else
            {
                LOG_W("Attempted to unregister a none registered Director: " + director.GetName())
                return false;
            }
        }
        else
        {
            LOG_E("The EntityBase: " + director.GetName() + " is not a Director.")
            return false;
        }        
    }

    //////////////////////////////////////////////////////////////////////////
    bool SystemManager::UnregisterDirector(const trBase::UniqueId& id)
    {
        return UnregisterDirector(*FindDirector(id));
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::UnregisterAllDirectors()
    {
        while (!mDirectorList.empty())
        {
            UnregisterDirector(*mDirectorList.back());
        }
    }

    //////////////////////////////////////////////////////////////////////////
    trManager::EntityBase* SystemManager::FindDirector(const trBase::UniqueId& id) const
    {
        DirectorIDMap::const_iterator it = mDirectorIDMap.find(id);
        if (it != mDirectorIDMap.end()) //Make sure we have a found value and are not at the end
        {
            //Return the stored value
            return it->second.Get();
        }
        else
        {
            return nullptr;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    trManager::EntityBase* SystemManager::FindDirector(const std::string& name) const 
    {
        DirectorNameMap::const_iterator it = mDirectorNameMap.find(name);
        if (it != mDirectorNameMap.end()) //Make sure we have a found value and are not at the end
        {
            //Return the stored value
            return it->second.Get();
        }
        else
        {
            return nullptr;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    std::vector<trManager::EntityBase*> SystemManager::FindDirectors(const std::string& type) const
    {
        std::vector<trManager::EntityBase*> directorList;
        
        for (trBase::SmrtPtr<trManager::EntityBase> i : mDirectorList)
        {
            if (i->GetType() == type)
            {
                directorList.push_back(i);
            }
        }       

        return directorList;
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::RemoveMarkedEntities()
    {
        for (int i = static_cast<int>(mEntityDeleteList.size()-1); i >= 0 ; --i)
        {
            // Set the entities De-registration options
            mEntityDeleteList[i]->SetSystemManager(nullptr);
            mEntityDeleteList[i]->SetRegistration(false);
            mEntityDeleteList[i]->OnRemovedFromSysMan();
            mEntityDeleteList.pop_back();
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void SystemManager::ShutDown()
    {
        LOG_D("Shutting down System Manager")

        LOG_D("Processing Last Messages")
        ProcessMessages(); //Send all left over messages before shutting down

        LOG_D("Unregistering All Directors")
        UnregisterAllDirectors(); //Unregister all Directors

        LOG_D("Unregistering All Actors and Actor Modules")
        UnregisterAllActors(); //Unregister all Actors and Actor Modules

        LOG_D("Removing all marked entities")
        RemoveMarkedEntities();
    }
}
