#include "Menu.h"
#include "layout.h"
#include "Console_size.h"

void Menu::drawLoading()
{
	Hidden_Mouse();

	int length = 100;
	gotoxy(5, 27, COLOR_BLACK);
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

	//K
	gotoxy(30, 12, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *     * *";
	gotoxy(30, 13, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *    * *";
	Sleep(200);
	gotoxy(30, 14, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *   * *"; Sleep(200);
	gotoxy(30, 15, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *  * *"; Sleep(200);
	gotoxy(30, 16, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * *"; Sleep(200);
	gotoxy(30, 17, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * *"; Sleep(200);
	gotoxy(30, 18, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *  * *"; Sleep(200);
	gotoxy(30, 19, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *   * *"; Sleep(200);
	gotoxy(30, 20, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *    * *"; Sleep(200);
	gotoxy(30, 21, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *     * *"; Sleep(200);
	
	//U
	gotoxy(46, 12, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *"; Sleep(200);
	gotoxy(46, 13, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *"; Sleep(200);
	Sleep(200);
	gotoxy(46, 14, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *"; Sleep(200);
	gotoxy(46, 15, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *"; Sleep(200);
	gotoxy(46, 16, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *"; Sleep(200);
	gotoxy(46, 17, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *"; Sleep(200);
	gotoxy(46, 18, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *"; Sleep(200);
	gotoxy(46, 19, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *"; Sleep(200);
	gotoxy(46, 20, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * * * * *"; Sleep(200);
	gotoxy(47, 21, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * * * *"; Sleep(200);
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

	//K
	gotoxy(30, 12, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *     * *";
	gotoxy(30, 13, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *    * *";
	gotoxy(30, 14, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *   * *";
	gotoxy(30, 15, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *  * *";
	gotoxy(30, 16, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * *";
	gotoxy(30, 17, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * *";
	gotoxy(30, 18, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *  * *";
	gotoxy(30, 19, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *   * *";
	gotoxy(30, 20, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *    * *";
	gotoxy(30, 21, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *     * *";

	//U
	gotoxy(46, 12, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *";
	gotoxy(46, 13, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *"; 
	gotoxy(46, 14, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *"; 
	gotoxy(46, 15, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *";
	gotoxy(46, 16, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *";
	gotoxy(46, 17, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *";
	gotoxy(46, 18, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *";
	gotoxy(46, 19, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* *           * *";
	gotoxy(46, 20, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * * * * *";
	gotoxy(47, 21, COLOR_RED + COLOR_WHITE_BACKGROUND);
	cout << "* * * * * * * *"; 

	//Menu
	gotoxy(42, 23, COLOR_BLACK + COLOR_WHITE_BACKGROUND); cout << "PLAY WITH OTHERS";
	gotoxy(42, 24, COLOR_BLACK + COLOR_WHITE_BACKGROUND); cout << "PLAY WITH COMPUTER";
	gotoxy(42, 25, COLOR_BLACK + COLOR_WHITE_BACKGROUND); cout << "GUIDE PLAY";
	gotoxy(42, 26, COLOR_BLACK + COLOR_WHITE_BACKGROUND); cout << "QUIT GAME";
}

void Menu::run()
{
	int choose;

	system("cls");
	Hidden_Mouse();

/*	// hien thi loading
	this->m_layout.WhiteConsole();
	this->drawLoading();

	// hien thi menu
	system("cls");
	Hidden_Mouse();

	
	this->drawGomoku_run();  */

	this->m_layout.WhiteConsole();

	this->choosen();

	choose = option();

	// play with other
	if (choose == 23) {

		layout Caro_twoPlayer;
		Caro_twoPlayer.run();
	}
	// play with computer ** ps: cho bo sung
	if (choose == 24) {

		layout Caro_PlayWithAI;
		Caro_PlayWithAI.runAI();
	}
	// quit game
	if (choose == 26) {
		return;
	}

}

int Menu::option()
{
	int x = 41, y = 23;
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
				if (y > 26) {
					y = 23;
				}
				system("cls");
				this->choosen();
				gotoxy(x, y, COLOR_RED + COLOR_WHITE_BACKGROUND); putchar(175);
			}
			// up
			if (choose == 'W' || choose == 'w' || choose == 72)
			{
				y = y - 1;
				if (y < 23) {
					y = 26;
				}
				system("cls");
				this->choosen();
				gotoxy(x, y, COLOR_RED + COLOR_WHITE_BACKGROUND); putchar(175);
			}
			// enter
			if (choose ==KEY_ENTER || choose == ' ')
			{
				if (y != 25) return y;
				// guide play
				this->m_layout.GuidePlay();
				system("cls");
				this->choosen();
				gotoxy(x, y, COLOR_RED + COLOR_WHITE_BACKGROUND); putchar(175);
			}
		}
	}
}