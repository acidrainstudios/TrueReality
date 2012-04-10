#pragma once

#include <dtCore/deltadrawable.h>
#include <dtDAL/actorproxy.h>

//#include <dtOcean/export.h>
#include "export.h"

#include <osg/Vec2>
#include <osg/Vec4>

namespace dtOcean
{
   class DT_OCEAN_EXPORT OceanConfigActor : public dtCore::DeltaDrawable
   {
   public:
      static const std::string CLASS_NAME;
      typedef dtCore::DeltaDrawable BaseClass;

      /** CTor */
      OceanConfigActor();

      virtual osg::Node* GetOSGNode() { return NULL; }
      virtual const osg::Node* GetOSGNode() const { return NULL; }

      virtual bool IsPlaceable() const { return false; }

      void SetFFTGridSize(int v) { mFFTGridSize = v; }
      int GetFFTGridSize() const { return mFFTGridSize; }

      void SetResolution(int v) { mResolution = v; }
      int GetResolution() const { return mResolution; }

      void SetNumTiles(int v) { mNumTiles = v; }
      int GetNumTiles() const { return mNumTiles; }

      void SetWindDirection(const osg::Vec2& v) { mWindDirection = v; }
      osg::Vec2 GetWindDirection() const { return mWindDirection; }

      void SetWindSpeed(float v) { mWindSpeed = v; }
      float GetWindSpeed() const { return mWindSpeed; }

      void SetDepth(float v) { mDepth = v; }
      float GetDepth() const { return mDepth; }

      void SetWaveScale(float v) { mWaveScale = v; }
      float GetWaveScale() const { return mWaveScale;}

      void SetIsChoppy(bool v) { mIsChoppy = v; }
      bool GetIsChoppy() const { return mIsChoppy; }

      void SetChoppyFactor(float v) { mChoppyFactor = v; }
      float GetChoppyFactor() const { return mChoppyFactor; }

      void SetAnimLoopTime(float v) { mAnimLoopTime = v; }
      float GetAnimLoopTime() const { return mAnimLoopTime; }

      void SetNumFrames(int v) { mNumFrames = v; }
      int GetNumFrames() const { return mNumFrames; }

      void SetSkyBoxUp(const std::string& f)    { mTexUp = f;    }
      std::string GetSkyBoxUp()    const { return mTexUp;    }

      void SetSkyBoxDown(const std::string& f)  { mTexDown = f;  }
      std::string GetSkyBoxDown()  const { return mTexDown;  }

      void SetSkyBoxLeft(const std::string& f)  { mTexLeft = f;  }
      std::string GetSkyBoxLeft()  const { return mTexLeft;  }

      void SetSkyBoxRight(const std::string& f) { mTexRight = f; }
      std::string GetSkyBoxRight() const { return mTexRight; }

      void SetSkyBoxFront(const std::string& f) { mTexFront = f; }
      std::string GetSkyBoxFront() const { return mTexFront; }

      void SetSkyBoxBack(const std::string& f)  { mTexBack = f;  }
      std::string GetSkyBoxBack()  const { return mTexBack;  }

      void SetFoamBottomHeight(float v) { mFoamBottomHeight = v; }
      float GetFoamBottomHeight() const { return mFoamBottomHeight; }

      void SetFoamTopHeight(float v) { mFoamTopHeight = v; }
      float GetFoamTopHeight() const { return mFoamTopHeight; }

      void SetEnableCrestFoam(bool v) { mEnableCrestFoam = v; }
      bool GetEnableCrestFoam() const { return mEnableCrestFoam; }

      void SetLightColor(const osg::Vec4& c) { mLightColor = c; }
      osg::Vec4 GetLightColor() const { return mLightColor; }

      void SetEnableEndlessOcean(bool v) { mEnableEndlessOcean = v; }
      bool GetEnableEndlessOcean() const { return mEnableEndlessOcean; }

      void SetEnableReflections(bool v) { mEnableReflections = v; }
      bool GetEnableReflections() const { return mEnableReflections; }

      void SetReflectionDamping(float v) { mReflectionDamping = v; }
      float GetReflectionDamping() const { return mReflectionDamping; }

      void SetEnableRefractions(bool v) { mEnableRefractions = v; }
      bool GetEnableRefractions() const { return mEnableRefractions; }

      void SetAboveWaterFogHeight(float v) { mAboveWaterFogHeight = v; }
      float GetAboveWaterFogHeight() const { return mAboveWaterFogHeight; }

      void SetUnderWaterFogHeight(float v) { mUnderWaterFogHeight = v; }
      float GetUnderWaterFogHeight() const { return mUnderWaterFogHeight; }

