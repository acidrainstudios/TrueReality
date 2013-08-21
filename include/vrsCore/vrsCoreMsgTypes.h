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


#ifndef COREDLL_MSG_TYPES_H
#define COREDLL_MSG_TYPES_H

#include "MsgChangeFocus.h"
#include "MsgChangePlayer.h"

namespace vrsCore
{
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	class CORE_EXPORT vrsCoreMessageType : public dtGame::MessageType
	{
	   DECLARE_ENUM(vrsCoreMessageType);

	   public:

		  static const vrsCoreMessageType MSG_FOCUS_ACTOR_CHANGE;
		  static const vrsCoreMessageType MSG_PLAYER_ACTOR_CHANGE;

		  static void RegisterMessageTypes(dtGame::MessageFactory& factory);

	   protected:

		  vrsCoreMessageType( const std::string &name, 
							   const std::string &category,
							   const std::string &description, 
							   const unsigned short messageId) :
			 dtGame::MessageType(name, category, description, messageId)
		  {
			 AddInstance(this);
		  }

		  virtual ~vrsCoreMessageType() { }
	};
}

#endif //COREDLL_MSG_TYPES_H