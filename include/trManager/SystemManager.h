/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
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
* Author: Maxim Serebrennik
*/

#pragma once

#include "Export.h"

#include <trManager/DirectorPriority.h>
#include <trManager/MessageBase.h>
#include <trManager/EntityBase.h>
#include <trUtil/HashMap.h>
#include <trBase/UniqueId.h>
#include <trBase/SmrtPtr.h>
#include <trBase/Base.h>

#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <list>

namespace trManager
{
    /**
    * System Manager class is a singleton that is responsible for all message routing and basic 
    * operations between actors and directors throughout TR. 
    */
    class TR_MANAGER_EXPORT SystemManager : public trBase::Base
    {
    public:

        typedef trBase::Base BaseClass;                 /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE;         /// Holds the class type name for efficient comparisons

        /**
         * @fn  static trManager::SystemManager& SystemManager::GetInstance();
         *
         * @brief   Returns the Instance of the System Manager Singleton.
         *
         * @return  The instance.
         */
        static trManager::SystemManager& GetInstance();

        /**
         * @fn  virtual const std::string& SystemManager::GetType() const override;
         *
         * @brief   Returns the class type.
         *
         * @return  The type.
         */
        virtual const std::string& GetType() const override;

        /**
         * @fn  virtual bool SystemManager::SendMessage(const trManager::MessageBase& message);
         *
         * @brief   Send a message to an Actor, Actor Module, or a Director.
         *
         * @param   message The message.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool SendMessage(const trManager::MessageBase& message);

        /**
         * @fn  virtual bool SystemManager::SendNetworkMessage(const trManager::MessageBase& message);
         *
         * @brief   Send a Network message to an Actor, Actor Module, or a Director.
         *
         * @param   message The message.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool SendNetworkMessage(const trManager::MessageBase& message);

        /**
         * @fn  virtual void SystemManager::ProcessMessage(const trManager::MessageBase& message);
         *
         * @brief   Immediately processes the passed in message. Usually used to manipulate the system
         *          flow.
         *
         * @param   message The message.
         */
        virtual void ProcessMessage(const trManager::MessageBase& message);

        /**
         * @fn  virtual void SystemManager::ProcessMessages();
         *
         * @brief   Sends out all the messages from the message queue. This is for system use only.
         */
        virtual void ProcessMessages();

        /**
         * @fn  virtual void SystemManager::ProcessNetworkMessages();
         *
         * @brief   Sends out all the network messages from the message queue. This is for system use
         *          only.
         */
        virtual void ProcessNetworkMessages();

        /**
         * @fn  virtual void SystemManager::RegisterForMessage(const std::string& messageType, EntityBase& listeningActor, const std::string& invokableName);
         *
         * @brief   Registers an actor for messages.
         *
         * @param           messageType     Type of the message.
         * @param [in,out]  listeningActor  The Listening actor that will receive the message.
         * @param           invokableName   Name of the invokable that the message will be routed to.
         */
        virtual void RegisterForMessage(const std::string& messageType, EntityBase& listeningActor, const std::string& invokableName);

        /**
         * @fn  virtual void SystemManager::UnregisterFromMessage(const std::string& messageType, EntityBase& listeningActor);
         *
         * @brief   Unregister an actor that is listening for a given message.
         *
         * @param           messageType     Type of the message.
         * @param [in,out]  listeningActor  The listening actor.
         */
        virtual void UnregisterFromMessage(const std::string& messageType, EntityBase& listeningActor);

        /**
         * @fn  virtual void SystemManager::RegisterForMessagesAboutEntity(EntityBase& listeningEntity, const trBase::UniqueId& aboutEntityId, const std::string& invokableName);
         *
         * @brief   Registers for messages about a specific actor.
         *
         * @param [in,out]  listeningEntity The Listening entity that will receive the message.
         * @param           aboutEntityId   Identifier for the about entity.
         * @param           invokableName   Name of the invokable.
         */
        virtual void RegisterForMessagesAboutEntity(EntityBase& listeningEntity, const trBase::UniqueId& aboutEntityId, const std::string& invokableName);

        /**
         * @fn  virtual void SystemManager::UnregisterFromMessagesAboutEntity(EntityBase& listeningEntity, const trBase::UniqueId& aboutEntityId);
         *
         * @brief   Unregisters from messages about a specific actor.
         *
         * @param [in,out]  listeningEntity The listening entity.
         * @param           aboutEntityId   Identifier for the about entity.
         */
        virtual void UnregisterFromMessagesAboutEntity(EntityBase& listeningEntity, const trBase::UniqueId& aboutEntityId);

