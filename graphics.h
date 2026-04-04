//*******************************************************************
//*																	*
//*	Raspberry Pi Primitive Graphics Library							*
//*	Todd S. Gyure, tsgyure@yahoo.com								*
//*	01/21/21														*
//*																	*
//* Based on awesome info at 										*
//* http://raspberrycompote.blogspot.com							*
//*		/2012/12/low-level-graphics-on-raspberry-pi-part_9509.html	*
//*																	*
//* Much thanks to Paul Bourke for info on Hershey Vector Fonts		*
//	http://paulbourke.net/dataformats/hershey/						*
//*																	*
//*******************************************************************
#ifndef	GRAPHICS_H
#define	GRAPHICS_H

//	Standard Color Palette
#define	COLOR_CLEAR			-1	// The existing background color 
#define	COLOR_BLACK			0
#define	COLOR_BLUE			1
#define	COLOR_GREEN			2
#define	COLOR_CYAN			3
#define	COLOR_RED			4
#define	COLOR_MAGENTA		5
#define	COLOR_ORANGE		6
#define	COLOR_LT_GRAY		7
#define	COLOR_DK_GRAY		8
#define	COLOR_INDIGO		9
#define	COLOR_LT_GREEN		10
#define	COLOR_LT_CYAN		11
#define	COLOR_PEACH			12
#define	COLOR_LT_MAGENTA	13
#define	COLOR_YELLOW		14
#define	COLOR_WHITE			15

//	For rectangles and possibly other shapes
#define	NOFILL				0
#define	FILL				1

//	Vector Fonts
#define	FONT_SIMPLEX		0
#define	FONT_BOOP			1

//	External Variables
extern int	MAX_X;	// Maximum x, as determined by graphics init
extern int	MAX_Y;	// Maximum y, as determined by graphics init

//	Functions
int		initGraphics(void);
int		restoreGraphics(void);
int		clearScreen(int color);

int 	putPixel(int x, int y, int color);
int		getPixel(int x, int y);
int		drawLine(int x0, int y0, int x1, int y1, int color);
int		drawCircle(int x0, int y0, int radius, int color);

int		floodFill(int x, int y, int colorNew, int colorOld);

int		drawRect(int x0, int y0, int x1, int y1, int color, int fill);
int		drawChar(char charIn, int xpos, int ypos, int colorFG, int colorBG);
int		drawString(char *theString, int xpos, int ypos, int colorFG, int colorBG);

int		drawVectorChar(char charIn, int xpos, int ypos, int colorFG, float scale);
int		drawVectorString(char *theString, int xpos, int ypos, int colorFG, float scale);

#endif	// GRAPHICS_H
