#include <iostream>
#include <string>
#include <Windows.h>
#pragma warning (disable:4996)
#include <conio.h>
#include "playing.h"
//COLOR CODE
#define COLOR_DEFAULT 7
#define COLOR_BLUE 1
#define COLOR_RED 4
#define COLOR_BLACK 0
#define COLOR_WHITE 15
#define COLOR_BLUE_BACKGROUND 16
#define COLOR_RED_BACKGROUND 64
#define COLOR_WHITE_BACKGROUND 240

//KEY CODE
#define KEY_BACKSPACE 8		// Backspace.
#define KEY_ENTER 13		// Enter.
#define KEY_ESC 27			// Esc.
#define KEY_UP 72			// 0 - 224	+ Up.
#define KEY_LEFT 75			// 0 - 224	+ Left.
#define KEY_RIGHT 77		// 0 - 224	+ Right.
#define KEY_DOWN 80		    // 0 - 224	+ Down.


//
#define PAUSE Sleep(2000);
#define BOARD_SIZE 12;

//
void fixConsole();
void colorizing(WORD color_code);
void gotoxy(int column, int row, WORD color_code=COLOR_DEFAULT);

class layout
{
private:
	board B;
public:
	void run();
	static void WhiteConsole();
	static void drawGomoku();
	static void GuidePlay();
	static void drawLoading();
};