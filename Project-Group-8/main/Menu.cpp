#include "Menu.h"
#include "layout.h"
#include "Console_size.h"

void Menu::run()
{
	int choose;

	system("cls");
	Hidden_Mouse();

	layout::WhiteConsole();
	layout::drawGomoku();

	choose = option();
	// play with other
	if (choose == 11) {
		layout Caro_twoPlayer;
		Caro_twoPlayer.run();
	}
	// play with computer . ps: cho bo sung
	if (choose == 12) {
		return;
	}
	// quit game
	if (choose == 14) {
		return;
	}
}

int option()
{
	int x = 30, y = 11;
	char choose;

	gotoxy(x, y, COLOR_RED + COLOR_WHITE_BACKGROUND); putchar(175);
	while (true) {
		if (_kbhit())
		{
			choose = _getch();
			// down
			if (choose == 'S' || choose == 's' || choose == 80)
			{
				y = y + 1;
				if (y > 14) {
					y = 11;
				}
				system("cls");
				layout::drawGomoku();
				gotoxy(x, y, COLOR_RED + COLOR_WHITE_BACKGROUND); putchar(175);
			}
			// up
			if (choose == 'W' || choose == 'w' || choose == 72)
			{
				y = y - 1;
				if (y < 11) {
					y = 14;
				}
				system("cls");
				layout::drawGomoku();
				gotoxy(x, y, COLOR_RED + COLOR_WHITE_BACKGROUND); putchar(175);
			}
			// enter
			if (choose == 13 || choose == ' ')
			{
				if (y != 13) return y;
				// guide play
				layout::GuidePlay();
				system("cls");
				layout::drawGomoku();
				gotoxy(x, y, COLOR_RED + COLOR_WHITE_BACKGROUND); putchar(175);
			}
		}
	}
}