#include <dtOcean/oceanactor.h>

#include <osgOcean/OceanScene>
#include <osgOcean/FFTOceanSurface>
#include <dtOcean/oceanconfigactor.h>
#include <dtCore/scene.h>
#include <dtOcean/skydome.h>
#include <dtOcean/spheresegment.h>

#include <dtABC/application.h>
#include <dtDAL/enginepropertytypes.h>
#include <dtCore/deltawin.h>
#include <dtCore/environment.h>
#include <dtGame/gamemanager.h>
#include <dtGame/messagetype.h>
#include <dtGame/message.h>
#include <dtUtil/exception.h>
#include <osg/LightSource>
#include <osg/PositionAttitudeTransform>

using namespace dtOcean;


class CameraTrackDataType : public osg::Referenced
{
private:
    osg::Vec3f _eye;
    osg::PositionAttitudeTransform& _pat;

public:
    CameraTrackDataType(osg::PositionAttitudeTransform& pat)
       :_pat(pat)
    {}

    inline void setEye(const osg::Vec3f& eye) { _eye = eye; }

    inline void update(void)
    {
       _pat.setPosition(osg::Vec3f(_eye.x(), _eye.y(), _pat.getPosition().z()));
    }
};


class CameraTrackCallback : public osg::NodeCallback
{
public:
   virtual void operator()(osg::Node* node, osg::NodeVisitor* nv)
   {
      osg::ref_ptr<CameraTrackDataType> data = dynamic_cast<CameraTrackDataType*> (node->getUserData());

      if (nv->getVisitorType() == osg::NodeVisitor::CULL_VISITOR)
      {
         osgUtil::CullVisitor* cv = static_cast<osgUtil::CullVisitor*>(nv);
         osg::Vec3f eye, centre, up;
         cv->getCurrentCamera()->getViewMatrixAsLookAt(eye, centre, up);
         data->setEye(eye);
      }
      else if (nv->getVisitorType() == osg::NodeVisitor::UPDATE_VISITOR)
      {
         data->update();
      }

      traverse(node, nv);
   }
};


OceanActor::OceanActor(dtGame::GameActorProxy& proxy)
   : BaseClass(proxy)
   , mEnv(new dtCore::Environment("OceanEnvironment"))
   , mOceanSurface(NULL)
   , mOceanScene(NULL)
   , mLightSource(NULL)
   , mConfig(NULL)
   , mFog(NULL)
   , mOceanVisible(true)
{
    SetName("OceanActor");
    AddChild(mEnv);
}


OceanActor::~OceanActor()
{
}


void OceanActor::OnEnteredWorld()
{
   // get informed about enabled debug drawing
   GetGameActorProxy().RegisterForMessages(dtGame::MessageType::INFO_MAP_LOADED,
      dtGame::GameActorProxy::PROCESS_MSG_INVOKABLE);
}


void OceanActor::ProcessMessage(const dtGame::Message& msg)
{
   if (msg.GetMessageType() == dtGame::MessageType::INFO_MAP_LOADED)
   {
      OnMapLoaded();
   }
}


void OceanActor::OnMapLoaded()
{
   if (mConfig == NULL)
   {
      dtGame::GameManager* gm = GetGameActorProxy().GetGameManager();
      const dtDAL::ActorType* type = gm->FindActorType("dtOcean", "OceanConfigActor");
      dtDAL::ActorProxy* proxy = NULL;
      gm->FindActorByType(*type, proxy);

      OceanConfigActor* configActor = proxy
         ? static_cast<OceanConfigActor*>(proxy->GetActor())
         : new OceanConfigActor();

      SetConfig(configActor);

	  const dtDAL::ActorType* type2 = gm->FindActorType("dtOcean", "OceanConfigActor");
      dtDAL::ActorProxy* proxy2 = NULL;
      gm->FindActorByType(*type2, proxy2);
 
   }
}


void OceanActor::AddActor(dtCore::DeltaDrawable& dd)
{
   mEnv->AddChild(&dd);
}


void OceanActor::RemoveActor(dtCore::DeltaDrawable& dd)
{
   mEnv->RemoveChild(&dd);
}


