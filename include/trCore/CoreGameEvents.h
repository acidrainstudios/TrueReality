/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
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

#ifndef COREDLL_GAME_EVENTS_H
#define COREDLL_GAME_EVENTS_H

#include <dtUtil/RefString.h>

namespace trCore
{
	// Constant identifier for our game event handler method.

	const dtUtil::RefString GAME_EVENT_IGNITION("Ignition");
	const dtUtil::RefString GAME_EVENT_AUTOLEVEL("AutoLevel");

	const dtUtil::RefString GAME_EVENT_MOVEFORWARD("MoveForward");
	const dtUtil::RefString GAME_EVENT_MOVEBACK("MoveBack");
	const dtUtil::RefString GAME_EVENT_YAWLEFT("YawLeft");
	const dtUtil::RefString GAME_EVENT_YAWRIGHT("YawRight");
	const dtUtil::RefString GAME_EVENT_PITCHUP("PitchUp");
	const dtUtil::RefString GAME_EVENT_PITCHDOWN("PitchDown");
	const dtUtil::RefString GAME_EVENT_ROLLLEFT("RollLeft");
	const dtUtil::RefString GAME_EVENT_ROLLRIGHT("RollRight");
	const dtUtil::RefString GAME_EVENT_STRAFERIGHT("StrafeRight");
	const dtUtil::RefString GAME_EVENT_STRAFELEFT("StrafeLeft");
	const dtUtil::RefString GAME_EVENT_STRAFEUP("StrafeUp");
	const dtUtil::RefString GAME_EVENT_STRAFEDOWN("StrafeDown");
	
	const dtUtil::RefString GAME_EVENT_RESETSTUFF("ResetStuff");
	const dtUtil::RefString GAME_EVENT_SHOWSTATISTICS("ShowStat");

	const dtUtil::RefString GAME_EVENT_F11("F11_Event");
	const dtUtil::RefString GAME_EVENT_F12("F12_Event");
}

#endif //COREDLL_GAME_EVENTS_H