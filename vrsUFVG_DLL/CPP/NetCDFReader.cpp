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

#ifndef VRS_NETCDF_READER_CPP
#define VRS_NETCDF_READER_CPP

#include "..\\Include\NetCDFReader.h"

namespace vrsUFVG
{
	////////////////////////////////////////////////////////////////////////////////
	NetCDFReader::NetCDFReader(void)
	:mDataFile(0)
	,mXCurPos(0)						//X Position to Read
	,mYCurPos(0)						//Y Position to Read
	,mXpos(0)							//Number of X positions in the file
	,mYpos(0)							//Number of Y positions in the file
	,mSigma(0)							//Number of Sigma Bands in the file
	,mTime(0)							//Number of Time positions in the file
	,mFileRead(false)					//Is the file read in
	{
	}

	////////////////////////////////////////////////////////////////////////////////
	void NetCDFReader::LoadFile(std::string FileName, int x, int y, bool Garbage)
	{

		mGarbage = Garbage;
	  
		char FilePath[256];
		strcpy( FilePath, FileName.c_str() );

		// Open the file. The ReadOnly parameter tells netCDF we want
		// read-only access to the file.
		mDataFile = new NcFile(FilePath, NcFile::ReadOnly);
	     
		// You should always check whether a netCDF file open or creation
		if (!mDataFile->is_valid())
		{
			std::cout << "NetCDFReader>Couldn't open file " << FileName << "!\n"<< std::endl;
		}
		else
		{
			mVectorData.clear();
			mXCurPos = x;
			mYCurPos = y;
			ReadData();
			mFileRead = true;
		}

		mDataFile->close();

		
	}
	////////////////////////////////////////////////////////////////////////////////
	void NetCDFReader::ReadData(void)
	{
		#ifdef _DEBUG
		std::cout << "NetCDFReader>Reading The Data File" << std::endl; 
		std::cout << "NetCDFReader>::Retrive the Dimentions" << std::endl; 
		#endif //_DEBUG

		//Retrive the Dimentions
		NcDim *xpos		= mDataFile->get_dim("xpos");
		NcDim *ypos		= mDataFile->get_dim("ypos");
		NcDim *sigma	= mDataFile->get_dim("sigma");
		NcDim *time		= mDataFile->get_dim("time");
	     
		
		mXpos = xpos->size();	
		mYpos = ypos->size();
		mSigma= sigma->size();							
		mTime = time->size();

		if(mXCurPos < 0 )
		{
			std::cout << "NetCDFReader>X Value is out of Scope:" << mXCurPos << " Setting to:";
			mXCurPos = 0;
			std::cout << mXCurPos << std::endl;
			 
		}
		else if(mXCurPos >= mXpos)
		{
			std::cout << "NetCDFReader>X Value is out of Scope:" << mXCurPos << " Setting to:";
			mXCurPos = xpos->size()-1;
			std::cout << mXCurPos << std::endl;
		}
		if(mYCurPos < 0)
		{
			std::cout << "NetCDFReader>Y Value is out of Scope:" << mYCurPos << " Setting to:";
			mYCurPos = 0;
			std::cout << mYCurPos << std::endl;
		}
		else if(mYCurPos >= mYpos)
		{
			std::cout << "NetCDFReader>Y Value is out of Scope:" << mYCurPos << " Setting to:";
			mYCurPos = ypos->size()-1;
			std::cout << mYCurPos << std::endl;
		}


		#ifdef _DEBUG
		std::cout << "NetCDFReader>::Finding the variables" << std::endl; 
		#endif //_DEBUG


	/*
		static float Lon;							//Longitude
		static float Lat;							//Latitude
		static float Depth;							//Water Depth in Meters
		static float Ang;							//Angle Of Rotation From East To X in Radians
		double	Date_Time;							//Date_Time YYYYMMDDHHmm
		short Elev;									//Sea Surface Height Above Sea Level in Meters
		short Wu;									//Wastward Wind in m/s
		short Wv;									//Northward Wind in m/s
		short Patm;									//Air Pressure At Sea Level in mbar
		short Airt;									//2m-above-surface Air Temperature in Celsius
		short Rhum;									//2m-above-surface Relative Humidity in Percent
		short Wh;									//Sea Surface Wind Wave Significant Height in Meters
		short Wp;									//Sea Surface Wind Wave Period in Sec
		short Wd;									//Significant Wave Direction in Meteorologic Convention in Deg(N)

		std::vector<SigmaLevelData> SigmaLayers;	//Sigma Layerd Data

		static float Sigma;							//Sigma Layer Value
		short U;									//Sea Water X Velocity
		short V;									//Sea Water Y Velocity
		float Angle;								//Sea Water Direction Angle
		short Salt;									//Sea Water Salinity
		short Temp;									//Sea Water Temperature

	*/
		NcVar *Lon = mDataFile->get_var("lon");
		NcVar *Lat = mDataFile->get_var("lat");
		NcVar *Depth = mDataFile->get_var("depth");
		NcVar *Ang = mDataFile->get_var("ang");
		NcVar *DateTime = mDataFile->get_var("date");
		NcVar *Elev = mDataFile->get_var("elev");
		NcVar *Wu = mDataFile->get_var("wu");
		NcVar *Wv = mDataFile->get_var("wv");
		NcVar *Patm = mDataFile->get_var("patm");
		NcVar *Airt = mDataFile->get_var("airt");
		NcVar *Rhum = mDataFile->get_var("rhum");
		NcVar *Wh = mDataFile->get_var("wh");
		NcVar *Wp = mDataFile->get_var("wp");
		NcVar *Wd = mDataFile->get_var("wd");

		NcVar *Sigma = mDataFile->get_var("sigma");
		NcVar *U = mDataFile->get_var("u");
		NcVar *V = mDataFile->get_var("v");
		NcVar *Salt = mDataFile->get_var("salt");
		NcVar *Temp = mDataFile->get_var("temp");

		#ifdef _DEBUG
		std::cout << "NetCDFReader>::Retrieve the variables" << std::endl; 
		#endif //_DEBUG

		DataSnapshot Snapshot;
		SigmaLevelData SigmaSnapshot;


		#ifdef _DEBUG
		std::cout << "NetCDFReader>::::Retrieve Long" << std::endl; 
		#endif //_DEBUG
		Lon->set_cur(mYCurPos, mXCurPos);
		Lon->get(&Snapshot.Lon,1,1);
		
		#ifdef _DEBUG
		std::cout << "NetCDFReader>::::Retrieve Lat" << std::endl; 
		#endif //_DEBUG
		Lat->set_cur(mYCurPos, mXCurPos);
		Lat->get(&Snapshot.Lat,1,1);

		if(!mGarbage || ((Snapshot.Lat > -700 && Snapshot.Lat < 700) && (Snapshot.Lon > -700 && Snapshot.Lon < 700)))
		{
			//Retreave Repeating Vars
			#ifdef _DEBUG
			std::cout << "NetCDFReader>::::Retrieve Sigma" << std::endl; 
			#endif //_DEBUG
			for(int k=0; k<mSigma; k++)
			{
				Sigma->set_cur(k);
				Sigma->get(&SigmaSnapshot.Sigma, 1);
				Snapshot.SigmaLayers.push_back(SigmaSnapshot);
			}

			#ifdef _DEBUG
			std::cout << "NetCDFReader>::::Retrieve Depth" << std::endl; 
			#endif //_DEBUG
			Depth->set_cur(mYCurPos, mXCurPos);
			Depth->get(&Snapshot.Depth,1,1);

			#ifdef _DEBUG
			std::cout << "NetCDFReader>::::Retrieve Ang" << std::endl; 
			#endif //_DEBUG
			Ang->set_cur(mYCurPos, mXCurPos);
			Ang->get(&Snapshot.Ang,1,1);
			
			//Retreave Non-Repeating Vars
			#ifdef _DEBUG
			std::cout << "NetCDFReader>::::Retrieve Non-Rep Vars" << std::endl; 
			#endif //_DEBUG
			for(int i=0; i<mTime; i++)
			{
				DateTime->set_cur(i);
				DateTime->get(&Snapshot.Date_Time, 1);

				Elev->set_cur(i, mYCurPos, mXCurPos);
				Elev->get(&Snapshot.Elev, 1, 1, 1);

				Wu->set_cur(i, mYCurPos, mXCurPos);
				Wu->get(&Snapshot.Wu, 1, 1, 1);

				Wv->set_cur(i, mYCurPos, mXCurPos);
				Wv->get(&Snapshot.Wv, 1, 1, 1);

				Patm->set_cur(i, mYCurPos, mXCurPos);
				Patm->get(&Snapshot.Patm, 1, 1, 1);

				Airt->set_cur(i, mYCurPos, mXCurPos);
				Airt->get(&Snapshot.Airt, 1, 1, 1);

				Rhum->set_cur(i, mYCurPos, mXCurPos);
				Rhum->get(&Snapshot.Rhum, 1, 1, 1);

				Wh->set_cur(i, mYCurPos, mXCurPos);
				Wh->get(&Snapshot.Wh, 1, 1, 1);

				Wp->set_cur(i, mYCurPos, mXCurPos);
				Wp->get(&Snapshot.Wp, 1, 1, 1);

				Wd->set_cur(i,mYCurPos,mXCurPos);
				Wd->get(&Snapshot.Wd, 1, 1, 1);

				for(int j=0; j<mSigma; j++)
				{
					U->set_cur(i, j, mYCurPos, mXCurPos);
					U->get(&Snapshot.SigmaLayers[j].U, 1, 1, 1, 1);

					V->set_cur(i, j, mYCurPos, mXCurPos);
					V->get(&Snapshot.SigmaLayers[j].V, 1, 1, 1, 1);

					
					/*std::cout << "U "<< Snapshot.SigmaLayers[j].U << 
						" V " << Snapshot.SigmaLayers[j].V <<
						" Sigma " << j<<
						" X " << mXCurPos <<
						" Y " << mYCurPos <<std::endl;*/

					float x, y;
					x=Snapshot.SigmaLayers[j].U;
					y=Snapshot.SigmaLayers[j].V;
					
					//std::cout << std::fixed;
					//std::cout << x*0.0001831222f << " " << y*0.0001831222f << std::endl;
					Snapshot.SigmaLayers[j].Angle = (atan2(y, x)*180.0f/3.14159265358979323846f) + Snapshot.Ang;

					Salt->set_cur(i, j, mYCurPos, mXCurPos);
					Salt->get(&Snapshot.SigmaLayers[j].Salt, 1, 1, 1, 1);

					Temp->set_cur(i, j, mYCurPos, mXCurPos);
					Temp->get(&Snapshot.SigmaLayers[j].Temp, 1, 1, 1, 1);
				}

				mVectorData.push_back(Snapshot);
			}
		}
		else
		{
			//Place garbage values into the data....skipping the file read
			//Retreave Repeating Vars
			#ifdef _DEBUG
			std::cout << "NetCDFReader>::::Retrieve Sigma" << std::endl; 
			#endif //_DEBUG
			for(int k=0; k<mSigma; k++)
			{
				SigmaSnapshot.Sigma = 0.0f;
				Snapshot.SigmaLayers.push_back(SigmaSnapshot);
			}

			#ifdef _DEBUG
			std::cout << "NetCDFReader>::::Retrieve Depth" << std::endl; 
			#endif //_DEBUG
			Snapshot.Depth = 0.0f;

			#ifdef _DEBUG
			std::cout << "NetCDFReader>::::Retrieve Ang" << std::endl; 
			#endif //_DEBUG
			Snapshot.Ang = 0.0f;
			
			//Retreave Non-Repeating Vars
			#ifdef _DEBUG
			std::cout << "NetCDFReader>::::Retrieve Non-Rep Vars" << std::endl; 
			#endif //_DEBUG
			for(int i=0; i<mTime; i++)
			{
				Snapshot.Date_Time = 0.0f;

				Snapshot.Elev = 0;

				Snapshot.Wu = 0;

				Snapshot.Wv = 0;

				Snapshot.Patm = 0;

				Snapshot.Airt = 0;

				Snapshot.Rhum = 0;

				Snapshot.Wh = 0;

				Snapshot.Wp = 0;

				Snapshot.Wd = 0;

				for(int j=0; j<mSigma; j++)
				{
					Snapshot.SigmaLayers[j].U = 0;

					Snapshot.SigmaLayers[j].V = 0;

					Snapshot.SigmaLayers[j].Angle  = 0.0f;

					Snapshot.SigmaLayers[j].Salt = 0;

					Snapshot.SigmaLayers[j].Temp = 0;
				}

				mVectorData.push_back(Snapshot);
			}
		}


		
		#ifdef _DEBUG
		std::cout << "NetCDFReader>::Test Print" << std::endl; 
		
		std::cout << std::fixed; 
		std::cout << mVectorData[0].Date_Time << std::endl;
		std::cout << mVectorData[0].SigmaLayers[5].Sigma << std::endl;
		std::cout << mVectorData[0].SigmaLayers[5].Temp << std::endl;
		std::cout << mVectorData[300].Date_Time << std::endl;
		std::cout << mVectorData[300].SigmaLayers[5].Sigma << std::endl;
		std::cout << mVectorData[300].SigmaLayers[5].Temp << std::endl;
		#endif //_DEBUG
		


		#ifdef _DEBUG
		std::cout << "NetCDFReader>Done Reading The Data File" << std::endl; 
		#endif //_DEBUG
	}

