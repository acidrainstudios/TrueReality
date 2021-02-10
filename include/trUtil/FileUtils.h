/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2021 Acid Rain Studios LLC
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
* @author David Guthrie
* @author Maxim Serebrennik
*/
#pragma once

#include <trUtil/Export.h>

#include <trUtil/Exception.h>
#include <trUtil/UnaryFunction.h>

#include <osg/Referenced>
#include <osg/Version>
#include <osgDB/ReaderWriter>
#include <osgDB/FileUtils>

#include <vector>
#include <string>

/// @cond DOXYGEN_SHOULD_SKIP_THIS
#if OPENSCENEGRAPH_MAJOR_VERSION < 3
namespace osgDB
{
    class ArchiveExtended;
}
#else
namespace osgDB
{
    using ArchiveExtended = Archive;
}
#endif
/// @endcond

namespace trUtil
{
    class Log;

    using DirectoryContents = std::vector<std::string>;
    using FileExtensionList = std::vector<std::string>;

    /**
     * @enum    FileType
     *
     * @brief   Values that represent file types.
     */
    enum FileType
    {
        FILE_NOT_FOUND,
        REGULAR_FILE,
        DIRECTORY,
        ARCHIVE
    };

    /**
     * @struct  FileInfo
     *
     * @brief   struct holding information about a file.
     */
    struct FileInfo
    {
        std::string fileName; ///< the file name with full path
        std::string path; ///< the path to the file
        std::string baseName; ///< the file name with extension
        std::string extensionlessFileName; ///< the file name with extension
        std::string extension; ///< the file extension
        size_t size; ///< the size of the file in bytes.
        time_t lastModified; ///< when the file was last modified.
        FileType fileType; ///< The enum value specifying the type of file
        bool isInArchive; ///< true if the specified file lives within an archive

        FileInfo() : size(0), lastModified(0), fileType(FILE_NOT_FOUND), isInArchive(false) {}
    };

    /**
     * @class   FileUtilIOException
     *
     * @brief   Exception for signaling file utility i/o errors.
     */
    class TR_UTIL_EXPORT FileUtilIOException : public trUtil::Exception
    {
    public:
        FileUtilIOException(const std::string& message, const std::string& filename, unsigned int linenum);
        virtual ~FileUtilIOException() {};
    };

    /**
     * @class   FileNotFoundException
     *
     * @brief   Exception for signalling file not found errors.
     */
    class TR_UTIL_EXPORT FileNotFoundException : public trUtil::Exception
    {
    public:
        FileNotFoundException(const std::string& message, const std::string& filename, unsigned int linenum);
        virtual ~FileNotFoundException() {};
    };

    /**
     * @class   FileUtils
     *
     * @brief   Singleton class implementing basic file operations.
     */
    class TR_UTIL_EXPORT FileUtils : public osg::Referenced
    {
    public:
        static const char PATH_SEPARATOR; /// Character separating the parts of a file path.

        /**
         * @fn  static FileUtils& FileUtils::GetInstance()
         *
         * @brief   Gets the instance.
         *
         * @return  the single instance of this class.
         */
        static FileUtils& GetInstance()
        {
            if (mInstance == NULL)
            {
                mInstance = new FileUtils();
            }
            return *mInstance;
        }

        /**
         * @fn  std::string FileUtils::RunCommand(const char* cmd);
         *
         * @brief   Runs a command on the console, and returns the console printout in a form of a string.
         *
         * @param   cmd The command.
         *
         * @return  A std::string.
         */
        std::string RunCommand(const char* cmd);

        /**
         * @fn  std::string FileUtils::RunCommand(const std::string cmd);
         *
         * @brief   Runs a command on the console, and returns the console printout in a form of a string.
         *
         * @param   cmd The command.
         *
         * @return  A std::string.
         */
        std::string RunCommand(const std::string cmd);

