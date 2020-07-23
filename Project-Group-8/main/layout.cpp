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
void layout::WhiteConsole()
{
	for (int i = 0; i < 120; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(i, j, COLOR_WHITE_BACKGROUND); std::cout << " ";
		}
	}
}

void layout::run()
{
	this->B.play();
}
void layout::drawlayout()
{
	//trai tren
	gotoxy(0, 0, 240); putchar(201);
	//ngang tren
	for (int i = 1; i <= 90; i++)
	{
		if (i == 55)
		{
			gotoxy(i, 0, 240); putchar(203);
		}
		else
			gotoxy(i, 0, 240); putchar(205);
	}
	//phai tren
	gotoxy(91, 0, 240); putchar(187);
	//cot doc
	for (int j = 0; j <= 91; j++)
	{
		if (j == 0 || j == 91 || j == 55)
		{
			for (int i = 1; i <= 25; i++)
			{
				gotoxy(j, i, 240); putchar(186);
			}
		}
		else
			continue;
	}
	//trai duoi
	gotoxy(0, 26, 240); putchar(200);
	//ngang duoi
	for (int i = 1; i <= 90; i++)
	{
		if (i == 55)
		{
			gotoxy(i, 26, 240); putchar(202);
		}
		else
			gotoxy(i, 26, 240); putchar(205);
	}
	gotoxy(91, 26, 240); putchar(188);
}