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


#ifndef COREDLL_MSG_CHANGE_FOCUS_H
#define COREDLL_MSG_CHANGE_FOCUS_H

#include "export.h"
#include <dtGame/message.h>
#include <dtGame/messagetype.h>
#include <dtGame/messagefactory.h>
#include <dtGame/messageparameter.h>
#include <dtCore/uniqueid.h>

namespace vrsCore
{
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	class CORE_EXPORT FocusActorChangeMsg : public dtGame::Message
	{
	   public:
		   //Default Msg Parameter Name
			static const std::string MSG_DEFAULT_NAME;

			FocusActorChangeMsg();

			void SetNewFocusActorUniqueId( const dtCore::UniqueId& uniqueId );
	      
			const dtCore::UniqueId& GetNewFocusActorUniqueId() const;

	   protected:
			virtual ~FocusActorChangeMsg();
	   
	};
}
#endif // COREDLL_MSG_CHANGE_FOCUS_H