        /**
         * @fn  bool FileUtils::FileExists(const std::string& strFile, bool caseInsensitive = false) const;
         *
         * @brief   Queries if a given file exists.
         *
         * @param   strFile         the path to the file to check.
         * @param   caseInsensitive (Optional) false for native, true for forced case insensitivity on
         *                          platforms that normally are sensitive.
         *
         * @return  true if the file exists.
         */
        bool FileExists(const std::string& strFile, bool caseInsensitive = false) const;

        /**
         * @fn  void FileUtils::FileCopy(const std::string& strSrc, const std::string& strDest, bool bOverwrite) const;
         *
         * @brief   Copys a file.
         *
         * @exception   trUtil::FileNotFoundException   if the source file is not found.
         * @exception   trUtil::IOException             if an error occurs copying the data or bOverwrite
         *                                              was false and the
         *                                                            destination file exists.
         *
         * @param   strSrc      The path to the source file.
         * @param   strDest     The path to the destination file or directory.
         * @param   bOverwrite  true if this call should overwrite the destination file if it exists.
         */
        void FileCopy(const std::string& strSrc, const std::string& strDest, bool bOverwrite) const;

        /**
         * @fn  void FileUtils::FileMove(const std::string& strSrc, const std::string& strDest, bool bOverwrite) const;
         *
         * @brief   Moves a file. This call will attempt to move the file without moving the data, but if
         *          it can't, the file will first be copied then the source file will be removed.
         *
         * @exception   trUtil::FileNotFoundException   if the source file is not found.
         * @exception   trUtil::IOException             if an error occurs moving the data or bOverwrite
         *                                              was false and the
         *                                                            destination file exists.
         *
         * @param   strSrc      The path to the source file.
         * @param   strDest     The path to the destintion file or directory.
         * @param   bOverwrite  true if this call should overwrite the destination file if it exists.
         */
        void FileMove(const std::string& strSrc, const std::string& strDest, bool bOverwrite) const;

        /**
         * @fn  void FileUtils::FileDelete(const std::string& strFile) const;
         *
         * @brief   Deletes the given file.
         *
         * @exception   trUtil::IOException if an error occurs deleting the data.
         *
         * @param   strFile the path to the file to delete.
         */
        void FileDelete(const std::string& strFile) const;

        /**
         * @struct  FileInfo
         *
         * @brief   Information about the file.
         *
         * @sa  trUtil::FileInfo
         *
         * ### param    caseInsensitive false for native behavior (default) or true to make it case
         *                              insensitive on case sensitive systems.
         *                              @note If the  file is not found, the fileType value will be set
         *                              to FILE_NOT_FOUND and all other values
         *                              will be undefined.
         * ### return   the fileInfo struct for the given file.
         */
        const struct FileInfo GetFileInfo(const std::string& strFile, bool caseInsensitive = false) const;

        /**
         * @fn  void FileUtils::CleanupFileString(std::string &strFileOrDir) const;
         *
         * @brief   Ensure that the passed in string is fit for use as a file or dir string. In our case
         *          we want all separators to be the '/' character and we do not want a separator at the
         *          end.
         *
         * @param [in,out]  strFileOrDir    The string to cleanup.
         *                                  @note The original string passed in is changed.
         */
        void CleanupFileString(std::string &strFileOrDir) const;

        /**
         * @fn  bool FileUtils::IsAbsolutePath(std::string strFileOrDir) const;
         *
         * @brief   Query whether a given string is an absolute path or not.
         *
         * @param   strFileOrDir    The path to check.
         *
         * @return  True if absolute, False if relative.
         *          @note This maybe a subjective determination, may need to add to this later.
         */
        bool IsAbsolutePath(std::string strFileOrDir) const;

        /**
         * @fn  void FileUtils::MakeDirectoryEX(std::string strDir);
         *
         * @brief   A more powerful version of the standard mkdir.  This function will check to see if
         *          the directory exists first and only create if needed.  Also, it will recursively
         *          create all subdirectories needed to create the final directory in the passed in
         *          string.
         *
         * @exception   all the exceptions that MakeDirectory throws.
         *
         * @param   strDir  The directory to create.
         *
         * @sa  ::MakeDirectory
         */
        void MakeDirectoryEX(std::string strDir);

