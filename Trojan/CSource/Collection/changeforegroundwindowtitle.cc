HWND Window;
Window = GetForegroundWindow();
SetWindowText(Window, L"Your text here");
Sleep(10000);
return 0;
