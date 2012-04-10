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

#ifndef VRS_HAPPY_SPHERE_ACTOR_CPP
#define VRS_HAPPY_SPHERE_ACTOR_CPP

#include "..\\Include\ActorHappySphere.h"
#include <time.h>

///////////////////////////////////////////////////////////////////////////////
const std::string HappySphereActor::ACTOR_DEFAULT_NAME("Happy Sphere Actor");
///////////////////////////////////////////////////////////////////////////////
HappySphereActor::HappySphereActor(vrsCore::GenericActorProxy& proxy)
:vrsCore::GenericActor(proxy)
,mSpeed(0.0f)
,mTurnRate(0.0f)
,mTurnDirection(0.0f)
,mTurnTimer(0.0f)
,mCollisionTimer(0.0f)
,mPathSet(false)
,mVisibleColVol(false)
,mPathShortEnabled(true)
,mAggressiveRatio(_DEFAULT_AGGRESSIVENESS)
,mCurrentVelocityVector( new osg::Vec3(0.0f,0.0f,0.0f) )
,mPreferredVelocityVector( new osg::Vec3(0.0f,0.0f,0.0f) )
,mTimeToCollision(0.0f)
,mCurrentWaypoint( new dtAI::Waypoint() )
,mUniqueId(++_UNIQUE_ID)
{	
	//Set the instences Name
	SetName(ACTOR_DEFAULT_NAME); 
	//Set the Actor Description
	SetDescription("Happy Sphere Actor for the CS586 Collision Avoidance Project "); 
}
///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::SetSpeed(float speed)
{
	mSpeed = speed;
}
///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::TurnRight(float speed, float time)
{
	mTurnDirection = -1;
	mTurnRate = speed;
	mTurnTimer = time;
}
///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::TurnLeft(float speed, float time)
{
	mTurnDirection = 1;
	mTurnRate = speed;
	mTurnTimer = time;
}
///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::TurnRight(float Degree)
{
	dtCore::Transform t;
	osg::Vec3f hpr(0.0f,0.0f,0.0f);
	GetTransform(t);
	t.GetRotation(hpr);
	hpr.set(hpr.x()+Degree, hpr.y(), hpr.z());
	t.SetRotation(hpr);
	SetTransform(t);
}
///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::TurnLeft(float Degree)
{
	dtCore::Transform t;
	osg::Vec3f hpr(0.0f,0.0f,0.0f);
	GetTransform(t);
	t.GetRotation(hpr);
	hpr.set(hpr.x()-Degree, hpr.y(), hpr.z());
	t.SetRotation(hpr);
	SetTransform(t);
}
//////////////////////////////////////////////////////////////////////////////
void HappySphereActor::HeightHack(float height)
{
	dtCore::Transform t;
	osg::Vec3f hpr(0.0f,0.0f,0.0f);
	osg::Vec3f pos(0.0f,0.0f,0.0f);
	GetTransform(t);
	t.GetRotation(hpr);
	t.GetTranslation(pos);
	hpr.set(hpr.x(), 0.0f, 0.0f);
	pos.set(pos.x(), pos.y(), height);
	t.SetRotation(hpr);
	t.SetTranslation(pos);
	SetTransform(t);
}
//////////////////////////////////////////////////////////////////////////////
void HappySphereActor::MoveActor(float deltaSimTime)
{
	/*  <--- do not remove this function ...  work in progress
	if(mTurnTimer > 0.0f)
	{
		
		mTurnTimer -= mDeltaSimTime;
		if(mTurnTimer <= 0.0f)
		{
			mTurnTimer = 0.0f;
		}
		else
		{
			SetTurnRateMax(mTurnRate);			
		}
	}
	else if(mTurnTimer == 0.0f)
	{
		mTurnDirection = 0;
	}
	else
	{
		SetTurnRateMax(mTurnRate);		
	}             
	SetTurnDirection(mTurnDirection);
	*/
	SetVelocity(mSpeed);
}
///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::SetPath(dtAI::Waypoint* Start, dtAI::Waypoint* End)
{
	mWayPointPath[0] = Start;
	mWayPointPath[1] = End;
	FindPath(Start, End);
	mPathSet = true;
	PaintNextWaypoint();
}
///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::JumpToPathStart(void)
{
	if(mPathSet)
	{
		dtCore::Transform t;
		osg::Vec3f pos = mWayPointPath[0]->GetPosition();
		osg::Vec3f hpr(180.0f,0.0f,0.0f);
		//pos.set(pos.x()+dtUtil::RandFloat(-3.0f, 3.0f), pos.y()+dtUtil::RandFloat(-3.0f, 3.0f), pos.z());
 
		GetTransform(t);
		t.SetTranslation(pos);
		t.SetRotation(hpr);
		SetTransform(t);
	}
}


