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


#ifndef UFVG_COMPONENT_CPP
#define UFVG_COMPONENT_CPP

#include "..\\Include\UFVGComponent.h"
namespace vrsUFVG
{
	////////////////////////////////////////////////////////////////////
	const std::string UFVGComponent::COMPONENT_DEFAULT_NAME("UFVGComponent");
	////////////////////////////////////////////////////////////////////
	const std::string UFVGComponent::UPDATE_TIMER_NAME("UpdateTimer");
	////////////////////////////////////////////////////////////////////
	UFVGComponent::UFVGComponent(const std::string& name)
	:dtGame::GMComponent(name)
	//,eventMsg(0)
	//,StatisticsTimer(0.0f)
	,mDeltaSimTime(0.0f)
	,mLastSimTime(0)
	,mSimTime(0)
	//,mLogController(0)
	//,mInPlaybackMode(inPlaybackMode)
	,mPlayerActorID("NULL")
	,mFocusActorID("NULL")
	,mPlayerActor(0)
	,mFocusActor(0)
	,mTimer(0)
	,mUFVGActor(0)
	,mPagedTerrainActor(0)
	,mCurColumnID(0)
	,mTree(new ColumnKDTree(std::ptr_fun(KDHolderIndexFunc)))
	{
		AddSender(&dtCore::System::GetInstance());			
	}
	////////////////////////////////////////////////////////////////////
	UFVGComponent::~UFVGComponent()
	{
		if(mTree != NULL)
		{
			delete mTree;
			mTree = NULL;
		}
	}