void OceanActor::RemoveAllActors()
{
   while (mEnv->GetNumChildren() > 0)
   {
      mEnv->RemoveChild(mEnv->GetChild(0));
   }
}


void OceanActor::GetAllActors(std::vector<dtCore::DeltaDrawable*>& vec)
{
   vec.clear();

   for(unsigned int i = 0; i < mEnv->GetNumChildren(); i++)
      vec.push_back(mEnv->GetChild(i));
}


bool OceanActor::ContainsActor(dtCore::DeltaDrawable& dd) const
{
   return (mEnv->GetChildIndex(&dd) == mEnv->GetNumChildren());
}


unsigned int OceanActor::GetNumEnvironmentChildren() const
{
   return mEnv->GetNumChildren();
}


void OceanActor::SetConfig(OceanConfigActor* config)
{
   mConfig = config;
   
   if (&GetGameActorProxy() != NULL)
   {
      Build();
   }
}

void OceanActor::Build()
{
   if (mLightSource != NULL)
   {
      GetOSGNode()->asGroup()->removeChild(mLightSource);
   }
   if (mOceanScene != NULL)
   {
      GetOSGNode()->asGroup()->removeChild(mOceanScene.get());
   }

   mOceanSurface = new osgOcean::FFTOceanSurface(
      mConfig->GetFFTGridSize(),
      mConfig->GetResolution(),
      mConfig->GetNumTiles() ,
      mConfig->GetWindDirection(),
      mConfig->GetWindSpeed(),
      mConfig->GetDepth(),
      mConfig->GetReflectionDamping(),
      mConfig->GetWaveScale(),
      mConfig->GetIsChoppy(),
      mConfig->GetChoppyFactor(),
      mConfig->GetAnimLoopTime(),
      mConfig->GetNumFrames());


   osg::ref_ptr<osg::TextureCubeMap> cubeMap = new osg::TextureCubeMap;
   cubeMap->setInternalFormat(GL_RGBA);

   cubeMap->setFilter(osg::Texture::MIN_FILTER, osg::Texture::LINEAR_MIPMAP_LINEAR);
   cubeMap->setFilter(osg::Texture::MAG_FILTER, osg::Texture::LINEAR);
   cubeMap->setWrap  (osg::Texture::WRAP_S,     osg::Texture::CLAMP_TO_EDGE);
   cubeMap->setWrap  (osg::Texture::WRAP_T,     osg::Texture::CLAMP_TO_EDGE);

   cubeMap->setImage(osg::TextureCubeMap::NEGATIVE_X, osgDB::readImageFile(mConfig->GetSkyBoxLeft()));
   cubeMap->setImage(osg::TextureCubeMap::POSITIVE_X, osgDB::readImageFile(mConfig->GetSkyBoxRight()));
   cubeMap->setImage(osg::TextureCubeMap::NEGATIVE_Z, osgDB::readImageFile(mConfig->GetSkyBoxBack()));
   cubeMap->setImage(osg::TextureCubeMap::POSITIVE_Z, osgDB::readImageFile(mConfig->GetSkyBoxFront()));
   cubeMap->setImage(osg::TextureCubeMap::POSITIVE_Y, osgDB::readImageFile(mConfig->GetSkyBoxDown()));
   cubeMap->setImage(osg::TextureCubeMap::NEGATIVE_Y, osgDB::readImageFile(mConfig->GetSkyBoxUp()));
   mOceanSurface->setEnvironmentMap(cubeMap.get());

   mOceanSurface->setFoamBottomHeight(mConfig->GetFoamBottomHeight());
   mOceanSurface->setFoamTopHeight(mConfig->GetFoamTopHeight());
   mOceanSurface->enableCrestFoam(mConfig->GetEnableCrestFoam());
   mOceanSurface->setLightColor(mConfig->GetLightColor());
   mOceanSurface->enableEndlessOcean(mConfig->GetEnableEndlessOcean());

   mOceanScene = new osgOcean::OceanScene(mOceanSurface.get());
   mOceanScene->setUseDefaultSceneShader(mConfig->GetUseDefaultSceneShader());
   // set scene size to window size
   dtCore::Camera* cam =  GetGameActorProxy().GetGameManager()->GetApplication().GetCamera();
   dtCore::DeltaWin::PositionSize size = cam->GetWindow()->GetPosition();
   mOceanScene->setScreenDims(osg::Vec2s(size.mWidth, size.mHeight));

   mOceanScene->setLightID(0);
   mOceanScene->enableReflections(mConfig->GetEnableReflections());
   mOceanScene->enableRefractions(mConfig->GetEnableRefractions());

   mOceanScene->setAboveWaterFog(mConfig->GetAboveWaterFogHeight(), mConfig->GetAboveWaterFogColor());
   mOceanScene->setUnderwaterFog(mConfig->GetUnderWaterFogHeight(),  mConfig->GetUnderWaterFogColor());
   mOceanScene->setUnderwaterDiffuse(mConfig->GetUnderWaterDiffuseColor());
   mOceanScene->setUnderwaterAttenuation(mConfig->GetUnderWaterAttentuation());


   mOceanScene->setSunDirection(-mConfig->GetSunDirection());
   mOceanScene->enableGodRays(mConfig->GetEnableGodRays());
   mOceanScene->enableSilt(mConfig->GetEnableSilt());
   mOceanScene->enableUnderwaterDOF(mConfig->GetEnableUnderwaterDOF());
   mOceanScene->enableGlare(mConfig->GetEnableGlare());
   mOceanScene->setGlareAttenuation(mConfig->GetGlareAttentuation());

   mSkyDome = new SkyDome(
      mConfig->GetSkyBoxRadius(),
      mConfig->GetSkyBoxLongSteps(),
      mConfig->GetSkyBoxLatSteps(),
      cubeMap.get()
   );

   mSkyDome->setNodeMask(mOceanScene->getReflectedSceneMask() | mOceanScene->getNormalSceneMask());

   mOceanCylinder = new Cylinder(mConfig->GetSkyBoxRadius(), 999.8f, 16, false, true);
   mOceanCylinder->setColor(mConfig->GetUnderWaterFogColor());
   mOceanCylinder->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
   mOceanCylinder->getOrCreateStateSet()->setMode(GL_FOG, osg::StateAttribute::OFF);


   osg::Geode* oceanCylinderGeode = new osg::Geode;
   oceanCylinderGeode->addDrawable(mOceanCylinder.get());
   oceanCylinderGeode->setNodeMask(mOceanScene->getNormalSceneMask());

   osg::PositionAttitudeTransform* cylinderPat = new osg::PositionAttitudeTransform;
   cylinderPat->setPosition(osg::Vec3f(0.f, 0.f, -1000.f));
   cylinderPat->addChild(oceanCylinderGeode);

   // add a pat to track the camera
   mSkyTransform = new osg::PositionAttitudeTransform;
   mSkyTransform->setDataVariance(osg::Object::DYNAMIC);
   mSkyTransform->setPosition(osg::Vec3f(0.f, 0.f, 0.f));
   mSkyTransform->setUserData(new CameraTrackDataType(*mSkyTransform));
   mSkyTransform->setUpdateCallback(new CameraTrackCallback);
   mSkyTransform->setCullCallback(new CameraTrackCallback);

   mSkyTransform->addChild(mSkyDome.get());
   mSkyTransform->addChild(cylinderPat);

   mOceanScene->addChild(mSkyTransform);

   {
      // Create and add fake texture for use with nodes without any texture
      // since the OceanScene default scene shader assumes that texture unit
      // 0 is used as a base texture map.
      osg::Image* image = new osg::Image;
      image->allocateImage(1, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE);
      *(osg::Vec4ub*)image->data() = osg::Vec4ub(0xFF, 0xFF, 0xFF, 0xFF);

      osg::Texture2D* fakeTex = new osg::Texture2D(image);
      fakeTex->setWrap(osg::Texture2D::WRAP_S,osg::Texture2D::REPEAT);
      fakeTex->setWrap(osg::Texture2D::WRAP_T,osg::Texture2D::REPEAT);
      fakeTex->setFilter(osg::Texture2D::MIN_FILTER,osg::Texture2D::NEAREST);
      fakeTex->setFilter(osg::Texture2D::MAG_FILTER,osg::Texture2D::NEAREST);

      osg::StateSet* stateset = mOceanScene->getOrCreateStateSet();
      stateset->setTextureAttribute(0,fakeTex,osg::StateAttribute::ON);
      stateset->setTextureMode(0,GL_TEXTURE_1D,osg::StateAttribute::OFF);
      stateset->setTextureMode(0,GL_TEXTURE_2D,osg::StateAttribute::ON);
      stateset->setTextureMode(0,GL_TEXTURE_3D,osg::StateAttribute::OFF);
   }

   mLightSource = new osg::LightSource;
   mLightSource->setLocalStateSetModes();

   osg::Light* light = mLightSource->getLight();
   light->setLightNum(0);
   light->setAmbient(osg::Vec4d(0.3f, 0.3f, 0.3f, 1.0f));
   light->setDiffuse(mConfig->GetSunDiffuseColor());
   light->setSpecular(osg::Vec4d(0.1f, 0.1f, 0.1f, 1.0f));
   light->setPosition(osg::Vec4f(mConfig->GetSunDirection(), 1.f)); // point light

   mOceanScene->setOceanSurfaceHeight(mConfig->GetOceanHeight());

   GetOSGNode()->asGroup()->addChild(mLightSource);

   GetOSGNode()->asGroup()->addChild(mOceanScene.get());

   mOceanScene->addChild(mEnv->GetOSGNode());
}


