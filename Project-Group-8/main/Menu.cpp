#include "Menu.h"
#include "layout.h"
#include "Console_size.h"

void Menu::drawLoading()
{
	system("cls");
	this->m_layout.WhiteConsole();
	Hidden_Mouse();
	//chu loading game
	gotoxy(40, 15, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "LOADING GAME !!!";
	//

	int length = 100;
	gotoxy(5, 20, COLOR_BLACK);
	for (int i =5; i <= length; ++i) {
		putchar(219);
		if (i == (int)(length * 0.2+15)) Sleep(800);		// == 20%
		else if (i == (int)(length * 0.6+15)) Sleep(1000);	// == 60%
		else if (i > (int)(length * 0.9+15)) Sleep(2 * i);	// >  90%
		else Sleep(20);
	}
}

void Menu::drawGomoku_run()
{
	//G
	gotoxy(5, 1, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * *";
	Sleep(200);
	gotoxy(3, 2, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * * * *";
	Sleep(200);
	gotoxy(1, 3, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *";
	Sleep(200);
	gotoxy(1, 4, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *";
	Sleep(200);
	gotoxy(1, 5, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *       * * * *";
	Sleep(200);
	gotoxy(1, 6, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *       * * * *";
	Sleep(200);
	gotoxy(1, 7, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *";
	Sleep(200);
	gotoxy(1, 8, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *";
	Sleep(200);
	gotoxy(3, 9, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * * * *";
	Sleep(200);
	gotoxy(5, 10, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * *";
	Sleep(200);


	//O
	gotoxy(26, 1, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * *";
	Sleep(200);
	gotoxy(24, 2, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * * * *";
	Sleep(200);
	gotoxy(22, 3, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	Sleep(200);
	gotoxy(22, 4, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	Sleep(200);
	gotoxy(22, 5, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	Sleep(200);
	gotoxy(22, 6, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	Sleep(200);
	gotoxy(22, 7, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	Sleep(200);
	gotoxy(22, 8, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	Sleep(200);
	gotoxy(24, 9, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * * * *";
	Sleep(200);
	gotoxy(26, 10, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * *";
	Sleep(200);

	//M
	gotoxy(45, 1, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * *                 * * *";
	Sleep(200);
	gotoxy(45, 2, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * *             * * * *";
	gotoxy(45, 3, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *  * *           * *  * *";
	Sleep(200);
	gotoxy(45, 4, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *   * *         * *   * *";
	Sleep(200);
	gotoxy(45, 5, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *    * *       * *    * *";
	Sleep(200);
	gotoxy(45, 6, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *     * *     * *     * *";
	Sleep(200);
	gotoxy(45, 7, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *      * *   * *      * *";
	Sleep(200);
	gotoxy(45, 8, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *       * * * *       * *";
	gotoxy(45, 9, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *        * * *        * *";
	Sleep(200);
	gotoxy(45, 10, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *         * *         * *";
	Sleep(200);

	//O
	gotoxy(80, 1, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * *";
	Sleep(200);
	gotoxy(78, 2, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * * * *";
	Sleep(200);
	gotoxy(76, 3, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	Sleep(200);
	gotoxy(76, 4, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	Sleep(200);
	gotoxy(76, 5, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	Sleep(200);
	gotoxy(76, 6, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	Sleep(200);
	gotoxy(76, 7, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	Sleep(200);
	gotoxy(76, 8, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	Sleep(200);
	gotoxy(78, 9, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * * * *";
	Sleep(200);
	gotoxy(80, 10, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * *";
	Sleep(200);
}

void Menu::choosen()
{
	//G
	gotoxy(5, 1, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * *";
	gotoxy(3, 2, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * * * *";
	gotoxy(1, 3, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *";
	gotoxy(1, 4, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *";
	gotoxy(1, 5, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *       * * * *";
	gotoxy(1, 6, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *       * * * *";
	gotoxy(1, 7, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *";
	gotoxy(1, 8, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *";
	gotoxy(3, 9, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * * * *";
	gotoxy(5, 10, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * *";


	//O
	gotoxy(26, 1, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * *";
	gotoxy(24, 2, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * * * *";
	gotoxy(22, 3, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	gotoxy(22, 4, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	gotoxy(22, 5, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	gotoxy(22, 6, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	gotoxy(22, 7, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	gotoxy(22, 8, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	gotoxy(24, 9, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * * * *";
	gotoxy(26, 10, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * *";

	//M
	gotoxy(45, 1, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * *                 * * *";
	gotoxy(45, 2, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * *             * * * *";
	gotoxy(45, 3, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *  * *           * *  * *";
	gotoxy(45, 4, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *   * *         * *   * *";
	gotoxy(45, 5, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *    * *       * *    * *";
	gotoxy(45, 6, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *     * *     * *     * *";
	gotoxy(45, 7, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *      * *   * *      * *";
	gotoxy(45, 8, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *       * * * *       * *";
	gotoxy(45, 9, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *        * * *        * *";
	gotoxy(45, 10, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *         * *         * *";

	//O
	gotoxy(80, 1, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * *";
	gotoxy(78, 2, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * * * *";
	gotoxy(76, 3, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	gotoxy(76, 4, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	gotoxy(76, 5, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	gotoxy(76, 6, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	gotoxy(76, 7, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	gotoxy(76, 8, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *             * *";
	gotoxy(78, 9, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * * * *";
	gotoxy(80, 10, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * *";


	//Menu
	gotoxy(45, 15, COLOR_BLACK + COLOR_WHITE_BACKGROUND); cout << "PLAY WITH OTHERS";
	gotoxy(45, 16, COLOR_BLACK + COLOR_WHITE_BACKGROUND); cout << "PLAY WITH COMPUTER";
	gotoxy(45, 17, COLOR_BLACK + COLOR_WHITE_BACKGROUND); cout << "GUIDE PLAY";
	gotoxy(45, 18, COLOR_BLACK + COLOR_WHITE_BACKGROUND); cout << "QUIT GAME";
}

void Menu::run()
{
	int choose;

	//this->drawLoading();

	system("cls");
	Hidden_Mouse();

	this->m_layout.WhiteConsole();
	this->drawGomoku_run();
	this->choosen();
	choose = option();
	// play with other
	if (choose == 15) {
		layout Caro_twoPlayer;
		Caro_twoPlayer.run();
	}
	// play with computer . ps: cho bo sung
	if (choose == 16) {
		return;
	}
	// quit game
	if (choose == 18) {
		return;
	} 
}

int Menu::option()
{
	int x = 44, y = 15;
	unsigned char choose;

	gotoxy(x, y, COLOR_RED + COLOR_WHITE_BACKGROUND); putchar(175);
	while (true) {
		if (_kbhit())
		{
			choose = _getch();
			// down
			if (choose == 'S' || choose == 's' || choose == 80)
			{
				y = y + 1;
				if (y > 18) {
					y = 15;
				}
				system("cls");
				this->choosen();
				gotoxy(x, y, COLOR_RED + COLOR_WHITE_BACKGROUND); putchar(175);
			}
			// up
			if (choose == 'W' || choose == 'w' || choose == 72)
			{
				y = y - 1;
				if (y < 15) {
					y = 18;
				}
				system("cls");
				this->choosen();
				gotoxy(x, y, COLOR_RED + COLOR_WHITE_BACKGROUND); putchar(175);
			}
			// enter
			if (choose ==KEY_ENTER || choose == ' ')
			{
				if (y != 17) return y;
				// guide play
				this->m_layout.GuidePlay();
				system("cls");
				this->choosen();
				gotoxy(x, y, COLOR_RED + COLOR_WHITE_BACKGROUND); putchar(175);
			}
		}
	}
}