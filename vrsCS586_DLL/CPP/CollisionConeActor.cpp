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

#ifndef VRS_CS586_COLLISIONCONE_ACTOR_CPP
#define VRS_CS586_COLLISIONCONE_ACTOR_CPP

#include "../Include/CollisionConeActor.h"

///////////////////////////////////////////////////////////////////////////////
const std::string CollisionConeActor::ACTOR_DEFAULT_NAME("CollisionCone");
///////////////////////////////////////////////////////////////////////////////
const float CollisionConeActor::COLLISION_VOLUME_MASS = 0.069f;
///////////////////////////////////////////////////////////////////////////////
CollisionConeActor::CollisionConeActor(bool Visible)
{
	SetName(ACTOR_DEFAULT_NAME);
   
	LoadFile( "Misc/TriColVol.ive" );
	SetCollisionMesh( 0 );
	/*this->SetCollisionBox(0);
	this->RenderCollisionGeometry(true);*/
	SetCollisionDetection( true );
	if(!Visible)
	{
		GetOSGNode( )->setNodeMask( 0 );
	}
	SetMass( (float) CollisionConeActor::COLLISION_VOLUME_MASS );

	agentsInRange = std::set<dtCore::Physical*>( );
}
void CollisionConeActor::addContactGeometryPoints( int _numberPoints, dContactGeom * _contactPoints )
{
	for( int i = 0 ; i < _numberPoints; i++ )
	{
		terrainCollisions.push_back( new osg::Vec3( _contactPoints[i].pos[0],_contactPoints[i].pos[1],_contactPoints[i].pos[2] ) );
	}
}
std::vector<osg::Vec3 *> CollisionConeActor::getTerrainCollisions()
{
	return terrainCollisions;
}
///////////////////////////////////////////////////////////////////////////////
void CollisionConeActor::addAgentInRange( dtCore::Physical* agent )
{
	if( agent == GetParent( ) ) return;
	agentsInRange.insert( agent );
}
///////////////////////////////////////////////////////////////////////////////
std::set<dtCore::Physical*> CollisionConeActor::getAgentsInRange( )
{
	return agentsInRange;
}
///////////////////////////////////////////////////////////////////////////////
void CollisionConeActor::clearAgentSet( )
{
	agentsInRange.clear( );
	terrainCollisions.clear( );
}
///////////////////////////////////////////////////////////////////////////////

#endif //VRS_CS586_COLLISIONCONE_ACTOR_H