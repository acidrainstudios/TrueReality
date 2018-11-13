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
    const int Vec2Impl::NUM_OF_COMPONENTS = 2;

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::Vec2Impl()
        : mVec()
    {
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::Vec2Impl(value_type x, value_type y)
        : mVec(x, y)
    {
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::Vec2Impl(const osg::Vec2Impl &v)
        : mVec(v.x(), v.y())
    {        
    }

    //////////////////////////////////////////////////////////////////////////
    const osg::Vec2Impl& Vec2Impl::GetOSGVector() const
    {
        return mVec;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::value_type Vec2Impl::Length() const
    {
        
        return sqrt(mVec._v[0] * mVec._v[0] + mVec._v[1] * mVec._v[1]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::value_type Vec2Impl::Length2() const
    {
        return (mVec._v[0] * mVec._v[0] + mVec._v[1] * mVec._v[1]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::value_type Vec2Impl::Normalize()
    {
        value_type norm = Vec2Impl::Length();
        if (norm>0.0)
        {
            value_type inv = 1.0 / norm;
            mVec._v[0] *= inv;
            mVec._v[1] *= inv;
        }
        return norm;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::value_type& Vec2Impl::X() 
    { 
        return mVec._v[0]; 
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::value_type& Vec2Impl::Y() 
    { 
        return mVec._v[1]; 
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::value_type Vec2Impl::X() const 
    { 
        return mVec._v[0]; 
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::value_type Vec2Impl::Y() const 
    { 
        return mVec._v[1]; 
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec2Impl::Set(value_type x, value_type y)
    { 
        mVec._v[0] = x; mVec._v[1] = y;
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec2Impl::Lerp(const Vec2Impl& to, value_type alpha)
    {
        mVec._v[0] = trUtil::Math::Lerp<value_type>(mVec._v[0], to.X(), alpha);
        mVec._v[1] = trUtil::Math::Lerp<value_type>(mVec._v[1], to.Y(), alpha);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl Vec2Impl::Lerp(const Vec2Impl& from, const Vec2Impl& to, value_type alpha)
    {
        return Vec2Impl(trUtil::Math::Lerp<value_type>(from.X(), to.X(), alpha), trUtil::Math::Lerp<value_type>(from.Y(), to.Y(), alpha));
    }

    //////////////////////////////////////////////////////////////////////////
    std::string Vec2Impl::ToString(int precision)
    {
        return std::string("<" + trUtil::StringUtils::ToString<value_type>(mVec._v[0], precision) + ", " + trUtil::StringUtils::ToString<value_type>(mVec._v[1], precision) + ">");
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::value_type* Vec2Impl::Ptr() 
    { 
        return mVec.ptr();
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec2Impl::value_type* Vec2Impl::Ptr() const 
    { 
        return mVec.ptr();
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::value_type& Vec2Impl::operator [] (int i) 
    { 
        return mVec[i];
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::value_type Vec2Impl::operator [] (int i) const 
    { 
        return mVec[i];
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec2Impl::operator = (const Vec2Impl& v)
    { 
        mVec._v[0] = v[0]; mVec._v[1] = v[1]; 
    }

    //////////////////////////////////////////////////////////////////////////
    void Vec2Impl::operator = (const osg::Vec2Impl& v)
    { 
        mVec._v[0] = v[0]; mVec._v[1] = v[1]; 
    }

    //////////////////////////////////////////////////////////////////////////
    bool Vec2Impl::operator == (const Vec2Impl& v) const
    { 
        return mVec._v[0] == v[0] && mVec._v[1] == v[1];
    }

    //////////////////////////////////////////////////////////////////////////
    bool Vec2Impl::operator != (const Vec2Impl& v) const
    { 
        return mVec._v[0] != v[0] || mVec._v[1] != v[1];
    }

    //////////////////////////////////////////////////////////////////////////
    bool Vec2Impl::operator <  (const Vec2Impl& v) const
    {
        if (mVec._v[0] < v[0]) return true;
        else if (mVec._v[0] > v[0]) return false;
        else return (mVec._v[1] < v[1]);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Vec2Impl::operator >  (const Vec2Impl& v) const
    {
        if (mVec._v[0] > v[0]) return true;
        else if (mVec._v[0] < v[0]) return false;
        else return (mVec._v[1] > v[1]);
    }
    
    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::value_type Vec2Impl::operator * (const Vec2Impl& rhs) const
    {
        return mVec._v[0] * rhs[0] + mVec._v[1] * rhs[1];
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec2Impl Vec2Impl::operator * (Vec2Impl::value_type rhs) const
    {
        return Vec2Impl(mVec._v[0] * rhs, mVec._v[1] * rhs);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl& Vec2Impl::operator *= (Vec2Impl::value_type rhs)
    {
        mVec._v[0] *= rhs;
        mVec._v[1] *= rhs;
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec2Impl Vec2Impl::operator / (Vec2Impl::value_type rhs) const
    {
        return Vec2Impl(mVec._v[0] / rhs, mVec._v[1] / rhs);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl& Vec2Impl::operator /= (Vec2Impl::value_type rhs)
    {
        mVec._v[0] /= rhs;
        mVec._v[1] /= rhs;
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec2Impl Vec2Impl::operator + (const Vec2Impl& rhs) const
    {
        return Vec2Impl(mVec._v[0] + rhs[0], mVec._v[1] + rhs[1]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl& Vec2Impl::operator += (const Vec2Impl& rhs)
    {
        mVec._v[0] += rhs[0];
        mVec._v[1] += rhs[1];
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec2Impl Vec2Impl::operator - (const Vec2Impl& rhs) const
    {
        return Vec2Impl(mVec._v[0] - rhs[0], mVec._v[1] - rhs[1]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl& Vec2Impl::operator -= (const Vec2Impl& rhs)
    {
        mVec._v[0] -= rhs[0];
        mVec._v[1] -= rhs[1];
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    const Vec2Impl Vec2Impl::operator - () const
    {
        return Vec2Impl(-1 * mVec._v[0], -1 * mVec._v[1]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::operator osg::Vec2Impl () const
    {
        return mVec;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::operator osg::Vec2Impl& ()
    {
        return mVec;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::operator const osg::Vec2Impl& () const
    {
        return mVec;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl::operator osg::Vec2Impl* ()
    {
        return &mVec;
    }
    
    //////////////////////////////////////////////////////////////////////////
    std::ostream& operator << (std::ostream& ios, const Vec2Impl& vec)
    {
        ios << "<" << vec.X() << ", " << vec.Y() << ">";
        return ios;
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl ComponentMultiply(const Vec2Impl& lhs, const Vec2Impl& rhs)
    {
        return Vec2Impl(lhs[0] * rhs[0], lhs[1] * rhs[1]);
    }

    //////////////////////////////////////////////////////////////////////////
    Vec2Impl ComponentDivide(const Vec2Impl& lhs, const Vec2Impl& rhs)
    {
        return Vec2Impl(lhs[0] / rhs[0], lhs[1] / rhs[1]);
    }
}