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


#ifndef COREDLL_MSG_CHANGE_PLAYER_H
#define COREDLL_MSG_CHANGE_PLAYER_H

#include "export.h"

#include <dtGame/message.h>
#include <dtGame/messagetype.h>
#include <dtGame/messagefactory.h>
#include <dtGame/messageparameter.h>
#include <dtGame/gameapplication.h>

#include <dtCore/uniqueid.h>
namespace trCore
{
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	class CORE_EXPORT PlayerActorChangeMsg : public dtGame::Message
	{
	   public:
		   //Default Msg Parameter Name
			static const std::string MSG_DEFAULT_NAME;
	      
			PlayerActorChangeMsg();

			void SetNewPlayerActorUniqueId( const dtCore::UniqueId& uniqueId );
			
			const dtCore::UniqueId& GetNewPlayerActorUniqueId() const;

	   protected:
      		virtual ~PlayerActorChangeMsg();   	
	};
}

#endif // COREDLL_MSG_CHANGE_PLAYER_H