        /**
         * @fn  virtual bool SystemManager::RegisterActor(trManager::EntityBase& actor);
         *
         * @brief   Registers an Actor or Actor Module with the System Manager.
         *
         * @param [in,out]  actor   The actor.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool RegisterActor(trManager::EntityBase& actor);

        /**
         * @fn  virtual bool SystemManager::UnregisterActor(trManager::EntityBase& actor);
         *
         * @brief   Disconnects the actor from the System Manager.
         *
         * @param [in,out]  actor   The actor.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool UnregisterActor(trManager::EntityBase& actor);

        /**
         * @fn  virtual bool SystemManager::UnregisterActor(const trBase::UniqueId& id);
         *
         * @brief   Disconnects the actor from the System Manager by using the actors ID.
         *
         * @param   id  The identifier.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool UnregisterActor(const trBase::UniqueId& id);

        /**
         * @fn  virtual bool SystemManager::UnregisterAllActors();
         *
         * @brief   Unregisters all actors from the System Manager.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool UnregisterAllActors();

        /**
         * @fn  virtual trManager::EntityBase* SystemManager::FindActor(const trBase::UniqueId& id);
         *
         * @brief   Searches for an actor or actor module with the given ID.
         *
         * @param   id  The unique identifier.
         *
         * @return  Null if it fails, else the found actor.
         */
        virtual trManager::EntityBase* FindActor(const trBase::UniqueId& id);

        /**
         * @fn  virtual std::vector<trManager::EntityBase*> SystemManager::FindActorsByType(const std::string& actorType);
         *
         * @brief   Searches for all actors of a given type. WARNING: This functions is slow.
         *
         * @param   actorType   Type of the actor.
         *
         * @return  Empty vector if it fails, else a vector of found actors.
         */
        virtual std::vector<trManager::EntityBase*> FindActorsByType(const std::string& actorType);

        /**
         * @fn  virtual std::vector<trManager::EntityBase*> SystemManager::FindActorsByName(const std::string& actorName);
         *
         * @brief   Searches for all actors by a given name. WARNING: This function is slow.
         *
         * @param   actorName   Name of the actor.
         *
         * @return  Empty vector if it fails, else a vector of found actors.
         */
        virtual std::vector<trManager::EntityBase*> FindActorsByName(const std::string& actorName);

        /**
         * @fn  virtual bool SystemManager::RegisterDirector(trManager::EntityBase& director, trManager::DirectorPriority& priority = trManager::DirectorPriority::NORMAL);
         *
         * @brief   Adds a director to the list of components the system manager will communicate with.
         *
         * @exception   trUtil::InvalidParameterException   if the director lacks a unique name.
         *
         * @param [in,out]  director    The director to add.
         * @param [in,out]  priority    (Optional) The priority of the director.  This translates into
         *                              the order of message delivery.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool RegisterDirector(trManager::EntityBase& director, trManager::DirectorPriority& priority = trManager::DirectorPriority::NORMAL);

        /**
         * @fn  virtual bool SystemManager::UnregisterDirector(trManager::EntityBase& director);
         *
         * @brief   Disconnects the director from System Manager.
         *
         * @param [in,out]  director    The director.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool UnregisterDirector(trManager::EntityBase& director);

        /**
         * @fn  virtual bool SystemManager::UnregisterDirector(const trBase::UniqueId& id);
         *
         * @brief   Disconnects the director from System Manager by using it's ID.
         *
         * @param   id  The identifier.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool UnregisterDirector(const trBase::UniqueId& id);

        /**
         * @fn  virtual void SystemManager::UnregisterAllDirectors();
         *
         * @brief   Unregisters all the directors from System Manager.
         */
        virtual void UnregisterAllDirectors();

        /**
         * @fn  virtual trManager::EntityBase* SystemManager::FindDirector(const trBase::UniqueId& id) const;
         *
         * @brief   Finds and returns the director with the given ID.
         *
         * @param   id  The identifier.
         *
         * @return  Null if it fails, else the found director.
         */
        virtual trManager::EntityBase* FindDirector(const trBase::UniqueId& id) const;

        /**
         * @fn  virtual trManager::EntityBase* SystemManager::FindDirector(const std::string& name) const;
         *
         * @brief   Finds and returns the director with the given Name. The Directors name is unique, so
         *          only one Director with the right name can exist.
         *
         * @param   name    The name.
         *
         * @return  Null if it fails, else the found director.
         */
        virtual trManager::EntityBase* FindDirector(const std::string& name) const;

