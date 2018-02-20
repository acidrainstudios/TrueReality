/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
*
* The Base of this class has been adopted from the Delta3D engine
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
* Class Inspired by the Delta3D Engine
* http://delta3dengine.org/
*
* Author: Matthew W. Campbell
* Author: David Guthrie
* Author: Maxim Serebrennik
*/
#pragma once

#include "Export.h"

#include <trUtil/WarningUtils.h>

#include <ostream>
#include <string>
#include <vector>

//Disable visual C++ compiler warnings that seem to indicate the compiler is
//getting confused when compiling an EnumerationString.
TR_DISABLE_WARNING_START_MSVC(4276)

namespace trUtil
{
    /**
     * This class represents a type-safe EnumerationString pattern.  It allows one to
     * also enumerate an EnumerationString thus looking up values in a list fashion.
     */
    class TR_UTIL_EXPORT EnumerationString
    {
    public:
        /**
         * Inlined because it's called frequently
         * @return the string representation of this EnumerationString.
         */
        const std::string& GetName() const
        {
            return mName;
        }
        
        /**
         * Equality test for an EnumerationString.  Since EnumerationString objects are static,
         * and only references to EnumerationStrings may be stored by the user, it is
         * safe and efficient to compare EnumerationString objects based on their memory
         * address.
         * Inlined because it's called frequently
         */
        bool operator==(const EnumerationString& rhs) const
        {
            return this == &rhs;
        }
        
        /**
         * Inequality test for an EnumerationString.
         * Inlined because it's called frequently
         * @see operator==
         */
        bool operator!=(const EnumerationString& rhs) const
        {
            return this != &rhs;
        }

        /**
         * Overloaded string compare operator for the EnumerationString.  This will compare
         * the string to this EnumerationStrings getName() value.
         * @param rhs
         * @return True if they are equal.
         * @note
         *  Uses the STL string compare method implying that the rules for string
         *  equality are the same as they are for the STL string compare method.
         */
        bool operator==(const std::string& rhs) const;

        /**
         * Overloaded inequality test for this EnumerationString's string value.
         */
        bool operator!=(const std::string& rhs) const;

        /**
         * Overloaded less than test for this EnumerationString's string value.
         */
        bool operator<(const std::string& rhs) const;

        /**
         * Overloaded greater than test for this EnumerationString's string value.
         */
        bool operator>(const std::string& rhs) const;
        
        /**
         * Overloaded less than operator.  This checks the memory addresses of the two
         * EnumerationStrings.
         * Inlined because it's called frequently
         * @param rhs The second EnumerationString to compare to this one.
         * @return True if this EnumerationString is less than rhs.
         * @note
         *  This method is supported by EnumerationStrings so they may be used as keys
         *  in STL containers.  Since memory addresses are guaranteed to be unique
         *  this methods works fine.  However, it really does not make sense to use
         *  this method of comparison in other circumstances.
         */
        bool operator<(const EnumerationString& rhs) const
        {
            return this < &rhs;
        }
    protected:
        /**
         * Virtual string compare method to used by the operators that take a string.  This allows overriding the behavior in a subclass.
         * It should work like std::string::compare
         */
        virtual int Compare(const std::string& nameString) const;

        /**
         * Private virtual destructor to get rid of compile warning
         */
        virtual ~EnumerationString();

        /**
         * Construct the EnumerationString.
         *  @note
         *      When creating a new EnumerationString, the constructor of derived types
         *      must call addInstance(this) in order for EnumerationStrings to be
         *      enumerated.
         */
        EnumerationString(const std::string& name);
    private:
        /**
         * Private assignment operator to enforce EnumerationString storage by reference.
         */
        EnumerationString& operator=(const EnumerationString&);

        /**
         * String representation of the EnumerationString.
         */
        std::string mName;

        /**
         * Private copy constructor to enforce EnumerationString storage by reference.
         */
        EnumerationString(const EnumerationString&);
    };

    /**
     * Helper method to print EnumerationStrings to an output stream.
     */
    TR_UTIL_EXPORT std::ostream& operator<<(std::ostream& os, const EnumerationString& e);

    //////////////////////////////////////////////////////

    /**
     * Helper macros used to create the static data and methods
     * needed to enumerate an EnumerationString.
     */
#define DECLARE_ENUM(EnumType)                                 \
public:                                                        \
    typedef std::vector<EnumType*> EnumerateListType;           \
    \
    static const EnumerateListType& EnumerateType()             \
    {                                                           \
    return EnumType::mInstances;                             \
    }                                                           \
    \
    static const std::vector<trUtil::EnumerationString*>& Enumerate() \
    {                                                           \
    return EnumType::mGenericInstances;                      \
    }                                                           \
    \
    static EnumType* GetValueForName(const std::string& name);  \
    \
private:                                                       \
    static EnumerateListType mInstances;                        \
    static std::vector<trUtil::EnumerationString*> mGenericInstances; \
    static void AddInstance(EnumType* instance);                \
public:


#define IMPLEMENT_ENUM(EnumType)                               \
    EnumType::EnumerateListType EnumType::mInstances;           \
    std::vector<trUtil::EnumerationString*> EnumType::mGenericInstances; \
    void EnumType::AddInstance(EnumType* instance)                 \
    {                                                           \
    EnumType::mInstances.push_back(instance);                \
    EnumType::mGenericInstances.push_back(instance);         \
    }                                                           \
    EnumType* EnumType::GetValueForName(const std::string& name)   \
    {                                                           \
    for (unsigned i = 0; i < mInstances.size(); ++i)         \
    {                                                        \
    if ((*mInstances[i]) == name)                 \
    {                                                     \
    return mInstances[i];                              \
    }                                                     \
    }                                                        \
    return nullptr;                                             \
    }

