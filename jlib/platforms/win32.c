#include <conio.h>
#include <windows.h>
//add jlib functions + keypress definitions

coord_t returnscreensize()
{
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    coord_t r = {columns, rows};
    return r;
}
//returns the screen width (x) and height (y) in characters
