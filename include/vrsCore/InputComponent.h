/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* Virtual Reality Simulation Lab
* 
* This file is part of Virtual Reality Simulation Lab software. You can redistribute 
* it and/or modify it only with the authors permission. All unlicensed use and modification
* of this file are prohibited. 
* 
* This does not restrict the user from creating custom modules and additional files to 
* interface with the VR-Sim Lab.
* 
* This software was developed by Maxim Serebrennik for Various projects he worked on.
* It is sold and distributed only with his permission. 
* 
* For more information e-mail him at MaximSter@gmail.com
* 
* @author Maxim Serebrennik 
*////////////////////////////////////////////////////////////////////////////////


#ifndef COREDLL_INPUT_COMPONENT_H
#define COREDLL_INPUT_COMPONENT_H

#include "export.h"
#include "vrsCoreMsgTypes.h"
#include "vrsCoreGameEvents.h"

#include <iostream>

#include <dtCore/refptr.h>
#include <dtCore/system.h>
#include <dtCore/shadermanager.h>


#include <dtABC/application.h>

#include <dtDAL/enginepropertytypes.h>
#include <dtDAL/gameevent.h>
#include <dtDAL/gameeventmanager.h>

#include <dtGame/baseinputcomponent.h>
#include <dtGame/logcontroller.h>
#include <dtGame/basemessages.h>
#include <dtGame/messagetype.h>

#include <osgViewer/CompositeViewer>

namespace vrsCore
{

	class CORE_EXPORT InputComponent : public dtGame::GMComponent
	{
	   public:

		   //Default Component Name
			static const std::string COMPONENT_DEFAULT_NAME;

		  // Constructor
		  InputComponent(const std::string& name, bool inPlaybackMode);

		  // Find our GameEvents after the map is loaded
		  void SetupEvents();

		  /**
		   * Handle messages if we want to
		   */
		  void ProcessMessage(const dtGame::Message& message);

		  virtual void OnMessage(MessageData *data);

		  //void SetFocusActor(dtCore::UniqueId& FocusActor);

		  // We're going to handle key presses!
		  //virtual bool HandleKeyPressed(const dtCore::Keyboard* keyboard, int key);

	   protected:

		  /// Destructor
		  virtual ~InputComponent() { }

	   private:
		  /**
		   * Simple helper method to fire a game event.  This method creates the game event
		   * message and sends it on to the Game Manager for processing.
		   * @param event The game event to fire.
		   */
		   
			void FireGameEvent(const dtDAL::GameEvent& event);


		  /**
		   * Some of out custom Game Events.....
		   */
			osg::ref_ptr<dtDAL::GameEvent> Ignition_Event;
			bool mSendIgnition;

			osg::ref_ptr<dtDAL::GameEvent> AutoLevel_Event;
			bool mSendAutoLevel;

			osg::ref_ptr<dtDAL::GameEvent> MoveForward_Event;
			osg::ref_ptr<dtDAL::GameEvent> MoveBack_Event;

			osg::ref_ptr<dtDAL::GameEvent> StrafeRight_Event;
			osg::ref_ptr<dtDAL::GameEvent> StrafeLeft_Event;
			osg::ref_ptr<dtDAL::GameEvent> StrafeUp_Event;
			osg::ref_ptr<dtDAL::GameEvent> StrafeDown_Event;

			osg::ref_ptr<dtDAL::GameEvent> YawLeft_Event;
			osg::ref_ptr<dtDAL::GameEvent> YawRight_Event;
			osg::ref_ptr<dtDAL::GameEvent> PitchUp_Event;
			osg::ref_ptr<dtDAL::GameEvent> PitchDown_Event;
			osg::ref_ptr<dtDAL::GameEvent> RollLeft_Event;
			osg::ref_ptr<dtDAL::GameEvent> RollRight_Event;

			osg::ref_ptr<dtDAL::GameEvent> Statistics_Event;
			bool mSendStatistics;

			osg::ref_ptr<dtDAL::GameEvent> F11_Event;
			bool mSendF11;
			osg::ref_ptr<dtDAL::GameEvent> F12_Event;
			bool mSendF12;

			osg::ref_ptr<dtGame::GameEventMessage> eventMsg;
			
			bool mInPlaybackMode;

			dtCore::UniqueId gFocusActor;

	};
}

#endif //COREDLL_INPUT_COMPONENT_H

