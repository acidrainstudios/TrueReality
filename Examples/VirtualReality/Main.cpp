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
#include <trBase/Vec4.h>
#include <trCore/SceneObjects/SkyBoxNode.h>
#include <trUtil/DefaultSettings.h>
#include <trUtil/Exception.h>
#include <trUtil/FileUtils.h>
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
#include <osgViewer/Renderer>
#include <osgViewer/ViewerEventHandlers>

#include <iostream>

static const std::string LOG_FILE_NAME = "VRExample.html";

static const int WIN_WIDTH = 1400;
static const int WIN_HEIGHT = 1600;
static const int WIN_POS_X = 200;
static const int WIN_POS_Y = 200;

static const double CAM_NEAR_CLIP = 0.1;
static const double CAM_FAR_CLIP = 10000.0;
static const double CAM_FOV = 25;

static const int SAMPLE_NUM = 4;

static const trUtil::RefStr SKY_BOX_MODEL = trUtil::RefStr(trUtil::PathUtils::GetStaticMeshesPath() + "/ConstructSkybox/ConstructSkybox.obj");
        
static GLuint mTestFbo = 0;
static GLuint mTestTex = 0;

//////////////////////////////////////////////////////////////////////////
osg::Texture2D* GenerateTexture(int renderWidth, int renderHeight, GLenum pxlFormat)
{
    osg::Texture2D* textureTargetPtr = new osg::Texture2D();
    textureTargetPtr->setResizeNonPowerOfTwoHint(false);
    textureTargetPtr->setTextureSize(renderWidth, renderHeight);
    textureTargetPtr->setInternalFormat(pxlFormat);
    textureTargetPtr->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
//    textureTargetPtr->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);

    trBase::SmrtPtr<osg::Image> image = new osg::Image();
    image->allocateImage(renderWidth, renderHeight, 1, GL_RGBA8, GL_UNSIGNED_BYTE);
//    trBase::SmrtPtr<osg::Image> image = osgDB::readImageFile(trUtil::PathUtils::GetTexturesPath() + "/Grid/Grid.jpg");
//    image->setPixelFormat(GL_RGBA);
//    image->setDataType(GL_UNSIGNED_BYTE);
    textureTargetPtr->setImage(image.Get());

    return textureTargetPtr;
}

//////////////////////////////////////////////////////////////////////////
osg::Geode* GenerateRenderTarget(osg::Texture2D* texture)
{
    int texWidth = texture->getTextureWidth();
    int texHeight = texture->getTextureHeight();

    trBase::SmrtPtr<osg::Vec3Array> verticies = new osg::Vec3Array();
    verticies->push_back(osg::Vec3(-texWidth, 0.0, -texHeight));
    verticies->push_back(osg::Vec3(-texWidth, 0.0, texHeight));
    verticies->push_back(osg::Vec3(texWidth, 0.0, -texHeight));
    verticies->push_back(osg::Vec3(texWidth, 0.0, texHeight));

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
bool CreateFBO(const osg::State& state, int width, int height)
{
    const osg::GLExtensions* fbo_ext = state.get<osg::GLExtensions>();
    
    if (fbo_ext)
    {
        fbo_ext->glGenFramebuffers(1, &mTestFbo);

        glGenTextures(1, &mTestTex);
        glBindTexture(GL_TEXTURE_2D, mTestTex);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);	// check FBO status

        GLenum status = fbo_ext->glCheckFramebufferStatus(GL_FRAMEBUFFER_EXT);
        if (status != GL_FRAMEBUFFER_COMPLETE_EXT)
        {
            LOG_W("Problem setting up frame buffer object.")
            return false;
        }
        
        return true;
    }
    
    return false;
}

//////////////////////////////////////////////////////////////////////////
class PreRenderDrawCallback : public osg::Camera::DrawCallback
{
public:
    explicit PreRenderDrawCallback(osg::Camera* camera)
        : mCamera(camera) {}
    virtual void operator()(osg::RenderInfo& info) const;
protected:
    osg::ref_ptr<osg::Camera> mCamera;
};