///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::FindPath(const dtAI::Waypoint* startWaypoint, const dtAI::Waypoint* endWaypoint)
{
	//call reset with the two points we want to path between
	mAStar.Reset(startWaypoint, endWaypoint);
	//call to find the path
	mAStar.FindPath();
	//copy the resulting path into a list
	mPathToWaypoint = mAStar.GetPath();
	//remove the first waypoint from the list, which is the starting waypoint
	mPathToWaypoint.pop_front(); 
}
///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::PaintNextWaypoint(void)
{
	//Paint Next waypoint in path
	static_cast<const dtAI::Waypoint*>(mPathToWaypoint.front())->SetRenderFlag(dtAI::Waypoint::RENDER_BLUE);
}
void HappySphereActor::AvoidCollision(const float _newOrientation)
{
	/*
	printf(" Avoiding Collision %f\n" , _newOrientation );
	float wpDirection = GetAngle(CurrentWaypoint());
	float myAngle = /**GetOrientation().x()+ **/(  _newOrientation) ;

		/*
		* -180 to 180 UTM Coord System  
		* 0 = north
		* -180 to 0 = west
		* 0 to 180 = east
		*/
	/*	
		if((myAngle < 0.0f) && (wpDirection < 0.0f)) //if myAngle = west and wpDirection = west
		{
			if (myAngle - wpDirection >= 0.0f) ///check which is biger
			{
				 TurnLeft(myAngle - wpDirection);
				 //TurnRight(myAngle - wpDirection);
			}
			else
			{
				 TurnRight(wpDirection-myAngle);
				//TurnLeft(wpDirection-myAngle);
			}
		} 
		else if ((myAngle >= 0.0f) && (wpDirection >= 0.0f)) //if myAngle = east and wpDirection = east
		{
			if (myAngle - wpDirection >= 0.0f) ///check which is biger
			{
				  TurnLeft(myAngle - wpDirection);
				//TurnRight(myAngle - wpDirection);
			}
			else
			{
				  TurnRight(wpDirection-myAngle);
				 //TurnLeft(wpDirection-myAngle);

			}
		}
		else if ((myAngle < 0.0f) && (wpDirection >= 0.0f)) //if myAngle = west and wpDirection = east
		{
			if (myAngle - wpDirection <= -180.0f)
			{
				  TurnLeft(360.0f + myAngle - wpDirection);
				 //TurnRight(360.0f + myAngle - wpDirection);
			}
			else
			{
				  TurnRight(wpDirection - myAngle);
				 //TurnLeft(wpDirection - myAngle);
			}
		}
		else	
		{
			if (myAngle - wpDirection <= 180.0f) ///check which is biger
			{
				  TurnLeft(myAngle - wpDirection);
				 //TurnRight(myAngle - wpDirection);
			}
			else
			{
				  TurnRight(360 + wpDirection - myAngle);
				 //TurnLeft(360 + wpDirection - myAngle);
			}
		}
*/
}

