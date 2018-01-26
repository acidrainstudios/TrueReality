/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
*
* The Base of this class has been adopted from the Delta3D engine
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
* Class Inspired by the Delta3D Engine
* http://delta3dengine.org/
*
* Author: David Guthrie
* Author: John K. Grant
* Author: William E. Johnson II
* Author: Chris Osborn
* Author: Maxim Serebrennik
*/
#pragma once

#include <trUtil/Export.h>

#include <trUtil/PlatformMacros.h>
#include <trUtil/RefStr.h>

#include <string>
#include <vector>


namespace trUtil
{
    namespace PathUtils
    {
#ifdef __APPLE__
		const static std::string DEFAULT_TR_FOLDER("/TrueReality");
#elif defined(TR_WIN)
		const static std::string DEFAULT_TR_FOLDER("\\TrueReality");
#else
		const static std::string DEFAULT_TR_FOLDER("/.trueReality");
#endif
        const static std::string DATA_PATH_DEFAULT("/Data");
        const static std::string STATIC_MESHES_PATH("/StaticMeshes");
        const static std::string SKELETAL_MESHES_PATH("/SkeletalMeshes");
        const static std::string SOUNDS_PATH("/Sounds");
        const static std::string PARTICLES_PATH("/Particles");
        const static std::string TEXTURES_PATH("/Textures");
        const static std::string TERRAINS_PATH("/Terrains");
        const static std::string SHADERS_PATH("/Shaders");
        const static std::string GUI_PATH("/GUI");
        const static std::string CONFIG_PATH("/Config");
        

        /**
        * Get the USER Home directory
        */
        TR_UTIL_EXPORT std::string GetHomeDirectory();

        /**
        * Get the folder where TR will save and store User data files
        * It is MyDocuments on Windows and the same as GetHomeDirectory()
        * on Linux and Apple
        * If TR_USER_DATA Environmental variable is defined, it will return
        * the path in TR_USER_DATA
        */
		TR_UTIL_EXPORT std::string GetUserDataPath();

        /**
        * Get the folder where TR will save and store the log files
        * It is the same as GetUserDataPath() by default, unless the variable 
        * TR_LOG_PATH is set.
        */
        TR_UTIL_EXPORT std::string GetLogPath();

        /**
        * Set the list of data file paths
        */
        TR_UTIL_EXPORT void SetDataFilePathList(const std::string& pathList);

        /**
        * Get the list of data file paths
        */
        TR_UTIL_EXPORT std::string GetDataFilePathList();

        /**
        * Get the TR Data file path.  This comes directly from the environment
        * variable "TR_DATA", if it wasn't overwritten by the user.  If the environment variable is not set,
        * TR_ROOT/Data directory will be returned.
        * @todo need to decide how paths will be handled.  We need to decide if TR_DATA is a list or a single item.
        */
        TR_UTIL_EXPORT std::string GetDataPath();

        /**
        * Overwrites the Data path. If this is set, TR will ignore the TR_DATA varible and use the
        * passed in value instead. 
        */
        TR_UTIL_EXPORT void SetDataPath(std::string path);

        /**
        * Creates all the folders in the Data (TR_DATA) folder, that includes Maps, GUI, Shaders, StaticMeshes, etc etc
        **/
        TR_UTIL_EXPORT void CreateDataPathTree();

		/**
		* Creates all the folders in the Data (TR_USER_DATA) folder, that includes Maps, GUI, Shaders, StaticMeshes, etc etc
		**/
		TR_UTIL_EXPORT void CreateUserDataPathTree();

        /**
        * Convenience function that calls CreateDataPathTree() and CreateUserDataPathTree();
        */
        TR_UTIL_EXPORT void CreateDataPathTrees();

        /**
        * Get the root path to the engine (equivalent to the TR_ROOT environment)
        * If the TR_ROOT environment is not set, the local directory will be
        * returned.
        */
        TR_UTIL_EXPORT std::string GetRootPath();
                

        /**
        * Convenience method to get the supplied environment variable
        */
        TR_UTIL_EXPORT std::string GetEnvironment(const std::string& env);

        /**
        * Is the supplied environment variable defined?
        */
        TR_UTIL_EXPORT bool IsEnvironment(const std::string& env);

        /**
        * Sets an environment variable.
        * @param name the name of the variable to set.
        * @param value the value of the environment variable to set.
        */
        TR_UTIL_EXPORT void SetEnvironment(const std::string& name, const std::string& value);

        /**
        * Searches for a file in the list of paths found by calling GetDataFilePathList()
        * @param fileName Can be a single filename or a path and file name relative
        *  to the current engines data path list.
        * @return The full path to the file requested or empty string if it's not found.
        */
        TR_UTIL_EXPORT std::string FindFile(const std::string& fileName);

        /**
        * Searches a given path list for a file name.
        * @param fileName Can be a single filename or a path and file name relative
        *  to the current engines data path list.
        * @param paths the list of file paths to search.
        * @param caseInsensitive  If the search should be case insensitive.  This only works around case-sensitive file systems,
        *                         it cannot not make a search fail if the case is wrong on a case insensitive one and one sets it to false.
        *
        */
        TR_UTIL_EXPORT std::string FindFile(const std::string& fileName, std::vector<std::string> paths, bool caseInsensitive = true);

#ifdef __APPLE__
        /**
        * @return the resource path inside the current application bundle.
        * This is used internally, and this api is subject to change.
        */
        std::string GetBundleResourcesPath();

        /**
        * @return the plugins path inside the current application bundle.
        * This is used internally, and this api is subject to change.
        */
        std::string GetBundlePlugInsPath();

        /**
        * @return the application bundle path.
        * This is used internally, and this api is subject to change.
        */
        std::string GetBundlePath();


        void RemovePSNCommandLineOption(int& argc, char**& argv);
#else
        inline void RemovePSNCommandLineOption(int& argc, char**& argv) {}
#endif

    }
}

