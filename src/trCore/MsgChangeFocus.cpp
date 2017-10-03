/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 3.0 of the License, or (at your option)
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


#ifndef COREDLL_MSG_CHANGE_FOCUS_CPP
#define COREDLL_MSG_CHANGE_FOCUS_CPP

#include <trCore\MsgChangeFocus.h>

namespace trCore
{
	/////////////////////////////////////////////////////////////////////////////////
	//const std::string FocusActorChangeMsg::MSG_DEFAULT_NAME("NewFocusActorUniqueId");
	/////////////////////////////////////////////////////////////////////////////////
	//FocusActorChangeMsg::FocusActorChangeMsg()
	//{
	//   AddParameter( new dtGame::ActorMessageParameter(MSG_DEFAULT_NAME) );
	//}

	/////////////////////////////////////////////////////////////////////////////////
	//FocusActorChangeMsg::~FocusActorChangeMsg()
	//{
	//}

	/////////////////////////////////////////////////////////////////////////////////
	//void FocusActorChangeMsg::SetNewFocusActorUniqueId(const dtCore::UniqueId& uniqueId)
	//{
	//   dtGame::ActorMessageParameter* uniqueIdParam = static_cast< dtGame::ActorMessageParameter* >(GetParameter(MSG_DEFAULT_NAME));
	//   uniqueIdParam->SetValue( uniqueId );
	//}

	/////////////////////////////////////////////////////////////////////////////////
	//const dtCore::UniqueId& FocusActorChangeMsg::GetNewFocusActorUniqueId() const
	//{
	//   const dtGame::ActorMessageParameter* uniqueIdParam = static_cast< const dtGame::ActorMessageParameter* >(GetParameter(MSG_DEFAULT_NAME));
	//   return uniqueIdParam->GetValue();
	//}
}

#endif //COREDLL_MSG_CHANGE_FOCUS_CPP

