/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
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
* Author: Maxim Serebrennik
*/
#pragma once
#include "Export.h"

#include <trBase/Vec4f.h>
#include <trBase/Vec4d.h>
#include <trBase/Vec3f.h>
#include <trBase/Vec3d.h>

#include <osg/Quat>

#include <iostream>
#include <string>

namespace trBase
{
    class Matrixd;
    class Matrixf;

    /**
     * @class   Quat
     *
     * @brief   Represents a quaternion, that is used for angular calculations and transformations. 
     */
    class TR_BASE_EXPORT Quat
    {
    public:
        
        typedef double value_type;

        /**
         * @brief   Default constructor.
         */
        Quat();

        /**
         * @brief   Copy constructor.
         *
         * @param [in,out]  q   The Quat to process.
         */
        Quat(const Quat& q);

        /**
         * @brief   Constructor.
         *
         * @param [in,out]  q   The osg::Quat to process.
         */
        Quat(const osg::Quat& q);

        /**
         * @brief   Constructor.
         *
         * @param   x   The x to process.
         * @param   y   The y to process.
         * @param   z   The z to process.
         * @param   w   The w to process.
         */
        Quat(value_type x, value_type y, value_type z, value_type w);

        /**
         * @brief   Constructor.
         *
         * @param   v   The Vec4f to process.
         */
        Quat(const Vec4f& v);

        /**
         * @brief   Constructor.
         *
         * @param   v   The Vec4d to process.
         */
        Quat(const Vec4d& v);

        /**
         * @brief   Constructor.
         *
         * @param   angle   The angle.
         * @param   axis    The axis.
         */
        Quat(value_type angle, const Vec3f& axis);

        /**
         * @brief   Constructor.
         *
         * @param   angle   The angle.
         * @param   axis    The axis.
         */
        Quat(value_type angle, const Vec3d& axis);

        /**
         * @brief   Constructor.
         *
         * @param   angle1  The first angle.
         * @param   axis1   The first axis.
         * @param   angle2  The second angle.
         * @param   axis2   The second axis.
         * @param   angle3  The third angle.
         * @param   axis3   The third axis.
         */
        Quat(value_type angle1, const Vec3f& axis1, value_type angle2, const Vec3f& axis2, value_type angle3, const Vec3f& axis3);

        /**
         * @brief   Constructor.
         *
         * @param   angle1  The first angle.
         * @param   axis1   The first axis.
         * @param   angle2  The second angle.
         * @param   axis2   The second axis.
         * @param   angle3  The third angle.
         * @param   axis3   The third axis.
         */
        Quat(value_type angle1, const Vec3d& axis1, value_type angle2, const Vec3d& axis2, value_type angle3, const Vec3d& axis3);

        /**
        * Returns a reference to the internal OSG Quat.
        */
        osg::Quat& GetOSGQuat();

        /**
        * Returns a reference to the internal OSG Quat.
        */
        const osg::Quat& GetOSGQuat() const;

        /**
         * @brief   Converts this object to a vector 4.
         *
         * @return  A Vec4d.
         */
        Vec4d AsVec4() const;

        /**
         * @brief   Converts this object to a vector 3.
         *
         * @return  A Vec3d.
         */
        Vec3d AsVec3() const;

        /**
         * @brief   Sets the given q.
         *
         * @param [in,out]  q   The q to set.
         */
        void Set(const Quat& q);

        /**
         * @brief   Sets the given q.
         *
         * @param [in,out]  q   The q to set.
         */
        void Set(const osg::Quat& q);

        /**
         * @brief   Sets.
         *
         * @param   x   The x to process.
         * @param   y   The y to process.
         * @param   z   The z to process.
         * @param   w   The w to process.
         */
        void Set(value_type x, value_type y, value_type z, value_type w);

        /**
         * @brief   Sets the given v.
         *
         * @param   v   The v to set.
         */
        void Set(const Vec4f& v);

        /**
         * @brief   Sets the given v.
         *
         * @param   v   The v to set.
         */
        void Set(const Vec4d& v);

        /**
        * Sets the quaternion from the given matrix
        */
        void Set(const Matrixf& matrix);

        /**
        * Sets the quaternion from the given matrix
        */
        void Set(const Matrixd& matrix);

        /**
        * Sets the quaternion from the given matrix
        */
        void Get(Matrixf& matrix) const;

        /**
        * Sets the quaternion from the given matrix
        */
        void Get(Matrixd& matrix) const;

        /**
         * @brief   Sets the given matrix.
         *
         * @param   matrix  The matrix to set.
         */
        void Set(const osg::Matrixf& matrix);

