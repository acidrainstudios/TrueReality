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


#ifndef VRS_VRSNETCDFCONV_CPP
#define VRS_VRSNETCDFCONV_CPP


#include "..\\Include\vrsNetCDFConv.h"

vrsNetCDFConv::vrsNetCDFConv(void)
{
}

void vrsNetCDFConv::Convert(std::string InFilePath, std::string UFPGFilePath)
{
	int XPos = 0;				//number of X pos in the file
	int YPos = 0;				//number of Y pos in the file
	int NumOfSig = 0;			//number of Sigma pos in the file
	int NumTimeRec = 0;			//number of Time pos in the file
	
	vrsUFVG::NetCDFReader mReaderIndex;			//Reads Data from the datafile
	mReaderIndex.LoadFile(InFilePath, 0, 0, false);

	XPos = mReaderIndex.GetNumOfXPos();
	YPos = mReaderIndex.GetNumOfYPos();
	NumOfSig = mReaderIndex.GetNumOfSigmas();
	NumTimeRec = mReaderIndex.GetNumOfTimeRecords();



	float count = 0;
	std::stringstream out2;
	std::string IndexFile;
	out2 << UFPGFilePath << "/index.ufvg";							//combine the filepath and file name
	IndexFile = out2.str();

	std::ofstream indexfile;		//write out the new files
	
	std::cout << "\nCreating Index file: " << IndexFile << std::endl;
	indexfile.open(IndexFile.c_str());
	if (!indexfile.is_open())
	{
		std::cout << "-->Error Creating " << IndexFile << std::endl;
		indexfile.close();
	}

	

	std::cout << "\n\nvrsNetCDFConv is preparing to start the conversion..." << std::endl;

	indexfile << XPos << " " << YPos << " " << NumOfSig << " " << NumTimeRec << std::endl;
	
	for(int i=0; i<NumOfSig; i++)
	{
		indexfile << mReaderIndex.GetSigma(i) << std::endl;
	}

	for(int i=0; i<XPos; i++)
	{
		for(int j=0; j<YPos; j++)
		{
			vrsUFVG::NetCDFReader mReader;
			mReader.LoadFile(InFilePath, i, j);

			std::stringstream out1;
			std::string UFPGFile, IndexFile; 
			out1 << UFPGFilePath << "/netCDF_" << i << "_" << j <<".ufvg"; //combine the filepath and file name
			UFPGFile = out1.str();

			if((mReader.GetLat() > -700 && mReader.GetLat() < 700) && (mReader.GetLon() > -700 && mReader.GetLon() < 700))
			{
				indexfile << std::fixed;
				indexfile << i << " " << j << " " << mReader.GetLat() << " " << mReader.GetLon() << std::endl;

				std::cout << "Exporting file: " << UFPGFile << " " << (count/(XPos*YPos))*100.00 << "% done..." << std::endl;

				std::ofstream ufpgfile;		//write out the new files
				
				ufpgfile.open (UFPGFile.c_str());
				if (!ufpgfile.is_open())
				{	
					std::cout << "-->Error Creating " << UFPGFile << std::endl;
					ufpgfile.close();
				}
				
				
				
				ufpgfile << std::fixed;
				ufpgfile << mReader.GetDepth() << std::endl;
																		
				for(int t = 0; t<mReader.GetNumOfTimeRecords(); t++)
				{
					ufpgfile << mReader.GetDateTime(t) << std::endl;

					for(int s=0; s<mReader.GetNumOfSigmas(); s++)
					{
						float x=0;
						float y=0;
						float speed = 0; //sqrtf
						x=mReader.GetWaterU(t,s);
						y=mReader.GetWaterV(t,s);
						speed = sqrtf(((x*x)+(y*y)));
						
						ufpgfile << speed << std::endl;
						ufpgfile << mReader.GetWaterDirection(t,s) << std::endl;
					}
				}
				
				ufpgfile.close();
				count++;
			}
			else
			{
				std::cout << "<>Skipping file: " << "netCDF_" << i << "_" << j <<".ufvg" << " " << " Bad Data Found... " << (count/(XPos*YPos))*100.00 << "% done..." << std::endl;
				count++;
			}

		}
	}
	indexfile.close();

	
}





#endif //VRS_VRSNETCDFCONVR_CPP