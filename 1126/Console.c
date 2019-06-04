/*
	Console.c: console-related functions
		This file is for Windows
*/



#include <stdio.h>
#include <stdlib.h>


#ifdef _WINDOWS
////////////////////////////////////////////////////////////////////////////////
// for Windows


#include <windows.h>

#include "Console.h"

void clrscr(void)		// clear the screen
{
	COORD Cur= {0, 0};
	unsigned long dwLen = 0;

	int width = getWindowWidth();
	int height = getWindowHeight();
	int size = width * height;

	gotoxy(1, 1);
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', size, Cur, &dwLen);
//	gotoxy(1, 1);
}

void gotoxy(int x, int y)	// move cursor to (x, y)
{
	COORD Pos = { (short)(x - 1), (short)(y - 1)};

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int getWindowWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &csbi);

    return (int)(csbi.srWindow.Right - csbi.srWindow.Left + 1);
}

int getWindowHeight()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &csbi);

    return (int)(csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
}

void EnableCursor(int enable)
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = enable;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void MySleep(int msec)
{
	Sleep(msec);
}

void MyPause()
{
	system("PAUSE");
}

#endif	// _WINDOWS


#if defined(_LINUX) || defined(_MAC)
////////////////////////////////////////////////////////////////////////////////
// for Mac or Linux


#include <unistd.h>
#include <sys/ioctl.h>

#include <termios.h>

#include "Console.h"

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

void clrscr()
{
	fprintf(stdout, "\033[2J\033[0;0f");
	fflush(stdout);
}

int getWindowWidth()
{
	struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	return w.ws_col;
}

int getWindowHeight()
{
	struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	return w.ws_row;
}


static struct termios oldTerm, newTerm;

/* Initialize newTerm terminal i/o settings */
void initTermios(int echo)
{
  tcgetattr(0, &oldTerm); /* grab oldTerm terminal i/o settings */
  newTerm = oldTerm; /* make newTerm settings same as oldTerm settings */
  newTerm.c_lflag &= ~ICANON; /* disable buffered i/o */
  newTerm.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &newTerm); /* use these newTerm terminal i/o settings now */
}

/* Restore oldTerm terminal i/o settings */
void resetTermios(void)
{
  tcsetattr(0, TCSANOW, &oldTerm);
}

/* Read 1 character - echo defines echo mode */
int getch_(int echo)
{
  char ch = 0;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
int _getch(void)
{
  return getch_(0);
}

/* Read 1 character with echo */
int _getche(void)
{
  return getch_(1);
}

int __getch()
{
    int ch = 0;
    struct termios buf, save;
    tcgetattr(0,&save);
    buf = save;
    buf.c_lflag &= ~(ICANON|ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}

void MySleep(int msec)
{
	usleep(msec * 1000);
}

void MyPause()
{
	printf("Press Enter to continue...");
	getchar();
}

int kbhit()
{
	struct termios term;
    tcgetattr(0, &term);

    struct termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting = 0;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return (byteswaiting > 0) ? 1 : 0;
}

#endif 	// defined(_LINUX) || defined(_MAC)


////////////////////////////////////////////////////////////////////////////////
// Common functions for all platforms

void DrawLine(int x1, int y1, int x2, int y2, char c)
{
	int dx = 0, dy = 0;
	int x = 0, y = 0;

	if(abs(x2 - x1) > abs(y2 - y1)){
		if(x1 > x2){
			swap(&x1, &x2);
			swap(&y1, &y2);
		}
	} else if(y1 > y2){
		swap(&x1, &x2);
		swap(&y1, &y2);
	}

	dx = x2 - x1;
	dy = y2 - y1;

	if(dx >= dy){
		if(dx == 0){
			gotoxy(x1, y1);
			printf("%c", c);
		} else {
			for(x = x1; x <= x2; x++){
				y = (y1 * (x2 - x) + y2 * (x - x1) + dx / 2) / dx;
				gotoxy(x, y);
				printf("%c", c);
			}
		}
	} else {
		for(y = y1; y <= y2; y++){
			x = (x1 * (y2 - y) + x2 * (y - y1) + dy / 2) / dy;
			gotoxy(x, y);
			printf("%c", c);
		}
	}
}

void swap(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}
