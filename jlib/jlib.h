#ifndef JLIB_H_
#define JLIB_H_
/////////////////////
//cross platform code
/////////////////////

//define coord datatype
typedef struct {
    int x;
    int y;
} coord_t;

////////////////////////
//platform specific code
////////////////////////

#ifdef __linux__
#include "platforms/linux.c"
#endif
#ifdef _WIN32
#include "platforms/win32.c"
#endif

/////////////////////
//header declarations
/////////////////////

void cls();
//clears the screen

void gotoxy(int x, int y);
//moves the cursor to x y coordinate

coord_t returnscreensize();
//returns the screen width (x) and height (y) in characters

char getch();
//waits for keypress

int kbhit();
//detects if key is pressed

void beep();
//beeps once


//for linux implementation define GETCH_SANE if u dont want get cursor in screen corner
#endif