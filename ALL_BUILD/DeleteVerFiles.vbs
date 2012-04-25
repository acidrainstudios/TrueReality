Option Explicit

Dim fso, Folder, SubFolder, f1

Set fso = CreateObject("Scripting.FileSystemObject")

Set Folder = fso.GetFolder("..\vrsVersionCTR")

Set SubFolder = Folder.subFolders

For Each f1 in SubFolder 
 f1.delete
Next