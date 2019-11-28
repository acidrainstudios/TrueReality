/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2019 Acid Rain Studios LLC
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

#include <trManager/ActorBase.h>

#include <trManager/SystemManager.h>
#include <trManager/Invokable.h>
#include <trManager/EntityType.h>
#include <trUtil/Functor.h>
#include <trUtil/Logging/Log.h>

namespace trManager
{
    const trUtil::RefStr ActorBase::CLASS_TYPE("trManager::ActorBase");

    //////////////////////////////////////////////////////////////////////////
    ActorBase::ActorBase(const std::string& name) : BaseClass(name)
    {
        mEntityType = &EntityType::ACTOR;
        BuildInvokables();
    }

    //////////////////////////////////////////////////////////////////////////
    ActorBase::~ActorBase()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    void ActorBase::ActorModuleTick(const trManager::MessageBase& msg)
    {
        //Access i by reference
        for (auto&& i : mActorModules)
        {
            i->OnTick(msg);
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void ActorBase::RegisterForMessage(const std::string& messageType, const std::string& invokableName)
    {
        if (mSysMan.valid())
        {
            mSysMan->RegisterForMessage(messageType, *this, invokableName);
        }
        else
        {
            LOG_E("The entity " + GetName() + " is missing the internal System Manager reference. ")
            if (!IsRegistered())
            {
                LOG_W("The entity " + GetName() + " is not registered with System Manager. ")
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void ActorBase::UnRegisterFromMessage(const std::string& messageType)
    {
        if (mSysMan.valid())
        {
            mSysMan->UnregisterFromMessage(messageType, *this);
        }
        else
        {
            LOG_E("The entity " + GetName() + " is missing the internal System Manager reference. ")
            if (!IsRegistered())
            {
                LOG_W("The entity " + GetName() + " is not registered with System Manager. ")
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void ActorBase::RegisterForMessagesAboutEntity(const trBase::UniqueId& aboutEntityId, const std::string& invokableName)
    {
        if (mSysMan.valid())
        {
            mSysMan->RegisterForMessagesAboutEntity(*this, aboutEntityId, invokableName);
        }
        else
        {
            LOG_E("The entity " + GetName() + " is missing the internal System Manager reference. ")
                if (!IsRegistered())
                {
                    LOG_W("The entity " + GetName() + " is not registered with System Manager. ")
                }
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void ActorBase::UnregisterFromMessagesAboutEntity(const trBase::UniqueId& aboutEntityId)
    {
        if (mSysMan.valid())
        {
            mSysMan->UnregisterFromMessagesAboutEntity(*this, aboutEntityId);
        }
        else
        {
            LOG_E("The entity " + GetName() + " is missing the internal System Manager reference. ")
                if (!IsRegistered())
                {
                    LOG_W("The entity " + GetName() + " is not registered with System Manager. ")
                }
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void ActorBase::BuildInvokables()
    {
        AddInvokable(*new Invokable(ActorBase::ON_TICK_INVOKABLE, trUtil::MakeFunctor(&ActorBase::OnTick, this)));
        AddInvokable(*new Invokable(ActorBase::ON_TICK_REMOTE_INVOKABLE, trUtil::MakeFunctor(&ActorBase::OnTickRemote, this)));
    }

    //////////////////////////////////////////////////////////////////////////
    void ActorBase::OnTickRemote(const trManager::MessageBase& /*msg*/)
    {}

    //////////////////////////////////////////////////////////////////////////
    bool ActorBase::SendMessage(const trManager::MessageBase& message)
    {
        if (mSysMan.valid())
        {
            return mSysMan->SendMessage(message);
        }
        else
        {
            LOG_E("The entity " + GetName() + " is missing the internal System Manager reference. ")
            if (!IsRegistered())
            {
                LOG_W("The entity " + GetName() + " is not registered with System Manager. ")
            }

            return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    bool ActorBase::SendNetworkMessage(const trManager::MessageBase& message)
    {
        if (mSysMan.valid())
        {
            return mSysMan->SendNetworkMessage(message);
        }
        else
        {
            LOG_E("The entity " + GetName() + " is missing the internal System Manager reference. ")
            if (!IsRegistered())
            {
                LOG_W("The entity " + GetName() + " is not registered with System Manager. ")
            }

            return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    bool ActorBase::AddActorModule(trManager::EntityBase& actorModule)
    {
        //Make sure we are dealing with an Actor Module, and not another entity
        if (actorModule.GetEntityType() == trManager::EntityType::ACTOR_MODULE)
        {
            trBase::SmrtPtr<trManager::EntityBase> newActor = &actorModule;
            mActorModules.push_back(newActor);

            //Sets the parent of the Actor Module
            actorModule.SetParent(*this);

            return true;
        }
        else
        {
            LOG_E("Attempted to add " + actorModule.GetEntityType().GetName() + " instead of an Actor Module")
            return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    bool ActorBase::RemoveActorModule(trManager::EntityBase& actorModule)
    {
        //Make sure we are dealing with an Actor Module, and not another entity
        if (actorModule.GetEntityType() == trManager::EntityType::ACTOR_MODULE)
        {
            //Find an Actor Module with the same reference
            ActorModules::iterator found;
            for (found = mActorModules.begin(); found != mActorModules.end(); ++found)
            {
                if (found->Get() == &actorModule)
                {
                    //Remove the parent reference from the actor module
                    found->Get()->ForgetParent();

                    //We found the actor module we need, remove it
                    mActorModules.erase(found);

                    return true;
                }
            }

            //If you are here then you wanted to remove something that does not exist
            LOG_E("Attempted to remove a module which does not exist")
            return false;
        }
        else
        {
            LOG_E("Attempted to remove " + actorModule.GetEntityType().GetName() + " instead of an Actor Module")
            return false;
        }

        return false;
    }

    //////////////////////////////////////////////////////////////////////////
    bool ActorBase::RemoveActorModule(const trBase::UniqueId& id)
    {
        trManager::EntityBase* foundModule = FindActorModule(id);
        if (foundModule != nullptr)
        {
            return RemoveActorModule(*foundModule);
        }
        else
        {
            return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    bool ActorBase::RemoveAllActorModules()
    {
        for (int index = mActorModules.size() - 1; index >= 0; --index)
        {
            if (!RemoveActorModule(*mActorModules[index]))
            {
                //If one of the removals fail, stop and return a failure. 
                LOG_E("Error in removing " + mActorModules[index]->GetEntityType().GetName())
                return false;
            }
        }

        return true;
    }

    //////////////////////////////////////////////////////////////////////////
    trManager::EntityBase* ActorBase::FindActorModule(const trBase::UniqueId& id)
    {
        //Find an Actor Module with the same reference
        ActorModules::iterator found;
        for (found = mActorModules.begin(); found != mActorModules.end(); ++found)
        {
            if (found->Get()->GetUUID() == id)
            {
                //We found the actor module we need
                return found->Get();
            }
        }
        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////
    void ActorBase::OnAddedToSysMan()
    {
        BaseClass::OnAddedToSysMan();

        //ReAttach all modules, if we have any saved in the reattach list. 
        for (int index = 0; index < mActModReAttachStore.size(); ++index)
        {
            AddActorModule(*mActModReAttachStore[index]);
        }

        //Clear the reattach list
        mActModReAttachStore.clear();
    }

    //////////////////////////////////////////////////////////////////////////
    void ActorBase::OnRemovedFromSysMan()
    {
        BaseClass::OnRemovedFromSysMan();

        //Make the vector a needed size to speed up assignment. 
        mActModReAttachStore.reserve(mActorModules.size()); 

        //Store all the registered modules so we can re-attach them if we re-register with System Manager
        for (int index = 0; index < mActorModules.size(); ++index)
        {
            mActModReAttachStore.push_back(mActorModules[index]);
        }

        //Remove all Modules to make sure we don't have a memory leak if this instance is deleted. 
        RemoveAllActorModules();
    }
}