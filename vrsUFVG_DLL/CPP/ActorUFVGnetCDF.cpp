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

#ifndef VRS_UFVG_NETCDF_ACTOR_CPP
#define VRS_UFVG_NETCDF_ACTOR_CPP

#include "..\\Include\ActorUFVGnetCDF.h"
namespace vrsUFVG
{
	///////////////////////////////////////////////////////////////////////////////
	const std::string UFVGnetCDFActor::ACTOR_DEFAULT_NAME("UFVG netCDF Actor");
	///////////////////////////////////////////////////////////////////////////////

	UFVGnetCDFActor::UFVGnetCDFActor(vrsCore::GameStaticMeshActorProxy& proxy)
	:vrsCore::GameStaticMeshActor(proxy)
	,mPropertiesUpdated(false)
	,mRecordNum(0)
	,mPlaybackSpeed(10.0f)
	,mPlaybackTimer(0.0f)
	,mDataFilePath("Data/NetCDF")				//Data File Path and Name
	//,mGeomDirFileName("Content/StaticMeshes/Misc/arrow.ive")			//Geometry File Path and Name
	//,mGeomSpdFileName("Content/StaticMeshes/Misc/SpeedMark.ive")		//Geometry File Path and Name
	//,mGeomComFileName("Content/StaticMeshes/Misc/Compass.ive")		//Geometry File Path and Name
	,mXCur(4)									//X Position to Read
	,mYCur(98)									//Y Position to Read
	,mCompass(0)								//hold the geometry for the compass
	//,mElevScale(0.0002289028f)				//sea_surface_height_above_sea_level
	//,mWuScale(0.004578056f)					//EW Wind Comp
	//,mWvScale(0.004578056f)					//NS Wind Comp
	//,mPatmScale(0.004578056f)					//Atmospheric pressure
	//,mAirtScale(0.002289028f)					//2m-above-surface Air Temperature
	//,mRhumScale(0.001526019f)					//2m-above-surface Relative Humidity
	//,mWhScale(0.0004730658f)					//wave heights
	//,mWpScale(0.1100259f)						//wave periods
	//,mWdScale(0.005646269f)					//Significant Wave Direction in Meteorologic Convention
	//,mUScale(0.0001831222f)					//sea_water_x_velocity
	//,mVScale(0.0001831222f)					//sea_water_y_velocity
	,mSpeedScale(0.0001831222f)					//sea_water_velocity
	//,mSaltScale(0.001297116f)					//sea_water_salinity
	//,mTempScale(0.0009156112f)				//Water Temperature
	{
		SetName(ACTOR_DEFAULT_NAME); //Set the instences Name
		//Set the Actor Description
		SetDescription("Underwater Flow Vector Generator is used to display Underwater Data from netCDF Data Files"); 

		//Set the Default Render Bin Options for this actor
		SetRenderBin(vrsCore::LAST_RENDER_BIN);
		SetRenderBinSortType(vrsCore::RENDER_BIN_TYPE::STATE_SORTED_BIN);
	}

	///////////////////////////////////////////////////////////////////////////////
	void UFVGnetCDFActor::OnTickLocal(const dtGame::TickMessage& tickMessage)
	{
		mDeltaSimTime = tickMessage.GetDeltaSimTime();

		UpdateVectors(mDeltaSimTime);
	}

	///////////////////////////////////////////////////////////////////////////////
	void UFVGnetCDFActor::OnTickRemote(const dtGame::TickMessage& tickMessage)
	{
		mDeltaSimTime = tickMessage.GetDeltaSimTime();
	}

