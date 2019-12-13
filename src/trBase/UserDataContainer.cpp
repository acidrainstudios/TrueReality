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

#include <trBase/UserDataContainer.h>


namespace trBase
{
    const trUtil::RefStr UserDataContainer::CLASS_TYPE = trUtil::RefStr("trBase::UserDataContainer");

    //////////////////////////////////////////////////////////////////////////
    UserDataContainer::UserDataContainer(const std::string name) : BaseClass(name)
    {
    }

    //////////////////////////////////////////////////////////////////////////
    UserDataContainer::~UserDataContainer()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& UserDataContainer::GetType() const
    {
        return CLASS_TYPE;
    }

    //////////////////////////////////////////////////////////////////////////
    trBase::SmrtClass* UserDataContainer::GetUserDataContainer()
    {
        return mUserDataContainer;
    }

    //////////////////////////////////////////////////////////////////////////
    const trBase::SmrtClass* UserDataContainer::GetUserDataContainer() const
    {
        return mUserDataContainer;
    }

    //////////////////////////////////////////////////////////////////////////
    void UserDataContainer::SetUserDataContainer(trBase::SmrtClass* data)
    {
        mUserDataContainer = data;
    }

    //////////////////////////////////////////////////////////////////////////
    std::vector<std::string> UserDataContainer::GetDescriptionList()
    {
        return mDescriptionList;
    }

    //////////////////////////////////////////////////////////////////////////
    const std::vector<std::string> UserDataContainer::GetDescriptionList() const
    {
        return mDescriptionList;
    }

    //////////////////////////////////////////////////////////////////////////
    int UserDataContainer::GetDescriptionListCount()
    {
        return mDescriptionList.size();
    }

    //////////////////////////////////////////////////////////////////////////
    std::string UserDataContainer::GetDescription(int index)
    {
        return mDescriptionList[index];
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string UserDataContainer::GetDescription(int index) const
    {
        return mDescriptionList[index];
    }

    //////////////////////////////////////////////////////////////////////////
    void UserDataContainer::AddDescription(std::string description)
    {
        mDescriptionList.push_back(description);
    }

    //////////////////////////////////////////////////////////////////////////
    void UserDataContainer::SetDescriptions(std::vector<std::string> descriptions)
    {
        mDescriptionList = descriptions;
    }

    //////////////////////////////////////////////////////////////////////////
    std::vector<trBase::SmrtPtr<trBase::Base>> UserDataContainer::GetObjectList()
    {
        return mObjectList;
    }

    //////////////////////////////////////////////////////////////////////////
    const std::vector<trBase::SmrtPtr<trBase::Base>> UserDataContainer::GetObjectList() const
    {
        return mObjectList;
    }

    //////////////////////////////////////////////////////////////////////////
    int UserDataContainer::GetObjectListCount()
    {
        return mObjectList.size();
    }

    //////////////////////////////////////////////////////////////////////////
    trBase::SmrtPtr<trBase::Base> UserDataContainer::GetObject(int index)
    {
        return mObjectList[index];
    }

    //////////////////////////////////////////////////////////////////////////
    const trBase::SmrtPtr<trBase::Base> UserDataContainer::GetObject(int index) const
    {
        return mObjectList[index];
    }

    //////////////////////////////////////////////////////////////////////////
    void UserDataContainer::AddObject(trBase::SmrtPtr<trBase::Base> obj)
    {
        return mObjectList.push_back(obj);
    }

    //////////////////////////////////////////////////////////////////////////
    void UserDataContainer::SetObjects(std::vector<trBase::SmrtPtr<trBase::Base>> objList)
    {
        mObjectList = objList;
    }
}
