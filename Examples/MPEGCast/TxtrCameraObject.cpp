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

#include "TxtrCameraObject.h"

#include <trMPEG/CodecH264.h>
#include <trMPEG/CodecH265.h>
#include <trMPEG/CodecMpeg2.h>
#include <trMPEG/CodecMpeg4.h>
#include <trMPEG/StreamServer.h>

#include <osg/Geometry>
#include <osgDB/WriteFile>

const trUtil::RefStr TxtrCameraObject::CLASS_TYPE("TxtrCameraObject");

const int TxtrCameraObject::DEFAULT_SCREEN_WIDTH = 1200;
const int TxtrCameraObject::DEFAULT_SCREEN_HEIGHT = 1024;

const double TxtrCameraObject::DEFAULT_CAM_NEAR_CLIP = 0.1;
const double TxtrCameraObject::DEFAULT_CAM_FAR_CLIP = 10000.0;
const double TxtrCameraObject::DEFAULT_CAM_FOV = 25;

const int TxtrCameraObject::DEFAULT_SAMPLE_NUM = 4;

//////////////////////////////////////////////////////////////////////////
TxtrCameraObject::TxtrCameraObject()
{
    trBase::SmrtPtr<osg::Node> scene;
    GenerateFullStructure(scene);
}

//////////////////////////////////////////////////////////////////////////
TxtrCameraObject::TxtrCameraObject(int screenWidth, int screenHeight)
{
    trBase::SmrtPtr<osg::Node> scene;
    GenerateFullStructure(scene, screenWidth, screenHeight);
}

//////////////////////////////////////////////////////////////////////////
TxtrCameraObject::TxtrCameraObject(osg::Node* scene, int screenWidth, int screenHeight)
{
    GenerateFullStructure(scene, screenWidth, screenHeight);
}

TxtrCameraObject::TxtrCameraObject(osg::Node* scene, int screenWidth, int screenHeight, const std::string& mpegType, const std::string& fileName, const std::string& udpAddrs)
{
    mMpegType = mpegType;
    mFileName = fileName;
    mUDPAddrs = udpAddrs;
    GenerateFullStructure(scene, screenWidth, screenHeight);
}

//////////////////////////////////////////////////////////////////////////
const std::string& TxtrCameraObject::GetType() const
{
    return CLASS_TYPE;
}

//////////////////////////////////////////////////////////////////////////
void TxtrCameraObject::SetScene(osg::Node* scene)
{
    mScene = scene;

    if (mTextureCam.Valid())
    {
        if (mTextureCam->getNumChildren() > 0)
        {
            mTextureCam->setChild(0, scene);
        }
        else
        {
            mTextureCam->addChild(scene);
        }            
    }
}

//////////////////////////////////////////////////////////////////////////
osg::Node* TxtrCameraObject::GetRenderTarget()
{
    return mRenderTraget;
}

//////////////////////////////////////////////////////////////////////////
osg::Texture2D* TxtrCameraObject::GetTextureTarget()
{
    return mTextureTarget;
}

//////////////////////////////////////////////////////////////////////////
osg::Camera* TxtrCameraObject::GetCamera()
{
    return mTextureCam;
}

//////////////////////////////////////////////////////////////////////////
TxtrCameraObject::~TxtrCameraObject()
{
}

//////////////////////////////////////////////////////////////////////////
osg::Texture2D* TxtrCameraObject::GenerateTexture(int screenWidth, int screenHeight)
{
    osg::Texture2D* textureTargetPtr = new osg::Texture2D();
    textureTargetPtr->setResizeNonPowerOfTwoHint(false);
    textureTargetPtr->setTextureSize(screenWidth, screenHeight);
    textureTargetPtr->setInternalFormat(GL_RGBA);
    textureTargetPtr->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
    textureTargetPtr->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
    return textureTargetPtr;
}

