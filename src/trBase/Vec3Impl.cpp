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

namespace trBase
{
    //////////////////////////////////////////////////////////////////////////
    const int Vec3Impl::NUM_OF_COMPONENTS = 3;

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::Vec3Impl()
    {
        mVec._v[0] = 0.0; mVec._v[1] = 0.0; mVec._v[2] = 0.0;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::Vec3Impl(value_type x, value_type y, value_type z)
    {
        mVec._v[0] = x; mVec._v[1] = y; mVec._v[2] = z;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::Vec3Impl(const osg::Vec3Impl &v)
    {
        mVec.set(v.x(), v.y(), v.z());
    }

    //////////////////////////////////////////////////////////////////////////
    const osg::Vec3Impl& Vec3Impl::GetOSGVector() const
    {
        return mVec;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type Vec3Impl::Length() const
    {

        return sqrt(mVec._v[0] * mVec._v[0] + mVec._v[1] * mVec._v[1] + mVec._v[2] * mVec._v[2]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type Vec3Impl::Length2() const
    {
        return (mVec._v[0] * mVec._v[0] + mVec._v[1] * mVec._v[1] + mVec._v[2] * mVec._v[2]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type Vec3Impl::Normalize()
    {
        value_type norm = Vec3Impl::Length();
        if (norm>0.0)
        {
            value_type inv = 1.0 / norm;
            mVec._v[0] *= inv;
            mVec._v[1] *= inv;
            mVec._v[2] *= inv;
        }
        return norm;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type& Vec3Impl::X()
    {
        return mVec._v[0];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type& Vec3Impl::Y()
    {
        return mVec._v[1];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type& Vec3Impl::Z()
    {
        return mVec._v[2];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type Vec3Impl::X() const
    {
        return mVec._v[0];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type Vec3Impl::Y() const
    {
        return mVec._v[1];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type Vec3Impl::Z() const
    {
        return mVec._v[2];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type& Vec3Impl::R()
    {
        return mVec._v[0];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type& Vec3Impl::G()
    {
        return mVec._v[1];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type& Vec3Impl::B()
    {
        return mVec._v[2];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type Vec3Impl::R() const
    {
        return mVec._v[0];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type Vec3Impl::G() const
    {
        return mVec._v[1];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type Vec3Impl::B() const
    {
        return mVec._v[2];
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec3Impl::Set(value_type x, value_type y, value_type z)
    {
        mVec._v[0] = x; mVec._v[1] = y; mVec._v[2] = z;
    }

    /**
    * Sets the initial values of the vector
    */
    void Vec3Impl::Set(const Vec3Impl& v)
    {
        mVec._v[0] = v[0]; mVec._v[1] = v[1]; mVec._v[2] = v[2];
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec3Impl::SetRGB(value_type r, value_type g, value_type b)
    {
        mVec._v[0] = r; mVec._v[1] = g; mVec._v[2] = b;
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec3Impl::Lerp(const Vec3Impl& to, value_type alpha)
    {
        mVec._v[0] = trUtil::Math::Lerp<value_type>(mVec._v[0], to.X(), alpha);
        mVec._v[1] = trUtil::Math::Lerp<value_type>(mVec._v[1], to.Y(), alpha);
        mVec._v[2] = trUtil::Math::Lerp<value_type>(mVec._v[2], to.Z(), alpha);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl Vec3Impl::Lerp(const Vec3Impl& from, const Vec3Impl& to, value_type alpha)
    {
        return Vec3Impl(trUtil::Math::Lerp<value_type>(from.X(), to.X(), alpha), trUtil::Math::Lerp<value_type>(from.Y(), to.Y(), alpha), trUtil::Math::Lerp<value_type>(from.Z(), to.Z(), alpha));
    }

    //////////////////////////////////////////////////////////////////////////
    std::string Vec3Impl::ToString(int precision)
    {
        return std::string("<" + trUtil::StringUtils::ToString<value_type>(mVec._v[0], precision) + ", " + trUtil::StringUtils::ToString<value_type>(mVec._v[1], precision) + ", " + trUtil::StringUtils::ToString<value_type>(mVec._v[2], precision) + ">");
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type* Vec3Impl::Ptr()
    {
        return mVec.ptr();
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec3Impl::value_type* Vec3Impl::Ptr() const
    {
        return mVec.ptr();
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type& Vec3Impl::operator [] (int i)
    {
        return mVec[i];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type Vec3Impl::operator [] (int i) const
    {
        return mVec[i];
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec3Impl::operator = (const Vec3Impl& v)
    {
        mVec._v[0] = v[0]; mVec._v[1] = v[1]; mVec._v[2] = v[2];
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec3Impl::operator = (const osg::Vec3Impl& v)
    {
        mVec._v[0] = v[0]; mVec._v[1] = v[1]; mVec._v[2] = v[2];
    }

    //////////////////////////////////////////////////////////////////////////
    bool Vec3Impl::operator == (const Vec3Impl& v) const
    {
        return mVec._v[0] == v[0] && mVec._v[1] == v[1] && mVec._v[2] == v[2];
    }

    //////////////////////////////////////////////////////////////////////////
    bool Vec3Impl::operator != (const Vec3Impl& v) const
    {
        return mVec._v[0] != v[0] || mVec._v[1] != v[1] || mVec._v[2] != v[2];
    }

    //////////////////////////////////////////////////////////////////////////
    bool Vec3Impl::operator <  (const Vec3Impl& v) const
    {
        if (mVec._v[0]<v[0]) return true;
        else if (mVec._v[0]>v[0]) return false;
        else if (mVec._v[1]<v[1]) return true;
        else if (mVec._v[1]>v[1]) return false;
        else return (mVec._v[2]<v[2]);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Vec3Impl::operator >  (const Vec3Impl& v) const
    {
        if (mVec._v[0]>v[0]) return true;
        else if (mVec._v[0]<v[0]) return false;
        else if (mVec._v[1]>v[1]) return true;
        else if (mVec._v[1]<v[1]) return false;
        else return (mVec._v[2]>v[2]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::value_type Vec3Impl::operator * (const Vec3Impl& rhs) const
    {
        return mVec._v[0] * rhs[0] + mVec._v[1] * rhs[1] + mVec._v[2] * rhs[2];
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec3Impl Vec3Impl::operator * (Vec3Impl::value_type rhs) const
    {
        return Vec3Impl(mVec._v[0] * rhs, mVec._v[1] * rhs, mVec._v[2] * rhs);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl& Vec3Impl::operator *= (Vec3Impl::value_type rhs)
    {
        mVec._v[0] *= rhs;
        mVec._v[1] *= rhs;
        mVec._v[2] *= rhs;
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec3Impl Vec3Impl::operator / (Vec3Impl::value_type rhs) const
    {
        return Vec3Impl(mVec._v[0] / rhs, mVec._v[1] / rhs, mVec._v[2] / rhs);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl& Vec3Impl::operator /= (Vec3Impl::value_type rhs)
    {
        mVec._v[0] /= rhs;
        mVec._v[1] /= rhs;
        mVec._v[2] /= rhs;
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec3Impl Vec3Impl::operator + (const Vec3Impl& rhs) const
    {
        return Vec3Impl(mVec._v[0] + rhs[0], mVec._v[1] + rhs[1], mVec._v[2] + rhs[2]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl& Vec3Impl::operator += (const Vec3Impl& rhs)
    {
        mVec._v[0] += rhs[0];
        mVec._v[1] += rhs[1];
        mVec._v[2] += rhs[2];
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec3Impl Vec3Impl::operator - (const Vec3Impl& rhs) const
    {
        return Vec3Impl(mVec._v[0] - rhs[0], mVec._v[1] - rhs[1], mVec._v[2] - rhs[2]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl& Vec3Impl::operator -= (const Vec3Impl& rhs)
    {
        mVec._v[0] -= rhs[0];
        mVec._v[1] -= rhs[1];
        mVec._v[2] -= rhs[2];
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec3Impl Vec3Impl::operator - () const
    {
        return Vec3Impl(-1 * mVec._v[0], -1 * mVec._v[1], -1 * mVec._v[2]);
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec3Impl Vec3Impl::operator ^ (const Vec3Impl& rhs) const
    {
        return Vec3Impl(mVec._v[1] * rhs[2] - mVec._v[2] * rhs[1],
            mVec._v[2] * rhs[0] - mVec._v[0] * rhs[2],
            mVec._v[0] * rhs[1] - mVec._v[1] * rhs[0]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::operator osg::Vec3Impl () const
    {
        return mVec;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::operator osg::Vec3Impl& ()
    {
        return mVec;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::operator const osg::Vec3Impl& () const
    {
        return mVec;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl::operator osg::Vec3Impl* ()
    {
        return &mVec;
    }

    //////////////////////////////////////////////////////////////////////////
    std::ostream& operator << (std::ostream& ios, const Vec3Impl& vec)
    {
        ios << "<" << vec.X() << ", " << vec.Y() << ", " << vec.Z() << ">";
        return ios;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl ComponentMultiply(const Vec3Impl& lhs, const Vec3Impl& rhs)
    {
        return Vec3Impl(lhs[0] * rhs[0], lhs[1] * rhs[1], lhs[2] * rhs[2]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec3Impl ComponentDivide(const Vec3Impl& lhs, const Vec3Impl& rhs)
    {
        return Vec3Impl(lhs[0] / rhs[0], lhs[1] / rhs[1], lhs[2] / rhs[2]);
    }
}