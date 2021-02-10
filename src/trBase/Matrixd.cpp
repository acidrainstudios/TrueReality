/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2021 Acid Rain Studios LLC
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
#include <trBase/Matrixd.h>

#include <trBase/Matrixf.h>

#include <osg/Matrixd>

// Specialize MatrixImpl to be Matrixd
#define MatrixImpl Matrixd

namespace trBase
{
    //////////////////////////////////////////////////////////////////////////
    Matrixd::Matrixd(const osg::Matrixd& mat)
        : mMatrix(mat)
    {
    }

    //////////////////////////////////////////////////////////////////////////
    Matrixd::Matrixd(const osg::Matrixf& mat)
        : mMatrix(mat)
    {
    }

    //////////////////////////////////////////////////////////////////////////
    Matrixd::Matrixd(const Matrixf& mat)
        : mMatrix(mat)
    {
    }

    //////////////////////////////////////////////////////////////////////////
    Matrixd& Matrixd::operator = (const Matrixf& rhs)
    {
        Set(rhs.Ptr());
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    void Matrixd::Set(const Matrixf& rhs)
    {
        Set(rhs.Ptr());
    }

    //////////////////////////////////////////////////////////////////////////
    Matrixd::~Matrixd()
    {}

    //////////////////////////////////////////////////////////////////////////
    void Matrixd::MakeOrtho(float left, float right, float bottom, float top, float zNear, float zFar)
    {
        mMatrix.makeOrtho(left, right, bottom, top, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Matrixd::GetOrtho(float& left, float& right, float& bottom, float& top, float& zNear, float& zFar) const
    {
        return mMatrix.getOrtho(left, right, bottom, top, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    void Matrixd::MakeOrtho2D(float left, float right, float bottom, float top)
    {
        mMatrix.makeOrtho(left, right, bottom, top, -1.0, 1.0);
    }

    //////////////////////////////////////////////////////////////////////////
    void Matrixd::MakeFrustum(float left, float right, float bottom, float top, float zNear, float zFar)
    {
        mMatrix.makeFrustum(left, right, bottom, top, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Matrixd::GetFrustum(float& left, float& right, float& bottom, float& top, float& zNear, float& zFar) const
    {
        return mMatrix.getFrustum(left, right, bottom, top, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    void Matrixd::MakePerspective(float fovy, float aspectRatio, float zNear, float zFar)
    {
        mMatrix.makePerspective(fovy, aspectRatio, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Matrixd::GetPerspective(float& fovy, float& aspectRatio, float& zNear, float& zFar) const
    {
        return mMatrix.getPerspective(fovy, aspectRatio, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    Matrixd Matrixd::Ortho(float left, float right, float bottom, float top, float zNear, float zFar)
    {
        Matrixd m;
        m.MakeOrtho(left, right, bottom, top, zNear, zFar);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    Matrixd Matrixd::Ortho2D(float left, float right, float bottom, float top)
    {
        Matrixd m;
        m.MakeOrtho2D(left, right, bottom, top);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    Matrixd Matrixd::Frustum(float left, float right, float bottom, float top, float zNear, float zFar)
    {
        Matrixd m;
        m.MakeFrustum(left, right, bottom, top, zNear, zFar);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    Matrixd Matrixd::Perspective(float fovy, float aspectRatio, float zNear, float zFar)
    {
        Matrixd m;
        m.MakePerspective(fovy, aspectRatio, zNear, zFar);
        return m;
    }
}

// Now compile up Matrix via MatrixImpl
#include "MatrixImpl.cpp"