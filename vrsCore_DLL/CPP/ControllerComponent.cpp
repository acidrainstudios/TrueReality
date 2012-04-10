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


#ifndef COREDLL_CONTROLLER_COMPONENT_CPP
#define COREDLL_CONTROLLER_COMPONENT_CPP

#include "..\\Include\ControllerComponent.h"
namespace vrsCore
{

	////////////////////////////////////////////////////////////////////
	const std::string ControllerComponent::COMPONENT_DEFAULT_NAME("ControllerComponent");
	////////////////////////////////////////////////////////////////////
	ControllerComponent::ControllerComponent(const std::string& name, bool inPlaybackMode)
	:dtGame::GMComponent(name)
	,eventMsg(0)
	,mLogController(0)
	,mPlayerActorID("NULL")
	,mFocusActorID("NULL")
	,mPlayerActor(0)
	,mFocusActor(0)
	,mInPlaybackMode(inPlaybackMode)
	{
		AddSender(&dtCore::System::GetInstance());		

		//dtCore::System::GetInstance().SetUseFixedTimeStep(true);
		//dtCore::System::GetInstance().SetMaxTimeBetweenDraws(1/3);
		//dtCore::System::GetInstance().SetFrameRate(60);	

		/*
		dtCore::System::GetInstance().SetSystemStages(dtCore::System::SystemStages::STAGE_CAMERA_SYNCH|
					dtCore::System::SystemStages::STAGE_CONFIG |
					dtCore::System::SystemStages::STAGE_EVENT_TRAVERSAL |
					dtCore::System::SystemStages::STAGE_FRAME |
					dtCore::System::SystemStages::STAGE_FRAME_SYNCH |
					dtCore::System::SystemStages::STAGE_POST_EVENT_TRAVERSAL |
					dtCore::System::SystemStages::STAGE_POSTFRAME |
					dtCore::System::SystemStages::STAGE_PREFRAME);
					*/
		
	}

	////////////////////////////////////////////////////////////////////
	void ControllerComponent::SetupEvents()
	{
	}
	////////////////////////////////////////////////////////////////////
	void ControllerComponent::ProcessMessage(const dtGame::Message& message)
	{

		//mDeltaSimTime = GetGameManager()-GetSimulationTime();
/*
		osg::ref_ptr<osgDB::DatabasePager> DBPager = GetGameManager()->GetApplication().GetView()->GetDatabasePager()->GetOsgDatabasePager();
		if(message.GetMessageType() == dtGame::MessageType::TICK_LOCAL)
		{
			if(DBPager->getRequestsInProgress() != 0 || DBPager->getDataToCompileListSize() != 0 || DBPager->getDataToMergeListSize() != 0 || DBPager->getFileRequestListSize() != 0 || DBPager->requiresCompileGLObjects() != 0)
			{
				GetGameManager()->GetApplication().GetCamera()->SetEnabled(false);
				std::cout << "getRequestsInProgress(): " << DBPager->getRequestsInProgress() << std::endl;
				std::cout << "getDataToCompileListSize(): " << DBPager->getDataToCompileListSize() << std::endl;
				std::cout << "getDataToMergeListSize(): " << DBPager->getDataToMergeListSize() << std::endl;
				std::cout << "getFileRequestListSize(): " << DBPager->getFileRequestListSize() << std::endl;
				std::cout << "requiresCompileGLObjects(): " << DBPager->requiresCompileGLObjects() << std::endl << std::endl;
			}
			else if(GetGameManager()->GetApplication().GetCamera()->GetEnabled() == false)
			{
				std::cout << "enabling Camera" << std::endl;
				GetGameManager()->GetApplication().GetCamera()->SetEnabled(true);
			}
		}
		else*/ if(message.GetMessageType() == dtGame::MessageType::INFO_GAME_EVENT)
		{

			const dtGame::GameEventMessage& GameEventMsg = static_cast<const dtGame::GameEventMessage&>(message);
		   
			if (GameEventMsg.GetGameEvent()->GetName() == vrsCore::GAME_EVENT_SHOWSTATISTICS)
			{
				GetGameManager()->GetApplication().SetNextStatisticsType();
			}

		}
		// After the map is finished loading, we will get this.  At which point, our events
		// have been loaded from the map and we can now find them
		else if (message.GetMessageType() == dtGame::MessageType::INFO_MAP_LOADED)
		{
			//GetGameManager()->GetApplication().GetCompositeViewer()->setThreadingModel(osgViewer::ViewerBase::CullThreadPerCameraDrawThreadPerContext);
			//GetGameManager()->GetApplication().GetCompositeViewer()->setThreadingModel(osgViewer::ViewerBase::ThreadingModel::DrawThreadPerContext);
			//GetGameManager()->GetApplication().GetCompositeViewer()->setThreadingModel(osgViewer::ViewerBase::ThreadingModel::ThreadPerCamera);
			//GetGameManager()->GetApplication().GetCompositeViewer()->setThreadingModel(osgViewer::ViewerBase::ThreadingModel::CullDrawThreadPerContext);
			//GetGameManager()->GetApplication().GetCompositeViewer()->setThreadingModel(osgViewer::ViewerBase::ThreadingModel::SingleThreaded);
			//GetGameManager()->GetApplication().GetCompositeViewer()->setThreadingModel(osgViewer::ViewerBase::ThreadingModel::ThreadPerContext);
			SetupEvents();

			//AttachActor();


		}
		// Once the system is started, we find the log controller so we can manipulate it later
		else if (message.GetMessageType() == dtGame::MessageType::INFO_RESTARTED)
		{
			mLogController = static_cast<dtGame::LogController*> (GetGameManager()->GetComponentByName(dtGame::LogController::DEFAULT_NAME));
		}
		//If the focus changed to a different actor, update who the focus is on now...
		else if (message.GetMessageType() == vrsCoreMessageType::MSG_FOCUS_ACTOR_CHANGE)
		{
			const FocusActorChangeMsg& focusActorChangeMsg = static_cast<const FocusActorChangeMsg&>(message);
			mFocusActorID = focusActorChangeMsg.GetNewFocusActorUniqueId();
		}
		//If the player changed to a different actor, update who the player is on now...
		else if (message.GetMessageType() == vrsCoreMessageType::MSG_PLAYER_ACTOR_CHANGE)
		{
			//Grabs the camera and places is on the actor that is controlled by the player...
			//The last Actor to send out the MSG_PLAYER_ACTOR_CHANGE gets the camera...

			osg::ref_ptr<dtCore::Camera> camera = GetGameManager()->GetApplication().GetCamera();
			
			if(mPlayerActorID.ToString() != "NULL")
			{	//if the camera is already attach... detach it....
				mPlayerActor = static_cast<vrsCore::GenericActor*>(GetGameManager()->FindActorById(mPlayerActorID)->GetActor());
				mPlayerActor->RemoveChild(camera);
			}
			
			const PlayerActorChangeMsg& playerActorChangeMsg = static_cast<const PlayerActorChangeMsg&>(message);
			mPlayerActorID = playerActorChangeMsg.GetNewPlayerActorUniqueId();

			mPlayerActor = static_cast<vrsCore::GenericActor*>(GetGameManager()->FindActorById(mPlayerActorID)->GetActor());

			//transform for our cam....
			dtCore::Transform tx;
			//Read in the Camera offset from the actor and apply it to the camera. 
			//Then attach the camera
			tx.SetTranslation(mPlayerActor->GetCameraOffset());
			camera->SetTransform(tx, dtCore::Transformable::REL_CS);
			mPlayerActor->AddChild(camera);


			
		}
		
	}
	//////////////////////////////////////////////////////////////////////////
	//void ControllerComponent::AttachActor(void)
	//{

