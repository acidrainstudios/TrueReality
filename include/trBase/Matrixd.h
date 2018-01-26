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
* Author: Maxim Serebrennik
*/
#pragma once

#include <trBase/Export.h>

#include <osg/Matrixd>

#include <trBase/Quat.h>

#include <iostream>
#include <string>

namespace trBase
{
    class Matrixf;

    /**
    * A float Matrix class to be used for generic matrix operations.
    */
    class TR_BASE_EXPORT Matrixd
    {
    public:

        typedef double value_type;

        /**
        * ctor
        */
        Matrixd();

        /**
        * ctor
        */
        Matrixd(const Matrixd& mat);

        /**
        * ctor
        */
        Matrixd(const Matrixf& mat);

        /**
        * ctor that takes a 4x4 array of floats and uses them as matrix input.
        */
        explicit Matrixd(float const * const ptr);

        /**
        * ctor that takes a 4x4 array of double and uses them as matrix input.
        */
        explicit Matrixd(double const * const ptr);

        /**
        * ctor that takes a quaternion and uses it as matrix input.
        */
        explicit Matrixd(const Quat& quat);

        /**
        * ctor
        */
        Matrixd(value_type a00, value_type a01, value_type a02, value_type a03,
            value_type a10, value_type a11, value_type a12, value_type a13,
            value_type a20, value_type a21, value_type a22, value_type a23,
            value_type a30, value_type a31, value_type a32, value_type a33);

        /**
        * dtor
        */
        ~Matrixd();

        /**
        * Returns a reference to the internal OSG Matrix.
        */
        osg::Matrixd& GetOSGMatrix();

        /**
        * Returns a reference to the internal OSG Matrix.
        */
        const osg::Matrixd& GetOSGMatrix() const;

        /**
        * Compare the current Matrix to the passed in one. Returns -1, 0, or 1.
        */
        int Compare(const Matrixd& m) const;

        /**
        * Returns true if the Matrix is not NaN.
        */
        bool Valid() const;

        /**
        * Returns true if the Matrix is NaN.
        */
        bool IsNaN() const;

        /**
        * Set the current Matrix from a passed in one.
        */
        void Set(const Matrixd& rhs);

        /**
        * Set the current Matrix from a passed in one.
        */
        void Set(const Matrixf& rhs);

        /**
        * Set the current Matrix from a passed in values array.
        */
        void Set(float const * const ptr);

        /**
        * Set the current Matrix from a passed in values array.
        */
        void Set(double const * const ptr);

        /**
        * Set the current Matrix from a passed in values.
        */
        void Set(value_type a00, value_type a01, value_type a02, value_type a03,
            value_type a10, value_type a11, value_type a12, value_type a13,
            value_type a20, value_type a21, value_type a22, value_type a23,
            value_type a30, value_type a31, value_type a32, value_type a33);

        /**
        * Pointer to the internal Matrix array.
        */
        value_type* Ptr();

        /**
        * Pointer to the internal Matrix array.
        */
        const value_type* Ptr() const;

        /**
        * Reset this matrix to be an Identity Matrix.
        */
        void MakeIdentity();

        /**
        * Reset this matrix to be a scale matrix of the passed in value.
        */
        void MakeScale(const Vec3f& v);

        /**
        * Reset this matrix to be a scale matrix of the passed in value.
        */
        void MakeScale(const Vec3d& v);

        /**
        * Reset this matrix to be a scale matrix of the passed in value.
        */
        void MakeScale(value_type x, value_type y, value_type z);

        /**
        * Reset this matrix to be a translation matrix of the passed in value.
        */
        void MakeTranslate(const Vec3f& v);

        /**
        * Reset this matrix to be a translation matrix of the passed in value.
        */
        void MakeTranslate(const Vec3d& v);

        /**
        * Reset this matrix to be a translation matrix of the passed in value.
        */
        void MakeTranslate(value_type x, value_type y, value_type z);

        /**
        * Reset this matrix to be a rotational matrix of the passed in value.
        */
        void MakeRotate(const Vec3f& from, const Vec3f& to);

        /**
        * Reset this matrix to be a rotational matrix of the passed in value.
        */
        void MakeRotate(const Vec3d& from, const Vec3d& to);

        /**
        * Reset this matrix to be a rotational matrix of the passed in value.
        */
        void MakeRotate(value_type angle, const Vec3f& axis);

        /**
        * Reset this matrix to be a rotational matrix of the passed in value.
        */
        void MakeRotate(value_type angle, const Vec3d& axis);

