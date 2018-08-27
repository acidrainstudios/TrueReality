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

#include "Utils.h"

#include <trBase/SmrtPtr.h>
#include <trMPEG/StreamSlave.h>
#include <trUtil/Console/Logo.h>
#include <trUtil/Console/TextColor.h>
#include <trUtil/DefaultSettings.h>
#include <trUtil/Exception.h>
#include <trUtil/Logging/Log.h>
#include <trUtil/PathUtils.h>

#include <osg/Image>
#include <osg/ImageStream>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Texture2D>

#include <iostream>

//////////////////////////////////////////////////////////////////////////
osg::Texture2D* GenerateTexture(int screenWidth, int screenHeight, GLint pxlFormat)
{
    osg::Texture2D* textureTargetPtr = new osg::Texture2D();
    textureTargetPtr->setResizeNonPowerOfTwoHint(false);
    textureTargetPtr->setTextureSize(screenWidth, screenHeight);
    textureTargetPtr->setInternalFormat(pxlFormat);
    textureTargetPtr->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
    textureTargetPtr->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
    return textureTargetPtr;
}

//////////////////////////////////////////////////////////////////////////
/**
 * @fn  int main(int argc, char** argv)
 *
 * @brief   Main entry-point for this application.
 *
 * @param   argc    The number of command-line arguments provided.
 * @param   argv    An array of command-line argument strings.
 *
 * @return  Exit-code for the process - 0 for success, else an error code.
 */
int main(int argc, char** argv)
{
    //Set our logging levels
    trUtil::Logging::Log::GetInstance().SetAllOutputStreamBits(trUtil::Logging::Log::STANDARD);
    trUtil::Logging::Log::GetInstance().SetAllLogLevels(trUtil::Logging::LogLevel::LOG_DEBUG);

    //Check for command line options.
    std::string logFileName = "";
    std::string logLevel = "";
    //ParseCmdLineArgs(argc, argv, mpegType, fileName, ip, logFileName, logLevel);

    //Creates the default folders in the User Data folder. 
    trUtil::PathUtils::CreateUserDataPathTree();

    //Setup our Logging options
    //trUtil::DefaultSettings::SetupLoggingOptions(logFileName, logLevel);

    try
    {
        //Show Logo
        trUtil::Console::Logo();

        trBase::SmrtPtr<osg::Texture2D> mTextureTarget = GenerateTexture(800, 600, GL_RGB);

        trBase::SmrtPtr<osg::Image> image = new osg::Image();
        trBase::SmrtPtr<osg::Texture2D> texture = new osg::Texture2D();
        texture->setImage(image.Get());
        trBase::SmrtPtr<osg::Drawable> quad = osg::createTexturedQuadGeometry(osg::Vec3(), osg::Vec3(1.0f, 0.0f, 0.0), osg::Vec3(0.0f, 0.0f, 1.0f));


        trMPEG::StreamSlave stream;
        stream.Run();

        //Ending program
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::BRIGHT_RED);
        std::cerr << "\nTrue Reality is now shutting down ... " << std::endl;
        trUtil::Console::TextColor(trUtil::Console::TXT_COLOR::DEFAULT);
        LOG_A("True Reality is now shutting down ... ");
    }
    catch (const trUtil::Exception& ex)
    {
        LOG_E(EXE_NAME + " caught an unhandled exception:\n" + ex.ToString());
        ex.LogException(trUtil::Logging::LogLevel::LOG_ERROR);
        return -1;
    }
    return 0;
}