#include <dtDAL/actorpluginregistry.h>
//#include <dtOcean/export.h>
#include "export.h"

class DT_OCEAN_EXPORT OceanActorRegistry : public dtDAL::ActorPluginRegistry
{
public:
   static dtCore::RefPtr<dtDAL::ActorType> OCEAN_ACTOR_TYPE; 
   static dtCore::RefPtr<dtDAL::ActorType> OCEAN_CONFIG_ACTOR_TYPE; 

   OceanActorRegistry();
   void RegisterActorTypes();
};
