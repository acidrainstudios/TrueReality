#include <dtOcean/oceanconfigactor.h>

#include <dtDAL/enginepropertytypes.h>
#include <dtDAL/resourceactorproperty.h>
#include <dtUtil/exception.h>

using namespace dtOcean;

const std::string OceanConfigActor::CLASS_NAME("dtOcean::OceanConfigActor");

OceanConfigActor::OceanConfigActor()
   : BaseClass()
   , mFFTGridSize(64)
   , mResolution(256)
   , mNumTiles(17)
   , mWindDirection(osg::Vec2f(1.0f,1.0f))
   , mWindSpeed(12.f)
   , mDepth(10000)
   , mWaveScale((float)1e-8)
   , mIsChoppy(true)
   , mChoppyFactor(-2.5f)
   , mAnimLoopTime(10.0f)
   , mNumFrames(256)
   , mFoamBottomHeight(2.2f)
   , mFoamTopHeight(3.0f)
   , mEnableCrestFoam(true)
   , mLightColor(osg::Vec4(0.5f, 0.5f, 0.6f, 1))
   , mEnableEndlessOcean(true)
   , mEnableReflections(true)
   , mEnableRefractions(true)
   , mAboveWaterFogHeight(0.0012f)
   , mUnderWaterFogHeight(0.002f)
   , mAboveWaterFogColor(osg::Vec4(0.8f, 0.9f, 0.9f, 1))
   , mUnderWaterFogColor(osg::Vec4(0.1f, 0.2f, 0.4f, 1))
   , mUnderWaterDiffuseColor(osg::Vec4(0.1f, 0.3f, 0.4f, 1))
   , mUnderWaterAttentuation(osg::Vec3f(0.015f, 0.0075f, 0.005f))
   , mSunDirection(osg::Vec3(520.f, 1900.f, 550.f))
   , mEnableGodRays(true)
   , mEnableSilt(true)
   , mEnableUnderwaterDOF(true)
   , mEnableGlare(true)
   , mGlareAttentuation(0.8f)
   , mSkyBoxRadius(1900.f)
   , mSkyBoxLongSteps(16)
   , mSunDiffuseColor(osg::Vec4(0.7f, 0.7f, 0.7f, 1))
   , mSkyBoxLatSteps(16)
   , mUseDefaultSceneShader(true)
   , mReflectionDamping(0.35f)
   , mOceanHeight(0)
{
   SetName("OceanConfigActor");
}

// --------------------------------------------

OceanConfigActorProxy::OceanConfigActorProxy()
   : BaseClass()
{
   SetClassName("dtOcean::OceanConfigActor");
}


OceanConfigActorProxy::~OceanConfigActorProxy()
{
}


void OceanConfigActorProxy::CreateActor()
{
   SetActor(*new OceanConfigActor());
}


