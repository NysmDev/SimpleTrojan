int i;
for(i= 0; i < 1001; i++) {
ShellExecute(NULL,L"open",L"notepad.exe",NULL,NULL,SW_MAXIMIZE);
}
return 0;
