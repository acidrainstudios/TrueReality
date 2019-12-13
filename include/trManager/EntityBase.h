/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2019 Acid Rain Studios LLC
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

#include <trUtil/EnumerationNumeric.h>
#include <trManager/EntityType.h>
#include <trManager/Invokable.h>
#include <trUtil/HashMap.h>
#include <trBase/ObsrvrPtr.h>
#include <trBase/SmrtPtr.h>
#include <trBase/Base.h>

#include <vector>

namespace trManager
{
    class SystemManager;

    /**
     * @class   EntityBase
     *
     * @brief   This serves as the base class for the Entity class and removes 
     *          a circular dependency between Entity and System Manager. 
     */
    class  TR_MANAGER_EXPORT EntityBase : public trBase::Base
    {
    public:

        using BaseClass = trBase::Base;                         /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE;                 /// Holds the class type name for efficient comparisons

        const static trUtil::RefStr ON_MESSAGE_INVOKABLE;               /// Invokable for general messages
        const static trUtil::RefStr ON_TICK_INVOKABLE;                  /// Invokable for Tick messages
        const static trUtil::RefStr ON_TICK_REMOTE_INVOKABLE;           /// Invokable for Tick Remote messages

        /**
         * @fn  EntityBase(const std::string& name = CLASS_TYPE);
         *
         * @brief   Constructor.
         *
         * @param   name    (Optional) The name.
         */
        EntityBase(const std::string& name = CLASS_TYPE);

        /**
         * @fn  virtual const std::string& EntityBase::GetType() const override = 0;
         *
         * @brief   Returns the class type.
         *
         * @return  The type.
         */
        virtual const std::string& GetType() const override = 0;

        /**
         * @fn  const EntityType& EntityBase::GetEntityType();
         *
         * @brief   Returns the Entity Type, which is usually a Director, Actor, or an Actor module.
         *
         * @return  The entity type.
         */
        const EntityType& GetEntityType();

        /**
         * @fn  virtual void EntityBase::SetSystemManager(trManager::SystemManager *sysMan);
         *
         * @brief   This method is used by the System Manager to pass the Entity an instance if itself
         *          when it is registered. The user should not use this function.
         *
         * @param [in,out]  sysMan  If non-null, manager for system.
         */
        virtual void SetSystemManager(trManager::SystemManager *sysMan);

        /**
         * @fn  virtual void EntityBase::OnAddedToSysMan()
         *
         * @brief   Called by the System Manager when EntityBase Registration is complete.
         */
        virtual void OnAddedToSysMan() {/*Meant for user to overwrite*/ };

        /**
         * @fn  virtual void EntityBase::OnRemovedFromSysMan()
         *
         * @brief   Called by the System Manager after removing and Unregistering the EntityBase.
         */
        virtual void OnRemovedFromSysMan() {/*Meant for user to overwrite*/ };

        /**
         * @fn  virtual const bool& EntityBase::IsRegistered();
         *
         * @brief   Returns True if the Instance is registered with a System Manager.
         *
         * @return  A reference to a const bool.
         */
        virtual const bool& IsRegistered();

        /**
         * @fn  virtual void EntityBase::SetRegistration(bool isRegistered);
         *
         * @brief   Is set to True by the System Manager when the class instance is registered with it.
         *          This function should not be called by the user.
         *
         * @param   isRegistered    True if this object is registered.
         */
        virtual void SetRegistration(bool isRegistered);

        /**
         * @fn  virtual void EntityBase::AddInvokable(trManager::Invokable &newInvokable);
         *
         * @brief   Adds an invokable that can receive a message.
         *
         * @param [in,out]  newInvokable    The new invokable.
         */
        virtual void AddInvokable(trManager::Invokable &newInvokable);

        /**
         * @fn  virtual void EntityBase::RemoveInvokable(trManager::Invokable *invokable);
         *
         * @brief   Removes the invokable that is passed in.
         *
         * @param [in,out]  invokable   If non-null, the invokable.
         */
        virtual void RemoveInvokable(trManager::Invokable *invokable);

        /**
         * @fn  virtual void EntityBase::RemoveInvokable(const std::string &invokableName);
         *
         * @brief   Removes the invokable described by invokableName.
         *
         * @param   invokableName   Name of the invokable.
         */
        virtual void RemoveInvokable(const std::string &invokableName);

        /**
         * @fn  trManager::Invokable* EntityBase::GetInvokable(const std::string &name);
         *
         * @brief   Gets a registered invokable.
         *
         * @param   name    The name.
         *
         * @return  Null if it fails, else the invokable.
         */
        trManager::Invokable* GetInvokable(const std::string &name);

        /**
         * @fn  void EntityBase::GetInvokables(std::vector<trManager::Invokable*> &toFill);
         *
         * @brief   Gets the list of invokables.
         *
         * @param [in,out]  toFill  [in,out] If non-null, to fill.
         */
        void GetInvokables(std::vector<trManager::Invokable*> &toFill);

        /**
         * @fn  void EntityBase::GetInvokables(std::vector<const trManager::Invokable*> &toFill) const;
         *
         * @brief   Gets the invokables.
         *
         * @param   toFill  to fill.
         */
        void GetInvokables(std::vector<const trManager::Invokable*> &toFill) const;

        /**
         * @fn  virtual void EntityBase::OnTick(const trManager::MessageBase &msg) = 0;
         *
         * @brief   Convenience function that will receive Tick Messages from the System Manager This
         *          does not happen automatically, each class needs to register for the message.
         *
         * @param   msg The message.
         */
        virtual void OnTick(const trManager::MessageBase &msg) = 0;