void OceanConfigActorProxy::BuildPropertyMap()
{
   //BaseClass::BuildPropertyMap();
   static const std::string GROUPNAME = "dtOcean";
   static const std::string GROUPNAME_SKY = "SkyBox";

   using namespace dtDAL;

   OceanConfigActor* actor;
   GetActor(actor);

   AddProperty(new dtDAL::DoubleActorProperty("Ocean Height", "Ocean Height",
      dtDAL::DoubleActorProperty::SetFuncType(actor, &OceanConfigActor::SetOceanHeight),
      dtDAL::DoubleActorProperty::GetFuncType(actor, &OceanConfigActor::GetOceanHeight),
      "Height of the ocean's surface",
      GROUPNAME));

   AddProperty(new dtDAL::BooleanActorProperty("Use Default Scene Shader", "Use Default Scene Shader",
      dtDAL::BooleanActorProperty::SetFuncType(actor, &OceanConfigActor::SetUseDefaultSceneShader),
      dtDAL::BooleanActorProperty::GetFuncType(actor, &OceanConfigActor::GetUseDefaultSceneShader),
      "",
      GROUPNAME));

   AddProperty(new dtDAL::BooleanActorProperty("Enable Crest Foam", "Enable Crest Foam",
      dtDAL::BooleanActorProperty::SetFuncType(actor, &OceanConfigActor::SetEnableCrestFoam),
      dtDAL::BooleanActorProperty::GetFuncType(actor, &OceanConfigActor::GetEnableCrestFoam),
      "Render foam on the crests",
      GROUPNAME));

   AddProperty(new dtDAL::BooleanActorProperty("Enable Endless Ocean", "Enable Endless Ocean",
      dtDAL::BooleanActorProperty::SetFuncType(actor, &OceanConfigActor::SetEnableEndlessOcean),
      dtDAL::BooleanActorProperty::GetFuncType(actor, &OceanConfigActor::GetEnableEndlessOcean),
      "",
      GROUPNAME));

   AddProperty(new dtDAL::BooleanActorProperty("Enable Reflections", "Enable Reflections",
      dtDAL::BooleanActorProperty::SetFuncType(actor, &OceanConfigActor::SetEnableReflections),
      dtDAL::BooleanActorProperty::GetFuncType(actor, &OceanConfigActor::GetEnableReflections),
      "",
      GROUPNAME));

    AddProperty(new dtDAL::FloatActorProperty("Reflection Damping", "Reflection Damping",
      dtDAL::FloatActorProperty::SetFuncType(actor, &OceanConfigActor::SetReflectionDamping),
      dtDAL::FloatActorProperty::GetFuncType(actor, &OceanConfigActor::GetReflectionDamping),
      "",
      GROUPNAME));

   AddProperty(new dtDAL::BooleanActorProperty("Enable Refractions", "Enable Refractions",
      dtDAL::BooleanActorProperty::SetFuncType(actor, &OceanConfigActor::SetEnableRefractions),
      dtDAL::BooleanActorProperty::GetFuncType(actor, &OceanConfigActor::GetEnableRefractions),
      "",
      GROUPNAME));

   AddProperty(new dtDAL::BooleanActorProperty("Enable God Rays", "Enable God Rays",
      dtDAL::BooleanActorProperty::SetFuncType(actor, &OceanConfigActor::SetEnableGodRays),
      dtDAL::BooleanActorProperty::GetFuncType(actor, &OceanConfigActor::GetEnableGodRays),
      "",
      GROUPNAME));

   AddProperty(new dtDAL::BooleanActorProperty("Enable Silt", "Enable Silt",
      dtDAL::BooleanActorProperty::SetFuncType(actor, &OceanConfigActor::SetEnableSilt),
      dtDAL::BooleanActorProperty::GetFuncType(actor, &OceanConfigActor::GetEnableSilt),
      "",
      GROUPNAME));

   AddProperty(new dtDAL::BooleanActorProperty("Enable Underwater DOF", "Enable Underwater DOF",
      dtDAL::BooleanActorProperty::SetFuncType(actor, &OceanConfigActor::SetEnableUnderwaterDOF),
      dtDAL::BooleanActorProperty::GetFuncType(actor, &OceanConfigActor::GetEnableUnderwaterDOF),
      "Enable underwater depth of field",
      GROUPNAME));

   AddProperty(new dtDAL::BooleanActorProperty("Enable Glare", "Enable Glare",
      dtDAL::BooleanActorProperty::SetFuncType(actor, &OceanConfigActor::SetEnableGlare),
      dtDAL::BooleanActorProperty::GetFuncType(actor, &OceanConfigActor::GetEnableGlare),
      "Enable cross hatch glare.",
      GROUPNAME));

   AddProperty(new dtDAL::IntActorProperty("FFT Grid Size", "FFT Grid Size",
      dtDAL::IntActorProperty::SetFuncType(actor, &OceanConfigActor::SetFFTGridSize),
      dtDAL::IntActorProperty::GetFuncType(actor, &OceanConfigActor::GetFFTGridSize),
      "",
      GROUPNAME));

   AddProperty(new dtDAL::IntActorProperty("Resolution", "Resolution",
      dtDAL::IntActorProperty::SetFuncType(actor, &OceanConfigActor::SetResolution),
      dtDAL::IntActorProperty::GetFuncType(actor, &OceanConfigActor::GetResolution),
      "",
      GROUPNAME));

   AddProperty(new dtDAL::IntActorProperty("Number of Tiles", "Number of Tiles",
      dtDAL::IntActorProperty::SetFuncType(actor, &OceanConfigActor::SetNumTiles),
      dtDAL::IntActorProperty::GetFuncType(actor, &OceanConfigActor::GetNumTiles),
      "",
      GROUPNAME));

   AddProperty(new dtDAL::Vec2ActorProperty("Wind Direction", "Wind Direction",
      dtDAL::Vec2ActorProperty::SetFuncType(actor, &OceanConfigActor::SetWindDirection),
      dtDAL::Vec2ActorProperty::GetFuncType(actor, &OceanConfigActor::GetWindDirection),
      "Change the wind's direction",
      GROUPNAME));

   AddProperty(new dtDAL::FloatActorProperty("Wind Speed", "Wind Speed",
      dtDAL::FloatActorProperty::SetFuncType(actor, &OceanConfigActor::SetWindSpeed),
      dtDAL::FloatActorProperty::GetFuncType(actor, &OceanConfigActor::GetWindSpeed),
      "Change the wind speed, makes bigger waves",
      GROUPNAME));

   AddProperty(new dtDAL::FloatActorProperty("Depth", "Depth",
      dtDAL::FloatActorProperty::SetFuncType(actor, &OceanConfigActor::SetDepth),
      dtDAL::FloatActorProperty::GetFuncType(actor, &OceanConfigActor::GetDepth),
      "",
      GROUPNAME));

   AddProperty(new dtDAL::FloatActorProperty("Wave Scale", "Wave Scale",
      dtDAL::FloatActorProperty::SetFuncType(actor, &OceanConfigActor::SetWaveScale),
      dtDAL::FloatActorProperty::GetFuncType(actor, &OceanConfigActor::GetWaveScale),
      "Wave scale factor (typically very small ~1e-8)",
      GROUPNAME));

   AddProperty(new dtDAL::BooleanActorProperty("Is Choppy", "Is Choppy",
      dtDAL::BooleanActorProperty::SetFuncType(actor, &OceanConfigActor::SetIsChoppy),
      dtDAL::BooleanActorProperty::GetFuncType(actor, &OceanConfigActor::GetIsChoppy),
      "Enable/Disable choppy wave geometry",
      GROUPNAME));

   AddProperty(new dtDAL::FloatActorProperty("Choppy Factor", "Choppy Factor",
      dtDAL::FloatActorProperty::SetFuncType(actor, &OceanConfigActor::SetChoppyFactor),
      dtDAL::FloatActorProperty::GetFuncType(actor, &OceanConfigActor::GetChoppyFactor),
      "Change the choppy wave factor",
      GROUPNAME));

   AddProperty(new dtDAL::FloatActorProperty("Anim Loop Time", "Anim Loop Time",
      dtDAL::FloatActorProperty::SetFuncType(actor, &OceanConfigActor::SetAnimLoopTime),
      dtDAL::FloatActorProperty::GetFuncType(actor, &OceanConfigActor::GetAnimLoopTime),
      "",
      GROUPNAME));

   AddProperty(new dtDAL::IntActorProperty("Number of Frames", "Number of Frames",
      dtDAL::IntActorProperty::SetFuncType(actor, &OceanConfigActor::SetNumFrames),
      dtDAL::IntActorProperty::GetFuncType(actor, &OceanConfigActor::GetNumFrames),
      "",
      GROUPNAME));

   AddProperty(new dtDAL::FloatActorProperty("SkyBox Radius", "SkyBox Radius",      
      dtDAL::FloatActorProperty::SetFuncType(actor, &OceanConfigActor::SetSkyBoxRadius),
      dtDAL::FloatActorProperty::GetFuncType(actor, &OceanConfigActor::GetSkyBoxRadius),
      "Sets the sky box radius",
      GROUPNAME_SKY));

   AddProperty(new dtDAL::ResourceActorProperty(*this, dtDAL::DataType::TEXTURE,
      "Skybox Up", "Skybox Up",
      dtDAL::ResourceActorProperty::SetFuncType(actor, &OceanConfigActor::SetSkyBoxUp),
      "Sets the sky box texture",
      GROUPNAME_SKY));

   AddProperty(new dtDAL::ResourceActorProperty(*this, dtDAL::DataType::TEXTURE,
      "Skybox Down", "Skybox Down",
      dtDAL::ResourceActorProperty::SetFuncType(actor, &OceanConfigActor::SetSkyBoxDown),
      "Sets the sky box texture",
      GROUPNAME_SKY));

   AddProperty(new dtDAL::ResourceActorProperty(*this, dtDAL::DataType::TEXTURE,
      "Skybox Left", "Skybox Left",
      dtDAL::ResourceActorProperty::SetFuncType(actor, &OceanConfigActor::SetSkyBoxLeft),
      "Sets the sky box texture",
      GROUPNAME_SKY));

   AddProperty(new dtDAL::ResourceActorProperty(*this, dtDAL::DataType::TEXTURE,
      "Skybox Right", "Skybox Right",
      dtDAL::ResourceActorProperty::SetFuncType(actor, &OceanConfigActor::SetSkyBoxRight),
      "Sets the sky box texture",
      GROUPNAME_SKY));

   AddProperty(new dtDAL::ResourceActorProperty(*this, dtDAL::DataType::TEXTURE,
      "Skybox Front", "Skybox Front",
      dtDAL::ResourceActorProperty::SetFuncType(actor, &OceanConfigActor::SetSkyBoxFront),
      "Sets the sky box texture",
      GROUPNAME_SKY));

   AddProperty(new dtDAL::ResourceActorProperty(*this, dtDAL::DataType::TEXTURE,
      "Skybox Back", "Skybox Back",
      dtDAL::ResourceActorProperty::SetFuncType(actor, &OceanConfigActor::SetSkyBoxBack),
      "Sets the sky box texture",
      GROUPNAME_SKY));

   AddProperty(new dtDAL::FloatActorProperty("Foam Bottom Height", "Foam Bottom Height",
      dtDAL::FloatActorProperty::SetFuncType(actor, &OceanConfigActor::SetFoamBottomHeight),
      dtDAL::FloatActorProperty::GetFuncType(actor, &OceanConfigActor::GetFoamBottomHeight),
      "",
      GROUPNAME));

   AddProperty(new dtDAL::FloatActorProperty("Foam Top Height", "Foam Top Height",
      dtDAL::FloatActorProperty::SetFuncType(actor, &OceanConfigActor::SetFoamTopHeight),
      dtDAL::FloatActorProperty::GetFuncType(actor, &OceanConfigActor::GetFoamTopHeight),
      "",
      GROUPNAME));

   AddProperty(new dtDAL::ColorRgbaActorProperty("Light Color", "Light Color",
      dtDAL::ColorRgbaActorProperty::SetFuncType(actor, &OceanConfigActor::SetLightColor),
      dtDAL::ColorRgbaActorProperty::GetFuncType(actor, &OceanConfigActor::GetLightColor),
      "color of sun",
      GROUPNAME));

   AddProperty(new dtDAL::FloatActorProperty("Above Water Fog Height", "Above Water Fog Height",
      dtDAL::FloatActorProperty::SetFuncType(actor, &OceanConfigActor::SetAboveWaterFogHeight),
      dtDAL::FloatActorProperty::GetFuncType(actor, &OceanConfigActor::GetAboveWaterFogHeight),
      "Above water fog density (EXP fog)",
      GROUPNAME));

   AddProperty(new dtDAL::FloatActorProperty("Under Water Fog Height", "Under Water Fog Height",
      dtDAL::FloatActorProperty::SetFuncType(actor, &OceanConfigActor::SetUnderWaterFogHeight),
      dtDAL::FloatActorProperty::GetFuncType(actor, &OceanConfigActor::GetUnderWaterFogHeight),
      "Under water fog density (EXP fog)",
      GROUPNAME));

   AddProperty(new dtDAL::ColorRgbaActorProperty("Above Water Fog Color", "Above Water Fog Color",
      dtDAL::ColorRgbaActorProperty::SetFuncType(actor, &OceanConfigActor::SetAboveWaterFogColor),
      dtDAL::ColorRgbaActorProperty::GetFuncType(actor, &OceanConfigActor::GetAboveWaterFogColor),
      "color of fog",
      GROUPNAME));

   AddProperty(new dtDAL::ColorRgbaActorProperty("Under Water Fog Color", "Under Water Fog Color",
      dtDAL::ColorRgbaActorProperty::SetFuncType(actor, &OceanConfigActor::SetUnderWaterFogColor),
      dtDAL::ColorRgbaActorProperty::GetFuncType(actor, &OceanConfigActor::GetUnderWaterFogColor),
      "color of fog under water",
      GROUPNAME));

   AddProperty(new dtDAL::ColorRgbaActorProperty("Under Water Diffuse Color", "Under Water Diffuse Color",
      dtDAL::ColorRgbaActorProperty::SetFuncType(actor, &OceanConfigActor::SetUnderWaterDiffuseColor),
      dtDAL::ColorRgbaActorProperty::GetFuncType(actor, &OceanConfigActor::GetUnderWaterDiffuseColor),
      "color of fog under water",
      GROUPNAME));

   AddProperty(new dtDAL::Vec3ActorProperty("Under Water Attentuation", "Under Water Attentuation",
      dtDAL::Vec3ActorProperty::SetFuncType(actor, &OceanConfigActor::SetUnderWaterAttentuation),
      dtDAL::Vec3ActorProperty::GetFuncType(actor, &OceanConfigActor::GetUnderWaterAttentuation),
      "Attentuation",
      GROUPNAME));

   AddProperty(new dtDAL::FloatActorProperty("Glare Attentuation", "Glare Attentuation",
      dtDAL::FloatActorProperty::SetFuncType(actor, &OceanConfigActor::SetGlareAttentuation),
      dtDAL::FloatActorProperty::GetFuncType(actor, &OceanConfigActor::GetGlareAttentuation),
      "Controls the rate at which the glare drops off (typically 0.75..0.95)",
      GROUPNAME));

   AddProperty(new dtDAL::ColorRgbaActorProperty("Sun Diffuse Color", "Sun Diffuse Color",
      dtDAL::ColorRgbaActorProperty::SetFuncType(actor, &OceanConfigActor::SetSunDiffuseColor),
      dtDAL::ColorRgbaActorProperty::GetFuncType(actor, &OceanConfigActor::GetSunDiffuseColor),
      "color of sun",
      GROUPNAME));

   AddProperty(new dtDAL::Vec3ActorProperty("Sun Direction", "Sun Direction",
      dtDAL::Vec3ActorProperty::SetFuncType(actor, &OceanConfigActor::SetSunDirection),
      dtDAL::Vec3ActorProperty::GetFuncType(actor, &OceanConfigActor::GetSunDirection),
      "Attentuation",
      GROUPNAME));
}