        /**
         * @fn  virtual std::vector<trManager::EntityBase*> SystemManager::FindDirectors(const std::string& type) const;
         *
         * @brief   Finds and returns all the Directors of a given type. WARNING: This function is slow.
         *
         * @param   type    The type.
         *
         * @return  Null if it fails, else the found directors.
         */
        virtual std::vector<trManager::EntityBase*> FindDirectors(const std::string& type) const;

        /**
         * @fn  virtual void SystemManager::RemoveMarkedEntities();
         *
         * @brief   Removes all entities that were marked to be unregistered. This is for system use only,
         *          and should not be called directly by the user.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual void RemoveMarkedEntities();

        /**
         * @fn  virtual void SystemManager::ShutDown();
         *
         * @brief   Shuts down the System Manager and unregisters all entities.
         */
        virtual void ShutDown();

    protected:

        /**
         * @fn  SystemManager::SystemManager(const std::string name = CLASS_TYPE);
         *
         * @brief   Ctor.
         *
         * @param   name    (Optional) The name.
         */
        SystemManager(const std::string name = CLASS_TYPE);

        /**
         * @fn  SystemManager::~SystemManager();
         *
         * @brief   Dtor.
         */
        ~SystemManager();

        /**
         * @fn  virtual void SystemManager::SendMessageToDirectors(const trManager::MessageBase& message);
         *
         * @brief   Send the passed in message to all registered Directors.
         *
         * @param   message The message.
         */
        virtual void SendMessageToDirectors(const trManager::MessageBase& message);

        /**
         * @fn  virtual void SystemManager::SendMessageToActors(const trManager::MessageBase& message);
         *
         * @brief   Sends the passed in message to appropriate actors.
         *
         * @param   message The message.
         */
        virtual void SendMessageToActors(const trManager::MessageBase& message);

        /**
         * @fn  virtual void SystemManager::SendMessageToListeners(const trManager::MessageBase& message);
         *
         * @brief   Sends a message to entities that are listening for messages about other actors.
         *
         * @param   message The message.
         */
        virtual void SendMessageToListeners(const trManager::MessageBase& message);

        /**
         * @fn  virtual void SystemManager::SendGlobalyRegisteredMessage(const trManager::MessageBase& message);
         *
         * @brief   Sends out a message to all entities who had a global registration for it.
         *
         * @param   message The message.
         */
        virtual void SendGlobalyRegisteredMessage(const trManager::MessageBase& message);

        /**
         * @fn  virtual void SystemManager::CallInvokable(const trManager::MessageBase& message, const std::string& invokableName, trManager::EntityBase& entity);
         *
         * @brief   Utility function. Calls the passed in Invokable on the passed in EntityBase.
         *
         * @param           message         The message to pass to the Invokable.
         * @param           invokableName   Name of the invokable.
         * @param [in,out]  entity          The EntityBase on which to call the Invokable.
         */
        virtual void CallInvokable(const trManager::MessageBase& message, const std::string& invokableName, trManager::EntityBase& entity);

        /**
         * @fn  virtual void SystemManager::UnregisterActorFromGlobalMessages(trManager::EntityBase& actor);
         *
         * @brief   Unregisters the actor/actor module from all messages that have registrations.
         *
         * @param [in,out]  actor   The actor.
         */
        virtual void UnregisterActorFromGlobalMessages(trManager::EntityBase& actor);

        /**
         * @fn  virtual void SystemManager::UnregisterDirectorFromGlobalMessages(trManager::EntityBase& director);
         *
         * @brief   Unregisters the director from all messages that have registrations.
         *
         * @param [in,out]  director    The director.
         */
        virtual void UnregisterDirectorFromGlobalMessages(trManager::EntityBase& director);

        /**
         * @fn  virtual void SystemManager::UnregisterEntityFromAboutMessages(trManager::EntityBase& listeningEntity);
         *
         * @brief   Unregisters the entity from about messages about another actor.
         *
         * @param [in,out]  listeningEntity The entity.
         */
        virtual void UnregisterEntityFromAboutMessages(trManager::EntityBase& listeningEntity);

    private:

        static trBase::SmrtPtr<trManager::SystemManager> mInstance;
        std::queue<trBase::SmrtPtr<const trManager::MessageBase>> mMessageQueue;
        std::queue<trBase::SmrtPtr<const trManager::MessageBase>> mNetworkMessageQueue;

