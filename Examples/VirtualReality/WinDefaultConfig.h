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
#pragma once

#include <osgViewer/View>

/**
    * @class   WinDefaultConfig
    *
    * @brief   A window default configuration.
    */
class WinDefaultConfig : public osgViewer::ViewConfig
{
public:

    /**
        * @fn  WinDefaultConfig::WinDefaultConfig();
        *
        * @brief   Default constructor.
        */
    WinDefaultConfig();

    /**
        * @fn  WinDefaultConfig::WinDefaultConfig(int x, int y, int width, int height, unsigned int screenNum = 0, bool windowDecoration = true, double camNearClip = 1.0, double camFarClip = 1000.0, double camFOV = 110.0);
        *
        * @brief   Constructor.
        *
        * @param   x                   The x coordinate.
        * @param   y                   The y coordinate.
        * @param   width               The width.
        * @param   height              The height.
        * @param   screenNum           (Optional) The screen number.
        * @param   windowDecoration    (Optional) True to show window decoration.
        * @param   camNearClip         (Optional) The cameras near clipping plane.
        * @param   camFarClip          (Optional) The cameras far clipping plane.
        * @param   camFOV              (Optional) The cameras horizontal field of view.
        */
    WinDefaultConfig(int x, int y, int width, int height, unsigned int screenNum = 0, bool windowDecoration = true, 
        double camNearClip = 1.0, double camFarClip = 1000.0, double camFOV = 110.0,
        bool orthoCamera = false);

    /**
        * @fn  virtual void WinDefaultConfig::Configure(osgViewer::View& view) const;
        *
        * @brief   Configures the given view and window. This is called by the internal system 
        *          and needs to be overwritten to do the configurations. 
        *
        * @param [in,out]  view    The view.
        */
    virtual void Configure(osgViewer::View& view) const;

    ~WinDefaultConfig();

private:

    int mX = 0;
    int mY = 0;
    int mWidth = -1;
    int mHeight = -1;
    unsigned int mScreenNum = 0;
    bool mWindowDecoration = true;

    double mCamNearClip = 0.1;
    double mCamFarClip = 1000.0;
    double mCamFOV = 110.0;

    bool mOrthoCamera = false;

    /**
        * @fn  virtual void WinDefaultConfig::configure(osgViewer::View& view) const override;
        *
        * @brief   Configures the given view.
        *
        * @param [in,out]  view    The view.
        */
    virtual void configure(osgViewer::View& view) const override;
};