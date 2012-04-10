Option Explicit

Dim FileName, FS, FileStream, args
Dim Line1, Line2, Line3, Line4


'Get file name from command line
set args = WScript.Arguments
FileName = args.Item(0)

'Read text file
Set FS = CreateObject("Scripting.FileSystemObject")
Set FileStream = FS.OpenTextFile(FileName)
Line1 = FileStream.ReadLine
Line2 = FileStream.ReadLine
Line3 = FileStream.ReadLine
Line4 = FileStream.ReadLine
FileStream.Close

'Increment the versions
Call Increment(Line1, 4, 0)
Call Increment(Line2, 4, 0)
Call Increment(Line3, 4, 1)
Call Increment(Line4, 4, 1)


'Write the file back
Set FileStream = FS.OpenTextFile(FileName, 2, False)
FileStream.WriteLine(Line1)
FileStream.WriteLine(Line2)
FileStream.WriteLine(Line3)
FileStream.WriteLine(Line4)
FileStream.Close


'**********************************************************
'LineStr	- the string to look at
'ChNum		- number of numeric values on the end to look at
'Opt		- does the string have a " on the end. 1 for true 0 for false

Function Increment(LineStr, ChNum, Opt)
Dim Num
If Opt=0 Then
	Num = Right(LineStr,ChNum)
	LineStr = Left(LineStr,Len(LineStr)-ChNum)
	Num = Num + 1

	Do While Len(Num) < ChNum
		Num = "0" & Num
	Loop

	LineStr = LineStr & Num
Else
	Num = Right(LineStr,ChNum+1)
	Num = Left(Num, ChNum)
	LineStr = Left(LineStr,Len(LineStr)-(ChNum+1))
	Num = Num + 1

	Do While Len(Num) < ChNum
		Num = "0" & Num
	Loop

	LineStr = LineStr & Num & Chr(34)

End If
End Function
