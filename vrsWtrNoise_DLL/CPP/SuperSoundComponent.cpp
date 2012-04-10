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

#ifndef VRS_SUPER_WTRNOISE_CPP
#define VRS_SUPER_WTRNOISE_CPP

#include "../Include/SuperSoundComponent.h"

////////////////////////////////////////////////////////////////////
const std::string SuperSoundComponent::COMPONENT_DEFAULT_NAME("SuperSoundComponent");
////////////////////////////////////////////////////////////////////
SuperSoundComponent::SuperSoundComponent(const std::string& name) 
:dtGame::GMComponent(name)
,mOceanHeight(-1)
,mOceanSndMaxHeight(1000)
,mPlayerCamera(false)
//,mCam(0)
,mLilCam(0)
,mUnderWaterSound(0)
,mAboveWaterSound(0)
,mUpHighSound(0)
,mSplashSound(0)
,mShouldSplash(false)
,mAboveWtrFade(0)
,mAboveOcean(false)
,mAboveWtrFadeAmount(0.01)
,mUnderWtrSndFilename(0)
,mAboveWtrSndFilename(0)
,mUpHighSndFilename(0)
,mSplashSndFilename(0)
,mPhysicsEnabled(false)
//,mLoadFile("sounds/Diving.wav")
//,mLoadFile("Sounds//Diving.wav")
//,mCameraName("Camera")
{	
	//std::cout << "here1" << std::endl;
	AddSender(&dtCore::System::GetInstance());

	dtAudio::AudioManager::Instantiate();
	//std::cout << "here2" << std::endl;
}


