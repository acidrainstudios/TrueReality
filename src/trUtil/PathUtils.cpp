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
* @author David Guthrie
* @author John K. Grant
* @author William E. Johnson II
* @author Chris Osborn
* @author Maxim Serebrennik
*/

#include <trUtil/PathUtils.h>

#include <trUtil/EnvVariables.h>
#include <trUtil/FileUtils.h>
#include <trUtil/PlatformMacros.h>
#include <trUtil/StringUtils.h>
#include <trUtil/Logging/Log.h>

#include <osgDB/FileUtils>
#include <osgDB/FileNameUtils>

#ifdef TR_APPLE
    #include <AvailabilityMacros.h>
    #include <Foundation/Foundation.h>
#endif

#ifdef TR_WIN
    #include <Shlobj.h>
#else
    #include <pwd.h>
    #include <unistd.h>
#endif

namespace trUtil
{
    namespace PathUtils
    {
        static OpenThreads::Mutex gDatapathMutex;
        
        static std::string mDataPath = trUtil::StringUtils::STR_BLANK;
        
        /////////////////////////////////////////////////////////////////////////////
        std::string GetUserHomeDirectory()
        {
            std::string homedir;
#ifdef TR_WIN
            char path[MAX_PATH];
            if (SUCCEEDED(SHGetFolderPathA(nullptr, CSIDL_PROFILE, nullptr, 0, path))) {
                homedir = path;
            }
#else
            int maxSize = sysconf(_SC_GETPW_R_SIZE_MAX);
            char* buffer = new char[maxSize];
            struct passwd pw, *resultOut = NULL;
            int rc = getpwuid_r(getuid(), &pw, buffer, maxSize, &resultOut);
            if (rc == 0 && resultOut != NULL)
            {
                homedir = pw.pw_dir;
            }
            delete[] buffer;
            buffer = NULL;
#endif
            return homedir;
        }
        
        /////////////////////////////////////////////////////////////////////////////
        std::string GetDataPath()
        {
            std::string result;
            
            if (mDataPath != trUtil::StringUtils::STR_BLANK)
            {
                result = mDataPath;
            }
            else
            {
                if (IsEnvironment(EnvVariables::TR_DATA))
                {
                    result = GetEnvironment(EnvVariables::TR_DATA);
                }
                else
                {
                    result = GetRootPath() + DATA_PATH_DEFAULT;
                }
                mDataPath = result;
            }
#ifdef TR_APPLE
            // Have to recheck because the get environment call doesn't currently return empty when it doesn't exist.
            char* ptr = getenv(EnvVariables::TR_DATA);
            
            if (mDataPath != trUtil::StringUtils::STR_BLANK)
            {
                result = mDataPath;
            }
            else if(ptr == NULL)
            {
                result = GetBundleResourcesPath() + DATA_PATH_DEFAULT;
            }
#endif
            
            return result;
        }
        
        /////////////////////////////////////////////////////////////////////////////
        void SetDataPath(std::string& path)
        {
            mDataPath = path;
        }
        
        /////////////////////////////////////////////////////////////////////////////
        void CreateDataPathTree()
        {
            try
            {
                FileUtils::GetInstance().MakeDirectoryEX(GetDataPath() + STATIC_MESHES_PATH);
                FileUtils::GetInstance().MakeDirectoryEX(GetDataPath() + SKELETAL_MESHES_PATH);
                FileUtils::GetInstance().MakeDirectoryEX(GetDataPath() + SOUNDS_PATH);
                FileUtils::GetInstance().MakeDirectoryEX(GetDataPath() + PARTICLES_PATH);
                FileUtils::GetInstance().MakeDirectoryEX(GetDataPath() + TEXTURES_PATH);
                FileUtils::GetInstance().MakeDirectoryEX(GetDataPath() + TERRAINS_PATH);
                FileUtils::GetInstance().MakeDirectoryEX(GetDataPath() + SHADERS_PATH);
                FileUtils::GetInstance().MakeDirectoryEX(GetDataPath() + GUI_PATH);
                FileUtils::GetInstance().MakeDirectoryEX(GetDataPath() + CONFIG_PATH);
            }
            catch (const trUtil::Exception& ex)
            {
                ex.LogException();
            }
        }
        
