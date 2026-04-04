//*******************************************************************
//*																	*
//*	DEMO Raspberry Pi Primitive Graphics Library					*
//*	11/21/20														*
//*																	*
//*******************************************************************

#include	<stdio.h>
#include	<unistd.h>	// Used for Linux sleep
#include	<stdlib.h>	// Used for random
#include	<time.h>	// Used for random
#include	<math.h>

#include	"graphics.h"

int		randInt(int low, int high);

double	deg2rad(double degreesIn);

int main(int arc, char *argv[])
{
	int		i, x, y;
	float	f;
	double	angle;
	char	displayBuffer[25];
	char	*ptrDisplayBuffer;
	
	printf("START of Raspberry Pi Graphics Library Demo.\n");
	
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
	for(i = 0; i <= 15; i++)
	{
		drawRect(i * MAX_X / 16, 0, i * MAX_X / 16 + MAX_X / 16, MAX_Y, i, FILL);
	}

	// Some raster text
	drawString("TINY 5 x 7 PIXEL TEXT - transparent background", MAX_X / 2 - 46 * 5, MAX_Y / 2, COLOR_BLACK, COLOR_CLEAR);

	sleep(5);
	clearScreen(COLOR_BLACK);

	// Some vector text
	drawVectorString("Vector text in Hershey Font", 10, MAX_Y / 2, COLOR_INDIGO, 1.0);
	sleep(1);
	drawVectorString("Vector text in Hershey Font", 10, MAX_Y / 2, COLOR_BLACK, 1.0);
	
	// Scale the vector text
	ptrDisplayBuffer = displayBuffer;
	for(f = 0.01; f < 12.0; f = f + 0.1)
	{
		sprintf(ptrDisplayBuffer, "Scale: %5.2f", f);
		drawVectorString(ptrDisplayBuffer, 20, MAX_Y - 50, COLOR_RED, 1.0);

		drawVectorString("Scaling...", 20, MAX_Y / 2, COLOR_GREEN, f);
		usleep(2000);
		drawVectorString(ptrDisplayBuffer, 20, MAX_Y - 50, COLOR_BLACK, 1.0);
		drawVectorString("Scaling...", 20, MAX_Y / 2, COLOR_BLACK, f);
	}
	sprintf(ptrDisplayBuffer, "Scale: %5.2f", f);
	drawVectorString(ptrDisplayBuffer, 20, MAX_Y - 50, COLOR_RED, 1.0);
	drawVectorString("Scaling...", 20, MAX_Y / 2, COLOR_GREEN, f);
	sleep(5);

	// Some lines
	drawLine(randInt(0, MAX_X), randInt(0, MAX_Y), randInt(0, MAX_X), randInt(0, MAX_Y), COLOR_WHITE);
	for(int i = 0; i <= 10; i++)
	{
		drawLine(-1, -1, randInt(0, MAX_X), randInt(0, MAX_Y), randInt(1, 15));
		sleep(1);
	}

	for(int i = 0; i <= 5000; i++)
	{
		drawLine(-1, -1, randInt(0, MAX_X), randInt(0, MAX_Y), randInt(1, 15));
	}

	sleep(5);
	
	clearScreen(COLOR_WHITE);
	
	// Circles
	int	radius, colorNew;
	for(i = 0; i <= 10; i++)
	{
		radius = randInt(1, MAX_Y /2 - 2);
		x = randInt(radius + 2, MAX_X - radius - 2);
		y = randInt(radius + 2, MAX_Y - radius - 2);
		colorNew = randInt(1, 15);
		drawCircle(x, y, radius, colorNew);
		sleep(1);
	}

	clearScreen(COLOR_BLACK);
	for(i = 0; i <= 10; i++)
	{
		radius = randInt(1, 200);
		x = randInt(radius + 2, MAX_X - radius - 2);
		y = randInt(radius + 2, MAX_Y - radius - 2);
		colorNew = randInt(1, 15);
		drawCircle(x, y, radius, colorNew);
		floodFill(x, y, colorNew, getPixel(x, y));
	}
	sleep(5);

	clearScreen(COLOR_BLACK);
	drawVectorString("Trig Function Funtime!", 20, MAX_Y - 100, COLOR_MAGENTA, 1.0);
	
	for(double freq = 1.0; freq < 5.0; freq+=0.1)
	{
		// Draw wave
		drawLine(-1, -1, 0, MAX_Y / 2.5 * sin((double)(0) / (double)MAX_X * 2.0 * M_PI * freq) + MAX_Y / 2, COLOR_BLACK);
		for(i = 0; i < MAX_X; i++)
		{
			drawLine(-1, -1, i, MAX_Y / 2.5 * sin((double)(i) / (double)MAX_X * 2.0 * M_PI * freq) + MAX_Y / 2, COLOR_GREEN);
		}
		usleep(50000);

		// Undraw wave
		drawLine(-1, -1, 0, MAX_Y / 2.5 * sin((double)(0) / (double)MAX_X * 2.0 * M_PI * freq) + MAX_Y / 2, COLOR_BLACK);
		for(i = 0; i < MAX_X; i++)
		{
			drawLine(-1, -1, i, MAX_Y / 2.5 * sin((double)(i) / (double)MAX_X * 2.0 * M_PI * freq) + MAX_Y / 2, COLOR_BLACK);
		}
	}

	clearScreen(COLOR_BLACK);
	#define	xAmp	((double)MAX_X / 2.0 - 2.0)
	#define yAmp	((double)MAX_Y / 2.0 - 2.0)
	#define xOff	(double)MAX_X / 2.0
	#define yOff	(double)MAX_Y / 2.0
	
	for(double inc = 0.01; inc < M_PI; inc+=0.01)
	{
		drawLine(xAmp + xOff, yOff, xAmp + xOff, yOff, COLOR_BLACK);
		for(angle = 0.0; angle < 2.0 * M_PI; angle+=inc)
		{
			 x =  xAmp * cos(angle) + xOff;
			 y =  yAmp * sin(angle) + yOff;
			 drawLine(-1, -1, x, y, COLOR_INDIGO);
		}
		usleep(100000);
	}	 

	for(int a = 0; a < 2; a++)
	{
		// Random schpeckles..
		for(int bela = 65535; bela != 0; bela--)
		{
			for(int count = 512; count != 0; count--)
			{
				putPixel(randInt(0, MAX_X), randInt(0, MAX_Y), randInt(1, 15));
			}
			if(randInt(0, 10000) == 5000)
			{
				for(i = 0; i <= 10; i++)
				{
					drawRect(randInt(0, MAX_X), randInt(0, MAX_Y), randInt(0, MAX_X), randInt(0, MAX_Y), randInt(1, 15), FILL);
				}
			}
		}
	}
	// Restore from graphics mode
	if(restoreGraphics())
	{
		printf("***** Graphics restore failed.\n");
		return(1);
	}

	printf("END of Raspberry Pi Graphics Library Demo.\n");
	return(0);
}

// randomNum = rand() % (High - Low + 1) + Low
int		randInt(int low, int high)
{
	return(rand() % (high - low + 1) + low);
}

double	deg2rad(double degreesIn)
{
	return(degreesIn * M_PI / 180.0);
}
