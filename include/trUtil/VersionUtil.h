/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
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
* Author: Maxim Serebrennik
*/

#pragma once

#include <trUtil/Export.h>

#include <trUtil/JSON/File.h>

#include <string>

namespace trUtil
{
    class TR_UTIL_EXPORT VersionUtil
    {
    public:

        const static std::string VERSION_FILE_NAME;
        const static std::string MAJ_VERSION;
        const static std::string MIN_VERSION;
        const static std::string YYMM_VERSION;
        const static std::string BUILD_VERSION;

        /**
        * ctor
        */
        VersionUtil();

        /**
        * dtor
        */
        ~VersionUtil();

        /**
        * Saves the version file currently in RAM to default location. 
        */
        void SaveVersionFile();

        /**
        * Sets the version numbers
        * Fills in the version numbers
        */
        void SetVersion(int maj, int min, std::string yymm, int build);

        /**
        * Sets the version numbers
        * Fills in the version numbers
        */
        void SetVersion(int maj, int min, int yymm, int build);

        /**
        * Generates a copy of the version file in RAM.
        */
        void GenerateVersionStructure();

        /**
        * Increments the version number of the build by one and 
        * sets the YYMM to current date. 
        */
        void IncrementVersion();

        /**
        * Sets the Major part of the version string
        */
        void SetMajorVersion(int maj);

        /**
        * Gets the Major part of the version string
        */
        int GetMajorVersion();

        /**
        * Sets the Minor part of the version string
        */
        void SetMinorVersion(int min);

        /**
        * Gets the Minor part of the version string
        */
        int GetMinorVersion();

        /**
        * Gets the Year/Month part of the version string
        */
        std::string GetYYMMVersion();

        /**
        * Sets the Year/Month part of the version string
        */
        void SetYYMMVersion(std::string yymm);

        /**
        * Sets the Year/Month part of the version string
        */
        void SetYYMMVersion(int yymm);

        /**
        * Sets the Build part of the version string
        */
        void SetBuildVersion(int build);

        /**
        * Gets the Build part of the version string
        */
        int GetBuildVersion();

        /**
        * Returns the full version string
        */
        std::string GetVersionString();  
		
		/**
		* Updates the version file to the most recent HG Revision and YTMM. 
		*/
		void UpdateVersion();
		
    private:
		JSON::File mVersion;

		/**
		* Returns todays date in the YYMM format as string.
		*/
		std::string GetTodaysVersionDate();

		/**
		* Returns the current system HG revision number.
		* Note that the revision number is not the commit hash and could be different on
		* individual systems. The best place to use this is on a build server.
		* This needs TR_ROOT to be set, and .hg folder to be in TR_ROOT
		*/
		int GetCurrentCommitNum();		
    };
}