        /////////////////////////////////////////////////////////////////////////////
        void CreateUserDataPathTree()
        {
            try
            {
                FileUtils::GetInstance().MakeDirectoryEX(GetUserDataPath() + STATIC_MESHES_PATH);
                FileUtils::GetInstance().MakeDirectoryEX(GetUserDataPath() + SKELETAL_MESHES_PATH);
                FileUtils::GetInstance().MakeDirectoryEX(GetUserDataPath() + SOUNDS_PATH);
                FileUtils::GetInstance().MakeDirectoryEX(GetUserDataPath() + PARTICLES_PATH);
                FileUtils::GetInstance().MakeDirectoryEX(GetUserDataPath() + TEXTURES_PATH);
                FileUtils::GetInstance().MakeDirectoryEX(GetUserDataPath() + TERRAINS_PATH);
                FileUtils::GetInstance().MakeDirectoryEX(GetUserDataPath() + SHADERS_PATH);
                FileUtils::GetInstance().MakeDirectoryEX(GetUserDataPath() + GUI_PATH);
                FileUtils::GetInstance().MakeDirectoryEX(GetUserDataPath() + CONFIG_PATH);
            }
            catch (const trUtil::Exception& ex)
            {
                ex.LogException();
            }
        }
        
        /////////////////////////////////////////////////////////////////////////////
        void CreateDataPathTrees()
        {
            try
            {
                CreateUserDataPathTree();
                CreateDataPathTree();
            }
            catch (const trUtil::Exception& ex)
            {
                ex.LogException();
            }
        }

        /////////////////////////////////////////////////////////////////////////////
        std::string GetRootPath()
        {
            std::string result;
            if (IsEnvironment(EnvVariables::TR_ROOT))
            {
                result = GetEnvironment(EnvVariables::TR_ROOT);
            }
            else
            {
                //The Root folder should be one level up from the Bin folder, so just return the parent
                result = "../";
            }
#ifdef TR_APPLE
            // Have to recheck because the get environment call doesn't currently return empty when it doesn't exist.
            char* ptr = getenv(EnvVariables::TR_ROOT);
            if (ptr == NULL)
            {
                result = GetBundleResourcesPath();
            }
#endif
            return result;
        }
        
        /////////////////////////////////////////////////////////////////////////////
        std::string GetLogPath()
        {
            if (IsEnvironment(EnvVariables::TR_LOG_PATH))
            {
                return GetEnvironment(EnvVariables::TR_LOG_PATH);
            }
            else
            {
                return GetUserDataPath();
            }
        }

        /////////////////////////////////////////////////////////////////////////////
        std::string GetUserDataPath()
        {
            if (IsEnvironment(EnvVariables::TR_USER_DATA))
            {
                return GetEnvironment(EnvVariables::TR_USER_DATA);
            }
            else
            {
                std::string userDir;
#ifdef TR_WIN
                char path[MAX_PATH];
                if (SUCCEEDED(SHGetFolderPathA(nullptr, CSIDL_MYDOCUMENTS, nullptr, 0, path)))
                {
                    userDir = path + DEFAULT_TR_FOLDER;
                }
#else
                userDir = GetHomeDirectory() + DEFAULT_TR_FOLDER;
#endif
                return userDir;
            }           
        }
        
        /////////////////////////////////////////////////////////////////////////////
        void SetDataFilePathList(const std::string& pathList)
        {
            OpenThreads::ScopedLock<OpenThreads::Mutex> lock(gDatapathMutex);
            
            std::string modpath = pathList;
            std::string::size_type pathLength = pathList.size();
            for (std::string::size_type i = 0; i < pathLength; ++i)
            {
#ifdef TR_WIN
                try
                {
                    // TODO: Determine why this silly thing is even being done.
                    // Did anyone consider that this would destroy a path with
                    // drive letter such as C:/... ? How about we do not concatenate
                    // paths with colons? CR
                    if (modpath.at(i) == ':' && (i + 1 >= pathLength || modpath.at(i + 1) != '\\'))
                    {
                        modpath.at(i) = ';';
                    }
                }
                catch (std::out_of_range &myexcept)
                {
                    LOG_W(myexcept.what());
                }
#else
                if (modpath[i] == ';')
                {
                    modpath[i] = ':';
                }
#endif
            }
            osgDB::setDataFilePathList(modpath);
        }
        
