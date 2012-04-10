/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* Virtual Reality Simulation Lab
*
* This file is part of Virtual Reality Simulation Lab software; you can redistribute 
* it and/or modify it under the terms of the GNU Lesser General Public License as 
* published by the Free Software Foundation; either version 2.1 of the License, or 
* (at your option) any later version.
*
* By the GNU LGP License any changes or modification you made must be sent back 
* to the original owner of the file, and appropriate credit given.
*
* This file is distributed WITHOUT ANY WARRANTY; without even the implied warranty 
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General 
* Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* This software was developed by Maxim Serebrennik for various projects he worked on. 
* For more information e-mail him at MaximSter@gmail.com
*
* @author Maxim Serebrennik
*////////////////////////////////////////////////////////////////////////////////

#ifndef VRS_UFVG_ACTOR_CPP
#define VRS_UFVG_ACTOR_CPP

#include "..\\Include\ActorUFVG.h"
namespace vrsUFVG
{
	///////////////////////////////////////////////////////////////////////////////
	const std::string UFVGActor::ACTOR_DEFAULT_NAME("UFVG Actor");
	///////////////////////////////////////////////////////////////////////////////

	UFVGActor::UFVGActor(vrsCore::GameStaticMeshActorProxy& proxy)
	:vrsCore::GameStaticMeshActor(proxy)
	,mPropertiesUpdated(false)
	,mRecordNum(1)
	,mPlaybackSpeed(10.0f)
	,mPlaybackTimer(0.0f)
	,mDataFileName("Data/sample.vel")		//Data File Path and Name
	,mGeomFileName("arrow.ive")				//Geometry File Path and Name
	{
		SetName(ACTOR_DEFAULT_NAME); //Set the instences Name
		//Set the Actor Description
		SetDescription("Underwater Flow Vector Generator is used to display Acoustic Doppler Current Profiler Data Files"); 
	}

	///////////////////////////////////////////////////////////////////////////////
	void UFVGActor::OnTickLocal(const dtGame::TickMessage& tickMessage)
	{
		mDeltaSimTime = tickMessage.GetDeltaSimTime();
		

		//Controll the playback advance
		if(mPlaybackTimer>(1.0f/mPlaybackSpeed))
		{
			mRecordNum++;
			if(mRecordNum >= mDataReader.GetNumberOfRecords())
			{
				mRecordNum = 1;
			}

			mPlaybackTimer = 0.0f;

		}


		
		//float h, p, r;
		dtCore::Transform t;
		osg::Vec3f  vector;
		
		//Rotate the Bubbles
		for(int i = (mDataReader.GetLowestBinNum()-1); i < mDataReader.GetHeightestBinNum(); i++)
		{

			mBubbles[i]->GetTransform(t);
			t.GetRotation(vector);
			//This math is wrong....  need to pass degrees, not vector length....
			//Will fix later......need to calculate the degrees with the NetCDF Reader....
			vector.set(mDataReader.GetX(mRecordNum,i+1), 
						90+mDataReader.GetZ(mRecordNum,i+1), 
						mDataReader.GetY(mRecordNum,i+1));
			t.SetRotation(vector);
			mBubbles[i]->SetTransform(t);
		}

		if (mPropertiesUpdated)
		{
			GetGameActorProxy().NotifyFullActorUpdate();
			mPropertiesUpdated = false;
		}

		mPlaybackTimer += mDeltaSimTime;
	}

	///////////////////////////////////////////////////////////////////////////////
	void UFVGActor::OnTickRemote(const dtGame::TickMessage& tickMessage)
	{
		mDeltaSimTime = tickMessage.GetDeltaSimTime();
	}