///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::TurnToWaypoint(const dtAI::Waypoint* Waypoint)
{

	float wpDirection = GetAngle(Waypoint);
	float myAngle = GetOrientation().x();

	/*
	* -180 to 180 UTM Coord System  
	* 0 = north
	* -180 to 0 = west
	* 0 to 180 = east
	*/
	
	
	if((myAngle < 0.0f) && (wpDirection < 0.0f)) //if myAngle = west and wpDirection = west
	{
		if (myAngle - wpDirection >= 0.0f) ///check which is biger
		{
			TurnLeft(myAngle - wpDirection);
		}
		else
		{
			TurnRight(wpDirection-myAngle);
		}
	} 
	else if ((myAngle >= 0.0f) && (wpDirection >= 0.0f)) //if myAngle = east and wpDirection = east
	{
		if (myAngle - wpDirection >= 0.0f) ///check which is biger
		{
			TurnLeft(myAngle - wpDirection);
		}
		else
		{
			TurnRight(wpDirection-myAngle);

		}
	}
	else if ((myAngle < 0.0f) && (wpDirection >= 0.0f)) //if myAngle = west and wpDirection = east
	{
		if (myAngle - wpDirection <= -180.0f)
		{
			TurnLeft(360.0f + myAngle - wpDirection);
		}
		else
		{
			TurnRight(wpDirection - myAngle);
		}
	}
	else	
	{
		if (myAngle - wpDirection <= 180.0f) ///check which is biger
		{
			TurnLeft(myAngle - wpDirection);
		}
		else
		{
			TurnRight(360 + wpDirection - myAngle);
		}
	}
 
	//float angle = GetAngle(Waypoint);
	//float direction = GetOrientation().x();
 // // Alberto's Method of Traversing Waypoints: 
 // if (angle < 0)
 // {
 //   angle += 360.0f;
 // }
 // if (direction < 0)
 // {
 //   direction += 360.0f;
 // }         
 // angle -= direction;
 // if (angle > 180)
 // {
 //   angle -= 360.0f;    
 // }
 // if (angle < -180)
 // {
	//angle += 360.0f;
 // }
 // if (angle < 0)
 // {
 //   TurnRight(abs(angle)*4, .25f);
 // }   
 // else
 // {	  
 //   TurnLeft(angle*4, .25f);
 // } 

}
///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::ShortenPathToWaypoint()
{
	if (mPathToWaypoint.size() < 2)
		return;
	
	const dtAI::WaypointInterface* NextWaypoint = *(++(mPathToWaypoint.begin()));

	//set the starting point of the ray
	mCastRay->SetStartPosition(GetPosition());
	//set the ending point of the ray	
	mCastRay->SetEndPosition(NextWaypoint->GetPosition());

	if (mCastRay->Update()) 
	{
		//skip to the next way point If no collisions are detected
		if (mCastRay->GetNumberOfHits() <= 1)
		{ 
			mPathToWaypoint.pop_front();
			PaintNextWaypoint();
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
bool HappySphereActor::IsAtWaypoint(const dtAI::Waypoint* Waypoint)
{
   return (GetDistance(Waypoint) < _WAYPOINT_TOLERANCE);
}
///////////////////////////////////////////////////////////////////////////////
bool HappySphereActor::IsAtGoal()
{
  return (mPathToWaypoint.front() == mPathToWaypoint.back());
}
///////////////////////////////////////////////////////////////////////////////
float HappySphereActor::Distance(osg::Vec3 vector1, osg::Vec3 vector2)
{
	osg::Vec3 dis = (vector1 - vector2);
	return dis.length();
}
///////////////////////////////////////////////////////////////////////////////
float HappySphereActor::GetDistance(const dtAI::Waypoint* Waypoint)
{
	return Distance(GetPosition(), Waypoint->GetPosition());
}
///////////////////////////////////////////////////////////////////////////////
float HappySphereActor::GetAngle(const dtAI::Waypoint* Waypoint)
{
	return ((atan2(Waypoint->GetPosition().y()-GetPosition().y(), Waypoint->GetPosition().x()-GetPosition().x()))*(180/osg::PI)-90.0f);
}
float HappySphereActor::GetAngle( HappySphereActor * _actor )
{
	return ((atan2(_actor->GetPosition().y()-GetPosition().y(), _actor->GetPosition().x()-GetPosition().x()))*(180/osg::PI)-90.0f);
}
///////////////////////////////////////////////////////////////////////////////
osg::Vec3 HappySphereActor::GetPosition()
{
	
	osg::Vec3 mCurrentPosition;
	dtCore::Transform delta;
	GetTransform(delta);
	mCurrentPosition.set(delta.GetTranslation());
	return mCurrentPosition;
}
void HappySphereActor::SetPosition(osg::Vec3 _pos)
{
	osg::Vec3 mCurrentPosition;
	dtCore::Transform delta;
	GetTransform(delta);
	mCurrentPosition.set(delta.GetTranslation());
}
///////////////////////////////////////////////////////////////////////////////
osg::Vec3 HappySphereActor::GetOrientation()
{
  osg::Vec3 mCurrentOrientation;
  dtCore::Transform delta;
  GetTransform(delta);
  delta.GetRotation(mCurrentOrientation);
  return mCurrentOrientation;
}
void HappySphereActor::update(osg::Vec3 * _candidateVelocityVector)
{

	if( _candidateVelocityVector!=NULL )
	{
 		osg::Vec3 * _vPref = PreferredVelocity(CurrentWaypoint());
	 	float _currentAngle = _180_OVER_PI * atan2(  CurrentVelocity()->y() , CurrentVelocity()->x() );
		float _newAngle = _180_OVER_PI * atan2( _candidateVelocityVector->y() ,  _candidateVelocityVector->x() );
		TurnRight(  ( _currentAngle-_newAngle ) );//u bastard
		SetSpeed((_candidateVelocityVector->length()));
	}
}
std::vector<osg::Vec3 *> HappySphereActor::CandidateCollisionActors(std::vector<osg::Vec3 *> _possibleCollisions )
{
	osg::Vec3 * _vectorToAdd = NULL;
	std::vector<osg::Vec3 *> _candidateTerrainPoints;
	float _lowestTTC = 1000000000.0f;
	for( unsigned int i = 0 ; i < _possibleCollisions.size() ;i++ )
	{
			float _ttCollide = TimeToCollision(  _possibleCollisions.at(i) , CurrentVelocity() ,1.0f   );
   			if( _ttCollide >  0.0f && _ttCollide < _lowestTTC ) 
			{
 					//_candidateTerrainPoints.push_back(_possibleCollisions.at(i));
				_lowestTTC = _ttCollide;
				_vectorToAdd = _possibleCollisions.at(i);
			}		
	}
	if(_vectorToAdd!=NULL)
	{
		_candidateTerrainPoints.push_back(_vectorToAdd);
	}
	return _candidateTerrainPoints;
}
std::vector<dtCore::Physical *> HappySphereActor::CandidateCollisionActors(std::set<dtCore::Physical *> _possibleCollisions )
{
	HappySphereActor * _actorToAdd = NULL;

	std::vector<dtCore::Physical *> _candidateActors;
	float _lowestTTC = 1000000000.0f;
	for( std::set<dtCore::Physical *>::iterator i = _possibleCollisions.begin( ); i != _possibleCollisions.end( ); i++ )
	{
		HappySphereActor * _actor = dynamic_cast<HappySphereActor*>((*i));
		if(_actor!=NULL)
		{
			float _ttCollide = TimeToCollision(  &_actor->GetPosition() , CurrentVelocity() ,1.0f   );
			if( _ttCollide >  0.0f && _ttCollide < _lowestTTC ) 
			{
 					//_candidateActors.push_back(_actor);
					_lowestTTC = _ttCollide;
					_actorToAdd = _actor;
			}
		}
	}
	if(_actorToAdd!=NULL)
	{
		_candidateActors.push_back(_actorToAdd);
	}
	return _candidateActors;
}
void HappySphereActor::TurnToWaypoint()
{
	
  
		if (IsAtWaypoint(static_cast<const dtAI::Waypoint*>(mPathToWaypoint.front()))) 
		{
			
			//if the goal was reached
			if (IsAtGoal())
			{
			//	printf("At Final Goal --> Reset )\n");
				//respawn actor
				SetPath(mWayPointPath[0], mWayPointPath[1]);
				JumpToPathStart();
			}
			else
			{
				mPathToWaypoint.pop_front();
				//go to the next waypoint
				PaintNextWaypoint();
			}
		}
		else 
		{
			mCurrentWaypoint = static_cast<const dtAI::Waypoint*>(mPathToWaypoint.front());
			TurnToWaypoint(mCurrentWaypoint);
			SetSpeed( PreferredVelocity(CurrentWaypoint())->length());
		}
}
///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::AvoidCollision(void)
{
	CollisionConeActor * _collisionCone = static_cast<CollisionConeActor*>( GetChild( 0 ) );
	std::vector<Physical *> _actors = CandidateCollisionActors( _collisionCone->getAgentsInRange() );
	std::vector<osg::Vec3 *> _terrain = CandidateCollisionActors( _collisionCone->getTerrainCollisions());

/*	TurnToWaypoint();
	for( unsigned int i=0; i < _actors.size() ; i++ )
	{
		osg::Vec3 * _intersectionPoint =  VelocityVectorIntersection( _actors.at(i) , 1.4f ) ;
		if(_intersectionPoint==NULL)
		{
			printf("No Collision - no intersection\n");
		}
		else
		{
			 printf( "Possible Collision Detected at (%f,%f)\n" , _intersectionPoint->x() , _intersectionPoint->y() );
			float _ttc = TimeToCollision( &(_actors.at(i)->GetPosition()),  _actors.at(i)->CurrentVelocity() , 2.0f );
			if( _ttc >= 0.0f )
			{
				osg::Vec3 * _v = CurrentVelocity();
				osg::Vec3 * _aV = _actors.at(i)->CurrentVelocity();
			}
		}

	}*/

					 if ( IsAtWaypoint(static_cast<const dtAI::Waypoint*>(mPathToWaypoint.front())) ||  _actors.size()==0)
				 	 {
						TurnToWaypoint();
					 }
					 else	
					 {
						//Avoid Collision
					 	update(ChooseCandidateVector( GenerateCandidateVectors( _actors  ,_terrain, PreferredVelocity( CurrentWaypoint() ) ) , _actors , _terrain ));
					 } 

	static_cast<CollisionConeActor*>( GetChild( 0 ) )->clearAgentSet( );

	//checking if waypoint was reached


}
///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::SetColVolVisibility(bool Visible)
{
	mVisibleColVol = Visible;
}
///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::SetPathShortEnabled(bool Enabled)
{
	mPathShortEnabled = Enabled;
}

///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::OnTickLocal(const dtGame::TickMessage& tickMessage)
{
	mDeltaSimTime = tickMessage.GetDeltaSimTime();
	/*************************************************
	**
	**	TEMPORARY BUG FIX -
	**	HAPPY ACTORS ARE RISING AND FALLING
	**
	*************************************************/
	HeightHack(10.0f);
	//Detect Collision and get movement correction values 
	 if(mCollisionTimer > _COLLISION_TIME_STEP ) //limiting responce to 5x/sec
	 {
		AvoidCollision();
		mCollisionTimer = 0.0f;
	 }
	//Cast the ray every 2sec, but at randome time between the actors...
	if(mPathShortEnabled)
	{
		if((mRayCastTimer-mRayCastTime) > 2.0f)
		{
			ShortenPathToWaypoint();
			mRayCastTimer = -mRayCastTime;
		}
		mRayCastTimer += mDeltaSimTime;
	}

	//Move the Actor
	MoveActor(mDeltaSimTime);
	mCollisionTimer += mDeltaSimTime;
	GenericActor::OnTickLocal(tickMessage);
}
osg::Vec3 * HappySphereActor::CurrentVelocity()
{
  dtCore::Transform delta;
  GetTransform(delta);
  osg::Vec3 _forwardVector ;
  osg::Vec3 _upVector;
  osg::Vec3 _rightVector;
  delta.GetOrientation(_upVector,_rightVector,_forwardVector);
  mCurrentVelocityVector->set((_forwardVector*mSpeed));

	//mCurrentVelocityVector->set( GetOrientation() );
	//mCurrentVelocityVector->normalize();
	//mCurrentVelocityVector->set(mCurrentVelocityVector->x()* mSpeed  ,mCurrentVelocityVector->y()* mSpeed   ,mCurrentVelocityVector->z()* mSpeed    ) ; 
  return mCurrentVelocityVector;
}
//Calculates the Preferred Velocity Vector to the Current Waypoint
osg::Vec3 * HappySphereActor::PreferredVelocity(const dtAI::Waypoint * _waypoint)
{
	const osg::Vec3 & _waypointPosition = _waypoint->GetPosition();
	osg::Vec3 _position = GetPosition();
	const osg::Vec3 & _currentPosition = osg::Vec3(_position.x(), _position.y() , _position.z() );
	const osg::Vec3 & _distanceVector = ( _waypointPosition - _currentPosition );
	const float _distanceToWaypointSquared =   _distanceVector.x()*_distanceVector.x() + _distanceVector.y()*_distanceVector.y();// ///May need to change this to dot(2 dimension)
	const float _calculatedAcceleration = ( _PREFERRED_SPEED * mDeltaSimTime ) * ( _PREFERRED_SPEED * mDeltaSimTime ) ;
	if( _calculatedAcceleration > _distanceToWaypointSquared )
 	{
		osg::Vec3 _newPreferredSpeed =  _distanceVector/mDeltaSimTime ;
		mPreferredVelocityVector->set(_newPreferredSpeed.x(), _newPreferredSpeed.y(), _newPreferredSpeed.z() );
 	}
 	else
 	{
		osg::Vec3 _newPreferredSpeed = _distanceVector * (_PREFERRED_SPEED/sqrt(_distanceToWaypointSquared))   ;
		mPreferredVelocityVector->set(_newPreferredSpeed.x(), _newPreferredSpeed.y(), _newPreferredSpeed.z() );
 	}
	return mPreferredVelocityVector;
}






//Returns the time to collision for a happy sphere actor.
float HappySphereActor::TimeToCollision( osg::Vec3 * _actorPosition,
										osg::Vec3 * _collisionVector,
										float _radius)
{
	
	float _timeToCollision = 0.0f;
	osg::Vec3 * _currentPosition = &GetPosition();
	const osg::Vec3  _deltaDistanceVector =   
	osg::Vec3( _actorPosition->x() - _currentPosition->x(), _actorPosition->y() -  _currentPosition->y() , _actorPosition->z() -  _currentPosition->z() ) ;//- (*_actorPosition);
	float _radius_squared = (_radius)*(_radius);   
	float _determinantDistanceCollisionVector = det( *(_collisionVector) ,   _deltaDistanceVector );
	
	
	float _dotProductCollisionVectorDistanceVector =   dot( *(_collisionVector), _deltaDistanceVector) ;
	
	//  _collisionVector->x()*_deltaDistanceVector.x() + _collisionVector->y()*_deltaDistanceVector.y();//( *(_collisionVector)) *( *(_deltaDistanceVector) );
	float _velocityVectorDotProduct =dot( *(_collisionVector) , *(_collisionVector) );// _collisionVector->x()* _collisionVector->x() + _collisionVector->y()*_collisionVector->y();
	float _discriminator = -(_determinantDistanceCollisionVector*_determinantDistanceCollisionVector)  + (_radius_squared * (_velocityVectorDotProduct) );
	if(_discriminator > 0.0f )
	{
	//	printf("Discriim > 0 (%f) \n",_discriminator);
		 _timeToCollision = (_dotProductCollisionVectorDistanceVector + std::sqrt(_discriminator)) / _velocityVectorDotProduct;
	
	}
	else
	{
	 	//printf("Discriim <= 0 (%f) \n",_discriminator);
		_discriminator = _discriminator * -1.0f;
		_timeToCollision = (_dotProductCollisionVectorDistanceVector - std::sqrt(_discriminator)) / _velocityVectorDotProduct;
	}
	return _timeToCollision;

}

osg::Vec3 * HappySphereActor::ChooseCandidateVector( std::vector<osg::Vec3 *> _candidateVectors, std::vector<dtCore::Physical *> _actors  , std::vector<osg::Vec3 *> _terrainCollisions )
{
	if( _actors.size()==0 && _terrainCollisions.size() == 0 )
	{
		 TurnToWaypoint();
		 return CurrentVelocity();
	}
	else
	{
		osg::Vec3 * _candidate = NULL;
		_candidate = ChoosePenaltyVector(_candidateVectors,_actors, _terrainCollisions);
		return _candidate;
	}


/*	std::vector<osg::Vec3 *> _timeToCollisionLessthanZero ;		//Stores all vectors that have no collision.
	std::vector<osg::Vec3 *> _timeToCollisionGreaterThanZero;   //Stores all the vectors that have a collision.
	osg::Vec3 * _candidate = NULL;
	for( unsigned short int i=0; i < _candidateVectors.size() ; i++ )
	{
		_candidate = _candidateVectors.at(i);
		float _totalTimeToCollision = 1000000000.0f;
		for( unsigned short int j=0; j < _actors.size() ; j++ )
		{
				float _timeToCollision = TimeToCollision( &(_actors.at(j)->GetPosition()), _candidate , 2.0f ) ;
				this->TimeToCollision(_actors.at(j) , _candidate , 2.0f );
				if( _totalTimeToCollision > _timeToCollision ) {_totalTimeToCollision = _timeToCollision; }
		}
		if( _totalTimeToCollision < 0.0f )
		{
			_timeToCollisionLessthanZero.push_back(_candidate);
		}
		else
		{
			_timeToCollisionGreaterThanZero.push_back(_candidate);
		}
	}
 	if(_candidate != NULL)
	{
		if( _timeToCollisionLessthanZero.size()==0    )
		{
			
			_candidate = ChoosePenaltyVector(_timeToCollisionGreaterThanZero,_actors);
		}
		else
		{
			osg::Vec3 * _currentVelocity = CurrentVelocity();
			float _minimumDistance = 10000000000.0f;
			osg::Vec3 * _candidate = NULL;
			for( unsigned short int z=0; z < _timeToCollisionLessthanZero.size(); z++ )
			{
				float _distance =    (*(_currentVelocity) - *(_timeToCollisionLessthanZero.at(z)) ).length();
				if(_distance < _minimumDistance )
				{
				 	_minimumDistance = _distance;
					_candidate = _timeToCollisionLessthanZero.at(z);
				}
			}  
		}
	}*/

}
	//Returns Penalty for Candidate Vector
float HappySphereActor::Penalty( osg::Vec3 * _actorPosition,   osg::Vec3 * _candidateVector, float _actorRadius )
{
	float _ttc =  TimeToCollision( _actorPosition, _candidateVector , _actorRadius );
	//printf(" Time To Collision(%f)\n" , _ttc );
//	if( _ttc > 0.0f  /** && _ttc < 3.0f **/ )
//	{
		osg::Vec3 _dV = *(PreferredVelocity( CurrentWaypoint() )) - *(_candidateVector) ;
		return  mAggressiveRatio / TimeToCollision(_actorPosition , _candidateVector , _actorRadius )  + _dV.length();
	//}
	return 1000000000.0f;
}
//Chooses penalty 
osg::Vec3 * HappySphereActor::ChoosePenaltyVector(std::vector<osg::Vec3 *> _candidateVectors , std::vector<dtCore::Physical *> _actors, std::vector<osg::Vec3 *> _terrainCollisions)
{
	osg::Vec3 * _candidate = NULL;
	
	if( _candidateVectors.size()  > 0 &&  _actors.size() > 0  )
	{
		HappySphereActor * _minimumTTCActor = dynamic_cast<HappySphereActor*>( _actors.at(0) );
 		_candidate =  _candidateVectors.at(0);
		float _ttCollide = TimeToCollision( &_minimumTTCActor->GetPosition() , CurrentVelocity() ,1.0f   );
		
		for(unsigned int j=0; j< _actors.size(); j++)
		{
			HappySphereActor * _actor  = dynamic_cast<HappySphereActor*>(_actors.at(j));
			if(_actor!=NULL)
			{
				float _ttc = TimeToCollision( &_actor->GetPosition() , CurrentVelocity() , 1.0f ) ;
				if( _ttCollide > _ttc )
				{
					_ttCollide=_ttc;
					_candidate = &_actor->GetPosition();
				}
			}
		}//end for(......)

				/*HappySphereActor * _actor = dynamic_cast<HappySphereActor*>( _actors.at(j) );
				if(_actor!=NULL)
				{
					float _penalty = Penalty( &_actor->GetPosition()  , _candidateVector , 1.0f ) ;
					if(  _minimumPenaltyAmongActors  > _penalty  ) 
					{ 
							_minimumPenaltyAmongActors = _penalty; 
					}
				}*/


		float _penalty = Penalty( &_minimumTTCActor->GetPosition()  , _candidate , 1.0f ) ;
		for( unsigned int i=0; i < _candidateVectors.size(); i++)
		{
 
			float _minimumPenaltyAmongActors = Penalty( &_minimumTTCActor->GetPosition()  , _candidateVectors.at(i) , 1.0f ) ;
			if( _penalty > _minimumPenaltyAmongActors )
			{
				if(  _minimumPenaltyAmongActors <  _penalty )
				{ 
					_candidate= _candidateVectors.at(i) ;
					_penalty=_minimumPenaltyAmongActors;
				} 
			}
		}
		osg::Vec3 * _terrainMinimumCollision = NULL;
		if( _terrainCollisions.size() > 0 )
		{
			_terrainMinimumCollision = _terrainCollisions.at(0);
		}
		if( _terrainMinimumCollision != NULL )
		{
			for( unsigned int j = 0 ; j < _candidateVectors.size() ; j++ )
			{
				float _minimumPenaltyAmongCollisionPoints = Penalty( _terrainMinimumCollision , _candidateVectors.at(j) , 1.0f ) ;
				if( _minimumPenaltyAmongCollisionPoints < _penalty )
				{
					_candidate=_candidateVectors.at(j) ;
					_penalty = _minimumPenaltyAmongCollisionPoints;
					//printf("Choosing terrain penalty \n");
				}
			}
		}
	}
	return _candidate;
}
 

//generates a psuedo-random float between 0.0 and 0.999... 
float HappySphereActor::randfloat() 
{ 
	srand(time(NULL) );
    return rand()/(float(RAND_MAX)+1); 
} 

//generates a psuedo-random float between 0.0 and max 
float HappySphereActor::randfloat(float max) 
{ 
    return randfloat()*max; 
} 

//generates a psuedo-random float between min and max 
float HappySphereActor::randfloat(float min, float max) 
{ 
    if (min>max) 
    { 
        return randfloat()*(min-max)+max;     
    } 
    else 
    { 
        return randfloat()*(max-min)+min; 
    }     
}
//True if the candidate vector is valid and false otherwise
bool HappySphereActor::ValidCandidateVelocityVector( osg::Vec3 * _candidateVector )
{
	return _candidateVector->length() <= _MAXIMUM_SPEED  && _candidateVector->length() >= 0.0f;  //Left out acceleration for now -- we will add that one later ....
}
//Generates the happy sphere actor's candidate vectors.
std::vector<osg::Vec3 *> HappySphereActor::GenerateCandidateVectors(std::vector<dtCore::Physical *>  _actors , std::vector<osg::Vec3 *> _terrainCollisions, osg::Vec3 * _vPref  )
{
	//printf("GenerateCandidateVectors\n");
	 std::vector<osg::Vec3 *> _candidateVectors;
	 osg::Vec3 *  _currentVelocity = CurrentVelocity();
	 float _vDT = _currentVelocity->length() * _COLLISION_TIME_STEP;
	 for( unsigned int i = 0 ; i < 10  ; i++ )
	 {
		srand( time(NULL) );
		float _scalar = dtUtil::RandFloat(0.0001f, _vDT ); //;randfloat( 0.001 , _vDT );
		 osg::Vec3 * _wVector = new osg::Vec3( _scalar * dtUtil::RandFloat(-_vDT, _vDT ) ,_scalar*  dtUtil::RandFloat(-_vDT, _vDT ) , 0.0f )   ;
		// _wVector->normalize();
		 
		 //*(_wVector) = *(_wVector) * _scalar;

		 osg::Vec3 * _candidate =  new osg::Vec3( _wVector->x() + _currentVelocity->x() , _wVector->y() + _currentVelocity->y() , _wVector->z() + _currentVelocity->z() ) ;
		 osg::Vec3 _difference = *(_candidate) - *(_currentVelocity) ;
		// if( _difference.length() < (_MAXIMUM_ACCELERATION*mDeltaSimTime) && _candidate->length() < _MAXIMUM_SPEED )
		// {
		 if(_candidate->length() > 1.9f && _candidate->length() < _MAXIMUM_SPEED )
		 {
			  _candidateVectors.push_back(_candidate);
		 }
			 // _candidateVectors.push_back(_wVector);
		// }
		 //printf(" Difference in candidate and current length is %f - mDeltasimTime * VelocityMax is %f\n" , _difference.length() , (5.0f*mDeltaSimTime) );

	 }

//	 float _twoPi = osg::PI * 2.0f;/
//	for( unsigned short int i = 0 ; i < _actors.size() ; i++ )
//	{
//			_candidateVectors.push_back( new osg::Vec3( (((*CurrentVelocity()*2.0f)+ (*_actors.at(i)->CurrentVelocity())) * 0.5f) ) );
//	}
//	 osg::Vec3 * _currentVelocity = CurrentVelocity();
//	 osg::Vec3 _s =  _MAXIMUM_ACCELERATION;
//		for( unsigned short int i = 0 ; i < 10 ; i ++ )
//		{
	//		osg::Vec3 _candidate = ( ( _currentVelocity *( _s * cos(_twoPi / 10.0 ) * i ))  + ( ( 1.0/_currentVelocity) * (_s *(sin(_twoPi / 10.0 ) * i ) )  ) );
//			_candidateVectors.push_back(new osg::Vec3( _currentVelocity->x()+_candidate.x(), _currentVelocity.->()+_candidate.y(), _currentVelocity->z()+_candidate.z() );
//		}
//		for( unsigned int j = 0 ; j < _candidateVectors.size() ; j++ )
//		{
//			
//			printf(" Candidate is %f,%f,%f\n" , _candidateVectors.at(j)->x(),_candidateVectors.at(j)->y(),_candidateVectors.at(j)->z() );
//		}
	 return _candidateVectors;
}
const dtAI::Waypoint * HappySphereActor::CurrentWaypoint()
{
	return mCurrentWaypoint;
}
///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::OnTickRemote(const dtGame::TickMessage& tickMessage)
{
	mDeltaSimTime = tickMessage.GetDeltaSimTime();
	GenericActor::OnTickRemote(tickMessage);
}

///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::ProcessMessage(const dtGame::Message& message)
{
	
	//if (message.GetMessageType() == dtGame::MessageType::INFO_GAME_EVENT)
	//{
		//const dtGame::GameEventMessage& eventMsg = static_cast<const dtGame::GameEventMessage&>(message);

		// Note, we are using strings which aren't constants.  In a real application, these
		// event names should be stored in some sort of shared place and should be constants...
		/*
		if (eventMsg.GetGameEvent() != NULL)
		{
			// Handle "ToggleEngine" Game Event
			if (eventMsg.GetGameEvent()->GetName() == "Ignition" && mIgnitionTimer > 1.0f)
			{
				mIsEngineRunning = !mIsEngineRunning;
				#ifdef _DEBUG
					printf("Toggling Engines to the [%s] state.\r\n", (mIsEngineRunning ? "ON" : "OFF"));
				#endif //_DEBUG

				mIgnitionTimer = 0.0f;
			}
			
		}*/
	//}
	GenericActor::ProcessMessage(message);
}
///////////////////////////////////////////////////////////////////////////////
void HappySphereActor::OnEnteredWorld()
{
	GenericActor::OnEnteredWorld();

	mRayCastTime = dtUtil::RandFloat(0.0f, 2.0f);

	mCastRay = new dtCore::Isector(&(GetGameActorProxy().GetGameManager()->GetScene()));

	CollisionConeActor * CollisionCone = new CollisionConeActor(mVisibleColVol);
	CollisionCone->SetName(CollisionConeActor::ACTOR_DEFAULT_NAME);
	AddChild(CollisionCone);

	std::cout	<< GetUniqueId() << ";" << GetName() 
				<< "\n" << CollisionCone->GetUniqueId() << ";" << CollisionCone->GetName()
				<< std::endl;
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
HappySphereActorProxy::HappySphereActorProxy()
{
   SetClassName("Happy Sphere Actor"); //Set the actors Class Name  
}

///////////////////////////////////////////////////////////////////////////////
void HappySphereActorProxy::BuildPropertyMap()
{
	const std::string Actor_GROUP = "HappySphere Properties"; //Property group name

	//dtDAL::ActorProxy::BuildPropertyMap();
	//TransformableActorProxy::BuildPropertyMap();
	//dtDAL::PhysicalActorProxy::BuildPropertyMap();
	//dtGame::GameActorProxy::BuildPropertyMap();
	dtActors::GameMeshActorProxy::BuildPropertyMap();
	//GenericActorProxy::BuildPropertyMap();

	HappySphereActor* actor = static_cast<HappySphereActor*>(GetActor());

	// "Speed" property
	AddProperty(new dtDAL::FloatActorProperty("Speed","Actors Speed",
		dtDAL::FloatActorProperty::SetFuncType(actor, &HappySphereActor::SetSpeed),
		dtDAL::FloatActorProperty::GetFuncType(actor, &HappySphereActor::GetSpeed),
		"Sets The Movement Speed", Actor_GROUP));

	// "ColVolVisibility" property
	AddProperty(new dtDAL::BooleanActorProperty("ColVolVisibility","Collision Volume Visible",
		dtDAL::BooleanActorProperty::SetFuncType(actor, &HappySphereActor::SetColVolVisibility),
		dtDAL::BooleanActorProperty::GetFuncType(actor, &HappySphereActor::GetColVolVisibility),
		"Sets Collision Volume Visibility for Debugging", Actor_GROUP));
 
	// "PathShortEnabled" property
	AddProperty(new dtDAL::BooleanActorProperty("PathShortEnabled","Enable Path Shortening",
		dtDAL::BooleanActorProperty::SetFuncType(actor, &HappySphereActor::SetPathShortEnabled),
		dtDAL::BooleanActorProperty::GetFuncType(actor, &HappySphereActor::GetPathShortEnabled),
		"Enable/Disable path shortening alg", Actor_GROUP));


	// Check if "static mesh" property exist.....
	dtDAL::ResourceActorProperty* resourceProperty;
	GetProperty("static mesh", resourceProperty);
	assert(resourceProperty);

	// Automatically default the mesh to the one we want
	const dtDAL::ResourceDescriptor meshDescriptor("StaticMeshes:Misc:HappySphere.ive");
	resourceProperty->SetValue(meshDescriptor);
   
}
///////////////////////////////////////////////////////////////////////////////
void HappySphereActorProxy::CreateActor()
{
   SetActor(*new HappySphereActor(*this));
}

///////////////////////////////////////////////////////////////////////////////
void HappySphereActorProxy::OnEnteredWorld()
{
   dtActors::GameMeshActorProxy::OnEnteredWorld();
}

#endif //VRS_HAPPY_SPHERE_ACTOR_CPP