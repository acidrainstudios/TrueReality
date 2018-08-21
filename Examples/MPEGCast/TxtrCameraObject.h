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

#include <GL/glew.h> //Needs to be included before the export macros. 

#include <trBase/SmrtClass.h>
#include <trBase/SmrtPtr.h>
#include <trMPEG/EncodingCallback.h>
#include <trUtil/RefStr.h>
#include <trUtil/StringUtils.h>

#include <osg/Camera>
#include <osg/Geode>
#include <osg/Image>
#include <osg/Node>
#include <osg/Texture2D>

#include <string>

/**
    * @class   TxtrCameraObject
    *
    * @brief   A texture camera object that sets up a Render to Texture Camera, the Texture and a Render Geometry.
    */
class TxtrCameraObject : public trBase::SmrtClass
{
public:

    using BaseClass = trBase::SmrtClass;            /// Adds an easy and swappable access to the base class

    const static trUtil::RefStr CLASS_TYPE;         /// Holds the class type name for efficient comparisons

    static const int DEFAULT_SCREEN_WIDTH;
    static const int DEFAULT_SCREEN_HEIGHT;

    static const double DEFAULT_CAM_NEAR_CLIP;
    static const double DEFAULT_CAM_FAR_CLIP;
    static const double DEFAULT_CAM_FOV;

    static const int DEFAULT_SAMPLE_NUM;

    /**
     * @fn  TxtrCameraObject::TxtrCameraObject();
     *
     * @brief   Default constructor.
     */
    TxtrCameraObject();

    /**
     * @fn  TxtrCameraObject::TxtrCameraObject(int screenWidth = DEFAULT_SCREEN_WIDTH, int screenHeight = DEFAULT_SCREEN_HEIGHT);
     *
     * @brief   Constructor.
     *
     * @param   screenWidth     (Optional) Width of the screen.
     * @param   screenHeight    (Optional) Height of the screen.
     */
    TxtrCameraObject(int screenWidth = DEFAULT_SCREEN_WIDTH, int screenHeight = DEFAULT_SCREEN_HEIGHT);

    /**
     * @fn  TxtrCameraObject::TxtrCameraObject(osg::Node* scene, int screenWidth = DEFAULT_SCREEN_WIDTH, int screenHeight = DEFAULT_SCREEN_HEIGHT);
     *
     * @brief   Default constructor.
     *
     * @param [in,out]  scene           The scene.
     * @param           screenWidth     (Optional) Width of the screen.
     * @param           screenHeight    (Optional) Height of the screen.
     */
    TxtrCameraObject(osg::Node* scene, int screenWidth = DEFAULT_SCREEN_WIDTH, int screenHeight = DEFAULT_SCREEN_HEIGHT);

    /**
     * @fn  TxtrCameraObject::TxtrCameraObject(osg::Node* scene, int screenWidth = DEFAULT_SCREEN_WIDTH, int screenHeight = DEFAULT_SCREEN_HEIGHT, const std::string& mpegType = trUtil::StringUtils::STR_BLANK, const std::string& fileName = trUtil::StringUtils::STR_BLANK, const std::string& udpAddrs = trUtil::StringUtils::STR_BLANK);
     *
     * @brief   Constructor.
     *
     * @param [in,out]  scene           If non-null, the scene.
     * @param           screenWidth     (Optional) Width of the screen.
     * @param           screenHeight    (Optional) Height of the screen.
     * @param           mpegType        (Optional) Type of the MPEG.
     * @param           fileName        (Optional) Filename of the file.
     * @param           udpAddrs        (Optional) The UDP address.
     */
    TxtrCameraObject(osg::Node* scene, int screenWidth = DEFAULT_SCREEN_WIDTH, int screenHeight = DEFAULT_SCREEN_HEIGHT, const std::string& mpegType = trUtil::StringUtils::STR_BLANK, const std::string& fileName = trUtil::StringUtils::STR_BLANK, const std::string& udpAddrs = trUtil::StringUtils::STR_BLANK);

    /**
     * @fn  virtual const std::string& TxtrCameraObject::GetType();
     *
     * @brief   Returns the class type.
     *
     * @return  The type.
     */
    virtual const std::string& GetType() const override;

    /**
     * @fn  void TxtrCameraObject::SetScene(osg::Node* scene);
     *
     * @brief   Sets a scene for the camera.
     *
     * @param [in,out]  scene   The scene.
     */
    void SetScene(osg::Node* scene);

    /**
     * @fn  osg::Node* TxtrCameraObject::GetRenderTarget();
     *
     * @brief   Gets render target of the render to texture structure. This is the geometry with the
     *          rendered texture on it.
     *
     * @return  Null if it fails, else the render target.
     */
    osg::Node* GetRenderTarget();

    /**
     * @fn  osg::Texture2D* TxtrCameraObject::GetTextureTarget();
     *
     * @brief   Gets internal texture that the camera is rendering to.
     *
     * @return  Null if it fails, else the texture target.
     */
    osg::Texture2D* GetTextureTarget();

    /**
     * @fn  osg::Camera* TxtrCameraObject::GetCamera();
     *
     * @brief   Gets the render to texture camera.
     *
     * @return  Null if it fails, else the camera.
     */
    osg::Camera* GetCamera();


protected:

    /**
     * @fn  TxtrCameraObject::~TxtrCameraObject();
     *
     * @brief   Destructor.
     */
    ~TxtrCameraObject();

