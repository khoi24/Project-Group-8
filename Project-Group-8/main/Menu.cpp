#include "Menu.h"
#include "layout.h"
#include "Console_size.h"

void Menu::drawLoading()
{
	system("cls");
	layout::WhiteConsole();
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


	/* ve  loading
	gotoxy(21, 12, COLOR_BLACK + COLOR_WHITE_BACKGROUND);
	for (int i = 0; i < 40; i++) {
		cout << "_";
	}
	gotoxy(21, 12, COLOR_BLACK);
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
	Sleep(1000);*/
}
void Menu::run()
{
	int choose;

	this->drawLoading();

	system("cls");
	Hidden_Mouse();

	layout::WhiteConsole();
	layout::drawGomoku();

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

int option()
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
				if (y > 19) {
					y = 15;
				}
				system("cls");
				layout::drawGomoku();
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
				layout::drawGomoku();
				gotoxy(x, y, COLOR_RED + COLOR_WHITE_BACKGROUND); putchar(175);
			}
			// enter
			if (choose ==KEY_ENTER || choose == ' ')
			{
				if (y != 17) return y;
				// guide play
				layout::GuidePlay();
				system("cls");
				layout::drawGomoku();
				gotoxy(x, y, COLOR_RED + COLOR_WHITE_BACKGROUND); putchar(175);
			}
		}
	}
}