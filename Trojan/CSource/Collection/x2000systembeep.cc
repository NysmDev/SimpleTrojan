int Freq, Dur, i;
for(i= 0; i < 2001; i++) {
    Freq = rand()%2001;
    Dur = rand()%501;
    Beep(Freq, Dur);
}
return 0;