	//	std::cout << "Attaching Actors" << std::endl;

	//	dtDAL::ActorProxy* HappyProxy;
	//	GetGameManager()->FindActorByName("Happy", HappyProxy); 
	//	

	//	dtDAL::ActorProxy* TriProxy;
	//	GetGameManager()->FindActorByName("Tri", TriProxy); 
	//	

	//	if(HappyProxy != NULL && TriProxy != NULL)
	//	{
	//		dtCore::Object* HappyActor = dynamic_cast<dtCore::Object*>(HappyProxy->GetActor());
	//		dtCore::Object* TriActor = dynamic_cast<dtCore::Object*>(TriProxy->GetActor());

	//		TriActor->Emancipate();
	//		std::cout << "Setting a new Parent" << std::endl;

	//		dtCore::Transform tx;
	//		tx.SetTranslation(0, 0, 0);
	//		TriActor->SetTransform(tx);
	//		

	//		HappyActor->AddChild(TriActor);
	//	}
	//	else
	//	{
	//		std::cout << "Actors Not Found" << std::endl;
	//	}
	//	
	//}
	//////////////////////////////////////////////////////////////////////////
	void ControllerComponent::OnMessage(MessageData *data)
	{
		if(data->message == dtCore::System::MESSAGE_POST_EVENT_TRAVERSAL)
		{
			dtABC::Application& app = GetGameManager()->GetApplication();
			///////////////////////////////////
			///////////////////////////////////

			if(app.GetKeyboard()->GetKeyState('p'))
			{
				//dtCore::System::GetInstance().SetPause(!dtCore::System::GetInstance().GetPause());
				//GetGameManager()->SetPaused(!GetGameManager()->IsPaused());
				if(dtCore::System::GetInstance().GetTimeScale() == 0.0)
				{
					dtCore::System::GetInstance().SetTimeScale(1);
				}
				else
				{
					dtCore::System::GetInstance().SetTimeScale(0);
				}

				#ifdef _DEBUG
						printf("Pausing.. GM is now [%s].\r\n", (GetGameManager()->IsPaused() ? "ON" : "OFF"));
				#endif //_DEBUG
			}

			///////////////////////////////////
			///////////////////////////////////
			if(app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Escape))
			{
				app.GetCompositeViewer()->setThreadingModel(osgViewer::ViewerBase::SingleThreaded);
				app.Quit();
			}
		}

		
	}

	//////////////////////////////////////////////////////////////////////////
	void ControllerComponent::FireGameEvent(const dtDAL::GameEvent& event)
	{
	   dtCore::RefPtr<dtGame::GameEventMessage> eventMsg;

	   GetGameManager()->GetMessageFactory().CreateMessage(dtGame::MessageType::INFO_GAME_EVENT, eventMsg);

	   eventMsg->SetGameEvent(event);				//Set the game envent to lunch
	   
	   eventMsg->SetAboutActorId(mFocusActorID);		//Set the actor this even is about

	   GetGameManager()->SendMessage(*eventMsg);	//Send the MSG out
	}
}
#endif //COREDLL_CONTROLLER_COMPONENT_H