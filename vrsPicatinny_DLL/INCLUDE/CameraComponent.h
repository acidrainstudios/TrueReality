/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* CS900 DLL Stevens Institute of Technology Picatinny Arsenal Demo Project
*
* CopyRight © The Stevens Institute of Technology 2010
*
* @author CS900 Project:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////


#ifndef VRS_PICATINNY_COMPONENT_H
#define VRS_PICATINNY_COMPONENT_H

#include "export.h"
#include "vrsPicatinnyActorsRegistry.h"
#include "ActorPicaCamera.h"

#include "..\\..\\vrsCore_DLL\include\vrsCoreGameEvents.h"

#include <iostream>

#include <dtCore/refptr.h>
#include <dtCore/system.h>
#include <dtCore/shadermanager.h>
#include <dtCore/DeltaWin.h>

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

#include <osgViewer/GraphicsWindow>
#include <osgViewer/View>

/**
 * 
 * CameraComponent does something.......
 * 
 */
class VRS_PICATINNY_EXPORT CameraComponent : public dtGame::GMComponent
{
public:

	//Default Component Name
	static const std::string COMPONENT_DEFAULT_NAME;

	//Timer Names
	static const std::string MONITOR2_TIMER_NAME;

    // Constructor
	CameraComponent(const std::string& name);

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

	/**
    * Called when the Component is added to the GM
    */
	virtual void OnAddedToGM();

	//Set the size of the monitor window
	void SetMonitor0Size(osg::Vec2f size);

	//Get the size of the monitor window
	osg::Vec2f GetMonitor0Size(void) const {return mMon0Size;}

	//Set the monitors position on the screen
	void SetMonitor0ScreenPosition(osg::Vec2f pos);

	//Get the monitors position on the screen
	osg::Vec2f GetMonitor0ScreenPosition(void) const {return mMon0ScrPos;}

	//Finds a camera by name and sets it to the Given Monitor 
	void SetCameraOnMonitor0ByName(std::string CamName = "NONE");

	

protected:

      /// Destructor
	virtual ~CameraComponent() { }

private:

	//PRIVATE Func

	/**
    * Creates camera monitors and links them to the cameras in the scene
    */
	void SetupCamMonitors(void);

	/**
    * Cycle Cameras on Monitor1
    */
	void CycleMon0Cam(void);
	/**
    * Cycle Cameras on Monitor2
    */
	void CycleMon1Cam(void);
	/**
    * Cycle Cameras on Monitor3
    */
	void CycleMon2Cam(void);

	//PRIVATE VARS

	float mDeltaSimTime;
	float mSimTime;
	float mLastSimTime;

									//vector of camera actor and view pointers
	std::vector<PicaCameraActor*>	mCameraAct;
	std::vector<dtCore::View*>		mViews;
									//holds the number of the cameras being displayed
	osg::Vec3f						mMonCamLink;
									//Toggle Manual Camera Setting
	bool							mManualSetCam;
	std::string						mCamNameToFind;

	//Monitor size and positions on the screen
	osg::Vec2f						mMon0Size;
	osg::Vec2f						mMon0ScrPos;
	osg::Vec2f						mMon1Size;
	osg::Vec2f						mMon1ScrPos;							
	osg::Vec2f						mMon2Size;
	osg::Vec2f						mMon2ScrPos;

};

#endif //VRS_PICATINNY_COMPONENT_H