        /**
        * Reset this matrix to be a rotational matrix of the passed in value.
        */
        void MakeRotate(value_type angle, value_type x, value_type y, value_type z);

        /**
        * Reset this matrix to be a rotational matrix of the passed in value.
        */
        void MakeRotate(const Quat& q);

        /**
        * Reset this matrix to be a rotational matrix of the passed in value.
        */
        void MakeRotate(value_type angle1, const Vec3f& axis1, value_type angle2, const Vec3f& axis2, value_type angle3, const Vec3f& axis3);

        /**
        * Reset this matrix to be a rotational matrix of the passed in value.
        */
        void MakeRotate(value_type angle1, const Vec3d& axis1, value_type angle2, const Vec3d& axis2, value_type angle3, const Vec3d& axis3);

        /**
        * Decomposes the matrix into translation, rotation, scale and scale orientation.
        */
        void Decompose(Vec3f& translation, Quat& rotation, Vec3f& scale, Quat& so) const;

        /**
        * Decompose the matrix into translation, rotation, scale and scale orientation.
        */
        void Decompose(Vec3d& translation, Quat& rotation, Vec3d& scale, Quat& so) const;

        /**
        * Set to an orthographic projection.
        * See glOrtho for further details.
        */
        void MakeOrtho(double left, double right, double bottom, double top, double zNear, double zFar);

        /**
        * Set to an orthographic projection.
        * See glOrtho for further details.
        */
        void MakeOrtho(float left, float right, float bottom, float top, float zNear, float zFar);

        /**
        * Get the orthographic settings of the orthographic projection matrix.
        * Note, if matrix is not an orthographic matrix then invalid values
        * will be returned.
        */
        bool GetOrtho(double& left, double& right, double& bottom, double& top, double& zNear, double& zFar) const;

        /**
        * float version of getOrtho(..)
        * Get the orthographic settings of the orthographic projection matrix.
        * Note, if matrix is not an orthographic matrix then invalid values
        * will be returned.
        */
        bool GetOrtho(float& left, float& right, float& bottom, float& top, float& zNear, float& zFar) const;

        /**
        * Set to a 2D orthographic projection.
        * See glOrtho2D for further details.
        */
        void MakeOrtho2D(double left, double right, double bottom, double top);

        /**
        * Set to a 2D orthographic projection.
        * See glOrtho2D for further details.
        */
        void MakeOrtho2D(float left, float right, float bottom, float top);

        /**
        * Set to a perspective projection.
        * See glFrustum for further details.
        */
        void MakeFrustum(double left, double right, double bottom, double top, double zNear, double zFar);

        /**
        * Set to a perspective projection.
        * See glFrustum for further details.
        */
        void MakeFrustum(float left, float right, float bottom, float top, float zNear, float zFar);

        /**
        * Get the frustum settings of a perspective projection matrix.
        * Note, if matrix is not a perspective matrix then invalid values
        * will be returned.
        */
        bool GetFrustum(double& left, double& right, double& bottom, double& top, double& zNear, double& zFar) const;

        /**
        * float version of getFrustum(..)
        * Get the frustum settings of a perspective projection matrix.
        * Note, if matrix is not a perspective matrix then invalid values
        * will be returned.
        */
        bool GetFrustum(float& left, float& right, float& bottom, float& top, float& zNear, float& zFar) const;

        /**
        * Set to a symmetrical perspective projection.
        * See gluPerspective for further details.
        * Aspect ratio is defined as width/height.
        */
        void MakePerspective(double fovy, double aspectRatio, double zNear, double zFar);

        /**
        * Set to a symmetrical perspective projection.
        * See gluPerspective for further details.
        * Aspect ratio is defined as width/height.
        */
        void MakePerspective(float fovy, float aspectRatio, float zNear, float zFar);

        /**
        * Get the frustum settings of a symmetric perspective projection
        * matrix.
        * Return false if matrix is not a perspective matrix,
        * where parameter values are undefined.
        * Note, if matrix is not a symmetric perspective matrix then the
        * shear will be lost.
        */
        bool GetPerspective(double& fovy, double& aspectRatio, double& zNear, double& zFar) const;

        /**
        * float version of getPerspective(..)
        * Get the frustum settings of a symmetric perspective projection
        * matrix.
        * Return false if matrix is not a perspective matrix,
        * where parameter values are undefined.
        * Note, if matrix is not a symmetric perspective matrix then the
        * shear will be lost.
        */
        bool GetPerspective(float& fovy, float& aspectRatio, float& zNear, float& zFar) const;

