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


#ifndef VRS_UFVG_READER_H
#define VRS_UFVG_READER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include <osg/Vec3>

namespace vrsUFVG
{
	const int MaxNumOfBins = 30;

	typedef struct 
	{
		float ElapsedTime;			// Time in hours since the beginning of the file
		float WaterLevel;			// Water Level
		int Year;					// Year of the taken data
		int Month;					// Month of the taken data
		int Day;					// Day of the taken data
		int Time;					// Time of the taken data in Decimal values. For example, 11:30 at night is 2350
		int BinNumber[MaxNumOfBins];// Bin number
		osg::Vec3f Direction[MaxNumOfBins];	// Direction and strength of the water sample			
		
	} SampleSnapshot;



	class UFVGReader
	{
	public:

		//Constructor
		UFVGReader();

		// Load The Acoustic Doppler Current Profiler Data File
		void LoadFile(char []);
		void LoadFile(std::string FileName);

		//Get the Start and End Julian Date as a 64bit Integer
		long long int GetJulianDateNumber(void) const {return mJulianDate;}

		//Get the number of the lowest Bin
		int GetLowestBinNum(void) const {return mLowBin;}

		//Get the number of the heighest Bin
		int GetHeightestBinNum(void) const {return mHighBin;}

		//Get the time increment between records
		float GetTimeIncr(void) const {return mTimeIncr;}

		//Get heigh of each Bin or distance between Bins...
		float GetBinHeight(void) const {return mBinHeight;}

		//Get the datas Start Year
		int GetStartYear(void) const {return mStartYear;}

		//Get the datas Stop Year
		int GetStopYear(void) const {return mStopYear;}

		//Get the datas Start Month
		int GetStartMonth(void) const {return mStartMonth;}

		//Get the datas Stop Month
		int GetStopMonth(void) const {return mStopMonth;}

		//Get the datas Start Day
		int GetStartDay(void) const {return mStartDay;}

		//Get the datas Stop Day
		int GetStopDay(void) const {return mStopDay;}

		//Get the total number of Bin records in the Data File
		int GetNumberOfRecords(void) const {return mVectorData.size();}

		//Get the Time Elapsed from current record
		float GetTimeElapsed(int RecordNumber);

		//Get the Water Level from current record
		float GetWaterLevel(int RecordNumber);

		//Get the Year from current record
		int GetYear(int RecordNumber);

		//Get the Month from current record
		int GetMonth(int RecordNumber);

		//Get the Day from current record
		int GetDay(int RecordNumber);

		//Get the Time from current record
		int GetTime(int RecordNumber);

		//Get the X component of the Direction Vector from current record and Bin
		float GetX(int RecordNumber, int BinNumber);

		//Get the Y component of the Direction Vector from current record and Bin
		float GetY(int RecordNumber, int BinNumber);

		//Get the Z component of the Direction Vector from current record and Bin
		float GetZ(int RecordNumber, int BinNumber);

		//Get the Length of the Direction Vector from current record and Bin
		float GetLength(int RecordNumber, int BinNumber);

		


		//Destructor
		virtual ~UFVGReader(void) {};

	protected:



	private:

		// Reads in the data from a file
		void ReadData(void);

		// Calculates aproximate number of days in a dataset.... error of +1/+2 days
		int JulianDateToDays(long long int DateNumber);




		std::fstream mInputFile;			//holds the path and name of the data file

		long long int mJulianDate;			//holds the julina date

		int mTotalNumOfDays;				//holds the total number of days

		int mLowBin;						//holds the number of the lowest Bin
		int mHighBin;						//holds the number of the highest Bin

		float mTimeIncr;					//holds the time increment between records
		float mBinHeight;					//heigh of each Bin

											//holds the Start and the Stop Date of the data
		int mStartYear, mStopYear, mStartMonth, mStopMonth, mStartDay, mStopDay;

											//holds all the data for all the vectors from the file
		std::vector<SampleSnapshot> mVectorData;
	};
}

#endif //VRS_UFVG_READER_H