//////////////////////////////////////////////////////////////////////////
SuperSoundComponent::~SuperSoundComponent()
{
	if (!mUnderWaterSound->IsStopped())
    {
       mUnderWaterSound->Stop();
	}

	if (!mAboveWaterSound->IsStopped())
    {
       mAboveWaterSound->Stop();
	}

	if (!mUpHighSound->IsStopped())
    {
       mUpHighSound->Stop();
	}

	if (!mSplashSound->IsStopped())
    {
       mSplashSound->Stop();
	}

	dtAudio::AudioManager::GetInstance().FreeSound(mUnderWaterSound);

	dtAudio::AudioManager::Destroy();
}
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
void SuperSoundComponent::ProcessMessage(const dtGame::Message& message)
{
	//std::cout << "here3" << std::endl;
	if (message.GetMessageType() == dtGame::MessageType::INFO_MAP_LOADED)
	{
		//std::cout << "here3.1" << std::endl;
		if (mUnderWtrSndFilename != NULL)
		{
			//std::cout << "here3.1.1" << std::endl;
			//char* bibble = (char*)malloc(256 * sizeof(char));
			//bibble = "E:/Documents/VRSimLab/D3D250/bin/Content/Sounds/underwater.wav";
			//mUnderWaterSound->LoadFile(bibble);
			mUnderWaterSound->LoadFile(mUnderWtrSndFilename->c_str());
			//mUnderWaterSound->LoadFile("Content/Sounds/underwater.wav");
			//std::cout << mUnderWtrSndFilename->c_str() << std::endl;
			//std::cout << "here3.1.2" << std::endl;
		}

		if (mAboveWtrSndFilename != NULL)
		{
			//std::cout << "here3.1.3" << std::endl;
			mAboveWaterSound->LoadFile(mAboveWtrSndFilename->c_str());
			//std::cout << "here3.1.4" << std::endl;
		}

		if (mUpHighSndFilename != NULL)
		{
			//std::cout << "here3.1.5" << std::endl;
			mUpHighSound->LoadFile(mUpHighSndFilename->c_str());
			//std::cout << "here3.1.6" << std::endl;
		}

		if (mSplashSndFilename != NULL)
		{
			//std::cout << "here3.1.7" << std::endl;
			mSplashSound->LoadFile(mSplashSndFilename->c_str());
			//std::cout << "here3.1.8" << std::endl;
		}
		//std::cout << "here3.2" << std::endl;
	}
	else if (message.GetMessageType() == dtGame::MessageType::TICK_LOCAL)
	{
		if (!mPlayerCamera)
		{
			//dtDAL::ActorProxy* proxy;
			//GetGameManager()->FindActorByName("Camera", proxy);
			//////////GetGameManager()->FindActorByName(mCameraName, proxy);
			mLilCam = GetGameManager()->GetApplication().GetCamera();

			/////////////mCam = static_cast<dtCore::Transformable*>(proxy->GetActor());
			
			//dtAudio::AudioManager::Instantiate();
			
			//GetGameManager()->FindActorByName("UnderWaterSound", proxy);
			//mUnderWaterSound = static_cast<dtAudio::Sound*>(proxy->GetActor());

			//mUnderWaterSound = dtAudio::AudioManager::GetInstance().NewSound();
			////mUnderWaterSound->LoadFile("sounds/bang.wav");
			////mUnderWaterSound->LoadFile("sounds/underwater.wav");
			////mUnderWaterSound->LoadFile("sounds/Diving.wav");
			//mUnderWaterSound->LoadFile(mLoadFile);
			//mUnderWaterSound->SetLooping(true);
			//std::cout << mUnderWaterSound->GetFilename() << std::endl;

			//mUnderWaterSound->Play();
			
			// make global listener move with the camera
			//mLilCam->AddChild(dtAudio::AudioManager::GetInstance().GetListener());

			mPlayerCamera = true;
		}
		
		dtCore::Transform xform;
		///////////////mCam->GetTransform(xform);
		mLilCam->GetTransform(xform);

		float tx;
		float ty;
		float tz;
		xform.GetTranslation(tx, ty, tz);

		if (tz < mOceanHeight)
		{
			//std::cout << mUnderWaterSound->IsPlaying() << std::endl;
			if (mUnderWaterSound->IsPlaying() == 0)
			{
				if (mSplashSound->IsPlaying() == 0)
				{
					if (mShouldSplash)
					{
						mSplashSound->Play();
					}
					else
					{
						mShouldSplash = true;
					}
				}
				mUnderWaterSound->Play();
			}

			if (mAboveWaterSound->IsPlaying() != 0)
			{
				mAboveWaterSound->Stop();
			}

			if (mUpHighSound->IsPlaying() != 0)
			{
				mUpHighSound->Stop();
			}
		}
		else if (tz >= mOceanHeight)
		{
			//dtCore::Transform xform;
			//osg::Vec3f soundPos;
			//mLilCam->GetTransform(xform);
	
			//xform.GetTranslation(soundPos);
			////soundPos.z(mOceanHeight);
			//soundPos.set(soundPos.x(), soundPos.y(), mOceanHeight);

			//mAboveWaterSound->SetPosition(soundPos);
			
			//osg::Vec3f aWtrSndPos;
			//mAboveWaterSound->GetPosition(aWtrSndPos);
			//std::cout << "x: " << aWtrSndPos.x() << " y: " << aWtrSndPos.y() << " z: " << aWtrSndPos.z() << std::endl;
			
			// send ray down to check terrain height

			if (mPhysicsEnabled)
			{
				dtPhysics::PhysicsComponent* physicsComponent = NULL;
				GetGameManager()->GetComponentByName(dtPhysics::PhysicsComponent::DEFAULT_NAME, physicsComponent);
				if (physicsComponent != NULL)
				{
					dtPhysics::RayCast* downRay = new dtPhysics::RayCast();
					downRay->SetOrigin(osg::Vec3f(tx, ty, tz));
					downRay->SetDirection(osg::Vec3f(0, 0, -mOceanSndMaxHeight));

					dtPhysics::RayCast::Report* downReport = new dtPhysics::RayCast::Report();

					physicsComponent->GetPhysicsWorld().TraceRay(*downRay, *downReport);
					
					if (downReport->mHasHitObject)
					{
						//std::cout << "Hit dist: " << downReport->mDistance << std::endl;

						if (downReport->mHitPos.z() > mOceanHeight && (downReport->mHitObject == 0 || downReport->mHitObject->GetName().compare("BoatPhysObj") != 0))
						{
							mAboveOcean = false;
						}
						else
						{
							mAboveOcean = true;
						}
					}
					else
					{
						//std::cout << "no hit" << std::endl;
						//mAboveOcean = true;
					}
				}
			}
			else
			{
				mAboveOcean = true;
			}


			float aboveWtrVolume;
			/*if (!mAboveOcean)
			{
				aboveWtrVolume= 0.0f;
			}*/
			
			// above water volume based on height
			if (tz == mOceanHeight)
			{
				aboveWtrVolume= 1.0f;
			}
			else if ((tz - mOceanHeight) >= mOceanSndMaxHeight)
			{
				aboveWtrVolume= 0.0f;
			}
			else
			{
				aboveWtrVolume= 1 - ((tz - mOceanHeight) / mOceanSndMaxHeight);
			}
			
			// fade above water volume down when above land, up when above water
			if (mAboveOcean && mAboveWtrFade < 1.0)
			{
				mAboveWtrFade += mAboveWtrFadeAmount;
				//aboveWtrVolume = mAboveWtrFade;
				if (mAboveWtrFade > 1.0)
				{
					mAboveWtrFade = 1.0;
				}
			}
			else if (!mAboveOcean && mAboveWtrFade > 0.0)
			{
				mAboveWtrFade -= mAboveWtrFadeAmount;
				//aboveWtrVolume = 1.0;

				if (mAboveWtrFade < 0.0)
				{
					mAboveWtrFade = 0.0;
				}
			}
			
			//std::cout << aboveWtrVolume << std::endl;
			//mAboveWaterSound->SetGain(aboveWtrVolume);
			mAboveWaterSound->SetGain(aboveWtrVolume * mAboveWtrFade);

			if (mUnderWaterSound->IsPlaying() != 0)
			{
				mUnderWaterSound->Stop();
			}
			
			if (mAboveWaterSound->IsPlaying() == 0)
			{
				if (mSplashSound->IsPlaying() == 0)
				{
					if (mShouldSplash)
					{
						mSplashSound->Play();
					}
					else
					{
						mShouldSplash = true;
					}
				}
				mAboveWaterSound->Play();
			}

			if (mUpHighSound->IsPlaying() == 0)
			{
				mUpHighSound->Play();
			}
		}

		//dtCore::Transformable::GetTransform(
			//dtCore::Transform::GetTranslation(
		
    }
	//std::cout << "here4" << std::endl;
}

