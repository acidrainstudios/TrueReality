/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* CS586 DLL Stevens University Collision Avoidance Project
*
* This file is part of Virtual Reality Simulation Lab software; you can redistribute 
* it and/or modify it under the terms of the GNU Lesser General Public License as 
* published by the Free Software Foundation; either version 2.1 of the License, or 
* (at your option) any later version.
*
* By the GNU LGP License any changes or modification you made must be sent back 
* to the original owners of the file, and appropriate credit given.
*
* This file is distributed WITHOUT ANY WARRANTY; without even the implied warranty 
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General 
* Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* @author CS586 Class:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////

#ifndef VRS_CS586_COLLISIONCONE_ACTOR_H
#define VRS_CS586_COLLISIONCONE_ACTOR_H

#include <iostream>
#include <set>

#include <dtCore/object.h>
#include <dtCore/refptr.h>
#include <dtCore/transform.h>
#include <dtCore/transformable.h>
#include <dtGame/gameactor.h>
#include <dtDAL/gameevent.h>
#include <dtDAL/gameeventmanager.h>
#include <dtActors/gamemeshactor.h>
#include <ode/collision.h>
#include <ode/objects.h>
class CollisionConeActor : public dtCore::Object
{
public:

	//Default Actors Name
	static const std::string ACTOR_DEFAULT_NAME;

    static const float COLLISION_VOLUME_MASS;

	CollisionConeActor(bool Visible);

	void addAgentInRange( dtCore::Physical*);
	void addContactGeometryPoints( int _numberPoints,  dContactGeom * _contactPoints );
	std::vector<osg::Vec3 *>  getTerrainCollisions();
	std::set<dtCore::Physical*> getAgentsInRange( );
	void clearAgentSet( );

protected:

	virtual ~CollisionConeActor() { };

private:
	std::set<dtCore::Physical*> agentsInRange;
	std::vector<osg::Vec3*> terrainCollisions;
};

#endif //VRS_CS586_COLLISIONCONE_ACTOR_H