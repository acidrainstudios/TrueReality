/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2020 Acid Rain Studios LLC
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
* @author Matthew W. Campbell
* @author David Guthrie
* @author Maxim Serebrennik
*/
#pragma once

#include "Export.h"

#include <trUtil/WarningUtils.h>

#include <ostream>
#include <string>
#include <vector>

/**
 * @brief   Disable visual C++ compiler warnings that seem to indicate the compiler is getting
 *          confused when compiling an EnumerationString.
 */
TR_DISABLE_WARNING_START_MSVC(4276)

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil
{
    /**
     * @class   EnumerationString
     *
     * @brief   This class represents a type-safe EnumerationString pattern.  It allows one to also
     *          enumerate an EnumerationString thus looking up values in a list fashion.
     */
    class TR_UTIL_EXPORT EnumerationString
    {
    public:

        /**
         * @fn  const std::string& EnumerationString::GetName() const
         *
         * @brief   Inlined because it's called frequently.
         *
         * @return  the string representation of this EnumerationString.
         */
        const std::string& GetName() const
        {
            return mName;
        }

        /**
         * @fn  bool EnumerationString::operator==(const EnumerationString& rhs) const
         *
         * @brief   Equality test for an EnumerationString.  Since EnumerationString objects are static,
         *          and only references to EnumerationStrings may be stored by the user, it is safe and
         *          efficient to compare EnumerationString objects based on their memory address. Inlined
         *          because it's called frequently.
         *
         * @param   rhs The right hand side.
         *
         * @return  True if the parameters are considered equivalent.
         */
        bool operator==(const EnumerationString& rhs) const
        {
            return this == &rhs;
        }

        /**
         * @fn  bool EnumerationString::operator!=(const EnumerationString& rhs) const
         *
         * @brief   Inequality test for an EnumerationString. Inlined because it's called frequently.
         *
         * @param   rhs The right hand side.
         *
         * @return  True if the parameters are not considered equivalent.
         *
         * @sa  operator==
         */
        bool operator!=(const EnumerationString& rhs) const
        {
            return this != &rhs;
        }

        /**
         * @fn  bool EnumerationString::operator==(const std::string& rhs) const;
         *
         * @brief   Overloaded string compare operator for the EnumerationString.  This will compare the
         *          string to this EnumerationStrings getName() value.
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
         * @fn  bool EnumerationString::operator!=(const std::string& rhs) const;
         *
         * @brief   Overloaded inequality test for this EnumerationString's string value.
         *
         * @param   rhs The right hand side.
         *
         * @return  True if the parameters are not considered equivalent.
         */
        bool operator!=(const std::string& rhs) const;

        /**
         * @fn  bool EnumerationString::operator<(const std::string& rhs) const;
         *
         * @brief   Overloaded less than test for this EnumerationString's string value.
         *
         * @param   rhs The right hand side.
         *
         * @return  True if the first parameter is less than the second.
         */
        bool operator<(const std::string& rhs) const;

        /**
         * @fn  bool EnumerationString::operator>(const std::string& rhs) const;
         *
         * @brief   Overloaded greater than test for this EnumerationString's string value.
         *
         * @param   rhs The right hand side.
         *
         * @return  True if the first parameter is greater than to the second.
         */
        bool operator>(const std::string& rhs) const;

        /**
         * @fn  bool EnumerationString::operator<(const EnumerationString& rhs) const
         *
         * @brief   Overloaded less than operator.  This checks the memory addresses of the two
         *          EnumerationStrings. Inlined because it's called frequently.
         *
         * @param   rhs The second EnumerationString to compare to this one.
         *
         * @return  True if this EnumerationString is less than rhs.
         *          @note
         *          This method is supported by EnumerationStrings so they may be used as keys in STL
         *          containers.  Since memory addresses are guaranteed to be unique this methods works
         *          fine.  However, it really does not make sense to use this method of comparison in
         *          other circumstances.
         */
        bool operator<(const EnumerationString& rhs) const
        {
            return this < &rhs;
        }
    protected:

        /**
         * @fn  virtual int EnumerationString::Compare(const std::string& nameString) const;
         *
         * @brief   Virtual string compare method to used by the operators that take a string.  This
         *          allows overriding the behavior in a subclass. It should work like
         *          std::string::compare.
         *
         * @param   nameString  The constant standard string&amp; to compare to this object.
         *
         * @return  Negative if 'nameString' is less than '', 0 if they are equal, or positive if it is
         *          greater.
         */
        virtual int Compare(const std::string& nameString) const;

        /**
         * @fn  virtual EnumerationString::~EnumerationString();
         *
         * @brief   Private virtual destructor to get rid of compile warning.
         */
        virtual ~EnumerationString();

        /**
         * @fn  EnumerationString::EnumerationString(const std::string& name);
         *
         * @brief   Construct the EnumerationString.
         *           @note
         *               When creating a new EnumerationString, the constructor of derived types must
         *               call addInstance(this) in order for EnumerationStrings to be enumerated.
         *
         * @param   name    The name.
         */
        EnumerationString(const std::string& name);
    private:

        /**
         * @fn  EnumerationString& EnumerationString::operator=(const EnumerationString&);
         *
         * @brief   Private assignment operator to enforce EnumerationString storage by reference.
         *
         * @param   parameter1  The first parameter.
         *
         * @return  A shallow copy of this object.
         */
        EnumerationString& operator=(const EnumerationString&);

        /** @brief   String representation of the EnumerationString. */
        std::string mName;

        /**
         * @fn  EnumerationString::EnumerationString(const EnumerationString&);
         *
         * @brief   Private copy constructor to enforce EnumerationString storage by reference.
         *
         * @param   parameter1  The first parameter.
         */
        EnumerationString(const EnumerationString&);
    };

     /**
      * @fn std::ostream& operator<<(std::ostream& os, const EnumerationString& e);
      *
      * @brief  Helper method to print EnumerationStrings to an output stream.
      *
      * @param [in,out] os  The operating system.
      * @param          e   The EnumerationString to process.
      *
      * @return The shifted result.
      */
    TR_UTIL_EXPORT std::ostream& operator<<(std::ostream& os, const EnumerationString& e);

    //////////////////////////////////////////////////////

/**
 * @def DECLARE_ENUM(EnumType);
 *
 * @brief   Helper macros used to create the static data and methods needed to enumerate an
 *          EnumerationString.
 *
 * @param   EnumType    Type of the enum.
 */
#define DECLARE_ENUM(EnumType)                                 \
public:                                                        \
    using EnumerateListType = std::vector<EnumType*>;           \
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

/**
 * @def IMPLEMENT_ENUM(EnumType);
 *
 * @brief   A macro that defines implement enum.
 *
 * @param   EnumType    Type of the enum.
 */
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
     * @class   EnumerationPointer
     *
     * @brief   EnumerationString Pointer class holds a reference to a passed in Enumeration. This is
     *          a container class for TR Enumerations.
     */
    template <typename T>
    class EnumerationPointer
    {
    public:
        /** @brief   Type of the element. */
        using element_type = T;

        /**
         * @fn  EnumerationPointer::EnumerationPointer()
         *
         * @brief   A constructor that creates and empty pointer.
         */
        EnumerationPointer() : mEnum(nullptr)
        {
        }

        /**
         * @fn  EnumerationPointer::EnumerationPointer(T* ptr)
         *
         * @brief   A constructor that creates a pointer from a passed in EnumerationString.
         *
         * @param [in,out]  ptr If non-null, the pointer.
         */
        EnumerationPointer(T* ptr) : mEnum(ptr)
        {
        }

        /**
         * @fn  EnumerationPointer::EnumerationPointer(const EnumerationPointer& rp)
         *
         * @brief   A constructor that creates a pointer from another EnumerationString Pointer.
         *
         * @param   rp  The rp.
         */
        EnumerationPointer(const EnumerationPointer& rp) : mEnum(rp.mEnum)
        {
        }

        /**
         * @fn  template<class Other> EnumerationPointer::EnumerationPointer(const EnumerationPointer<Other>& rp)
         *
         * @brief   A templated pointer constructor that can create an EnumerationString pointer from an
         *          EnumerationString pointer of a different type.
         *
         * @tparam  Other   Type of the other.
         * @param   rp  The rp.
         */
        template<class Other> EnumerationPointer(const EnumerationPointer<Other>& rp) : mEnum(rp.mEnum)
        {
        }

        /**
         * @fn  EnumerationPointer::~EnumerationPointer()
         *
         * @brief   Destructor.
         */
        ~EnumerationPointer()
        {
            mEnum = nullptr;
        }

        /**
         * @fn  operator EnumerationPointer::T*() const
         *
         * @brief   Pointer operator.
         *
         * @return  The result of the operation.
         */
        operator T*() const
        {
            return mEnum;
        }

        /**
         * @fn  operator EnumerationPointer::T&() const
         *
         * @brief   Reference Operator.
         *
         * @return  The result of the operation.
         */
        operator T&() const
        {
            return *mEnum;
        }

        /**
         * @fn  EnumerationPointer& EnumerationPointer::operator=(const EnumerationPointer& rp)
         *
         * @brief   Assignment by reference operator.
         *
         * @param   rp  The rp.
         *
         * @return  A shallow copy of this object.
         */
        EnumerationPointer& operator=(const EnumerationPointer& rp)
        {
            mEnum = rp.mEnum;
            return *this;
        }

        /**
         * @fn  template<class Other> EnumerationPointer& EnumerationPointer::operator=(const EnumerationPointer<Other>& rp)
         *
         * @brief   Assignment by reference operator.
         *
         * @tparam  Other   Type of the other.
         * @param   rp  The rp.
         *
         * @return  The result of the operation.
         */
        template<class Other> EnumerationPointer& operator=(const EnumerationPointer<Other>& rp)
        {
            /** @brief   . */
            mEnum = rp.mEnum;
            /** @brief   this. */
            return *this;
        }

        /**
         * @fn  inline EnumerationPointer& EnumerationPointer::operator=(T* ptr)
         *
         * @brief   Assignment from a pointer operator.
         *
         * @param [in,out]  ptr If non-null, the pointer.
         *
         * @return  A shallow copy of this object.
         */
        inline EnumerationPointer& operator=(T* ptr)
        {
            if (mEnum == ptr) return *this;
            mEnum = ptr;
            return *this;
        }

        /**
         * @fn  inline EnumerationPointer& EnumerationPointer::operator=(T& enumRef)
         *
         * @brief   Assignment from a reference operator.
         *
         * @param [in,out]  enumRef The enum reference.
         *
         * @return  A shallow copy of this object.
         */
        inline EnumerationPointer& operator=(T& enumRef)
        {
            if (mEnum == &enumRef) return *this;
            mEnum = &enumRef;
            return *this;
        }

        /**
         * @fn  bool EnumerationPointer::operator==(const EnumerationPointer& rp) const
         *
         * @brief   Comparison between two EnumerationPointers.
         *
         * @param   rp  The rp.
         *
         * @return  True if the parameters are considered equivalent.
         */
        bool operator==(const EnumerationPointer& rp) const
        {
            return (mEnum == rp.mEnum);
        }

        /**
         * @fn  bool EnumerationPointer::operator==(const T* ptr) const
         *
         * @brief   Comparison between EnumerationPointers and a pointer.
         *
         * @param   ptr The pointer.
         *
         * @return  True if the parameters are considered equivalent.
         */
        bool operator==(const T* ptr) const
        {
            return (mEnum == ptr);
        }

        /**
         * @fn  friend bool EnumerationPointer::operator==(const T* ptr, const EnumerationPointer& rp)
         *
         * @brief   Comparison between EnumerationPointer and a pointer.
         *
         * @param   ptr The first instance to compare.
         * @param   rp  The second instance to compare.
         *
         * @return  True if the parameters are considered equivalent.
         */
        friend bool operator==(const T* ptr, const EnumerationPointer& rp)
        {
            return (ptr == rp.mEnum);
        }

        /**
         * @fn  bool EnumerationPointer::operator!=(const EnumerationPointer& rp) const
         *
         * @brief   Comparison between two EnumerationPointers.
         *
         * @param   rp  The rp.
         *
         * @return  True if the parameters are not considered equivalent.
         */
        bool operator!=(const EnumerationPointer& rp) const
        {
            return (mEnum != rp.mEnum);
        }

        /**
         * @fn  bool EnumerationPointer::operator!=(const T* ptr) const
         *
         * @brief   Comparison between EnumerationPointers and a pointer.
         *
         * @param   ptr The pointer.
         *
         * @return  True if the parameters are not considered equivalent.
         */
        bool operator!=(const T* ptr) const
        {
            return (mEnum != ptr);
        }

        /**
         * @fn  friend bool EnumerationPointer::operator!=(const T* ptr, const EnumerationPointer& rp)
         *
         * @brief   Comparison between EnumerationPointer and a pointer.
         *
         * @param   ptr The first instance to compare.
         * @param   rp  The second instance to compare.
         *
         * @return  True if the parameters are not considered equivalent.
         */
        friend bool operator!=(const T* ptr, const EnumerationPointer& rp)
        {
            return (ptr != rp.mEnum);
        }

        /**
         * @fn  bool EnumerationPointer::operator<(const EnumerationPointer& rp) const
         *
         * @brief   Overloaded less than test for this EnumerationString pointers's string value.
         *
         * @param   rp  The rp.
         *
         * @return  True if the first parameter is less than the second.
         */
        bool operator<(const EnumerationPointer& rp) const
        {
            return (mEnum < rp.mEnum);
        }

        /**
         * @fn  bool EnumerationPointer::operator>(const EnumerationPointer& rp) const
         *
         * @brief   Overloaded greater than test for this EnumerationString pointers's string value.
         *
         * @param   rp  The rp.
         *
         * @return  True if the first parameter is greater than to the second.
         */
        bool operator>(const EnumerationPointer& rp) const
        {
            return (mEnum > rp.mEnum);
        }

        /**
         * @fn  T& EnumerationPointer::operator*() const
         *
         * @brief   Pointer operator that returns a reference.
         *
         * @return  The result of the operation.
         */
        T& operator*() const
        {
            return *mEnum;
        }

        /**
         * @fn  T* EnumerationPointer::operator->() const
         *
         * @brief   Pointer method access operator.
         *
         * @return  The dereferenced object.
         */
        T* operator->() const
        {
            return mEnum;
        }

        /**
         * @fn  T* EnumerationPointer::get() const
         *
         * @brief   Pointer access operator.
         *
         * @return  Null if it fails, else a pointer to a T.
         */
        T* get() const
        {
            return mEnum;
        }

        /**
         * @fn  bool EnumerationPointer::operator!() const
         *
         * @brief   The NOT operator.
         *
         * @return  The logical inverse of this value.
         */
        bool operator!() const
        {
            return mEnum == nullptr;
        } // not required

        /**
         * @fn  bool EnumerationPointer::valid() const
         *
         * @brief   Returns FALSE if the pointer is nullptr.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool valid() const
        {
            return mEnum != nullptr;
        }

        /**
         * @fn  void EnumerationPointer::swap(EnumerationPointer& rp)
         *
         * @brief   Swaps the internal object with the passed in.
         *
         * @param [in,out]  rp  The rp.
         */
        void swap(EnumerationPointer& rp)
        {
            T* tmp = mEnum;
            mEnum = rp.mEnum;
            rp.mEnum = tmp;
        }
    private:
        /** @brief   The enum. */
        T* mEnum;
    };
}
TR_DISABLE_WARNING_END