float OceanActor::GetOceanHeight() const
{
   return mOceanScene->getOceanSurfaceHeight();
}


void OceanActor::SetOceanHeight(float v)
{
   return mOceanScene->setOceanSurfaceHeight(v);
}


osg::Vec3f OceanActor::GetSunDirection()
{
   return mOceanScene->getSunDirection();
}


void OceanActor::SetSunDirection(const osg::Vec3f& v)
{
   mOceanScene->setSunDirection(v);
   mLightSource->getLight()->setPosition(osg::Vec4f(v, 1.0f));
}

void OceanActor::SetSkyRotation(const osg::Quat& q)
{
   mSkyTransform->setAttitude(q);
}

osg::Quat OceanActor::GetSkyRotation() const
{
   return mSkyTransform->getAttitude();
}

osg::Vec2 OceanActor::GetWindDirection() const
{
   return mConfig->GetWindDirection();
}
void OceanActor::SetWindDirection(osg::Vec2& v)
{
   mConfig->SetWindDirection(v);
}
float OceanActor::GetWindSpeed() const
{
	return mConfig->GetWindSpeed();
}
void OceanActor::SetWindSpeed(float v)
{
	mConfig->SetWindSpeed(v);
}

osg::Group* OceanActor::GetNode() const
{
   return mEnv->GetDrawableNode();
}

