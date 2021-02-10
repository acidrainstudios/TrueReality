/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2021 Acid Rain Studios LLC
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

#pragma once

#include "Export.h"

#include <trManager/MessageBase.h>
#include <trManager/EntityBase.h>
#include <trBase/UniqueId.h>
#include <trBase/SmrtPtr.h>

#include <stdlib.h>
#include <vector>

namespace trManager
{
    /**
     * @class   ActorBase
     *
     * @brief   A base class for all actors in the entity system.
     */
    class TR_MANAGER_EXPORT ActorBase : public trManager::EntityBase
    {
    public:

        using BaseClass = trManager::EntityBase;                /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE;                 /// Holds the class type name for efficient comparisons

        /**
         * @fn  ActorBase(const std::string& name = CLASS_TYPE);
         *
         * @brief   ctor.
         *
         * @param   name    (Optional) The name.
         */
        ActorBase(const std::string& name = CLASS_TYPE);

        /**
        * Returns the class type
        */
        virtual const std::string& GetType() const override = 0;

        /**
         * @fn  virtual void ActorBase::RegisterForMessage(const std::string& messageType, const std::string& invokableName);
         *
         * @brief   Registers an actor for messages.
         *
         * @param [in,out]  listeningActor  The listening actor.
         *
         * @param           messageType     Type of the message.
         * @param           invokableName   Name of the invokable.
         */
        virtual void RegisterForMessage(const std::string& messageType, const std::string& invokableName);

        /**
         * @fn  virtual void ActorBase::UnRegisterFromMessage(const std::string& messageType);
         *
         * @brief   Unregister an actor that is listening for a given message.
         *
         * @param [in,out]  listeningActor  The listening actor.
         *
         * @param           messageType Type of the message.
         */
        virtual void UnRegisterFromMessage(const std::string& messageType);

        /**
         * @fn  virtual void ActorBase::RegisterForMessagesAboutEntity(const trBase::UniqueId& aboutEntityId, const std::string& invokableName);
         *
         * @brief   Registers for messages about a specific actor.
         *
         * @param   aboutEntityId   Identifier for the about entity.
         * @param   invokableName   Name of the invokable.
         */
        virtual void RegisterForMessagesAboutEntity(const trBase::UniqueId& aboutEntityId, const std::string& invokableName);

        /**
         * @fn  virtual void ActorBase::UnregisterFromMessagesAboutEntity(const trBase::UniqueId& aboutEntityId);
         *
         * @brief   Unregisters from messages about a specific actor.
         *
         * @param   aboutEntityId   Identifier for the about entity.
         */
        virtual void UnregisterFromMessagesAboutEntity(const trBase::UniqueId& aboutEntityId);

        /**
         * @fn  virtual void ActorBase::BuildInvokables();
         *
         * @brief   Builds the default invokables for this class.
         */
        virtual void BuildInvokables();

        /**
         * @fn  virtual void ActorBase::OnTick(const trManager::MessageBase& msg) = 0;
         *
         * @brief   Convenience function that will receive Tick Messages from the System Manager This
         *          does not happen automatically, each class needs to register for the message.
         *
         * @param   msg The message.
         */
        virtual void OnTick(const trManager::MessageBase& msg) = 0;

        /**
         * @fn  virtual void ActorBase::OnTickRemote(const trManager::MessageBase& msg);
         *
         * @brief   Convenience function that will receive a Network Tick Message from the System Manager
         *          This does not happen automatically, each class needs to register for the message.
         *
         * @param   msg The message.
         */
        virtual void OnTickRemote(const trManager::MessageBase& msg);

        /**
         * @fn  virtual bool ActorBase::SendMessage(const trManager::MessageBase& message);
         *
         * @brief   Send a message to an Actor, Actor Module, or a Director.
         *
         * @param   message The message.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool SendMessage(const trManager::MessageBase& message);

        /**
         * @fn  virtual bool ActorBase::SendNetworkMessage(const trManager::MessageBase& message);
         *
         * @brief   Send a Network message to an Actor, Actor Module, or a Director.
         *
         * @param   message The message.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool SendNetworkMessage(const trManager::MessageBase& message);

        /**
         * @fn  virtual bool ActorBase::AddActorModule(trManager::EntityBase& actorModule);
         *
         * @brief   Adds an Actor Module to the current Actor. NOTE: If this actor is never
         *             registered with the System Manager, you manually need to remove attached Actor Modules, or
         *             there could be a memory leak. Use RemoveAllActorModules() to remove all at once or
         *             RemoveActorModule(...) to remove them one at a time.
         *
         * @param [in,out]  actorModule The actor module.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool AddActorModule(trManager::EntityBase& actorModule);

        /**
         * @fn  virtual bool ActorBase::RemoveActorModule(trManager::EntityBase& actorModule);
         *
         * @brief   Removes the given Actor Module from the current Actor.
         *
         * @param [in,out]  actorModule The actor module.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool RemoveActorModule(trManager::EntityBase& actorModule);

        /**
         * @fn  virtual bool ActorBase::RemoveActorModule(const trBase::UniqueId& id);
         *
         * @brief   Removes the given Actor Module from the current Actor.
         *
         * @param   id  The identifier.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool RemoveActorModule(const trBase::UniqueId& id);

        /**
         * @fn    virtual bool ActorBase::RemoveAllActorModule();
         *
         * @brief    Removes all attached actor modules from this actor.
         *
         * @return    True if it succeeds, false if it fails.
         */
        virtual bool RemoveAllActorModules();

        /**
         * @fn  virtual trManager::EntityBase* ActorBase::FindActorModule(const trBase::UniqueId& id);
         *
         * @brief   Finds and returns the Actor Module cast down to Entity.
         *
         * @param   id  The identifier.
         *
         * @return  Null if it fails, else the found actor module.
         */
        virtual trManager::EntityBase* FindActorModule(const trBase::UniqueId& id);

        /**
         * @fn    virtual void ActorBase::OnAddedToSysMan() override;
         *
         * @brief    Called by the System Manager when EntityBase Registration is complete.
         */
        virtual void OnAddedToSysMan() override;

        /**
         * @fn    virtual void ActorBase::OnRemovedFromSysMan() override;
         *
         * @brief    Called by the System Manager after removing and Unregistering the EntityBase.
         */
        virtual void OnRemovedFromSysMan() override;

    protected:

        /**
         * @fn  ActorBase::~ActorBase();
         *
         * @brief   dtor.
         */
        ~ActorBase();

        /**
         * @fn  virtual void ActorBase::ActorModuleTick(const trManager::MessageBase& tickMsg);
         *
         * @brief   Sends the passed in message Tick Message to all attached Actor Modules. It is the
         *          developers responsibility to make sure you are passing a TickMessage and nothing else.
         *
         * @param   tickMsg Message describing the tick.
         */
        virtual void ActorModuleTick(const trManager::MessageBase& tickMsg);

    private:

        /**
         * @using ActorModules = std::vector<trBase::SmrtPtr<trManager::EntityBase>>
         *
         * @brief   Defines an alias representing the actor modules.
         */
        using ActorModules = std::vector<trBase::SmrtPtr<trManager::EntityBase>>;
        ActorModules mActorModules; //Actor Module Storage

        //Temp Storage for actor modules if this actor is disconnected and reconnected from and to System Manager.
        ActorModules mActModReAttachStore;
    };
}

