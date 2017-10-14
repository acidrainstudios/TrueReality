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

#include <trBase/Matrixf.h>
#include <trBase/Matrixd.h>

namespace trBase
{
    //////////////////////////////////////////////////////////////////////////
    Quat::Quat()
    {}

    //////////////////////////////////////////////////////////////////////////
    Quat::Quat(const Quat& q)
    {
        Quat(q.X(), q.Y(), q.Z(), q.W());
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::Quat(const osg::Quat& q)
    {
        Quat(q.x(), q.y(), q.z(), q.w());
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::Quat(value_type x, value_type y, value_type z, value_type w)
    {
        mQuat.set(x, y, z, w);
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::Quat(const Vec4f& v)
    {
        mQuat.set(v);
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::Quat(const Vec4d& v)
    {
        mQuat.set(v);
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::Quat(value_type angle, const Vec3f& axis)
    {
        mQuat.makeRotate(angle, axis);
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::Quat(value_type angle, const Vec3d& axis)
    {
        mQuat.makeRotate(angle, axis);
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::Quat(value_type angle1, const Vec3f& axis1, value_type angle2, const Vec3f& axis2, value_type angle3, const Vec3f& axis3)
    {
        mQuat.makeRotate(angle1, axis1, angle2, axis2, angle3, axis3);
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::Quat(value_type angle1, const Vec3d& axis1, value_type angle2, const Vec3d& axis2, value_type angle3, const Vec3d& axis3)
    {
        mQuat.makeRotate(angle1, axis1, angle2, axis2, angle3, axis3);
    }

    //////////////////////////////////////////////////////////////////////////
    osg::Quat& Quat::GetOSGQuat()
    {
        return mQuat;
    }

    //////////////////////////////////////////////////////////////////////////
    const osg::Quat& Quat::GetOSGQuat() const
    {
        return mQuat;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4d Quat::AsVec4() const
    {
        return Vec4d(mQuat._v[0], mQuat._v[1], mQuat._v[2], mQuat._v[3]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3d Quat::AsVec3() const
    {
        return Vec3d(mQuat._v[0], mQuat._v[1], mQuat._v[2]);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::Set(const Quat& q)
    {
        mQuat._v[0] = q.X();
        mQuat._v[1] = q.Y();
        mQuat._v[2] = q.Z();
        mQuat._v[3] = q.W();
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::Set(const osg::Quat& q)
    {
        mQuat._v[0] = q.x();
        mQuat._v[1] = q.y();
        mQuat._v[2] = q.z();
        mQuat._v[3] = q.w();
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::Set(value_type x, value_type y, value_type z, value_type w)
    {
        mQuat._v[0] = x;
        mQuat._v[1] = y;
        mQuat._v[2] = z;
        mQuat._v[3] = w;
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::Set(const Vec4f& v)
    {
        mQuat._v[0] = v.X();
        mQuat._v[1] = v.Y();
        mQuat._v[2] = v.Z();
        mQuat._v[3] = v.W();
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::Set(const Vec4d& v)
    {
        mQuat._v[0] = v.X();
        mQuat._v[1] = v.Y();
        mQuat._v[2] = v.Z();
        mQuat._v[3] = v.W();
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::Set(const Matrixf& matrix)
    {
        mQuat.set(matrix);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::Set(const Matrixd& matrix)
    {
        mQuat.set(matrix);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::Get(Matrixf& matrix) const
    {
        mQuat.get(matrix);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::Get(Matrixd& matrix) const
    {
        mQuat.get(matrix);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::Set(const osg::Matrixf& matrix)
    {
        mQuat.set(matrix);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::Set(const osg::Matrixd& matrix)
    {
        mQuat.set(matrix);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::Get(osg::Matrixf& matrix) const
    {
        mQuat.get(matrix);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::Get(osg::Matrixd& matrix) const
    {
        mQuat.get(matrix);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Quat::IsZeroRotation() const
    { 
        return mQuat._v[0] == 0.0 && mQuat._v[1] == 0.0 && mQuat._v[2] == 0.0 && mQuat._v[3] == 1.0;
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::value_type Quat::Length() const
    {
        return sqrt(mQuat._v[0] * mQuat._v[0] + mQuat._v[1] * mQuat._v[1] + mQuat._v[2] * mQuat._v[2] + mQuat._v[3] * mQuat._v[3]);
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::value_type Quat::Length2() const
    {
        return mQuat._v[0] * mQuat._v[0] + mQuat._v[1] * mQuat._v[1] + mQuat._v[2] * mQuat._v[2] + mQuat._v[3] * mQuat._v[3];
    }

    //////////////////////////////////////////////////////////////////////////
    trBase::Quat Quat::Conj() const
    {
        return Quat(-mQuat._v[0], -mQuat._v[1], -mQuat._v[2], mQuat._v[3]);
    }

    //////////////////////////////////////////////////////////////////////////
    const trBase::Quat Quat::Inverse() const
    {
        return Conj() / Length2();
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::MakeRotate(value_type  angle, value_type  x, value_type  y, value_type  z)
    {
        mQuat.makeRotate(angle, x, y, z);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::MakeRotate(value_type  angle, const Vec3f& vec)
    {
        mQuat.makeRotate(angle, vec);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::MakeRotate(value_type  angle, const Vec3d& vec)
    {
        mQuat.makeRotate(angle, vec);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::MakeRotate(value_type  angle1, const Vec3f& axis1, value_type  angle2, const Vec3f& axis2, value_type  angle3, const Vec3f& axis3)
    {
        mQuat.makeRotate(angle1, axis1, angle2, axis2, angle3, axis3);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::MakeRotate(value_type  angle1, const Vec3d& axis1, value_type  angle2, const Vec3d& axis2, value_type  angle3, const Vec3d& axis3)
    {
        mQuat.makeRotate(angle1, axis1, angle2, axis2, angle3, axis3);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::MakeRotate(const Vec3f& vec1, const Vec3f& vec2)
    {
        mQuat.makeRotate(vec1, vec2);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::MakeRotate(const Vec3d& vec1, const Vec3d& vec2)
    {
        mQuat.makeRotate(vec1, vec2);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::GetRotate(value_type& angle, value_type& x, value_type& y, value_type& z) const
    {
        mQuat.getRotate(angle, x, y, z);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::GetRotate(value_type& angle, Vec3f& vec) const
    {
        mQuat.getRotate(angle, vec);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::GetRotate(value_type& angle, Vec3d& vec) const
    {
        mQuat.getRotate(angle, vec);
    }

    //////////////////////////////////////////////////////////////////////////
    void Quat::Slerp(value_type  t, const Quat& from, const Quat& to)
    {
        mQuat.slerp(t, from, to);
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::value_type& Quat::X() 
    { 
        return mQuat._v[0];
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::value_type& Quat::Y()
    {
        return mQuat._v[1];
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::value_type& Quat::Z()
    {
        return mQuat._v[2];
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::value_type& Quat::W()
    {
        return mQuat._v[3];
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::value_type Quat::X() const
    {
        return mQuat._v[0];
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::value_type Quat::Y() const
    {
        return mQuat._v[1];
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::value_type Quat::Z() const
    {
        return mQuat._v[2];
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::value_type Quat::W() const 
    {
        return mQuat._v[3];
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::value_type& Quat::operator [] (int i) 
    { 
        return mQuat._v[i]; 
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::value_type Quat::operator [] (int i) const
    {
        return mQuat._v[i];
    }

    //////////////////////////////////////////////////////////////////////////
    Quat& Quat::operator = (const Quat& v)
    { 
        mQuat._v[0] = v[0];  mQuat._v[1] = v[1]; mQuat._v[2] = v[2]; mQuat._v[3] = v[3];
        return *this; 
    }

    //////////////////////////////////////////////////////////////////////////
    bool Quat::operator == (const Quat& v) const 
    { 
        return mQuat._v[0] == v[0] && mQuat._v[1] == v[1] && mQuat._v[2] == v[2] && mQuat._v[3] == v[3];
    }

    //////////////////////////////////////////////////////////////////////////
    bool Quat::operator != (const Quat& v) const 
    { 
        return  mQuat._v[0] != v[0] || mQuat._v[1] != v[1] || mQuat._v[2] != v[2] || mQuat._v[3] != v[3];
    }

    //////////////////////////////////////////////////////////////////////////
    bool Quat::operator <  (const Quat& v) const
    {
        if (mQuat._v[0]<v[0]) return true;
        else if (mQuat._v[0]>v[0]) return false;
        else if (mQuat._v[1]<v[1]) return true;
        else if (mQuat._v[1]>v[1]) return false;
        else if (mQuat._v[2]<v[2]) return true;
        else if (mQuat._v[2]>v[2]) return false;
        else return (mQuat._v[3]<v[3]);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Quat::operator >  (const Quat& v) const
    {
        if (mQuat._v[0]>v[0]) return true;
        else if (mQuat._v[0]<v[0]) return false;
        else if (mQuat._v[1]>v[1]) return true;
        else if (mQuat._v[1]<v[1]) return false;
        else if (mQuat._v[2]>v[2]) return true;
        else if (mQuat._v[2]<v[2]) return false;
        else return (mQuat._v[3]>v[3]);
    }

    //////////////////////////////////////////////////////////////////////////
    const Quat Quat::operator * (value_type rhs) const
    {
        return Quat(mQuat._v[0] * rhs, mQuat._v[1] * rhs, mQuat._v[2] * rhs, mQuat._v[3] * rhs);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3f Quat::operator* (const Vec3f& v) const
    {
        // nVidia SDK implementation
        Vec3f uv, uuv;
        Vec3f qvec(mQuat._v[0], mQuat._v[1], mQuat._v[2]);
        uv = qvec ^ v;
        uuv = qvec ^ uv;
        uv *= (2.0f * mQuat._v[3]);
        uuv *= 2.0f;
        return v + uv + uuv;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3d Quat::operator* (const Vec3d& v) const
    {
        // nVidia SDK implementation
        Vec3d uv, uuv;
        Vec3d qvec(mQuat._v[0], mQuat._v[1], mQuat._v[2]);
        uv = qvec ^ v;
        uuv = qvec ^ uv;
        uv *= (2.0f * mQuat._v[3]);
        uuv *= 2.0f;
        return v + uv + uuv;
    }

    //////////////////////////////////////////////////////////////////////////
    Quat& Quat::operator *= (value_type rhs)
    {
        mQuat._v[0] *= rhs;
        mQuat._v[1] *= rhs;
        mQuat._v[2] *= rhs;
        mQuat._v[3] *= rhs;
        return *this;        // enable nesting
    }

    //////////////////////////////////////////////////////////////////////////
    const Quat Quat::operator*(const Quat& rhs) const
    {
        return Quat(rhs[3] * mQuat._v[0] + rhs[0] * mQuat._v[3] + rhs[1] * mQuat._v[2] - rhs[2] * mQuat._v[1],
                    rhs[3] * mQuat._v[1] - rhs[0] * mQuat._v[2] + rhs[1] * mQuat._v[3] + rhs[2] * mQuat._v[0],
                    rhs[3] * mQuat._v[2] + rhs[0] * mQuat._v[1] - rhs[1] * mQuat._v[0] + rhs[2] * mQuat._v[3],
                    rhs[3] * mQuat._v[3] - rhs[0] * mQuat._v[0] - rhs[1] * mQuat._v[1] - rhs[2] * mQuat._v[2]);
    }

    //////////////////////////////////////////////////////////////////////////
    Quat& Quat::operator*=(const Quat& rhs)
    {
        value_type x = rhs[3] * mQuat._v[0] + rhs[0] * mQuat._v[3] + rhs[1] * mQuat._v[2] - rhs[2] * mQuat._v[1];
        value_type y = rhs[3] * mQuat._v[1] - rhs[0] * mQuat._v[2] + rhs[1] * mQuat._v[3] + rhs[2] * mQuat._v[0];
        value_type z = rhs[3] * mQuat._v[2] + rhs[0] * mQuat._v[1] - rhs[1] * mQuat._v[0] + rhs[2] * mQuat._v[3];
        mQuat._v[3] = rhs[3] * mQuat._v[3] - rhs[0] * mQuat._v[0] - rhs[1] * mQuat._v[1] - rhs[2] * mQuat._v[2];

        mQuat._v[2] = z;
        mQuat._v[1] = y;
        mQuat._v[0] = x;

        return (*this);            // enable nesting
    }

    //////////////////////////////////////////////////////////////////////////
    Quat Quat::operator / (value_type rhs) const
    {
        value_type div = 1.0 / rhs;
        return Quat(mQuat._v[0] * div, mQuat._v[1] * div, mQuat._v[2] * div, mQuat._v[3] * div);
    }

    //////////////////////////////////////////////////////////////////////////
    Quat& Quat::operator /= (value_type rhs)
    {
        value_type div = 1.0 / rhs;
        mQuat._v[0] *= div;
        mQuat._v[1] *= div;
        mQuat._v[2] *= div;
        mQuat._v[3] *= div;
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    const Quat Quat::operator/(const Quat& denom) const
    {
        return ((*this) * denom.Inverse());
    }

    //////////////////////////////////////////////////////////////////////////
    Quat& Quat::operator/=(const Quat& denom)
    {
        (*this) = (*this) * denom.Inverse();
        return (*this);            // enable nesting
    }

    //////////////////////////////////////////////////////////////////////////
    const Quat Quat::operator + (const Quat& rhs) const
    {
        return Quat(mQuat._v[0] + rhs[0], mQuat._v[1] + rhs[1],
                    mQuat._v[2] + rhs[2], mQuat._v[3] + rhs[3]);
    }

    //////////////////////////////////////////////////////////////////////////
    Quat& Quat::operator += (const Quat& rhs)
    {
        mQuat._v[0] += rhs[0];
        mQuat._v[1] += rhs[1];
        mQuat._v[2] += rhs[2];
        mQuat._v[3] += rhs[3];
        return *this;            // enable nesting
    }

    //////////////////////////////////////////////////////////////////////////
    const Quat Quat::operator - (const Quat& rhs) const
    {
        return Quat(mQuat._v[0] - rhs[0], mQuat._v[1] - rhs[1],
                    mQuat._v[2] - rhs[2], mQuat._v[3] - rhs[3]);
    }

    //////////////////////////////////////////////////////////////////////////
    Quat& Quat::operator -= (const Quat& rhs)
    {
        mQuat._v[0] -= rhs[0];
        mQuat._v[1] -= rhs[1];
        mQuat._v[2] -= rhs[2];
        mQuat._v[3] -= rhs[3];
        return *this;            // enable nesting
    }

    //////////////////////////////////////////////////////////////////////////
    const Quat Quat::operator - () const
    {
        return Quat(-mQuat._v[0], -mQuat._v[1], -mQuat._v[2], -mQuat._v[3]);
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::operator osg::Quat() const
    {
        return mQuat;
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::operator osg::Quat&()
    {
        return mQuat;
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::operator const osg::Quat&() const
    {
        return mQuat;
    }

    //////////////////////////////////////////////////////////////////////////
    Quat::operator osg::Quat*()
    {
        return &mQuat;
    }

    //////////////////////////////////////////////////////////////////////////
    std::string Quat::ToString(int precision)
    {
        return std::string("[" + trUtil::StringUtils::ToString<value_type>(mQuat._v[0], precision) + "][" + trUtil::StringUtils::ToString<value_type>(mQuat._v[1], precision) +
                          "][" + trUtil::StringUtils::ToString<value_type>(mQuat._v[2], precision) + "][" + trUtil::StringUtils::ToString<value_type>(mQuat._v[3], precision) + "]");
    }

    //////////////////////////////////////////////////////////////////////////
    std::ostream& operator << (std::ostream& ios, const Quat& q)
    {
        ios << "[" << q.X() << "][" << q.Y() << "][" << q.Z() << "][" << q.W() << "]";
        return ios;
    }
}
