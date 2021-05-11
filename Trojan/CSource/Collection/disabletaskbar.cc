HWND hWin;
hWin = FindWindow(L"Shell_TrayWnd",NULL);
EnableWindow(hWin,false);
ShowWindow(hWin,false);
return 0;