        /**
         * @fn  void FileUtils::ChangeDirectory(const std::string& path);
         *
         * @brief   Changes the current directory to the one given in "path." This will clear the stack
         *          of directories that is set by pushDirectory and popDirectory. If this call fails, the
         *          stack will not be cleared.
         *
         * @sa  popDirectory.
         *
         * @param   path    The path to the new directory.
         *
         * @sa  pushDirectory
         *
         * @exception   trUtil::FileNotFoundException   if the path does not exist.
         */
        void ChangeDirectory(const std::string& path);

        /**
         * @fn  const std::string& FileUtils::CurrentDirectory() const;
         *
         * @brief   Current directory.
         *
         * @return  the full path to the current directory.
         */
        const std::string& CurrentDirectory() const;

        /**
         * @fn  void FileUtils::PushDirectory(const std::string& path);
         *
         * @brief   Changes the current directory to the one given in "path" and adds the previous
         *          current directory to an internal stack so it can be returned to via popDirectory. If
         *          this call fails, the stack will not be changed.
         *
         * @exception   trUtil::FileNameFoundException  if the path does not exist.
         *
         * @param   path    The path to the new directory.
         *
         * @sa  popDirectory
         */
        void PushDirectory(const std::string& path);

        /**
         * @fn  void FileUtils::PopDirectory();
         *
         * @brief   sets the current directory to the last directory on the stack.
         *
         * @exception   trUtil::FileNotFoundException   if the previous directory no longer exists.
         *
         * @sa  pushDirectory
         */
        void PopDirectory();

        /**
         * @fn  std::string FileUtils::GetAbsolutePath(const std::string& relativePath, bool removeFinalFile = false) const;
         *
         * @brief   Converts a relative path to an absolute path.
         *
         * @exception   trUtil::FileNotFoundException   if the path does not exist.
         *
         * @param   relativePath    the relative path to convert to absolute.
         * @param   removeFinalFile (Optional) If this refers to a file, then remove the final file in
         *                          the result.
         *
         * @return  the absolute path.
         */
        std::string GetAbsolutePath(const std::string& relativePath, bool removeFinalFile = false) const;

        /**
         * @fn  DirectoryContents FileUtils::DirGetFiles(const std::string& path, const FileExtensionList& extensions = FileExtensionList()) const;
         *
         * @brief   Note: throws exceptions of type trUtil::Exception.
         *
         * @exception   trUtil::FileNotFoundException   if the path does not exist.
         * @exception   trUtil::IOException             if the path is not an actual directory.
         *
         * @param   path        the path to the directory to list the contents of.
         * @param   extensions  (Optional) Optional list of file extensions to filter on, including the
         *                      "dot". (e.g., ".txt", ".xml")
         *
         * @return  a vector of file names.
         */
        DirectoryContents DirGetFiles(const std::string& path, const FileExtensionList& extensions = FileExtensionList()) const;

        /**
         * @fn  DirectoryContents FileUtils::DirGetSubs(const std::string& path) const;
         *
         * @brief   Dir get subs.
         *
         * @exception   trUtil::FileNotFoundException   if the path does not exist.
         *
         * @param   path    the path to the directory to get the subdirectories for.
         *
         * @return  a vector holding the list of subdirectories.
         */
        DirectoryContents DirGetSubs(const std::string& path) const;

        /**
         * @fn  void FileUtils::DirCopy(const std::string& srcPath, const std::string& destPath, bool bOverwrite, bool copyContentsOnly = false) const;
         *
         * @brief   Copys an entire directory.  If destPath exists, then a subdirectory will be created
         *          in destPath with the same name as srcPath unless copyContentsOnly is true, in which
         *          case the contents of srcPath will be copied into destPath.  If destPath does not
         *          exist, destPath will be created if the parent exists and the contents of srcPath will
         *          be copied to destPath whether copyContentsOnly is true or false.
         *
         * @exception   trUtil::FileNotFoundException   if the source file is not found.
         * @exception   trUtil::IOException             if an error occurs copying the data or bOverwrite
         *                                              was false and a
         *                                                            destination file exists.
         *
         * @param   srcPath             the source directory to copy.
         * @param   destPath            the destination directory.
         * @param   bOverwrite          true if this call should overwrite the destination file if it
         *                              exists.
         * @param   copyContentsOnly    (Optional) true if the contents of srcPath should be copied into
         *                              destPath rather than create a subdirectory.
         */
        void DirCopy(const std::string& srcPath, const std::string& destPath, bool bOverwrite, bool copyContentsOnly = false) const;

