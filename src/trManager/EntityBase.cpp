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

#include <trManager/EntityBase.h>

#include <trManager/SystemManager.h>
#include <trUtil/Logging/Log.h>

namespace trManager
{
    const trUtil::RefStr EntityBase::CLASS_TYPE("trManager::EntityBase");

    const trUtil::RefStr EntityBase::ON_MESSAGE_INVOKABLE("OnMessage");
    const trUtil::RefStr EntityBase::ON_TICK_INVOKABLE("OnTick");
    const trUtil::RefStr EntityBase::ON_TICK_REMOTE_INVOKABLE("OnTickRemote");

    //////////////////////////////////////////////////////////////////////////
    EntityBase::EntityBase(const std::string& name) : BaseClass(name)
    {
        mEntityType = &EntityType::INVALID;
    }

    //////////////////////////////////////////////////////////////////////////
    const EntityType& EntityBase::GetEntityType()
    {
        return mEntityType;
    }

    //////////////////////////////////////////////////////////////////////////
    void EntityBase::SetSystemManager(trManager::SystemManager *sysMan)
    {
        mSysMan = sysMan;
    }

    //////////////////////////////////////////////////////////////////////////
    const bool & EntityBase::IsRegistered()
    {
        return mIsRegistered;
    }

    //////////////////////////////////////////////////////////////////////////
    void EntityBase::SetRegistration(bool isRegistered)
    {
        mIsRegistered = isRegistered;
    }

