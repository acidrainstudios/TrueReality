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
#include <GL/glew.h>

#include <Examples/VirtualReality/Utils.h>
#include <Examples/VirtualReality/WinDefaultConfig.h>

#include <trBase/ObsrvrPtr.h>
#include <trBase/SmrtClass.h>
#include <trBase/SmrtPtr.h>
#include <trBase/Vec4.h>
#include <trCore/SceneObjects/RingArray.h>
#include <trCore/SceneObjects/RingArrayCallback.h>
#include <trCore/SceneObjects/SkyBoxNode.h>
#include <trUtil/DefaultSettings.h>
#include <trUtil/Exception.h>
#include <trUtil/FileUtils.h>
#include <trUtil/PathUtils.h>
#include <trUtil/Console/Logo.h>
#include <trUtil/Console/TextColor.h>
#include <trUtil/Logging/Log.h>
#include <trVR/VrBase.h>
#include <trVR/MirrorTexture.h>
#include <trVR/OpenVRTexture.h>

#include <osg/Camera>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/GLExtensions>
#include <osg/MatrixTransform>
#include <osg/Node>
#include <osg/PositionAttitudeTransform>
#include <osg/State>
#include <osg/Texture>
#include <osg/Texture2D>
#include <osg/Transform>
#include <osgDB/ReadFile>
#include <osgGA/CameraManipulator>
#include <osgGA/TrackballManipulator>
#include <osgViewer/CompositeViewer>
#include <osgViewer/GraphicsWindow>
#include <osgViewer/Renderer>
#include <osgViewer/ViewerEventHandlers>

#include <iostream>

//#define USE_SLAVES
//#define USE_GL

static const std::string LOG_FILE_NAME = "VRExample.html";

static const int WIN_WIDTH = 1758/3;
static const int WIN_HEIGHT = 1953/3;
static const int WIN_POS_X = 50;
static const int WIN_POS_Y = 50;

static const double CAM_NEAR_CLIP = 1.0e-2;
static const double CAM_FAR_CLIP = 1.0e6;

static const trUtil::RefStr COLOR_CUBE_MODEL = trUtil::RefStr(trUtil::PathUtils::GetStaticMeshesPath() + "/ColorCube/ColorCube.osg");
static const trUtil::RefStr SKY_BOX_MODEL = trUtil::RefStr(trUtil::PathUtils::GetStaticMeshesPath() + "/ConstructSkybox/ConstructSkybox.obj");
static const trUtil::RefStr SKY_SPHERE_MODEL = trUtil::RefStr(trUtil::PathUtils::GetStaticMeshesPath() + "/Milky Sphere/milky_sphere.obj");

static trBase::SmrtPtr<osg::Texture2D> mTestL;
static trBase::SmrtPtr<osg::Texture2D> mTestR;
static trBase::SmrtPtr<trVR::VrBase> mVrInstance;

#ifdef USE_GL
static trBase::SmrtPtr<trVR::OpenVRTexture> mLeftEye;
static trBase::SmrtPtr<trVR::OpenVRTexture> mRightEye;
static trBase::SmrtPtr<trVR::MirrorTexture> mMirrored;
#endif

//////////////////////////////////////////////////////////////////////////
enum class CameraType
{
    CAMERA_LEFT = 0,
    CAMERA_RIGHT = 1,
    MAX = 2
};

//////////////////////////////////////////////////////////////////////////
osg::Texture2D* GenerateTexture(int renderWidth, int renderHeight, GLenum pxlFormat)
{
    osg::Texture2D* textureTargetPtr = new osg::Texture2D();
    textureTargetPtr->setResizeNonPowerOfTwoHint(false);
    textureTargetPtr->setTextureSize(renderWidth, renderHeight);
    textureTargetPtr->setInternalFormat(pxlFormat);
    textureTargetPtr->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
    textureTargetPtr->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);

    trBase::SmrtPtr<osg::Image> image = osgDB::readImageFile(trUtil::PathUtils::GetStaticMeshesPath() + "/ColorCube/color.jpg");
    textureTargetPtr->setImage(image.Get());

    return textureTargetPtr;
}

