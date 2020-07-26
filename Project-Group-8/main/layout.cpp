#include "layout.h"
#include "Console_size.h"

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
	this->WhiteConsole();
	this->B.drawBoard();
	this->B.play();
}

void layout::drawGomoku()
{
	gotoxy(0, 0, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "   ********      *******     ****     ****     *******     **   **   **     **" << endl;
	cout << "  **      **    **     **    ** **   ** **    **     **    **  **    **     **" << endl;
	cout << " **            **       **   **  ** **  **   **       **   ** **     **     **" << endl;
	cout << " **            **       **   **    **   **   **       **   ****      **     **" << endl;
	cout << " **    *****   **       **   **    *    **   **       **   ** **     **     **" << endl;
	cout << "  **      **    **     **    **         **    **     **    **  **    **     **" << endl;
	cout << "   ********      *******     **         **     *******     **  **     ******* " << endl;
	
	gotoxy(32, 11, COLOR_BLACK + COLOR_WHITE_BACKGROUND); cout << "PLAY WITH OTHERS";
	gotoxy(32, 12, COLOR_BLACK + COLOR_WHITE_BACKGROUND); cout << "PLAY WITH COMPUTER";
	gotoxy(32, 13, COLOR_BLACK + COLOR_WHITE_BACKGROUND); cout << "GUIDE PLAY";
	gotoxy(32, 14, COLOR_BLACK + COLOR_WHITE_BACKGROUND); cout << "QUIT GAME";
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

void layout::drawLoading()
{
	system("cls");
	layout::WhiteConsole();
	Hidden_Mouse();

	gotoxy(0, 0, COLOR_BLACK + COLOR_WHITE_BACKGROUND);
	
	// chu loading game
	gotoxy(33, 9, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "LOADING GAME !!!";

	// ve  loading
	gotoxy(21, 12, COLOR_BLACK + COLOR_WHITE_BACKGROUND);
	for (int i = 0; i < 40; i++) {
		cout << "_" ;
	}
	gotoxy(21, 12, COLOR_BLACK );
	for (int i = 0; i < 20; i++) {
		cout << " ";
		Sleep(150);
	}
	gotoxy(41, 12, COLOR_BLACK);
	for (int i = 0; i < 12; i++) {
		cout << " ";
		Sleep(210);
	}
	gotoxy(53, 12, COLOR_BLACK);
	for (int i = 0; i < 9; i++) {
		cout << " ";
		Sleep(390);
	}
	Sleep(1000);
	
}