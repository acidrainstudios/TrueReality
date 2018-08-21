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

#include "WinDefaultConfig.h"

#include <trBase/SmrtPtr.h>

#include <osg/GraphicsContext>
#include <osgViewer/Keystone>

#include <iostream>

//////////////////////////////////////////////////////////////////////////
WinDefaultConfig::WinDefaultConfig()
{}

//////////////////////////////////////////////////////////////////////////
WinDefaultConfig::WinDefaultConfig(int x, int y, int width, int height, unsigned int screenNum, bool windowDecoration,
    double camNearClip, double camFarClip, double camFOV, bool orthoCamera)
{
    mX = x;
    mY = y;
    mWidth = width;
    mHeight = height;
    mScreenNum = screenNum;
    mWindowDecoration = windowDecoration;
    mCamNearClip = camNearClip;
    mCamFarClip = camFarClip;
    mCamFOV = camFOV;
    mOrthoCamera = orthoCamera;
}

//////////////////////////////////////////////////////////////////////////
void WinDefaultConfig::Configure(osgViewer::View& view) const
{
    //Grab the windowing interface instance. 
    osg::GraphicsContext::WindowingSystemInterface* wsi = osg::GraphicsContext::getWindowingSystemInterface();
    if (!wsi)
    {
        OSG_NOTICE << "WinDefaultConfig::Configure() : Error, no WindowSystemInterface available, cannot create windows." << std::endl;
        return;
    }

    osg::DisplaySettings* ds = getActiveDisplaySetting(view);

    //Create and configure display traits. 
    trBase::SmrtPtr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits(ds);

    traits->readDISPLAY();
    if (traits->displayNum<0) traits->displayNum = 0;

    traits->screenNum = mScreenNum;
    traits->x = mX;
    traits->y = mY;
    traits->width = mWidth;
    traits->height = mHeight;
    traits->windowDecoration = mWindowDecoration;
    traits->overrideRedirect = false;
    traits->doubleBuffer = true;
    traits->sharedContext = 0;
    traits->samples = 8;
    traits->vsync = false;

    if (traits->width <= 0 || traits->height <= 0)
    {
        osg::GraphicsContext::ScreenIdentifier si;
        si.readDISPLAY();

        // displayNum has not been set so reset it to 0.
        if (si.displayNum<0) si.displayNum = 0;

        si.screenNum = mScreenNum;

        unsigned int width, height;
        wsi->getScreenResolution(si, width, height);
        if (traits->width <= 0) traits->width = width;
        if (traits->height <= 0) traits->height = height;
    }

    //Create a graphics context. 
    trBase::SmrtPtr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits.Get());
    view.getCamera()->setGraphicsContext(gc.Get());

    //Create a graphics window
    osgViewer::GraphicsWindow* gw = dynamic_cast<osgViewer::GraphicsWindow*>(gc.Get());
    if (gw)
    {
        OSG_INFO << "View::setUpViewOnSingleScreen - GraphicsWindow has been created successfully." << std::endl;
        gw->getEventQueue()->getCurrentEventState()->setWindowRectangle(traits->x, traits->y, traits->width, traits->height);
    }
    else
    {
        OSG_NOTICE << "  GraphicsWindow has not been created successfully." << std::endl;
        return;
    }

    //Setup Perspective
    if (mOrthoCamera)
    {
        view.getCamera()->setProjectionMatrix(osg::Matrix::ortho2D(static_cast<double>(-traits->width), static_cast<double>(traits->width), static_cast<double>(-traits->height), static_cast<double>(traits->height)));
    }
    else
    {
        view.getCamera()->setProjectionMatrixAsPerspective(mCamFOV, static_cast<double>(traits->width) / static_cast<double>(traits->height), mCamNearClip, mCamFarClip);
    }
    view.getCamera()->setViewport(new osg::Viewport(0, 0, traits->width, traits->height));

    //Setup double buffering
    GLenum buffer = traits->doubleBuffer ? GL_BACK : GL_FRONT;
    view.getCamera()->setDrawBuffer(buffer);
    view.getCamera()->setReadBuffer(buffer);

    //Assign Stereo and KeyStone options. 
    if (ds->getKeystoneHint())
    {
        if (ds->getKeystoneHint() && !ds->getKeystoneFileNames().empty())
        {
            osgViewer::Keystone::loadKeystoneFiles(ds);
        }
        if (ds->getKeystones().empty()) ds->getKeystones().push_back(new osgViewer::Keystone);

        view.assignStereoOrKeystoneToCamera(view.getCamera(), ds);
    }
    else if (ds->getStereo() && ds->getUseSceneViewForStereoHint())
    {
        view.assignStereoOrKeystoneToCamera(view.getCamera(), ds);
    }

    //Setup the background clear color. 
    view.getCamera()->setClearColor(osg::Vec4(1.0, 0.0, 1.0, 1.0));
}

//////////////////////////////////////////////////////////////////////////
WinDefaultConfig::~WinDefaultConfig()
{
}

//////////////////////////////////////////////////////////////////////////
void WinDefaultConfig::configure(osgViewer::View& view) const
{
    Configure(view);
}