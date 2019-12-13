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
#pragma once

#include "Export.h"

#include <trUtil/EnumerationString.h>

#include <ostream>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil
{
    /**
     * @class   EnumerationNumeric
     *
     * @brief   This class represents a type-safe Enumeration pattern.  It allows one to also
     *          enumerate an Enumeration thus looking up values in a list fashion. Unlike
     *          EnumerationString, EnumerationNumeric also stores an integer value with each Enum.
     *          
     * @author Maxim Serebrennik
     */
    class TR_UTIL_EXPORT EnumerationNumeric : public EnumerationString
    {
    public:
        /** @brief   / Adds an easy and swappable access to the base class. */
        using BaseClass = EnumerationString;

        /**
         * @fn  unsigned int EnumerationNumeric::GetID() const;
         *
         * @brief   Returns the Numeric value of the Enum.
         *
         * @return  The identifier.
         */
        unsigned int GetID() const;

        /**
         * @fn  bool EnumerationNumeric::operator==(const unsigned int &id) const
         *
         * @brief   Equality test for an EnumerationNumeric. This comparison option takes in an unsigned
         *          integer. Inlined because it's called frequently.
         *
         * @param   id  The identifier.
         *
         * @return  True if the parameters are considered equivalent.
         */
        bool operator==(const unsigned int &id) const
        {
            return (mID == id);
        }

        /**
         * @fn  bool EnumerationNumeric::operator!=(const unsigned int &id) const
         *
         * @brief   Inequality test for an EnumerationNumeric. This comparison option takes in an
         *          unsigned integer. Inlined because it's called frequently.
         *
         * @param   id  The identifier.
         *
         * @return  True if the parameters are not considered equivalent.
         */
        bool operator!=(const unsigned int &id) const
        {
            return (mID != id);
        }

        /**
         * @fn  bool EnumerationNumeric::operator>(const unsigned int &id) const
         *
         * @brief   Greater than test for an EnumerationNumeric. This comparison option takes in an
         *          unsigned integer. Inlined because it's called frequently.
         *
         * @param   id  The identifier.
         *
         * @return  True if the first parameter is greater than to the second.
         */
        bool operator>(const unsigned int &id) const
        {
            return (mID > id);
        }

        /**
         * @fn  bool EnumerationNumeric::operator<(const unsigned int &id) const
         *
         * @brief   Less than test for an EnumerationNumeric. This comparison option takes in an unsigned
         *          integer. Inlined because it's called frequently.
         *
         * @param   id  The identifier.
         *
         * @return  True if the first parameter is less than the second.
         */
        bool operator<(const unsigned int &id) const
        {
            return (mID < id);
        }

        /**
         * @fn  bool EnumerationNumeric::operator>(const EnumerationNumeric &e) const
         *
         * @brief   Greater than test for an EnumerationNumeric. This comparison option takes in an
         *          EnumerationNumeric. Inlined because it's called frequently.
         *
         * @param   e   The EnumerationNumeric to process.
         *
         * @return  True if the first parameter is greater than to the second.
         */
        bool operator>(const EnumerationNumeric &e) const
        {
            return (mID > e.mID);
        }

        /**
         * @fn  bool EnumerationNumeric::operator<(const EnumerationNumeric &e) const
         *
         * @brief   Less than test for an EnumerationNumeric. This comparison option takes in an
         *          EnumerationNumeric. Inlined because it's called frequently.
         *
         * @param   e   The EnumerationNumeric to process.
         *
         * @return  True if the first parameter is less than the second.
         */
        bool operator<(const EnumerationNumeric &e) const
        {
            return (mID < e.mID);
        }

        /**
         * @fn  bool EnumerationNumeric::operator==(const EnumerationNumeric &e) const
         *
         * @brief   Equality test for an EnumerationNumeric. This comparison option takes in an
         *          EnumerationNumeric. Inlined because it's called frequently.
         *
         * @param   e   The EnumerationNumeric to process.
         *
         * @return  True if the parameters are considered equivalent.
         */
        bool operator==(const EnumerationNumeric &e) const
        {
            return (this == &e);
        }

        /**
         * @fn  bool EnumerationNumeric::operator!=(const EnumerationNumeric &e) const
         *
         * @brief   Inequality test for an EnumerationNumeric. This comparison option takes in an
         *          EnumerationNumeric. Inlined because it's called frequently.
         *
         * @param   e   The EnumerationNumeric to process.
         *
         * @return  True if the parameters are not considered equivalent.
         */
        bool operator!=(const EnumerationNumeric &e) const
        {
            return (this != &e);
        }

        /**
         * @fn  bool EnumerationNumeric::operator==(const std::string& rhs) const;
         *
         * @brief   Overloaded string compare operator for the EnumerationNumeric.  This will compare the
         *          string to this EnumerationNumeric getName() value.
         *
         * @param   rhs .
         *
         * @return  True if they are equal.
         *          @note
         *          Uses the STL string compare method implying that the rules for string equality are
         *          the same as they are for the STL string compare method.
         */
        bool operator==(const std::string& rhs) const;

        /**
         * @fn  bool EnumerationNumeric::operator!=(const std::string& rhs) const;
         *
         * @brief   Overloaded inequality test for this EnumerationNumeric's string value.
         *
         * @param   rhs The right hand side.
         *
         * @return  True if the parameters are not considered equivalent.
         */
        bool operator!=(const std::string& rhs) const;

        /**
         * @fn  bool EnumerationNumeric::operator<(const std::string& rhs) const;
         *
         * @brief   Overloaded less than test for this EnumerationNumeric's string value.
         *
         * @param   rhs The right hand side.
         *
         * @return  True if the first parameter is less than the second.
         */
        bool operator<(const std::string& rhs) const;

        /**
         * @fn  bool EnumerationNumeric::operator>(const std::string& rhs) const;
         *
         * @brief   Overloaded greater than test for this EnumerationNumeric's string value.
         *
         * @param   rhs The right hand side.
         *
         * @return  True if the first parameter is greater than to the second.
         */
        bool operator>(const std::string& rhs) const;

    protected:

        /**
         * @fn  EnumerationNumeric::EnumerationNumeric(const std::string& name, unsigned int orderId);
         *
         * @brief   ctor Protected to prevent creation of an instance.
         *
         * @param   name    The name.
         * @param   orderId Identifier for the order.
         */
        EnumerationNumeric(const std::string& name, unsigned int orderId);

        /**
         * @fn  EnumerationNumeric::~EnumerationNumeric();
         *
         * @brief   dtor.
         */
        ~EnumerationNumeric();

    private:
        /** @brief   The identifier. */
        unsigned int mID;

        /**
         * @fn  EnumerationNumeric& EnumerationNumeric::operator=(const EnumerationNumeric&);
         *
         * @brief   Private assignment operator to enforce EnumerationNumeric storage by reference.
         *
         * @param   parameter1  The first parameter.
         *
         * @return  A shallow copy of this object.
         */
        EnumerationNumeric& operator=(const EnumerationNumeric&);

        /**
         * @fn  EnumerationNumeric::EnumerationNumeric(const EnumerationNumeric&);
         *
         * @brief   Private copy constructor to enforce EnumerationNumeric storage by reference.
         *
         * @param   parameter1  The first parameter.
         */
        EnumerationNumeric(const EnumerationNumeric&);
    };

     /**
      * @fn std::ostream& operator<<(std::ostream& os, const EnumerationString& e);
      *
      * @brief  Helper method to print EnumerationNumeric to an output stream.
      *
      * @param [in,out] os  The operating system.
      * @param          e   The EnumerationString to process.
      *
      * @return The shifted result.
      */
    TR_UTIL_EXPORT std::ostream& operator<<(std::ostream& os, const EnumerationString& e);
}