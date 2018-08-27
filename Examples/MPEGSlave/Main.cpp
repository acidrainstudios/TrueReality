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
#include <osgViewer/Viewer>
#include <osgViewer/GraphicsWindow>
#include <osgDB/ReadFile>

#include <iostream>

static const trUtil::RefStr RING_TEXTURE = trUtil::RefStr(trUtil::PathUtils::GetTexturesPath() + "/RingArrayStill/RingArray.jpg");

//////////////////////////////////////////////////////////////////////////
osg::Texture2D* GenerateTexture(int screenWidth, int screenHeight, GLint pxlFormat)
{
    osg::Texture2D* textureTargetPtr = new osg::Texture2D();
    textureTargetPtr->setResizeNonPowerOfTwoHint(false);
    textureTargetPtr->setTextureSize(screenWidth, screenHeight);
    textureTargetPtr->setInternalFormat(pxlFormat);
    textureTargetPtr->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
    textureTargetPtr->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);

    trBase::SmrtPtr<osg::Image> image = osgDB::readImageFile(RING_TEXTURE);
    textureTargetPtr->setImage(image.Get());

    return textureTargetPtr;
}

//////////////////////////////////////////////////////////////////////////
osg::Geode* GenerateRenderTarget(osg::Texture2D* texture)
{
    int screenWidth = texture->getTextureWidth();
    int screenHeight = texture->getTextureHeight();

    trBase::SmrtPtr<osg::Vec3Array> verticies = new osg::Vec3Array();
    verticies->push_back(osg::Vec3(-screenWidth, 0.0, -screenHeight));
    verticies->push_back(osg::Vec3(-screenWidth, 0.0, screenHeight));
    verticies->push_back(osg::Vec3(screenWidth, 0.0, -screenHeight));
    verticies->push_back(osg::Vec3(screenWidth, 0.0, screenHeight));

    trBase::SmrtPtr<osg::Vec2Array> texCoords = new osg::Vec2Array();
    texCoords->push_back(osg::Vec2(0.0, 0.0));
    texCoords->push_back(osg::Vec2(0.0, 1.0));
    texCoords->push_back(osg::Vec2(1.0, 0.0));
    texCoords->push_back(osg::Vec2(1.0, 1.0));

    trBase::SmrtPtr<osg::Vec3Array> normals = new osg::Vec3Array();
    normals->push_back(osg::Vec3(0.0, -1.0, 0.0));

    trBase::SmrtPtr<osg::Geometry> quad = new osg::Geometry;
    quad->setVertexArray(verticies.Get());
    quad->setNormalArray(normals.Get());
    quad->setNormalBinding(osg::Geometry::BIND_OVERALL);
    quad->setTexCoordArray(0, texCoords.Get());
    quad->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::TRIANGLE_STRIP, 0, 4));

    trBase::SmrtPtr<osg::StateSet> stateset = new osg::StateSet;
    stateset->setTextureAttributeAndModes(0, texture, osg::StateAttribute::ON);
    quad->setStateSet(stateset);

    osg::Geode* texNodePtr = new osg::Geode();
    texNodePtr->addDrawable(quad.Get());

    return texNodePtr;
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
        trBase::SmrtPtr<osg::Geode> mRenderTraget = GenerateRenderTarget(mTextureTarget);

        osgViewer::Viewer viewer;
        viewer.setSceneData(mRenderTraget);
        //viewer.getWindows()
        viewer.run();

        //trMPEG::StreamSlave stream;
        //stream.Run();

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