	///////////////////////////////////////////////////////////////////////////////
	void UFVGnetCDFActor::ProcessMessage(const dtGame::Message& message)
	{
		//std::cout << "UFVGnetCDFActor" << std::endl;
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
	inline void UFVGnetCDFActor::OnEnteredWorld()
	{
		vrsCore::GameStaticMeshActor::OnEnteredWorld();

		//Create and place Geometry visuals
		InitGeom();
		
		//Disable the Depth Buffer
		//GetOSGNode()->getStateSet()->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);

		
	}
	///////////////////////////////////////////////////////////////////////////////
	void UFVGnetCDFActor::AddedToScene(dtCore::Scene* scene)
	{
		#ifdef _DEBUG
		std::cout << "UFVGnetCDFActor::AddedToScene" << std::endl;
		#endif //_DEBUG

		vrsCore::GameStaticMeshActor::AddedToScene(scene);
	}
	///////////////////////////////////////////////////////////////////////////////
	inline void UFVGnetCDFActor::Reload(void)
	{
		//Load the Data File
		ReadData();

		//Move the vectors and speeds geometry....
		//mNumOfSig-1 to remove the last "underground" vector
		for(int i = 0; i<((signed)mNumOfSig-1); i++)
		{
			// move our Direction and Speed Marker to a new height
			mDirectionMark[i]->SetTransform(dtCore::Transform(0.0,0.0f,(mColumnDepth * mSigmas[i]+(mColumnDepth/2)),0.0f,0.0f,0.0f), dtCore::Transformable::REL_CS);
		}

		//Move the Compass to a new position....
		mCompass->SetTransform(dtCore::Transform(0.0f,0.0f,-mColumnDepth/2,0.0f,0.0f,0.0f), dtCore::Transformable::REL_CS);
		SetTransform(dtCore::Transform(0.0f,mColumnDepth*3.0f,0.0f,0.0f,0.0f, 0.0f),dtCore::Transformable::REL_CS);

	}
	///////////////////////////////////////////////////////////////////////////////
	void UFVGnetCDFActor::SetPlaybackSpeed(float Speed)
	{
		if(Speed < 0)
			Speed = 1;
		mPlaybackSpeed = Speed;
	}
	///////////////////////////////////////////////////////////////////////////////
	float UFVGnetCDFActor::GetPlaybackSpeed(void)
	{
		return mPlaybackSpeed;
	}
	///////////////////////////////////////////////////////////////////////////////
	void UFVGnetCDFActor::SetXPosition(int X)
	{
		if (X<0)
		{	
			mXCur = 0;
		}
		else
		{
			mXCur = X;
		}
		//std::cout<< "UFVG Set X" << std::endl;
		//OnEnteredWorld();
	}
	///////////////////////////////////////////////////////////////////////////////
	int UFVGnetCDFActor::GetXPosition(void)
	{
		return mXCur;
	}
	///////////////////////////////////////////////////////////////////////////////
	void UFVGnetCDFActor::SetYPosition(int Y)
	{
		if (Y<0)
		{	
			mYCur = 0;
		}
		else
		{
			mYCur = Y;
		}
	}
	///////////////////////////////////////////////////////////////////////////////
	int UFVGnetCDFActor::GetYPosition(void)
	{
		return mYCur;
	}
	///////////////////////////////////////////////////////////////////////////////
	void UFVGnetCDFActor::SetDataFile(const std::string& FileName)
	{
		mDataFilePath = FileName;
	}
	///////////////////////////////////////////////////////////////////////////////
	std::string UFVGnetCDFActor::GetDataFile(void)
	{
		return mDataFilePath;
	}
	///////////////////////////////////////////////////////////////////////////////
	void UFVGnetCDFActor::SetDirGeomFile(const std::string& FileName)
	{
		mGeomDirFileName = FileName;
	}
	///////////////////////////////////////////////////////////////////////////////
	std::string UFVGnetCDFActor::GetDirGeomFile(void)
	{
		return mGeomDirFileName;
	}
	///////////////////////////////////////////////////////////////////////////
	void UFVGnetCDFActor::SetSpdGeomFile(const std::string& FileName)
	{
		mGeomSpdFileName = FileName;
	}
	///////////////////////////////////////////////////////////////////////////
	std::string UFVGnetCDFActor::GetSpdGeomFile(void)
	{
		return mGeomSpdFileName;
	}
	///////////////////////////////////////////////////////////////////////////
	void UFVGnetCDFActor::SetComGeomFile(const std::string& FileName)
	{
		mGeomComFileName = FileName;
	}
	///////////////////////////////////////////////////////////////////////////
	std::string UFVGnetCDFActor::GetComGeomFile(void)
	{
		return mGeomComFileName;
	}
	///////////////////////////////////////////////////////////////////////////
	inline void UFVGnetCDFActor::ReadData(void)
	{
		mData.clear();
		
		std::stringstream out;
		std::string UFVGFile; 
		out << mDataFilePath << "/netCDF_" << mXCur << "_" << mYCur <<".UFVG"; //combine the filepath and file name
		UFVGFile = out.str();

		std::ifstream UFVGfile;		//file sream
		
		UFVGfile.open (UFVGFile.c_str(),std::ios_base::in);
		if (!UFVGfile.is_open())
		{	
			std::cout << "-->Error Could not find " << UFVGFile << std::endl;
			UFVGfile.close();
		}

		UFVGfile >> mColumnDepth;		//reads in the depth

		for(int i=0; i<mTotalRecordNum; i++)
		{
			SigmaData SidDat;
			DataColumn DatCol;

			UFVGfile >> DatCol.Date_Time; //reads in the date/time
			
			//reads in the sigma level data
			for(int j=0; j<mNumOfSig; j++)
			{
				UFVGfile >> SidDat.Speed;
				SidDat.Speed *= mSpeedScale;
				UFVGfile >> SidDat.Angle;

				DatCol.SigmaLayers.push_back(SidDat);
			}

			mData.push_back(DatCol);
		}
		



		UFVGfile.close();
	}
	///////////////////////////////////////////////////////////////////////////
	inline void UFVGnetCDFActor::ReadIndex(void)
	{
		std::stringstream out;
		std::string UFVGFile; 
		out << mDataFilePath << "/index.UFVG"; //combine the filepath and file name
		UFVGFile = out.str();

		std::ifstream UFVGfile;		//file sream
		
		UFVGfile.open (UFVGFile.c_str(),std::ios_base::in);
		if (!UFVGfile.is_open())
		{	
			std::cout << "-->Error Could not find " << UFVGFile << std::endl;
			UFVGfile.close();
		}

		UFVGfile >> mXMax >> mYMax >> mNumOfSig >> mTotalRecordNum;
		//std::cout << mXMax << " " << mYMax << " " << mNumOfSig << " " << mTotalRecordNum << std::endl;

		mSigmas.clear();
		for(int i=0; i<mNumOfSig; i++)
		{
			float sig;
			UFVGfile >> sig;
			mSigmas.push_back(sig);
		}

		UFVGfile.close();
	}
	///////////////////////////////////////////////////////////////////////////
	inline void UFVGnetCDFActor::InitGeom(void)
	{
		//Read the index file
		ReadIndex();

		//Load the Data File
		ReadData();
		
		if(mXCur > mXMax)
		{
			mXCur = mXMax;
		}

		if(mYCur > mYMax)
		{
			mYCur = mYMax;
		}

		//check if there are children attached to this node
		//and remove them
		if(GetOSGNode()->asGroup()->getNumChildren() > 0)
		{
			GetOSGNode()->asGroup()->removeChild(0, GetOSGNode()->asGroup()->getNumChildren());
		}

		//clear our vectors if they held any data...
		mDirectionMark.clear();
		mSpeedMark.clear();

		//Set up the vectors and speeds geometry....
		//mNumOfSig-1 to remove the last "underground" vector
		for(int i = 0; i<((signed)mNumOfSig-1); i++)
		{
			// add our Direction and Speed Marker 
			//dtCore::Transform t(0.0f,0.0f,(mColumnDepth * mSigmas[i]),0.0f,0.0f,0.0f);

			osg::ref_ptr<dtCore::Object> DirectionMarker = new dtCore::Object();
			osg::ref_ptr<dtCore::Object> SpeedMarker = new dtCore::Object();
			
			if(!mGeomDirFileName.empty())
			{
				DirectionMarker->LoadFile(mGeomDirFileName,true);
			}
			if(!mGeomSpdFileName.empty())
			{
				SpeedMarker->LoadFile(mGeomSpdFileName,true);
			}
			
			DirectionMarker->AddChild(SpeedMarker);
			DirectionMarker->SetTransform(dtCore::Transform(0.0f,0.0f,(mColumnDepth * mSigmas[i]),0.0f,0.0f,0.0f));

			AddChild(DirectionMarker);
			
			mDirectionMark.push_back(DirectionMarker);
			mSpeedMark.push_back(SpeedMarker);
		}

		//Add the Compass
		mCompass = new dtCore::Object();
		if(!mGeomComFileName.empty())
		{
			mCompass->LoadFile(mGeomComFileName,true);
		}
		mCompass->SetTransform(dtCore::Transform(0.0f,0.0f,-mColumnDepth,0.0f,0.0f,0.0f));
		AddChild(mCompass.get());

	}
	///////////////////////////////////////////////////////////////////////////
	void UFVGnetCDFActor::UpdateVectors(float DeltaTime)
	{
		
		//Controll the playback advance
		if(mPlaybackTimer>(1.0f/mPlaybackSpeed))
		{
			mRecordNum++;
			if(mRecordNum >= mTotalRecordNum)
			{
				mRecordNum = 0;
			}
			mPlaybackTimer = 0.0f;
		}
		
		dtCore::Transform t0, t, t2;
		osg::Vec3f  vect;

		//Make sure the UFVG alwase stays in the same rotation....
		GetTransform(t0);
		t0.SetRotation(0,0,0);
		SetTransform(t0);
		
		//Rotate the DirectionMarker
		for(int i = 0; i <(signed)mDirectionMark.size(); i++)
		{
			mDirectionMark[i]->GetTransform(t);
			t.GetRotation(vect);
			vect.set(mData[mRecordNum].SigmaLayers[i].Angle, 0, 0);
			t.SetRotation(vect);
			mDirectionMark[i]->SetTransform(t);
			
			//move the water speed marker
			mSpeedMark[i]->GetTransform(t2);
			t2.Set(0,mData[mRecordNum].SigmaLayers[i].Speed,0,0,0,0);
			mSpeedMark[i]->SetTransform(t2, dtCore::Transformable::REL_CS);
		}

		if (mPropertiesUpdated)
		{
			GetGameActorProxy().NotifyFullActorUpdate();
			mPropertiesUpdated = false;
		}

		mPlaybackTimer += DeltaTime;


	}
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	UFVGnetCDFActorProxy::UFVGnetCDFActorProxy()
	{
	   SetClassName(UFVGnetCDFActor::ACTOR_DEFAULT_NAME); //Set the actors Class Name
	  
	}

	///////////////////////////////////////////////////////////////////////////////
	void UFVGnetCDFActorProxy::BuildPropertyMap()
	{
		const std::string Actor_GROUP = "Actor Properties"; //Property group name
		//const std::string Motion_GROUP = Actor_GROUP + ".Motion Properties"; //Property group name

		//dtDAL::ActorProxy::BuildPropertyMap();
		///TransformableActorProxy::BuildPropertyMap();
		//dtDAL::PhysicalActorProxy::BuildPropertyMap();
		//dtGame::GameActorProxy::BuildPropertyMap();
		vrsCore::GameStaticMeshActorProxy::BuildPropertyMap();

		UFVGnetCDFActor* actor = static_cast<UFVGnetCDFActor*>(GetActor());
		
		
		// "XPosition" property
		/*AddProperty(new dtDAL::IntActorProperty("XPosition","X Position in the netCDF File",
			dtDAL::IntActorProperty::SetFuncType(actor, &UFVGnetCDFActor::SetXPosition),
			dtDAL::IntActorProperty::GetFuncType(actor, &UFVGnetCDFActor::GetXPosition),
			"Sets/Gets X Position to play from the netCDF File", Actor_GROUP));*/

		// "YPosition" property
		/*AddProperty(new dtDAL::IntActorProperty("YPosition","Y Position in the netCDF File",
			dtDAL::IntActorProperty::SetFuncType(actor, &UFVGnetCDFActor::SetYPosition),
			dtDAL::IntActorProperty::GetFuncType(actor, &UFVGnetCDFActor::GetYPosition),
			"Sets/Gets Y Position to play from the netCDF File", Actor_GROUP));*/

		// "PlaybackSpeed" property
		AddProperty(new dtDAL::FloatActorProperty("PlaybackSpeed","Playback Speed (Steps/sec)",
			dtDAL::FloatActorProperty::SetFuncType(actor, &UFVGnetCDFActor::SetPlaybackSpeed),
			dtDAL::FloatActorProperty::GetFuncType(actor, &UFVGnetCDFActor::GetPlaybackSpeed),
			"Sets/Gets Speed with which each record is played back (10 is 10 times a second)", Actor_GROUP));

		// "DataFilePathName" property
		AddProperty(new dtDAL::StringActorProperty("DataFilePathName","netCDF Data Dump Path",
			dtDAL::StringActorProperty::SetFuncType(actor, &UFVGnetCDFActor::SetDataFile),
			dtDAL::StringActorProperty::GetFuncType(actor, &UFVGnetCDFActor::GetDataFile),
			"Sets/Gets the path of data files", Actor_GROUP));

		// "DirGeometry" property
		/*AddProperty(new dtDAL::StringActorProperty("DirGeometry", "Directional Geometry Path",
			dtDAL::StringActorProperty::SetFuncType(actor, &UFVGnetCDFActor::SetDirGeomFile),
			dtDAL::StringActorProperty::GetFuncType(actor, &UFVGnetCDFActor::GetDirGeomFile),
			"Sets/Gets the name name and path of the (Directional) Geometry", Actor_GROUP));
		*/

		// "DirGeometry" property
		AddProperty(new dtDAL::ResourceActorProperty(*this, dtDAL::DataType::STATIC_MESH,
			"VectorGeom", "Vector Geometry", 
			dtDAL::ResourceActorProperty::SetFuncType(actor, &UFVGnetCDFActor::SetDirGeomFile),
			"The static mesh resource that defines the geometry of the vectors direction", Actor_GROUP));

		// "SpdGeometry" property
		AddProperty(new dtDAL::ResourceActorProperty(*this, dtDAL::DataType::STATIC_MESH,
			"SpeedGeom", "Speed Geometry", 
			dtDAL::ResourceActorProperty::SetFuncType(actor, &UFVGnetCDFActor::SetSpdGeomFile),
			"The static mesh resource that defines the geometry of the speed indicator", Actor_GROUP));

		// "ComGeometry" property
		AddProperty(new dtDAL::ResourceActorProperty(*this, dtDAL::DataType::STATIC_MESH,
			"ComGeom", "Compass Geometry", 
			dtDAL::ResourceActorProperty::SetFuncType(actor, &UFVGnetCDFActor::SetComGeomFile),
			"The static mesh resource that defines the geometry of the Compass", Actor_GROUP));
			

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
	void UFVGnetCDFActorProxy::CreateActor()
	{
	   SetActor(*new UFVGnetCDFActor(*this));
	}

	///////////////////////////////////////////////////////////////////////////////
	void UFVGnetCDFActorProxy::OnEnteredWorld()
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

	   
	   dtGame::GameActorProxy::OnEnteredWorld();
	}
}

#endif //VRS_UFVG_NETCDF_ACTOR_CPP