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


#ifndef VRS_HAPPY_SPHERE_ACTOR_H
#define VRS_HAPPY_SPHERE_ACTOR_H

#include "export.h"

#include "CollisionConeActor.h"
#include "..\\..\\vrsCore_DLL\Include\ActorGeneric.h"

#include <dtAI/waypointinterface.h>
#include <dtAI/astarwaypointutils.h>

static float _COLLISION_TIME_STEP = 0.01f;

static unsigned short int _UNIQUE_ID = 1; 

static const float _PREFERRED_SPEED = 15.0f;

//Const to define the maximum speed of a happy sphere actor.
static const float _MAXIMUM_SPEED = 20.0f;

//Const to define the maximum acceleration of a happy sphere actor.
static const float _MAXIMUM_ACCELERATION = 5.0f;

//Default aggressiveness 
static const float _DEFAULT_AGGRESSIVENESS = 0.5;

static const float _TIME_TO_COLLISION_UNDEFINED_POSITIVE = 10000000000.0f;

static const float _TIME_TO_COLLISION_UNDEFINED_NEGATIVE = -10000000000.0f;

static const float _180_OVER_PI = 180.0f/osg::PI;

static const float _WAYPOINT_TOLERANCE = 3.5f;
class VRS_CS586_EXPORT HappySphereActor : public vrsCore::GenericActor
{
public:

	//Default Actors Name
	static const std::string ACTOR_DEFAULT_NAME;

	/// Constructor
	HappySphereActor(vrsCore::GenericActorProxy& proxy);

	/**
	* Set the movement speed in (m/sec)
	*/
	void SetSpeed(float speed);

	/**
	* Get the movement speed in (m/sec)
	*/
	float GetSpeed(void) const {return mSpeed;}

	/**
	* Turn the actor to the Right in (deg/sec)
	* for # of seconds
	*/
	void TurnRight(float speed, float time);
	
	/**
	* Turn the actor to the Left in (deg/sec)
	* for # of seconds
	*/
	void TurnLeft(float speed, float time);

	//temp none animating turn right function
	void TurnRight(float Degrees);

	//temp none animating turn left function
	void TurnLeft(float Degrees);
	
	//Performst the TurnToWaypoint code
	 void TurnToWaypoint();
	//Set the first and last way points of path to travel
	void SetPath(dtAI::Waypoint* Start, dtAI::Waypoint* End);

	//Places the actor around path the starting location
	void JumpToPathStart(void);

	/*
	*  Make the Collision Cone Visible
	*/
	void SetColVolVisibility(bool Visible);
	/*
	*  Check if the Collision Cone is Visible
	*/
	bool GetColVolVisibility(void) const {return mVisibleColVol;}

	/*
	*  Enable the Path Shortening Algorithm
	*/
	void SetPathShortEnabled(bool Enabled);
	/*
	*  See if the Path Shortening Algorithm is Enabled
	*/
	bool GetPathShortEnabled(void) const {return mPathShortEnabled;}
	
	/**
	* This method is an invokable for when a local object receives a tick.
	* @param tickMessage A message containing tick related information.
	*/
	virtual void OnTickLocal(const dtGame::TickMessage& tickMessage);

	/**
	* This method is an invokable for when a remote object receives a tick.
	* @param tickMessage A message containing tick related information.
	*/
	virtual void OnTickRemote(const dtGame::TickMessage& tickMessage);

	/**
	* Generic handler (Invokable) for messages. Overridden from base class.
	* This is the default invokable on GameActorProxy.
	*/
	virtual void ProcessMessage(const dtGame::Message& message);

	/**
    * This is a method called by the game event invokable when a game
    * event message is passed through the game manager.
    * @param msg The message containing the game event.
    */
    //void HandleGameEvent(const dtGame::Message& msg);