        /**
         * @brief   Sets the given matrix.
         *
         * @param   matrix  The matrix to set.
         */
        void Set(const osg::Matrixd& matrix);

        /**
         * @brief   Gets a the values of the internal matrix.
         *
         * @param [in,out]  matrix  The matrix to get.
         */
        void Get(osg::Matrixf& matrix) const;

        /**
         * @brief   Gets a the values of the internal matrix.
         *
         * @param [in,out]  matrix  The matrix to get.
         */
        void Get(osg::Matrixd& matrix) const;

        /**
         * @brief   return true if the Quat represents a zero rotation, and therefore can be ignored in
         *          computations.
         *
         * @return  True if zero rotation, false if not.
         */
        bool IsZeroRotation() const;

        /**
         * @brief   Length of the quaternion = sqrt( vec . vec )
         *
         * @return  A value_type.
         */
        value_type Length() const;

        /**
         * @brief   Length of the quaternion = vec . vec.
         *
         * @return  A value_type.
         */
        value_type Length2() const;

        /**
         * @brief   Conjugate.
         *
         * @return  A Quat.
         */
        trBase::Quat Conj() const;

        /**
         * @brief   Multiplicative inverse method: q^(-1) = q^* /(q.q^*)
         *
         * @return  A const Quat.
         */
        const trBase::Quat Inverse() const;

        /**
         * @brief   Set a quaternion which will perform a rotation of an angle around the axis given by
         *          the vector(x, y, z).
         *
         * @param   angle   The angle.
         * @param   x       The x to process.
         * @param   y       The y to process.
         * @param   z       The z to process.
         */
        void MakeRotate(value_type  angle, value_type  x, value_type  y, value_type  z);

        /**
         * @brief   Set a quaternion which will perform a rotation of an angle around the axis given by
         *          the vector(x, y, z).
         *
         * @param   angle   The angle.
         * @param   vec     The vector.
         */
        void MakeRotate(value_type  angle, const Vec3f& vec);

        /**
         * @brief   Set a quaternion which will perform a rotation of an angle around the axis given by
         *          the vector(x, y, z).
         *
         * @param   angle   The angle.
         * @param   vec     The vector.
         */
        void MakeRotate(value_type  angle, const Vec3d& vec);

        /**
         * @brief   Set a quaternion which will perform a rotation of an angle around the axis given by
         *          the vector(x, y, z).
         *
         * @param   angle1  The first angle.
         * @param   axis1   The first axis.
         * @param   angle2  The second angle.
         * @param   axis2   The second axis.
         * @param   angle3  The third angle.
         * @param   axis3   The third axis.
         */
        void MakeRotate(value_type  angle1, const Vec3f& axis1, value_type  angle2, const Vec3f& axis2, value_type  angle3, const Vec3f& axis3);

        /**
         * @brief   Set a quaternion which will perform a rotation of an angle around the axis given by
         *          the vector(x, y, z).
         *
         * @param   angle1  The first angle.
         * @param   axis1   The first axis.
         * @param   angle2  The second angle.
         * @param   axis2   The second axis.
         * @param   angle3  The third angle.
         * @param   axis3   The third axis.
         */
        void MakeRotate(value_type  angle1, const Vec3d& axis1, value_type  angle2, const Vec3d& axis2, value_type  angle3, const Vec3d& axis3);

        /**
         * @brief   Make a rotation Quat which will rotate vec1 to vec2. Watch out for the two special
         *          cases when the vectors are co-incident or opposite in direction.
         *          This routine uses only fast geometric transforms, without costly acos/sin computations.
         *          It's exact, fast, and with less degenerate cases than the acos/sin method.
         * 
         *          For an explanation of the math used, you may see for example:
         *          http://logiciels.cnes.fr/MARMOTTES/marmottes-mathematique.pdf
         *
         * @param   vec1    The first vector.
         * @param   vec2    The second vector.
         */
        void MakeRotate(const Vec3f& vec1, const Vec3f& vec2);

        /**
         * @brief   Make a rotation Quat which will rotate vec1 to vec2. Watch out for the two special
         *          cases when the vectors are co-incident or opposite in direction.
         *          This routine uses only fast geometric transforms, without costly acos/sin computations.
         *          It's exact, fast, and with less degenerate cases than the acos/sin method.
         *
         *          For an explanation of the math used, you may see for example:
         *          http://logiciels.cnes.fr/MARMOTTES/marmottes-mathematique.pdf
         *
         * @param   vec1    The first vector.
         * @param   vec2    The second vector.
         */
        void MakeRotate(const Vec3d& vec1, const Vec3d& vec2);