        /**
        * Set the position and orientation to be a view matrix,
        * using the same convention as gluLookAt.
        */
        void MakeLookAt(const Vec3f& eye, const Vec3f& center, const Vec3f& up);

        /**
        * Set the position and orientation to be a view matrix,
        * using the same convention as gluLookAt.
        */
        void MakeLookAt(const Vec3d& eye, const Vec3d& center, const Vec3d& up);

        /**
        * Get to the position and orientation of a modelview matrix,
        * using the same convention as gluLookAt.
        */
        void GetLookAt(Vec3f& eye, Vec3f& center, Vec3f& up, value_type lookDistance = 1.0f) const;

        /**
        * Get to the position and orientation of a modelview matrix,
        * using the same convention as gluLookAt.
        */
        void GetLookAt(Vec3d& eye, Vec3d& center, Vec3d& up, value_type lookDistance = 1.0f) const;

        /**
        * Invert the matrix rhs, automatically select invert_4x3 or invert_4x4.
        */
        bool Invert(const Matrixd& rhs);

        /**
        * 4x3 matrix invert, not right hand column is assumed to be 0,0,0,1.
        */
        bool Invert_4x3(const Matrixd& rhs);

        /**
        * Full 4x4 matrix invert.
        */
        bool Invert_4x4(const Matrixd& rhs);

        /**
        * Ortho-normalize the 3x3 rotation & scale matrix
        */
        void OrthoNormalize(const Matrixd& rhs);

        /**
        * Applies the rotation to the matrix
        */
        void SetRotate(const Quat& q);

        /**
        * Get the matrix rotation as a Quat. Note that this function
        * assumes a non-scaled matrix and will return incorrect results
        * for scaled matrixces. Consider decompose() instead.
        */
        Quat GetRotate() const;

        /**
        * Sets the translation area of the matrix.
        */
        void SetTrans(value_type tx, value_type ty, value_type tz);

        /**
        * Sets the translation area of the matrix.
        */
        void SetTrans(const Vec3f& v);

        /**
        * Sets the translation area of the matrix.
        */
        void SetTrans(const Vec3d& v);

        /**
        * Returns the translation area of the matrix.
        */
        Vec3d GetTrans() const;

        /**
        * Returns the matrix scale.
        */
        Vec3d GetScale() const;

        /**
        * Sets the scale values of the matrix.
        */
        void SetScale(value_type x, value_type y, value_type z);

        /**
        * Sets the scale values of the matrix.
        */
        void SetScale(const Vec3f& v);

        /**
        * Sets the scale values of the matrix.
        */
        void SetScale(const Vec3d& v);

        /**
        * PreMultiply the matrix by the passed in vector.
        */
        Vec3f PreMult(const Vec3f& v) const;

        /**
        * PreMultiply the matrix by the passed in vector.
        */
        Vec3d PreMult(const Vec3d& v) const;

        /**
        * PostMultiply the matrix by the passed in vector.
        */
        Vec3f PostMult(const Vec3f& v) const;

        /**
        * PostMultiply the matrix by the passed in vector.
        */
        Vec3d PostMult(const Vec3d& v) const;

        /**
        * PreMultiply the matrix by the passed in vector.
        */
        Vec4f PreMult(const Vec4f& v) const;

        /**
        * PreMultiply the matrix by the passed in vector.
        */
        Vec4d PreMult(const Vec4d& v) const;

        /**
        * PostMultiply the matrix by the passed in vector.
        */
        Vec4f PostMult(const Vec4f& v) const;

        /**
        * PostMultiply the matrix by the passed in vector.
        */
        Vec4d PostMult(const Vec4d& v) const;

        /**
        * Basic Matrixd multiplication, our workhorse methods.
        */
        void Mult(const Matrixd& m1, const Matrixd& m2);

        /**
        * Basic Matrixd multiplication, our workhorse methods.
        */
        void PreMult(const Matrixd& m);

        /**
        * Basic Matrixd multiplication, our workhorse methods.
        */
        void PostMult(const Matrixd& m);

        /**
        * Optimized version of preMult(translate(v));
        */
        void PreMultTranslate(const Vec3d& v);

        /**
        * Optimized version of preMult(translate(v));
        */
        void PreMultTranslate(const Vec3f& v);

        /**
        * Optimized version of postMult(translate(v));
        */
        void PostMultTranslate(const Vec3d& v);

        /**
        * Optimized version of postMult(translate(v));
        */
        void PostMultTranslate(const Vec3f& v);

