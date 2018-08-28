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

#include <trBase/Quat.h>
#include <trBase/Vec3d.h>
#include <trBase/Vec3f.h>
#include <trBase/Vec4d.h>
#include <trBase/Vec4f.h>

namespace trBase
{
    //////////////////////////////////////////////////////////////////////////
    MatrixImpl::MatrixImpl() 
    { 
        MakeIdentity(); 
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl::MatrixImpl(const MatrixImpl& mat) 
        : mMatrix(mat)
    { 
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl::MatrixImpl(float const * const ptr) 
        : mMatrix(ptr)
    { 
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl::MatrixImpl(double const * const ptr) 
        : mMatrix(ptr)
    { 
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl::MatrixImpl(const Quat& quat) 
        : mMatrix(quat)
    { 
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl::MatrixImpl(value_type a00, value_type a01, value_type a02, value_type a03,
        value_type a10, value_type a11, value_type a12, value_type a13,
        value_type a20, value_type a21, value_type a22, value_type a23,
        value_type a30, value_type a31, value_type a32, value_type a33)
        : mMatrix(a00, a01, a02, a03, a10, a11, a12, a13, a20, a21, a22, a23, a30, a31, a32, a33)
    {
    }

    //////////////////////////////////////////////////////////////////////////
    osg::MatrixImpl& MatrixImpl::GetOSGMatrix()
    {
        return mMatrix;
    }

    //////////////////////////////////////////////////////////////////////////
    const osg::MatrixImpl& MatrixImpl::GetOSGMatrix() const
    {
        return mMatrix;
    }

    //////////////////////////////////////////////////////////////////////////
    int MatrixImpl::Compare(const MatrixImpl& m) const 
    { 
        return mMatrix.compare(m); 
    }

    //////////////////////////////////////////////////////////////////////////
    bool MatrixImpl::Valid() const 
    { 
        return mMatrix.valid(); 
    }

    //////////////////////////////////////////////////////////////////////////
    bool MatrixImpl::IsNaN() const 
    { 
        return mMatrix.isNaN(); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::Set(const MatrixImpl& rhs) 
    { 
        Set(rhs.Ptr()); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::Set(float const * const ptr) 
    { 
        mMatrix.set(ptr); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::Set(double const * const ptr) 
    { 
        mMatrix.set(ptr); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::Set(value_type a00, value_type a01, value_type a02, value_type a03,
        value_type a10, value_type a11, value_type a12, value_type a13,
        value_type a20, value_type a21, value_type a22, value_type a23,
        value_type a30, value_type a31, value_type a32, value_type a33)
    {
        mMatrix.set(a00, a01, a02, a03, a10, a11, a12, a13,
            a20, a21, a22, a23, a30, a31, a32, a33);
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl::value_type* MatrixImpl::Ptr() 
    { 
        return mMatrix.ptr(); 
    }

    //////////////////////////////////////////////////////////////////////////
    const MatrixImpl::value_type* MatrixImpl::Ptr() const 
    { 
        return mMatrix.ptr(); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeIdentity() 
    { 
        mMatrix.makeIdentity(); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeScale(const Vec3f& v) 
    { 
        mMatrix.makeScale(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeScale(const Vec3d& v) 
    { 
        mMatrix.makeScale(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeScale(value_type x, value_type y, value_type z) 
    { 
        mMatrix.makeScale(x, y, z); 
    }
    
    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeTranslate(const Vec3f& v) 
    { 
        mMatrix.makeTranslate(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeTranslate(const Vec3d& v)  
    { 
        mMatrix.makeTranslate(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeTranslate(value_type x, value_type y, value_type z) 
    { 
        mMatrix.makeTranslate(x, y, z); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeRotate(const Vec3f& from, const Vec3f& to) 
    { 
        mMatrix.makeRotate(from, to); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeRotate(const Vec3d& from, const Vec3d& to) 
    { 
        mMatrix.makeRotate(from, to); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeRotate(value_type angle, const Vec3f& axis) 
    { 
        mMatrix.makeRotate(angle, axis); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeRotate(value_type angle, const Vec3d& axis) 
    { 
        mMatrix.makeRotate(angle, axis); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeRotate(value_type angle, value_type x, value_type y, value_type z) 
    { 
        mMatrix.makeRotate(angle, x, y, z); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeRotate(const Quat& q) 
    { 
        mMatrix.makeRotate(q); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeRotate(value_type angle1, const Vec3f& axis1, value_type angle2, const Vec3f& axis2, value_type angle3, const Vec3f& axis3) 
    { 
        mMatrix.makeRotate(angle1, axis1, angle2, axis2, angle3, axis3); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeRotate(value_type angle1, const Vec3d& axis1, value_type angle2, const Vec3d& axis2, value_type angle3, const Vec3d& axis3) 
    { 
        mMatrix.makeRotate(angle1, axis1, angle2, axis2, angle3, axis3); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::Decompose(Vec3f& translation, Quat& rotation, Vec3f& scale, Quat& so) const
    {
        mMatrix.decompose(translation, rotation, scale, so);
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::Decompose(Vec3d& translation, Quat& rotation, Vec3d& scale, Quat& so) const
    {
        mMatrix.decompose(translation, rotation, scale, so);
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeOrtho(value_type left, value_type right, value_type bottom, value_type top, value_type zNear, value_type zFar)
    {
        mMatrix.makeOrtho(left, right, bottom, top, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    bool MatrixImpl::GetOrtho(value_type& left, value_type& right, value_type& bottom, value_type& top, value_type& zNear, value_type& zFar) const
    {
        return mMatrix.getOrtho(left, right, bottom, top, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeOrtho2D(value_type left, value_type right, value_type bottom, value_type top)
    {
        mMatrix.makeOrtho(left, right, bottom, top, -1.0, 1.0);
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeFrustum(value_type left, value_type right, value_type bottom, value_type top, value_type zNear, value_type zFar)
    {
        mMatrix.makeFrustum(left, right, bottom, top, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    bool MatrixImpl::GetFrustum(value_type& left, value_type& right, value_type& bottom, value_type& top, value_type& zNear, value_type& zFar) const
    {
        return mMatrix.getFrustum(left, right, bottom, top, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakePerspective(value_type fovy, value_type aspectRatio, value_type zNear, value_type zFar)
    {
        mMatrix.makePerspective(fovy, aspectRatio, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    bool MatrixImpl::GetPerspective(value_type& fovy, value_type& aspectRatio, value_type& zNear, value_type& zFar) const
    {
        return mMatrix.getPerspective(fovy, aspectRatio, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeLookAt(const Vec3f& eye, const Vec3f& center, const Vec3f& up)
    {
        mMatrix.makeLookAt(eye.GetOSGVector(), center.GetOSGVector(), up.GetOSGVector());
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::MakeLookAt(const Vec3d& eye, const Vec3d& center, const Vec3d& up)
    {
        mMatrix.makeLookAt(eye, center, up);
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::GetLookAt(Vec3f& eye, Vec3f& center, Vec3f& up, value_type lookDistance) const
    {
        mMatrix.getLookAt(eye, center, up, lookDistance);
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::GetLookAt(Vec3d& eye, Vec3d& center, Vec3d& up, value_type lookDistance) const
    {
        mMatrix.getLookAt(eye, center, up, lookDistance);
    }

    //////////////////////////////////////////////////////////////////////////
    bool  MatrixImpl::Invert(const MatrixImpl& rhs)
    {
        return mMatrix.invert(rhs);
    }

    //////////////////////////////////////////////////////////////////////////
    bool  MatrixImpl::Invert_4x3(const MatrixImpl& rhs)
    {
        return mMatrix.invert_4x3(rhs);
    }

    //////////////////////////////////////////////////////////////////////////
    bool  MatrixImpl::Invert_4x4(const MatrixImpl& rhs)
    {
        return mMatrix.invert_4x4(rhs);
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::OrthoNormalize(const MatrixImpl& rhs)
    {
        mMatrix.orthoNormalize(rhs);
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::SetRotate(const Quat& q)
    {
        mMatrix.setRotate(q);
    }

    //////////////////////////////////////////////////////////////////////////
    Quat MatrixImpl::GetRotate() const 
    { 
        return mMatrix.getRotate(); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::SetTrans(value_type tx, value_type ty, value_type tz)
    {
        mMatrix.setTrans(tx, ty, tz);
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::SetTrans(const Vec3f& v)
    {
        mMatrix.setTrans(v);
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::SetTrans(const Vec3d& v)
    {
        mMatrix.setTrans(v);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3d MatrixImpl::GetTrans() const 
    { 
        return mMatrix.getTrans(); 
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3d MatrixImpl::GetScale() const
    {
        return mMatrix.getScale();
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::SetScale(value_type x, value_type y, value_type z)
    {
        mMatrix(0, 0) = x;
        mMatrix(1, 1) = y;
        mMatrix(2, 2) = z;
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::SetScale(const Vec3f& v)
    {
        SetScale(v[0], v[1], v[2]);
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::SetScale(const Vec3d& v)
    {
        SetScale(v[0], v[1], v[2]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3f MatrixImpl::PreMult(const Vec3f& v) const
    { 
        return mMatrix.preMult(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3d MatrixImpl::PreMult(const Vec3d& v) const
    { 
        return mMatrix.preMult(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3f MatrixImpl::PostMult(const Vec3f& v) const
    { 
        return mMatrix.postMult(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3d MatrixImpl::PostMult(const Vec3d& v) const
    { 
        return mMatrix.postMult(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4f MatrixImpl::PreMult(const Vec4f& v) const
    { 
        return mMatrix.preMult(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4d MatrixImpl::PreMult(const Vec4d& v) const
    { 
        return mMatrix.preMult(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4f MatrixImpl::PostMult(const Vec4f& v) const
    { 
        return mMatrix.postMult(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4d MatrixImpl::PostMult(const Vec4d& v) const
    { 
        return mMatrix.postMult(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::Mult(const MatrixImpl& m1, const MatrixImpl& m2)
    { 
        mMatrix.mult(m1, m2); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::PreMult(const MatrixImpl& m)
    { 
        mMatrix.preMult(m); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::PostMult(const MatrixImpl& m)
    { 
        mMatrix.postMult(m); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::PreMultTranslate(const Vec3d& v)
    { 
        mMatrix.preMultTranslate(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::PreMultTranslate(const Vec3f& v)
    { 
        mMatrix.preMultTranslate(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::PostMultTranslate(const Vec3d& v)
    { 
        mMatrix.postMultTranslate(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::PostMultTranslate(const Vec3f& v)
    { 
        mMatrix.postMultTranslate(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::PreMultScale(const Vec3d& v)
    { 
        mMatrix.preMultScale(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::PreMultScale(const Vec3f& v)
    { 
        mMatrix.preMultScale(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::PostMultScale(const Vec3d& v)
    { 
        mMatrix.postMultScale(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::PostMultScale(const Vec3f& v)
    { 
        mMatrix.postMultScale(v); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::PreMultRotate(const Quat& q)
    { 
        mMatrix.preMultRotate(q); 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::PostMultRotate(const Quat& q)
    { 
        mMatrix.preMultRotate(q); 
    }

    //////////////////////////////////////////////////////////////////////////
    std::string MatrixImpl::ToString(int precision)
    {
        return std::string("[" + trUtil::StringUtils::ToString<value_type>(mMatrix(0, 0), precision) + ", " + trUtil::StringUtils::ToString<value_type>(mMatrix(0, 1), precision) + ", " + trUtil::StringUtils::ToString<value_type>(mMatrix(0, 2), precision) + ", " + trUtil::StringUtils::ToString<value_type>(mMatrix(0, 3), precision) +
            "] [" + trUtil::StringUtils::ToString<value_type>(mMatrix(1, 0), precision) + ", " + trUtil::StringUtils::ToString<value_type>(mMatrix(1, 1), precision) + ", " + trUtil::StringUtils::ToString<value_type>(mMatrix(1, 2), precision) + ", " + trUtil::StringUtils::ToString<value_type>(mMatrix(1, 3), precision) +
            "] [" + trUtil::StringUtils::ToString<value_type>(mMatrix(2, 0), precision) + ", " + trUtil::StringUtils::ToString<value_type>(mMatrix(2, 1), precision) + ", " + trUtil::StringUtils::ToString<value_type>(mMatrix(2, 2), precision) + ", " + trUtil::StringUtils::ToString<value_type>(mMatrix(2, 3), precision) +
            "] [" + trUtil::StringUtils::ToString<value_type>(mMatrix(3, 0), precision) + ", " + trUtil::StringUtils::ToString<value_type>(mMatrix(3, 1), precision) + ", " + trUtil::StringUtils::ToString<value_type>(mMatrix(3, 2), precision) + ", " + trUtil::StringUtils::ToString<value_type>(mMatrix(3, 3), precision) +
            "]");
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Identity(void)
    {
        MatrixImpl m;
        m.MakeIdentity();
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Scale(const Vec3f& sv)
    {
        MatrixImpl m;
        m.MakeScale(sv);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Scale(const Vec3d& sv)
    {
        MatrixImpl m;
        m.MakeScale(sv);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Scale(value_type sx, value_type sy, value_type sz)
    {
        MatrixImpl m;
        m.MakeScale(sx, sy, sz);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Translate(const Vec3f& dv)
    {
        MatrixImpl m;
        m.MakeTranslate(dv);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Translate(const Vec3d& dv)
    {
        MatrixImpl m;
        m.MakeTranslate(dv);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Translate(value_type x, value_type y, value_type z)
    {
        MatrixImpl m;
        m.MakeTranslate(x, y, z);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Rotate(const Vec3f& from, const Vec3f& to)
    {
        MatrixImpl m;
        m.MakeRotate(from, to);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Rotate(const Vec3d& from, const Vec3d& to)
    {
        MatrixImpl m;
        m.MakeRotate(from, to);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Rotate(value_type angle, value_type x, value_type y, value_type z)
    {
        MatrixImpl m;
        m.MakeRotate(angle, x, y, z);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Rotate(value_type angle, const Vec3f& axis)
    {
        MatrixImpl m;
        m.MakeRotate(angle, axis);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Rotate(value_type angle, const Vec3d& axis)
    {
        MatrixImpl m;
        m.MakeRotate(angle, axis);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Rotate(value_type angle1, const Vec3f& axis1, value_type angle2, const Vec3f& axis2, value_type angle3, const Vec3f& axis3)
    {
        MatrixImpl m;
        m.MakeRotate(angle1, axis1, angle2, axis2, angle3, axis3);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Rotate(value_type angle1, const Vec3d& axis1, value_type angle2, const Vec3d& axis2, value_type angle3, const Vec3d& axis3)
    {
        MatrixImpl m;
        m.MakeRotate(angle1, axis1, angle2, axis2, angle3, axis3);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Rotate(const Quat& quat)
    {
        MatrixImpl m;
        m.MakeRotate(quat);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Inverse(const MatrixImpl& matrix)
    {
        MatrixImpl m;
        m.Invert(matrix);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::OrthoNormal(const MatrixImpl& matrix)
    {
        MatrixImpl m;
        m.OrthoNormalize(matrix);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Ortho(value_type left, value_type right, value_type bottom, value_type top, value_type zNear, value_type zFar)
    {
        MatrixImpl m;
        m.MakeOrtho(left, right, bottom, top, zNear, zFar);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Ortho2D(value_type left, value_type right, value_type bottom, value_type top)
    {
        MatrixImpl m;
        m.MakeOrtho2D(left, right, bottom, top);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Frustum(value_type left, value_type right, value_type bottom, value_type top, value_type zNear, value_type zFar)
    {
        MatrixImpl m;
        m.MakeFrustum(left, right, bottom, top, zNear, zFar);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::Perspective(value_type fovy, value_type aspectRatio, value_type zNear, value_type zFar)
    {
        MatrixImpl m;
        m.MakePerspective(fovy, aspectRatio, zNear, zFar);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::LookAt(const Vec3f& eye, const Vec3f& center, const Vec3f& up)
    {
        MatrixImpl m;
        m.MakeLookAt(eye, center, up);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::LookAt(const Vec3d& eye, const Vec3d& center, const Vec3d& up)
    {
        MatrixImpl m;
        m.MakeLookAt(eye, center, up);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3f MatrixImpl::Transform3x3(const Vec3f& v, const MatrixImpl& m)
    {
        return osg::MatrixImpl::transform3x3(v, m);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3d MatrixImpl::Transform3x3(const Vec3d& v, const MatrixImpl& m)
    {
        return osg::MatrixImpl::transform3x3(v, m);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3f MatrixImpl::Transform3x3(const MatrixImpl& m, const Vec3f& v)
    {
        return osg::MatrixImpl::transform3x3(m, v);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3d MatrixImpl::Transform3x3(const MatrixImpl& m, const Vec3d& v)
    {
        return osg::MatrixImpl::transform3x3(m, v);
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl& MatrixImpl::operator = (const MatrixImpl& rhs)
    {
        if (&rhs == this) return *this;
        Set(rhs);
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    bool MatrixImpl::operator > (const MatrixImpl& m) const 
    { 
        return Compare(m)>0; 
    }

    //////////////////////////////////////////////////////////////////////////
    bool MatrixImpl::operator < (const MatrixImpl& m) const 
    { 
        return Compare(m)<0; 
    }

    //////////////////////////////////////////////////////////////////////////
    bool MatrixImpl::operator == (const MatrixImpl& m) const 
    { 
        return Compare(m) == 0; 
    }

    //////////////////////////////////////////////////////////////////////////
    bool MatrixImpl::operator != (const MatrixImpl& m) const 
    { 
        return Compare(m) != 0; 
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3f MatrixImpl::operator* (const Vec3f& v) const 
    { 
        return mMatrix * v; 
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3d MatrixImpl::operator* (const Vec3d& v) const 
    { 
        return mMatrix * v; 
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4f MatrixImpl::operator* (const Vec4f& v) const 
    { 
        return mMatrix * v; 
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4d MatrixImpl::operator* (const Vec4d& v) const 
    { 
        return mMatrix * v; 
    }

    //////////////////////////////////////////////////////////////////////////
    void MatrixImpl::operator *= (const MatrixImpl& other)
    {
        if (this == &other)
        {
            MatrixImpl temp(other);
            PostMult(temp);
        }
        else
        {
            PostMult(other);
        }
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::operator * (const MatrixImpl &m) const
    {
        MatrixImpl r;
        r.Mult(*this, m);
        return  r;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::operator * (MatrixImpl::value_type rhs) const
    {
        return MatrixImpl(
            mMatrix(0, 0) * rhs,
            mMatrix(0, 1) * rhs,
            mMatrix(0, 2) * rhs,
            mMatrix(0, 3) * rhs,
            mMatrix(1, 0) * rhs,
            mMatrix(1, 1) * rhs,
            mMatrix(1, 2) * rhs,
            mMatrix(1, 3) * rhs,
            mMatrix(2, 0) * rhs,
            mMatrix(2, 1) * rhs,
            mMatrix(2, 2) * rhs,
            mMatrix(2, 3) * rhs,
            mMatrix(3, 0) * rhs,
            mMatrix(3, 1) * rhs,
            mMatrix(3, 2) * rhs,
            mMatrix(3, 3) * rhs);
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl& MatrixImpl::operator *= (MatrixImpl::value_type rhs)
    {
        mMatrix(0, 0) *= rhs;
        mMatrix(0, 1) *= rhs;
        mMatrix(0, 2) *= rhs;
        mMatrix(0, 3) *= rhs;
        mMatrix(1, 0) *= rhs;
        mMatrix(1, 1) *= rhs;
        mMatrix(1, 2) *= rhs;
        mMatrix(1, 3) *= rhs;
        mMatrix(2, 0) *= rhs;
        mMatrix(2, 1) *= rhs;
        mMatrix(2, 2) *= rhs;
        mMatrix(2, 3) *= rhs;
        mMatrix(3, 0) *= rhs;
        mMatrix(3, 1) *= rhs;
        mMatrix(3, 2) *= rhs;
        mMatrix(3, 3) *= rhs;
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::operator / (MatrixImpl::value_type rhs) const
    {
        return MatrixImpl(
            mMatrix(0, 0) / rhs,
            mMatrix(0, 1) / rhs,
            mMatrix(0, 2) / rhs,
            mMatrix(0, 3) / rhs,
            mMatrix(1, 0) / rhs,
            mMatrix(1, 1) / rhs,
            mMatrix(1, 2) / rhs,
            mMatrix(1, 3) / rhs,
            mMatrix(2, 0) / rhs,
            mMatrix(2, 1) / rhs,
            mMatrix(2, 2) / rhs,
            mMatrix(2, 3) / rhs,
            mMatrix(3, 0) / rhs,
            mMatrix(3, 1) / rhs,
            mMatrix(3, 2) / rhs,
            mMatrix(3, 3) / rhs);
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl& MatrixImpl::operator /= (MatrixImpl::value_type rhs)
    {
        mMatrix(0, 0) /= rhs;
        mMatrix(0, 1) /= rhs;
        mMatrix(0, 2) /= rhs;
        mMatrix(0, 3) /= rhs;
        mMatrix(1, 0) /= rhs;
        mMatrix(1, 1) /= rhs;
        mMatrix(1, 2) /= rhs;
        mMatrix(1, 3) /= rhs;
        mMatrix(2, 0) /= rhs;
        mMatrix(2, 1) /= rhs;
        mMatrix(2, 2) /= rhs;
        mMatrix(2, 3) /= rhs;
        mMatrix(3, 0) /= rhs;
        mMatrix(3, 1) /= rhs;
        mMatrix(3, 2) /= rhs;
        mMatrix(3, 3) /= rhs;
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::operator + (const MatrixImpl& rhs) const
    {
        return MatrixImpl(
            mMatrix(0, 0) + rhs(0, 0),
            mMatrix(0, 1) + rhs(0, 1),
            mMatrix(0, 2) + rhs(0, 2),
            mMatrix(0, 3) + rhs(0, 3),
            mMatrix(1, 0) + rhs(1, 0),
            mMatrix(1, 1) + rhs(1, 1),
            mMatrix(1, 2) + rhs(1, 2),
            mMatrix(1, 3) + rhs(1, 3),
            mMatrix(2, 0) + rhs(2, 0),
            mMatrix(2, 1) + rhs(2, 1),
            mMatrix(2, 2) + rhs(2, 2),
            mMatrix(2, 3) + rhs(2, 3),
            mMatrix(3, 0) + rhs(3, 0),
            mMatrix(3, 1) + rhs(3, 1),
            mMatrix(3, 2) + rhs(3, 2),
            mMatrix(3, 3) + rhs(3, 3));
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl& MatrixImpl::operator += (const MatrixImpl& rhs)
    {
        mMatrix(0, 0) += rhs(0, 0);
        mMatrix(0, 1) += rhs(0, 1);
        mMatrix(0, 2) += rhs(0, 2);
        mMatrix(0, 3) += rhs(0, 3);
        mMatrix(1, 0) += rhs(1, 0);
        mMatrix(1, 1) += rhs(1, 1);
        mMatrix(1, 2) += rhs(1, 2);
        mMatrix(1, 3) += rhs(1, 3);
        mMatrix(2, 0) += rhs(2, 0);
        mMatrix(2, 1) += rhs(2, 1);
        mMatrix(2, 2) += rhs(2, 2);
        mMatrix(2, 3) += rhs(2, 3);
        mMatrix(3, 0) += rhs(3, 0);
        mMatrix(3, 1) += rhs(3, 1);
        mMatrix(3, 2) += rhs(3, 2);
        mMatrix(3, 3) += rhs(3, 3);
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl MatrixImpl::operator - (const MatrixImpl& rhs) const
    {
        return MatrixImpl(
            mMatrix(0, 0) - rhs(0, 0),
            mMatrix(0, 1) - rhs(0, 1),
            mMatrix(0, 2) - rhs(0, 2),
            mMatrix(0, 3) - rhs(0, 3),
            mMatrix(1, 0) - rhs(1, 0),
            mMatrix(1, 1) - rhs(1, 1),
            mMatrix(1, 2) - rhs(1, 2),
            mMatrix(1, 3) - rhs(1, 3),
            mMatrix(2, 0) - rhs(2, 0),
            mMatrix(2, 1) - rhs(2, 1),
            mMatrix(2, 2) - rhs(2, 2),
            mMatrix(2, 3) - rhs(2, 3),
            mMatrix(3, 0) - rhs(3, 0),
            mMatrix(3, 1) - rhs(3, 1),
            mMatrix(3, 2) - rhs(3, 2),
            mMatrix(3, 3) - rhs(3, 3));
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl& MatrixImpl::operator -= (const MatrixImpl& rhs)
    {
        mMatrix(0, 0) -= rhs(0, 0);
        mMatrix(0, 1) -= rhs(0, 1);
        mMatrix(0, 2) -= rhs(0, 2);
        mMatrix(0, 3) -= rhs(0, 3);
        mMatrix(1, 0) -= rhs(1, 0);
        mMatrix(1, 1) -= rhs(1, 1);
        mMatrix(1, 2) -= rhs(1, 2);
        mMatrix(1, 3) -= rhs(1, 3);
        mMatrix(2, 0) -= rhs(2, 0);
        mMatrix(2, 1) -= rhs(2, 1);
        mMatrix(2, 2) -= rhs(2, 2);
        mMatrix(2, 3) -= rhs(2, 3);
        mMatrix(3, 0) -= rhs(3, 0);
        mMatrix(3, 1) -= rhs(3, 1);
        mMatrix(3, 2) -= rhs(3, 2);
        mMatrix(3, 3) -= rhs(3, 3);
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl::value_type& MatrixImpl::operator()(int row, int col) 
    { 
        return mMatrix(row, col); 
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl::value_type MatrixImpl::operator()(int row, int col) const 
    { 
        return mMatrix(row, col); 
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl::operator osg::MatrixImpl() const 
    { 
        return mMatrix; 
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl::operator osg::MatrixImpl&() 
    { 
        return mMatrix; 
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl::operator const osg::MatrixImpl&() const
    {
        return mMatrix;
    }

    //////////////////////////////////////////////////////////////////////////
    MatrixImpl::operator osg::MatrixImpl*() 
    { 
        return &mMatrix; 
    }

    //////////////////////////////////////////////////////////////////////////
    std::ostream& operator << (std::ostream& ios, const MatrixImpl& m)
    {
        ios << "[" << m(0, 0) << ", " << m(0, 1) << ", " << m(0, 2) << ", " << m(0, 3) <<
              "] [" << m(1, 0) << ", " << m(1, 1) << ", " << m(1, 2) << ", " << m(1, 3) <<
              "] [" << m(2, 0) << ", " << m(2, 1) << ", " << m(2, 2) << ", " << m(2, 3) <<
              "] [" << m(3, 0) << ", " << m(3, 1) << ", " << m(3, 2) << ", " << m(3, 3) <<
              "]";
        return ios;
    }
}