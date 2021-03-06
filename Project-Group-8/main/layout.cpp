#include "layout.h"
#include "Console_size.h"
#include "playing.h"

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

// chay computer
void layout::runAI()
{
	this->B.playWithComputer();
}


void layout::GuidePlay()
{
	char choose;

	system("cls");
	layout::WhiteConsole();
	gotoxy(30, 0, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "GUIDE PLAY";

	gotoxy(23, 3, COLOR_BLACK + COLOR_WHITE_BACKGROUND);
	cout << "Play 1:";
	gotoxy(23, 4, COLOR_BLACK + COLOR_WHITE_BACKGROUND);
	cout << "Press A, S, D, W to move";
	gotoxy(23, 5, COLOR_BLACK + COLOR_WHITE_BACKGROUND);
	cout << "Press SPACE to input ";
	gotoxy(44, 5, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "X";

	gotoxy(23, 8, COLOR_BLACK + COLOR_WHITE_BACKGROUND);
	cout << "Player 2:";
	gotoxy(23, 9, COLOR_BLACK + COLOR_WHITE_BACKGROUND);
	cout << "Press KEYBOARD ARROW to move";
	gotoxy(23, 10, COLOR_BLACK + COLOR_WHITE_BACKGROUND);
	cout << "Press ENTER to input ";
	gotoxy(44, 10, COLOR_BLUE + COLOR_WHITE_BACKGROUND);
	cout << "O";

	gotoxy(30, 13, COLOR_BLUE + COLOR_WHITE_BACKGROUND);
	cout << "THE RULE OF GOMOKU";
	gotoxy(15, 15, COLOR_BLACK + COLOR_WHITE_BACKGROUND);
	cout << " Two players alternate in placing a stone of their color ";
	gotoxy(15, 16, COLOR_BLACK + COLOR_WHITE_BACKGROUND);
	cout << "  on an empty intersection. The winner is the first ";
	gotoxy(15, 17, COLOR_BLACK + COLOR_WHITE_BACKGROUND);
	cout << "   player to get an unbroken row of five stones ";
	gotoxy(15, 18, COLOR_BLACK + COLOR_WHITE_BACKGROUND);
	cout << "    horizontally, vertically, or diagonally. ";

	gotoxy(28, 20, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << " *press ENTER to exit *";

	while (true) {
		if (_kbhit())
		{
			choose = _getch();
			if (choose == 13) {
				break;
			}
		}
	}
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
				if (i == 11 && j == 55)
				{
					gotoxy(j, i, 240); putchar(204);
				}
				if (i == 11 && j == 91)
				{
					gotoxy(j, i, 240); putchar(185);
				}
			}
		}
		else if (j > 55 && j < 91)
		{
			for (int i = 1; i <= 25; i++)
			{ 
				if (i == 11)
				{
					gotoxy(j, i, 240); putchar(205);
				}
			}
		}
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
	layout_menu();
}

void layout::layout_menu()
{
	gotoxy(67, 15, 240); cout << "Pause: P";
	gotoxy(67, 16, 240); cout << "Undo:  B";
	gotoxy(67, 17, 240); cout << "Save:  Ctrl +S";
	gotoxy(67, 18, 240); cout << "Load:  L";
	//X
	gotoxy(60, 2, COLOR_BLUE + COLOR_WHITE_BACKGROUND); cout << "* *     * *";
	gotoxy(61, 3, COLOR_BLUE + COLOR_WHITE_BACKGROUND); cout << "* *   * *";
	gotoxy(62, 4, COLOR_BLUE + COLOR_WHITE_BACKGROUND); cout << "* * * *";
	gotoxy(63, 5, COLOR_BLUE + COLOR_WHITE_BACKGROUND); cout << "* * *";
	gotoxy(62, 6, COLOR_BLUE + COLOR_WHITE_BACKGROUND); cout << "  * *";
	gotoxy(63, 7, COLOR_BLUE + COLOR_WHITE_BACKGROUND); cout << "* * *";
	gotoxy(62, 8, COLOR_BLUE + COLOR_WHITE_BACKGROUND); cout << "* * * *";
	gotoxy(61, 9, COLOR_BLUE + COLOR_WHITE_BACKGROUND); cout << "* *   * *";
	gotoxy(60, 10, COLOR_BLUE + COLOR_WHITE_BACKGROUND); cout << "* *     * *";
	
	//O
	gotoxy(74, 2, COLOR_RED + COLOR_WHITE_BACKGROUND); cout << "* * * * * *";
	gotoxy(72, 3, COLOR_RED + COLOR_WHITE_BACKGROUND); cout << "* * * * * * * *";
	gotoxy(72, 4, COLOR_RED + COLOR_WHITE_BACKGROUND); cout << "* *         * *";
	gotoxy(72, 5, COLOR_RED + COLOR_WHITE_BACKGROUND); cout << "* *         * *";
	gotoxy(72, 6, COLOR_RED + COLOR_WHITE_BACKGROUND); cout << "* *         * *";
	gotoxy(72, 7, COLOR_RED + COLOR_WHITE_BACKGROUND); cout << "* *         * *";
	gotoxy(72, 8, COLOR_RED + COLOR_WHITE_BACKGROUND); cout << "* *         * *";
	gotoxy(72, 9, COLOR_RED + COLOR_WHITE_BACKGROUND); cout << "* * * * * * * *";
	gotoxy(74, 10, COLOR_RED + COLOR_WHITE_BACKGROUND); cout << "* * * * * *";
}