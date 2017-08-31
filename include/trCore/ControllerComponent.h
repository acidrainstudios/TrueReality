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


#ifndef COREDLL_CONTROLLER_COMPONENT_H
#define COREDLL_CONTROLLER_COMPONENT_H

#include "export.h"
#include "CoreMsgTypes.h"
#include "CoreGameEvents.h"
#include "ActorGeneric.h"

#include <iostream>

#include <dtCore/refptr.h>
#include <dtCore/system.h>
#include <dtCore/transform.h>
#include <dtCore/shadermanager.h>



#include <dtABC/application.h>

#include <dtDAL/enginepropertytypes.h>
#include <dtDAL/gameevent.h>
#include <dtDAL/gameeventmanager.h>

#include <dtGame/baseinputcomponent.h>
#include <dtGame/logcontroller.h>
#include <dtGame/basemessages.h>
#include <dtGame/messagetype.h>
#include <dtGame/gamemanager.h>

#include <osgViewer/CompositeViewer>

#include <osgDB/DatabasePager>

namespace trCore
{
	/**
	 * 
	 * ControllerComponent will control all the main functionalety of program, like configuration, 
	 * setup, and in game controll
	 */
	class TR_CORE_EXPORT ControllerComponent : public dtGame::GMComponent
	{
	   public:

			//Default Component Name
			static const std::string COMPONENT_DEFAULT_NAME;

		  // Constructor
		  ControllerComponent(const std::string& name, bool inPlaybackMode);

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
		   * We're going to handle raw key presses!
		   */
		  //virtual bool HandleKeyPressed(const dtCore::Keyboard* keyboard, int key);

	   protected:

		  /// Destructor
		  virtual ~ControllerComponent() { }

	   private:

		   //void AttachActor(void);

		  /**
		   * This method creates the game event
		   * message and sends it on to the Game Manager for processing.
		   * @param event The game event to fire.
		   */
	   		void FireGameEvent(const dtDAL::GameEvent& event);

			//Our LogController
			osg::ref_ptr<dtGame::LogController> mLogController;

			//Our pointer for shooting off messages
			osg::ref_ptr<dtGame::GameEventMessage> eventMsg;

			//float StatisticsTimer;

			//float mDeltaSimTime;

			bool mInPlaybackMode;

			//Pointer to Player Actor and Focus Actor
			osg::ref_ptr<trCore::GenericActor> mPlayerActor;
			osg::ref_ptr<trCore::GenericActor> mFocusActor;

			//IDs for Player Actor and Focus Actor
			dtCore::UniqueId mFocusActorID;
			dtCore::UniqueId mPlayerActorID;


	};
}

#endif //COREDLL_CONTROLLER_COMPONENT_H

