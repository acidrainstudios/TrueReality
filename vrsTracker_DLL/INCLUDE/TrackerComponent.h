/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* CS900 DLL Stevens Institute of Technology Camera Tracker Project
*
* CopyRight © The Stevens Institute of Technology 2010
*
* @author CS900 Project:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////


#ifndef VRS_TRACKER_COMPONENT_H
#define VRS_TRACKER_COMPONENT_H

#include "ActorTracker.h"
#include "export.h"
#include "utils.h"

#include <iostream>
#include <fstream>

#include <dtCore/refptr.h>
#include <dtCore/system.h>
#include <dtCore/shadermanager.h>
#include <dtUtil/coordinates.h>

#include <dtABC/application.h>

#include <dtDAL/enginepropertytypes.h>
#include <dtDAL/gameevent.h>
#include <dtDAL/gameeventmanager.h>


#include <dtGame/baseinputcomponent.h>
#include <dtGame/logcontroller.h>
#include <dtGame/basemessages.h>
#include <dtGame/messagetype.h>
#include <dtGame/gamemanager.h>
#include <dtActors/CoordinateConfigActor.h>	

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>


/**
 * 
 * TrackerComponent does something.......
 * 
 */

//data in an event from event log
#define POSITION_DELIM ','
#define PATH_ID 0
#define PATH_X_COOR 2
#define PATH_Y_COOR 3
#define PATH_WIDTH 4
#define PATH_HEIGHT 5
#define PATH_X_UTM 9//3
#define PATH_Y_UTM 8//4
#define PATH_TIME 10//5
#define PATH_TYPE 11//5
#define PATH_CLASSNAME 12

class VRS_TRACKER_EXPORT TrackerComponent : public dtGame::GMComponent
{
public:

	//Default Component Name
	static const std::string COMPONENT_DEFAULT_NAME;

    // Constructor
	TrackerComponent(const std::string& name);

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

	//struct to store events from tracker event log
	struct evt{
		int id;			//tracker id
		osg::Vec3f pos;	//utm position
		float time;		//time
		int type;		//boat type
		float realtime;
		std::string classname;
	};
	typedef std::map<int,evt> evtMap;	//store a list of events
	typedef std::map<std::string,std::string> mapType;  //stores mapping of class names to prototype names


protected:

      /// Destructor
	virtual ~TrackerComponent() { }

private:

	float mDeltaSimTime;
	float mSimTime;
	float mLastSimTime;
	
	
	int fpos;  //event_log file position
	std::string fname;  //event_log path
	evtMap newevents;	//list of new tracker events
	float mSubSampleRate;  //how often to parse event log file
	float mKillTime;	//how long until remove actor
	int mAvgWindowSize;	//how long until update actor (and how much smoothing to do)
	mapType mShipTypes;	//map of class numbers to prototype names
	osg::Vec3f mOrigin;	//origin of the "world" (boats UTMs are relative to this)
	std::vector<TrackerActor*> mBabyVector;

	void MakeBaby(evt);				//create new actor
	bool ReadNewData(std::string);	//read new data from event log
	void UpdateBabies();			//update the actors' positions based on newevents
	void KillBabies();				//remove actors who are too old
	bool ParsePosition(const std::string &);	//parse the event log file

};

#endif //VRS_TRACKER_COMPONENT_H

