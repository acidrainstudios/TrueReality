/*
* The Construct Open Source Game and Simulation Engine
* Copyright (C) 2013
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


#ifndef COREDLL_INPUT_COMPONENT_CPP
#define COREDLL_INPUT_COMPONENT_CPP

#include <vrsCore\InputComponent.h>

namespace vrsCore
{

	////////////////////////////////////////////////////////////////////
	const std::string InputComponent::COMPONENT_DEFAULT_NAME("InputComponent");
	////////////////////////////////////////////////////////////////////
	InputComponent::InputComponent(const std::string& name, bool inPlaybackMode)
		:dtGame::GMComponent(name)
		,eventMsg(0)
		,mSendStatistics(true), mSendIgnition(true), mSendAutoLevel(true)
		,Ignition_Event(0)
		,AutoLevel_Event(0)
		,MoveForward_Event(0), MoveBack_Event(0)
		,StrafeRight_Event(0), StrafeLeft_Event(0), StrafeUp_Event(0), StrafeDown_Event(0)
		,YawLeft_Event(0), YawRight_Event(0), PitchUp_Event(0), PitchDown_Event(0), RollLeft_Event(0), RollRight_Event(0)
		,F11_Event(0), F12_Event(0) 
		,mInPlaybackMode(inPlaybackMode)
	{
		AddSender(&dtCore::System::GetInstance());			
	}

	////////////////////////////////////////////////////////////////////
	void InputComponent::SetupEvents()
	{
		Ignition_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_IGNITION);	
		if (Ignition_Event == NULL)
		{
			Ignition_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_IGNITION);
			Ignition_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_IGNITION)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*Ignition_Event);
		}

		AutoLevel_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_AUTOLEVEL);
		if (AutoLevel_Event == NULL)
		{

			AutoLevel_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_AUTOLEVEL);
			AutoLevel_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_AUTOLEVEL)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*AutoLevel_Event);
		}

		MoveForward_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_MOVEFORWARD);
		if (MoveForward_Event == NULL)
		{

			MoveForward_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_MOVEFORWARD);
			MoveForward_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_MOVEFORWARD)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*MoveForward_Event);
		}

		MoveBack_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_MOVEBACK);
		if (MoveBack_Event == NULL)
		{

			MoveBack_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_MOVEBACK);
			MoveBack_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_MOVEBACK)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*MoveBack_Event);
		}

		StrafeRight_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_STRAFERIGHT);
		if (StrafeRight_Event == NULL)
		{

			StrafeRight_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_STRAFERIGHT);
			StrafeRight_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_STRAFERIGHT)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*StrafeRight_Event);
		}

		StrafeLeft_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_STRAFELEFT);
		if (StrafeLeft_Event == NULL)
		{

			StrafeLeft_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_STRAFELEFT);
			StrafeLeft_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_STRAFELEFT)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*StrafeLeft_Event);
		}

		StrafeUp_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_STRAFEUP);
		if (StrafeUp_Event == NULL)
		{

			StrafeUp_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_STRAFEUP);
			StrafeUp_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_STRAFEUP)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*StrafeUp_Event);
		}

		StrafeDown_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_STRAFEDOWN);
		if (StrafeDown_Event == NULL)
		{

			StrafeDown_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_STRAFEDOWN);
			StrafeDown_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_STRAFEDOWN)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*StrafeDown_Event);
		}

		YawLeft_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_YAWLEFT);
		if (YawLeft_Event == NULL)
		{
			YawLeft_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_YAWLEFT);
			YawLeft_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_YAWLEFT)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*YawLeft_Event);
		}

		YawRight_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_YAWRIGHT);
		if (YawRight_Event == NULL)
		{
			YawRight_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_YAWRIGHT);
			YawRight_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_YAWRIGHT)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*YawRight_Event);
		}

		PitchUp_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_PITCHUP);
		if (PitchUp_Event == NULL)
		{
			PitchUp_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_PITCHUP);
			PitchUp_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_PITCHUP)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*PitchUp_Event);
		}

		PitchDown_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_PITCHDOWN);
		if (PitchDown_Event == NULL)
		{
			PitchDown_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_PITCHDOWN);
			PitchDown_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_PITCHDOWN)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*PitchDown_Event);
		}

		RollLeft_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_ROLLLEFT);
		if (RollLeft_Event == NULL)
		{
			RollLeft_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_ROLLLEFT);
			RollLeft_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_ROLLLEFT)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*RollLeft_Event);
		}

		RollRight_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_ROLLRIGHT);
		if (RollRight_Event == NULL)
		{
			RollRight_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_ROLLRIGHT);
			RollRight_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_ROLLRIGHT)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*RollRight_Event);
		}

		Statistics_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_SHOWSTATISTICS);
		if (Statistics_Event == NULL)
		{
			Statistics_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_SHOWSTATISTICS);
			Statistics_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_SHOWSTATISTICS)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*Statistics_Event);
		}

		F11_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_F11);
		if (F11_Event == NULL)
		{
			F11_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_F11);
			F11_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_F11)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*F11_Event);
		}

		F12_Event = dtDAL::GameEventManager::GetInstance().FindEvent(vrsCore::GAME_EVENT_F12);
		if (F12_Event == NULL)
		{
			F12_Event = new dtDAL::GameEvent(vrsCore::GAME_EVENT_F12);
			F12_Event->SetUniqueId(dtCore::UniqueId(vrsCore::GAME_EVENT_F12)); 
			dtDAL::GameEventManager::GetInstance().AddEvent(*F12_Event);
		}

	}

	////////////////////////////////////////////////////////////////////
	/*
	bool InputComponent::HandleKeyPressed(const dtCore::Keyboard* keyboard, int key)
	{
		dtABC::Application& app = GetGameManager()->GetApplication();

		if(app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Escape))
		{
		   app.Quit();
		   std::cout << "esc" << std::endl;
		   return true;
		   
		}

	}
	*/

	//////////////////////////////////////////////////////////////////////////
	void InputComponent::ProcessMessage(const dtGame::Message& message)
	{
		// After the map is finished loading, we will get this.  At which point, our events
		// have been loaded from the map and we can now find them
		if (message.GetMessageType() == dtGame::MessageType::INFO_MAP_LOADED)
		{
			SetupEvents();
		}

		//If the focus changed to a different actor, update who the focus is on now...
	   
		else if (message.GetMessageType() == vrsCoreMessageType::MSG_FOCUS_ACTOR_CHANGE)
		{
			const FocusActorChangeMsg& focusActorChangeMsg = static_cast<const FocusActorChangeMsg&>(message);
			gFocusActor = focusActorChangeMsg.GetNewFocusActorUniqueId();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void InputComponent::OnMessage(MessageData *data)
	{
		if(data->message == dtCore::System::MESSAGE_POST_EVENT_TRAVERSAL)
		{
			dtABC::Application& app = GetGameManager()->GetApplication();

			///////////////////////////////////
			///////////////////////////////////
			if(app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Up) 
				&& !app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Alt_L))
			{
				if(!mInPlaybackMode && PitchDown_Event != NULL)
				{
					FireGameEvent(*PitchDown_Event);
				}
			}
			else if(app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Down)
				&& !app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Alt_L))
			{
				if(!mInPlaybackMode && PitchUp_Event != NULL)
					{
						FireGameEvent(*PitchUp_Event);
					}
			}

			if(app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Left)
				&& !app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Alt_L))
			{
				if(!mInPlaybackMode && YawLeft_Event != NULL)
					{
						FireGameEvent(*YawLeft_Event);
					}
			}
			else if(app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Right)
				&& !app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Alt_L))
			{
				if(!mInPlaybackMode && YawRight_Event != NULL)
					{
						FireGameEvent(*YawRight_Event);
					}
			}
		
			///////////////////////////////////
			///////////////////////////////////

			if(app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Up)
				&& app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Alt_L))
			{
				if(!mInPlaybackMode && StrafeUp_Event != NULL)
					{
						FireGameEvent(*StrafeUp_Event);
					}
			}
			else if(app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Down)
				&& app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Alt_L))
			{
				if(!mInPlaybackMode && StrafeDown_Event != NULL)
					{
						FireGameEvent(*StrafeDown_Event);
					}
			}

			if(app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Left)
				&& app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Alt_L))
			{
				if(!mInPlaybackMode && StrafeLeft_Event != NULL)
					{
						FireGameEvent(*StrafeLeft_Event);
					}
			}
			else if(app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Right)
				&& app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Alt_L))
			{
				if(!mInPlaybackMode && StrafeRight_Event != NULL)
					{
						FireGameEvent(*StrafeRight_Event);
					}
			}

			///////////////////////////////////
			///////////////////////////////////

			if(app.GetKeyboard()->GetKeyState('w'))
			{
				if (!mInPlaybackMode && MoveForward_Event != NULL)
				{
					FireGameEvent(*MoveForward_Event);
				}
			}
			else if(app.GetKeyboard()->GetKeyState('s'))
			{
				if (!mInPlaybackMode && MoveBack_Event != NULL)
				{
					FireGameEvent(*MoveBack_Event);
				}
			}
		
			if(app.GetKeyboard()->GetKeyState('d'))
			{
				if (!mInPlaybackMode && RollLeft_Event != NULL)
				{
					FireGameEvent(*RollLeft_Event);
					
				}
			}
			else if(app.GetKeyboard()->GetKeyState('a'))
			{
				if (!mInPlaybackMode && RollRight_Event != NULL)
				{
					FireGameEvent(*RollRight_Event);
				}
			}


		///////////////////////////////////
		///////////////////////////////////
			if(app.GetKeyboard()->GetKeyState('i') && mSendIgnition)
			{
				if (!mInPlaybackMode && Ignition_Event != NULL)
				{
					FireGameEvent(*Ignition_Event);
					mSendIgnition = false;
				}
			}
			else if(!app.GetKeyboard()->GetKeyState('i') && !mSendIgnition)
			{
				mSendIgnition = true;
			}

		///////////////////////////////////
		///////////////////////////////////
			if(app.GetKeyboard()->GetKeyState('l') && mSendAutoLevel)
			{
				if (!mInPlaybackMode && AutoLevel_Event != NULL)
				{
					FireGameEvent(*AutoLevel_Event);
					mSendAutoLevel = false;
				}
			}
			else if(!app.GetKeyboard()->GetKeyState('l') && !mSendAutoLevel)
			{
				mSendAutoLevel = true;
			}
		///////////////////////////////////
		///////////////////////////////////
			if(app.GetKeyboard()->GetKeyState('`') && mSendStatistics)
			{
				if (!mInPlaybackMode && Statistics_Event != NULL)
				{
					FireGameEvent(*Statistics_Event);
					mSendStatistics = false;
				}			
			}
			else if(!app.GetKeyboard()->GetKeyState('`') && !mSendStatistics)
			{
				mSendStatistics = true;
			}
		///////////////////////////////////
		///////////////////////////////////
			if(app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_F11) && mSendF11)
			{
				if (!mInPlaybackMode && F11_Event != NULL)
				{
					FireGameEvent(*F11_Event);
					mSendF11 = false;
				}			
			}
			else if(!app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_F11) && !mSendF11)
			{
				mSendF11 = true;
			}
		///////////////////////////////////
		///////////////////////////////////
			if(app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_F12) && mSendF12)
			{
				if (!mInPlaybackMode && F12_Event != NULL)
				{
					FireGameEvent(*F12_Event);
					mSendF12 = false;
				}			
			}
			else if(!app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_F12) && !mSendF12)
			{
				mSendF12 = true;
			}
		///////////////////////////////////
		///////////////////////////////////
		/*	if(app.GetKeyboard()->GetKeyState('p'))
			{
				GetGameManager()->SetPaused(!GetGameManager()->IsPaused());
				
				#ifdef _DEBUG
						printf("Pausing.. GM is now [%s].\r\n", (GetGameManager()->IsPaused() ? "ON" : "OFF"));
				#endif //_DEBUG
			}
	*/
			
		///////////////////////////////////
		///////////////////////////////////

		}
		
	}

	//////////////////////////////////////////////////////////////////////////
	void InputComponent::FireGameEvent(const dtDAL::GameEvent& event)
	{
	   dtCore::RefPtr<dtGame::GameEventMessage> eventMsg;
	   GetGameManager()->GetMessageFactory().CreateMessage(dtGame::MessageType::INFO_GAME_EVENT, eventMsg);

	   eventMsg->SetGameEvent(event);
	   
	   eventMsg->SetAboutActorId(gFocusActor);

	   GetGameManager()->SendMessage(*eventMsg);
	}
	//////////////////////////////////////////////////////////////////////////
}

#endif //COREDLL_INPUT_COMPONENT_H