    //////////////////////////////////////////////////////
    /**
     * EnumerationString Pointer class holds a reference to a passed in Enumeration. 
     * This is a container class for TR Enumerations
     */
    template <typename T>
    class EnumerationPointer
    {
    public:
        typedef T element_type;
        /**
         * A constructor that creates and empty pointer
         */
        EnumerationPointer() : mEnum(nullptr)
        {
        }
        
        /**
         * A constructor that creates a pointer from a passed in EnumerationString
         */
        EnumerationPointer(T* ptr) : mEnum(ptr)
        {
        }
        
        /**
         * A constructor that creates a pointer from another EnumerationString Pointer
         */
        EnumerationPointer(const EnumerationPointer& rp) : mEnum(rp.mEnum)
        {
        }
        
        /**
         * A templated pointer constructor that can create an EnumerationString pointer from an EnumerationString pointer of a different type
         */
        template<class Other> EnumerationPointer(const EnumerationPointer<Other>& rp) : mEnum(rp.mEnum)
        {
        }
        
        /**
         * Destructor
         */
        ~EnumerationPointer()
        {
            mEnum = nullptr;
        }
        
        /**
         * Pointer operator
         */
        operator T*() const
        {
            return mEnum;
        }
        
        /**
         * Reference Operator
         */
        operator T&() const
        {
            return *mEnum;
        }
        
        /**
         * Assignment by reference operator.
         */
        EnumerationPointer& operator=(const EnumerationPointer& rp)
        {
            mEnum = rp.mEnum;
            return *this;
        }
        
        /**
         * Assignment by reference operator.
         */
        template<class Other> EnumerationPointer& operator=(const EnumerationPointer<Other>& rp)
        {
            mEnum = rp.mEnum;
            return *this;
        }
        
        /**
         * Assignment from a pointer operator.
         */
        inline EnumerationPointer& operator=(T* ptr)
        {
            if (mEnum == ptr) return *this;
            mEnum = ptr;
            return *this;
        }
        
        /**
         * Assignment from a reference operator.
         */
        inline EnumerationPointer& operator=(T& enumRef)
        {
            if (mEnum == &enumRef) return *this;
            mEnum = &enumRef;
            return *this;
        }
        
        /**
         * Comparison between two EnumerationPointers
         */
        bool operator==(const EnumerationPointer& rp) const
        {
            return (mEnum == rp.mEnum);
        }
        
        /**
         * Comparison between EnumerationPointers and a pointer
         */
        bool operator==(const T* ptr) const
        {
            return (mEnum == ptr);
        }
        
        /**
         * Comparison between EnumerationPointer and a pointer
         */
        friend bool operator==(const T* ptr, const EnumerationPointer& rp)
        {
            return (ptr == rp.mEnum);
        }
        
        /**
         * Comparison between two EnumerationPointers
         */
        bool operator!=(const EnumerationPointer& rp) const
        {
            return (mEnum != rp.mEnum);
        }
        
        /**
         * Comparison between EnumerationPointers and a pointer
         */
        bool operator!=(const T* ptr) const
        {
            return (mEnum != ptr);
        }
        
        /**
         * Comparison between EnumerationPointer and a pointer
         */
        friend bool operator!=(const T* ptr, const EnumerationPointer& rp)
        {
            return (ptr != rp.mEnum);
        }
        
        /**
         * Overloaded less than test for this EnumerationString pointers's string value.
         */
        bool operator<(const EnumerationPointer& rp) const
        {
            return (mEnum < rp.mEnum);
        }
        
        /**
         * Overloaded greater than test for this EnumerationString pointers's string value.
         */
        bool operator>(const EnumerationPointer& rp) const
        {
            return (mEnum > rp.mEnum);
        }
        
        /**
         * Pointer operator that returns a reference. 
         */
        T& operator*() const
        {
            return *mEnum;
        }
        
        /**
         * Pointer method access operator
         */
        T* operator->() const
        {
            return mEnum;
        }
        
        /**
         * Pointer access operator
         */
        T* get() const
        {
            return mEnum;
        }
        
        /**
         * The NOT operator
         */
        bool operator!() const
        {
            return mEnum == nullptr;
        } // not required
        
        /**
         * Returns FALSE if the pointer is nullptr
         */
        bool valid() const
        {
            return mEnum != nullptr;
        }
        
        /**
         * Swaps the internal object with the passed in
         */
        void swap(EnumerationPointer& rp)
        {
            T* tmp = mEnum;
            mEnum = rp.mEnum;
            rp.mEnum = tmp;
        }
    private:
        T* mEnum;
    };
}
TR_DISABLE_WARNING_END