//////////////////////////////////////////////////////////////////////////
void SuperSoundComponent::EnablePhysics(bool enable)
{
	mPhysicsEnabled = enable;
}
//////////////////////////////////////////////////////////////////////////
void SuperSoundComponent::SetOceanHeight(float height)
{
	//std::cout << "here5" << std::endl;
	mOceanHeight = height;
	//std::cout << "here6" << std::endl;
}
//////////////////////////////////////////////////////////////////////////
void SuperSoundComponent::SetOceanSndMaxHeight(float height)
{
	//std::cout << "here7" << std::endl;
	mOceanSndMaxHeight = height;
	//std::cout << "here8" << std::endl;
}
//////////////////////////////////////////////////////////////////////////
//void SuperSoundComponent::SetUnderWtrSnd(dtDAL::ResourceDescriptor* undWtrSnd)
void SuperSoundComponent::SetUnderWtrSnd(std::string* undWtrSnd)
{
	//std::cout << "here9" << std::endl;
	mUnderWaterSound = dtAudio::AudioManager::GetInstance().NewSound();
	//std::cout << "here9.1" << std::endl;
	if (undWtrSnd != NULL)
	{
		//std::cout << "here9.2" << std::endl;
		//std::cout << "inund: " << *undWtrSnd << std::endl;
		//mUnderWaterSound = dtAudio::AudioManager::GetInstance().NewSound();
		
		//mUnderWaterSound->LoadFile(getFileNameFromRes(undWtrSnd));
		//std::cout << "undtryload: " << (*undWtrSnd).c_str() << std::endl;
		//std::cout << undWtrSnd->c_str() << std::endl;
		//mUnderWaterSound->LoadFile(undWtrSnd->c_str());

		mUnderWtrSndFilename = undWtrSnd;

		//mUnderWaterSound->LoadFile("E:/Documents/VRSimLab/D3D250/bin/Content/Sounds/underwater.wav");
		//std::cout << "here9.3" << std::endl;
		mUnderWaterSound->SetLooping(true);
		//std::cout << "here9.4" << std::endl;
		//std::cout << "und: " << mUnderWaterSound->GetFilename() << std::endl;
	}
	//std::cout << "here10" << std::endl;
}
//////////////////////////////////////////////////////////////////////////
//void SuperSoundComponent::SetAboveWtrSnd(dtDAL::ResourceDescriptor* aboveWtrSnd)
void SuperSoundComponent::SetAboveWtrSnd(std::string* aboveWtrSnd)
{
	//std::cout << "here11" << std::endl;
	mAboveWaterSound = dtAudio::AudioManager::GetInstance().NewSound();
	if (aboveWtrSnd != NULL)
	{
		//std::cout << "inabove: " << *aboveWtrSnd << std::endl;
		//mAboveWaterSound = dtAudio::AudioManager::GetInstance().NewSound();
		
		//mAboveWaterSound->LoadFile(getFileNameFromRes(aboveWtrSnd));
		//std::cout << "abovetryload: " << (*aboveWtrSnd).c_str() << std::endl;
		//mAboveWaterSound->LoadFile(aboveWtrSnd->c_str());
		mAboveWaterSound->SetLooping(true);
		mAboveWaterSound->SetRolloffFactor(0.05f);
		//mAboveWaterSound->SetGain(0.4f);
		//mAboveWaterSound->SetListenerRelative(true);
		//std::cout << "above: " << mAboveWaterSound->GetFilename() << std::endl;

		mAboveWtrSndFilename = aboveWtrSnd;
	}
	//std::cout << "here12" << std::endl;
}
//////////////////////////////////////////////////////////////////////////
//void SuperSoundComponent::SetUpHighSnd(dtDAL::ResourceDescriptor* upHighSnd)
void SuperSoundComponent::SetUpHighSnd(std::string* upHighSnd)
{
	//std::cout << "here13" << std::endl;
	mUpHighSound = dtAudio::AudioManager::GetInstance().NewSound();
	if (upHighSnd != NULL)
	{
		//std::cout << "inuphigh: " << *upHighSnd << std::endl;
		//mUpHighSound = dtAudio::AudioManager::GetInstance().NewSound();
		
		//mUpHighSound->LoadFile(getFileNameFromRes(upHighSnd));
		//mUpHighSound->LoadFile(upHighSnd->c_str());
		mUpHighSound->SetLooping(true);
		//std::cout << "uphigh: " << mUpHighSound->GetFilename() << std::endl;

		mUpHighSndFilename = upHighSnd;
	}
	//std::cout << "here14" << std::endl;
}
//////////////////////////////////////////////////////////////////////////
//void SuperSoundComponent::SetSplashSnd(dtDAL::ResourceDescriptor* splashSnd)
void SuperSoundComponent::SetSplashSnd(std::string* splashSnd)
{
	//std::cout << "here15" << std::endl;
	mSplashSound = dtAudio::AudioManager::GetInstance().NewSound();
	if (splashSnd != NULL)
	{
		//std::cout << "insplash: " << *splashSnd << std::endl;
		//mSplashSound = dtAudio::AudioManager::GetInstance().NewSound();
		
		//mSplashSound->LoadFile(getFileNameFromRes(splashSnd));
		//mSplashSound->LoadFile(splashSnd->c_str());
		mSplashSound->SetLooping(false);
		mSplashSound->SetGain(0.5f);
		//std::cout << "splash: " << mSplashSound->GetFilename() << std::endl;

		mSplashSndFilename = splashSnd;
	}
	//std::cout << "here16" << std::endl;
}
//////////////////////////////////////////////////////////////////////////
char* SuperSoundComponent::getFileNameFromRes(dtDAL::ResourceDescriptor* res)
{
	//std::cout << "here17" << std::endl;
	const std::string resPath = res->GetResourceIdentifier();
	char* filePath = (char*)malloc(resPath.size());
	
	int fileStringPos= 0;
	for (int i= 0; resPath[i] != '\0'; i++)
	{
		if (resPath[i] == ':' && resPath[i + 1] == ':')
		{
			filePath[fileStringPos] = '/';
			i++;
		}
		else
		{
			filePath[fileStringPos] = resPath[i];
		}

		fileStringPos++;
	}

	if (filePath[fileStringPos] != '\0')
	{
		filePath[fileStringPos] = '\0';
	}
	

	return filePath;
	//std::cout << "here18" << std::endl;
}

#endif //VRS_SUPER_WTRNOISE_CPP