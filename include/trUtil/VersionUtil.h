/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2018 Acid Rain Studios LLC
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

#include <trUtil/Export.h>

#include <trUtil/JSON/File.h>

#include <string>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil
{
    /**
     * @class   VersionUtil
     *
     * @brief   A utility to read and control the engines version numbers.
     *          
     * @author Maxim Serebrennik
     */
    class TR_UTIL_EXPORT VersionUtil
    {
    public:

        const static std::string VERSION_FILE_NAME;
        const static std::string MAJ_VERSION;
        const static std::string MIN_VERSION;
        const static std::string YYMM_VERSION;
        const static std::string BUILD_VERSION;

        /**
         * @fn  VersionUtil::VersionUtil();
         *
         * @brief   ctor.
         */
        VersionUtil();

        /**
         * @fn  VersionUtil::VersionUtil(std::string fileName);
         *
         * @brief   Constructor.
         *
         * @param   fileName    Filename of the custom version file.
         */
        VersionUtil(std::string fileName);

        /**
         * @fn  VersionUtil::VersionUtil(std::string fileName, std::string filePath);
         *
         * @brief   Constructor.
         *
         * @param   fileName    Filename of the custom version file.
         * @param   filePath    Full path to where the version file is located. 
         */
        VersionUtil(std::string fileName, std::string filePath);

        /**
         * @fn  VersionUtil::~VersionUtil();
         *
         * @brief   dtor.
         */
        ~VersionUtil();

        /**
         * @fn  void VersionUtil::SaveVersionFile();
         *
         * @brief   Saves the version file currently in RAM to default location.
         */
        void SaveVersionFile();

        /**
         * @fn  void VersionUtil::SetVersion(int maj, int min, std::string yymm, int build);
         *
         * @brief   Sets the version numbers. Fills in the version numbers.
         *
         * @param   maj     The maj.
         * @param   min     The minimum.
         * @param   yymm    The yymm.
         * @param   build   The build.
         */
        void SetVersion(int maj, int min, std::string yymm, int build);

        /**
         * @fn  void VersionUtil::SetVersion(int maj, int min, int yymm, int build);
         *
         * @brief   Sets the version numbers. Fills in the version numbers.
         *
         * @param   maj     The maj.
         * @param   min     The minimum.
         * @param   yymm    The yymm.
         * @param   build   The build.
         */
        void SetVersion(int maj, int min, int yymm, int build);

        /**
         * @fn  void VersionUtil::GenerateVersionStructure();
         *
         * @brief   Generates a copy of the version file in RAM.
         */
        void GenerateVersionStructure();

        /**
         * @fn  void VersionUtil::IncrementVersion();
         *
         * @brief   Increments the version number of the build by one and sets the YYMM to current date.
         */
        void IncrementVersion();

        /**
         * @fn  void VersionUtil::SetMajorVersion(int maj);
         *
         * @brief   Sets the Major part of the version string.
         *
         * @param   maj The maj.
         */
        void SetMajorVersion(int maj);

        /**
         * @fn  int VersionUtil::GetMajorVersion();
         *
         * @brief   Gets the Major part of the version string.
         *
         * @return  The major version.
         */
        int GetMajorVersion();

        /**
         * @fn  void VersionUtil::SetMinorVersion(int min);
         *
         * @brief   Sets the Minor part of the version string.
         *
         * @param   min The minimum.
         */
        void SetMinorVersion(int min);

        /**
         * @fn  int VersionUtil::GetMinorVersion();
         *
         * @brief   Gets the Minor part of the version string.
         *
         * @return  The minor version.
         */
        int GetMinorVersion();

        /**
         * @fn  std::string VersionUtil::GetYYMMVersion();
         *
         * @brief   Gets the Year/Month part of the version string.
         *
         * @return  The yymm version.
         */
        std::string GetYYMMVersion();

        /**
         * @fn  void VersionUtil::SetYYMMVersion(std::string yymm);
         *
         * @brief   Sets the Year/Month part of the version string.
         *
         * @param   yymm    The yymm.
         */
        void SetYYMMVersion(std::string yymm);

        /**
         * @fn  void VersionUtil::SetYYMMVersion(int yymm);
         *
         * @brief   Sets the Year/Month part of the version string.
         *
         * @param   yymm    The yymm.
         */
        void SetYYMMVersion(int yymm);

        /**
         * @fn  void VersionUtil::SetBuildVersion(int build);
         *
         * @brief   Sets the Build part of the version string.
         *
         * @param   build   The build.
         */
        void SetBuildVersion(int build);

        /**
         * @fn  int VersionUtil::GetBuildVersion();
         *
         * @brief   Gets the Build part of the version string.
         *
         * @return  The build version.
         */
        int GetBuildVersion();

        /**
         * @fn  std::string VersionUtil::GetVersionString();
         *
         * @brief   Returns the full version string.
         *
         * @return  The version string.
         */
        std::string GetVersionString();  

        /**
         * @fn  void VersionUtil::UpdateVersion();
         *
         * @brief   Updates the version file to the most recent HG/Git Revision and YTMM.
         */
        void UpdateVersion();
        
    private:
        JSON::File mVersion;

        /**
         * @fn  std::string VersionUtil::GetTodaysVersionDate();
         *
         * @brief   Returns todays date in the YYMM format as string.
         *
         * @return  The todays version date.
         */
        std::string GetTodaysVersionDate();

        /**
         * @fn  int VersionUtil::GetCurrentCommitNum();
         *
         * @brief   Returns the current system HG/Git revision number. Note that the revision number is
         *          not the commit hash and could be different on individual systems. The best place to
         *          use this is on a build server. This needs TR_ROOT to be set, and .hg or .git folder
         *          to be in TR_ROOT.
         *
         * @return  The current commit number.
         */
        int GetCurrentCommitNum();        
    };
}