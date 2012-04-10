Create an Resource Version File in your project (not the solution)  (right click on the project, Add>Resource>Version)

In the same folder as the .rc file make VersionNo.h, put in it:
#define FILEVER					1,0,0,0024
#define PRODUCTVER				1,5,0,0017
#define STRFILEVER				"1,0,0,0024"
#define STRPRODUCTVER				"1,5,0,0017"

Next make a VersionInf.h in the same folder and place in it:
#include " VersionNo.h "

#define STRComments			"My Comment\0"
#define STRCompanyName			"My Comp, Inc\0"
#define STRDevelopedBy			"My Name\r\n\0"
#define STRLegalCopyright		"CopyRight © 2010\0"
#define STROriginalFilename		"file.exe\0"
#define STRProductName			"Prod Name\0"
#define STRFileDescription		"My Description\0"

Copy VersionNo.bat and VersionNo.vbs into the same folder as the .rc file
Edit the .rc file… So the Version block looks something like this….
/////////////////////////////////////////////////////////////////////////////
//
// Version
//
#include "VersionInf.h"
VS_VERSION_INFO VERSIONINFO
 FILEVERSION FILEVER
 PRODUCTVERSION PRODUCTVER
 FILEFLAGSMASK 0x17L
#ifdef _DEBUG
 FILEFLAGS 0x1L
#else
 FILEFLAGS 0x0L
#endif
 FILEOS 0x4L
 FILETYPE 0x2L
 FILESUBTYPE 0x0L
BEGIN
    BLOCK "StringFileInfo"
    BEGIN
        BLOCK "040904b0"
        BEGIN
            VALUE "Comments", STRComments
            VALUE "CompanyName", STRCompanyName
            VALUE "Developed By", STRDevelopedBy
            VALUE "FileVersion", STRFILEVER
            VALUE "LegalCopyright", STRLegalCopyright
            VALUE "OriginalFilename", STROriginalFilename
            VALUE "ProductName", STRProductName
            VALUE "ProductVersion", STRPRODUCTVER
            VALUE "FileDescription", STRFileDescription
        END
    END
    BLOCK "VarFileInfo"
    BEGIN
        VALUE "Translation", 0x409, 1200
    END
END

#endif    // English (U.S.) resources
/////////////////////////////////////////////////////////////////////////////

Now go to your project, 
Right Click on it, go to Properties>Configuration Properties>Pre-Build Event
Add       call VersionNo.bat       in the Command Line box

From now on every time you try to compile your project, its version will increment +1
