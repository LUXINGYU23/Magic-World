/*
 * File: graphics.h
 * Version: 1.0
 * Last modified on Mon Jun  6 11:03:27 1994 by eroberts
 * -----------------------------------------------------
 * This interface provides access to a simple library of
 * functions that make it possible to draw lines and arcs
 * on the screen.  This interface presents a portable
 * abstraction that can be used with a variety of window
 * systems implemented on different hardware platforms.
 */

#ifndef _graphics_h
#define _graphics_h
#include<windows.h>
#include"solve.h"
#include"file.h" 
#include"monsters.h"
#include"wordle.h"
#define MAX_BUTTONS 100
/*
 * Overview
 * --------
 * This library provides several functions for drawing lines
 * and circular arcs in a region of the screen that is
 * defined as the "graphics window."  Once drawn, these
 * lines and arcs stay in their position, which means that
 * the package can only be used for static pictures and not
 * for animation.
 *
 * Individual points within the window are specified by
 * giving their x and y coordinates.  These coordinates are
 * real numbers measured in inches, with the origin in the
 * lower left corner, as it is in traditional mathematics.
 *
 * The calls available in the package are listed below.  More
 * complete descriptions are included with each function
 * description.
 *
 *   InitGraphics();
 *   MovePen(x, y);
 *   DrawLine(dx, dy);
 *   DrawArc(r, start, sweep);
 *   width = GetWindowWidth();
 *   height = GetWindowHeight();
 *   x = GetCurrentX();
 *   y = GetCurrentY();
 */

/*
 * Function: InitGraphics
 * Usage: InitGraphics();
 * ----------------------
 * This procedure creates the graphics window on the screen.
 * The call to InitGraphics must precede any calls to other
 * functions in this package and must also precede any printf
 * output.  In most cases, the InitGraphics call is the first
 * statement in the function main.
 */

void InitGraphics(void);

void InitConsole(void);

/*
 * Function: MovePen
 * Usage: MovePen(x, y);
 * ---------------------
 * This procedure moves the current point to the position
 * (x, y), without drawing a line.  The model is that of
 * the pen being lifted off the graphics window surface and
 * then moved to its new position.
 */

void MovePen(double x, double y);

/*
 * Function: DrawLine
 * Usage: DrawLine(dx, dy);
 * ------------------------
 * This procedure draws a line extending from the current
 * point by moving the pen dx inches in the x direction
 * and dy inches in the y direction.  The final position
 * becomes the new current point.
 */

void DrawLine(double dx, double dy);

/*
 * Function: DrawArc
 * Usage: DrawArc(r, start, sweep);
 * --------------------------------
 * This procedure draws a circular arc, which always begins
 * at the current point.  The arc itself has radius r, and
 * starts at the angle specified by the parameter start,
 * relative to the center of the circle.  This angle is
 * measured in degrees counterclockwise from the 3 o'clock
 * position along the x-axis, as in traditional mathematics.
 * For example, if start is 0, the arc begins at the 3 o'clock
 * position; if start is 90, the arc begins at the 12 o'clock
 * position; and so on.  The fraction of the circle drawn is
 * specified by the parameter sweep, which is also measured in
 * degrees.  If sweep is 360, DrawArc draws a complete circle;
 * if sweep is 90, it draws a quarter of a circle.  If the value
 * of sweep is positive, the arc is drawn counterclockwise from
 * the current point.  If sweep is negative, the arc is drawn
 * clockwise from the current point.  The current point at the
 * end of the DrawArc operation is the final position of the pen
 * along the arc.
 *
 * Examples:
 *   DrawArc(r, 0, 360)    Draws a circle to the left of the
 *                         current point.
 *   DrawArc(r, 90, 180)   Draws the left half of a semicircle
 *                         starting from the 12 o'clock position.
 *   DrawArc(r, 0, 90)     Draws a quarter circle from the 3
 *                         o'clock to the 12 o'clock position.
 *   DrawArc(r, 0, -90)    Draws a quarter circle from the 3
 *                         o'clock to the 6 o'clock position.
 *   DrawArc(r, -90, -90)  Draws a quarter circle from the 6
 *                         o'clock to the 9 o'clock position.
 */

void DrawArc(double r, double start, double sweep);

/*
 * Functions: GetWindowWidth, GetWindowHeight
 * Usage: width = GetWindowWidth();
 *        height = GetWindowHeight();
 * ------------------------------------------
 * These functions return the width and height of the graphics
 * window, in inches.
 */

double GetWindowWidth(void);
double GetWindowHeight(void);

/*
 * Functions: GetCurrentX, GetCurrentY
 * Usage: x = GetCurrentX();
 *        y = GetCurrentY();
 * -----------------------------------
 * These functions return the current x and y positions.
 */

double GetCurrentX(void);
double GetCurrentY(void);

void Main();

typedef enum
{
    NO_BUTTON = 0,
    LEFT_BUTTON,
    MIDDLE_BUTTON,
    RIGHT_BUTTON
} ACL_Mouse_Button;

typedef enum 
{
    BUTTON_DOWN,
    BUTTON_DOUBLECLICK,
    BUTTON_UP,
    ROLL_UP,
    ROLL_DOWN,
    MOUSEMOVE	
} ACL_Mouse_Event;

typedef enum 
{
	KEY_DOWN,
	KEY_UP
} ACL_Keyboard_Event;

typedef void (*KeyboardEventCallback) (int key,int event);
typedef void (*CharEventCallback) (char c);
typedef void (*MouseEventCallback) (int x, int y, int button, int event);
typedef void (*TimerEventCallback) (int timerID);

void registerKeyboardEvent(KeyboardEventCallback callback);
void registerCharEvent(CharEventCallback callback);
void registerMouseEvent(MouseEventCallback callback);
void registerTimerEvent(TimerEventCallback callback);

void cancelKeyboardEvent();
void cancelCharEvent();
void cancelMouseEvent();
void cancelTimerEvent();
HWND CreateImageButton(LPCSTR filePath, double xPosInch, double yPosInch, double widthInch, double heightInch, int buttonId);
extern int ButtonChoice;
extern HWND buttonList[MAX_BUTTONS];
extern HWND textboxList[MAX_BUTTONS];
extern int scene;
extern int mode;
extern int inmenu;
void DestroyButton(HWND buttonHandle);
void draw_bmp(const char* bmp_path, double x, double y, double width, double height) ;
void DestroyTextBox(HWND hwndTextBox);
HWND CreateTextBox(double xPosInch, double yPosInch, double widthInch, double heightInch, int textBoxId); 
extern char wordle_array[5][5];  // 声明一个5x5的全局wordle字符数组
extern char wordle_current[5][5];
void fill_results_in_array(char array[5][5], const char* result, int count);
// Function to read a word from a file by its index
// file_path: path to the word list file
// word_index: index of the word in the file (zero-indexed)
// returns: a pointer to the word read from the file
char* read_word_from_file(const char* file_path, int word_index);

// Function to compare two words and generate feedback
// target: the correct word to guess
// guess: the word guessed by the player
// returns: a string with feedback for each character ('G', 'Y', 'R')
char* compare_words(const char* target, const char* guess);
void print_array(char array[5][5]);
#endif