        /**
         * @brief   Return the angle and vector components represented by the quaternion.
         *
         * @param [in,out]  angle   The angle.
         * @param [in,out]  x       The x to process.
         * @param [in,out]  y       The y to process.
         * @param [in,out]  z       The z to process.
         */
        void GetRotate(value_type& angle, value_type& x, value_type& y, value_type& z) const;

        /**
         * @brief   Return the angle and vector represented by the quaternion.
         *
         * @param [in,out]  angle   The angle.
         * @param [in,out]  vec     The vector.
         */
        void GetRotate(value_type& angle, Vec3f& vec) const;

        /**
         * @brief   Return the angle and vector represented by the quaternion.
         *
         * @param [in,out]  angle   The angle.
         * @param [in,out]  vec     The vector.
         */
        void GetRotate(value_type& angle, Vec3d& vec) const;

        /**
         * @brief   Spherical Linear Interpolation. As t goes from 0 to 1, the Quat object goes from
         *          "from" to "to".
         *
         * @param   t       The value_type to process.
         * @param   from    Source for the.
         * @param   to      to.
         */
        void Slerp(value_type  t, const Quat& from, const Quat& to);

        /**
        * Returns the X component of the quaternion/
        */
        value_type& X();

        /**
        * Returns the Y component of the quaternion/
        */
        value_type& Y();

        /**
        * Returns the Z component of the quaternion/
        */
        value_type& Z();

        /**
        * Returns the W component of the quaternion/
        */
        value_type& W();

        /**
        * Returns the X component of the quaternion/
        */
        value_type X() const;
        
        /**
        * Returns the Y component of the quaternion/
        */
        value_type Y() const;

        /**
        * Returns the Z component of the quaternion/
        */
        value_type Z() const;
        
        /**
        * Returns the W component of the quaternion/
        */
        value_type W() const;

        /**
        * Index operator
        */
        value_type & operator [] (int i);
        
        /**
        * Index operator
        */
        value_type operator [] (int i) const;

        /**
        * Set operator
        */
        Quat& operator = (const Quat& v);

        /**
        * Equals operator
        */
        bool operator == (const Quat& v) const;

        /**
        * Not equals operator
        */
        bool operator != (const Quat& v) const;

        /**
        * Less than operator
        */
        bool operator <  (const Quat& v) const;

        /**
        * Greater than operator
        */
        bool operator >  (const Quat& v) const;

        /**
        * Multiply by scalar
        */
        const Quat operator * (value_type rhs) const;

        /** 
        * Rotate a vector by this quaternion.
        */
        Vec3f operator* (const Vec3f& v) const;

        /** 
        * Rotate a vector by this quaternion.
        */
        Vec3d operator* (const Vec3d& v) const;

        /**
        * Unary multiply by scalar
        */
        Quat& operator *= (value_type rhs);

        /**
        * Binary multiply
        */
        const Quat operator*(const Quat& rhs) const;

        /**
        * Unary multiply
        */
        Quat& operator*=(const Quat& rhs);

        /**
        * Divide by scalar
        */
        Quat operator / (value_type rhs) const;

        /**
        * Unary divide by scalar
        */
        Quat& operator /= (value_type rhs);

        /**
        * Binary divide
        */
        const Quat operator/(const Quat& denom) const;

        /**
        * Unary divide
        */
        Quat& operator/=(const Quat& denom);

        /**
        * Binary addition
        */
        const Quat operator + (const Quat& rhs) const;

        /**
        * Unary addition
        */
        Quat& operator += (const Quat& rhs);

        /**
        * Binary subtraction
        */
        const Quat operator - (const Quat& rhs) const;

        /**
        * Unary subtraction
        */
        Quat& operator -= (const Quat& rhs);

        /** 
        * Negation operator - returns the negative of the quaternion.
        * Basically just calls operator - () on the Vec4 
        */
        const Quat operator - () const;

        /**
        * Implicit conversion operator to OSG Quaternion
        */
        operator osg::Quat () const;

        /**
        * Implicit conversion operator to OSG Quaternion
        */
        operator osg::Quat& ();

        /**
        * Implicit conversion operator to OSG Quaternion
        */
        operator const osg::Quat& () const;

        /**
        * Implicit conversion operator to OSG Quaternion
        */
        operator osg::Quat* ();

        /**
         * @fn  std::string Quat::ToString(int precision = -1);
         *
         * @brief   Convert this object into a string representation.
         *
         * @param   precision   (Optional) The precision.
         *
         * @return  A std::string that represents this object.
         */
        std::string ToString(int precision = -1);

        protected:

            osg::Quat mQuat;
    };

    /**
    * @brief   Stream insertion operator.
    *
    * @return  The stream string result.
    */
    TR_BASE_EXPORT std::ostream& operator << (std::ostream& ios, const Quat& q);
}



   
