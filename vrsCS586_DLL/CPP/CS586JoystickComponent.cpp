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


#ifndef CS586_JOYSTICK_COMPONENT_CPP
#define CS586_JOYSTICK_COMPONENT_CPP

#include "..\\Include\CS586JoystickComponent.h"

////////////////////////////////////////////////////////////////////
const std::string JoystickComponent::COMPONENT_DEFAULT_NAME("JoystickComponent");
////////////////////////////////////////////////////////////////////
JoystickComponent::JoystickComponent(const std::string& name)
:dtGame::GMComponent(name)
,eventMsg(0)
,AutoLevel_Event(0)
,MoveForward_Event(0), MoveBack_Event(0)
,YawLeft_Event(0), YawRight_Event(0), PitchUp_Event(0), PitchDown_Event(0), RollLeft_Event(0), RollRight_Event(0)
,StrafeRight_Event(0), StrafeLeft_Event(0), StrafeUp_Event(0), StrafeDown_Event(0)
,mInputMapper(0)
,mApplicationInputDevice(0)
{
	
	AddSender(&dtCore::System::GetInstance());

	dtInputPLIB::Joystick::CreateInstances();	

	mInputMapper = new dtCore::InputMapper;	

	for (int i = 0; i < dtInputPLIB::Joystick::GetInstanceCount(); i++)
	{
		mInputMapper->AddDevice(dtInputPLIB::Joystick::GetInstance(i));
	}
}
//////////////////////////////////////////////////////////////////////////
void JoystickComponent::SetupEvents()
{
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
}
//////////////////////////////////////////////////////////////////////////
void JoystickComponent::ProcessMessage(const dtGame::Message& message)
{
	if (message.GetMessageType() == dtGame::MessageType::INFO_MAP_LOADED)
	{
		SetupEvents();
	}
   
	else if (message.GetMessageType() == vrsCore::vrsCoreMessageType::MSG_FOCUS_ACTOR_CHANGE)
	{
		const vrsCore::FocusActorChangeMsg& focusActorChangeMsg = static_cast<const vrsCore::FocusActorChangeMsg&>(message);
		gFocusActor = focusActorChangeMsg.GetNewFocusActorUniqueId();
	}
}

//////////////////////////////////////////////////////////////////////////
void JoystickComponent::OnMessage(MessageData *data)
{
	if(data->message == "posteventtraversal")
	{
		dtInputPLIB::Joystick::PollInstances();

		if(dtInputPLIB::Joystick::GetInstance(0)->GetAxis(7)->GetState() < -0.5f){
			if(PitchDown_Event != NULL){
				FireGameEvent(*PitchDown_Event);
			}}
		else if(dtInputPLIB::Joystick::GetInstance(0)->GetAxis(7)->GetState() > 0.5f){
			if(PitchUp_Event != NULL){
					FireGameEvent(*PitchUp_Event);
					}}

		if(dtInputPLIB::Joystick::GetInstance(0)->GetAxis(6)->GetState() < -0.5f ){
			if(YawLeft_Event != NULL){
					FireGameEvent(*YawLeft_Event);
					}}
		else if(dtInputPLIB::Joystick::GetInstance(0)->GetAxis(6)->GetState() > 0.5f){
			if(YawRight_Event != NULL){
					FireGameEvent(*YawRight_Event);
					}}

		if(dtInputPLIB::Joystick::GetInstance(0)->GetAxis(3)->GetState()> 0.5f){
			if(StrafeUp_Event != NULL){
					FireGameEvent(*StrafeUp_Event);
					}}
		else if(dtInputPLIB::Joystick::GetInstance(0)->GetAxis(3)->GetState()< -0.5f){
			if(StrafeDown_Event != NULL){
					FireGameEvent(*StrafeDown_Event);
					}}

		if(dtInputPLIB::Joystick::GetInstance(0)->GetAxis(2)->GetState() < -0.5f)	{
			if(StrafeLeft_Event != NULL){
					FireGameEvent(*StrafeLeft_Event);
					}}
		else if(dtInputPLIB::Joystick::GetInstance(0)->GetAxis(2)->GetState() > 0.5f){
			if(StrafeRight_Event != NULL){
					FireGameEvent(*StrafeRight_Event);
					}}

		if(dtInputPLIB::Joystick::GetInstance(0)->GetButton(1)->GetState()){
			if (MoveForward_Event != NULL){
				FireGameEvent(*MoveForward_Event);}}
		else if(dtInputPLIB::Joystick::GetInstance(0)->GetButton(0)->GetState()){
			if (MoveBack_Event != NULL){
				FireGameEvent(*MoveBack_Event);}}
	
		if(dtInputPLIB::Joystick::GetInstance(0)->GetButton(5)->GetState()){
			if (RollLeft_Event != NULL){
				FireGameEvent(*RollLeft_Event);}}
		else if(dtInputPLIB::Joystick::GetInstance(0)->GetButton(4)->GetState()){
			if (RollRight_Event != NULL){
				FireGameEvent(*RollRight_Event);}}

		if(dtInputPLIB::Joystick::GetInstance(0)->GetButton(3)->GetState()){
			if (AutoLevel_Event != NULL){
				FireGameEvent(*AutoLevel_Event);
				mSendAutoLevel = false;}}		
		else if(!dtInputPLIB::Joystick::GetInstance(0)->GetButton(3)->GetState() && !mSendAutoLevel)
		{
			mSendAutoLevel = true;
		}


	}

}

//////////////////////////////////////////////////////////////////////////
void JoystickComponent::FireGameEvent(const dtDAL::GameEvent& event)
{

   dtCore::RefPtr<dtGame::GameEventMessage> eventMsg;
   GetGameManager()->GetMessageFactory().CreateMessage(dtGame::MessageType::INFO_GAME_EVENT, eventMsg);

   eventMsg->SetGameEvent(event);
   
   eventMsg->SetAboutActorId(gFocusActor);

   GetGameManager()->SendMessage(*eventMsg);
	
}

#endif //CS586_JOYSTICK_COMPONENT