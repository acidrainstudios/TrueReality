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


#ifndef CS586_JOYSTICK_COMPONENT_H
#define CS586_JOYSTICK_COMPONENT_H

#include <iostream>

#include "export.h"
#include "..\\..\\vrsCore_DLL\include\vrsCoreMsgTypes.h"
#include "..\\..\\vrsCore_DLL\include\vrsCoreGameEvents.h"

#include <dtCore/refptr.h>
#include <dtCore/system.h>
#include <dtCore/inputmapper.h>

#include <dtDAL/gameeventmanager.h>

#include <dtGame/baseInputComponent.h>
#include <dtGame/basemessages.h>

#include <dtInputPLIB/joystick.h>

/**
 * This is an example use of the base input component for our tutorial. We will put
 * all of our keyboard and mouse event handling in here. As a GM component, it will
 * also receive all game messages.
 */
class VRS_CS586_EXPORT  JoystickComponent : public dtGame::GMComponent
{
   public:
		//Default Component Name
		static const std::string COMPONENT_DEFAULT_NAME;

		// Constructor
		JoystickComponent(const std::string& name);

		// Find our GameEvents after the map is loaded
		void SetupEvents();

		/**
		* Handle messages if we want to
		*/
		void ProcessMessage(const dtGame::Message& message);

		virtual void OnMessage(MessageData *data);

   protected:

		// Destructor
		virtual ~JoystickComponent() { }

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
		osg::ref_ptr<dtDAL::GameEvent> AutoLevel_Event;
		bool mSendAutoLevel;

		osg::ref_ptr<dtDAL::GameEvent> MoveForward_Event;
		osg::ref_ptr<dtDAL::GameEvent> MoveBack_Event;

		osg::ref_ptr<dtDAL::GameEvent> YawLeft_Event;
		osg::ref_ptr<dtDAL::GameEvent> YawRight_Event;
		osg::ref_ptr<dtDAL::GameEvent> PitchUp_Event;
		osg::ref_ptr<dtDAL::GameEvent> PitchDown_Event;
		osg::ref_ptr<dtDAL::GameEvent> RollLeft_Event;
		osg::ref_ptr<dtDAL::GameEvent> RollRight_Event;

		osg::ref_ptr<dtDAL::GameEvent> StrafeRight_Event;
		osg::ref_ptr<dtDAL::GameEvent> StrafeLeft_Event;
		osg::ref_ptr<dtDAL::GameEvent> StrafeUp_Event;
		osg::ref_ptr<dtDAL::GameEvent> StrafeDown_Event;

		

		/**
		* The index of the button/axis being mapped.
		*/
		int mButtonIndex, mAxisIndex;
		std::string mButtonName, mAxisName;
		bool mGUILoaded;

		osg::ref_ptr<dtCore::InputMapper> mInputMapper;
		osg::ref_ptr<dtCore::LogicalInputDevice> mApplicationInputDevice;

		osg::ref_ptr<dtGame::GameEventMessage> eventMsg;
		
		bool mInPlaybackMode;

		dtCore::UniqueId gFocusActor;

};

#endif //CS586_JOYSTICK_COMPONENT_H

