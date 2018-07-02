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
* @author: Maxim Serebrennik
*/

#pragma once

#include <trBase/Export.h>

#include <trBase/SmrtClass.h>
#include <trBase/SmrtPtr.h>
#include <trBase/Base.h>
#include <trUtil/RefStr.h>

#include <string>
#include <vector>

namespace trBase 
{
    /**
    * This class hold custom user data. 
    * Since all the objects in this class can be different, it is strongly encouraged to use
    * the Description field to note what objects are stored in the instance. 
    */
    class TR_BASE_EXPORT UserDataContainer : public trBase::Base
    {
    public:

        typedef trBase::Base BaseClass;                 /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE;         /// Holds the class type name for efficient comparisons

        /**
        * ctor
        */
        UserDataContainer(const std::string name = CLASS_TYPE);

        /**
        * Returns the class type
        */
        virtual const std::string& GetType() const override;

        /**
        * Returns the user data object
        */
        virtual trBase::SmrtClass* GetUserDataContainer();
        
        /**
        * Returns the user data object
        */
        virtual const trBase::SmrtClass* GetUserDataContainer() const;

        /**
        * Sets the user data object
        */
        virtual void SetUserDataContainer(trBase::SmrtClass* data);

        /**
        * Returns a list of Description strings
        */
        virtual std::vector<std::string> GetDescriptionList();

        /**
        * Returns a list of Description strings
        */
        virtual const std::vector<std::string> GetDescriptionList() const;

        /**
        * Returns the number of objects stored in the Description list
        */
        virtual int GetDescriptionListCount();

        /**
        * Returns the specified description. Returns the first one if no index is specified
        */
        virtual std::string GetDescription(int index = 0);

        /**
        * Returns the specified description. Returns the first one if no index is specified
        */
        virtual const std::string GetDescription(int index = 0) const;

        /**
        * Adds a new description string to the list of descriptions 
        */
        virtual void AddDescription(std::string description);

        /**
        * Set a new list of descriptions strings
        */
        virtual void SetDescriptions(std::vector<std::string> descriptions);

        /**
        * Returns the list of all the user objects cast down to Base class. 
        */
        virtual std::vector<trBase::SmrtPtr<trBase::Base>> GetObjectList();

        /**
        * Returns the list of all the user objects cast down to Base class.
        */
        virtual const std::vector<trBase::SmrtPtr<trBase::Base>> GetObjectList() const;

        /**
        * Returns the number of objects stored in the Object list
        */
        virtual int GetObjectListCount();

        /**
        * Returns the specified object. Returns the first one if no index is specified
        */
        virtual trBase::SmrtPtr<trBase::Base> GetObject(int index = 0);

        /**
        * Returns the specified object. Returns the first one if no index is specified
        */
        virtual const trBase::SmrtPtr<trBase::Base> GetObject(int index = 0) const;

        /**
        * Adds a new object to the object list
        */
        virtual void AddObject(trBase::SmrtPtr<trBase::Base> obj);

        /**
        * Set a new list of objects
        */
        virtual void SetObjects(std::vector<trBase::SmrtPtr<trBase::Base>> objList);
        
    protected:

        trBase::SmrtPtr<trBase::SmrtClass> mUserDataContainer;
        std::vector<std::string> mDescriptionList;
        std::vector<trBase::SmrtPtr<trBase::Base>> mObjectList;

        /**
        * dtor
        */
        ~UserDataContainer();
    };
}
