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


#ifndef COREDLL_MSG_TYPES_CPP
#define COREDLL_MSG_TYPES_CPP


#include "..\\Include\vrsCoreMsgTypes.h"

namespace vrsCore
{

	IMPLEMENT_ENUM(vrsCoreMessageType);

	const vrsCoreMessageType vrsCoreMessageType::MSG_FOCUS_ACTOR_CHANGE(vrsCore::FocusActorChangeMsg::MSG_DEFAULT_NAME, "Info", "Focus on Different Actor", 
													USER_DEFINED_MESSAGE_TYPE + 1);

	const vrsCoreMessageType vrsCoreMessageType::MSG_PLAYER_ACTOR_CHANGE(vrsCore::PlayerActorChangeMsg::MSG_DEFAULT_NAME, "Info", "Human Player changes Actors", 
													USER_DEFINED_MESSAGE_TYPE + 2);

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////


	void vrsCoreMessageType::RegisterMessageTypes(dtGame::MessageFactory& factory)
	{
		factory.RegisterMessageType<vrsCore::FocusActorChangeMsg>(MSG_FOCUS_ACTOR_CHANGE);
		factory.RegisterMessageType<vrsCore::PlayerActorChangeMsg>(MSG_PLAYER_ACTOR_CHANGE);
	}
}

#endif //COREDLL_MSG_TYPES_CPP