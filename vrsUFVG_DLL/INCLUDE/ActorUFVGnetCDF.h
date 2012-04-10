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


#ifndef VRS_UFVG_NETCDF_ACTOR_H
#define VRS_UFVG_NETCDF_ACTOR_H

#include "export.h"
#include "NetCDFReader.h"

#include "..\\..\\vrsCore_DLL\Include\vrsCoreEnum.h"
#include "..\\..\\vrsCore_DLL\Include\ActorGameStaticMesh.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include <dtABC/application.h>

#include <dtUtil/datapathutils.h>

#include <dtCore/transform.h>
#include <dtCore/object.h>

#include <dtGame/basemessages.h>
#include <dtGame/gamemanager.h>
#include <dtGame/gameactor.h>
#include <dtGame/messagetype.h>
#include <dtGame/message.h>

#include <dtDAL/actorproxyicon.h>
#include <dtDAL/enginepropertytypes.h>

#include <dtUtil/functor.h>

namespace vrsUFVG
{
	class VRS_UFVG_EXPORT UFVGnetCDFActor : public vrsCore::GameStaticMeshActor
	{
	public:

		//Default Actors Name
		static const std::string ACTOR_DEFAULT_NAME;

		// Constructor
		UFVGnetCDFActor(vrsCore::GameStaticMeshActorProxy& proxy);

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
		
		virtual void AddedToScene(dtCore::Scene* scene);
		
		//Reposition the Geometry and reread the data files
		void Reload(void);

		//Speed with which each record is played back 5 is 5 times a second
		void SetPlaybackSpeed(float Speed);
		//Speed with which each record is played back 5 is 5 times a second
		float GetPlaybackSpeed(void);

		//X Position to read....
		void SetXPosition(int X);
		//X Position to read....
		int GetXPosition(void);

		//Y Position to read....
		void SetYPosition(int Y);
		//Y Position to read....
		int GetYPosition(void);

		//Load Data File
		void SetDataFile(const std::string& FileName);
		//Load Data File
		std::string GetDataFile(void);

		//Load Direction Geometry File
		void SetDirGeomFile(const std::string& FileName);
		//Load Direction Geometry File
		std::string GetDirGeomFile(void);

		//Load Speed Marker Geometry File
		void SetSpdGeomFile(const std::string& FileName);
		//Load Speed Marker Geometry File
		std::string GetSpdGeomFile(void);

		//Load Compass Geometry File
		void SetComGeomFile(const std::string& FileName);
		//Load Compass Geometry File
		std::string GetComGeomFile(void);


	protected:

		// Destructor
		virtual ~UFVGnetCDFActor() { } ;

	private:

		// private functions

		void ReadData(void);		//reads in the .UFVG file
		void ReadIndex(void);		//reads in the .UFVG index file
		void InitGeom(void);		//reads in the geometry models and places them in the right positions
		void UpdateVectors(float DeltaSimTime);	//Updates the Vectors for UFVG

		// private vars

		std::vector<float> mSigmas;  //Vector to hold sigma values

		struct SigmaData
		{
			float Speed;					//Sea Water Speed (m/sec)
			float Angle;					//Sea Water Direction Angle (Degrees)

		};

		struct DataColumn
		{
			double	Date_Time;							//Date_Time YYYYMMDDHHmm
			
			std::vector<SigmaData> SigmaLayers;	//Sigma Layerd Data

		};

		std::vector<DataColumn> mData;  //Vector to hold file data

		int mXMax;						//Max X Positions
		int mYMax;						//Max Y Positions

		int mXCur;						//X Position to Read
		int mYCur;						//Y Position to Read

		int	mRecordNum;					//Record Number that is currently being read
		int mTotalRecordNum;			//Total # of Records

		int mNumOfSig;					//Total Number of Sigmas

		float	mColumnDepth;			//Heihgt of the particle columb
		
										//holds all the vector generators....
		std::vector<osg::ref_ptr<dtCore::Object>> mDirectionMark;
		std::vector<osg::ref_ptr<dtCore::Object>> mSpeedMark;
		
										//hold the geometry for the compass
		osg::ref_ptr<dtCore::Object> mCompass;

		float	mDeltaSimTime;			//sim time between frames


		float	mPlaybackSpeed;			//Speed with which each record is played back 5 is 5 times a second
		float   mPlaybackTimer;			//Timer for playback



		std::string mDataFilePath;		//Data File Path
		std::string mGeomDirFileName;	//Geometry File Path and Name
		std::string mGeomSpdFileName;	//Geometry File Path and Name
		std::string mGeomComFileName;	//Geometry File Path and Name

		//value scales
		//float mElevScale;				//sea_surface_height_above_sea_level
		//float mWuScale;					//EW Wind Comp
		//float mWvScale;					//NS Wind Comp
		//float mPatmScale;				//Atmospheric pressure
		//float mAirtScale;				//2m-above-surface Air Temperature
		//float mRhumScale;				//2m-above-surface Relative Humidity
		//float mWhScale;					//wave heights
		//float mWpScale;					//wave periods
		//float mWdScale;					//Significant Wave Direction in Meteorologic Convention
		//float mUScale;					//sea_water_x_velocity
		//float mVScale;					//sea_water_y_velocity
		float mSpeedScale;					//sea_water_velocity
		//float mSaltScale;				//sea_water_salinity
		//float mTempScale;				//Water Temperature

		bool	mPropertiesUpdated;		//set to true if a property changed....

		//NetCDFReader mDataReader;

	};


	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	class VRS_UFVG_EXPORT UFVGnetCDFActorProxy : public vrsCore::GameStaticMeshActorProxy
	{
	public:

		/**
		* Constructor
		*/
		UFVGnetCDFActorProxy();

		// Creates the properties that are custom to the actor proxy.
		  virtual void BuildPropertyMap();



	protected:

		/**
		* Destructor
		*/
		virtual ~UFVGnetCDFActorProxy() { }

		// Creates an instance of our actor
		virtual void CreateActor();

		// Called when this proxy is added to the game manager (ie, the "world")
		// You can respond to OnEnteredWorld on either the proxy or actor or both.
		virtual void OnEnteredWorld();

	private:

	};
}

#endif //VRS_UFVG_NETCDF_ACTOR_H
