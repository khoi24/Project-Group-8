#include "layout.h"
void colorizing(WORD color_code)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, color_code);
}

void gotoxy(int column, int row, WORD color_code)
{
	COORD coord = { column,row };
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdout, coord);
	colorizing(color_code);
}

void fixConsole() {

	HWND consoleWindow = GetConsoleWindow();

	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);

	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void WhiteConsole()
{
	for (int i = 0; i < 120; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(i, j, COLOR_WHITE_BACKGROUND); std::cout << " ";
		}
	}
}