    // Called when the actor has been added to the game manager.
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();
	//Returns the current Velocity Vector
	virtual osg::Vec3 * CurrentVelocity();
	//Calculates the Preferred Velocity Vector to the Current Waypoint
	virtual osg::Vec3 * PreferredVelocity(const dtAI::Waypoint * _waypoint);	
	

protected:
	float randfloat();
	float randfloat(float max);
	float randfloat(float min, float max) ;
	//Based upon the new candidate vector -  a new orientation is chosen.
	virtual void HappySphereActor::AvoidCollision(const float _newOrientation);
	//Updates the actor's orientation and speed based upon the candidate velocity vector.
	virtual void update(osg::Vec3 * _candidateVelocityVector);
	//True if the candidate vector is valid and false otherwise
	virtual bool ValidCandidateVelocityVector( osg::Vec3 * _candidateVector );
	//Takes the candidates for collision and determines the only valid candidate HappySphereActor *
	virtual std::vector<dtCore::Physical *> CandidateCollisionActors(std::set<dtCore::Physical *> _possibleCollisions );
	virtual std::vector<osg::Vec3 *> CandidateCollisionActors(std::vector<osg::Vec3 *> _terrainCollisions );
	//Returns the time to collision for a happy sphere actor.
	virtual float  TimeToCollision(osg::Vec3 * _actorPosition, osg::Vec3 * _collisionVector, float _actorRadius);
	//Overloaded 
	//Returns Penalty for Candidate Vector
	virtual float Penalty(osg::Vec3 * _actorPosition, osg::Vec3 * _candidateVector, float _actorRadius );
	//virtual float Penalty(HappySphereActor * _actor , osg::Vec3 * _candidateVector, float _actorRadius );
	//Chooses penalty 
	virtual osg::Vec3 * ChoosePenaltyVector(std::vector<osg::Vec3 *> _candidateVectors , std::vector<dtCore::Physical *> _actorPositions, std::vector<osg::Vec3 *> _terrainCollisions );
	//Chooses the candidate vectors out of all candidate vectors.  
	//If there is a vector with time to collision < 0 - choose the vector closest to current velocity vector, otherwise choose the vector with lowest penalty.
	virtual osg::Vec3 * ChooseCandidateVector( std::vector<osg::Vec3 *> _candidateVectors, std::vector<dtCore::Physical *> _actors , std::vector<osg::Vec3 *> _terrainCollisions );
	//Returns the current waypoint goal
	virtual const dtAI::Waypoint * CurrentWaypoint();
	//Generates the happy sphere actor's candidate vectors.
	virtual std::vector<osg::Vec3 *> GenerateCandidateVectors(std::vector<dtCore::Physical *>  _actors , std::vector<osg::Vec3 *> _terrainCollisions, osg::Vec3 * _vPref );
	// Destructor
    virtual ~HappySphereActor() { } ;
	/**
	*	This method returns a determinant of 2 Vec3 vectors.
	*	@param osg::Vec3 & _p to get first determinant of
	*	@param osg::Vec3 & _q to get second determint of.
	*	@return float of the determinant.
	*/
	inline float det(const osg::Vec3 & _p, const  osg::Vec3 &  _q) { return _p.x()*_q.y() - _p.y()*_q.x(); }
	/**
	*	Returns the X / Y DOT Product of the 2 vectors
	*   @param osg::Vec3 &  Vector
	*	@param osg::Vec3 &  Vector
	*	@reeturn float
	*/
	inline float dot( const osg::Vec3 & _p , const osg::Vec3 & _q ) { return _p.x()*_q.x() + _p.y()*_q.y(); }
private:
	// make sure our actor is leveled
	void HeightHack(float height);

	//Moves and turns the actor
	void MoveActor(float DeltaSimTime);

	//Detects object within the collision volume and adjusts actors path
	void AvoidCollision(void);

	/*
	*	Path finding algorithm:
	*   Finds the shortest path from the starting waypoint	
	*   to the ending waypoint	
	*/
	void FindPath(const dtAI::Waypoint* startWaypoint, const dtAI::Waypoint* endWaypoint);
	