    //////////////////////////////////////////////////////////////////////////
    void EntityBase::AddInvokable(trManager::Invokable &newInvokable)
    {
        trUtil::HashMap<std::string, trBase::SmrtPtr<trManager::Invokable>>::iterator itor = mInvokables.find(newInvokable.GetName());
        if (itor != mInvokables.end())
        {
            LOG_W("Could not add new invokable " + newInvokable.GetName() + " for " + GetName() + " because an invokable with that name already exists.")
        }
        else
        {
            LOG_D("Adding a new invokable " + newInvokable.GetName() + " for " + GetName())
                mInvokables.insert(std::make_pair(newInvokable.GetName(), trBase::SmrtPtr<Invokable>(&newInvokable)));
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void EntityBase::RemoveInvokable(trManager::Invokable *invokable)
    {
        RemoveInvokable(invokable->GetName());
    }

    //////////////////////////////////////////////////////////////////////////
    void EntityBase::RemoveInvokable(const std::string &invokableName)
    {
        trUtil::HashMap<std::string, trBase::SmrtPtr<trManager::Invokable>>::iterator itor = mInvokables.find(invokableName);

        if (itor != mInvokables.end())
        {
            mInvokables.erase(itor);
        }
        else
        {
            LOG_W("Could not remove invokable " + invokableName + " because an invokable with that name does not exists.")
        }
    }

    //////////////////////////////////////////////////////////////////////////
    trManager::Invokable * EntityBase::GetInvokable(const std::string &name)
    {
        trUtil::HashMap<std::string, trBase::SmrtPtr<trManager::Invokable>>::iterator itor = mInvokables.find(name);

        if (itor == mInvokables.end())
        {
            return nullptr;
        }
        else
        {
            return itor->second.Get();
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void EntityBase::GetInvokables(std::vector<trManager::Invokable*> &toFill)
    {
        toFill.clear();
        toFill.reserve(mInvokables.size());

        for (trUtil::HashMap<std::string, trBase::SmrtPtr<trManager::Invokable>>::iterator i = mInvokables.begin();
            i != mInvokables.end(); ++i)
        {
            toFill.push_back(i->second.Get());
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void EntityBase::GetInvokables(std::vector<const trManager::Invokable*> &toFill) const
    {
        toFill.clear();
        toFill.reserve(mInvokables.size());

        for (trUtil::HashMap<std::string, trBase::SmrtPtr<trManager::Invokable>>::const_iterator i = mInvokables.begin();
            i != mInvokables.end(); ++i)
        {
            toFill.push_back(i->second.Get());
        }
    }

    //////////////////////////////////////////////////////////////////////////
    bool EntityBase::AddChild(trManager::EntityBase &child)
    {
        if (child.GetParent() == nullptr)
        {
            //Make sure that the only entities that can attach to one another are actors.
            if (GetEntityType() == EntityType::ACTOR && child.GetEntityType() == EntityType::ACTOR)
            {
                mChildren.push_back(*new trBase::SmrtPtr<trManager::EntityBase>(&child));
                child.SetParent(*this);
                return true;
            }
            else
            {
                LOG_E("You can not add " + child.GetEntityType().GetName() + " to " + GetEntityType().GetName() + " as a child.")
                return false;
            }
        }
        else
        {
            LOG_E("You can not add " + child.GetEntityType().GetName() + " to " + GetEntityType().GetName() + " because the child already has a parent " + child.GetParent()->GetName())
            return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    bool EntityBase::RemoveChild(trManager::EntityBase &child)
    {
        //Find and remove the child from this entity
        for (unsigned int i = 0; i < mChildren.size(); ++i)
        {
            if (mChildren[i].Get() == &child)
            {
                mChildren.erase(mChildren.begin() + i);
                break;
            }
        }

        //Remove the child's parent
        if (child.GetParent() != nullptr)
        {
            child.Emancipate();
        }
        return false;
    }

    //////////////////////////////////////////////////////////////////////////
    bool EntityBase::RemoveAllChildren()
    {
        for (int i = mChildren.size() - 1; i >= 0; --i)
        {
            //Remove the parental link to this entity.
            mChildren[i]->ForgetParent();
        }
        //Clear the children list
        mChildren.clear();
        return true;
    }

    //////////////////////////////////////////////////////////////////////////
    std::vector<trBase::SmrtPtr<trManager::EntityBase>>* EntityBase::GetChildren()
    {
        return &mChildren;
    }

    //////////////////////////////////////////////////////////////////////////
    const std::vector<trBase::SmrtPtr<trManager::EntityBase>>* EntityBase::GetChildren() const
    {
        return &mChildren;
    }

    //////////////////////////////////////////////////////////////////////////
    const trManager::EntityBase* EntityBase::FindChild(const trBase::UniqueId &childId)
    {
        //Find and remove the child from this entity
        for (unsigned int i = 0; i < mChildren.size(); ++i)
        {
            if (mChildren[i]->GetUUID() == childId)
            {
                return mChildren[i];
            }
        }

        //If the child was not found, return NULL;
        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////
    int EntityBase::GetNumOfChildren()
    {
        return mChildren.size();
    }

    //////////////////////////////////////////////////////////////////////////
    void EntityBase::SetParent(trManager::EntityBase &parent)
    {
        if (!mParent.Valid())
        {
            //Set the new parent
            mParent = &parent;

            //Call the On Parent Set callback
            OnParentSet(parent);
        }
        else
        {
            LOG_E("Entity " + GetName() + " already has a parent " + mParent->GetName())
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void EntityBase::ForgetParent()
    {
        //Make a copy of the parent before disconnecting from it.
        trBase::SmrtPtr<trManager::EntityBase> parent = mParent;

        mParent = nullptr;

        OnParentRemoved(*parent);
    }

    //////////////////////////////////////////////////////////////////////////
    trManager::EntityBase* EntityBase::GetParent()
    {
        return mParent.Get();
    }

    //////////////////////////////////////////////////////////////////////////
    const trManager::EntityBase* EntityBase::GetParent() const
    {
        return mParent.Get();
    }

    //////////////////////////////////////////////////////////////////////////
    void EntityBase::OnParentRemoved(trManager::EntityBase& /*parent*/)
    {
    }

    //////////////////////////////////////////////////////////////////////////
    void EntityBase::OnParentSet(trManager::EntityBase& /*parent*/)
    {
    }

    //////////////////////////////////////////////////////////////////////////
    void EntityBase::Emancipate()
    {
        //Make a copy of the parent before disconnecting from it.
        trBase::SmrtPtr<trManager::EntityBase> parent = mParent;


        //Remove this Entity from its previous parent.
        if (!parent.Valid())
        {
            ForgetParent();
            parent->RemoveChild(*this);
        }
        else
        {
            LOG_W("The Entity " + GetName() + " was not attached to a parent.")
        }
    }

    //////////////////////////////////////////////////////////////////////////
    bool EntityBase::RemoveFromHierarchy()
    {
        if (mParent.Valid())
        {
            for (unsigned int i = 0; i < mChildren.size(); ++i)
            {
                //Remove the child's parent (this entity)
                mChildren[i]->ForgetParent();

                //Add the child to this entities previous parent.
                if (!mParent->AddChild(*mChildren[i]))
                {
                    return false;
                }
            }

            //Delete all references to the children;
            mChildren.clear();

            //Remove this entities parent.
            ForgetParent();

            return true;
        }
        else
        {
            LOG_E(GetName() + " is not attached to a parent. Can't remove it from Hierarchy.")
            return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    EntityBase::~EntityBase()
    {
    }
}