      void SetAboveWaterFogColor(const osg::Vec4& c) { mAboveWaterFogColor = c; }
      osg::Vec4 GetAboveWaterFogColor() const { return mAboveWaterFogColor; }

      void SetUnderWaterFogColor(const osg::Vec4& c) { mUnderWaterFogColor = c; }
      osg::Vec4 GetUnderWaterFogColor() const { return mUnderWaterFogColor; }

      void SetUnderWaterDiffuseColor(const osg::Vec4& c) { mUnderWaterDiffuseColor = c; }
      osg::Vec4 GetUnderWaterDiffuseColor() const { return mUnderWaterDiffuseColor; }

      void SetUnderWaterAttentuation(const osg::Vec3& c) { mUnderWaterAttentuation = c; }
      osg::Vec3 GetUnderWaterAttentuation() const { return mUnderWaterAttentuation; }

      void SetSunDirection(const osg::Vec3& c) { mSunDirection = c; }
      osg::Vec3 GetSunDirection() const { return mSunDirection; }

      void SetEnableGodRays(bool v) { mEnableGodRays = v; }
      bool GetEnableGodRays() const { return mEnableGodRays; }

      void SetEnableSilt(bool v) { mEnableSilt = v; }
      bool GetEnableSilt() const { return mEnableSilt; }

      void SetEnableUnderwaterDOF(bool v) { mEnableUnderwaterDOF = v; }
      bool GetEnableUnderwaterDOF() const { return mEnableUnderwaterDOF; }

      void SetEnableGlare(bool v) { mEnableGlare = v; }
      bool GetEnableGlare() const { return mEnableGlare; }

      void SetGlareAttentuation(float v) { mGlareAttentuation = v; }
      float GetGlareAttentuation() const { return mGlareAttentuation; }

      void SetSkyBoxRadius(float v) { mSkyBoxRadius = v; }
      float GetSkyBoxRadius() const { return mSkyBoxRadius; }

      void SetSkyBoxLongSteps(int v) { mSkyBoxLongSteps = v; }
      int GetSkyBoxLongSteps() const { return mSkyBoxLongSteps; }

      void SetSkyBoxLatSteps(int v) { mSkyBoxLatSteps = v; }
      int GetSkyBoxLatSteps() const { return mSkyBoxLatSteps; }

      void SetSunDiffuseColor(const osg::Vec4& c) { mSunDiffuseColor = c; }
      osg::Vec4 GetSunDiffuseColor() const { return mSunDiffuseColor; }

      void SetUseDefaultSceneShader(bool v) { mUseDefaultSceneShader = v; }
      bool GetUseDefaultSceneShader() const { return mUseDefaultSceneShader; }

      void SetOceanHeight(double v) { mOceanHeight = v; }
      double GetOceanHeight() const { return mOceanHeight; }

   private:
      /** skybox params */
      float mSkyBoxRadius;
      int mSkyBoxLongSteps;
      int mSkyBoxLatSteps;

      int mFFTGridSize;
      int mResolution;
      int mNumTiles;

      osg::Vec2f mWindDirection;
      float mWindSpeed;
      float mDepth;

      float mWaveScale;

      float mReflectionDamping;

      bool mIsChoppy;
      float mChoppyFactor;

      float mAnimLoopTime;

      int mNumFrames;

      std::string mTexUp;
      std::string mTexDown;
      std::string mTexLeft;
      std::string mTexRight;
      std::string mTexFront;
      std::string mTexBack;

      float mFoamBottomHeight;
      float mFoamTopHeight;

      bool mEnableCrestFoam;

      osg::Vec4f mLightColor;

      bool mEnableEndlessOcean;

      bool mEnableReflections;
      bool mEnableRefractions;

      float mAboveWaterFogHeight;
      float mUnderWaterFogHeight;

      osg::Vec4f mAboveWaterFogColor;
      osg::Vec4f mUnderWaterFogColor;
      osg::Vec4f mUnderWaterDiffuseColor;

      osg::Vec3 mUnderWaterAttentuation;

      osg::Vec3 mSunDirection;

      bool mEnableGodRays;
      bool mEnableSilt;

      bool mEnableUnderwaterDOF;
      bool mEnableGlare;

      float mGlareAttentuation;

      osg::Vec4f mSunDiffuseColor;

      bool mUseDefaultSceneShader;

      float mOceanHeight;
   };

   // -----------------------------------------------

   class DT_OCEAN_EXPORT OceanConfigActorProxy : public dtDAL::ActorProxy
   {
      typedef dtDAL::ActorProxy BaseClass;

   public:
      OceanConfigActorProxy();
      virtual void CreateActor();
      virtual void BuildPropertyMap();

      virtual bool IsPlaceable() const { return false; }

   protected:
      virtual ~OceanConfigActorProxy();
   };

} // namespace dtOcean
