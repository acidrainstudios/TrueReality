/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 2.1 of the License, or (at your option)
* any later version.
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
* details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* Author: Maxim Serebrennik
*/


#ifndef COREDLL_INPUT_COMPONENT_H
#define COREDLL_INPUT_COMPONENT_H

#include "export.h"
#include "CoreMsgTypes.h"
#include "CoreGameEvents.h"

#include <iostream>

#include <dtCore/refptr.h>
#include <dtCore/system.h>
#include <dtCore/shadermanager.h>


//#include <dtABC/application.h>
//
//#include <dtDAL/enginepropertytypes.h>
//#include <dtDAL/gameevent.h>
//#include <dtDAL/gameeventmanager.h>
//
//#include <dtGame/baseinputcomponent.h>
//#include <dtGame/logcontroller.h>
//#include <dtGame/basemessages.h>
//#include <dtGame/messagetype.h>

#include <osgViewer/CompositeViewer>

namespace trCore
{

	//class TR_CORE_EXPORT InputComponent : public dtGame::GMComponent
	//{
	//   public:

	//	   //Default Component Name
	//		static const std::string COMPONENT_DEFAULT_NAME;

	//	  // Constructor
	//	  InputComponent(const std::string& name, bool inPlaybackMode);

	//	  // Find our GameEvents after the map is loaded
	//	  void SetupEvents();

	//	  /**
	//	   * Handle messages if we want to
	//	   */
	//	  void ProcessMessage(const dtGame::Message& message);

	//	  virtual void OnMessage(MessageData *data);

	//	  //void SetFocusActor(dtCore::UniqueId& FocusActor);

	//	  // We're going to handle key presses!
	//	  //virtual bool HandleKeyPressed(const dtCore::Keyboard* keyboard, int key);

	//   protected:

	//	  /// Destructor
	//	  virtual ~InputComponent() { }

	//   private:
	//	  /**
	//	   * Simple helper method to fire a game event.  This method creates the game event
	//	   * message and sends it on to the Game Manager for processing.
	//	   * @param event The game event to fire.
	//	   */
	//	   
	//		void FireGameEvent(const dtDAL::GameEvent& event);


	//	  /**
	//	   * Some of out custom Game Events.....
	//	   */
	//		osg::ref_ptr<dtDAL::GameEvent> Ignition_Event;
	//		bool mSendIgnition;

	//		osg::ref_ptr<dtDAL::GameEvent> AutoLevel_Event;
	//		bool mSendAutoLevel;

	//		osg::ref_ptr<dtDAL::GameEvent> MoveForward_Event;
	//		osg::ref_ptr<dtDAL::GameEvent> MoveBack_Event;

	//		osg::ref_ptr<dtDAL::GameEvent> StrafeRight_Event;
	//		osg::ref_ptr<dtDAL::GameEvent> StrafeLeft_Event;
	//		osg::ref_ptr<dtDAL::GameEvent> StrafeUp_Event;
	//		osg::ref_ptr<dtDAL::GameEvent> StrafeDown_Event;

	//		osg::ref_ptr<dtDAL::GameEvent> YawLeft_Event;
	//		osg::ref_ptr<dtDAL::GameEvent> YawRight_Event;
	//		osg::ref_ptr<dtDAL::GameEvent> PitchUp_Event;
	//		osg::ref_ptr<dtDAL::GameEvent> PitchDown_Event;
	//		osg::ref_ptr<dtDAL::GameEvent> RollLeft_Event;
	//		osg::ref_ptr<dtDAL::GameEvent> RollRight_Event;

	//		osg::ref_ptr<dtDAL::GameEvent> Statistics_Event;
	//		bool mSendStatistics;

	//		osg::ref_ptr<dtDAL::GameEvent> F11_Event;
	//		bool mSendF11;
	//		osg::ref_ptr<dtDAL::GameEvent> F12_Event;
	//		bool mSendF12;

	//		osg::ref_ptr<dtGame::GameEventMessage> eventMsg;
	//		
	//		bool mInPlaybackMode;

	//		dtCore::UniqueId gFocusActor;

	//};
}

#endif //COREDLL_INPUT_COMPONENT_H

