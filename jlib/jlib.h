#ifndef JLIB_H_
#define JLIB_H_

//define coord datatype
typedef struct {
    int x;
    int y;
} coord_t;

void cls();
//clears the screen

void gotoxy(int x, int y);
//moves the cursor to x y coordinate

coord_t returnscreensize();
//returns the screen width (x) and height (y) in characters

int getch();
//waits for keypress

int kbhit();
//detects if key is pressed

void beep();
//beeps once


//GETCH_SANE removed - it's more readable to just goto(0,0)
#endif