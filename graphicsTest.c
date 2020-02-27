//*******************************************************************
//*																	*
//*	Testing Raspberry Pi Primitive Graphics Library					*
//*	02/15/20														*
//*																	*
//*******************************************************************

#include	<stdio.h>
#include	<unistd.h>	// Used for Linux sleep
#include	<stdlib.h>	// Used for random
#include	<time.h>	// Used for random

#include	"graphics.h"

int main(int arc, char *argv[])
{
	printf("START of Raspberry Pi Graphics Library test.\n");
	
	// Seed for random numbers
	srandom((unsigned)time(NULL));

	// Initialize graphics mode
	if(initGraphics())
	{
		printf("***** Graphics initialize failed.\n");
		return(1);
	}

	// Now do some graphics stuff!
	
	// Draw some color bars
	for(int i = 0; i <= 15; i++)
	{
		drawRect(i * 80, 50, i * 80 + 79, 720, i, 1);
	}
	
	// Some raster text
	drawString("TINY 5 x 7 PIXEL TEXT - transparent background", 10, 100, COLOR_YELLOW, COLOR_CLEAR);

	// Some vector text
	drawVectorString("Text in vector Hershey Font", 800, 100, COLOR_BLACK);
	sleep(5);

	// Some lines
	drawLine(500, 300, 501, 301, COLOR_WHITE);
	for(int i = 0; i <= 10; i++)
	{
		drawLine(-1, -1, rand() % 1300 + 10, rand() % 750 + 10, rand() % 16);
		sleep(1);
	}

	for(int i = 0; i <= 5000; i++)
	{
		drawLine(-1, -1, rand() % 1300 + 10, rand() % 750 + 10, rand() % 16);
	}

	sleep(1);
	
	clearScreen(COLOR_WHITE);
	
	// Circles
	for(int i = 0; i <= 10; i++)
	{
		drawCircle(rand() % 1000 + 100, rand() % 300 + 100, rand() % 80 + 10, rand() % 16);
		sleep(1);
	}

	for(int i = 0; i <= 5000; i++)
	{
		drawCircle(rand() % 1000 + 100, rand() % 300 + 100, rand() % 80 + 10, rand() % 16);
	}

	sleep(1);

	clearScreen(COLOR_WHITE);
	drawVectorString("Now, random pixels, random colors, almost EVERYWHERE!", 25, 720, COLOR_BLACK);

	for(int bela = 65535; bela != 0; bela--)
	{
		for(int count = 512; count != 0; count--)
		{
			putPixel(rand() % 1357, rand() % 680, rand() % 16);
		}
	}
	// Restore from graphics mode
	if(restoreGraphics())
	{
		printf("***** Graphics restore failed.\n");
		return(1);
	}

	printf("END of Raspberry Pi Graphics Library test.\n");
	return(0);
}