	////////////////////////////////////////////////////////////////////
	void UFVGComponent::SetupEvents()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void UFVGComponent::ProcessMessage(const dtGame::Message& message)
	{
		//std::cout <<"UFVGComponent ProcessMessage" << std::endl;

		if (message.GetMessageType() == dtGame::MessageType::TICK_LOCAL)
		{
			//Calculate DeltaTime
			mSimTime = GetGameManager()->GetSimulationTime();
			mDeltaSimTime = mSimTime - mLastSimTime;
			mLastSimTime = mSimTime;
		}
		//else if(message.GetMessageType() == dtGame::MessageType::SYSTEM_FRAME_SYNCH)
		//{
		//}
		else if (message.GetMessageType() == vrsCore::vrsCoreMessageType::MSG_PLAYER_ACTOR_CHANGE)
		{
			const vrsCore::PlayerActorChangeMsg& playerActorChangeMsg = static_cast<const vrsCore::PlayerActorChangeMsg&>(message);
			mPlayerActorID = playerActorChangeMsg.GetNewPlayerActorUniqueId();
		}
		else if (message.GetMessageType() == dtGame::MessageType::INFO_MAP_LOADED)
		{
			//Find the Terrain Actor
			dtDAL::ActorProxy* TerrainProxy;
			GetGameManager()->FindActorByType(*vrsCore::CoreActorsRegistry::PAGED_TERRAIN_ACTOR_TYPE, TerrainProxy);
			if(TerrainProxy != NULL)
			{
				//Find the terrain actor
				mPagedTerrainActor = static_cast<vrsCore::PagedTerrainActor*>(TerrainProxy->GetActor());
			}

			//Attach UFVG actor to the screen and set up the display
			SetupDisplay();

			//Setup the Positional tree
			SetupKDTree();

			//Create our timers
			GetGameManager()->SetTimer(UPDATE_TIMER_NAME, NULL, 1.0f, true);
		}
		else if(message.GetMessageType() == dtGame::MessageType::INFO_TIMER_ELAPSED)
		{
			const dtGame::TimerElapsedMessage& timeMsg = static_cast<const dtGame::TimerElapsedMessage&>(message);
			if (timeMsg.GetTimerName() == UPDATE_TIMER_NAME)
			{
				
				if(mUFVGActor.valid())
				{
					dtCore::Transform t;
					osg::Vec3f pos;
					mUFVGActor->GetTransform(t);
					t.GetTranslation(pos);

					//std::cout << "x:" << pos.x() << " y:" << pos.y() << " z:" << pos.z() << std::endl;

					//osg::Vec3f TestPos(0,75,0);
					float maxRadius = 1024.0f;

					find_result found = mTree->find_nearest(pos, maxRadius);
					if ((found.first != mTree->end()) && (mCurColumnID != found.first->mID))
			        {              
						mCurColumnID = found.first->mID;
						
						//std::cout << "Changing Column to ID:" << found.first->mID << " x:" <<found.first->d[0] << " y:" <<found.first->d[1] << std::endl;  
						//std::cout << "ID:" << found.first->mID << " x:" << mColumnIndex[mCurColumnID].xPos << " y:" << mColumnIndex[mCurColumnID].yPos << " xUTM:" << mColumnIndex[mCurColumnID].xUTM << " yUTM:" << mColumnIndex[mCurColumnID].yUTM << " Lat:" << mColumnIndex[mCurColumnID].LatVal << " Lon:" << mColumnIndex[mCurColumnID].LonVal << std::endl;  
						
						//Update our visual 
						mUFVGActor->SetXPosition(mColumnIndex[mCurColumnID].xPos);
						mUFVGActor->SetYPosition(mColumnIndex[mCurColumnID].yPos);
						mUFVGActor->Reload();
			        }



					
				}
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////

	void UFVGComponent::OnMessage(MessageData *data)
	{
		/*
		if(data->message == "posteventtraversal")
		{

			dtABC::Application& app = GetGameManager()->GetApplication();
			///////////////////////////////////
			///////////////////////////////////

			if(app.GetKeyboard()->GetKeyState('p'))
			{
				GetGameManager()->SetPaused(!GetGameManager()->IsPaused());
				
				#ifdef _DEBUG
						printf("Pausing.. GM is now [%s].\r\n", (GetGameManager()->IsPaused() ? "ON" : "OFF"));
				#endif //_DEBUG
			}

			/*
			if(app.GetKeyboard()->GetKeyState('`') && StatisticsTimer > 5.5f)
			{
				GetGameManager()->GetApplication().SetNextStatisticsType();
				
				StatisticsTimer = 0.0f;
			}
			
		///////////////////////////////////
		///////////////////////////////////


			if(app.GetKeyboard()->GetKeyState(osgGA::GUIEventAdapter::KEY_Escape))
			{
				app.GetCompositeViewer()->setThreadingModel(osgViewer::ViewerBase::SingleThreaded);
				app.Quit();
			}
		}
		*/

		
	}
	//////////////////////////////////////////////////////////////////////////
	void UFVGComponent::SetupDisplay()
	{
		//Find the UFVG Actor
		dtDAL::ActorProxy* UFVGProxy;
		GetGameManager()->FindActorByType(*UFVGActorsRegistry::UFVGNETCDF_ACTOR_TYPE, UFVGProxy); 

		if(UFVGProxy != NULL)
		{
			//Find the actor and detach the parent
			mUFVGActor = static_cast<UFVGnetCDFActor*>(UFVGProxy->GetActor());
			mUFVGActor->Emancipate();

			if(mPlayerActorID.ToString() != "NULL")
			{	//find the PlayerActor
				mPlayerActor = static_cast<vrsCore::GenericActor*>(GetGameManager()->FindActorById(mPlayerActorID)->GetActor());
				dtCore::Transform tx;
				tx.SetTranslation(0, 0, 0);
				mUFVGActor->SetTransform(tx);
			
				//Add the UFVG actor to the Player Actor
				mPlayerActor->AddChild(mUFVGActor.get());
			}
			else
			{
				std::cout << "Player Not Found" << std::endl;
			}
		}
		else
		{
			std::cout << "UFVG Actor Not Found" << std::endl;
		}

	}
	//////////////////////////////////////////////////////////////////////////
	void UFVGComponent::SetupKDTree()
	{
		//////////////////////
		//index file format
		//XPos YPos NumOfSig NumTimeRec
		//sigma levels(11 of them)
		//sigma levels(11 of them)
		//sigma lev ...
		//..
		//x y Lat Lon (all the file lists...)
		//... 
		std::string UFVGIndexFileName = "Data/NetCDF/index.UFVG"; 

		std::ifstream UFVGIndexFile;		//file sream
		
		UFVGIndexFile.open(UFVGIndexFileName.c_str(),std::ios_base::in);
		if (!UFVGIndexFile.is_open())
		{	
			std::cout << "-->Error Could not find " << UFVGIndexFileName << std::endl;
			UFVGIndexFile.close();
		}


		int mXMax, mYMax, mNumOfSig, mTotalRecordNum;	//holds the # of X y columbs, #of sigmas, and total # of time records
		float SigDump;									//used to ignore Sigma vals in the index file
		//int xCol, yCol;								//used to store X and Y val of the columb being read
		//float LatVal, LonVal;							//used to store Lat and Lon of the given data columb

		//Get the file reader to the right data point by skipping/reading in unwanted data....
		UFVGIndexFile >> mXMax >> mYMax >> mNumOfSig >> mTotalRecordNum;
		for(int i=0; i<mNumOfSig; i++)
		{
			UFVGIndexFile >> SigDump;
		}


		ColumnData DataNode;							//holds the x, y position for each column
		int ColumnCount = 0;							//holds an index number for each column for the KDTree
		osg::Vec3f ColumnPos;							//Vector that passes the position to the KDTree
		osg::Vec3 xyzPos;								//Vector that holds the xyz position of the column
		
		//Construct the Tree and the Index Vector
		while(!UFVGIndexFile.eof())
		{

			UFVGIndexFile >> DataNode.xPos >> DataNode.yPos >> DataNode.LatVal >> DataNode.LonVal;
			
			//Convert Lat/Lon to UTM (has to be preconfigured on the mPagedTerrainActor)
			xyzPos.set(mPagedTerrainActor->ConvertIncomingToLocalTranslation(osg::Vec3d(DataNode.LatVal, DataNode.LonVal, 0)));
			DataNode.xUTM = xyzPos.x();
			DataNode.yUTM = xyzPos.y();
			
			mColumnIndex.push_back(DataNode);
			
			ColumnPos.set(DataNode.xUTM, DataNode.yUTM, 0.0f);

			vrsUFVG::KDHolder node(ColumnPos, ColumnCount);
            mTree->insert(node);
			ColumnCount++;
		}
		mTree->optimize();
		
		
		//////////////////////////TESTING////////////////////////////
		//vrsUFVG::KDHolder node(osg::Vec3f(75,75,0), 1600);
  //      mTree->insert(node);
		//mTree->optimize();

		//for(int i=0; i<200; i++)
		//{
		//	std::cout << ColumnIndex[i].xPos << " " << ColumnIndex[i].yPos << std::endl;
		//}

		//osg::Vec3f TestPos(0,75,0);
		//float maxRadius = 1000024.0f;

		//find_result found = mTree->find_nearest(TestPos, maxRadius);
		//if (found.first != mTree->end())
  //      {              
		//	std::cout << found.first->mID << std::endl;            
  //      }
		//////////////////////////TESTING////////////////////////////


	}
	//////////////////////////////////////////////////////////////////////////
}
#endif //UFVG_COMPONENT_H