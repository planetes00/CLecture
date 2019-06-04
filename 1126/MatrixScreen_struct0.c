#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Console.h"

#define MAX_COLUMN 256

struct Bar {
	int y;				// y coordinates for each column
	int delay;			// inverse of speed of each column
	int length;			// length of each column
	int prevLength;		// length of each column in the previous turn
};

char GetRandomChar();		// a function that returns a random alpha-numeric character
void MoveBar(struct Bar *pBar);

int main()
{
/*
	int y[MAX_COLUMN];				// y coordinates for each column
	int delay[MAX_COLUMN];			// inverse of speed of each column
	int length[MAX_COLUMN];			// length of each column
	int prevLength[MAX_COLUMN];		// length of each column in the previous turn
*/
	struct Bar bar[MAX_COLUMN];

	int t = 0;						// master clock
	int screenWidth = getWindowWidth();
	int screenHeight = getWindowHeight() - 2;
	int col = 0;

	srand(time(NULL));

	clrscr();

	printf("Screen size = %d x %d.\n", screenWidth, screenHeight);
	printf("If you want to finish, press ESC.\n");
	printf("Press enter to start :");
	getchar();

	clrscr();

	// initialize each screenWidths
	for(col = 0; col < screenWidth; col++){
		bar[col].y = 1;
		bar[col].delay = rand() % 10 + 1;	// initialize delay and length
		bar[col].length = rand() % 5 + 3;
		bar[col].prevLength = length[col];
	}

	while(1){
		if(kbhit() && _getch() == 27)	// if ESC is pressed, terminate the loop
			break;

		for(col = 0; col < screenWidth; col++){
			if(t % bar[col].delay == 0){
				MoveBar(&bar[col]);
/*
// TO DO: Move this part to MoveBar() below and adjust appropriately

				// print a random character at current position
				gotoxy(col + 1, y[col]);
				putchar(GetRandomChar());

				// erase previous location
				if(y[col] - length[col] >= 1){
					gotoxy(col + 1, y[col] - length[col]);
					putchar(' ');
				}
				
				if(y[col] <= prevLength[col]){
					gotoxy(col + 1, screenHeight + y[col] - prevLength[col]);	// wrapped
					putchar(' ');
				}

				// increase current y coordinate
				y[col]++;

				// check if y reached the last screenHeight
				if(y[col] > screenHeight){
					y[col] = 1;
					delay[col] = rand() % 10 + 1;	// reset delay and length
					
					prevLength[col] = length[col];
					length[col] = rand() % 5 + 3;
				}
*/
			}
		}
		
		MySleep(50);
		t++;				// increase master clock
	}

	clrscr();

	gotoxy(1, 1);
	printf("Good bye!\n");

    MyPause();

	return 0;	
}

char GetRandomChar()
{
	const int noUpperCase = 26;
	const int noLowerCase = 26;
	const int noDigits = 10;

	int x = rand() % (noUpperCase + noLowerCase + noDigits);
	if(x < noUpperCase)
		return 'A' + x;
	else if(x < noUpperCase + noLowerCase)
		return 'a' + x - noUpperCase;
	else
		return '0' + x - (noUpperCase + noLowerCase);
}

void MoveBar(struct Bar *pBar)
{
}
	
