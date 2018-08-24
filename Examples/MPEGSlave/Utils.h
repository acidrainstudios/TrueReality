/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 3.0 of the License, or (at your option)
* any later version.
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
* details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* @author Maxim Serebrennik
*/
#pragma once

#include <trUtil/RefStr.h>

#include <trBase/SmrtPtr.h>

#include <osg/LightSource>

static const trUtil::RefStr PROGRAM_NAME = "TrueReality";
static const trUtil::RefStr EXE_NAME = "exampleMPEGSlave";

/**
 * @fn  void ParseCmdLineArgs(int& argc, char** argv, std::string& mpegType, std::string& fileName, std::string& ip, std::string& logFileName, std::string& logLevel);
 *
 * @brief   Parses the command line variables that are passed in to the executable.
 *
 * @param [in,out]  argc        System argument count.
 * @param [in,out]  argv        System argument values.
 * @param [in,out]  mpegType    Type of MPEG.
 * @param [in,out]  fileName    Filename of the output file, or UDP for broadcast.
 * @param [in,out]  ip          The UDP broadcast IP.
 * @param [in,out]  logFileName Filename of the log file.
 * @param [in,out]  logLevel    The log level.
 */
void ParseCmdLineArgs(int& argc, char** argv, std::string& mpegType, std::string& fileName, std::string& ip, std::string& logFileName, std::string& logLevel);