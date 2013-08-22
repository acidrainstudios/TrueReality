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


#ifndef COREDLL_MSG_TYPES_CPP
#define COREDLL_MSG_TYPES_CPP


#include <trCore\trCoreMsgTypes.h>

namespace trCore
{

	IMPLEMENT_ENUM(trCoreMessageType);

	const trCoreMessageType trCoreMessageType::MSG_FOCUS_ACTOR_CHANGE(trCore::FocusActorChangeMsg::MSG_DEFAULT_NAME, "Info", "Focus on Different Actor", 
													USER_DEFINED_MESSAGE_TYPE + 1);

	const trCoreMessageType trCoreMessageType::MSG_PLAYER_ACTOR_CHANGE(trCore::PlayerActorChangeMsg::MSG_DEFAULT_NAME, "Info", "Human Player changes Actors", 
													USER_DEFINED_MESSAGE_TYPE + 2);

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////


	void trCoreMessageType::RegisterMessageTypes(dtGame::MessageFactory& factory)
	{
		factory.RegisterMessageType<trCore::FocusActorChangeMsg>(MSG_FOCUS_ACTOR_CHANGE);
		factory.RegisterMessageType<trCore::PlayerActorChangeMsg>(MSG_PLAYER_ACTOR_CHANGE);
	}
}

#endif //COREDLL_MSG_TYPES_CPP