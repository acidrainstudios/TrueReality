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


#ifndef VRS_NETCDF_READER_H
#define VRS_NETCDF_READER_H


#include <iostream>
#include <vector>
#include <math.h>

#include <dtCore/RefPtr.h>

#include "export.h"
#include "netcdfcpp.h"

#pragma warning( disable: 4251 )
namespace vrsUFVG
{
	struct VRS_UFVG_EXPORT SigmaLevelData
	{
		float Sigma;								//Sigma Layer Value
		short U;									//Sea Water X Velocity
		short V;									//Sea Water Y Velocity
		float Angle;								//Sea Water Direction Angle
		short Salt;									//Sea Water Salinity
		short Temp;									//Sea Water Temperature

	};

	struct VRS_UFVG_EXPORT DataSnapshot
	{
		float Lon;									//Longitude
		float Lat;									//Latitude
		float Depth;								//Water Depth in Meters
		float Ang;									//Angle Of Rotation From East To X in Radians
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

	};


	class VRS_UFVG_EXPORT NetCDFReader
	{
	public:

		//Constructor
		NetCDFReader();

		// Load The netCDF Data File
		void LoadFile(std::string FileName, int XPos = 0, int YPos = 0, bool GarbageDetection = true);

		//Destructor
		virtual ~NetCDFReader(void) 
		{
			mDataFile = NULL;
			delete mDataFile;
		};

		int GetNumOfXPos(void);								//Number of X Positions
		int GetNumOfYPos(void);								//Number of X Positions
		int GetNumOfTimeRecords(void);						//Number of Time Records
		float GetLon(void);									//Longitude
		float GetLat(void);									//Latitude
		float GetDepth(void);								//Water Depth in Meters
		float GetAng(void);									//Angle Of Rotation From East To X in Radians
		double	GetDateTime(int RecNum);					//Date_Time YYYYMMDDHHmm
		short GetElev(int RecNum);							//Sea Surface Height Above Sea Level in Meters
		short GetWindU(int RecNum);							//Wastward Wind in m/s
		short GetWindV(int RecNum);							//Northward Wind in m/s
		short GetAirPressure(int RecNum);					//Air Pressure At Sea Level in mbar
		short GetAirTemp(int RecNum);						//2m-above-surface Air Temperature in Celsius
		short GetHumidity(int RecNum);						//2m-above-surface Relative Humidity in Percent
		short GetWaveHeight(int RecNum);					//Sea Surface Wind Wave Significant Height in Meters
		short GetWavePeriod(int RecNum);					//Sea Surface Wind Wave Period in Sec
		short GetWaveDirection(int RecNum);					//Significant Wave Direction in Meteorologic Convention in Deg(N)

		int GetNumOfSigmas(void);							//Number of water Sigmas
		float GetSigma(int SigmaLevel);						//Sigma Layer Value
		short GetWaterU(int RecNum, int SigmaLevel);		//Sea Water X Velocity
		short GetWaterV(int RecNum, int SigmaLevel);		//Sea Water Y Velocity
		float GetWaterDirection(int RecNum, int SigmaLevel);//Sea WAter Direction in Degrees
		short GetWaterSalt(int RecNum, int SigmaLevel);		//Sea Water Salinity
		short GetWaterTemp(int RecNum, int SigmaLevel);		//Sea Water Temperature



	private:

		// Reads in the data from a file
		void ReadData(void);

		NcFile* mDataFile;					//opens the NetCDF file....
		
		int mXCurPos;						//X Position to Read
		int mYCurPos;						//Y Position to Read
		int mXpos;							//Number of X positions in the file
		int mYpos;							//Number of Y positions in the file
		int mSigma;							//Number of Sigma Bands in the file
		int mTime;							//Number of Time positions in the file

		bool mFileRead;						//Is the file read in

		bool mGarbage;						//Used for detecting garbage data fields....


											//holds all the data for all the vectors from the file
		std::vector<DataSnapshot> mVectorData;
	};
}

#endif //VRS_NETCDF_READER_H