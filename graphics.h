//*******************************************************************
//*																	*
//*	Raspberry Pi Primitive Graphics Library							*
//*	Todd S. Gyure, tsgyure@yahoo.com								*
//*	02/15/20														*
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

#define	COLOR_CLEAR			-1	// The existing background color 
#define	COLOR_BLACK			0
#define	COLOR_BLUE			1
#define	COLOR_GREEN			2
#define	COLOR_CYAN			3
#define	COLOR_RED			4
#define	COLOR_MAGENTA		5
#define	COLOR_BROWN			6
#define	COLOR_LT_GRAY		7
#define	COLOR_DK_GRAY		8
#define	COLOR_INDIGO		9
#define	COLOR_LT_GREEN		10
#define	COLOR_LT_CYAN		11
#define	COLOR_ORANGE		12
#define	COLOR_LT_MAGENTA	13
#define	COLOR_YELLOW		14
#define	COLOR_WHITE			15

int		initGraphics(void);
int		restoreGraphics(void);

int		clearScreen(int color);
int 	putPixel(int x, int y, int color);
int		getPixel(int x, int y);
int		drawLine(int x0, int y0, int x1, int y1, int color);
int		drawCircle(int x0, int y0, int radius, int color);
int		drawRect(int x0, int y0, int x1, int y1, int color, int fill);
int		drawChar(char charIn, int xpos, int ypos, int colorFG, int colorBG);
int		drawString(char *theString, int xpos, int ypos, int colorFG, int colorBG);

int		drawVectorChar(char charIn, int xpos, int ypos, int colorFG);
int		drawVectorString(char *theString, int xpos, int ypos, int colorFG);

#endif	// GRAPHICS_H