        // Storage for all the registered Directors       
        typedef std::list<trBase::SmrtPtr<trManager::EntityBase>> DirectorList;           //Needs to be a std::list so the directors can be priority sorted 
        typedef trUtil::HashMap<const std::string, trBase::SmrtPtr<trManager::EntityBase>> DirectorNameMap;
        typedef trUtil::HashMap<const trBase::UniqueId, trBase::SmrtPtr<trManager::EntityBase>> DirectorIDMap;
        DirectorList mDirectorList;   
        DirectorNameMap mDirectorNameMap;
        DirectorIDMap mDirectorIDMap;

        //Message registration structures.. 
        typedef std::pair<trBase::SmrtPtr<trManager::EntityBase>, std::string> EntityInvokablePair;                     //<entity, invokableName>        
        typedef trUtil::HashMap<const std::string*, std::vector<EntityInvokablePair>> MessageRegistrationVectorMap;     //<messageName, vector of registered entityPairs>
        typedef trUtil::HashMap<const trBase::UniqueId, std::vector<EntityInvokablePair>> UUIDRegistrationVectorMap;    //<UUID, vector of registered entityPairs>
        typedef trUtil::HashMap<trBase::SmrtPtr<trManager::EntityBase>, std::string> EntityInvokableMap;                //<entity, invokableName>
        typedef trUtil::HashMap<const std::string*, EntityInvokableMap> MessageRegistrationMap;                         //<messageName, <entity, invokableName>>
        MessageRegistrationVectorMap mEntityGlobalMsgRegistrationMap;
        MessageRegistrationMap mDirectorGlobalMsgRegistrationMap;
        UUIDRegistrationVectorMap mListenerRegistrationMap;
        
        //Storage for all registered Actors and Actor Modules
        typedef std::vector<trBase::SmrtPtr<trManager::EntityBase>> ActorList;
        typedef trUtil::HashMap<const trBase::UniqueId, trBase::SmrtPtr<trManager::EntityBase>> ActorIDMap;
        ActorList mActorList;
        ActorIDMap mActorIDMap; 

        std::vector<trBase::SmrtPtr<trManager::EntityBase>> mEntityDeleteList;         //List of entities that will be deleted at the end of the frame

        /**
         * @fn  void SystemManager::RegisterMsgWithMsgVectorMap(const std::string& messageType, EntityBase& listeningEntity, const std::string& invokableName, MessageRegistrationVectorMap& messageMap);
         *
         * @brief   Registers the message with a given message map.
         *
         * @param           messageType     Type of the message.
         * @param [in,out]  listeningEntity The listening entity.
         * @param           invokableName   Name of the invokable.
         * @param [in,out]  messageMap      The message map.
         */
        void RegisterMsgWithMsgVectorMap(const std::string& messageType, EntityBase& listeningEntity, const std::string& invokableName, MessageRegistrationVectorMap& messageMap);

        /**
         * @fn  void SystemManager::UnregisterMsgFromMsgVectorMap(const std::string& messageType, EntityBase& listeningEntity, MessageRegistrationVectorMap& messageMap);
         *
         * @brief   Un register message from a given message map.
         *
         * @param           messageType     Type of the message.
         * @param [in,out]  listeningEntity The listening entity.
         * @param [in,out]  messageMap      The message map.
         */
        void UnregisterMsgFromMsgVectorMap(const std::string& messageType, EntityBase& listeningEntity, MessageRegistrationVectorMap& messageMap);

        /**
         * @fn  void SystemManager::RegisterMsgWithMsgMap(const std::string& messageType, EntityBase& listeningEntity, const std::string& invokableName, MessageRegistrationMap& messageMap);
         *
         * @brief   Registers the message with message map.
         *
         * @param           messageType     Type of the message.
         * @param [in,out]  listeningEntity The listening entity.
         * @param           invokableName   Name of the invokable.
         * @param [in,out]  messageMap      The message map.
         */
        void RegisterMsgWithMsgMap(const std::string& messageType, EntityBase& listeningEntity, const std::string& invokableName, MessageRegistrationMap& messageMap);

        /**
         * @fn  void SystemManager::UnregisterMsgFromMsgMap(const std::string& messageType, EntityBase& listeningEntity, MessageRegistrationMap& messageMap);
         *
         * @brief   Un register message from message map.
         *
         * @param           messageType     Type of the message.
         * @param [in,out]  listeningEntity The listening entity.
         * @param [in,out]  messageMap      The message map.
         */
        void UnregisterMsgFromMsgMap(const std::string& messageType, EntityBase& listeningEntity, MessageRegistrationMap& messageMap);
    };
}