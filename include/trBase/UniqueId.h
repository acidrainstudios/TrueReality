/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2021 Acid Rain Studios LLC
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

#include <trBase/SmrtClass.h>
#include <trUtil/RefStr.h>
#include <trUtil/Hash.h>

#include <string>
#include <sstream>
#include <iosfwd>

namespace trBase
{
    // Forward declarations of the pimpl class
    class implId;

    /**
    * This class creates a GUID, or a Unique ID that is used through out TR to identify and distinguish one object from another.
    */
    class TR_BASE_EXPORT UniqueId : public trBase::SmrtClass
    {

    public:

        using BaseClass = trBase::SmrtClass;            /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE;         /// Holds the class type name for efficient comparisons

        /**
        * @param createNewId if true, generates a new id.  If not, it sets the id to empty.
        */
        explicit UniqueId(bool createNewId = true);

        /**
        * Makes a copy of the passed in Unique ID GUID
        */
        UniqueId(const UniqueId& toCopy);

        /**
        * Makes the Unique ID equal to the ID in the passes in string.
        * The string should be in 00000000-0000-0000-0000-000000000000 format.
        */
        explicit UniqueId(const std::string& toCopy);

        /**
        * dtor
        */
        virtual ~UniqueId();

        /**
        * Returns the class type
        */
        virtual const std::string& GetType() const override;

        /**
        * Convert the current GUID into a string
        */
        const std::string ToString() const;

        /**
        * Assign the GUID value to this instance from a string.
        * The = operator can be used to accomplish the same thing.
        * The string should be in 00000000-0000-0000-0000-000000000000 format.
        */
        void FromString(const std::string& idString);

        /**
        * Returns true if the GUID is equal to 00000000-0000-0000-0000-000000000000
        */
        bool IsNull() const;

        /**
        * Copy the GUID from another unique id.
        * The assignment operator is public so that unique id's can be changed if they are
        * member variables.  Use const to control when they are changed.
        */
        UniqueId& operator=(const UniqueId& id);

        /**
        * Copy the GUID from another unique id.
        * The assignment operator is public so that unique id's can be changed if they are
        * member variables.  Use const to control when they are changed.
        */
        UniqueId& operator=(const UniqueId* id);

        /**
        * Copy the GUID form a string.
        * The assignment operator is public so that unique id's can be changed if they are
        * member variables.  Use const to control when they are changed.
        */
        UniqueId& operator=(const std::string& id);

        /**
         * @fn  bool UniqueId::operator==(const UniqueId& id) const;
         *
         * @brief   Equality operator.
         *
         * @param   id  The identifier.
         *
         * @return  True if the parameters are considered equivalent.
         */
        bool operator==(const UniqueId& id) const;

        /**
         * @fn  bool UniqueId::operator!=(const UniqueId& id) const;
         *
         * @brief   Inequality operator.
         *
         * @param   id  The identifier.
         *
         * @return  True if the parameters are not considered equivalent.
         */
        bool operator!=(const UniqueId& id) const;

        /**
         * @fn  bool UniqueId::operator< (const UniqueId& id) const;
         *
         * @brief   Less-than comparison operator.
         *
         * @param   id  The identifier.
         *
         * @return  True if the first parameter is less than the second.
         */
        bool operator< (const UniqueId& id) const;

        /**
         * @fn  bool UniqueId::operator> (const UniqueId& id) const;
         *
         * @brief   Greater-than comparison operator.
         *
         * @param   id  The identifier.
         *
         * @return  True if the first parameter is greater than to the second.
         */
        bool operator> (const UniqueId& id) const;

    protected:
        implId* mGUIDPtr = nullptr;
    };

    ////////////////////////////////////////////////////
    /////////////  Stream Operators        /////////////
    ////////////////////////////////////////////////////
    TR_BASE_EXPORT std::ostream& operator << (std::ostream& o, const UniqueId& id);

    TR_BASE_EXPORT std::istream& operator >> (std::istream& i, UniqueId& id);
}

namespace trUtil
{
    /**
     * Hash function for hashing trBase::UniqueId
     */
    template<> struct hash<trBase::UniqueId>
    {
        size_t operator()(const trBase::UniqueId& id) const
        {
            return __hash_string(id.ToString().c_str());
        }
    };

    /**
     * Hash function for hashing const trBase::UniqueId
     */
    template<> struct hash<const trBase::UniqueId>
    {
        size_t operator()(const trBase::UniqueId& id) const
        {
            return __hash_string(id.ToString().c_str());
        }
    };
}