	////////////////////////////////////////////////////////////////////////////////
	int NetCDFReader::GetNumOfXPos(void)								//Number of X Positions
	{
		if(mFileRead)
		{
			return mXpos;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	int NetCDFReader::GetNumOfYPos(void)								//Number of X Positions
	{
		if(mFileRead)
		{
			return mYpos;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	int NetCDFReader::GetNumOfTimeRecords(void)						//Number of Time Records
	{
		if(mFileRead)
		{
			return mTime;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	int NetCDFReader::GetNumOfSigmas(void)							//Number of water Sigmas
	{
		if(mFileRead)
		{
			return mSigma;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	float NetCDFReader::GetLon(void)									//Longitude
	{
		if(mFileRead)
		{
			return mVectorData[0].Lon;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	float NetCDFReader::GetLat(void)									//Latitude
	{
		if(mFileRead)
		{
			return mVectorData[0].Lat;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	float NetCDFReader::GetDepth(void)								//Water Depth in Meters
	{
		if(mFileRead)
		{
			return mVectorData[0].Depth;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	float NetCDFReader::GetAng(void)									//Angle Of Rotation From East To X in Radians
	{
		if(mFileRead)
		{
			return mVectorData[0].Ang;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	double NetCDFReader::GetDateTime(int RecNum)					//Date_Time YYYYMMDDHHmm
	{
		if(mFileRead)
		{
			if(RecNum < 0 || RecNum > mTime)
			{
				return -1;
			}
			return mVectorData[RecNum].Date_Time;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	short NetCDFReader::GetElev(int RecNum)							//Sea Surface Height Above Sea Level in Meters
	{
		if(mFileRead)
		{
			if(RecNum < 0 || RecNum > mTime)
			{
				return -1;
			}
			return mVectorData[RecNum].Elev;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	short NetCDFReader::GetWindU(int RecNum)							//Wastward Wind in m/s
	{
		if(mFileRead)
		{
			if(RecNum < 0 || RecNum > mTime)
			{
				return -1;
			}
			return mVectorData[RecNum].Wu;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	short NetCDFReader::GetWindV(int RecNum)							//Northward Wind in m/s
	{
		if(mFileRead)
		{
			if(RecNum < 0 || RecNum > mTime)
			{
				return -1;
			}
			return mVectorData[RecNum].Wv;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	short NetCDFReader::GetAirPressure(int RecNum)					//Air Pressure At Sea Level in mbar
	{
		if(mFileRead)
		{
			if(RecNum < 0 || RecNum > mTime)
			{
				return -1;
			}
			return mVectorData[RecNum].Patm;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	short NetCDFReader::GetAirTemp(int RecNum)						//2m-above-surface Air Temperature in Celsius
	{
		if(mFileRead)
		{
			if(RecNum < 0 || RecNum > mTime)
			{
				return -1;
			}
			return mVectorData[RecNum].Airt;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	short NetCDFReader::GetHumidity(int RecNum)						//2m-above-surface Relative Humidity in Percent
	{
		if(mFileRead)
		{
			if(RecNum < 0 || RecNum > mTime)
			{
				return -1;
			}
			return mVectorData[RecNum].Rhum;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	short NetCDFReader::GetWaveHeight(int RecNum)					//Sea Surface Wind Wave Significant Height in Meters
	{
		if(mFileRead)
		{
			if(RecNum < 0 || RecNum > mTime)
			{
				return -1;
			}
			return mVectorData[RecNum].Wh;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	short NetCDFReader::GetWavePeriod(int RecNum)					//Sea Surface Wind Wave Period in Sec
	{
		if(mFileRead)
		{
			if(RecNum < 0 || RecNum > mTime)
			{
				return -1;
			}
			return mVectorData[RecNum].Wp;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	short NetCDFReader::GetWaveDirection(int RecNum)					//Significant Wave Direction in Meteorologic Convention in Deg(N)
	{
		if(mFileRead)
		{
			if(RecNum < 0 || RecNum > mTime)
			{
				return -1;
			}
			return mVectorData[RecNum].Wd;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	float NetCDFReader::GetSigma(int SigmaLevel)						//Sigma Layer Value
	{
		if(mFileRead)
		{
			if(SigmaLevel < 0 || SigmaLevel > mSigma)
			{
				return -1;
			}
			return mVectorData[0].SigmaLayers[SigmaLevel].Sigma;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	short NetCDFReader::GetWaterU(int RecNum, int SigmaLevel)		//Sea Water X Velocity
	{
		if(mFileRead)
		{
			if(RecNum < 0 || RecNum > mTime || SigmaLevel < 0 || SigmaLevel > mSigma)
			{
				return -1;
			}
			return mVectorData[RecNum].SigmaLayers[SigmaLevel].U;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	short NetCDFReader::GetWaterV(int RecNum, int SigmaLevel)		//Sea Water Y Velocity
	{
		if(mFileRead)
		{
			if(RecNum < 0 || RecNum > mTime || SigmaLevel < 0 || SigmaLevel > mSigma)
			{
				return -1;
			}
			return mVectorData[RecNum].SigmaLayers[SigmaLevel].V;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	float NetCDFReader::GetWaterDirection(int RecNum, int SigmaLevel)//Sea WAter Direction in Degrees
	{
		if(mFileRead)
		{
			if(RecNum < 0 || RecNum > mTime || SigmaLevel < 0 || SigmaLevel > mSigma)
			{
				return -1;
			}
			return mVectorData[RecNum].SigmaLayers[SigmaLevel].Angle;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	short NetCDFReader::GetWaterSalt(int RecNum, int SigmaLevel)		//Sea Water Salinity
	{
		if(mFileRead)
		{
			if(RecNum < 0 || RecNum > mTime || SigmaLevel < 0 || SigmaLevel > mSigma)
			{
				return -1;
			}
			return mVectorData[RecNum].SigmaLayers[SigmaLevel].Salt;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	short NetCDFReader::GetWaterTemp(int RecNum, int SigmaLevel)		//Sea Water Temperature
	{
		if(mFileRead)
		{
			if(RecNum < 0 || RecNum > mTime || SigmaLevel < 0 || SigmaLevel > mSigma)
			{
				return -1;
			}
			return mVectorData[RecNum].SigmaLayers[SigmaLevel].Temp;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
}
#endif //VRS_NETCDF_READER_CPP


