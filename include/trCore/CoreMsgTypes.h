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


#ifndef COREDLL_MSG_TYPES_H
#define COREDLL_MSG_TYPES_H

#include "MsgChangeFocus.h"
#include "MsgChangePlayer.h"

namespace trCore
{
	/////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////
	//class TR_CORE_EXPORT trCoreMessageType : public dtGame::MessageType
	//{
	//   DECLARE_ENUM(trCoreMessageType);

	//   public:

	//	  static const trCoreMessageType MSG_FOCUS_ACTOR_CHANGE;
	//	  static const trCoreMessageType MSG_PLAYER_ACTOR_CHANGE;

	//	  static void RegisterMessageTypes(dtGame::MessageFactory& factory);

	//   protected:

	//	  trCoreMessageType( const std::string &name, 
	//						   const std::string &category,
	//						   const std::string &description, 
	//						   const unsigned short messageId) :
	//		 dtGame::MessageType(name, category, description, messageId)
	//	  {
	//		 AddInstance(this);
	//	  }

	//	  virtual ~trCoreMessageType() { }
	//};
}

#endif //COREDLL_MSG_TYPES_H