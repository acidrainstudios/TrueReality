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
    const int Vec4Impl::NUM_OF_COMPONENTS = 4;

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::Vec4Impl()
        : mVec()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::Vec4Impl(value_type x, value_type y, value_type z, value_type w)
        : mVec(x, y, z, w)
    {
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::Vec4Impl(const osg::Vec4Impl &v)
        : mVec(v[0], v[1], v[2], v[3])
    {        
    }

    //////////////////////////////////////////////////////////////////////////
    const osg::Vec4Impl& Vec4Impl::GetOSGVector() const
    {
        return mVec;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type Vec4Impl::Length() const
    {

        return sqrt(mVec._v[0] * mVec._v[0] + mVec._v[1] * mVec._v[1] + mVec._v[2] * mVec._v[2] + mVec._v[3] * mVec._v[3]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type Vec4Impl::Length2() const
    {
        return (mVec._v[0] * mVec._v[0] + mVec._v[1] * mVec._v[1] + mVec._v[2] * mVec._v[2] + mVec._v[3] * mVec._v[3]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type Vec4Impl::Normalize()
    {
        value_type norm = Vec4Impl::Length();
        if (norm>0.0)
        {
            value_type inv = 1.0 / norm;
            mVec._v[0] *= inv;
            mVec._v[1] *= inv;
            mVec._v[2] *= inv;
            mVec._v[3] *= inv;
        }
        return norm;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type& Vec4Impl::X()
    {
        return mVec._v[0];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type& Vec4Impl::Y()
    {
        return mVec._v[1];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type& Vec4Impl::Z()
    {
        return mVec._v[2];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type& Vec4Impl::W()
    {
        return mVec._v[3];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type Vec4Impl::X() const
    {
        return mVec._v[0];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type Vec4Impl::Y() const
    {
        return mVec._v[1];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type Vec4Impl::Z() const
    {
        return mVec._v[2];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type Vec4Impl::W() const
    {
        return mVec._v[3];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type& Vec4Impl::R()
    {
        return mVec._v[0];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type& Vec4Impl::G()
    {
        return mVec._v[1];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type& Vec4Impl::B()
    {
        return mVec._v[2];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type& Vec4Impl::A()
    {
        return mVec._v[3];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type Vec4Impl::R() const
    {
        return mVec._v[0];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type Vec4Impl::G() const
    {
        return mVec._v[1];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type Vec4Impl::B() const
    {
        return mVec._v[2];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type Vec4Impl::A() const
    {
        return mVec._v[3];
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec4Impl::Set(value_type x, value_type y, value_type z, value_type w)
    {
        mVec._v[0] = x; mVec._v[1] = y; mVec._v[2] = z; mVec._v[3] = w;
    }

    /**
    * Sets the initial values of the vector
    */
    void Vec4Impl::Set(const Vec4Impl& v)
    {
        mVec._v[0] = v[0]; mVec._v[1] = v[1]; mVec._v[2] = v[2]; mVec._v[3] = v[3];
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec4Impl::SetRGBA(value_type r, value_type g, value_type b, value_type a)
    {
        mVec._v[0] = r; mVec._v[1] = g; mVec._v[2] = b; mVec._v[3] = a;
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec4Impl::Lerp(const Vec4Impl& to, value_type alpha)
    {
        mVec._v[0] = trUtil::Math::Lerp<value_type>(mVec._v[0], to.X(), alpha);
        mVec._v[1] = trUtil::Math::Lerp<value_type>(mVec._v[1], to.Y(), alpha);
        mVec._v[2] = trUtil::Math::Lerp<value_type>(mVec._v[2], to.Z(), alpha);
        mVec._v[3] = trUtil::Math::Lerp<value_type>(mVec._v[3], to.W(), alpha);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl Vec4Impl::Lerp(const Vec4Impl& from, const Vec4Impl& to, value_type alpha)
    {
        return Vec4Impl(trUtil::Math::Lerp<value_type>(from.X(), to.X(), alpha), trUtil::Math::Lerp<value_type>(from.Y(), to.Y(), alpha), trUtil::Math::Lerp<value_type>(from.Z(), to.Z(), alpha), trUtil::Math::Lerp<value_type>(from.W(), to.W(), alpha));
    }

    //////////////////////////////////////////////////////////////////////////
    std::string Vec4Impl::ToString(int precision)
    {
        return std::string("<" + trUtil::StringUtils::ToString<value_type>(mVec._v[0], precision) + ", " + trUtil::StringUtils::ToString<value_type>(mVec._v[1], precision) + ", " + trUtil::StringUtils::ToString<value_type>(mVec._v[2], precision) + ", " + trUtil::StringUtils::ToString<value_type>(mVec._v[3], precision) + ">");
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type* Vec4Impl::Ptr()
    {
        return mVec.ptr();
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec4Impl::value_type* Vec4Impl::Ptr() const
    {
        return mVec.ptr();
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type& Vec4Impl::operator [] (int i)
    {
        return mVec[i];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type Vec4Impl::operator [] (int i) const
    {
        return mVec[i];
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec4Impl::operator = (const Vec4Impl& v)
    {
        mVec._v[0] = v[0]; mVec._v[1] = v[1]; mVec._v[2] = v[2]; mVec._v[3] = v[3];
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec4Impl::operator = (const osg::Vec4Impl& v)
    {
        mVec._v[0] = v[0]; mVec._v[1] = v[1]; mVec._v[2] = v[2]; mVec._v[3] = v[3];
    }

    //////////////////////////////////////////////////////////////////////////
    bool Vec4Impl::operator == (const Vec4Impl& v) const
    {
        return mVec._v[0] == v[0] && mVec._v[1] == v[1] && mVec._v[2] == v[2] && mVec._v[3] == v[3];
    }

    //////////////////////////////////////////////////////////////////////////
    bool Vec4Impl::operator != (const Vec4Impl& v) const
    {
        return mVec._v[0] != v[0] || mVec._v[1] != v[1] || mVec._v[2] != v[2] || mVec._v[3] != v[3];
    }

    //////////////////////////////////////////////////////////////////////////
    bool Vec4Impl::operator <  (const Vec4Impl& v) const
    {
        if (mVec._v[0]<v[0]) return true;
        else if (mVec._v[0]>v[0]) return false;
        else if (mVec._v[1]<v[1]) return true;
        else if (mVec._v[1]>v[1]) return false;
        else if (mVec._v[2]<v[2]) return true;
        else if (mVec._v[2]>v[2]) return false;
        else return (mVec._v[3]<v[3]);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Vec4Impl::operator >  (const Vec4Impl& v) const
    {
        if (mVec._v[0]>v[0]) return true;
        else if (mVec._v[0]<v[0]) return false;
        else if (mVec._v[1]>v[1]) return true;
        else if (mVec._v[1]<v[1]) return false;
        else if (mVec._v[2]>v[2]) return true;
        else if (mVec._v[2]<v[2]) return false;
        else return (mVec._v[3]>v[3]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::value_type Vec4Impl::operator * (const Vec4Impl& rhs) const
    {
        return mVec._v[0] * rhs[0] + mVec._v[1] * rhs[1] + mVec._v[2] * rhs[2] + mVec._v[3] * rhs[3];
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec4Impl Vec4Impl::operator * (Vec4Impl::value_type rhs) const
    {
        return Vec4Impl(mVec._v[0] * rhs, mVec._v[1] * rhs, mVec._v[2] * rhs, mVec._v[3] * rhs);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl& Vec4Impl::operator *= (Vec4Impl::value_type rhs)
    {
        mVec._v[0] *= rhs;
        mVec._v[1] *= rhs;
        mVec._v[2] *= rhs;
        mVec._v[3] *= rhs;
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec4Impl Vec4Impl::operator / (Vec4Impl::value_type rhs) const
    {
        return Vec4Impl(mVec._v[0] / rhs, mVec._v[1] / rhs, mVec._v[2] / rhs, mVec._v[3] / rhs);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl& Vec4Impl::operator /= (Vec4Impl::value_type rhs)
    {
        mVec._v[0] /= rhs;
        mVec._v[1] /= rhs;
        mVec._v[2] /= rhs;
        mVec._v[3] /= rhs;
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec4Impl Vec4Impl::operator + (const Vec4Impl& rhs) const
    {
        return Vec4Impl(mVec._v[0] + rhs[0], mVec._v[1] + rhs[1], mVec._v[2] + rhs[2], mVec._v[3] + rhs[3]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl& Vec4Impl::operator += (const Vec4Impl& rhs)
    {
        mVec._v[0] += rhs[0];
        mVec._v[1] += rhs[1];
        mVec._v[2] += rhs[2];
        mVec._v[3] += rhs[3];
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec4Impl Vec4Impl::operator - (const Vec4Impl& rhs) const
    {
        return Vec4Impl(mVec._v[0] - rhs[0], mVec._v[1] - rhs[1], mVec._v[2] - rhs[2], mVec._v[3] - rhs[3]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl& Vec4Impl::operator -= (const Vec4Impl& rhs)
    {
        mVec._v[0] -= rhs[0];
        mVec._v[1] -= rhs[1];
        mVec._v[2] -= rhs[2];
        mVec._v[3] -= rhs[3];
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec4Impl Vec4Impl::operator - () const
    {
        return Vec4Impl(-1 * mVec._v[0], -1 * mVec._v[1], -1 * mVec._v[2], -1 * mVec._v[3]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::operator osg::Vec4Impl () const
    {
        return mVec;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::operator osg::Vec4Impl& ()
    {
        return mVec;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::operator const osg::Vec4Impl& () const
    {
        return mVec;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl::operator osg::Vec4Impl* ()
    {
        return &mVec;
    }

    //////////////////////////////////////////////////////////////////////////
    std::ostream& operator << (std::ostream& ios, const Vec4Impl& vec)
    {
        ios << "<" << vec.X() << ", " << vec.Y() << ", " << vec.Z() << ", " << vec.Z() << ">";
        return ios;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl ComponentMultiply(const Vec4Impl& lhs, const Vec4Impl& rhs)
    {
        return Vec4Impl(lhs[0] * rhs[0], lhs[1] * rhs[1], lhs[2] * rhs[2], lhs[3] * rhs[3]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec4Impl ComponentDivide(const Vec4Impl& lhs, const Vec4Impl& rhs)
    {
        return Vec4Impl(lhs[0] / rhs[0], lhs[1] / rhs[1], lhs[2] / rhs[2], lhs[3] / rhs[3]);
    }
}