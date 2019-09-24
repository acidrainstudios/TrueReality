/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2019 Acid Rain Studios LLC
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

#include <trBase/Export.h>

#include <trUtil/StringUtils.h>
#include <trUtil/Math.h>

#include <osg/Vec4d>

#include <iostream>
#include <string>

/// @cond DOXYGEN_SHOULD_SKIP_THIS
namespace osg
{
    class Vec4f;
}
/// @endcond

namespace trBase
{
    class Vec4f;

    /**
    * General purpose 3D double Vector
    */
    class TR_BASE_EXPORT Vec4d
    {
    public:

        /** Data type of vector components.*/
        using value_type = double;

        const static int NUM_OF_COMPONENTS;

        /**
        * @brief   Default constructor.
        */
        Vec4d();

        /**
        * @brief   Constructor.
        *
        * @param   x   The x component of the vector.
        * @param   y   The y component of the vector.
        * @param   z   The z component of the vector.
        * @param   w   The w component of the vector.
        */
        Vec4d(value_type x, value_type y, value_type z, value_type w);

        /**
        * @brief   Copy Constructor from osg::Vec to trBase::Vec.
        *
        * @param   v   The osg::Vec4d to process.
        */
        Vec4d(const osg::Vec4d &v);

        /**
        * @brief   Copy Constructor from osg::Vec to trBase::Vec.
        *
        * @param   v   The osg::Vec4f to process.
        */
        Vec4d(const osg::Vec4f &v);

        /**
        * Returns the internal OSG vector.
        */
        const osg::Vec4d& GetOSGVector() const;

        /**
        * Length of the vector = sqrt( vec . vec )
        */
        value_type Length() const;

        /**
        * Length squared of the vector = vec . vec
        */
        value_type Length2() const;

        /**
        * Normalize the vector so that it has length unity.
        * Returns the previous length of the vector.
        */
        value_type Normalize();

        /**
        * Returns the X component of the vector
        */
        value_type& X();

        /**
        * Returns the Y component of the vector
        */
        value_type& Y();

        /**
        * Returns the Z component of the vector
        */
        value_type& Z();

        /**
        * Returns the W component of the vector
        */
        value_type& W();

        /**
        * Returns the X component of the vector
        */
        value_type X() const;

        /**
        * Returns the Y component of the vector
        */
        value_type Y() const;

        /**
        * Returns the Z component of the vector
        */
        value_type Z() const;

        /**
        * Returns the W component of the vector
        */
        value_type W() const;

        /**
        * Returns the R component of the vector
        */
        value_type& R();

        /**
        * Returns the G component of the vector
        */
        value_type& G();

        /**
        * Returns the B component of the vector
        */
        value_type& B();

        /**
        * Returns the A component of the vector
        */
        value_type& A();

        /**
        * Returns the R component of the vector
        */
        value_type R() const;

        /**
        * Returns the G component of the vector
        */
        value_type G() const;

        /**
        * Returns the B component of the vector
        */
        value_type B() const;

        /**
        * Returns the A component of the vector
        */
        value_type A() const;

        /**
        * Sets the initial values of the vector
        */
        void Set(value_type x, value_type y, value_type z, value_type w);

        /**
        * Sets the initial values of the vector
        */
        void Set(const Vec4d& v);

        /**
        * Sets the initial values of the vector
        */
        void SetRGBA(value_type r, value_type g, value_type b, value_type a);

        /**
        * @brief   Linear interpolation of this vector to a passed in vector.
        *
        * @param   to      The vector that we are interpolating to.
        * @param   alpha   Amount of change (0-1).
        */
        void Lerp(const Vec4d& to, value_type alpha);

        /**
        * @brief   Linear interpolation of two vectors.
        *
        * @param   from    The vector that we are interpolating from.
        * @param   to      The vector that we are interpolating to.
        * @param   alpha   Amount of change (0-1).
        *
        * @return  An interpolated vector.
        */
        Vec4d Lerp(const Vec4d& from, const Vec4d& to, value_type alpha);

        /**
         * @fn  std::string Vec4d::ToString(int precision = -1);
         *
         * @brief   Convert this object into a string representation.
         *
         * @param   precision   (Optional) The precision.
         *
         * @return  A std::string that represents this object.
         */
        std::string ToString(int precision = -1);

        /**
        *  Pointer to the internal Vector array.
        */
        value_type* Ptr();

        /**
        *  Pointer to the internal Vector array.
        */
        const value_type* Ptr() const;

        /**
        * Index operator
        */
        value_type& operator [] (int i);

        /**
        * Index operator
        */
        value_type operator [] (int i) const;

        /**
        * Set operator
        */
        void operator = (const Vec4d& v);

        /**
        * Set operator
        */
        void operator = (const Vec4f& v);

        /**
        * Set operator
        */
        void operator = (const osg::Vec4d& v);

        /**
        * Equality operator
        */
        bool operator == (const Vec4d& v) const;

        /**
        * Inequality operator
        */
        bool operator != (const Vec4d& v) const;

        /**
        * Less than operator
        */
        bool operator <  (const Vec4d& v) const;

        /**
        * Greater than operator
        */
        bool operator >  (const Vec4d& v) const;

        /**
        * Dot product operator.
        */
        value_type operator * (const Vec4d& rhs) const;

        /**
        * Scalar multiplication operator.
        */
        const Vec4d operator * (value_type rhs) const;

        /**
        * Unary scalar multiplication operator.
        */
        Vec4d& operator *= (value_type rhs);

        /**
        * Divide by scalar operator.
        */
        const Vec4d operator / (value_type rhs) const;

        /**
        * Unary divide by scalar operator.
        */
        Vec4d& operator /= (value_type rhs);

        /**
        * Binary vector add operator.
        */
        const Vec4d operator + (const Vec4d& rhs) const;

        /**
        * Unary vector add operator. Slightly more efficient because it has
        * no temporary intermediate objects.
        */
        Vec4d& operator += (const Vec4d& rhs);

        /**
        * Binary vector subtraction operator.
        */
        const Vec4d operator - (const Vec4d& rhs) const;

        /**
        * Unary vector subtraction operator.
        */
        Vec4d& operator -= (const Vec4d& rhs);


        /**
        * Negation operator. Returns the negative of the Vec4d.
        */
        const Vec4d operator - () const;

        /**
        * Implicit conversion operator to OSG Vector
        */
        operator osg::Vec4d() const;

        /**
        * Implicit conversion operator to OSG Vector
        */
        operator osg::Vec4d& ();

        /**
        * Implicit conversion operator to OSG Vector
        */
        operator const osg::Vec4d& () const;

        /**
        * Implicit conversion operator to OSG Vector
        */
        operator osg::Vec4d* ();

    protected:

        osg::Vec4d mVec;
    };

    /**
    * @brief   Stream insertion operator.
    *
    * @param [in,out]  ios The ios.
    * @param           vec The vector.
    *
    * @return  The shifted result.
    */
    TR_BASE_EXPORT std::ostream& operator << (std::ostream& ios, const Vec4d& vec);

    /**
    * Multiply individual vector components.
    */
    TR_BASE_EXPORT Vec4d ComponentMultiply(const Vec4d& lhs, const Vec4d& rhs);

    /**
    * Divide rhs components by rhs vector components.
    */
    TR_BASE_EXPORT Vec4d ComponentDivide(const Vec4d& lhs, const Vec4d& rhs);
}