        /**
         * @fn  bool FileUtils::DirDelete(const std::string& strDir, bool bRecursive);
         *
         * @brief   Deletes a directory.  If bRecursive is true, the directory and all it's contents will
         *          be removed.  If it's false, the call will fail unless the directory is empty.
         *
         * @exception   trUtil::FileNotFoundException   if the path does not exist.
         * @exception   trUtil::IOException             if an error occurs deleteting the directory.
         *
         * @param   strDir      The path of the directory to delete.
         * @param   bRecursive  true if the directory should be deleted recursively.
         *
         * @return  true if successful or false if the directory is NOT empty and bRecursive is false.
         */
        bool DirDelete(const std::string& strDir, bool bRecursive);

        /**
         * @fn  void FileUtils::MakeDirectory(const std::string& strDir) const;
         *
         * @brief   creates a new directory from a path.
         *
         * @exception   trUtil::FileNotFoundException   if the parent path does not exist.
         * @exception   trUtil::IOException             if an error occurs creating the directory.
         *
         * @param   strDir  the directory to create.
         */
        void MakeDirectory(const std::string& strDir) const;

        /**
         * @fn  bool FileUtils::DirExists(const std::string& strDir, bool caseInsensitive = false) const;
         *
         * @brief   Queries if a given dir exists.
         *
         * @param   strDir          The directory to check.
         * @param   caseInsensitive (Optional) false for native, true for forced case insensitivity on
         *                          platforms that normally are sensitive.
         *
         * @return  true if the path exists and is a directory.
         */
        bool DirExists(const std::string& strDir, bool caseInsensitive = false) const;

        /**
         * @fn  std::string FileUtils::RelativePath(const std::string& absolutePath, const std::string& file) const;
         *
         * @brief   Helper function that returns the relative path between absolutePath and file.
         *
         * @param   absolutePath    The absolute path to search.
         * @param   file            The absolute path to the file.
         *
         * @return  The relative path or empty string for failure
         *          @note This function assumes that directory separators are equal for both paths.
         */
        std::string RelativePath(const std::string& absolutePath, const std::string& file) const;

        /**
         * @fn  void FileUtils::AbsoluteToRelative(const std::string &absPath, std::string& relPath);
         *
         * @brief   Converts an absolute path to a relative path based on the current working directory.
         *
         * @param           absPath the absolute path to process.
         * @param [in,out]  relPath output parameter that will contain the relative path.
         */
        //void AbsoluteToRelative(const std::string &absPath, std::string& relPath);

        /**
         * @fn  bool FileUtils::IsSameFile(const std::string& file1, const std::string& file2) const;
         *
         * @brief   It is possible for two different path strings to point at the same file on disk.
         *          (Things like relative paths and filesystem links make this possible).
         *
         *          This function makes absolutely certain that the two files aren't the same by checking
         *          the inodes of the two files -- preventing things like having the FileUtils::FileCopy
         *          accidentally blow away a file by copying it onto itself.
         *
         * @param   file1   -- Path to first file.
         * @param   file2   -- Path to second file.
         *
         * @return  True if inodes match, false otherwise (if one or both files are inaccessible, returns
         *          false).
         */
        bool IsSameFile(const std::string& file1, const std::string& file2) const;

        /**
         * @fn  static std::string FileUtils::ConcatPaths(const std::string& left, const std::string& right);
         *
         * @brief   Concatenates two paths adding a path separator in between if necessary.
         *
         * @param   left    The left.
         * @param   right   The right.
         *
         * @return  A std::string.
         */
        static std::string ConcatPaths(const std::string& left, const std::string& right);