        /**
        * Optimized version of preMult(scale(v));
        */
        void PreMultScale(const Vec3d& v);

        /**
        * Optimized version of preMult(scale(v));
        */
        void PreMultScale(const Vec3f& v);

        /**
        * Optimized version of postMult(scale(v));
        */
        void PostMultScale(const Vec3d& v);

        /**
        * Optimized version of postMult(scale(v));
        */
        void PostMultScale(const Vec3f& v);

        /**
        * Optimized version of preMult(rotate(q));
        */
        void PreMultRotate(const Quat& q);

        /**
        * Optimized version of postMult(rotate(q));
        */
        void PostMultRotate(const Quat& q);

        /**
         * @fn  std::string Matrixd::ToString(int precision = -1) static Matrixd Identity(void);
         *
         * @brief   Convert this object into a string representation.
         *
         * @param   precision   (Optional) The precision.
         *
         * @return  A std::string that represents this object.
         */
        std::string ToString(int precision = -1);

        /**
        * Static method to create an Identity matrix
        */
        static Matrixd Identity(void);

        /**
        * Static method to create a Scale matrix.
        */
        static Matrixd Scale(const Vec3f& sv);

        /**
        * Static method to create a Scale matrix.
        */
        static Matrixd Scale(const Vec3d& sv);

        /**
        * Static method to create a Scale matrix.
        */
        static Matrixd Scale(value_type sx, value_type sy, value_type sz);

        /**
        * Static method to create a Translate matrix.
        */
        static Matrixd Translate(const Vec3f& dv);

        /**
        * Static method to create a Translate matrix.
        */
        static Matrixd Translate(const Vec3d& dv);

        /**
        * Static method to create a Translate matrix.
        */
        static Matrixd Translate(value_type x, value_type y, value_type z);

        /**
        * Static method to create a Rotational matrix.
        */
        static Matrixd Rotate(const Vec3f& from, const Vec3f& to);

        /**
        * Static method to create a Rotational matrix.
        */
        static Matrixd Rotate(const Vec3d& from, const Vec3d& to);

        /**
        * Static method to create a Rotational matrix.
        */
        static Matrixd Rotate(value_type angle, value_type x, value_type y, value_type z);

        /**
        * Static method to create a Rotational matrix.
        */
        static Matrixd Rotate(value_type angle, const Vec3f& axis);

        /**
        * Static method to create a Rotational matrix.
        */
        static Matrixd Rotate(value_type angle, const Vec3d& axis);

        /**
        * Static method to create a Rotational matrix.
        */
        static Matrixd Rotate(value_type angle1, const Vec3f& axis1, value_type angle2, const Vec3f& axis2, value_type angle3, const Vec3f& axis3);

        /**
        * Static method to create a Rotational matrix.
        */
        static Matrixd Rotate(value_type angle1, const Vec3d& axis1, value_type angle2, const Vec3d& axis2, value_type angle3, const Vec3d& axis3);

        /**
        * Static method to create a Rotational matrix.
        */
        static Matrixd Rotate(const Quat& quat);

        /**
        * Static method to create an inverted matrix.
        */
        static Matrixd Inverse(const Matrixd& matrix);

        /**
        * Static method to create an Ortho Normalized matrix.
        */
        static Matrixd OrthoNormal(const Matrixd& matrix);

        /**
        * Create an orthographic projection matrix.
        * See glOrtho for further details.
        */
        static Matrixd Ortho(double left, double right, double bottom, double top, double zNear, double zFar);

        /**
        * Create an orthographic projection matrix.
        * See glOrtho for further details.
        */
        static Matrixd Ortho(float left, float right, float bottom, float top, float zNear, float zFar);

        /**
        * Create a 2D orthographic projection matrix.
        * See glOrtho for further details.
        */
        static Matrixd Ortho2D(double left, double right, double bottom, double top);

        /**
        * Create a 2D orthographic projection matrix.
        * See glOrtho for further details.
        */
        static Matrixd Ortho2D(float left, float right, float bottom, float top);

        /**
        * Create a perspective projection matrix.
        * See glFrustum for further details.
        */
        static Matrixd Frustum(double left, double right, double bottom, double top, double zNear, double zFar);

        /**
        * Create a perspective projection matrix.
        * See glFrustum for further details.
        */
        static Matrixd Frustum(float left, float right, float bottom, float top, float zNear, float zFar);

