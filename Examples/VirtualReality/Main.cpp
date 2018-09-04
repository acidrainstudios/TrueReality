/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2018 Acid Rain Studios LLC
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
* @author Alexander Koufos
*/

#include <Examples/VirtualReality/Utils.h>
#include <Examples/VirtualReality/WinDefaultConfig.h>

#include <trUtil/DefaultSettings.h>
#include <trUtil/Exception.h>
#include <trUtil/PathUtils.h>
#include <trUtil/Console/Logo.h>
#include <trUtil/Console/TextColor.h>
#include <trUtil/Logging/Log.h>
#include <trVR/VrBase.h>

#include <osg/Geode>
#include <osg/Geometry>
#include <osg/GLExtensions>
#include <osg/State>
#include <osg/Texture2D>
#include <osgDB/ReadFile>
#include <osgGA/CameraManipulator>
#include <osgGA/TrackballManipulator>
#include <osgViewer/CompositeViewer>
#include <osgViewer/GraphicsWindow>
#include <osgViewer/ViewerEventHandlers>

#include <iostream>

#include "trUtil/FileUtils.h"

static const std::string LOG_FILE_NAME = "VRExample.html";

static const int WIN_WIDTH = 1400;
static const int WIN_HEIGHT = 1600;
static const int WIN_POS_X = 200;
static const int WIN_POS_Y = 200;

static const double CAM_NEAR_CLIP = 0.1;
static const double CAM_FAR_CLIP = 10000.0;
static const double CAM_FOV = 25;

static const int SAMPLE_NUM = 4;

//////////////////////////////////////////////////////////////////////////
osg::Texture2D* GenerateTexture(int screenWidth, int screenHeight, GLenum pxlFormat)
{
    osg::Texture2D* textureTargetPtr = new osg::Texture2D();
    textureTargetPtr->setResizeNonPowerOfTwoHint(false);
    textureTargetPtr->setTextureSize(screenWidth, screenHeight);
    textureTargetPtr->setInternalFormat(pxlFormat);
    textureTargetPtr->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
//    textureTargetPtr->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);

//    trBase::SmrtPtr<osg::Image> image = new osg::Image();
//    image->allocateImage(WIN_WIDTH, WIN_HEIGHT, 1, GL_RGBA, GL_UNSIGNED_BYTE);
    trBase::SmrtPtr<osg::Image> image = osgDB::readImageFile(trUtil::PathUtils::GetTexturesPath() + "/Grid/Grid.jpg");
//    image->setPixelFormat(GL_RGBA);
//    image->setDataType(GL_UNSIGNED_BYTE);
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
GLuint FboTest(const osg::State& state, int width, int height)
{
//    const osg::GLExtensions* fbo_ext = state.get<osg::GLExtensions>();
//    GLuint testFbo;
//    GLuint testTex;
//    
//    fbo_ext->glGenFramebuffers(1, &testFbo);
    
//    glGenTextures(1, &testTex);
//    glBindTexture(GL_TEXTURE_2D, testTex);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    
//    return testTex;
}

/**
* Software's main function. 
*/
int main(int argc, char** argv)
{
    //Set default logging level
    trUtil::DefaultSettings::SetupLoggingOptions(LOG_FILE_NAME, "Debug");
    
    //Parse command line arguments
    ParseCmdLineArgs(argc, argv);

    //Creates the default folders in the User Data folder. 
    trUtil::PathUtils::CreateUserDataPathTree();

    try
    {
        //Show Logo
        trUtil::Console::Logo();

        trBase::SmrtPtr<osg::Texture2D> textureTarget = GenerateTexture(WIN_WIDTH, WIN_HEIGHT, GL_RGBA8);
        trBase::SmrtPtr<osg::Geode> rootNode = GenerateRenderTarget(textureTarget);

        //Create our View
        trBase::SmrtPtr<osgViewer::View> mainView = new osgViewer::View();
        mainView->setSceneData(rootNode.Get());
        mainView->apply(new WinDefaultConfig(WIN_POS_X, WIN_POS_Y, WIN_WIDTH, WIN_HEIGHT, 0U, true, CAM_NEAR_CLIP, CAM_FAR_CLIP, CAM_FOV));

        //Adds the statistics handler. 
        mainView->addEventHandler(new osgViewer::StatsHandler);

        //Set up the viewer
        osgViewer::CompositeViewer viewer;
        viewer.addView(mainView);
        
        trBase::SmrtPtr<trVR::VrBase> vrInstance = new trVR::VrBase;
        
        vrInstance->Init();

        //Set up the main frame loop
        if ((mainView->getCameraManipulator() == 0) && mainView->getCamera()->getAllowEventFocus())
        {
            mainView->setCameraManipulator(new osgGA::TrackballManipulator());
        }
        viewer.setReleaseContextAtEndOfFrameHint(true);
        
        if (!viewer.isRealized())
        {
            viewer.realize();
        }

        //Run the main frame loop
        while (!viewer.done())        
        //while (vrInstance->IsSystemReady())
        //for (unsigned int i = 0; i < 1000; ++i)
        {
            vrInstance->GetHeadsetPose();
            viewer.frame();
            
            if (textureTarget->getTextureObject(0))
            {
                vrInstance->SubmitFrame(textureTarget, textureTarget);
            }
        }
        
        vrInstance->Shutdown();

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