        /////////////////////////////////////////////////////////////////////////////
        std::string GetDataFilePathList()
        {
            OpenThreads::ScopedLock<OpenThreads::Mutex> lock(gDatapathMutex);
            
            osgDB::FilePathList pathList = osgDB::getDataFilePathList();
            
            std::string pathString = "";
            
            using StringDeque = std::deque<std::string>;
            for (StringDeque::iterator itr = pathList.begin(); itr != pathList.end(); ++itr)
            {
                pathString += *itr;
                
                StringDeque::iterator next = itr + 1;         if (next != pathList.end())
                {
#ifdef TR_WIN
                    pathString += ';';
#else
                    pathString += ':';
#endif
                }
            }
            
            return pathString;
        }
        
        /////////////////////////////////////////////////////////////////////////////
        std::string FindFile(const std::string& fileName)
        {
            OpenThreads::ScopedLock<OpenThreads::Mutex> lock(gDatapathMutex);
            
            std::string filePath = osgDB::findDataFile(fileName, osgDB::CASE_INSENSITIVE);
            
            // In some cases, filePath will contain a url that is
            // relative to the current working directory so for
            // consistency, be sure to return the full path every time
            if (!filePath.empty())
            {
                filePath = osgDB::getRealPath(filePath);
            }
            
            return filePath;
            
        }
        
        /////////////////////////////////////////////////////////////////////////////
        std::string FindFile(const std::string& fileName, std::vector<std::string> pathList, bool caseInsensitive)
        {
            std::vector<std::string>::const_iterator itor;
            
            trUtil::FileUtils& fileUtils = trUtil::FileUtils::GetInstance();
            std::string path;
            for (itor = pathList.begin(); itor != pathList.end(); ++itor)
            {
                path = *itor;
                //Make sure we remove any trailing slashes from the cache path.
                if (path[path.length() - 1] == '/' || path[path.length() - 1] == '\\')
                    path = path.substr(0, path.length() - 1);
                
                FileInfo fi = fileUtils.GetFileInfo(path + FileUtils::PATH_SEPARATOR + fileName, caseInsensitive);
                if (fi.fileType != FILE_NOT_FOUND)
                {
                    return fi.fileName;
                }
            }
            
            return std::string();
        }
        
        /////////////////////////////////////////////////////////////////////////////
        std::string GetEnvironment(const std::string& env)
        {
#ifdef TR_WIN
            const size_t bufferSize = 32767;
            TCHAR  buffer[bufferSize], buffer2[bufferSize];
            size_t sizeOut1 = GetEnvironmentVariable(env.c_str(), buffer, bufferSize);
            size_t sizeOut2 = ExpandEnvironmentStrings(buffer, buffer2, bufferSize);
            if (sizeOut1 <= bufferSize && sizeOut2 <= bufferSize && sizeOut1 > 0 && sizeOut2 > 0)
            {
                return buffer2;
            }
#endif
            char* ptr = getenv(env.c_str());
            if (ptr != nullptr)
            {
                return std::string(ptr);
            }
            else
            {
                return std::string("./");
            }
        }
        
        /////////////////////////////////////////////////////////////////////////////
        void SetEnvironment(const std::string& name, const std::string& value)
        {
#ifdef TR_WIN
            //technically we have to do both because windows has two different environments
            SetEnvironmentVariable(name.c_str(), value.c_str());
            _putenv_s(name.c_str(), value.c_str());
#else
            setenv(name.c_str(), value.c_str(), true);
#endif
        }
        
#ifdef TR_APPLE
        /////////////////////////////////////////////////////////////////////////////              
        std::string GetBundleResourcesPath()
        {
            // Since this is currently the only Objective-C code in the
            // library, we need an autoreleasepool for obj-c memory management.
            // If more Obj-C is added, we might move this pool to another
            // location so it can be shared. Pools seem to be stackable,
            // so I don't think there will be a problem if multiple pools
            // exist at a time.
            NSAutoreleasePool* mypool = [[NSAutoreleasePool alloc] init];
            
            // This is the path to the resources inside the app bundle.
            NSString* resourcePathNS = [[NSBundle mainBundle] resourcePath];
            
            // Make a c string from the cocoa one tack data on the end.
            std::string result = std::string([resourcePathNS UTF8String]);
            
            // Clean up the autorelease pool
            [mypool release];
            return result;
        }
        