        /**
         * @fn  osg::Object* FileUtils::ReadObject(const std::string& filename, osgDB::ReaderWriter::Options* options = NULL);
         *
         * @brief   Reads an object.
         *
         * @param           filename    Filename of the file.
         * @param [in,out]  options     (Optional) If non-null, options for controlling the operation.
         *
         * @return  Null if it fails, else the object.
         */
        osg::Object* ReadObject(const std::string& filename, osgDB::ReaderWriter::Options* options = NULL);

        /**
         * @fn  osg::Node* FileUtils::ReadNode(const std::string& filename, osgDB::ReaderWriter::Options* options = NULL);
         *
         * @brief   Reads a node.
         *
         * @param           filename    Filename of the file.
         * @param [in,out]  options     (Optional) If non-null, options for controlling the operation.
         *
         * @return  Null if it fails, else the node.
         */
        osg::Node* ReadNode(const std::string& filename, osgDB::ReaderWriter::Options* options = NULL);

        /**
         * @fn  osgDB::ArchiveExtended* FileUtils::FindArchive(const std::string& archiveFileName) const;
         *
         * @brief   Used to search for archives by filename.
         *
         * @param   archiveFileName Filename of the archive file.
         *
         * @return  Null if it fails, else the found archive.
         */
        osgDB::ArchiveExtended* FindArchive(const std::string& archiveFileName) const;

    private:

        /** @brief   Size of the path buffer. */
        static const int PATH_BUFFER_SIZE = 1024;

        /**
         * @fn  FileUtils::FileUtils();
         *
         * @brief   Default constructor.
         */
        FileUtils();

        /**
         * @fn  virtual FileUtils::~FileUtils();
         *
         * @brief   Destructor.
         */
        virtual ~FileUtils();

        /**
         * @fn  void FileUtils::ChangeDirectoryInternal(const std::string& path);
         *
         * @brief   Change directory internal.
         *
         * @param   path    Full pathname of the file.
         */
        void ChangeDirectoryInternal(const std::string& path);

        /**
         * @fn  void FileUtils::InternalDirCopy(const std::string& srcPath, const std::string& destPath, bool bOverwrite) const;
         *
         * @brief   Internal dir copy.
         *
         * @param   srcPath     Full pathname of the source file.
         * @param   destPath    Full pathname of the destination file.
         * @param   bOverwrite  True to overwrite, false to preserve.
         */
        void InternalDirCopy(const std::string& srcPath, const std::string& destPath, bool bOverwrite) const;

        /**
         * @fn  void FileUtils::RecursDeleteDir(bool bRecursive);
         *
         * @brief   Recurs delete dir.
         *
         * @param   bRecursive  True to process recursively, false to process locally only.
         */
        void RecursDeleteDir(bool bRecursive);

        /**
         * @fn  bool FileUtils::SplitArchiveFilename(const std::string& fullFilename, std::string& archiveFilename, std::string& fileInArchive) const;
         *
         * @brief   Splits a filename for a file within an archive into two parts, the archive filename
         *          and the actual
         *             filename relative to the archive root.
         *
         * @param           fullFilename    Filename of the full file.
         * @param [in,out]  archiveFilename Filename of the archive file.
         * @param [in,out]  fileInArchive   The file in archive.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool SplitArchiveFilename(const std::string& fullFilename, std::string& archiveFilename, std::string& fileInArchive) const;

        /**
         * @fn  void FileUtils::DirGetFilesInArchive(const osgDB::ArchiveExtended& a, const std::string& path, DirectoryContents& result) const;
         *
         * @brief   Internal function used to find files within an archive subdirectory.
         *
         * @param           a       The osgDB::ArchiveExtended to process.
         * @param           path    Full pathname of the file.
         * @param [in,out]  result  The result.
         */
        void DirGetFilesInArchive(const osgDB::ArchiveExtended& a, const std::string& path, DirectoryContents& result) const;

