/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* CS900 DLL Stevens Institute of Technology Picatinny Arsenal Demo Project
*
* CopyRight © The Stevens Institute of Technology 2010
*
* @author CS900 Project:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////


#ifndef VRS_PICATINNY_COMPONENT_CPP
#define VRS_PICATINNY_COMPONENT_CPP

#include "..\\Include\CameraComponent.h"

////////////////////////////////////////////////////////////////////
const std::string CameraComponent::COMPONENT_DEFAULT_NAME("CameraComponent");

const std::string CameraComponent::MONITOR2_TIMER_NAME("Monitor2TimerName");
////////////////////////////////////////////////////////////////////
CameraComponent::CameraComponent(const std::string& name)
:dtGame::GMComponent(name)
,mDeltaSimTime(0.0f)
,mLastSimTime(0)
,mSimTime(0)
,mMonCamLink(0,1, 2)
,mMon0Size(200,200), mMon0ScrPos(0,0), mMon1Size(200,200), mMon1ScrPos(200,0), mMon2Size(200,200), mMon2ScrPos(400,0)
,mManualSetCam(false)
{
	AddSender(&dtCore::System::GetInstance());			
}

////////////////////////////////////////////////////////////////////
void CameraComponent::SetupEvents()
{

}

//////////////////////////////////////////////////////////////////////////
void CameraComponent::ProcessMessage(const dtGame::Message& message)
{
	if (message.GetMessageType() == dtGame::MessageType::TICK_LOCAL)
	{
		mSimTime = GetGameManager()->GetSimulationTime();
		mDeltaSimTime = mSimTime - mLastSimTime;
		
		mLastSimTime = mSimTime;
	}
	else if (message.GetMessageType() == dtGame::MessageType::INFO_GAME_EVENT)
	{
		const dtGame::GameEventMessage& eventMsg = static_cast<const dtGame::GameEventMessage&>(message);

		if (eventMsg.GetGameEvent() != NULL)
		{
			// Handle "F11" Game Event
			if (eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_F11)
			{
				CycleMon0Cam();
			}
			// Handle "F12" Game Event
			else if (eventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_F12)
			{
				CycleMon1Cam();
			}
		}
	}
	else if(message.GetMessageType() == dtGame::MessageType::INFO_TIMER_ELAPSED)
	{
		const dtGame::TimerElapsedMessage& timeMsg = static_cast<const dtGame::TimerElapsedMessage&>(message);
		if (timeMsg.GetTimerName() == MONITOR2_TIMER_NAME)
		{
			CycleMon2Cam();
		}
	}
	else if (message.GetMessageType() == dtGame::MessageType::INFO_MAP_LOADED)
	{
		//Setup Our Cameras and Monitors
		SetupCamMonitors();	

		//Create our timers
		GetGameManager()->SetTimer(MONITOR2_TIMER_NAME, NULL, 2.0f, true);

		/*dtDAL::ActorProxy* proxie;
		GetGameManager()->FindActorByName("Player", proxie);
		dtGame::GameActor* mTrackedActor = dynamic_cast<dtGame::GameActor*>(proxie->GetActor());
		mCameraAct[0]->TrackActor(mTrackedActor->GetUniqueId());
		mCameraAct[0]->TrackingOn(true);

		mCameraAct[0]->SetPowerOn(false);*/

		if(mManualSetCam)
		{
			SetCameraOnMonitor0ByName(mCamNameToFind);
		}
		
	}
}
//////////////////////////////////////////////////////////////////////////
void CameraComponent::OnMessage(MessageData *data)
{
		
}
//////////////////////////////////////////////////////////////////////////
void CameraComponent::OnAddedToGM(void)
{
	dtGame::GMComponent::OnAddedToGM();
}
void CameraComponent::SetMonitor0Size(osg::Vec2f size)
{
	mMon0Size = size;
}
//////////////////////////////////////////////////////////////////////////
void CameraComponent::SetMonitor0ScreenPosition(osg::Vec2f pos)
{
	mMon0ScrPos = pos;
}
//////////////////////////////////////////////////////////////////////////
void CameraComponent::SetCameraOnMonitor0ByName(std::string CamName)
{
	mCamNameToFind = CamName;
	mManualSetCam = true;

	//mMonCamLink

	int CamNum = 0;
	for(; CamNum<(signed)mCameraAct.size(); CamNum++)
	{
		if(mCameraAct[CamNum]->GetName() == mCamNameToFind)
		{
			if(mMonCamLink.x() != CamNum)
			{
				//Hide the current view
				mViews[mMonCamLink.x()]->SetRenderOrder(1);

				//Make sure Mon1 and Mon2 are not on the
				//Cam number we are looking for
				while((CamNum == mMonCamLink.y()) || (CamNum == mMonCamLink.z()))
				{
					if(CamNum == mMonCamLink.y())
					{
						CycleMon1Cam();
					}
					if(CamNum == mMonCamLink.z())
					{
						CycleMon2Cam();
					}
				}
				//Cycle to the Cam Num we are looking for
				while(mMonCamLink.x() != CamNum)
				{
					CycleMon0Cam();
				}
			}
			
		}
	}
}
//////////////////////////////////////////////////////////////////////////
void CameraComponent::SetupCamMonitors(void)
{
	
	//Get the window position and size
	int WinHeight = 0;
	int WinWidth =	0;
	int WinXpos = 0;
	int WinYpos = 0;
	GetGameManager()->GetApplication().GetWindow()->GetOsgViewerGraphicsWindow()->getWindowRectangle(WinXpos, WinYpos, WinWidth, WinHeight);
	
	mMon0ScrPos.set(0, WinHeight-mMon0Size.y());
	mMon1ScrPos.set(mMon0Size.x(), WinHeight-mMon1Size.y());
	mMon2ScrPos.set(mMon0Size.x()+mMon1Size.x(), WinHeight-mMon2Size.y());

	//find actors by TYPE
	std::vector<dtDAL::ActorProxy*> proxies;
	GetGameManager()->FindActorsByType(*PicatinnyActorsRegistry::PICA_CAMERA_ACTOR_TYPE, proxies); 


	//Create a vector of actors so we can access them directly
	//And a vector of our views
	for(int i=0; i<(signed)proxies.size(); i++)
	{
		PicaCameraActor* actor = static_cast<PicaCameraActor*>(proxies[i]->GetActor());
		mCameraAct.push_back(actor);

		dtCore::View* CamView = new dtCore::View();
		CamView->SetScene(GetGameManager()->GetApplication().GetScene());
		CamView->SetCamera(actor->GetDtCoreCamera());
		CamView->SetRenderOrder(1);
		GetGameManager()->GetApplication().AddView(*CamView);
		mViews.push_back(CamView);
	}

	//Add the first 3 cameras to the monitoes...if they exist...
	if(mCameraAct.size()>0)
	{
		mCameraAct[0]->GetDtCoreCamera()->GetOSGCamera()->setViewport(new osg::Viewport(mMon0ScrPos.x(), mMon0ScrPos.y(), mMon0Size.x(), mMon0Size.y()));
		mViews[0]->SetRenderOrder(10);
	}
	if(mCameraAct.size()>1)
	{
		mCameraAct[1]->GetDtCoreCamera()->GetOSGCamera()->setViewport(new osg::Viewport(mMon1ScrPos.x(), mMon1ScrPos.y(), mMon1Size.x(), mMon1Size.y()));
		mViews[1]->SetRenderOrder(10);
	}
	if(mCameraAct.size()>2)
	{
		mCameraAct[2]->GetDtCoreCamera()->GetOSGCamera()->setViewport(new osg::Viewport(mMon2ScrPos.x(), mMon2ScrPos.y(), mMon2Size.x(), mMon2Size.y()));
		mViews[2]->SetRenderOrder(10);
	}

	
	

}
//////////////////////////////////////////////////////////////////////////
void CameraComponent::CycleMon0Cam(void)
{
	//Place the current Monitor in the back
	mViews[mMonCamLink.x()]->SetRenderOrder(1);

	//add 1 to the camera number
	mMonCamLink.set(mMonCamLink.x()+1, mMonCamLink.y(), mMonCamLink.z());

	
	//if pointing at the same cam, add 1 again
	if(mMonCamLink.x() == mMonCamLink.y())
	{
		mMonCamLink.set(mMonCamLink.x()+1, mMonCamLink.y(), mMonCamLink.z());
	}
	if(mMonCamLink.x() == mMonCamLink.z())
	{
		mMonCamLink.set(mMonCamLink.x()+1, mMonCamLink.y(), mMonCamLink.z());
	}
	//if at the end of the list, reset to 0
	if(mCameraAct.size() <= (mMonCamLink.x()))
	{
		mMonCamLink.set(0, mMonCamLink.y(), mMonCamLink.z());
		while((mMonCamLink.x()==mMonCamLink.y()) || (mMonCamLink.x()==mMonCamLink.z()))
		{
			mMonCamLink.set(mMonCamLink.x()+1, mMonCamLink.y(), mMonCamLink.z());
		}
		
	}

	mViews[mMonCamLink.x()]->SetRenderOrder(10);
	mCameraAct[mMonCamLink.x()]->GetDtCoreCamera()->GetOSGCamera()->setViewport(new osg::Viewport(mMon0ScrPos.x(), mMon0ScrPos.y(), mMon0Size.x(), mMon0Size.y()));
}
//////////////////////////////////////////////////////////////////////////
void CameraComponent::CycleMon1Cam(void)
{
	if(mCameraAct.size() > 1)
	{
		//Place the current Monitor in the back
		mViews[mMonCamLink.y()]->SetRenderOrder(1);

		//add 1 to the camera number
		mMonCamLink.set(mMonCamLink.x(), mMonCamLink.y()+1, mMonCamLink.z());

		
		//if pointing at the same cam, add 1 again
		if(mMonCamLink.y() == mMonCamLink.x())
		{
			mMonCamLink.set(mMonCamLink.x(), mMonCamLink.y()+1, mMonCamLink.z());
		}
		if(mMonCamLink.y() == mMonCamLink.z())
		{
			mMonCamLink.set(mMonCamLink.x(), mMonCamLink.y()+1, mMonCamLink.z());
		}
		//if at the end of the list, reset to 0
		if(mCameraAct.size() <= (mMonCamLink.y()))
		{
			mMonCamLink.set(mMonCamLink.x(), 0, mMonCamLink.z());
			while((mMonCamLink.y()==mMonCamLink.x()) || (mMonCamLink.y()==mMonCamLink.z()))
			{
				mMonCamLink.set(mMonCamLink.x(), mMonCamLink.y()+1, mMonCamLink.z());
			}
			
		}

		mViews[mMonCamLink.y()]->SetRenderOrder(10);
		mCameraAct[mMonCamLink.y()]->GetDtCoreCamera()->GetOSGCamera()->setViewport(new osg::Viewport(mMon1ScrPos.x(), mMon1ScrPos.y(), mMon1Size.x(), mMon1Size.y()));
	}

}
//////////////////////////////////////////////////////////////////////////
void CameraComponent::CycleMon2Cam(void)
{
	if(mCameraAct.size() > 2)
	{
		//Place the current Monitor in the back
		mViews[mMonCamLink.z()]->SetRenderOrder(1);

		//add 1 to the camera number
		mMonCamLink.set(mMonCamLink.x(), mMonCamLink.y(), mMonCamLink.z()+1);

		
		//if pointing at the same cam, add 1 again
		if(mMonCamLink.z() == mMonCamLink.x())
		{
			mMonCamLink.set(mMonCamLink.x(), mMonCamLink.y(), mMonCamLink.z()+1);
		}
		if(mMonCamLink.z() == mMonCamLink.y())
		{
			mMonCamLink.set(mMonCamLink.x(), mMonCamLink.y(), mMonCamLink.z()+1);
		}
		//if at the end of the list, reset to 0
		if(mCameraAct.size() <= (mMonCamLink.z()))
		{
			mMonCamLink.set(mMonCamLink.x(), mMonCamLink.y(), 0);
			while((mMonCamLink.z()==mMonCamLink.x()) || (mMonCamLink.z()==mMonCamLink.y()))
			{
				mMonCamLink.set(mMonCamLink.x(), mMonCamLink.y(), mMonCamLink.z()+1);
			}
			
		}
		
		mViews[mMonCamLink.z()]->SetRenderOrder(10);
		mCameraAct[mMonCamLink.z()]->GetDtCoreCamera()->GetOSGCamera()->setViewport(new osg::Viewport(mMon2ScrPos.x(), mMon2ScrPos.y(), mMon2Size.x(), mMon2Size.y()));
	}
}
//////////////////////////////////////////////////////////////////////////

#endif //Tracker_COMPONENT_H