    /**
     * @fn  virtual osg::Texture2D* TxtrCameraObject::GenerateTexture(int screenWidth = DEFAULT_SCREEN_WIDTH, int screenHeight = DEFAULT_SCREEN_HEIGHT);
     *
     * @brief   Generates a texture target for rendering.
     *
     * @param   screenWidth     (Optional) Width of the screen.
     * @param   screenHeight    (Optional) Height of the screen.
     *
     * @return  Null if it fails, else the texture pointer. The pointer is unmanaged so the user
     *          needs to release it after he is done with it.
     */
    virtual osg::Texture2D* GenerateTexture(int screenWidth = DEFAULT_SCREEN_WIDTH, int screenHeight = DEFAULT_SCREEN_HEIGHT);

    /**
     * @fn  virtual osg::Geode* TxtrCameraObject::GenerateRenderTarget(osg::Texture2D* texture);
     *
     * @brief   Generates geometry for a render target.
     *
     * @param [in,out]  texture If non-null, the texture.
     *
     * @return  Null if it fails, else the render target pointer. The pointer is unmanaged so the
     *          user needs to release it after he is done with it.
     */
    virtual osg::Geode* GenerateRenderTarget(osg::Texture2D* texture);

    /**
     * @fn  virtual osg::Camera* TxtrCameraObject::GenerateCamera(osg::Node *scene, osg::Texture* texture, double screenWidth = DEFAULT_SCREEN_WIDTH, double screenHeight = DEFAULT_SCREEN_HEIGHT, int multisampleNum = DEFAULT_SAMPLE_NUM, double fov = DEFAULT_CAM_FOV, double nearClip = DEFAULT_CAM_NEAR_CLIP, double farClip = DEFAULT_CAM_FAR_CLIP);
     *
     * @brief   Generates a camera.
     *
     * @param [in,out]  scene           If non-null, the camera scene.
     * @param [in,out]  texture         If non-null, the image that will be used for rendering.
     * @param           screenWidth     (Optional) Width of the screen.
     * @param           screenHeight    (Optional) Height of the screen.
     * @param           multisampleNum  (Optional) The multisample number for AA.
     * @param           fov             (Optional) The fov.
     * @param           nearClip        (Optional) The cameras near clip.
     * @param           farClip         (Optional) The cameras far clip.
     *
     * @return  Null if it fails, else the camera  pointer. The pointer is unmanaged so the user
     *          needs to release it after he is done with it.
     */
    virtual osg::Camera* GenerateCamera(osg::Node *scene, osg::Texture* texture, double screenWidth = DEFAULT_SCREEN_WIDTH, double screenHeight = DEFAULT_SCREEN_HEIGHT, int multisampleNum = DEFAULT_SAMPLE_NUM, double fov = DEFAULT_CAM_FOV, double nearClip = DEFAULT_CAM_NEAR_CLIP, double farClip = DEFAULT_CAM_FAR_CLIP);

    /**
     * @fn  virtual void TxtrCameraObject::GenerateFullStructure(osg::Node *scene, double screenWidth = DEFAULT_SCREEN_WIDTH, double screenHeight = DEFAULT_SCREEN_HEIGHT, int multisampleNum = DEFAULT_SAMPLE_NUM, double fov = DEFAULT_CAM_FOV, double nearClip = DEFAULT_CAM_NEAR_CLIP, double farClip = DEFAULT_CAM_FAR_CLIP);
     *
     * @brief   Generates the full Render to texture structure.
     *
     * @param [in,out]  scene           If non-null, the scene.
     * @param           screenWidth     (Optional) Width of the screen.
     * @param           screenHeight    (Optional) Height of the screen.
     * @param           multisampleNum  (Optional) The multi-sample number.
     * @param           fov             (Optional) The fov.
     * @param           nearClip        (Optional) The near clip.
     * @param           farClip         (Optional) The far clip.
     */
    virtual void GenerateFullStructure(osg::Node *scene, double screenWidth = DEFAULT_SCREEN_WIDTH, double screenHeight = DEFAULT_SCREEN_HEIGHT, int multisampleNum = DEFAULT_SAMPLE_NUM, double fov = DEFAULT_CAM_FOV, double nearClip = DEFAULT_CAM_NEAR_CLIP, double farClip = DEFAULT_CAM_FAR_CLIP);

    /**
     * @fn  virtual trMPEG::EncodingCallback* TxtrCameraObject::CreateEncodingCallback(osg::Texture* texture, double screenWidth, double screenHeight);
     *
     * @brief   Creates and sets up a new MPEG Encoder Codec. WARNING This method returns a pointer
     *          which is does not clean up. The user must clean up the pointer themselves.
     *
     * @param [in,out]  texture         If non-null, the image.
     * @param           screenWidth     Width of the screen.
     * @param           screenHeight    Height of the screen.
     *
     * @return  Null if it fails, else the new encoding callback.
     */
    virtual trMPEG::EncodingCallback* CreateEncodingCallback(osg::Texture* texture, double screenWidth, double screenHeight);

private:

    trBase::SmrtPtr<osg::Node> mScene;
    trBase::SmrtPtr<osg::Camera> mTextureCam;
    trBase::SmrtPtr<osg::Texture2D> mTextureTarget;
    trBase::SmrtPtr<osg::Geode> mRenderTraget;

    trUtil::RefStr mMpegType;
    trUtil::RefStr mFileName;
    trUtil::RefStr mUDPAddrs;
};