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
* @author Maxim Serebrennik
*/
#include <trBase/Matrixf.h>

#include <trBase/Matrixd.h>

#include <osg/Matrixf>

// Specialize MatrixImpl to be Matrixf
#define MatrixImpl Matrixf

namespace trBase
{
    //////////////////////////////////////////////////////////////////////////
    Matrixf::Matrixf(const Matrixd& mat)
    {
        mMatrix.set(mat.GetOSGMatrix().ptr());
    }

    //////////////////////////////////////////////////////////////////////////
    Matrixf& Matrixf::operator = (const Matrixd& rhs)
    {
        Set(rhs.Ptr());
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    void Matrixf::Set(const Matrixd& rhs)
    {
        Set(rhs.Ptr());
    }

    //////////////////////////////////////////////////////////////////////////
    Matrixf::~Matrixf()
    {}

    //////////////////////////////////////////////////////////////////////////
    void Matrixf::MakeOrtho(double left, double right, double bottom, double top, double zNear, double zFar)
    {
        mMatrix.makeOrtho(left, right, bottom, top, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Matrixf::GetOrtho(double& left, double& right, double& bottom, double& top, double& zNear, double& zFar) const
    {
        return mMatrix.getOrtho(left, right, bottom, top, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    void Matrixf::MakeOrtho2D(double left, double right, double bottom, double top)
    {
        mMatrix.makeOrtho(left, right, bottom, top, -1.0, 1.0);
    }

    //////////////////////////////////////////////////////////////////////////
    void Matrixf::MakeFrustum(double left, double right, double bottom, double top, double zNear, double zFar)
    {
        mMatrix.makeFrustum(left, right, bottom, top, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Matrixf::GetFrustum(double& left, double& right, double& bottom, double& top, double& zNear, double& zFar) const
    {
        return mMatrix.getFrustum(left, right, bottom, top, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    void Matrixf::MakePerspective(double fovy, double aspectRatio, double zNear, double zFar)
    {
        mMatrix.makePerspective(fovy, aspectRatio, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    bool Matrixf::GetPerspective(double& fovy, double& aspectRatio, double& zNear, double& zFar) const
    {
        return mMatrix.getPerspective(fovy, aspectRatio, zNear, zFar);
    }

    //////////////////////////////////////////////////////////////////////////
    Matrixf Matrixf::Ortho(double left, double right, double bottom, double top, double zNear, double zFar)
    {
        Matrixf m;
        m.MakeOrtho(left, right, bottom, top, zNear, zFar);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    Matrixf Matrixf::Ortho2D(double left, double right, double bottom, double top)
    {
        Matrixf m;
        m.MakeOrtho2D(left, right, bottom, top);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    Matrixf Matrixf::Frustum(double left, double right, double bottom, double top, double zNear, double zFar)
    {
        Matrixf m;
        m.MakeFrustum(left, right, bottom, top, zNear, zFar);
        return m;
    }

    //////////////////////////////////////////////////////////////////////////
    Matrixf Matrixf::Perspective(double fovy, double aspectRatio, double zNear, double zFar)
    {
        Matrixf m;
        m.MakePerspective(fovy, aspectRatio, zNear, zFar);
        return m;
    }
}

// Now compile up Matrix via MatrixImpl
#include "MatrixImpl.cpp"