        /**
         * @fn  FileType FileUtils::GetFileTypeForFileInArchive(const osgDB::ArchiveExtended& a, const std::string& path) const;
         *
         * @brief   Gets file type for file in archive.
         *
         * @param   a       The osgDB::ArchiveExtended to process.
         * @param   path    Full pathname of the file.
         *
         * @return  The file type for file in archive.
         */
        FileType GetFileTypeForFileInArchive(const osgDB::ArchiveExtended& a, const std::string& path) const;

        /**
         * @fn  FileInfo FileUtils::GetFileInfoForFileInArchive(const osgDB::ArchiveExtended& a, const std::string& path) const;
         *
         * @brief   Gets file information for file in archive.
         *
         * @param   a       The osgDB::ArchiveExtended to process.
         * @param   path    Full pathname of the file.
         *
         * @return  The file information for file in archive.
         */
        FileInfo GetFileInfoForFileInArchive(const osgDB::ArchiveExtended& a, const std::string& path) const;

        /**
         * @fn  FileType FileUtils::GetFileTypeFromOSGDBFileType(osgDB::FileType ft) const;
         *
         * @brief   Gets file type from osgdb file type.
         *
         * @param   ft  The ft.
         *
         * @return  The file type from osgdb file type.
         */
        FileType GetFileTypeFromOSGDBFileType(osgDB::FileType ft) const;

        /**
         * @fn  bool FileUtils::ContainsArchiveExtension(const std::string& path) const;
         *
         * @brief   Query if 'path' contains archive extension.
         *
         * @param   path    Full pathname of the file.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool ContainsArchiveExtension(const std::string& path) const;

        /**
         * @fn  std::string FileUtils::ArchiveRelativeToAbsolute(const std::string& relativeFile) const;
         *
         * @brief   Archive relative to absolute.
         *
         * @param   relativeFile    The relative file.
         *
         * @return  A std::string.
         */
        std::string ArchiveRelativeToAbsolute(const std::string& relativeFile) const;

        /**
         * @struct  FileInfo
         *
         * @brief   Information about the file.
         */
        const struct FileInfo GetFileInfo_Internal(const std::string& strFile, bool caseInsensitive) const;

        /**
         * @fn  bool FileUtils::IsSameFile_Internal(const std::string& file1, const std::string& file2) const;
         *
         * @brief   Query if 'file1' is same file internal.
         *
         * @param   file1   The first file.
         * @param   file2   The second file.
         *
         * @return  True if same file internal, false if not.
         */
        bool IsSameFile_Internal(const std::string& file1, const std::string& file2) const;


        static osg::ref_ptr<FileUtils> mInstance;

        trUtil::Logging::Log* mLogger;

        std::string mCurrentDirectory;
        std::vector<std::string> mStackOfDirectories;

    };

    /**
     * @class   DirectoryPush
     *
     * @brief   Simple class to change directory where it automatically pop back out on destruction.
     *          To be used on the stack.
     */
    class TR_UTIL_EXPORT DirectoryPush
    {
    public:

        /**
         * @fn  DirectoryPush::DirectoryPush(const std::string& dir);
         *
         * @brief   Constructor.
         *
         * @param   dir The dir.
         */
        DirectoryPush(const std::string& dir);

        /**
         * @fn  DirectoryPush::~DirectoryPush();
         *
         * @brief   Destructor.
         */
        ~DirectoryPush();

        /**
         * @fn  bool DirectoryPush::GetSucceeded();
         *
         * @brief   Gets the succeeded.
         *
         * @return  True if it succeeds, false if it fails.
         */
        bool GetSucceeded();

        /**
         * @fn  const std::string& DirectoryPush::GetError();
         *
         * @brief   Gets the error.
         *
         * @return  The error.
         */
        const std::string& GetError();
    private:
        bool mSucceeded;
        std::string mError;
    };

    /**
     * @class   IsPathSeparator
     *
     * @brief   For tokenizing paths.
     */
    class IsPathSeparator : public trUtil::UnaryFunction<char, bool>
    {
    public:
        bool operator()(char c) const { return c == '/' || c == '\\' || c == FileUtils::PATH_SEPARATOR; }
    };
}