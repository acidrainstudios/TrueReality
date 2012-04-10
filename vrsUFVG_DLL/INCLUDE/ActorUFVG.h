/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* Virtual Reality Simulation Lab
*
* This file is part of Virtual Reality Simulation Lab software; you can redistribute 
* it and/or modify it under the terms of the GNU Lesser General Public License as 
* published by the Free Software Foundation; either version 2.1 of the License, or 
* (at your option) any later version.
*
* By the GNU LGP License any changes or modification you made must be sent back 
* to the original owner of the file, and appropriate credit given.
*
* This file is distributed WITHOUT ANY WARRANTY; without even the implied warranty 
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General 
* Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* This software was developed by Maxim Serebrennik for various projects he worked on. 
* For more information e-mail him at MaximSter@gmail.com
*
* @author Maxim Serebrennik
*////////////////////////////////////////////////////////////////////////////////


#ifndef VRS_UFVG_ACTOR_H
#define VRS_UFVG_ACTOR_H

#include "export.h"
#include "UFVGReader.h"
#include "..\\..\\vrsCore_DLL\Include\ActorGameStaticMesh.h"

#include <iostream>

//#include <dtActors/gamemeshactor.h>

#include <dtUtil/datapathutils.h>

#include <dtCore/refptr.h>
#include <dtCore/particlesystem.h>
#include <dtCore/transform.h>
#include <dtCore/object.h>

#include <dtGame/basemessages.h>
#include <dtGame/gamemanager.h>
#include <dtGame/messagetype.h>
#include <dtGame/message.h>

#include <dtDAL/actorproxyicon.h>
#include <dtDAL/enginepropertytypes.h>


namespace vrsUFVG
{
	const int	MaxNumberOfParticles = 30;	//Set the maximum number of particles possible...

	class VRS_UFVG_EXPORT UFVGActor : public vrsCore::GameStaticMeshActor
	{
	public:

		//Default Actors Name
		static const std::string ACTOR_DEFAULT_NAME;

		/// Constructor
		UFVGActor(vrsCore::GameStaticMeshActorProxy& proxy);

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
		void HandleGameEvent(const dtGame::Message& msg);

		// Called when the actor has been added to the game manager.
		// You can respond to OnEnteredWorld on either the proxy or actor or both.
		virtual void OnEnteredWorld();

		//Speed with which each record is played back 5 is 5 times a second
		void SetPlaybackSpeed(float Speed);
		//Speed with which each record is played back 5 is 5 times a second
		float GetPlaybackSpeed(void);

		//Load Data File
		void SetDataFile(std::string FileName);
		//Load Data File
		std::string GetDataFile(void);

		//Load Geometry File
		void SetGeomFile(std::string FileName);
		//Load Geometry File
		std::string GetGeomFile(void);

		
	protected:

		// Destructor
		virtual ~UFVGActor() { } ;

	private:

		// private vars
		dtCore::RefPtr<dtCore::Object> mBubbles[MaxNumberOfParticles];

		float	mDeltaSimTime;			//sim time between frames
		
		int		mRecordNum;				//Record Number that is currently being read
		float	mPlaybackSpeed;			//Speed with which each record is played back 5 is 5 times a second
		float   mPlaybackTimer;			//Timer for playback

		std::string mDataFileName;		//Data File Path and Name
		std::string mGeomFileName;		//Geometry File Path and Name

		bool	mPropertiesUpdated;		//set to true if a property changed....

		UFVGReader mDataReader;

	};


	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	class VRS_UFVG_EXPORT UFVGActorProxy : public vrsCore::GameStaticMeshActorProxy
	{
	public:

		/**
		* Constructor
		*/
		UFVGActorProxy();

		// Creates the properties that are custom to the actor proxy.
		  virtual void BuildPropertyMap();



	protected:

		/**
		* Destructor
		*/
		virtual ~UFVGActorProxy() { }

		// Creates an instance of our actor
		virtual void CreateActor();

		// Called when this proxy is added to the game manager (ie, the "world")
		// You can respond to OnEnteredWorld on either the proxy or actor or both.
		virtual void OnEnteredWorld();

	private:


	};
}

#endif //VRS_UFVG_ACTOR_H