        /**
        * Create a symmetrical perspective projection matrix.
        * See gluPerspective for further details.
        * Aspect ratio is defined as width/height.
        */
        static Matrixd Perspective(float fovy, float aspectRatio, float zNear, float zFar);

        /**
        * Create a symmetrical perspective projection matrix.
        * See gluPerspective for further details.
        * Aspect ratio is defined as width/height.
        */
        static Matrixd Perspective(double fovy, double aspectRatio, double zNear, double zFar);

        /**
        * Create the position and orientation matrix as per a camera,
        * using the same convention as gluLookAt.
        */
        static Matrixd LookAt(const Vec3f& eye, const Vec3f& center, const Vec3f& up);

        /**
        * Create the position and orientation matrix as per a camera,
        * using the same convention as gluLookAt.
        */
        static Matrixd LookAt(const Vec3d& eye, const Vec3d& center, const Vec3d& up);

        /**
        * Apply a 3x3 transform of v*M[0..2,0..2].
        */
        static Vec3f Transform3x3(const Vec3f& v, const Matrixd& m);

        /**
        * Apply a 3x3 transform of v*M[0..2,0..2].
        */
        static Vec3d Transform3x3(const Vec3d& v, const Matrixd& m);

        /**
        * Apply a 3x3 transform of M[0..2,0..2]*v.
        */
        static Vec3f Transform3x3(const Matrixd& m, const Vec3f& v);

        /**
        Apply a 3x3 transform of M[0..2,0..2]*v.
        */
        static Vec3d Transform3x3(const Matrixd& m, const Vec3d& v);

        /**
        * Set operator
        */
        Matrixd& operator = (const Matrixd& rhs);

        /**
        * Set operator
        */
        Matrixd& operator = (const Matrixf& rhs);

        /**
        * Greater than by operator.
        */
        bool operator > (const Matrixd& m) const;

        /**
        * Less than by operator.
        */
        bool operator < (const Matrixd& m) const;

        /**
        * Equality operator.
        */
        bool operator == (const Matrixd& m) const;

        /**
        * Inequality operator.
        */
        bool operator != (const Matrixd& m) const;

        /**
        * Multiply by vector.
        */
        Vec3f operator* (const Vec3f& v) const;

        /**
        * Multiply by vector.
        */
        Vec3d operator* (const Vec3d& v) const;

        /**
        * Multiply by vector.
        */
        Vec4f operator* (const Vec4f& v) const;

        /**
        * Multiply by vector.
        */
        Vec4d operator* (const Vec4d& v) const;

        /**
        * Unary Multiply by a matrix.
        */
        void operator *= (const Matrixd& other);

        /**
        * Multiply by a matrix.
        */
        Matrixd operator * (const Matrixd &m) const;

        /**
        * Multiply by scalar.
        */
        Matrixd operator * (value_type rhs) const;

        /**
        * Unary multiply by scalar.
        * More efficient than *
        */
        Matrixd& operator *= (value_type rhs);

        /**
        * Divide by scalar.
        */
        Matrixd operator / (value_type rhs) const;

        /**
        * Unary divide by scalar.
        * More efficient than /
        */
        Matrixd& operator /= (value_type rhs);

        /**
        * Binary vector add.
        */
        Matrixd operator + (const Matrixd& rhs) const;

        /**
        * Unary vector add.
        * More efficient than +
        */
        Matrixd& operator += (const Matrixd& rhs);

        /**
        * Binary vector subtract.
        */
        Matrixd operator - (const Matrixd& rhs) const;

        /**
        * Unary vector subtract.
        * More efficient than -
        */
        Matrixd& operator -= (const Matrixd& rhs);

        /**
        * Returns a specific row and column value of the matrix.
        */
        value_type& operator ()(int row, int col);

        /**
        * Returns a specific row and column value of the matrix.
        */
        value_type operator ()(int row, int col) const;

        /**
        * Implicit conversion operator to OSG Matrix
        */
        operator osg::Matrixd () const;

        /**
        * Implicit conversion operator to OSG Matrix
        */
        operator osg::Matrixd& ();

        /**
        * Implicit conversion operator to OSG Matrix
        */
        operator const osg::Matrixd& () const;

        /**
        * Implicit conversion operator to OSG Matrix
        */
        operator osg::Matrixd* ();

    protected:

        osg::Matrixd mMatrix;
    };

    /**
    * @brief   Stream insertion operator.
    *
    * @return  The stream string result.
    */
    TR_BASE_EXPORT std::ostream& operator << (std::ostream& ios, const Matrixd& q);
}