//////////////////////////////////////////////////////////////////////////
osg::Geode* TxtrCameraObject::GenerateRenderTarget(osg::Texture2D* texture)
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
osg::Camera* TxtrCameraObject::GenerateCamera(osg::Node *scene, osg::Texture* texture, double screenWidth, double screenHeight, int multisampleNum,  double fov, double nearClip, double farClip)
{
    //Create the render to texture camera
    osg::Camera* textureCamPtr = new osg::Camera();
    textureCamPtr->setViewport(0, 0, screenWidth, screenHeight);
    textureCamPtr->setClearColor(osg::Vec4(255.0/255.0, 186.0/255.0, 66.0/255.0, 1.0));                     //Set scene background color
    //textureCamPtr->setClearColor(osg::Vec4(1.0, 1.0, 1.0, 1.0));                                           //Set scene background color
    textureCamPtr->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                                 //Set what to clear on every frame
    textureCamPtr->setRenderOrder(osg::Camera::PRE_RENDER);                                                 //Set Camera render order
    textureCamPtr->setRenderTargetImplementation(osg::Camera::FRAME_BUFFER_OBJECT);                         //Enable FBO rendering
    textureCamPtr->attach(osg::Camera::COLOR_BUFFER, texture, 0U, 0U, true, multisampleNum, 0U);            //Attach the texture target
    textureCamPtr->setReferenceFrame(osg::Camera::ABSOLUTE_RF);                                             //Set the cameras transform to be absolute
    textureCamPtr->addChild(scene);                                                                         //Set the cameras scene
                                                                                          
    textureCamPtr->setProjectionMatrixAsPerspective(fov, (screenWidth/screenHeight), nearClip, farClip);    //Setup Camera FOVs and viewports
    textureCamPtr->setViewMatrixAsLookAt(osg::Vec3(0.0, scene->getBound().radius()*-4.0, 0.0), osg::Vec3(0.0f, 0.0f, 0.0f), osg::Vec3(0.0f, 0.0f, 1.0f));

    //Create the callback
    textureCamPtr->setPostDrawCallback(CreateEncodingCallback(texture, screenWidth, screenHeight));

    return textureCamPtr;
}

//////////////////////////////////////////////////////////////////////////
void TxtrCameraObject::GenerateFullStructure(osg::Node *scene, double screenWidth, double screenHeight, int multisampleNum, double fov, double nearClip, double farClip)
{
    mTextureTarget = GenerateTexture(screenWidth, screenHeight);
    mRenderTraget = GenerateRenderTarget(mTextureTarget);
    mTextureCam = GenerateCamera(scene, mTextureTarget, screenWidth, screenHeight, multisampleNum, fov, nearClip, farClip);
}

//////////////////////////////////////////////////////////////////////////
trMPEG::EncodingCallback* TxtrCameraObject::CreateEncodingCallback(osg::Texture* texture, double screenWidth, double screenHeight)
{
    trMPEG::EncodingCallback* callbackPtr = new trMPEG::EncodingCallback(texture);

    callbackPtr->SetResolution(screenWidth, screenHeight);
    callbackPtr->SetBitRate(8000000);
    callbackPtr->SetFileName(mFileName);
    //callbackPtr->SetFrameRate(50);
    if (mFileName == "UDP")
    {
        callbackPtr->SetBroadcast(true);
        callbackPtr->SetUDPAddress(mUDPAddrs);
    }
        
    if (mMpegType == "mpeg4")
    {
        callbackPtr->SetMpegType(new trMPEG::CodecMpeg4());
    }
    else if (mMpegType == "h264")
    {
        callbackPtr->SetMpegType(new trMPEG::CodecH264());
    }
    else if (mMpegType == "h265")
    {
        callbackPtr->SetMpegType(new trMPEG::CodecH265());
    }
    else
    {
        callbackPtr->SetMpegType(new trMPEG::CodecMpeg2);
    }
    callbackPtr->SetSilent(false);
    callbackPtr->Init();
    //callbackPtr->SetEnabled(false);

    return callbackPtr;
}