	///////////////////////////////////////////////////////////////////////////////
	void UFVGActor::ProcessMessage(const dtGame::Message& message)
	{
		if (message.GetMessageType() == dtGame::MessageType::INFO_GAME_EVENT)
		{
			const dtGame::GameEventMessage& eventMsg = static_cast<const dtGame::GameEventMessage&>(message);

			// Note, we are using strings which aren't constants.  In a real application, these
			// event names should be stored in some sort of shared place and should be constants...
			/*
			if (eventMsg.GetGameEvent() != NULL)
			{
				// Handle "ToggleEngine" Game Event
				if (eventMsg.GetGameEvent()->GetName() == "Ignition" && mIgnitionTimer > 1.0f)
				{
					mIsEngineRunning = !mIsEngineRunning;
					#ifdef _DEBUG
						printf("Toggling Engines to the [%s] state.\r\n", (mIsEngineRunning ? "ON" : "OFF"));
					#endif //_DEBUG

					mIgnitionTimer = 0.0f;
				}
				
			}*/
		}
	}
	///////////////////////////////////////////////////////////////////////////////
	void UFVGActor::OnEnteredWorld()
	{
		//Load the Data File
		mDataReader.LoadFile(mDataFileName);
		//mDataReader.LoadFile(dtCore::GetDeltaDataPathList() + "/sample.vel");
		//mDataReader.LoadFile(dtCore::FindFileInPathList("samplex.vel"));
		//FindFileInPathList

		

		for(int i = (mDataReader.GetLowestBinNum()-1); i<mDataReader.GetHeightestBinNum(); i++)
		{

			vrsCore::GameStaticMeshActor::OnEnteredWorld();

			// add our bubbles particle
			dtCore::Transform t(0.0f,0.0f,(0.0f+i*(mDataReader.GetBinHeight())),0.0f,0.0f,0.0f);

	//		mBubbles[i] = new dtCore::ParticleSystem();
			//mBubbles[i]->LoadFile(PARTICLES_PATH + "bubble.osg",false);
			mBubbles[i] = new dtCore::Object();
			mBubbles[i]->LoadFile(mGeomFileName,true);
			//mBubbles[i]->SetEnabled(true);
			mBubbles[i]->SetTransform(t);
			AddChild(mBubbles[i].get());
		}

		GetOSGNode()->getStateSet()->setRenderBinDetails(50, "RenderBin");
	}
	///////////////////////////////////////////////////////////////////////////////

	void UFVGActor::SetPlaybackSpeed(float Speed)
	{
		mPlaybackSpeed = Speed;
	}
	///////////////////////////////////////////////////////////////////////////////
	float UFVGActor::GetPlaybackSpeed(void)
	{
		return mPlaybackSpeed;
	}
	///////////////////////////////////////////////////////////////////////////////
	void UFVGActor::SetDataFile(std::string FileName)
	{
		mDataFileName = FileName;
	}
	///////////////////////////////////////////////////////////////////////////////
	std::string UFVGActor::GetDataFile(void)
	{
		return mDataFileName;
	}
	///////////////////////////////////////////////////////////////////////////////
	void UFVGActor::SetGeomFile(std::string FileName)
	{
		mGeomFileName = FileName;
	}
	///////////////////////////////////////////////////////////////////////////////
	std::string UFVGActor::GetGeomFile(void)
	{
		return mGeomFileName;
	}
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	UFVGActorProxy::UFVGActorProxy()
	{
	   SetClassName(UFVGActor::ACTOR_DEFAULT_NAME); //Set the actors Class Name  
	}

	///////////////////////////////////////////////////////////////////////////////
	void UFVGActorProxy::BuildPropertyMap()
	{
	   const std::string Actor_GROUP = "Actor Properties"; //Property group name
	   //const std::string Motion_GROUP = Actor_GROUP + ".Motion Properties"; //Property group name

	   //dtDAL::ActorProxy::BuildPropertyMap();
	   //TransformableActorProxy::BuildPropertyMap();
	   //dtDAL::PhysicalActorProxy::BuildPropertyMap();
	   //dtGame::GameActorProxy::BuildPropertyMap();
	   vrsCore::GameStaticMeshActorProxy::BuildPropertyMap();

	   UFVGActor& actor = dynamic_cast<UFVGActor&>(GetGameActor());

	   /*
	   // Check if "static mesh" property exist.....
	   dtDAL::ResourceActorProperty* resourceProperty;
	   GetProperty("static mesh", resourceProperty);
	   assert(resourceProperty);

	   // Automatically default the mesh to the one we want
	   dtDAL::ResourceDescriptor meshDescriptor("StaticMeshes:Vehicle:Space:AWing:AWing.ive");
	   resourceProperty->SetValue(&meshDescriptor);
	   */
	}

	///////////////////////////////////////////////////////////////////////////////
	void UFVGActorProxy::CreateActor()
	{
	   SetActor(*new UFVGActor(*this));
	}

	///////////////////////////////////////////////////////////////////////////////
	void UFVGActorProxy::OnEnteredWorld()
	{

	   //Register an invokable for Game Events...
	   //RegisterForMessages(dtGame::MessageType::INFO_GAME_EVENT);
		RegisterForMessagesAboutSelf(dtGame::MessageType::INFO_GAME_EVENT);

	   // Register an invokable for tick messages. Local or Remote only, not both!
	   if (IsRemote())
	   {
		  RegisterForMessages(dtGame::MessageType::TICK_REMOTE,
			 dtGame::GameActorProxy::TICK_REMOTE_INVOKABLE);
	   }
	   else
	   {
		  RegisterForMessages(dtGame::MessageType::TICK_LOCAL,
			 dtGame::GameActorProxy::TICK_LOCAL_INVOKABLE);
	   }

	   
	   vrsCore::GameStaticMeshActorProxy::OnEnteredWorld();
	}
}

#endif //VRS_UFVG_ACTOR_CPP