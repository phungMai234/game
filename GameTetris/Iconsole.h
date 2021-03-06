#ifndef _console_header
#define _console_header


#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

#define default_ColorCode		7


#define key_Up		72
#define key_Down	80
#define key_Left	75
#define key_Right	77
//#define key_none	-1



//--------------------------------------------------------

#include <windows.h>


/* PROTOTYPE */

/*
 * Function: {void} clrscr()
 * Brief: clear screen
 */
void clrscr();

/*
 * Function: {void} gotoXY(int column, int line)
 * Brief: move to location
 */
void gotoXY (int column, int line);

/*
 * Function: {void} TextColor
 * Brief: fill color for object
 */
void TextColor (int color);




#endif
