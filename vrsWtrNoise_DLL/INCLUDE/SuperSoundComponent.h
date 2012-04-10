/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* WTRNOISE DLL Stevens University Collision Avoidance Project
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
* @author WTRNOISE Class:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////

#ifndef VRS_SUPER_WTRNOISE_H
#define VRS_SUPER_WTRNOISE_H

#include <iostream>

#include "export.h"

#include <dtGame/baseinputcomponent.h>
#include <dtGame/messagetype.h>
#include <dtGame/message.h>

#include <dtCore/system.h>
#include <dtCore/scene.h>
#include <dtCore/physical.h>
#include <dtCore/transform.h>

#include <dtABC/application.h>

#include <dtAudio/sound.h>
#include <dtAudio/audiomanager.h>

#include <dtPhysics/physicshelper.h>
#include <dtPhysics/physicscomponent.h>
#include <dtPhysics/palutil.h>
#include <dtPhysics/palphysicsworld.h>

#include <pal/pal.h>
#include <pal/palFactory.h>


class VRS_WTRNOISE_EXPORT SuperSoundComponent : public dtGame::GMComponent
{
	 
   public:
		//Default Component Name
		static const std::string COMPONENT_DEFAULT_NAME;
		
		// Constructor
		SuperSoundComponent(const std::string& name);

		/**
		* Handle messages if we want to
		*/
		void ProcessMessage(const dtGame::Message& message);

		//Set the ocean height
		void SetOceanHeight(float height);
		//Get the ocean height
		float GetOceanHeight(void) const {return mOceanHeight;}

		//Set the ocean sound max height
		void SetOceanSndMaxHeight(float height);

		// set the underwater sound
		//void SetUnderWtrSnd(dtDAL::ResourceDescriptor* undWtrSnd);
		void SetUnderWtrSnd(std::string* undWtrSnd);

		// set the above water sound
		//void SetAboveWtrSnd(dtDAL::ResourceDescriptor* aboveWtrSnd);
		void SetAboveWtrSnd(std::string* aboveWtrSnd);

		// set the way up in the air sound
		//void SetUpHighSnd(dtDAL::ResourceDescriptor* upHighSnd);
		void SetUpHighSnd(std::string* upHighSnd);

		// set the splash sound
		//void SetSplashSnd(dtDAL::ResourceDescriptor* splashSnd);
		void SetSplashSnd(std::string* splashSnd);
		
		// enable/disable physics for sound
		void EnablePhysics(bool enable);

   protected:

		// Destructor
		virtual ~SuperSoundComponent();

		char* getFileNameFromRes(dtDAL::ResourceDescriptor* res);

   private:

		float mOceanHeight;
		float mOceanSndMaxHeight;
		//dtCore::Transformable* mCam;
		dtCore::Camera* mLilCam;
		dtAudio::Sound* mUnderWaterSound;
		dtAudio::Sound* mAboveWaterSound;
		dtAudio::Sound* mUpHighSound;
		dtAudio::Sound* mSplashSound;
		bool mPlayerCamera;
		bool mShouldSplash;
		//const char* mLoadFile;
		//const char* mCameraName;
		bool mAboveOcean;
		float mAboveWtrFade; // 0 = no sound, 1 = full sound
		float mAboveWtrFadeAmount; // how much to increase/decrease fade each frame

		std::string* mUnderWtrSndFilename;
		std::string* mAboveWtrSndFilename;
		std::string* mUpHighSndFilename;
		std::string* mSplashSndFilename;

		bool mPhysicsEnabled;

};
#endif //VRS_SUPER_WTRNOISE_H