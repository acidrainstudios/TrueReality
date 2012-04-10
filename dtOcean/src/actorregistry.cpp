#include <dtOcean/actorregistry.h>

#include <dtOcean/oceanactor.h>
#include <dtOcean/oceanconfigactor.h>

using namespace dtOcean;

dtCore::RefPtr<dtDAL::ActorType> OceanActorRegistry::OCEAN_ACTOR_TYPE(new dtDAL::ActorType("OceanActor", "dtOcean",
                                                                                   "OSGOcean actor"));

dtCore::RefPtr<dtDAL::ActorType> OceanActorRegistry::OCEAN_CONFIG_ACTOR_TYPE(new dtDAL::ActorType("OceanConfigActor", "dtOcean",
                                                                                            "OSGOceanConfigActor"));

//////////////////////////////////////////////////////////////////////////
extern "C" DT_OCEAN_EXPORT dtDAL::ActorPluginRegistry* CreatePluginRegistry()
{
   return new OceanActorRegistry;
}

extern "C" DT_OCEAN_EXPORT void DestroyPluginRegistry(dtDAL::ActorPluginRegistry* registry)
{
   if (registry)
   {
      delete registry;
   }
}

OceanActorRegistry::OceanActorRegistry() : dtDAL::ActorPluginRegistry("dtOcean Library")
{
   mDescription = "All game actors for dtOcean";
}

void OceanActorRegistry::RegisterActorTypes()
{   
   //OceanActor/OceanActorProxy
   mActorFactory->RegisterType<dtOcean::OceanActorProxy>(OCEAN_ACTOR_TYPE.get());

   //OceanConfigActor/OceanConfigActorProxy
   mActorFactory->RegisterType<dtOcean::OceanConfigActorProxy>(OCEAN_CONFIG_ACTOR_TYPE.get());
}
