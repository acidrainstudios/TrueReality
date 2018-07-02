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

#include "Export.h"

#include <trUtil/EnumerationString.h>

#include <ostream>

namespace trUtil
{
    /**
     * This class represents a type-safe Enumeration pattern.  It allows one to
     * also enumerate an Enumeration thus looking up values in a list fashion. Unlike
     * EnumerationString, EnumerationNumeric also stores an integer value with each Enum. 
     */
    class TR_UTIL_EXPORT EnumerationNumeric : public EnumerationString
    {
    public:
        typedef EnumerationString BaseClass; /// Adds an easy and swappable access to the base class

        /**
         * Returns the Numeric value of the Enum
         */
        unsigned int GetID() const;
        
        /**
         * Equality test for an EnumerationNumeric. This comparison option takes in an unsigned integer.
         * Inlined because it's called frequently
         */
        bool operator==(const unsigned int &id) const
        {
            return (mID == id);
        }
        
        /**
         * Inequality test for an EnumerationNumeric. This comparison option takes in an unsigned integer.
         * Inlined because it's called frequently
         */
        bool operator!=(const unsigned int &id) const
        {
            return (mID != id);
        }
        
        /**
         * Greater than test for an EnumerationNumeric. This comparison option takes in an unsigned integer.
         * Inlined because it's called frequently
         */
        bool operator>(const unsigned int &id) const
        {
            return (mID > id);
        }
        
        /**
         * Less than test for an EnumerationNumeric. This comparison option takes in an unsigned integer.
         * Inlined because it's called frequently
         */
        bool operator<(const unsigned int &id) const
        {
            return (mID < id);
        }
        
        /**
         * Greater than test for an EnumerationNumeric. This comparison option takes in an EnumerationNumeric.
         * Inlined because it's called frequently
         */
        bool operator>(const EnumerationNumeric &e) const
        {
            return (mID > e.mID);
        }
        
        /**
         * Less than test for an EnumerationNumeric. This comparison option takes in an EnumerationNumeric.
         * Inlined because it's called frequently
         */
        bool operator<(const EnumerationNumeric &e) const
        {
            return (mID < e.mID);
        }
        
        /**
         * Equality test for an EnumerationNumeric. This comparison option takes in an EnumerationNumeric.
         * Inlined because it's called frequently
         */
        bool operator==(const EnumerationNumeric &e) const
        {
            return (this == &e);
        }
        
        /**
         * Inequality test for an EnumerationNumeric. This comparison option takes in an EnumerationNumeric.
         * Inlined because it's called frequently
         */
        bool operator!=(const EnumerationNumeric &e) const
        {
            return (this != &e);
        }

        /**
         * Overloaded string compare operator for the EnumerationNumeric.  This will compare
         * the string to this EnumerationNumeric getName() value.
         * @param rhs
         * @return True if they are equal.
         * @note
         *  Uses the STL string compare method implying that the rules for string
         *  equality are the same as they are for the STL string compare method.
         */
        bool operator==(const std::string& rhs) const;

        /**
         * Overloaded inequality test for this EnumerationNumeric's string value.
         */
        bool operator!=(const std::string& rhs) const;

        /**
         * Overloaded less than test for this EnumerationNumeric's string value.
         */
        bool operator<(const std::string& rhs) const;

        /**
         * Overloaded greater than test for this EnumerationNumeric's string value.
         */
        bool operator>(const std::string& rhs) const;

    protected:
        /**
         * ctor
         * Protected to prevent creation of an instance. 
         */
        EnumerationNumeric(const std::string& name, unsigned int orderId);

        /**
         * dtor
         */
        ~EnumerationNumeric();

    private:
        unsigned int mID;

        /**
         * Private assignment operator to enforce EnumerationNumeric storage by reference.
         */
        EnumerationNumeric& operator=(const EnumerationNumeric&);

        /**
         * Private copy constructor to enforce EnumerationNumeric storage by reference.
         */
        EnumerationNumeric(const EnumerationNumeric&);
    };

    /**
     * Helper method to print EnumerationNumeric to an output stream.
     */
    TR_UTIL_EXPORT std::ostream& operator<<(std::ostream& os, const EnumerationString& e);
}