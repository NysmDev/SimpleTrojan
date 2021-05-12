# SimpleTrojan
This is made for educational purposes, I am not responsible for you acts. How to inject a Trojan Virus into a victim's computer !

### Information

Hello everyone, I decided today to stop my C# project to make this one, a simple Trojan Virus. The trojan downloads 3 textfiles each 5 seconds, the textfiles contain a number, and based on that number it executes commands.

Before we start with the C++ code, I have a very easy way to get the trojan on the victim's computer. You just need a U3-enabled USB drive, USB access to the victim's computer, and the Universal Customizer. Delete the U3CUSTOM.ISO and create your own U3CUSTOM.ISO with these files included. (the files will be in the repository)

### Second Step

Then, create a folder "trojan", and we'll later put the trojan files in there. You also need to create a file "Trojan.lnk", it will be copied to the startup folder. Also place all the neccessary DLL's in there for the program to run, for example urlmon.dll and wininet.dll. 

Then create an ISO and run the U3 Updater to put the trojan on your U3 drive. Now it will automatically run go.vbs without any notice once you plug in your U3 drive in any Windows XP computer (It will not work on Vista or 7, they have autorun disabled).

And also, before we start creating our program itself, we need a way to control it. As I said, the trojan downloads 3 files. Let's make these files on our web site/server. Create index.html, assign.html and target.html and don't put anything in there. Then we create a PHP file (edit.php) that is able to edit the html files. Why just PHP and not some normal application? Because this way we can control the trojan from anywhere by just going to yourwebsitehere.com/trojan/edit.php. You can even control computers with your mobile phone if you have mobile internet or Wifi.


Now we start with creating our winrat.exe, the trojan itself. Source code in repository.

That's our trojan. But it doesn't have any commands. You can do anything you want now. Run an FTP server in the background (I recommend SlimFTPd), open websites or applications, play a sound, open your CD drive, etc.

# SlimFTPd Server

### Download :

https://slimftpd.soft112.com/

**Please Note that I am not responsible for malwares that enters your computer or if you use the Trojan Horse Virus as a threat.**
