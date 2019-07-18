#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include "../jlib.h"


void cls()
{
    putchar('\n');
    system("clear");
};
//clears the screen

void gotoxy(int x, int y)
{
    printf("%c[%d;%df",0x1B,y,x);
};
//moves the cursor to x y coordinate

coord_t returnscreensize()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    coord_t r = {w.ws_col, w.ws_row};
    return r;
};
//returns the screen width (x) and height (y) in characters

int getch()
{
    int c;
    system("stty raw");
    c = getchar();
    system("stty sane");
    return c;
};
//waits for keypress

int kbhit()
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
    ungetc(ch, stdin);
    return 1;
    }
    return 0;
};
//detects if key is pressed

void beep()
{
    putchar(0x07);
};
//beeps once