//////////////////////////////////////////////////////////////////////////
osg::Geode* GenerateRenderTarget(osg::Texture2D* texture, const trBase::Vec3& offset)
{
    int texWidth = texture->getTextureWidth();
    int texHeight = texture->getTextureHeight();

    trBase::SmrtPtr<osg::Vec3Array> verticies = new osg::Vec3Array();
    verticies->push_back(osg::Vec3(-texWidth, 0.0, -texHeight) + offset.GetOSGVector());
    verticies->push_back(osg::Vec3(-texWidth, 0.0, texHeight) + offset.GetOSGVector());
    verticies->push_back(osg::Vec3(texWidth, 0.0, -texHeight) + offset.GetOSGVector());
    verticies->push_back(osg::Vec3(texWidth, 0.0, texHeight) + offset.GetOSGVector());

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
class PreRenderDrawCallback : public osg::Camera::DrawCallback
{
public:
    explicit PreRenderDrawCallback(osg::Camera* camera, trVR::OpenVRTexture* texture, const int& cameraType)
        : mCamera(camera)
        , mTexture(texture)
        , mCameraType(cameraType)
        {}
    explicit PreRenderDrawCallback(osg::Camera* camera, osg::Texture2D* texture, const int& cameraType)
        : mCamera(camera)
        , mOsgTexture(texture)
        , mCameraType(cameraType)
        {}
    virtual void operator()(osg::RenderInfo& info) const;
protected:
    osg::ref_ptr<osg::Camera> mCamera;
    trBase::SmrtPtr<trVR::OpenVRTexture> mTexture;
    trBase::SmrtPtr<osg::Texture2D> mOsgTexture;
    int mCameraType = vr::Eye_Left;
};

//////////////////////////////////////////////////////////////////////////
void PreRenderDrawCallback::operator()(osg::RenderInfo& info) const
{
#ifdef USE_GL
    mTexture->PreRenderUpdate(info);
#endif
    
#ifndef USE_SLAVES
    if (mCameraType == vr::Eye_Left)
    {
        mVrInstance->GetHeadsetPose();
    }
    
    trBase::Vec3 position = mVrInstance->GetPosition();
    trBase::Quat orientation = mVrInstance->GetOrientation();
    
    trBase::Matrix viewOffset;
    
    switch (mCameraType)
    {
        case vr::Eye_Left:
            viewOffset = mVrInstance->GetLeftViewMatrix();
            break;
        case vr::Eye_Right:
            viewOffset = mVrInstance->GetRightViewMatrix();
            break;
        default:
            LOG_W("Camera type is not set. This is a problem.")
            break;
    }
    
    viewOffset.PreMultRotate(orientation);
    viewOffset.SetTrans(viewOffset.GetTrans() + position);
    
    mCamera->setViewMatrix(viewOffset);
#endif
}

//////////////////////////////////////////////////////////////////////////
class PostRenderDrawCallback : public osg::Camera::DrawCallback
{
public:
    explicit PostRenderDrawCallback(osg::Camera* camera, trVR::OpenVRTexture* texture)
        : mCamera(camera)
        , mTexture(texture)
        {}
    virtual void operator()(osg::RenderInfo& info) const;
protected:
    osg::ref_ptr<osg::Camera> mCamera;
    trBase::SmrtPtr<trVR::OpenVRTexture> mTexture;
};

//////////////////////////////////////////////////////////////////////////
void PostRenderDrawCallback::operator()(osg::RenderInfo& info) const
{
#ifdef USE_GL
    mTexture->PostRenderUpdate(info);
#endif
}

//////////////////////////////////////////////////////////////////////////
class RealizeOperation : public osg::GraphicsOperation
{
public:
    explicit RealizeOperation(int width, int height)
        : osg::GraphicsOperation("RealizeOperation", false)
        , mHeight(height)
        , mWidth(width) 
        {}
    virtual void operator()(osg::GraphicsContext* gc);
    bool IsRealized() const { return mIsRealized; }
protected:
    OpenThreads::Mutex mMutex;
    bool mIsRealized = false;
    int mHeight = 1600;
    int mWidth = 1400;
};

//////////////////////////////////////////////////////////////////////////
void RealizeOperation::operator()(osg::GraphicsContext* gc)
{
    if (!mIsRealized)
    {
        OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
        gc->makeCurrent();
        
        if (osgViewer::GraphicsWindow* window = dynamic_cast<osgViewer::GraphicsWindow*>(gc))
        {
            // Forces the vsync off by running wglSwapIntervalEXT(0)
            window->setSyncToVBlank(false);
        }
        
#ifdef USE_GL
        osg::ref_ptr<osg::State> state = gc->getState();
        
        if (!state.valid())
        {
            LOG_E("The state is not valid. This should not happen.")
        }
        
//        CreateFBO(*state, mWidth, mHeight);
        mLeftEye = new trVR::OpenVRTexture(*state, mWidth, mHeight, "Left Eye Texture");
        mRightEye = new trVR::OpenVRTexture(*state, mWidth, mHeight, "Right Eye Texture");
        
        mMirrored = new trVR::MirrorTexture(state, 800, 450);
        mMirrored->SetEyeTextures(mLeftEye, mRightEye);
#endif
    }
    
    mIsRealized = true;
}

//////////////////////////////////////////////////////////////////////////
class SwapCallback : public osg::GraphicsContext::SwapCallback
{
public:
    explicit SwapCallback(trBase::SmrtPtr<trVR::VrBase> device)
        : mDevice(device)
        {}
    void swapBuffersImplementation(osg::GraphicsContext* gc) override;
    unsigned int GetFrameNumber() const { return mFrameNumber; }
private:
    trBase::ObsrvrPtr<trVR::VrBase> mDevice;
    unsigned int mFrameNumber = 0;
};

//////////////////////////////////////////////////////////////////////////
void SwapCallback::swapBuffersImplementation(osg::GraphicsContext* gc)
{
#ifdef USE_GL
    mDevice->SubmitFrame(mLeftEye, mRightEye);
#else
    mDevice->SubmitFrame(mTestL->getTextureObject(0)->id(), mTestR->getTextureObject(0)->id());
#endif
    
    gc->swapBuffersImplementation();
}

//////////////////////////////////////////////////////////////////////////
class InitialDrawCallback : public osg::Camera::DrawCallback
{
public:
    virtual void operator()(osg::RenderInfo& info) const
    {
        osg::GraphicsOperation* go = info.getCurrentCamera()->getRenderer();
        osgViewer::Renderer* renderer = dynamic_cast<osgViewer::Renderer*>(go);
        
        if (renderer != nullptr)
        {
            // Disable normal OSG FBO camera setup because it will undo the MSAA FBO configuration.
            renderer->setCameraRequiresSetUp(false);
        }
    }
};

//////////////////////////////////////////////////////////////////////////
class UpdateSlaveCallback : public osg::View::Slave::UpdateSlaveCallback
{
public:
    UpdateSlaveCallback(CameraType type, trVR::VrBase* vrInstance, SwapCallback* swapCallback)
    : mCameraType(type)
    , mVrInstance(vrInstance)
    , mSwapCallback(swapCallback)
    {}
    
    virtual void updateSlave(osg::View& view, osg::View::Slave& slave) override;
private:
    CameraType mCameraType = CameraType::MAX;
    trBase::SmrtPtr<trVR::VrBase> mVrInstance;
    osg::ref_ptr<SwapCallback> mSwapCallback;
};

//////////////////////////////////////////////////////////////////////////
void UpdateSlaveCallback::updateSlave(osg::View& view, osg::View::Slave& slave)
{
    if (mCameraType == CameraType::CAMERA_LEFT)
    {
        mVrInstance->GetHeadsetPose();
    }
    
    trBase::Vec3 position = mVrInstance->GetPosition();
    trBase::Quat orientation = mVrInstance->GetOrientation();
    
    trBase::Matrix viewOffset;
    
    switch (mCameraType)
    {
        case CameraType::CAMERA_LEFT:
            viewOffset = mVrInstance->GetLeftViewMatrix();
            break;
        case CameraType::CAMERA_RIGHT:
            viewOffset = mVrInstance->GetRightViewMatrix();
            break;
        default:
            LOG_W("Camera type is not set. This is a problem.")
            break;
    }
    
    viewOffset.PreMultRotate(orientation);
    viewOffset.SetTrans(viewOffset.GetTrans() + position);
    
    slave._viewOffset = viewOffset;
    
    slave.updateSlaveImplementation(view);
}

//////////////////////////////////////////////////////////////////////////
osg::Camera* CreateRTTCamera(const int& eye, trVR::OpenVRTexture* texture, const osg::Vec4& clearColor, osg::GraphicsContext* gc)
{
    osg::ref_ptr<osg::Camera> camera = new osg::Camera();
    camera->setClearColor(clearColor);
    camera->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera->setRenderTargetImplementation(osg::Camera::FRAME_BUFFER_OBJECT);
    camera->setRenderOrder(osg::Camera::PRE_RENDER, eye);
    camera->setComputeNearFarMode(osg::CullSettings::DO_NOT_COMPUTE_NEAR_FAR);
    camera->setAllowEventFocus(false);
    camera->setReferenceFrame(osg::Transform::RELATIVE_RF);
    camera->setViewport(0, 0, texture->GetWidth(), texture->GetHeight());
    camera->setGraphicsContext(gc);

    // Here we avoid doing anything regarding OSG camera RTT attachment.
    // Ideally we would use automatic methods within OSG for handling RTT but in this
    // case it seemed simpler to handle FBO creation and selection within this class.

    // This initial draw callback is used to disable normal OSG camera setup which 
    // would undo our RTT FBO configuration.
    camera->setInitialDrawCallback(new InitialDrawCallback());

    camera->setPreDrawCallback(new PreRenderDrawCallback(camera.get(), texture, eye));
    camera->setPostDrawCallback(new PostRenderDrawCallback(camera.get(), texture));

    return camera.release();
}

//////////////////////////////////////////////////////////////////////////
osg::Camera* CreateRTTCamera(const int& eye, osg::Texture2D* texture, const osg::Vec4& clearColor, osg::GraphicsContext* gc, osg::Node* scene)
{
    osg::ref_ptr<osg::Camera> camera = new osg::Camera();
    camera->setViewport(0, 0, texture->getTextureWidth(), texture->getTextureHeight());
    camera->setClearColor(clearColor);
    camera->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera->setRenderOrder(osg::Camera::PRE_RENDER, eye);
    camera->setRenderTargetImplementation(osg::Camera::FRAME_BUFFER_OBJECT);
    camera->attach(osg::Camera::COLOR_BUFFER, texture);
    camera->setReferenceFrame(osg::Transform::RELATIVE_RF);
    camera->setGraphicsContext(gc);
    camera->addChild(scene);
    camera->setComputeNearFarMode(osg::CullSettings::DO_NOT_COMPUTE_NEAR_FAR);
    camera->setAllowEventFocus(false);
    
#ifndef USE_SLAVES
    camera->setPreDrawCallback(new PreRenderDrawCallback(camera.get(), texture, eye));
    
    // Set the projection and view matrices of the camera
//    trBase::Matrix offsetMat = mVrInstance->CalculateProjectionMatrixOffset(eye);
//    camera->setProjectionMatrixAsPerspective(90.0, (double)texture->getTextureWidth()/texture->getTextureHeight(), mVrInstance->GetNearClippingPlane(), mVrInstance->GetFarClippingPlane());
    camera->setProjectionMatrix(mVrInstance->GetCenterProjectionMatrix());
//    camera->setProjectionMatrix(offsetMat);
    
    if (eye == vr::Eye_Left)
    {
        camera->setViewMatrix(mVrInstance->GetLeftViewMatrix());
    }
    else
    {
        camera->setViewMatrix(mVrInstance->GetRightViewMatrix());
    }
#endif
    
#ifdef _DEBUG
    trBase::Vec3 eyePos, center, up;
    camera->getViewMatrixAsLookAt(eyePos, center, up);
    std::cout << eyePos.ToString() << std::endl;
    std::cout << center.ToString() << std::endl;
    std::cout << up.ToString() << std::endl;std::cout << "[" << camera->getProjectionMatrix()(0, 0) << ", " << camera->getProjectionMatrix()(1, 0) << ", " << camera->getProjectionMatrix()(2, 0) << ", " << camera->getProjectionMatrix()(3, 0) << "]," << std::endl;
    std::cout << "[" << camera->getProjectionMatrix()(0, 1) << ", " << camera->getProjectionMatrix()(1, 1) << ", " << camera->getProjectionMatrix()(2, 1) << ", " << camera->getProjectionMatrix()(3, 1) << "]," << std::endl;
    std::cout << "[" << camera->getProjectionMatrix()(0, 2) << ", " << camera->getProjectionMatrix()(1, 2) << ", " << camera->getProjectionMatrix()(2, 2) << ", " << camera->getProjectionMatrix()(3, 2) << "]," << std::endl;
    std::cout << "[" << camera->getProjectionMatrix()(0, 3) << ", " << camera->getProjectionMatrix()(1, 3) << ", " << camera->getProjectionMatrix()(2, 3) << ", " << camera->getProjectionMatrix()(3, 3) << "]" << std::endl;
#endif

    return camera.release();
}

//////////////////////////////////////////////////////////////////////////
osg::GraphicsContext::Traits* CreateGraphicsContextTraits()
{
	osg::GraphicsContext::WindowingSystemInterface* wsi = osg::GraphicsContext::getWindowingSystemInterface();

	if (!wsi)
	{
            LOG_E("No WindowSystemInterface available, cannot create windows.")
            return 0;
	}

	// Get the screen identifiers set in environment variable DISPLAY
	osg::GraphicsContext::ScreenIdentifier si;
	si.readDISPLAY();

	// If displayNum has not been set, reset it to 0.
	if (si.displayNum < 0)
	{
            si.displayNum = 0;
            LOG_W("Couldn't get display number, setting to 0")
	}

	// If screenNum has not been set, reset it to 0.
	if (si.screenNum < 0)
	{
            si.screenNum = 0;
            LOG_W("Couldn't get screen number, setting to 0")
	}

	unsigned int width, height;
	wsi->getScreenResolution(si, width, height);

	osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
	traits->hostName = si.hostName;
	traits->screenNum = si.screenNum;
	traits->displayNum = si.displayNum;
	traits->windowDecoration = true;
	traits->x = WIN_POS_X;
	traits->y = WIN_POS_Y;
	traits->width = WIN_WIDTH;
	traits->height = WIN_HEIGHT;
	traits->doubleBuffer = true;
	traits->sharedContext = nullptr;
	traits->vsync = false; // VSync should always be disabled for because HMD submit handles the timing of the swap.

	return traits.release();
}

//////////////////////////////////////////////////////////////////////////
osg::LightSource* CreateLight(int lightNum, const trBase::Vec4& position)
{
    trBase::SmrtPtr<osg::Light> light = new osg::Light;
    light->setLightNum(lightNum);
    light->setDiffuse(osg::Vec4(1.0, 1.0, 1.0, 1.0));
    light->setPosition(position.GetOSGVector());
    light->setConstantAttenuation(0.00001);

    osg::LightSource* lightSource = new osg::LightSource;
    lightSource->setLight(light);

    return lightSource;
}

//////////////////////////////////////////////////////////////////////////
bool ConfigureViewer(osgViewer::Viewer& viewer, trBase::SmrtPtr<trVR::VrBase>& vrInstance, osg::Node* scene)
{
    bool isConfigured = false;
    
    // Get main camera from view/viewer
    osg::ref_ptr<osg::Camera> camera = viewer.getCamera();
    camera->setName("Main camera");
    
    // Get graphics context from viewer's camera
    osg::ref_ptr<osg::GraphicsContext> gc = camera->getGraphicsContext();
        
    // Setup the swap callback for handling the submission of frames
    osg::ref_ptr<SwapCallback> swapCallback = new SwapCallback(vrInstance);
    gc->setSwapCallback(swapCallback);
    
    // Disable automatic computation of near and far plane
    camera->setComputeNearFarMode(osg::CullSettings::DO_NOT_COMPUTE_NEAR_FAR);
    
    // Set main camera to center projection matrix
    camera->setProjectionMatrix(vrInstance->GetCenterProjectionMatrix());

#ifdef USE_SLAVES
    // Create left RTT Camera
    trBase::Vec4 clearColorL(0.4, 0.2, 0.2, 1.0);
    osg::ref_ptr<osg::Camera> leftCamera 
        = CreateRTTCamera(vr::Eye_Left, mTestL, clearColorL.GetOSGVector(), gc, scene);
    leftCamera->setName("Left Eye Camera");
    viewer.addSlave(leftCamera.get(),
                    vrInstance->CalculateProjectionMatrixOffset(vr::Eye_Left),
                    vrInstance->GetLeftViewMatrix(),
                    false);
    viewer.getSlave(0)._updateSlaveCallback
        = new UpdateSlaveCallback(CameraType::CAMERA_LEFT, vrInstance.Get(), swapCallback.get());
    #ifdef _DEBUG
    osg::Vec3 eye, center, up;
    osg::Camera* leftCam = viewer.getSlave(0)._camera;
    leftCam->getViewMatrixAsLookAt(eye, center, up);
    std::cout << "<" << eye.x() << ", " << eye.y() << ", " << eye.z() << ">" << std::endl;
    std::cout << "<" << center.x() << ", " << center.y() << ", " << center.z() << ">" << std::endl;
    std::cout << "<" << up.x() << ", " << up.y() << ", " << up.z() << ">" << std::endl;
    std::cout << "[" << leftCam->getProjectionMatrix()(0, 0) << ", " << leftCam->getProjectionMatrix()(1, 0) << ", " << leftCam->getProjectionMatrix()(2, 0) << ", " << leftCam->getProjectionMatrix()(3, 0) << "]," << std::endl;
    std::cout << "[" << leftCam->getProjectionMatrix()(0, 1) << ", " << leftCam->getProjectionMatrix()(1, 1) << ", " << leftCam->getProjectionMatrix()(2, 1) << ", " << leftCam->getProjectionMatrix()(3, 1) << "]," << std::endl;
    std::cout << "[" << leftCam->getProjectionMatrix()(0, 2) << ", " << leftCam->getProjectionMatrix()(1, 2) << ", " << leftCam->getProjectionMatrix()(2, 2) << ", " << leftCam->getProjectionMatrix()(3, 2) << "]," << std::endl;
    std::cout << "[" << leftCam->getProjectionMatrix()(0, 3) << ", " << leftCam->getProjectionMatrix()(1, 3) << ", " << leftCam->getProjectionMatrix()(2, 3) << ", " << leftCam->getProjectionMatrix()(3, 3) << "]" << std::endl;
    #endif

    // Create right RTT Camera
    trBase::Vec4 clearColorR(0.2, 0.4, 0.2, 1.0);
    osg::ref_ptr<osg::Camera> rightCamera
        = CreateRTTCamera(vr::Eye_Right, mTestR, clearColorR.GetOSGVector(), gc, scene);
    rightCamera->setName("Right Eye Camera");
    viewer.addSlave(rightCamera.get(),
                    vrInstance->CalculateProjectionMatrixOffset(vr::Eye_Right),
                    vrInstance->GetRightViewMatrix(),
                    false);
    viewer.getSlave(1)._updateSlaveCallback
        = new UpdateSlaveCallback(CameraType::CAMERA_RIGHT, vrInstance.Get(), swapCallback.get());
    #ifdef _DEBUG
    osg::Camera* rightCam = viewer.getSlave(0)._camera;
    rightCam->getViewMatrixAsLookAt(eye, center, up);
    std::cout << "<" << eye.x() << ", " << eye.y() << ", " << eye.z() << ">" << std::endl;
    std::cout << "<" << center.x() << ", " << center.y() << ", " << center.z() << ">" << std::endl;
    std::cout << "<" << up.x() << ", " << up.y() << ", " << up.z() << ">" << std::endl;
    std::cout << "[" << rightCam->getProjectionMatrix()(0, 0) << ", " << rightCam->getProjectionMatrix()(1, 0) << ", " << rightCam->getProjectionMatrix()(2, 0) << ", " << rightCam->getProjectionMatrix()(3, 0) << "]," << std::endl;
    std::cout << "[" << rightCam->getProjectionMatrix()(0, 1) << ", " << rightCam->getProjectionMatrix()(1, 1) << ", " << rightCam->getProjectionMatrix()(2, 1) << ", " << rightCam->getProjectionMatrix()(3, 1) << "]," << std::endl;
    std::cout << "[" << rightCam->getProjectionMatrix()(0, 2) << ", " << rightCam->getProjectionMatrix()(1, 2) << ", " << rightCam->getProjectionMatrix()(2, 2) << ", " << rightCam->getProjectionMatrix()(3, 2) << "]," << std::endl;
    std::cout << "[" << rightCam->getProjectionMatrix()(0, 3) << ", " << rightCam->getProjectionMatrix()(1, 3) << ", " << rightCam->getProjectionMatrix()(2, 3) << ", " << rightCam->getProjectionMatrix()(3, 3) << "]" << std::endl;
    #endif
#endif
    
    isConfigured = true;
    
    return isConfigured;
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

        mVrInstance = new trVR::VrBase;

        mVrInstance->Init(CAM_NEAR_CLIP, CAM_FAR_CLIP);
        mVrInstance->ResetHeadsetOrientation();

        uint32_t renderHeight, renderWidth;
        mVrInstance->GetVrSystem()->GetRecommendedRenderTargetSize(&renderWidth, &renderHeight);
        
        // Create nodes for the main scene and the headset scene.
        trBase::SmrtPtr<osg::Group> mainNode = new osg::Group();
        trBase::SmrtPtr<osg::Group> headsetNode = new osg::Group();

        // Generate the osg textures to be used for the cameras and create quads
        // to put the textures on. These quad will be added to the main scene.
        mTestL = GenerateTexture(renderWidth, renderHeight, GL_RGBA8);
        trBase::SmrtPtr<osg::Geode> textureNodeL = GenerateRenderTarget(mTestL, trBase::Vec3(-1800.0, 0.0, 0.0));
        mainNode->addChild(textureNodeL);
        
        mTestR = GenerateTexture(renderWidth, renderHeight, GL_RGBA8);
        trBase::SmrtPtr<osg::Geode> textureNodeR = GenerateRenderTarget(mTestR, trBase::Vec3(1800.0, 0.0, 0.0));
        mainNode->addChild(textureNodeR);
        
        // Create the ring array to be used in the headset scene
        trBase::SmrtPtr<trCore::SceneObjects::RingArray> ringArray = new trCore::SceneObjects::RingArray(80);
        trBase::SmrtPtr<trCore::SceneObjects::RingArrayCallback> ringCallback = new trCore::SceneObjects::RingArrayCallback();
        ringArray->setUpdateCallback(ringCallback);

        // Setup sky box
        trBase::SmrtPtr<trCore::SceneObjects::SkyBoxNode> skyBox = new trCore::SceneObjects::SkyBoxNode();

        if (!skyBox->LoadFile(SKY_BOX_MODEL))
        {
            LOG_E("Cannot load the skybox model. Something went wrong")
#ifndef _DEBUG
            return 0;
#endif
        }
        
        // Add sky box to the nodes
        headsetNode->addChild(skyBox);
        
        // Setup sky sphere
        trBase::SmrtPtr<trCore::SceneObjects::SkyBoxNode> skySphere = new trCore::SceneObjects::SkyBoxNode();
        
        if (!skySphere->LoadFile(SKY_SPHERE_MODEL))
        {
            LOG_E("Cannot load the skybox model. Something went wrong")
#ifndef _DEBUG
            return 0;
#endif
        }

        // Add sky sphere to the nodes
        mainNode->addChild(skySphere);

        // Get the suggested context traits
        osg::ref_ptr<osg::GraphicsContext::Traits> traits = CreateGraphicsContextTraits();
        traits->windowName = "True Reality - VR Example";

        // Create a graphic context based on our desired traits
        osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits);

        if (!gc)
        {
            LOG_E("GraphicsWindow has not been created successfully")
            return 1;
        }

        if (gc.valid())
        {
            gc->setClearColor(osg::Vec4(0.2f, 0.2f, 0.2f, 1.0f));
            gc->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
        
        osg::ref_ptr<osg::PositionAttitudeTransform> transformRing = new osg::PositionAttitudeTransform();
        transformRing->setPosition(osg::Vec3(0.0, 0.0, -1000.0));
        transformRing->addChild(ringArray);
        headsetNode->addChild(transformRing);
        
        osg::ref_ptr<osg::PositionAttitudeTransform> transformCube = new osg::PositionAttitudeTransform();
        transformCube->setPosition(osg::Vec3(0.0, 0.0, -0.000001));
        transformCube->setScale(osg::Vec3(5.0, 5.0, 5.0));
        transformCube->addChild(osgDB::readNodeFile(COLOR_CUBE_MODEL));
        headsetNode->addChild(transformCube);
        
        //Place a light in the texture scene
        trBase::SmrtPtr<osg::LightSource> light0 = CreateLight(0, trBase::Vec4(100.0, 0.0, 0.0, 1.0));
        headsetNode->addChild(light0);
        trBase::SmrtPtr<osg::LightSource> light1 = CreateLight(1, trBase::Vec4(-100.0, 0.0, 0.0, 1.0));
        headsetNode->addChild(light1);
      
#ifndef USE_SLAVES
        // Create main camera transform
        osg::ref_ptr<osg::PositionAttitudeTransform> headTrans = new osg::PositionAttitudeTransform();
        
        // Create vector to offset the cameras in the headset scene
        trBase::Vec3 offset(5000.0, 0.0, 0.0);
        
        // Create and setup left camera
        trBase::Vec4 clearColorL(0.4, 0.2, 0.2, 1.0);
        osg::Camera* testCamL = CreateRTTCamera(vr::Eye_Left, mTestL, clearColorL.GetOSGVector(), gc, headsetNode);
        osg::ref_ptr<osg::PositionAttitudeTransform> transformL = new osg::PositionAttitudeTransform();
        transformL->addChild(testCamL);
        offset = mVrInstance->CalculateProjectionOffset(vr::Eye_Left);
        transformL->setPosition(offset);
        headTrans->addChild(transformL);
        
        // Create and setup right camera
        trBase::Vec4 clearColorR(0.2, 0.4, 0.2, 1.0);
        osg::Camera* testCamR = CreateRTTCamera(vr::Eye_Right, mTestR, clearColorR.GetOSGVector(), gc, headsetNode);
        osg::ref_ptr<osg::PositionAttitudeTransform> transformR = new osg::PositionAttitudeTransform();
        transformR->addChild(testCamR);
        offset = mVrInstance->CalculateProjectionOffset(vr::Eye_Right);
        transformR->setPosition(offset);
        headTrans->addChild(transformR);
        
        mainNode->addChild(headTrans);
#endif

        // Create Trackball manipulator
        osg::ref_ptr<osgGA::CameraManipulator> cameraManipulator = new osgGA::TrackballManipulator;

        //Set up the viewer
        osgViewer::Viewer viewer;

        // Force single threaded to make sure that no other thread can use the GL context
        viewer.setThreadingModel(osgViewer::Viewer::SingleThreaded);
        viewer.getCamera()->setGraphicsContext(gc);
        viewer.getCamera()->setViewport(0, 0, traits->width, traits->height);
        
        // Add scene data to view
        viewer.setSceneData(mainNode.Get());
        
        // Add statistics handler
        viewer.addEventHandler(new osgViewer::StatsHandler);

        viewer.setCameraManipulator(cameraManipulator);
        viewer.setReleaseContextAtEndOfFrameHint(true);
        
        // Runs during the realize operations of OSG
        osg::ref_ptr<RealizeOperation> realizeOperatation = new RealizeOperation(renderWidth, renderHeight);
        viewer.setRealizeOperation(realizeOperatation.get());
        
        if (!viewer.isRealized())
        {
            viewer.realize();
        }
        
        // Finish the viewer's configuration after it has been realized
        if (!ConfigureViewer(viewer, mVrInstance, headsetNode))
        {
            return 0;
        }

        viewer.run();
        
        mVrInstance->Shutdown();

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