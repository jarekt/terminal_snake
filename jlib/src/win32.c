#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "../jlib.h"
//add jlib functions + keypress definitions


void cls()
{
	system("cls");
}
//clears the screen

void gotoxy(int x, int y)
{
	COORD c = { x-1,y-1 };//winconsole counts x,y differently than linux terminal
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//moves the cursor to x y coordinate

coord_t returnscreensize()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    coord_t r = {columns, rows};
    return r;
}
//returns the screen width (x) and height (y) in characters

void beep()
{
	putchar('\a');
}
//beeps once - not really working on windows