void OceanActor::Show(bool showit)
{
   if (showit == mOceanVisible)
   {
      return;
   }

   mOceanVisible = showit;

   if (mOceanVisible)
   {
      GetOSGNode()->asGroup()->addChild(mOceanScene.get());
   }
   else
   {
      GetOSGNode()->asGroup()->removeChild(mOceanScene.get());
   }
}
// --------------------------------------------

OceanActorProxy::OceanActorProxy()
   : BaseClass()
{
   SetClassName("dtOcean::OceanActor");
}


OceanActorProxy::~OceanActorProxy()
{
}


void OceanActorProxy::CreateActor()
{
   OceanActor* actor = new OceanActor(*this);
   SetActor(*actor);
}


void OceanActorProxy::BuildPropertyMap()
{
   BaseClass::BuildPropertyMap();
   static const std::string GROUPNAME = "dtOcean";

   using namespace dtDAL;

   OceanActor* actor;
   GetActor(actor);
}

////////////////////////////////////////////////////////////////////////////////
float dtOcean::OceanActor::GetOceanSurfaceHeightAt(float x, float y, osg::Vec3* normal) const
{
   return mOceanScene->getOceanSurfaceHeightAt(x, y, normal);
}

////////////////////////////////////////////////////////////////////////////////
void dtOcean::OceanActor::SetWindowSize(const osg::Vec2s size)
{
   if (mOceanScene.valid())
   {
      mOceanScene->setScreenDims(size);
   }
}