//////////////////////////////////////////////////////////////////////////
void PreRenderDrawCallback::operator()(osg::RenderInfo& info) const
{
    const osg::GLExtensions* fbo_ext = info.getState()->get<osg::GLExtensions>();
    
    if (fbo_ext)
    {
        fbo_ext->glBindFramebuffer(GL_FRAMEBUFFER_EXT, mTestFbo);
    }
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
        
        osg::ref_ptr<osg::State> state = gc->getState();
        CreateFBO(*state, mWidth, mHeight);
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
    mDevice->SubmitFrame(mTestTex, mTestTex);
    
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
enum class CameraType
{
    CAMERA_LEFT = 0,
    CAMERA_RIGHT = 1,
    MAX = 2
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
            viewOffset = mVrInstance->GetLeftViewMatrix();
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
osg::Camera* CreateRTTCamera(const int& eye, const int& width, const int& height, const osg::Vec4& clearColor, osg::GraphicsContext* gc)
{
    osg::ref_ptr<osg::Camera> camera = new osg::Camera();
    camera->setClearColor(clearColor);
    camera->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera->setRenderTargetImplementation(osg::Camera::FRAME_BUFFER_OBJECT);
    camera->setRenderOrder(osg::Camera::PRE_RENDER, eye);
    camera->setComputeNearFarMode(osg::CullSettings::DO_NOT_COMPUTE_NEAR_FAR);
    camera->setAllowEventFocus(false);
    camera->setReferenceFrame(osg::Transform::RELATIVE_RF);
    camera->setViewport(0, 0, width, height);
    camera->setGraphicsContext(gc);

    // Here we avoid doing anything regarding OSG camera RTT attachment.
    // Ideally we would use automatic methods within OSG for handling RTT but in this
    // case it seemed simpler to handle FBO creation and selection within this class.

    // This initial draw callback is used to disable normal OSG camera setup which 
    // would undo our RTT FBO configuration.
    camera->setInitialDrawCallback(new InitialDrawCallback());

    camera->setPreDrawCallback(new PreRenderDrawCallback(camera.get()));

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
	traits->x = 50;
	traits->y = 50;
	traits->width = 800;
	traits->height = 450;
	traits->doubleBuffer = true;
	traits->sharedContext = nullptr;
	traits->vsync = false; // VSync should always be disabled for because HMD submit handles the timing of the swap.

	return traits.release();
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

        trBase::SmrtPtr<trVR::VrBase> vrInstance = new trVR::VrBase;

        vrInstance->Init();

        uint32_t renderHeight, renderWidth;
        vrInstance->GetVrSystem()->GetRecommendedRenderTargetSize(&renderWidth, &renderHeight);

        trBase::SmrtPtr<osg::Texture2D> textureTarget = GenerateTexture(renderWidth, renderHeight, GL_RGBA8);
        trBase::SmrtPtr<osg::Geode> rootNode = GenerateRenderTarget(textureTarget);

        // Setup skybox
        trBase::SmrtPtr<trCore::SceneObjects::SkyBoxNode> skyBox = new trCore::SceneObjects::SkyBoxNode();

        if (!skyBox->LoadFile(SKY_BOX_MODEL))
        {
            LOG_E("Cannot load the skybox model. Something went wrong")
//            return 0;
        }

        rootNode->addChild(skyBox);

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
            gc->setClearColor(osg::Vec4(0.2f, 0.2f, 0.4f, 1.0f));
            gc->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
        
        // Setup the swap callback for handling the submission of frames
        osg::ref_ptr<SwapCallback> swapCallback = new SwapCallback(vrInstance);
        gc->setSwapCallback(swapCallback);

        // Create Trackball manipulator
        osg::ref_ptr<osgGA::CameraManipulator> cameraManipulator = new osgGA::TrackballManipulator;

        //Set up the viewer
        osgViewer::Viewer viewer;
        
        // Add scene data to view
        viewer.setSceneData(rootNode.Get());

        // Get main camera from view/viewer
        osg::ref_ptr<osg::Camera> camera = viewer.getCamera();
        camera->setName("Main camera");
        trBase::Vec4 clearColor = camera->getClearColor();

        // Disable automatic computation of near and far plane
        camera->setComputeNearFarMode(osg::CullSettings::DO_NOT_COMPUTE_NEAR_FAR);
        viewer.setCameraManipulator(cameraManipulator);

        // Force single threaded to make sure that no other thread can use the GL context
        viewer.setThreadingModel(osgViewer::Viewer::SingleThreaded);
        camera->setGraphicsContext(gc);
        camera->setViewport(0, 0, traits->width, traits->height);

        // Create RTT Camera and remove rendering of the main camera
        camera->setProjectionMatrix(vrInstance->GetCenterProjectionMatrix());
        osg::ref_ptr<osg::Camera> leftCamera = CreateRTTCamera(vr::Eye_Left, renderWidth, renderHeight, clearColor.GetOSGVector(), gc);
        leftCamera->setName("Left Eye Camera");
        viewer.addSlave(leftCamera.get(),
                        vrInstance->GetLeftProjectionMatrix(),
                        vrInstance->GetLeftViewMatrix(),
                        true);
        viewer.getSlave(0)._updateSlaveCallback
            = new UpdateSlaveCallback(CameraType::CAMERA_LEFT, vrInstance.Get(), swapCallback.get());
        osg::ref_ptr<osg::Camera> rightCamera = CreateRTTCamera(vr::Eye_Right, renderWidth, renderHeight, clearColor.GetOSGVector(), gc);
        leftCamera->setName("Right Eye Camera");
        viewer.addSlave(rightCamera.get(),
                        vrInstance->GetRightProjectionMatrix(),
                        vrInstance->GetRightViewMatrix(),
                        true);
        viewer.getSlave(1)._updateSlaveCallback
            = new UpdateSlaveCallback(CameraType::CAMERA_RIGHT, vrInstance.Get(), swapCallback.get());
        camera->setGraphicsContext(nullptr);

        viewer.setReleaseContextAtEndOfFrameHint(true);
        viewer.setLightingMode(osg::View::SKY_LIGHT);
        
        // Runs during the realize operations of OSG
        osg::ref_ptr<RealizeOperation> realizeOperatation = new RealizeOperation(renderWidth, renderHeight);
        viewer.setRealizeOperation(realizeOperatation.get());
        
        if (!viewer.isRealized())
        {
            viewer.realize();
        }

        //Run the main frame loop
        while (!viewer.done())
        {
            //vrInstance->GetHeadsetPose();
            viewer.frame();
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