        /**
         * @fn  virtual void EntityBase::OnTickRemote(const trManager::MessageBase &msg) = 0;
         *
         * @brief   Convenience function that will receive a Network Tick Message from the System Manager
         *          This does not happen automatically, each class needs to register for the message.
         *
         * @param   msg The message.
         */
        virtual void OnTickRemote(const trManager::MessageBase &msg) = 0;

        /**
         * @fn  virtual bool EntityBase::AddChild(trManager::EntityBase &child);
         *
         * @brief   Adds a child to this Entity.
         *
         * @param [in,out]  child   The child.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool AddChild(trManager::EntityBase &child);

        /**
         * @fn  virtual bool EntityBase::RemoveChild(trManager::EntityBase &child);
         *
         * @brief   Removes the child from this Entity.
         *
         * @param [in,out]  child   The child.
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool RemoveChild(trManager::EntityBase &child);

        /**
         * @fn  virtual bool EntityBase::RemoveAllChildren();
         *
         * @brief   Removes all of the entities children .
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool RemoveAllChildren();

        /**
         * @fn  virtual std::vector<trBase::SmrtPtr<trManager::EntityBase>>* EntityBase::GetChildren();
         *
         * @brief   Gets the children of this Entity.
         *
         * @return  Null if it fails, else the children.
         */
        virtual std::vector<trBase::SmrtPtr<trManager::EntityBase>>* GetChildren();

        /**
         * @fn  virtual const std::vector<trBase::SmrtPtr<trManager::EntityBase>>* EntityBase::GetChildren() const;
         *
         * @brief   Gets the children of this Entity.
         *
         * @return  Null if it fails, else the children.
         */
        virtual const std::vector<trBase::SmrtPtr<trManager::EntityBase>>* GetChildren() const;

        /**
         * @fn  virtual const trManager::EntityBase* EntityBase::FindChild(const trBase::UniqueId& childId);
         *
         * @brief   Finds a child of this Entity in the children list.
         *
         * @param   childId Identifier for the child.
         *
         * @return  Null if it fails, else the found child.
         */
        virtual const trManager::EntityBase* FindChild(const trBase::UniqueId& childId);

        /**
        * @fn  virtual int EntityBase::GetNumOfChildren();
        *
        * @brief   Gets the children of this Entity has.
        *
        * @return  The number of children.
        */
        virtual int GetNumOfChildren();

        /**
         * @fn  virtual void EntityBase::SetParent(trManager::EntityBase &parent);
         *
         * @brief   Sets the hierarchal parent of this Entity. This is for system use only.
         *          Use AddChild() if you want to attach entities. 
         *
         * @param [in,out]  parent  The parent.
         */
        virtual void SetParent(trManager::EntityBase &parent);

        /**
         * @fn  virtual void EntityBase::ForgetParent() trManager::EntityBase* GetParent();
         *
         * @brief   Forgets the hierarchal parent of this Entiry. This is for system use only. 
         *          Used Emancipate() if you want to disconnect your entity.
         */
        virtual void ForgetParent();

        /**
         * @fn  trManager::EntityBase* EntityBase::GetParent();
         *
         * @brief   Gets the parent of this hierarchal Entity.
         *
         * @return  Null if it fails, else the parent.
         */
        trManager::EntityBase* GetParent();

        /**
         * @fn  const trManager::EntityBase* EntityBase::GetParent() const;
         *
         * @brief   Gets the parent of this hierarchal Entity.
         *
         * @return  Null if it fails, else the parent.
         */
        const trManager::EntityBase* GetParent() const;

        /**
         * @fn  virtual void EntityBase::OnParentRemoved(trManager::EntityBase &parent);
         *
         * @brief   Convenience function that will be called by the system when the Entities parent is
         *          removed. Overwrite to capture the event. 
         *
         * @param [in,out]  parent  The parent.
         */
        virtual void OnParentRemoved(trManager::EntityBase &parent);

        /**
         * @fn  virtual void EntityBase::OnParentSet(trManager::EntityBase &parent) virtual void Emancipate();
         *
         * @brief   Convenience function that will be called by the system when a new parent is added or
         *          set to the Entity. Overwrite to capture the event. 
         *
         * @param [in,out]  parent  The parent.
         */
        virtual void OnParentSet(trManager::EntityBase &parent);


        /**
         * @fn  virtual void EntityBase::Emancipate();
         *
         * @brief   Removes the hierarchal parent of this Entity, and removes this Entity from the parent.
         *
         * @param [in,out]  parent  The parent.
         */
        virtual void Emancipate();

        /**
         * @fn  virtual bool EntityBase::RemoveFromHierarchy();
         *
         * @brief   Removes from this entity from the hierarchy tree attaching its children to its parent. 
         *          Does nothing if this entity does not have a parent. 
         *
         * @return  True if it succeeds, false if it fails.
         */
        virtual bool RemoveFromHierarchy();

    protected:

        trBase::ObsrvrPtr<trManager::SystemManager> mSysMan;
        trUtil::EnumerationPointer<const trManager::EntityType> mEntityType;
        trUtil::HashMap<std::string, trBase::SmrtPtr<trManager::Invokable>> mInvokables;  //<invokable name, invokable>   

        ~EntityBase();

    private:

        bool mIsRegistered = false;
        std::vector<trBase::SmrtPtr<trManager::EntityBase>> mChildren;
        trBase::SmrtPtr<trManager::EntityBase> mParent;

    };
}