        /////////////////////////////////////////////////////////////////////////////
        std::string GetBundlePlugInsPath()
        {
            // Since this is currently the only Objective-C code in the
            // library, we need an autoreleasepool for obj-c memory management.
            // If more Obj-C is added, we might move this pool to another
            // location so it can be shared. Pools seem to be stackable,
            // so I don't think there will be a problem if multiple pools
            // exist at a time.
            NSAutoreleasePool* mypool = [[NSAutoreleasePool alloc] init];
            
            // This is the path to the resources inside the app bundle.
            NSString* resourcePathNS = [[NSBundle mainBundle] builtInPlugInsPath];
            
            // Make a c string from the cocoa one tack data on the end.
            std::string result = std::string([resourcePathNS UTF8String]);
            
            // Clean up the autorelease pool
            [mypool release];
            return result;
        }
        
        /////////////////////////////////////////////////////////////////////////////
        std::string GetBundlePath()
        {
            // Since this is currently the only Objective-C code in the
            // library, we need an autoreleasepool for obj-c memory management.
            // If more Obj-C is added, we might move this pool to another
            // location so it can be shared. Pools seem to be stackable,
            // so I don't think there will be a problem if multiple pools
            // exist at a time.
            NSAutoreleasePool* mypool = [[NSAutoreleasePool alloc] init];
            
            // This is the path to the resources inside the app bundle.
            NSString* resourcePathNS = [[NSBundle mainBundle] bundlePath];
            
            // Make a c string from the cocoa one tack data on the end.
            std::string result = std::string([resourcePathNS UTF8String]);
            
            // Clean up the autorelease pool
            [mypool release];
            return result;
        }
        
        /////////////////////////////////////////////////////////////////////////////
        void RemovePSNCommandLineOption(int& argc, char**& argv)
        {
            static std::string osxPSN("-psn_");
            for (int i = 0; i < argc; ++i)
            {
                if (std::string(argv[i]).compare(0, osxPSN.length(), osxPSN) == 0)
                {
                    for (int j = i; j < argc; ++j)
                    {
                        if (j == argc - 1)
                        {
                            argv[j] = 0;
                        }
                        else
                        {
                            argv[j] = argv[j + 1];
                        }
                    }
                    --argc;
                }
            }
        }
#endif
        
        /////////////////////////////////////////////////////////////////////////////
        bool IsEnvironment(const std::string& env)
        {
            if (getenv(env.c_str()))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        /////////////////////////////////////////////////////////////////////////////
        std::string GetStaticMeshesPath()
        {
            return GetDataPath() + STATIC_MESHES_PATH;
        }

        /////////////////////////////////////////////////////////////////////////////
        std::string GetSkeletalMeshesPath()
        {
            return GetDataPath() + SKELETAL_MESHES_PATH;
        }

        /////////////////////////////////////////////////////////////////////////////
        std::string GetSoundsPath()
        {
            return GetDataPath() + SOUNDS_PATH;
        }

        /////////////////////////////////////////////////////////////////////////////
        std::string GetParticlesPath()
        {
            return GetDataPath() + PARTICLES_PATH;
        }

        /////////////////////////////////////////////////////////////////////////////
        std::string GetTexturesPath()
        {
            return GetDataPath() + TEXTURES_PATH;
        }

        /////////////////////////////////////////////////////////////////////////////
        std::string GetTerrainsPath()
        {
            return GetDataPath() + TERRAINS_PATH;
        }

        /////////////////////////////////////////////////////////////////////////////
        std::string GetShadersPath()
        {
            return GetDataPath() + SHADERS_PATH;
        }

        /////////////////////////////////////////////////////////////////////////////
        std::string GetGUIPath()
        {
            return GetDataPath() + GUI_PATH;
        }

        /////////////////////////////////////////////////////////////////////////////
        std::string GetConfigPath()
        {
            return GetDataPath() + CONFIG_PATH;
        }

        /////////////////////////////////////////////////////////////////////////////
        std::string GetUserStaticMeshesPath()
        {
            return GetUserDataPath() + STATIC_MESHES_PATH;
        }

        /////////////////////////////////////////////////////////////////////////////
        std::string GetUserSkeletalMeshesPath()
        {
            return GetUserDataPath() + SKELETAL_MESHES_PATH;
        }

        /////////////////////////////////////////////////////////////////////////////
        std::string GetUserSoundsPath()
        {
            return GetUserDataPath() + SOUNDS_PATH;
        }

        /////////////////////////////////////////////////////////////////////////////
        std::string GetUserParticlesPath()
        {
            return GetUserDataPath() + PARTICLES_PATH;
        }

    }
}