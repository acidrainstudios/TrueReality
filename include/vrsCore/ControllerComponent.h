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


#ifndef COREDLL_CONTROLLER_COMPONENT_H
#define COREDLL_CONTROLLER_COMPONENT_H

#include "export.h"
#include "vrsCoreMsgTypes.h"
#include "vrsCoreGameEvents.h"
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

namespace vrsCore
{
	/**
	 * 
	 * ControllerComponent will control all the main functionalety of program, like configuration, 
	 * setup, and in game controll
	 */
	class CORE_EXPORT ControllerComponent : public dtGame::GMComponent
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
			osg::ref_ptr<vrsCore::GenericActor> mPlayerActor;
			osg::ref_ptr<vrsCore::GenericActor> mFocusActor;

			//IDs for Player Actor and Focus Actor
			dtCore::UniqueId mFocusActorID;
			dtCore::UniqueId mPlayerActorID;


	};
}

#endif //COREDLL_CONTROLLER_COMPONENT_H

