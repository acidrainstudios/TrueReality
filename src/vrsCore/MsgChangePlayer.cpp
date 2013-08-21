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


#ifndef COREDLL_MSG_CHANGE_PLAYER_CPP
#define COREDLL_MSG_CHANGE_PLAYER_CPP

#include <vrsCore\MsgChangePlayer.h>
namespace vrsCore
{
	///////////////////////////////////////////////////////////////////////////////
	const std::string PlayerActorChangeMsg::MSG_DEFAULT_NAME("NewPlayerActorUniqueId");
	///////////////////////////////////////////////////////////////////////////////
	PlayerActorChangeMsg::PlayerActorChangeMsg()
	{
	   AddParameter( new dtGame::ActorMessageParameter(MSG_DEFAULT_NAME) );
	}

	///////////////////////////////////////////////////////////////////////////////
	PlayerActorChangeMsg::~PlayerActorChangeMsg()
	{
	}

	///////////////////////////////////////////////////////////////////////////////
	void PlayerActorChangeMsg::SetNewPlayerActorUniqueId( const dtCore::UniqueId& uniqueId )
	{
		dtGame::ActorMessageParameter* uniqueIdParam =
			 static_cast< dtGame::ActorMessageParameter* >( GetParameter(MSG_DEFAULT_NAME) );
		uniqueIdParam->SetValue(uniqueId);
	}

	///////////////////////////////////////////////////////////////////////////////
	const dtCore::UniqueId& PlayerActorChangeMsg::GetNewPlayerActorUniqueId() const
	{
	   const dtGame::ActorMessageParameter* uniqueIdParam =
			 static_cast< const dtGame::ActorMessageParameter* >( GetParameter(MSG_DEFAULT_NAME) );
	   return uniqueIdParam->GetValue();
	}
}

#endif //COREDLL_MSG_CHANGE_PLAYER_CPP

