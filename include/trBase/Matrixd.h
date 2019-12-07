/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2019 Acid Rain Studios LLC
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

#include <osg/Matrixd>
#include <osg/Matrixf>

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

        using value_type = double;

        /**
         * @fn  Matrixd::Matrixd();
         *
         * @brief   ctor.
         */
        Matrixd();

        /**
         * @fn  Matrixd::Matrixd(const osg::Matrixd& mat);
         *
         * @brief   ctor.
         *
         * @param   mat The matrix.
         */
        Matrixd(const osg::Matrixd& mat);

        /**
         * @fn  Matrixd::Matrixd(const osg::Matrixf& mat);
         *
         * @brief   ctor.
         *
         * @param   mat The matrix.
         */
        Matrixd(const osg::Matrixf& mat);

        /**
         * @fn  Matrixd::Matrixd(const Matrixd& mat);
         *
         * @brief   ctor.
         *
         * @param   mat The matrix.
         */
        Matrixd(const Matrixd& mat);

        /**
         * @fn  Matrixd::Matrixd(const Matrixf& mat);
         *
         * @brief   ctor.
         *
         * @param   mat The matrix.
         */
        Matrixd(const Matrixf& mat);

        /**
         * @fn  explicit Matrixd::Matrixd(float const * const ptr);
         *
         * @brief   ctor that takes a 4x4 array of floats and uses them as matrix input.
         *
         * @param   ptr The pointer.
         */
        explicit Matrixd(float const * const ptr);

        /**
         * @fn  explicit Matrixd::Matrixd(double const * const ptr);
         *
         * @brief   ctor that takes a 4x4 array of double and uses them as matrix input.
         *
         * @param   ptr The pointer.
         */
        explicit Matrixd(double const * const ptr);

        /**
         * @fn  explicit Matrixd::Matrixd(const Quat& quat);
         *
         * @brief   ctor that takes a quaternion and uses it as matrix input.
         *
         * @param   quat    The quaternion.
         */
        explicit Matrixd(const Quat& quat);

        /**
         * @fn  Matrixd::Matrixd(value_type a00, value_type a01, value_type a02, value_type a03, value_type a10, value_type a11, value_type a12, value_type a13, value_type a20, value_type a21, value_type a22, value_type a23, value_type a30, value_type a31, value_type a32, value_type a33);
         *
         * @brief   ctor.
         *
         * @param   a00 The [0][0] value of the matrix.
         * @param   a01 The [0][1] value of the matrix.
         * @param   a02 The [0][2] value of the matrix.
         * @param   a03 The [0][3] value of the matrix.
         * @param   a10 The [1][0] value of the matrix.
         * @param   a11 The [1][1] value of the matrix.
         * @param   a12 The [1][2] value of the matrix.
         * @param   a13 The [1][3] value of the matrix.
         * @param   a20 The [2][0] value of the matrix.
         * @param   a21 The [2][1] value of the matrix.
         * @param   a22 The [2][2] value of the matrix.
         * @param   a23 The [2][3] value of the matrix.
         * @param   a30 The [3][0] value of the matrix.
         * @param   a31 The [3][1] value of the matrix.
         * @param   a32 The [3][2] value of the matrix.
         * @param   a33 The [3][3] value of the matrix.
         */
        Matrixd(value_type a00, value_type a01, value_type a02, value_type a03,
            value_type a10, value_type a11, value_type a12, value_type a13,
            value_type a20, value_type a21, value_type a22, value_type a23,
            value_type a30, value_type a31, value_type a32, value_type a33);

        /**
         * @fn  Matrixd::~Matrixd();
         *
         * @brief   dtor.
         */
        ~Matrixd();

        /**
         * @fn  osg::Matrixd& Matrixd::GetOSGMatrix();
         *
         * @brief   Returns a reference to the internal OSG Matrix.
         *
         * @return  The osg matrix.
         */
        osg::Matrixd& GetOSGMatrix();

        /**
         * @fn  const osg::Matrixd& Matrixd::GetOSGMatrix() const;
         *
         * @brief   Returns a reference to the internal OSG Matrix.
         *
         * @return  The osg matrix.
         */
        const osg::Matrixd& GetOSGMatrix() const;

        /**
         * @fn  int Matrixd::Compare(const Matrixd& m) const;
         *
         * @brief   Compare the current Matrix to the passed in one. Returns -1, 0, or 1.
         *
         * @param   m   The constant matrixd&amp; to compare to this object.
         *
         * @return  Negative if 'm' is less than '', 0 if they are equal, or positive if it is greater.
         */
        int Compare(const Matrixd& m) const;

        /**
         * @fn  bool Matrixd::Valid() const;
         *
         * @brief   Returns true if the Matrix is not NaN.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Valid() const;

        /**
         * @fn  bool Matrixd::IsNaN() const;
         *
         * @brief   Returns true if the Matrix is NaN.
         *
         * @return  True if nan, false if not.
         */
        bool IsNaN() const;

        /**
         * @fn  void Matrixd::Set(const Matrixd& rhs);
         *
         * @brief   Set the current Matrix from a passed in one.
         *
         * @param   rhs The Right hand side to set.
         */
        void Set(const Matrixd& rhs);

        /**
         * @fn  void Matrixd::Set(const Matrixf& rhs);
         *
         * @brief   Set the current Matrix from a passed in one.
         *
         * @param   rhs The Right hand side to set.
         */
        void Set(const Matrixf& rhs);

        /**
         * @fn  void Matrixd::Set(float const * const ptr);
         *
         * @brief   Set the current Matrix from a passed in values array.
         *
         * @param   ptr The pointer.
         */
        void Set(float const * const ptr);

        /**
        * Set the current Matrix from a passed in values array.
        */
        void Set(double const * const ptr);

        /**
         * @fn  void Matrixd::Set(value_type a00, value_type a01, value_type a02, value_type a03, value_type a10, value_type a11, value_type a12, value_type a13, value_type a20, value_type a21, value_type a22, value_type a23, value_type a30, value_type a31, value_type a32, value_type a33);
         *
         * @brief   Set the current Matrix from a passed in values.
         *
         * @param   a00 The [0][0] value of the matrix.
         * @param   a01 The [0][1] value of the matrix.
         * @param   a02 The [0][2] value of the matrix.
         * @param   a03 The [0][3] value of the matrix.
         * @param   a10 The [1][0] value of the matrix.
         * @param   a11 The [1][1] value of the matrix.
         * @param   a12 The [1][2] value of the matrix.
         * @param   a13 The [1][3] value of the matrix.
         * @param   a20 The [2][0] value of the matrix.
         * @param   a21 The [2][1] value of the matrix.
         * @param   a22 The [2][2] value of the matrix.
         * @param   a23 The [2][3] value of the matrix.
         * @param   a30 The [3][0] value of the matrix.
         * @param   a31 The [3][1] value of the matrix.
         * @param   a32 The [3][2] value of the matrix.
         * @param   a33 The [3][3] value of the matrix.
         */
        void Set(value_type a00, value_type a01, value_type a02, value_type a03,
            value_type a10, value_type a11, value_type a12, value_type a13,
            value_type a20, value_type a21, value_type a22, value_type a23,
            value_type a30, value_type a31, value_type a32, value_type a33);

        /**
         * @fn  value_type* Matrixd::Ptr();
         *
         * @brief   Pointer to the internal Matrix array.
         *
         * @return  Null if it fails, else a pointer to a value_type.
         */
        value_type* Ptr();

        /**
         * @fn  const value_type* Matrixd::Ptr() const;
         *
         * @brief   Pointer to the internal Matrix array.
         *
         * @return  Null if it fails, else a pointer to a const value_type.
         */
        const value_type* Ptr() const;

        /**
         * @fn  void Matrixd::MakeIdentity();
         *
         * @brief   Reset this matrix to be an Identity Matrix.
         */
        void MakeIdentity();

        /**
         * @fn  void Matrixd::MakeScale(const Vec3f& v);
         *
         * @brief   Reset this matrix to be a scale matrix of the passed in value.
         *
         * @param   v   The Vec3f to process.
         */
        void MakeScale(const Vec3f& v);

        /**
         * @fn  void Matrixd::MakeScale(const Vec3d& v);
         *
         * @brief   Reset this matrix to be a scale matrix of the passed in value.
         *
         * @param   v   The Vec3d to process.
         */
        void MakeScale(const Vec3d& v);

        /**
         * @fn  void Matrixd::MakeScale(value_type x, value_type y, value_type z);
         *
         * @brief   Reset this matrix to be a scale matrix of the passed in value.
         *
         * @param   x   The value_type to process.
         * @param   y   The value_type to process.
         * @param   z   The value_type to process.
         */
        void MakeScale(value_type x, value_type y, value_type z);

        /**
         * @fn  void Matrixd::MakeTranslate(const Vec3f& v);
         *
         * @brief   Reset this matrix to be a translation matrix of the passed in value.
         *
         * @param   v   The Vec3f to process.
         */
        void MakeTranslate(const Vec3f& v);

        /**
         * @fn  void Matrixd::MakeTranslate(const Vec3d& v);
         *
         * @brief   Reset this matrix to be a translation matrix of the passed in value.
         *
         * @param   v   The Vec3d to process.
         */
        void MakeTranslate(const Vec3d& v);

        /**
         * @fn  void Matrixd::MakeTranslate(value_type x, value_type y, value_type z);
         *
         * @brief   Reset this matrix to be a translation matrix of the passed in value.
         *
         * @param   x   The value_type to process.
         * @param   y   The value_type to process.
         * @param   z   The value_type to process.
         */
        void MakeTranslate(value_type x, value_type y, value_type z);

        /**
         * @fn  void Matrixd::MakeRotate(const Vec3f& from, const Vec3f& to);
         *
         * @brief   Reset this matrix to be a rotational matrix of the passed in value.
         *
         * @param   from    Source for the.
         * @param   to      to.
         */
        void MakeRotate(const Vec3f& from, const Vec3f& to);

        /**
         * @fn  void Matrixd::MakeRotate(const Vec3d& from, const Vec3d& to);
         *
         * @brief   Reset this matrix to be a rotational matrix of the passed in value.
         *
         * @param   from    Source for the.
         * @param   to      to.
         */
        void MakeRotate(const Vec3d& from, const Vec3d& to);

        /**
         * @fn  void Matrixd::MakeRotate(value_type angle, const Vec3f& axis);
         *
         * @brief   Reset this matrix to be a rotational matrix of the passed in value.
         *
         * @param   angle   The angle.
         * @param   axis    The axis.
         */
        void MakeRotate(value_type angle, const Vec3f& axis);

        /**
         * @fn  void Matrixd::MakeRotate(value_type angle, const Vec3d& axis);
         *
         * @brief   Reset this matrix to be a rotational matrix of the passed in value.
         *
         * @param   angle   The angle.
         * @param   axis    The axis.
         */
        void MakeRotate(value_type angle, const Vec3d& axis);

        /**
         * @fn  void Matrixd::MakeRotate(value_type angle, value_type x, value_type y, value_type z);
         *
         * @brief   Reset this matrix to be a rotational matrix of the passed in value.
         *
         * @param   angle   The angle.
         * @param   x       The value_type to process.
         * @param   y       The value_type to process.
         * @param   z       The value_type to process.
         */
        void MakeRotate(value_type angle, value_type x, value_type y, value_type z);

        /**
         * @fn  void Matrixd::MakeRotate(const Quat& q);
         *
         * @brief   Reset this matrix to be a rotational matrix of the passed in value.
         *
         * @param   q   The Quat to process.
         */
        void MakeRotate(const Quat& q);

        /**
         * @fn  void Matrixd::MakeRotate(value_type angle1, const Vec3f& axis1, value_type angle2, const Vec3f& axis2, value_type angle3, const Vec3f& axis3);
         *
         * @brief   Reset this matrix to be a rotational matrix of the passed in value.
         *
         * @param   angle1  The first angle.
         * @param   axis1   The first axis.
         * @param   angle2  The second angle.
         * @param   axis2   The second axis.
         * @param   angle3  The third angle.
         * @param   axis3   The third axis.
         */
        void MakeRotate(value_type angle1, const Vec3f& axis1, value_type angle2, const Vec3f& axis2, value_type angle3, const Vec3f& axis3);

        /**
         * @fn  void Matrixd::MakeRotate(value_type angle1, const Vec3d& axis1, value_type angle2, const Vec3d& axis2, value_type angle3, const Vec3d& axis3);
         *
         * @brief   Reset this matrix to be a rotational matrix of the passed in value.
         *
         * @param   angle1  The first angle.
         * @param   axis1   The first axis.
         * @param   angle2  The second angle.
         * @param   axis2   The second axis.
         * @param   angle3  The third angle.
         * @param   axis3   The third axis.
         */
        void MakeRotate(value_type angle1, const Vec3d& axis1, value_type angle2, const Vec3d& axis2, value_type angle3, const Vec3d& axis3);

        /**
         * @fn  void Matrixd::Decompose(Vec3f& translation, Quat& rotation, Vec3f& scale, Quat& so) const;
         *
         * @brief   Decomposes the matrix into translation, rotation, scale and scale orientation.
         *
         * @param [in,out]  translation The translation.
         * @param [in,out]  rotation    The rotation.
         * @param [in,out]  scale       The scale.
         * @param [in,out]  so          The so.
         */
        void Decompose(Vec3f& translation, Quat& rotation, Vec3f& scale, Quat& so) const;

        /**
         * @fn  void Matrixd::Decompose(Vec3d& translation, Quat& rotation, Vec3d& scale, Quat& so) const;
         *
         * @brief   Decompose the matrix into translation, rotation, scale and scale orientation.
         *
         * @param [in,out]  translation The translation.
         * @param [in,out]  rotation    The rotation.
         * @param [in,out]  scale       The scale.
         * @param [in,out]  so          The so.
         */
        void Decompose(Vec3d& translation, Quat& rotation, Vec3d& scale, Quat& so) const;

        /**
         * @fn  void Matrixd::MakeOrtho(double left, double right, double bottom, double top, double zNear, double zFar);
         *
         * @brief   Set to an orthographic projection. See glOrtho for further details.
         *
         * @param   left    The left.
         * @param   right   The right.
         * @param   bottom  The bottom.
         * @param   top     The top.
         * @param   zNear   The near.
         * @param   zFar    The far.
         */
        void MakeOrtho(double left, double right, double bottom, double top, double zNear, double zFar);

        /**
         * @fn  void Matrixd::MakeOrtho(float left, float right, float bottom, float top, float zNear, float zFar);
         *
         * @brief   Set to an orthographic projection. See glOrtho for further details.
         *
         * @param   left    The left.
         * @param   right   The right.
         * @param   bottom  The bottom.
         * @param   top     The top.
         * @param   zNear   The near.
         * @param   zFar    The far.
         */
        void MakeOrtho(float left, float right, float bottom, float top, float zNear, float zFar);

        /**
         * @fn  bool Matrixd::GetOrtho(double& left, double& right, double& bottom, double& top, double& zNear, double& zFar) const;
         *
         * @brief   Get the orthographic settings of the orthographic projection matrix. Note, if matrix
         *          is not an orthographic matrix then invalid values will be returned.
         *
         * @param [in,out]  left    The left.
         * @param [in,out]  right   The right.
         * @param [in,out]  bottom  The bottom.
         * @param [in,out]  top     The top.
         * @param [in,out]  zNear   The near.
         * @param [in,out]  zFar    The far.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool GetOrtho(double& left, double& right, double& bottom, double& top, double& zNear, double& zFar) const;

        /**
         * @fn  bool Matrixd::GetOrtho(float& left, float& right, float& bottom, float& top, float& zNear, float& zFar) const;
         *
         * @brief   float version of getOrtho(..)
         *          Get the orthographic settings of the orthographic projection matrix. Note, if matrix
         *          is not an orthographic matrix then invalid values will be returned.
         *
         * @param [in,out]  left    The left.
         * @param [in,out]  right   The right.
         * @param [in,out]  bottom  The bottom.
         * @param [in,out]  top     The top.
         * @param [in,out]  zNear   The near.
         * @param [in,out]  zFar    The far.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool GetOrtho(float& left, float& right, float& bottom, float& top, float& zNear, float& zFar) const;

        /**
         * @fn  void Matrixd::MakeOrtho2D(double left, double right, double bottom, double top);
         *
         * @brief   Set to a 2D orthographic projection. See glOrtho2D for further details.
         *
         * @param   left    The left.
         * @param   right   The right.
         * @param   bottom  The bottom.
         * @param   top     The top.
         */
        void MakeOrtho2D(double left, double right, double bottom, double top);

        /**
         * @fn  void Matrixd::MakeOrtho2D(float left, float right, float bottom, float top);
         *
         * @brief   Set to a 2D orthographic projection. See glOrtho2D for further details.
         *
         * @param   left    The left.
         * @param   right   The right.
         * @param   bottom  The bottom.
         * @param   top     The top.
         */
        void MakeOrtho2D(float left, float right, float bottom, float top);

        /**
         * @fn  void Matrixd::MakeFrustum(double left, double right, double bottom, double top, double zNear, double zFar);
         *
         * @brief   Set to a perspective projection. See glFrustum for further details.
         *
         * @param   left    The left.
         * @param   right   The right.
         * @param   bottom  The bottom.
         * @param   top     The top.
         * @param   zNear   The near.
         * @param   zFar    The far.
         */
        void MakeFrustum(double left, double right, double bottom, double top, double zNear, double zFar);

        /**
         * @fn  void Matrixd::MakeFrustum(float left, float right, float bottom, float top, float zNear, float zFar);
         *
         * @brief   Set to a perspective projection. See glFrustum for further details.
         *
         * @param   left    The left.
         * @param   right   The right.
         * @param   bottom  The bottom.
         * @param   top     The top.
         * @param   zNear   The near.
         * @param   zFar    The far.
         */
        void MakeFrustum(float left, float right, float bottom, float top, float zNear, float zFar);

        /**
         * @fn  bool Matrixd::GetFrustum(double& left, double& right, double& bottom, double& top, double& zNear, double& zFar) const;
         *
         * @brief   Get the frustum settings of a perspective projection matrix. Note, if matrix is not a
         *          perspective matrix then invalid values will be returned.
         *
         * @param [in,out]  left    The left.
         * @param [in,out]  right   The right.
         * @param [in,out]  bottom  The bottom.
         * @param [in,out]  top     The top.
         * @param [in,out]  zNear   The near.
         * @param [in,out]  zFar    The far.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool GetFrustum(double& left, double& right, double& bottom, double& top, double& zNear, double& zFar) const;

        /**
         * @fn  bool Matrixd::GetFrustum(float& left, float& right, float& bottom, float& top, float& zNear, float& zFar) const;
         *
         * @brief   float version of getFrustum(..)
         *          Get the frustum settings of a perspective projection matrix. Note, if matrix is not a
         *          perspective matrix then invalid values will be returned.
         *
         * @param [in,out]  left    The left.
         * @param [in,out]  right   The right.
         * @param [in,out]  bottom  The bottom.
         * @param [in,out]  top     The top.
         * @param [in,out]  zNear   The near.
         * @param [in,out]  zFar    The far.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool GetFrustum(float& left, float& right, float& bottom, float& top, float& zNear, float& zFar) const;

        /**
         * @fn  void Matrixd::MakePerspective(double fovy, double aspectRatio, double zNear, double zFar);
         *
         * @brief   Set to a symmetrical perspective projection. See gluPerspective for further details.
         *          Aspect ratio is defined as width/height.
         *
         * @param   fovy        The fovy.
         * @param   aspectRatio The aspect ratio.
         * @param   zNear       The near.
         * @param   zFar        The far.
         */
        void MakePerspective(double fovy, double aspectRatio, double zNear, double zFar);

        /**
         * @fn  void Matrixd::MakePerspective(float fovy, float aspectRatio, float zNear, float zFar);
         *
         * @brief   Set to a symmetrical perspective projection. See gluPerspective for further details.
         *          Aspect ratio is defined as width/height.
         *
         * @param   fovy        The fovy.
         * @param   aspectRatio The aspect ratio.
         * @param   zNear       The near.
         * @param   zFar        The far.
         */
        void MakePerspective(float fovy, float aspectRatio, float zNear, float zFar);

        /**
         * @fn  bool Matrixd::GetPerspective(double& fovy, double& aspectRatio, double& zNear, double& zFar) const;
         *
         * @brief   Get the frustum settings of a symmetric perspective projection matrix. Return false
         *          if matrix is not a perspective matrix, where parameter values are undefined. Note, if
         *          matrix is not a symmetric perspective matrix then the shear will be lost.
         *
         * @param [in,out]  fovy        The fovy.
         * @param [in,out]  aspectRatio The aspect ratio.
         * @param [in,out]  zNear       The near.
         * @param [in,out]  zFar        The far.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool GetPerspective(double& fovy, double& aspectRatio, double& zNear, double& zFar) const;

        /**
         * @fn  bool Matrixd::GetPerspective(float& fovy, float& aspectRatio, float& zNear, float& zFar) const;
         *
         * @brief   float version of getPerspective(..)
         *          Get the frustum settings of a symmetric perspective projection matrix. Return false
         *          if matrix is not a perspective matrix, where parameter values are undefined. Note, if
         *          matrix is not a symmetric perspective matrix then the shear will be lost.
         *
         * @param [in,out]  fovy        The fovy.
         * @param [in,out]  aspectRatio The aspect ratio.
         * @param [in,out]  zNear       The near.
         * @param [in,out]  zFar        The far.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool GetPerspective(float& fovy, float& aspectRatio, float& zNear, float& zFar) const;

        /**
         * @fn  void Matrixd::MakeLookAt(const Vec3f& eye, const Vec3f& center, const Vec3f& up);
         *
         * @brief   Set the position and orientation to be a view matrix, using the same convention as
         *          gluLookAt.
         *
         * @param   eye     The eye.
         * @param   center  The center.
         * @param   up      The up.
         */
        void MakeLookAt(const Vec3f& eye, const Vec3f& center, const Vec3f& up);

        /**
         * @fn  void Matrixd::MakeLookAt(const Vec3d& eye, const Vec3d& center, const Vec3d& up);
         *
         * @brief   Set the position and orientation to be a view matrix, using the same convention as
         *          gluLookAt.
         *
         * @param   eye     The eye.
         * @param   center  The center.
         * @param   up      The up.
         */
        void MakeLookAt(const Vec3d& eye, const Vec3d& center, const Vec3d& up);

        /**
         * @fn  void Matrixd::GetLookAt(Vec3f& eye, Vec3f& center, Vec3f& up, value_type lookDistance = 1.0f) const;
         *
         * @brief   Get to the position and orientation of a modelview matrix, using the same convention
         *          as gluLookAt.
         *
         * @param [in,out]  eye             The eye.
         * @param [in,out]  center          The center.
         * @param [in,out]  up              The up.
         * @param           lookDistance    (Optional) The look distance.
         */
        void GetLookAt(Vec3f& eye, Vec3f& center, Vec3f& up, value_type lookDistance = 1.0f) const;

        /**
         * @fn  void Matrixd::GetLookAt(Vec3d& eye, Vec3d& center, Vec3d& up, value_type lookDistance = 1.0f) const;
         *
         * @brief   Get to the position and orientation of a modelview matrix, using the same convention
         *          as gluLookAt.
         *
         * @param [in,out]  eye             The eye.
         * @param [in,out]  center          The center.
         * @param [in,out]  up              The up.
         * @param           lookDistance    (Optional) The look distance.
         */
        void GetLookAt(Vec3d& eye, Vec3d& center, Vec3d& up, value_type lookDistance = 1.0f) const;

        /**
         * @fn  bool Matrixd::Invert(const Matrixd& rhs);
         *
         * @brief   Invert the matrix rhs, automatically select invert_4x3 or invert_4x4.
         *
         * @param   rhs The right hand side.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Invert(const Matrixd& rhs);

        /**
         * @fn  bool Matrixd::Invert_4x3(const Matrixd& rhs);
         *
         * @brief   4x3 matrix invert, not right hand column is assumed to be 0,0,0,1.
         *
         * @param   rhs The right hand side.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Invert_4x3(const Matrixd& rhs);

        /**
         * @fn  bool Matrixd::Invert_4x4(const Matrixd& rhs);
         *
         * @brief   Full 4x4 matrix invert.
         *
         * @param   rhs The right hand side.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool Invert_4x4(const Matrixd& rhs);

        /**
         * @fn  void Matrixd::OrthoNormalize(const Matrixd& rhs);
         *
         * @brief   Ortho-normalize the 3x3 rotation &amp; scale matrix.
         *
         * @param   rhs The right hand side.
         */
        void OrthoNormalize(const Matrixd& rhs);

        /**
         * @fn  void Matrixd::SetRotate(const Quat& q);
         *
         * @brief   Applies the rotation to the matrix.
         *
         * @param   q   The Quat to process.
         */
        void SetRotate(const Quat& q);

        /**
         * @fn  Quat Matrixd::GetRotate() const;
         *
         * @brief   Get the matrix rotation as a Quat. Note that this function assumes a non-scaled
         *          matrix and will return incorrect results for scaled matrixces. Consider decompose()
         *          instead.
         *
         * @return  The rotate.
         */
        Quat GetRotate() const;

        /**
         * @fn  void Matrixd::SetTrans(value_type tx, value_type ty, value_type tz);
         *
         * @brief   Sets the translation area of the matrix.
         *
         * @param   tx  The transmit.
         * @param   ty  The ty.
         * @param   tz  The tz.
         */
        void SetTrans(value_type tx, value_type ty, value_type tz);

        /**
         * @fn  void Matrixd::SetTrans(const Vec3f& v);
         *
         * @brief   Sets the translation area of the matrix.
         *
         * @param   v   The Vec3f to process.
         */
        void SetTrans(const Vec3f& v);

        /**
         * @fn  void Matrixd::SetTrans(const Vec3d& v);
         *
         * @brief   Sets the translation area of the matrix.
         *
         * @param   v   The Vec3d to process.
         */
        void SetTrans(const Vec3d& v);

        /**
         * @fn  Vec3d Matrixd::GetTrans() const;
         *
         * @brief   Returns the translation area of the matrix.
         *
         * @return  The transaction.
         */
        Vec3d GetTrans() const;

        /**
         * @fn  Vec3d Matrixd::GetScale() const;
         *
         * @brief   Returns the matrix scale.
         *
         * @return  The scale.
         */
        Vec3d GetScale() const;

        /**
         * @fn  void Matrixd::SetScale(value_type x, value_type y, value_type z);
         *
         * @brief   Sets the scale values of the matrix.
         *
         * @param   x   The value_type to process.
         * @param   y   The value_type to process.
         * @param   z   The value_type to process.
         */
        void SetScale(value_type x, value_type y, value_type z);

        /**
         * @fn  void Matrixd::SetScale(const Vec3f& v);
         *
         * @brief   Sets the scale values of the matrix.
         *
         * @param   v   The Vec3f to process.
         */
        void SetScale(const Vec3f& v);

        /**
         * @fn  void Matrixd::SetScale(const Vec3d& v);
         *
         * @brief   Sets the scale values of the matrix.
         *
         * @param   v   The Vec3d to process.
         */
        void SetScale(const Vec3d& v);

        /**
         * @fn  Vec3f Matrixd::PreMult(const Vec3f& v) const;
         *
         * @brief   PreMultiply the matrix by the passed in vector.
         *
         * @param   v   The Vec3f to process.
         *
         * @return  A Vec3f.
         */
        Vec3f PreMult(const Vec3f& v) const;

        /**
         * @fn  Vec3d Matrixd::PreMult(const Vec3d& v) const;
         *
         * @brief   PreMultiply the matrix by the passed in vector.
         *
         * @param   v   The Vec3d to process.
         *
         * @return  A Vec3d.
         */
        Vec3d PreMult(const Vec3d& v) const;

        /**
         * @fn  Vec3f Matrixd::PostMult(const Vec3f& v) const;
         *
         * @brief   PostMultiply the matrix by the passed in vector.
         *
         * @param   v   The Vec3f to process.
         *
         * @return  A Vec3f.
         */
        Vec3f PostMult(const Vec3f& v) const;

        /**
         * @fn  Vec3d Matrixd::PostMult(const Vec3d& v) const;
         *
         * @brief   PostMultiply the matrix by the passed in vector.
         *
         * @param   v   The Vec3d to process.
         *
         * @return  A Vec3d.
         */
        Vec3d PostMult(const Vec3d& v) const;

        /**
         * @fn  Vec4f Matrixd::PreMult(const Vec4f& v) const;
         *
         * @brief   PreMultiply the matrix by the passed in vector.
         *
         * @param   v   The Vec4f to process.
         *
         * @return  A Vec4f.
         */
        Vec4f PreMult(const Vec4f& v) const;

        /**
         * @fn  Vec4d Matrixd::PreMult(const Vec4d& v) const;
         *
         * @brief   PreMultiply the matrix by the passed in vector.
         *
         * @param   v   The Vec4d to process.
         *
         * @return  A Vec4d.
         */
        Vec4d PreMult(const Vec4d& v) const;

        /**
         * @fn  Vec4f Matrixd::PostMult(const Vec4f& v) const;
         *
         * @brief   PostMultiply the matrix by the passed in vector.
         *
         * @param   v   The Vec4f to process.
         *
         * @return  A Vec4f.
         */
        Vec4f PostMult(const Vec4f& v) const;

        /**
         * @fn  Vec4d Matrixd::PostMult(const Vec4d& v) const;
         *
         * @brief   PostMultiply the matrix by the passed in vector.
         *
         * @param   v   The Vec4d to process.
         *
         * @return  A Vec4d.
         */
        Vec4d PostMult(const Vec4d& v) const;

        /**
         * @fn  void Matrixd::Mult(const Matrixd& m1, const Matrixd& m2);
         *
         * @brief   Basic Matrixd multiplication, our workhorse methods.
         *
         * @param   m1  The first Matrixd.
         * @param   m2  The second Matrixd.
         */
        void Mult(const Matrixd& m1, const Matrixd& m2);

        /**
         * @fn  void Matrixd::PreMult(const Matrixd& m);
         *
         * @brief   Basic Matrixd multiplication, our workhorse methods.
         *
         * @param   m   The Matrixd to process.
         */
        void PreMult(const Matrixd& m);

        /**
         * @fn  void Matrixd::PostMult(const Matrixd& m);
         *
         * @brief   Basic Matrixd multiplication, our workhorse methods.
         *
         * @param   m   The Matrixd to process.
         */
        void PostMult(const Matrixd& m);

        /**
         * @fn  void Matrixd::PreMultTranslate(const Vec3d& v);
         *
         * @brief   Optimized version of preMult(translate(v));
         *
         * @param   v   The Vec3d to process.
         */
        void PreMultTranslate(const Vec3d& v);

        /**
         * @fn  void Matrixd::PreMultTranslate(const Vec3f& v);
         *
         * @brief   Optimized version of preMult(translate(v));
         *
         * @param   v   The Vec3f to process.
         */
        void PreMultTranslate(const Vec3f& v);

        /**
         * @fn  void Matrixd::PostMultTranslate(const Vec3d& v);
         *
         * @brief   Optimized version of postMult(translate(v));
         *
         * @param   v   The Vec3d to process.
         */
        void PostMultTranslate(const Vec3d& v);

        /**
         * @fn  void Matrixd::PostMultTranslate(const Vec3f& v);
         *
         * @brief   Optimized version of postMult(translate(v));
         *
         * @param   v   The Vec3f to process.
         */
        void PostMultTranslate(const Vec3f& v);

        /**
         * @fn  void Matrixd::PreMultScale(const Vec3d& v);
         *
         * @brief   Optimized version of preMult(scale(v));
         *
         * @param   v   The Vec3d to process.
         */
        void PreMultScale(const Vec3d& v);

        /**
         * @fn  void Matrixd::PreMultScale(const Vec3f& v);
         *
         * @brief   Optimized version of preMult(scale(v));
         *
         * @param   v   The Vec3f to process.
         */
        void PreMultScale(const Vec3f& v);

        /**
         * @fn  void Matrixd::PostMultScale(const Vec3d& v);
         *
         * @brief   Optimized version of postMult(scale(v));
         *
         * @param   v   The Vec3d to process.
         */
        void PostMultScale(const Vec3d& v);

        /**
         * @fn  void Matrixd::PostMultScale(const Vec3f& v);
         *
         * @brief   Optimized version of postMult(scale(v));
         *
         * @param   v   The Vec3f to process.
         */
        void PostMultScale(const Vec3f& v);

        /**
         * @fn  void Matrixd::PreMultRotate(const Quat& q);
         *
         * @brief   Optimized version of preMult(rotate(q));
         *
         * @param   q   The Quat to process.
         */
        void PreMultRotate(const Quat& q);

        /**
         * @fn  void Matrixd::PostMultRotate(const Quat& q);
         *
         * @brief   Optimized version of postMult(rotate(q));
         *
         * @param   q   The Quat to process.
         */
        void PostMultRotate(const Quat& q);

        /**
         * @fn  std::string Matrixd::ToString(int precision = -1);
         *
         * @brief   Convert this object into a string representation.
         *
         * @param   precision   (Optional) The precision.
         *
         * @return  A std::string that represents this object.
         */
        std::string ToString(int precision = -1);

        /**
         * @fn  static Matrixd Matrixd::Identity(void);
         *
         * @brief   Static method to create an Identity matrix.
         *
         * @return  A Matrixd.
         */
        static Matrixd Identity(void);

        /**
         * @fn  static Matrixd Matrixd::Scale(const Vec3f& sv);
         *
         * @brief   Static method to create a Scale matrix.
         *
         * @param   sv  The sv.
         *
         * @return  A Matrixd.
         */
        static Matrixd Scale(const Vec3f& sv);

        /**
         * @fn  static Matrixd Matrixd::Scale(const Vec3d& sv);
         *
         * @brief   Static method to create a Scale matrix.
         *
         * @param   sv  The sv.
         *
         * @return  A Matrixd.
         */
        static Matrixd Scale(const Vec3d& sv);

        /**
         * @fn  static Matrixd Matrixd::Scale(value_type sx, value_type sy, value_type sz);
         *
         * @brief   Static method to create a Scale matrix.
         *
         * @param   sx  The sx.
         * @param   sy  The sy.
         * @param   sz  The size.
         *
         * @return  A Matrixd.
         */
        static Matrixd Scale(value_type sx, value_type sy, value_type sz);

        /**
         * @fn  static Matrixd Matrixd::Translate(const Vec3f& dv);
         *
         * @brief   Static method to create a Translate matrix.
         *
         * @param   dv  The dv.
         *
         * @return  A Matrixd.
         */
        static Matrixd Translate(const Vec3f& dv);

        /**
         * @fn  static Matrixd Matrixd::Translate(const Vec3d& dv);
         *
         * @brief   Static method to create a Translate matrix.
         *
         * @param   dv  The dv.
         *
         * @return  A Matrixd.
         */
        static Matrixd Translate(const Vec3d& dv);

        /**
         * @fn  static Matrixd Matrixd::Translate(value_type x, value_type y, value_type z);
         *
         * @brief   Static method to create a Translate matrix.
         *
         * @param   x   The value_type to process.
         * @param   y   The value_type to process.
         * @param   z   The value_type to process.
         *
         * @return  A Matrixd.
         */
        static Matrixd Translate(value_type x, value_type y, value_type z);

        /**
         * @fn  static Matrixd Matrixd::Rotate(const Vec3f& from, const Vec3f& to);
         *
         * @brief   Static method to create a Rotational matrix.
         *
         * @param   from    Source for the.
         * @param   to      to.
         *
         * @return  A Matrixd.
         */
        static Matrixd Rotate(const Vec3f& from, const Vec3f& to);

        /**
         * @fn  static Matrixd Matrixd::Rotate(const Vec3d& from, const Vec3d& to);
         *
         * @brief   Static method to create a Rotational matrix.
         *
         * @param   from    Source for the.
         * @param   to      to.
         *
         * @return  A Matrixd.
         */
        static Matrixd Rotate(const Vec3d& from, const Vec3d& to);

        /**
         * @fn  static Matrixd Matrixd::Rotate(value_type angle, value_type x, value_type y, value_type z);
         *
         * @brief   Static method to create a Rotational matrix.
         *
         * @param   angle   The angle.
         * @param   x       The value_type to process.
         * @param   y       The value_type to process.
         * @param   z       The value_type to process.
         *
         * @return  A Matrixd.
         */
        static Matrixd Rotate(value_type angle, value_type x, value_type y, value_type z);

        /**
         * @fn  static Matrixd Matrixd::Rotate(value_type angle, const Vec3f& axis);
         *
         * @brief   Static method to create a Rotational matrix.
         *
         * @param   angle   The angle.
         * @param   axis    The axis.
         *
         * @return  A Matrixd.
         */
        static Matrixd Rotate(value_type angle, const Vec3f& axis);

        /**
         * @fn  static Matrixd Matrixd::Rotate(value_type angle, const Vec3d& axis);
         *
         * @brief   Static method to create a Rotational matrix.
         *
         * @param   angle   The angle.
         * @param   axis    The axis.
         *
         * @return  A Matrixd.
         */
        static Matrixd Rotate(value_type angle, const Vec3d& axis);

        /**
         * @fn  static Matrixd Matrixd::Rotate(value_type angle1, const Vec3f& axis1, value_type angle2, const Vec3f& axis2, value_type angle3, const Vec3f& axis3);
         *
         * @brief   Static method to create a Rotational matrix.
         *
         * @param   angle1  The first angle.
         * @param   axis1   The first axis.
         * @param   angle2  The second angle.
         * @param   axis2   The second axis.
         * @param   angle3  The third angle.
         * @param   axis3   The third axis.
         *
         * @return  A Matrixd.
         */
        static Matrixd Rotate(value_type angle1, const Vec3f& axis1, value_type angle2, const Vec3f& axis2, value_type angle3, const Vec3f& axis3);

        /**
         * @fn  static Matrixd Matrixd::Rotate(value_type angle1, const Vec3d& axis1, value_type angle2, const Vec3d& axis2, value_type angle3, const Vec3d& axis3);
         *
         * @brief   Static method to create a Rotational matrix.
         *
         * @param   angle1  The first angle.
         * @param   axis1   The first axis.
         * @param   angle2  The second angle.
         * @param   axis2   The second axis.
         * @param   angle3  The third angle.
         * @param   axis3   The third axis.
         *
         * @return  A Matrixd.
         */
        static Matrixd Rotate(value_type angle1, const Vec3d& axis1, value_type angle2, const Vec3d& axis2, value_type angle3, const Vec3d& axis3);

        /**
         * @fn  static Matrixd Matrixd::Rotate(const Quat& quat);
         *
         * @brief   Static method to create a Rotational matrix.
         *
         * @param   quat    The quaternion.
         *
         * @return  A Matrixd.
         */
        static Matrixd Rotate(const Quat& quat);

        /**
         * @fn  static Matrixd Matrixd::Inverse(const Matrixd& matrix);
         *
         * @brief   Static method to create an inverted matrix.
         *
         * @param   matrix  The matrix.
         *
         * @return  A Matrixd.
         */
        static Matrixd Inverse(const Matrixd& matrix);

        /**
         * @fn  static Matrixd Matrixd::OrthoNormal(const Matrixd& matrix);
         *
         * @brief   Static method to create an Ortho Normalized matrix.
         *
         * @param   matrix  The matrix.
         *
         * @return  A Matrixd.
         */
        static Matrixd OrthoNormal(const Matrixd& matrix);

        /**
         * @fn  static Matrixd Matrixd::Ortho(double left, double right, double bottom, double top, double zNear, double zFar);
         *
         * @brief   Create an orthographic projection matrix. See glOrtho for further details.
         *
         * @param   left    The left.
         * @param   right   The right.
         * @param   bottom  The bottom.
         * @param   top     The top.
         * @param   zNear   The near.
         * @param   zFar    The far.
         *
         * @return  A Matrixd.
         */
        static Matrixd Ortho(double left, double right, double bottom, double top, double zNear, double zFar);

        /**
         * @fn  static Matrixd Matrixd::Ortho(float left, float right, float bottom, float top, float zNear, float zFar);
         *
         * @brief   Create an orthographic projection matrix. See glOrtho for further details.
         *
         * @param   left    The left.
         * @param   right   The right.
         * @param   bottom  The bottom.
         * @param   top     The top.
         * @param   zNear   The near.
         * @param   zFar    The far.
         *
         * @return  A Matrixd.
         */
        static Matrixd Ortho(float left, float right, float bottom, float top, float zNear, float zFar);

        /**
         * @fn  static Matrixd Matrixd::Ortho2D(double left, double right, double bottom, double top);
         *
         * @brief   Create a 2D orthographic projection matrix. See glOrtho for further details.
         *
         * @param   left    The left.
         * @param   right   The right.
         * @param   bottom  The bottom.
         * @param   top     The top.
         *
         * @return  A Matrixd.
         */
        static Matrixd Ortho2D(double left, double right, double bottom, double top);

        /**
         * @fn  static Matrixd Matrixd::Ortho2D(float left, float right, float bottom, float top);
         *
         * @brief   Create a 2D orthographic projection matrix. See glOrtho for further details.
         *
         * @param   left    The left.
         * @param   right   The right.
         * @param   bottom  The bottom.
         * @param   top     The top.
         *
         * @return  A Matrixd.
         */
        static Matrixd Ortho2D(float left, float right, float bottom, float top);

        /**
         * @fn  static Matrixd Matrixd::Frustum(double left, double right, double bottom, double top, double zNear, double zFar);
         *
         * @brief   Create a perspective projection matrix. See glFrustum for further details.
         *
         * @param   left    The left.
         * @param   right   The right.
         * @param   bottom  The bottom.
         * @param   top     The top.
         * @param   zNear   The near.
         * @param   zFar    The far.
         *
         * @return  A Matrixd.
         */
        static Matrixd Frustum(double left, double right, double bottom, double top, double zNear, double zFar);

        /**
         * @fn  static Matrixd Matrixd::Frustum(float left, float right, float bottom, float top, float zNear, float zFar);
         *
         * @brief   Create a perspective projection matrix. See glFrustum for further details.
         *
         * @param   left    The left.
         * @param   right   The right.
         * @param   bottom  The bottom.
         * @param   top     The top.
         * @param   zNear   The near.
         * @param   zFar    The far.
         *
         * @return  A Matrixd.
         */
        static Matrixd Frustum(float left, float right, float bottom, float top, float zNear, float zFar);

        /**
         * @fn  static Matrixd Matrixd::Perspective(float fovy, float aspectRatio, float zNear, float zFar);
         *
         * @brief   Create a symmetrical perspective projection matrix. See gluPerspective for further
         *          details. Aspect ratio is defined as width/height.
         *
         * @param   fovy        The fovy.
         * @param   aspectRatio The aspect ratio.
         * @param   zNear       The near.
         * @param   zFar        The far.
         *
         * @return  A Matrixd.
         */
        static Matrixd Perspective(float fovy, float aspectRatio, float zNear, float zFar);

        /**
         * @fn  static Matrixd Matrixd::Perspective(double fovy, double aspectRatio, double zNear, double zFar);
         *
         * @brief   Create a symmetrical perspective projection matrix. See gluPerspective for further
         *          details. Aspect ratio is defined as width/height.
         *
         * @param   fovy        The fovy.
         * @param   aspectRatio The aspect ratio.
         * @param   zNear       The near.
         * @param   zFar        The far.
         *
         * @return  A Matrixd.
         */
        static Matrixd Perspective(double fovy, double aspectRatio, double zNear, double zFar);

        /**
         * @fn  static Matrixd Matrixd::LookAt(const Vec3f& eye, const Vec3f& center, const Vec3f& up);
         *
         * @brief   Create the position and orientation matrix as per a camera, using the same convention
         *          as gluLookAt.
         *
         * @param   eye     The eye.
         * @param   center  The center.
         * @param   up      The up.
         *
         * @return  A Matrixd.
         */
        static Matrixd LookAt(const Vec3f& eye, const Vec3f& center, const Vec3f& up);

        /**
         * @fn  static Matrixd Matrixd::LookAt(const Vec3d& eye, const Vec3d& center, const Vec3d& up);
         *
         * @brief   Create the position and orientation matrix as per a camera, using the same convention
         *          as gluLookAt.
         *
         * @param   eye     The eye.
         * @param   center  The center.
         * @param   up      The up.
         *
         * @return  A Matrixd.
         */
        static Matrixd LookAt(const Vec3d& eye, const Vec3d& center, const Vec3d& up);

        /**
         * @fn  static Vec3f Matrixd::Transform3x3(const Vec3f& v, const Matrixd& m);
         *
         * @brief   Apply a 3x3 transform of v*M[0..2,0..2].
         *
         * @param   v   The Vec3f to process.
         * @param   m   The Matrixd to process.
         *
         * @return  A Vec3f.
         */
        static Vec3f Transform3x3(const Vec3f& v, const Matrixd& m);

        /**
         * @fn  static Vec3d Matrixd::Transform3x3(const Vec3d& v, const Matrixd& m);
         *
         * @brief   Apply a 3x3 transform of v*M[0..2,0..2].
         *
         * @param   v   The Vec3d to process.
         * @param   m   The Matrixd to process.
         *
         * @return  A Vec3d.
         */
        static Vec3d Transform3x3(const Vec3d& v, const Matrixd& m);

        /**
         * @fn  static Vec3f Matrixd::Transform3x3(const Matrixd& m, const Vec3f& v);
         *
         * @brief   Apply a 3x3 transform of M[0..2,0..2]*v.
         *
         * @param   m   The Matrixd to process.
         * @param   v   The Vec3f to process.
         *
         * @return  A Vec3f.
         */
        static Vec3f Transform3x3(const Matrixd& m, const Vec3f& v);

        /**
         * @fn  static Vec3d Matrixd::Transform3x3(const Matrixd& m, const Vec3d& v);
         *
         * @brief   Apply a 3x3 transform of M[0..2,0..2]*v.
         *
         * @param   m   The Matrixd to process.
         * @param   v   The Vec3d to process.
         *
         * @return  A Vec3d.
         */
        static Vec3d Transform3x3(const Matrixd& m, const Vec3d& v);

        /**
         * @fn  Matrixd& Matrixd::operator= (const Matrixd& rhs);
         *
         * @brief   Set operator.
         *
         * @param   rhs The right hand side.
         *
         * @return  A shallow copy of this object.
         */
        Matrixd& operator = (const Matrixd& rhs);

        /**
         * @fn  Matrixd& Matrixd::operator= (const Matrixf& rhs);
         *
         * @brief   Set operator.
         *
         * @param   rhs The right hand side.
         *
         * @return  A shallow copy of this object.
         */
        Matrixd& operator = (const Matrixf& rhs);

        /**
         * @fn  bool Matrixd::operator> (const Matrixd& m) const;
         *
         * @brief   Greater than by operator.
         *
         * @param   m   The Matrixd to process.
         *
         * @return  True if the first parameter is greater than to the second.
         */
        bool operator > (const Matrixd& m) const;

        /**
         * @fn  bool Matrixd::operator< (const Matrixd& m) const;
         *
         * @brief   Less than by operator.
         *
         * @param   m   The Matrixd to process.
         *
         * @return  True if the first parameter is less than the second.
         */
        bool operator < (const Matrixd& m) const;

        /**
         * @fn  bool Matrixd::operator== (const Matrixd& m) const;
         *
         * @brief   Equality operator.
         *
         * @param   m   The Matrixd to process.
         *
         * @return  True if the parameters are considered equivalent.
         */
        bool operator == (const Matrixd& m) const;

        /**
         * @fn  bool Matrixd::operator!= (const Matrixd& m) const;
         *
         * @brief   Inequality operator.
         *
         * @param   m   The Matrixd to process.
         *
         * @return  True if the parameters are not considered equivalent.
         */
        bool operator != (const Matrixd& m) const;

        /**
         * @fn  Vec3f Matrixd::operator* (const Vec3f& v) const;
         *
         * @brief   Multiply by vector.
         *
         * @param   v   The Vec3f to process.
         *
         * @return  The result of the operation.
         */
        Vec3f operator* (const Vec3f& v) const;

        /**
         * @fn  Vec3d Matrixd::operator* (const Vec3d& v) const;
         *
         * @brief   Multiply by vector.
         *
         * @param   v   The Vec3d to process.
         *
         * @return  The result of the operation.
         */
        Vec3d operator* (const Vec3d& v) const;

        /**
         * @fn  Vec4f Matrixd::operator* (const Vec4f& v) const;
         *
         * @brief   Multiply by vector.
         *
         * @param   v   The Vec4f to process.
         *
         * @return  The result of the operation.
         */
        Vec4f operator* (const Vec4f& v) const;

        /**
         * @fn  Vec4d Matrixd::operator* (const Vec4d& v) const;
         *
         * @brief   Multiply by vector.
         *
         * @param   v   The Vec4d to process.
         *
         * @return  The result of the operation.
         */
        Vec4d operator* (const Vec4d& v) const;

        /**
         * @fn  void Matrixd::operator*= (const Matrixd& other);
         *
         * @brief   Unary Multiply by a matrix.
         *
         * @param   other   The other.
         */
        void operator *= (const Matrixd& other);

        /**
         * @fn  Matrixd Matrixd::operator* (const Matrixd &m) const;
         *
         * @brief   Multiply by a matrix.
         *
         * @param   m   The Matrixd to process.
         *
         * @return  The result of the operation.
         */
        Matrixd operator * (const Matrixd &m) const;

        /**
         * @fn  Matrixd Matrixd::operator* (value_type rhs) const;
         *
         * @brief   Multiply by scalar.
         *
         * @param   rhs The right hand side.
         *
         * @return  The result of the operation.
         */
        Matrixd operator * (value_type rhs) const;

        /**
         * @fn  Matrixd& Matrixd::operator*= (value_type rhs);
         *
         * @brief   Unary multiply by scalar. More efficient than *.
         *
         * @param   rhs The right hand side.
         *
         * @return  The result of the operation.
         */
        Matrixd& operator *= (value_type rhs);

        /**
         * @fn  Matrixd Matrixd::operator/ (value_type rhs) const;
         *
         * @brief   Divide by scalar.
         *
         * @param   rhs The right hand side.
         *
         * @return  The result of the operation.
         */
        Matrixd operator / (value_type rhs) const;

        /**
         * @fn  Matrixd& Matrixd::operator/= (value_type rhs);
         *
         * @brief   Unary divide by scalar. More efficient than /.
         *
         * @param   rhs The right hand side.
         *
         * @return  The result of the operation.
         */
        Matrixd& operator /= (value_type rhs);

        /**
         * @fn  Matrixd Matrixd::operator+ (const Matrixd& rhs) const;
         *
         * @brief   Binary vector add.
         *
         * @param   rhs The right hand side.
         *
         * @return  The result of the operation.
         */
        Matrixd operator + (const Matrixd& rhs) const;

        /**
         * @fn  Matrixd& Matrixd::operator+= (const Matrixd& rhs);
         *
         * @brief   Unary vector add. More efficient than +.
         *
         * @param   rhs The right hand side.
         *
         * @return  The result of the operation.
         */
        Matrixd& operator += (const Matrixd& rhs);

        /**
         * @fn  Matrixd Matrixd::operator- (const Matrixd& rhs) const;
         *
         * @brief   Binary vector subtract.
         *
         * @param   rhs The right hand side.
         *
         * @return  The result of the operation.
         */
        Matrixd operator - (const Matrixd& rhs) const;

        /**
         * @fn  Matrixd& Matrixd::operator-= (const Matrixd& rhs);
         *
         * @brief   Unary vector subtract. More efficient than -.
         *
         * @param   rhs The right hand side.
         *
         * @return  The result of the operation.
         */
        Matrixd& operator -= (const Matrixd& rhs);

        /**
         * @fn  value_type& Matrixd::operator()(int row, int col);
         *
         * @brief   Returns a specific row and column value of the matrix.
         *
         * @param   row The row.
         * @param   col The col.
         *
         * @return  The result of the operation.
         */
        value_type& operator ()(int row, int col);

        /**
         * @fn  value_type Matrixd::operator()(int row, int col) const;
         *
         * @brief   Returns a specific row and column value of the matrix.
         *
         * @param   row The row.
         * @param   col The col.
         *
         * @return  The result of the operation.
         */
        value_type operator ()(int row, int col) const;

        /**
         * @fn  operator osg::Matrixd () const;
         *
         * @brief   Implicit conversion operator to OSG Matrix.
         *
         * @return  The result of the operation.
         */
        operator osg::Matrixd () const;

        /**
         * @fn  operator osg::Matrixd& ();
         *
         * @brief   Implicit conversion operator to OSG Matrix.
         *
         * @return  The result of the operation.
         */
        operator osg::Matrixd& ();

        /**
         * @fn  operator const osg::Matrixd& () const;
         *
         * @brief   Implicit conversion operator to OSG Matrix.
         *
         * @return  A const.
         */
        operator const osg::Matrixd& () const;

        /**
         * @fn  operator osg::Matrixd* ();
         *
         * @brief   Implicit conversion operator to OSG Matrix.
         *
         * @return  The result of the operation.
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