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

#include <trBase/Export.h>

#include <trUtil/StringUtils.h>
#include <trUtil/Math.h>

#include <osg/Vec2s>

#include <iostream>
#include <string>

namespace trBase
{
    /**
    * General purpose 2D short Vector
    */
    class TR_BASE_EXPORT Vec2s
    {
    public:

        /** Data type of vector components.*/
        using value_type = short;

        const static int NUM_OF_COMPONENTS;

        /**
        * @brief   Default constructor.
        */
        Vec2s();

        /**
        * @brief   Constructor.
        *
        * @param   x   The x component of the vector.
        * @param   y   The y component of the vector.
        */
        Vec2s(value_type x, value_type y);

        /**
        * @brief   Copy Constructor from osg::Vec to trBase::Vec.
        *
        * @param   v   The osg::Vec2 to process.
        */
        Vec2s(const osg::Vec2s &v);

        /**
        * Returns the internal OSG vector.
        */
        const osg::Vec2s& GetOSGVector() const;

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
        * Returns the X component of the vector
        */
        value_type X() const;

        /**
        * Returns the Y component of the vector
        */
        value_type Y() const;

        /**
        * Sets the initial values of the vector
        */
        void Set(value_type x, value_type y);

        /**
        * @brief   Linear interpolation of this vector to a passed in vector.
        *
        * @param   to      The vector that we are interpolating to.
        * @param   alpha   Amount of change (0-1).
        */
        void Lerp(const Vec2s& to, value_type alpha);

        /**
        * @brief   Linear interpolation of two vectors.
        *
        * @param   from    The vector that we are interpolating from.
        * @param   to      The vector that we are interpolating to.
        * @param   alpha   Amount of change (0-1).
        *
        * @return  An interpolated vector.
        */
        Vec2s Lerp(const Vec2s& from, const Vec2s& to, value_type alpha);

        /**
         * @fn  std::string Vec2s::ToString(int precision = -1);
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
        void operator = (const Vec2s& v);

        /**
        * Set operator
        */
        void operator = (const osg::Vec2s& v);

        /**
        * Equality operator
        */
        bool operator == (const Vec2s& v) const;

        /**
        * Inequality operator
        */
        bool operator != (const Vec2s& v) const;

        /**
        * Less than operator
        */
        bool operator <  (const Vec2s& v) const;

        /**
        * Greater than operator
        */
        bool operator >  (const Vec2s& v) const;

        /**
        * Dot product operator.
        */
        value_type operator * (const Vec2s& rhs) const;

        /**
        * Scalar multiplication operator.
        */
        const Vec2s operator * (value_type rhs) const;

        /**
        * Unary scalar multiplication operator.
        */
        Vec2s& operator *= (value_type rhs);

        /**
        * Divide by scalar operator.
        */
        const Vec2s operator / (value_type rhs) const;

        /**
        * Unary divide by scalar operator.
        */
        Vec2s& operator /= (value_type rhs);

        /**
        * Binary vector add operator.
        */
        const Vec2s operator + (const Vec2s& rhs) const;

        /**
        * Unary vector add operator. Slightly more efficient because it has
        * no temporary intermediate objects.
        */
        Vec2s& operator += (const Vec2s& rhs);

        /**
        * Binary vector subtraction operator.
        */
        const Vec2s operator - (const Vec2s& rhs) const;

        /**
        * Unary vector subtraction operator.
        */
        Vec2s& operator -= (const Vec2s& rhs);

        /**
        * Negation operator. Returns the negative of the Vec2d.
        */
        const Vec2s operator - () const;

        /**
        * Implicit conversion operator to OSG Vector
        */
        operator osg::Vec2s() const;

        /**
        * Implicit conversion operator to OSG Vector
        */
        operator osg::Vec2s& ();

        /**
        * Implicit conversion operator to OSG Vector
        */
        operator const osg::Vec2s& () const;

        /**
        * Implicit conversion operator to OSG Vector
        */
        operator osg::Vec2s* ();

    protected:

        osg::Vec2s mVec;
    };

    /**
    * @brief   Stream insertion operator.
    *
    * @param [in,out]  ios The ios.
    * @param           vec The vector.
    *
    * @return  The shifted result.
    */
    TR_BASE_EXPORT std::ostream& operator << (std::ostream& ios, const Vec2s& vec);

    /**
    * Multiply individual vector components.
    */
    TR_BASE_EXPORT Vec2s ComponentMultiply(const Vec2s& lhs, const Vec2s& rhs);

    /**
    * Divide rhs components by rhs vector components.
    */
    TR_BASE_EXPORT Vec2s ComponentDivide(const Vec2s& lhs, const Vec2s& rhs);
}