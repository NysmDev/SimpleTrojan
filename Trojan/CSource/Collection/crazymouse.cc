int i,x,y;
for(i= 0; i < 201; i++) {
    x = rand()%1001;
    y = rand()%801;
    SetCursorPos(x,y);
    Sleep(200);
}
return 0;
