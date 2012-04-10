#pragma once

#include <dtGame/gameactor.h>
#include <dtCore/skybox.h>
#include <dtGame/environmentactor.h>
//#include <dtOcean/export.h>
#include <osg/Fog>
#include <osg/TextureCubeMap>
#include "cylinder.h"
#include "export.h"

namespace dtCore
{
   class Environment;
}

namespace osgOcean
{
   class OceanScene;
   class FFTOceanSurface;
}

namespace dtOcean
{

   class OceanConfigActor;
   class SkyDome;
   class SphereSegment;

   class DT_OCEAN_EXPORT OceanActor : public dtGame::IEnvGameActor
   {
   public:
      typedef dtGame::IEnvGameActor BaseClass;

      /** CTor */
      OceanActor(dtGame::GameActorProxy& proxy);
      ~OceanActor();

      void OnEnteredWorld();
      void ProcessMessage(const dtGame::Message& msg);

      void SetConfig(OceanConfigActor*);

      virtual bool IsPlaceable() const { return false; }

      /**
       * Adds an actor to the internal hierarchy of the environment
       * @param dd The DeltaDrawable to add as a child
       */
      virtual void AddActor(dtCore::DeltaDrawable& dd);

      /**
       * Removes a DeltaDrawable from the internal hierarchy
       * @param dd The DeltaDrawable to remove
       */
      virtual void RemoveActor(dtCore::DeltaDrawable& dd);

      /**
       * Removes all actors associated with this environment
       */
      virtual void RemoveAllActors();

      /**
       * Called to see if this environment has the specified proxy
       * @param proxy The proxy to look for
       * @return True if it contains it, false if not
       */
      virtual bool ContainsActor(dtCore::DeltaDrawable& dd) const;

      /**
       * Gets all the actors associated with this environment
       * @param vec The vector to fill
       */
      virtual void GetAllActors(std::vector<dtCore::DeltaDrawable*>& vec);

      /**
       * Gets the number of children of this environment
       */
      virtual unsigned int GetNumEnvironmentChildren() const;

      osg::Group* GetNode() const;

      void SetSkyRotation(const osg::Quat& rot);
      osg::Quat GetSkyRotation() const;

      osg::Vec3f GetSunDirection();
      void SetSunDirection(const osg::Vec3f& v);

      float GetOceanHeight() const;
      void SetOceanHeight(float v);

	  osg::Vec2 GetWindDirection() const; 
	  void SetWindDirection(osg::Vec2& v);
	  float GetWindSpeed() const;
	  void SetWindSpeed(float v);

      /** Get the height of the ocean surface at the supplied (x,y).
       * @param x : the X location
       * @param y : the Y location
       * @param normal : the Vec3 normal at x,y (optional)
       * @return The height of the surface
       */
      float GetOceanSurfaceHeightAt(float x, float y, osg::Vec3* normal = NULL) const;

      // show or hide the ocean geometry
      void Show(bool showit);

      /** Set the window dimensions.  Call this whenever the window gets
        * resized to keep osgOcean in sync.
        * @param size The window (width, height)
        */
      void SetWindowSize(const osg::Vec2s size);

   private:
      dtCore::RefPtr<dtCore::Environment> mEnv;
      dtCore::RefPtr<osg::LightSource> mLightSource;
      dtCore::RefPtr<OceanConfigActor> mConfig;
	  dtCore::RefPtr<osgOcean::FFTOceanSurface> mOceanSurface;
      dtCore::RefPtr<osgOcean::OceanScene> mOceanScene;
      dtCore::RefPtr<Cylinder> mOceanCylinder;
      dtCore::RefPtr<osg::Fog> mFog;
      dtCore::RefPtr<SkyDome> mSkyDome;
      dtCore::RefPtr<osg::PositionAttitudeTransform> mSkyTransform;
      void OnMapLoaded();
      void Build();

      bool mOceanVisible;
   };

   // -----------------------------------------------

   class DT_OCEAN_EXPORT OceanActorProxy : public dtGame::IEnvGameActorProxy
   {
      typedef dtGame::IEnvGameActorProxy BaseClass;

   public:
      OceanActorProxy();
      virtual void CreateActor();
      virtual void BuildPropertyMap();

   protected:
      virtual ~OceanActorProxy();
   };

} // namespace dtOcean
