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


#ifndef UFVG_COMPONENT_H
#define UFVG_COMPONENT_H

#include "export.h"

#include "vrsUFVGActorsRegistry.h"
#include "ActorUFVGnetCDF.h"
#include "UFVGKDTree.h"

#include "..\\..\\vrsUtil_dll\Include\vrsMath.h"
#include "..\\..\\vrsCore_dll\Include\ActorGeneric.h"
#include "..\\..\\vrsCore_dll\Include\ActorPagedTerrain.h"
#include "..\\..\\vrsCore_dll\Include\vrsCoreMsgTypes.h"
#include "..\\..\\vrsCore_dll\Include\vrsCoreActorsRegistry.h"

#include <iostream>
#include <fstream>
#include <sstream>

//#include <dtCore/refptr.h>
#include <dtCore/system.h>
//#include <dtCore/shadermanager.h>

//#include <dtUtil/coordinates.h>


#include <dtABC/application.h>

#include <dtDAL/enginepropertytypes.h>
#include <dtDAL/gameevent.h>
#include <dtDAL/gameeventmanager.h>

#include <dtGame/baseinputcomponent.h>
//#include <dtGame/logcontroller.h>
#include <dtGame/basemessages.h>
#include <dtGame/messagetype.h>
#include <dtGame/gamemanager.h>

#include <osg/Ref_Ptr>



//#include <osgViewer/CompositeViewer>

/**
 * 
 * UFVGComponent does something.......
 * 
 */
namespace vrsUFVG
{
	class VRS_UFVG_EXPORT UFVGComponent : public dtGame::GMComponent
	{
	public:

		//Default Component Name
		static const std::string COMPONENT_DEFAULT_NAME;

		
		//Timer Names
		static const std::string UPDATE_TIMER_NAME;

		// Constructor
		UFVGComponent(const std::string& name);

		/**
		* Setup our custom GameEvents after the map is loaded
		* They will be sent out by the controller
		*/
		void SetupEvents();

		/**
		* Handle messages from the GameManager if we want to
		*/
		void ProcessMessage(const dtGame::Message& message);
			
		/**
		* Handle messages from the dtCore::Base if we want to
		*/
		virtual void OnMessage(MessageData *data);

	protected:

		/// Destructor
		virtual ~UFVGComponent(); 
	private:
		
		//Set up all the UFVG display options and positions
		void SetupDisplay(void);

		//Set up the KD tree and creste the nodes from the index file
		void SetupKDTree(void);
			
		/**
		* This method creates the game event
		* message and sends it on to the Game Manager for processing.
		* @param event The game event to fire.
		*/
   		//void FireGameEvent(const dtDAL::GameEvent& event);

		//Our LogController
		//dtCore::RefPtr<dtGame::LogController> mLogController;

		//Our pointer for shooting off messages
		//dtCore::RefPtr<dtGame::GameEventMessage> eventMsg;

		//float StatisticsTimer;

		//out coordinates converter....
		//dtUtil::Coordinates mCoord;

		float mDeltaSimTime;
		float mSimTime;
		float mLastSimTime;

		//bool mInPlaybackMode;
		float mTimer;

		//Pointer to Player Actor and Focus Actor
		osg::ref_ptr<vrsCore::GenericActor> mPlayerActor;
		osg::ref_ptr<vrsCore::GenericActor> mFocusActor;

		//IDs for Player Actor and Focus Actor
		dtCore::UniqueId					mFocusActorID;
		dtCore::UniqueId					mPlayerActorID;

		
		//UFVG Actor Pointer
		osg::ref_ptr<vrsUFVG::UFVGnetCDFActor> mUFVGActor;

		//Paged Terrain Actor Pointer
		osg::ref_ptr<vrsCore::PagedTerrainActor> mPagedTerrainActor;

		 

		struct ColumnData
		{
			int xPos;				//Hold the X Position of the column in the NetCDF file
			int yPos;				//Hold the Y Position of the column in the NetCDF file
			float LatVal;			//Hold the Lat Position of the column in the NetCDF file
			float LonVal;			//Hold the Lon Position of the column in the NetCDF file
			float xUTM;				//Hold the UTM x Position of the column in the NetCDF file
			float yUTM;				//Hold the UTM y Position of the column in the NetCDF file
		};
		std::vector<ColumnData> mColumnIndex;

		int mCurColumnID;			//Holds the ID of the closest column to the player

		ColumnKDTree* mTree;		//KD tree to hold the NetCDF Column positional data

		//osg::ref_ptr<dtUtil::kdtree>

	};
}

#endif //UFVG_COMPONENT_H