	/*
	*	Paint Next Waypoint Blue
	*/
	void PaintNextWaypoint(void);
	
	/*
	*   Turns the actor to the correct direction at the angle 
	*   returned by the GetAngle function
	*/  	
	void TurnToWaypoint(const dtAI::Waypoint* Waypoint);

	/*
	*	Cast a ray from the actor to the next waypoint,
	*   and go to that waypoint if no collision is detected
	*/
	void ShortenPathToWaypoint();

	/*
	*	Returns true is actor is at the current waypoint;
	*	otherwise, returns false
	*/
	bool IsAtWaypoint(const dtAI::Waypoint* Waypoint);
	
	/*
	*    Returns true if the actor has reached the final waypoint
	*/	
	bool IsAtGoal();

    /*
    *	Returns the 2 dimensional calculation of distance between the 2 vectors.
    *	@param _vector1 const osg::Vec3  first vector 
    *	@param _vector2 const osg::Vec3  second vector
    */
	float Distance(const osg::Vec3 vector1, const osg::Vec3 vector2);

    /*
    *	Calculates distance between the actor and the specified waypoint.
    *	@param dtAI::Waypoint * the specified waypoint to calculate distance agains.
    *	@return const float specifying the distance between the actor and the specified waypoint.
    */
	float GetDistance(const dtAI::Waypoint* Waypoint);
	
	/*
	*   Calculates the angle between the actor and the waypoint
	*/	
	float GetAngle(const dtAI::Waypoint* Waypoint);
	//Angle to the actor
	float GetAngle( HappySphereActor * _actor);
	
	/*
	*  Get the actor's current position
	*/
	osg::Vec3 GetPosition();

	void SetPosition(osg::Vec3 _pos);
	
	/*
	*  Get the actor's current orientation
	*/	
	osg::Vec3 GetOrientation();

	const dtAI::Waypoint * mCurrentWaypoint;	//Current waypoint goal

	osg::Vec3 * mCurrentVelocityVector;			//Current Velocity Vector

	osg::Vec3 * mPreferredVelocityVector;		//Preferred Velocity Vector

	unsigned short int mUniqueId;

	float   mAggressiveRatio;					//Used in penalty calculation - calculates the aggressive tendency.

	float	mSpeed;								//movement speed

	float	mTurnRate;							//actors turn rate

	float	mTurnDirection;						//actors turn direction

	float	mTurnTimer;							//amount of time to turn

	float	mTimeToCollision;

	float	mCollisionTimer;					//Limits the collition reactions /sec

	float	mDeltaSimTime;						//sim time between local Ticks

	float	mRayCastTimer;						//limits the rays casted

	float	mRayCastTime;						//Time Between Raycasts

	bool	mPathShortEnabled;					//Enable or Disable the path shortening 


	
		
										//hold the way points for path to travel
	osg::ref_ptr<dtAI::Waypoint> mWayPointPath[2]; 

	bool	mPathSet;				//is the path set?

	bool	mVisibleColVol;			//Is the collision volume visible?

	osg::ref_ptr<dtCore::Isector> mCastRay;                 //casting ray to next waypoint

	dtAI::WaypointAStar::container_type mPathToWaypoint;	//container holding the path	

	dtAI::WaypointAStar mAStar;
};


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
class VRS_CS586_EXPORT HappySphereActorProxy : public vrsCore::GenericActorProxy
{
public:

	/**
    * Constructor
    */
    HappySphereActorProxy();

	// Creates the properties that are custom to the actor proxy.
      virtual void BuildPropertyMap();



protected:


	/**
    * Destructor
    */
    virtual ~HappySphereActorProxy() { }

	// Creates an instance of our actor
    virtual void CreateActor();

    // Called when this proxy is added to the game manager (ie, the "world")
    // You can respond to OnEnteredWorld on either the proxy or actor or both.
    virtual void OnEnteredWorld();

private:


};


#endif //VRS_HAPPY_SPHERE_ACTOR_H