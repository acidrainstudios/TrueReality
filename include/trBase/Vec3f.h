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

#include <trBase/Export.h>

#include <trUtil/StringUtils.h>
#include <trUtil/Math.h>

#include <osg/Vec3f>

#include <iostream>
#include <string>

/// @cond DOXYGEN_SHOULD_SKIP_THIS
namespace osg
{
    class Vec3d;
}
/// @endcond

namespace trBase
{
    class Vec3d;

    /**
    * General purpose 3D float Vector
    */
    class TR_BASE_EXPORT Vec3f
    {
    public:

        /** Data type of vector components.*/
        using value_type = float;

        const static int NUM_OF_COMPONENTS;

        /**
        * @brief   Default constructor.
        */
        Vec3f();

        /**
        * @brief   Constructor.
        *
        * @param   x   The x component of the vector.
        * @param   y   The y component of the vector.
        * @param   z   The z component of the vector.
        */
        Vec3f(value_type x, value_type y, value_type z);

        /**
        * @brief   Copy Constructor from osg::Vec to trBase::Vec.
        *
        * @param   v   The osg::Vec3f to process.
        */
        Vec3f(const osg::Vec3f &v);

        /**
        * @brief   Copy Constructor from osg::Vec to trBase::Vec.
        *
        * @param   v   The osg::Vec3d to process.
        */
        Vec3f(const osg::Vec3d &v);

        /**
        * Returns the internal OSG vector.
        */
        const osg::Vec3f& GetOSGVector() const;

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
        * Sets the initial values of the vector
        */
        void Set(value_type x, value_type y, value_type z);

        /**
        * Sets the initial values of the vector
        */
        void Set(const Vec3f& v);

        /**
        * Sets the initial values of the vector
        */
        void SetRGB(value_type r, value_type g, value_type b);

        /**
        * @brief   Linear interpolation of this vector to a passed in vector.
        *
        * @param   to      The vector that we are interpolating to.
        * @param   alpha   Amount of change (0-1).
        */
        void Lerp(const Vec3f& to, value_type alpha);

        /**
        * @brief   Linear interpolation of two vectors.
        *
        * @param   from    The vector that we are interpolating from.
        * @param   to      The vector that we are interpolating to.
        * @param   alpha   Amount of change (0-1).
        *
        * @return  An interpolated vector.
        */
        Vec3f Lerp(const Vec3f& from, const Vec3f& to, value_type alpha);

        /**
         * @fn  std::string Vec3f::ToString(int precision = -1);
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
        void operator = (const Vec3f& v);

        /**
        * Set operator
        */
        void operator = (const Vec3d& v);

        /**
        * Set operator
        */
        void operator = (const osg::Vec3f& v);

        /**
        * Equality operator
        */
        bool operator == (const Vec3f& v) const;

        /**
        * Inequality operator
        */
        bool operator != (const Vec3f& v) const;

        /**
        * Less than operator
        */
        bool operator <  (const Vec3f& v) const;

        /**
        * Greater than operator
        */
        bool operator >  (const Vec3f& v) const;

        /**
        * Dot product operator.
        */
        value_type operator * (const Vec3f& rhs) const;

        /**
        * Scalar multiplication operator.
        */
        const Vec3f operator * (value_type rhs) const;

        /**
        * Unary scalar multiplication operator.
        */
        Vec3f& operator *= (value_type rhs);

        /**
        * Divide by scalar operator.
        */
        const Vec3f operator / (value_type rhs) const;

        /**
        * Unary divide by scalar operator.
        */
        Vec3f& operator /= (value_type rhs);

        /**
        * Binary vector add operator.
        */
        const Vec3f operator + (const Vec3f& rhs) const;

        /**
        * Unary vector add operator. Slightly more efficient because it has
        * no temporary intermediate objects.
        */
        Vec3f& operator += (const Vec3f& rhs);

        /**
        * Binary vector subtraction operator.
        */
        const Vec3f operator - (const Vec3f& rhs) const;

        /**
        * Unary vector subtraction operator.
        */
        Vec3f& operator -= (const Vec3f& rhs);

        /**
        * Negation operator. Returns the negative of the Vec3f.
        */
        const Vec3f operator - () const;

        /**
        * Cross product operator.
        */
        const Vec3f operator ^ (const Vec3f& rhs) const;

        /**
        * Implicit conversion operator to OSG Vector
        */
        operator osg::Vec3f() const;

        /**
        * Implicit conversion operator to OSG Vector
        */
        operator osg::Vec3f& ();

        /**
        * Implicit conversion operator to OSG Vector
        */
        operator const osg::Vec3f& () const;

        /**
        * Implicit conversion operator to OSG Vector
        */
        operator osg::Vec3f* ();

    protected:

        osg::Vec3f mVec;
    };

    /**
    * @brief   Stream insertion operator.
    *
    * @param [in,out]  ios The ios.
    * @param           vec The vector.
    *
    * @return  The shifted result.
    */
    TR_BASE_EXPORT std::ostream& operator << (std::ostream& ios, const Vec3f& vec);

    /**
    * Multiply individual vector components.
    */
    TR_BASE_EXPORT Vec3f ComponentMultiply(const Vec3f& lhs, const Vec3f& rhs);

    /**
    * Divide rhs components by rhs vector components.
    */
    TR_BASE_EXPORT Vec3f ComponentDivide(const Vec3f& lhs, const Vec3f& rhs);
}