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
void layout::drawBoard()
{
	//đường ngang trên
	int count = 0;
	for (int i = 2; i <= 50; i++)
	{
		if (i == 2)
		{
			gotoxy(2, 1, COLOR_WHITE_BACKGROUND); putchar(218);
		}
		else if(i==50)
		{
			gotoxy(50, 1, COLOR_WHITE_BACKGROUND); putchar(191);
		}
		else
		{
			count++;
			if (count != 4)
			{
				gotoxy(i, 1, COLOR_WHITE_BACKGROUND); putchar(196);
			}
			else
			{
				gotoxy(i, 1, COLOR_WHITE_BACKGROUND); putchar(194);
				count = 0;
				continue;
			}
		}
	}

	//cột dọc biên
	for (int i = 3; i <= 24; i += 2)
	{
		for (int j = 2; j <= 50; j += 4)
		{
			if (j == 2)
			{
				gotoxy(2, i, COLOR_WHITE_BACKGROUND);
				putchar(195);
			}
			else if (j == 50)
			{
				gotoxy(50, i, COLOR_WHITE_BACKGROUND);
				putchar(180);
			}
			else
			{
				gotoxy(j, i, COLOR_WHITE_BACKGROUND);
				putchar(197);
			}
		}
	}
	//cột dọc trong
	for (int i = 2; i <= 50; i += 4)
	{
		for (int j = 2; j <= 24; j += 2)
		{
			gotoxy(i, j, 240); putchar(179);
		}
	}
	//ngang dưới
	count = 0;
	for (int i = 2; i <= 50; i++)
	{
		if (i == 2)
		{
			gotoxy(2, 25, COLOR_WHITE_BACKGROUND); putchar(192);
		}
		else if (i == 50)
		{
			gotoxy(50, 25, COLOR_WHITE_BACKGROUND); putchar(217);
		}
		else
		{
			count++;
			if (count != 4)
			{
				gotoxy(i, 25, COLOR_WHITE_BACKGROUND); putchar(196);
			}
			else
			{
				gotoxy(i, 25, COLOR_WHITE_BACKGROUND); putchar(193);
				count = 0;
				continue;
			}
		}
	}
	//ngang trong
	count = 0;
	for (int i = 3; i <= 24; i +=2)
	{
		for (int j = 3; j <= 50; j ++)
		{
			count++;
			if (count != 4)
			{
				gotoxy(j, i, 240); putchar(196);
			}
			else
			{
				count = 0;
				/*gotoxy(j, i, 240); putchar(197);
				continue;*/
			}
		}
		count = 0;
	}
	gotoxy(27, 27, 240); std::cout << " ";
}