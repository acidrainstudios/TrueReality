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

#ifndef VRS_UFVG_READER_CPP
#define VRS_UFVG_READER_CPP

#include "..\\Include\UFVGReader.h"


namespace vrsUFVG
{
	////////////////////////////////////////////////////////////////////////////////
	UFVGReader::UFVGReader(void):
	mJulianDate(99999999999999),
	mTotalNumOfDays(0),
	mLowBin(0),		
	mHighBin(0),		
	mTimeIncr(0.0f),		
	mBinHeight(0.0f),		
	mStartYear(0),
	mStopYear(0),
	mStartMonth(0),
	mStopMonth(0),
	mStartDay(0),
	mStopDay(0)
	{
	}
	////////////////////////////////////////////////////////////////////////////////
	void UFVGReader::LoadFile(char *DataFile)
	{

		mInputFile.open(DataFile,std::ios_base::in);

		if (mInputFile.fail())   // cheks if the file exists
		{
			std::cout << "\nThe file " << DataFile << " was not found \n"
				<< "Please check to see if it exists and in this directory." << std::endl;
			
		}
		else
		{
			mVectorData.clear();
			ReadData();
		}


	}
	////////////////////////////////////////////////////////////////////////////////
	void UFVGReader::LoadFile(std::string FileName)
	{
		
		char FilePath[256];
		strcpy( FilePath, FileName.c_str() );
		

		LoadFile(FilePath);
	}
	////////////////////////////////////////////////////////////////////////////////
	float UFVGReader::GetTimeElapsed(int RecordNumber)
	{
		if ((RecordNumber <= (int)mVectorData.size()) && (RecordNumber > 0)  && (mVectorData.size() != 0))
		{
			return mVectorData[RecordNumber-1].ElapsedTime;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	float UFVGReader::GetWaterLevel(int RecordNumber)
	{
		if ((RecordNumber <= (int)mVectorData.size()) && (RecordNumber > 0)  && (mVectorData.size() != 0))
		{
			return mVectorData[RecordNumber-1].WaterLevel;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	int UFVGReader::GetYear(int RecordNumber)
	{
		if ((RecordNumber <= (int)mVectorData.size()) && (RecordNumber > 0)  && (mVectorData.size() != 0))
		{
			return mVectorData[RecordNumber-1].Year;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	int UFVGReader::GetMonth(int RecordNumber)
	{
		if ((RecordNumber <= (int)mVectorData.size()) && (RecordNumber > 0)  && (mVectorData.size() != 0))
		{
			return mVectorData[RecordNumber-1].Month;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	int UFVGReader::GetDay(int RecordNumber)
	{
		if ((RecordNumber <= (int)mVectorData.size()) && (RecordNumber > 0)  && (mVectorData.size() != 0))
		{
			return mVectorData[RecordNumber-1].Day;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	int UFVGReader::GetTime(int RecordNumber)
	{
		if ((RecordNumber <= (int)mVectorData.size()) && (RecordNumber > 0)  && (mVectorData.size() != 0))
		{
			return mVectorData[RecordNumber-1].Time;
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	float UFVGReader::GetX(int RecordNumber, int BinNumber)
	{
		if ((RecordNumber <= (int)mVectorData.size()) && (RecordNumber > 0)  && (mVectorData.size() != 0))
		{
			if((BinNumber != 0) && (BinNumber >= mLowBin) && (BinNumber <= mHighBin))
			{
				return mVectorData[RecordNumber-1].Direction[BinNumber-1].x();
				
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	float UFVGReader::GetY(int RecordNumber, int BinNumber)
	{
		if ((RecordNumber <= (int)mVectorData.size()) && (RecordNumber > 0)  && (mVectorData.size() != 0))
		{
			if((BinNumber != 0) && (BinNumber >= mLowBin) && (BinNumber <= mHighBin))
			{
				return mVectorData[RecordNumber-1].Direction[BinNumber-1].y();
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	float UFVGReader::GetZ(int RecordNumber, int BinNumber)
	{
		if ((RecordNumber <= (int)mVectorData.size()) && (RecordNumber > 0)  && (mVectorData.size() != 0))
		{
			if((BinNumber != 0) && (BinNumber >= mLowBin) && (BinNumber <= mHighBin))
			{
				return mVectorData[RecordNumber-1].Direction[BinNumber-1].z();
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	float UFVGReader::GetLength(int RecordNumber, int BinNumber)
	{
		if ((RecordNumber <= (int)mVectorData.size()) && (RecordNumber > 0)  && (mVectorData.size() != 0))
		{
			if((BinNumber != 0) && (BinNumber >= mLowBin) && (BinNumber <= mHighBin))
			{
				return mVectorData[RecordNumber-1].Direction[BinNumber-1].length();
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	void UFVGReader::ReadData(void)
	{
		//Used to skip lines....or end them
		char InputLine[256];

		//used to fill in the vectors
		float x, y, z;
		z=0.0f;

	#ifdef _DEBUG
		std::cout << "*\n*\n*\n*\nData File Printout:" << std::endl;
	#endif //_DEBUG

		//Read the first line (skip it)
		mInputFile.getline(InputLine, 256); 
	#ifdef _DEBUG
		std::cout << InputLine << std::endl;
	#endif //_DEBUG

		//Read the second line
		mInputFile >> mJulianDate;
	#ifdef _DEBUG
		std::cout << mJulianDate << std::endl; 
	#endif //_DEBUG

		//fix the "long long int error"
		mInputFile.seekg(0);
		mInputFile.getline(InputLine, 256);   
		mInputFile.getline(InputLine, 256);   
		
		//Read the third line (skip it)
		mInputFile.getline(InputLine, 256);
	#ifdef _DEBUG
		std::cout << InputLine << std::endl;
	#endif //_DEBUG

		//Read in the fourth line
		mInputFile >> mLowBin;   
		mInputFile >> mHighBin; 
		if(mHighBin > MaxNumOfBins)
		{
			mHighBin = MaxNumOfBins;
		}
		mInputFile >> mTimeIncr;
		mInputFile >> mBinHeight;
		mInputFile.getline(InputLine, 256);
	#ifdef _DEBUG
		std::cout << mLowBin << " " << mHighBin << " " << mTimeIncr << " " << mBinHeight << " " << InputLine  << std::endl;
	#endif //_DEBUG

		//Read in the fith line
		mInputFile >> mStartYear;
		mInputFile >> mStopYear;
		mInputFile >> mStartMonth;
		mInputFile >> mStopMonth;
		mInputFile >> mStartDay;
		mInputFile >> mStopDay;
		mInputFile.getline(InputLine, 256);
	#ifdef _DEBUG
		std::cout << mStartYear << " " << mStopYear << " " << mStartMonth 
			<< " " << mStopMonth << " " << mStartDay << " " << mStopDay << " " << InputLine  << std::endl;
	#endif //_DEBUG


		mTotalNumOfDays = JulianDateToDays(mJulianDate);
	#ifdef _DEBUG
		std::cout << "\n\nTotal # of Days: " << mTotalNumOfDays << std::endl;
	#endif //_DEBUG


		//Read in the actual vector data, read untill the end of file is reached
		while(mInputFile.peek()!= EOF)
		{
			SampleSnapshot Snapshot;

			//Load the records header
			mInputFile >> Snapshot.ElapsedTime;
			mInputFile >> Snapshot.WaterLevel;
			mInputFile >> Snapshot.Year;
			mInputFile >> Snapshot.Month;
			mInputFile >> Snapshot.Day;
			mInputFile >> Snapshot.Time;

			//Load the vectors
			for(int i = (mLowBin-1); i<mHighBin; i++)
			{
				mInputFile >> Snapshot.BinNumber[i];
				mInputFile >> x;
				mInputFile >> y;
				Snapshot.Direction[i].set(x, y, z);
			}

			//Push the Snapshot into the main DataBase
			mVectorData.push_back(Snapshot);
		}
		//Depending on how the EOF was created we can over run by 1
		mVectorData.pop_back();

		mInputFile.close();
		
	#ifdef _DEBUG
		//Print out the DataFile from memory.... (test test test)
		std::cout	<< "\n*****************************************"
					<< "\nData File Printout From Memory"
					<< "\n*****************************************\n" << std::endl;
		int RecNum;
		RecNum = mVectorData.size();
		for(int i=0; i<RecNum; i++) 
		{
			std::cout << mVectorData[i].ElapsedTime << " ";
			std::cout << mVectorData[i].WaterLevel << " ";
			std::cout << mVectorData[i].Year << " ";
			std::cout << mVectorData[i].Month << " ";
			std::cout << mVectorData[i].Day << " ";
			std::cout << mVectorData[i].Time << std::endl;

			for(int j = (mLowBin-1); j<mHighBin; j++)
			{
				std::cout << mVectorData[i].BinNumber[j] << " ";
				std::cout << mVectorData[i].Direction[j].x() << " ";
				std::cout << mVectorData[i].Direction[j].y() << std::endl;
			}
		}

		std::cout <<"\n\nTotal Record Number: " << mVectorData.size() << std::endl;

		std::cout	<< "\n\n\n*****************************************"
					<< "\nEnd of Data File Printout From Memory"
					<< "\n*****************************************\n" << std::endl;
	#endif //_DEBUG


	}
	////////////////////////////////////////////////////////////////////////////////
	int UFVGReader::JulianDateToDays(long long int DateNumber)
	{
		int EndYear = DateNumber % 10000;
		int EndDay = ((DateNumber % 10000000)-EndYear)/10000;
		int StartYear = ((DateNumber % 100000000000)-(EndDay*10000+EndYear))/10000000;
		int StartDay = (DateNumber-(StartYear*10000000+EndDay*10000+EndYear))/100000000000;

		//std::cout << StartDay << " " << StartYear << " " << EndDay << " " << EndYear << std::endl;


		return (365*(EndYear-StartYear)+(EndDay-StartDay)+(EndYear-StartYear)/4);
	}

	////////////////////////////////////////////////////////////////////////////////
}
#endif //VRS_UFVG_READER_CPP


