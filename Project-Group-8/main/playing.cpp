#include <iostream>
#include "layout.h"
#include "playing.h"
using namespace std;


void board::init()
{
	layout::WhiteConsole();
	layout::drawlayout();
	board::drawBoard();
	board::appearCursor();
	board::BlankMatrix();
}
// Xét chẵn lẻ
bool board::even_odd()
{
	if (this->turn % 2 == 0)
	{
		return true;
	}
	return false;
}

// Ẩn con trỏ
void board::hiddenCursor()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}

//Hiện con trỏ
void board::appearCursor()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = TRUE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}

// Tạo ma trận trống
void board::BlankMatrix()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			a[i][j] = ' ';
		}
	}
}

// Xử lý chạm biên
void board::Edge()
{
	if (this->x > 48) this->x = 4;
	if (this->x < 4) this->x = 48;
	if (this->y < 2) this->y = 24;
	if (this->y > 24) this->y = 2;

}

// Check O hoặc X
char board::checkOX()
{
	if (this->even_odd() == true)
		return 'X';
	return 'O';
}

// Vẽ O hoặc X
void board::drawOX()
{
	if (a[this->x][this->y] != 'X' && a[this->x][this->y] != 'O')
	{
		a[this->x][this->y] = this->checkOX();

		if (a[this->x][this->y] == 'X')
		{
			cout << a[this->x][this->y];
		}

		if (a[this->x][this->y] == 'O')
		{
			cout << a[this->x][this->y];
		}

		turn += 1;
	}
	colorizing(COLOR_DEFAULT);

	// cap nhat vi tri x hoac o
	pr_x = x;
	pr_y = y;
	turn_back = true;
}

// Điều kiện O win
bool board::winO()
{
	for (int h = 4; h <= 48; h += 4)       // h là hoành độ
	{
		for (int t = 2; t <= 24; t += 2)   // t là tung độ
		{
			// Thắng theo hàng ngang
			if ((a[h][t] == 'O') && (a[h + 4][t] == 'O') && (a[h + 8][t] == 'O') && (a[h + 12][t] == 'O') && (a[h + 16][t] == 'O') && ((a[h + 20][t] != 'X') || (a[h - 4][t] != 'X')))
			{
				return true;
			}

			// Thắng theo hàng dọc
			if ((a[h][t] == 'O') && (a[h][t + 2] == 'O') && (a[h][t + 4] == 'O') && (a[h][t + 6] == 'O') && (a[h][t + 8] == 'O') && ((a[h][t + 10] != 'X') || (a[h][t - 2] != 'X')))
			{
				return true;
			}

			// Thắng theo hàng chéo qua phải
			if ((a[h][t] == 'O') && (a[h + 4][t + 2] == 'O') && (a[h + 8][t + 4] == 'O') && (a[h + 12][t + 6] == 'O') && (a[h + 16][t + 8] == 'O') && ((a[h + 20][t + 10] != 'X') || (a[h - 4][t - 2] != 'X')))
			{
				return true;
			}
		}
	}

	for (int h = 20; h <= 48; h += 4)       // h là hoành độ
	{
		for (int t = 2; t <= 24; t += 2)    // t là tung độ
		{
			// Thắng theo hàng chéo qua trái
			if ((a[h][t] == 'O') && (a[h - 4][t + 2] == 'O') && (a[h - 8][t + 4] == 'O') && (a[h - 12][t + 6] == 'O') && (a[h - 16][t + 8] == 'O') && ((a[h - 20][t + 10] != 'X') || (a[h + 4][t - 2] != 'X')))
			{
				return true;
			}
		}
	}
	return false;
}

// Điều kiện X win
bool board::winX()
{
	for (int h = 4; h <= 48; h += 4)       // h là hoành độ
	{
		for (int t = 2; t <= 24; t += 2)   // t là tung độ
		{
			// Thắng theo hàng ngang
			if ((a[h][t] == 'X') && (a[h + 4][t] == 'X') && (a[h + 8][t] == 'X') && (a[h + 12][t] == 'X') && (a[h + 16][t] == 'X') && ((a[h + 20][t] != 'O') || (a[h - 4][t] != 'O')))
			{
				return true;
			}

			// Thắng theo hàng dọc
			if ((a[h][t] == 'X') && (a[h][t + 2] == 'X') && (a[h][t + 4] == 'X') && (a[h][t + 6] == 'X') && (a[h][t + 8] == 'X') && ((a[h][t + 10] != 'O') || (a[h][t - 2] != 'O')))
			{
				return true;
			}

			// Thắng theo hàng chéo qua phải
			if ((a[h][t] == 'X') && (a[h + 4][t + 2] == 'X') && (a[h + 8][t + 4] == 'X') && (a[h + 12][t + 6] == 'X') && (a[h + 16][t + 8] == 'X') && ((a[h + 20][t + 10] != 'O') || (a[h - 4][t - 2] != 'O')))
			{
				return true;
			}
		}
	}

	for (int h = 20; h <= 48; h += 4)       // h là hoành độ
	{
		for (int t = 2; t <= 24; t += 2)    // t là tung độ
		{
			// Thắng theo hàng chéo qua trái
			if ((a[h][t] == 'X') && (a[h - 4][t + 2] == 'X') && (a[h - 8][t + 4] == 'X') && (a[h - 12][t + 6] == 'X') && (a[h - 16][t + 8] == 'X') && ((a[h - 20][t + 10] != 'O') || (a[h + 4][t - 2] != 'O')))
			{
				return true;
			}
		}
	}
	return false;
}

// Hiển thị O thắng cuộc
void board::Oiswinner()
{
	gotoxy(17, 1, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                 OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
	gotoxy(17, 2, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                 OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
	gotoxy(17, 3, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "     OOOOOOOOOOOOOOOOOOO                                    OOOOOOOOOOOOOOOOOOO" << endl;
	gotoxy(17, 4, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "  OOOOOOOOOOOOOOOOOOOOOO                                    OOOOOOOOOOOOOOOOOOOOOO" << endl;
	gotoxy(17, 5, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << " OOOOO           OOOOOOO       OOOOOOOOOOOOOOOOOOOOOO       OOOOOOO           OOOOO" << endl;
	gotoxy(17, 6, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << " OOOOO           OOOOOOO       OOOOOOOOOOOOOOOOOOOOOO       OOOOOOO           OOOOO" << endl;
	gotoxy(17, 7, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << " OOOOO           OOOOOOO     OOOOO                OOOOO     OOOOOOO           OOOOO" << endl;
	gotoxy(17, 8, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << " OOOOO           OOOOOOO     OOOOO                OOOOO     OOOOOOO           OOOOO" << endl;
	gotoxy(17, 9, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << " OOOOO           OOOOOOO     OOOOO                OOOOO     OOOOOOO           OOOOO" << endl;
	gotoxy(17, 10, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << " OOOOO           OOOOOOO     OOOOO                OOOOO     OOOOOOO           OOOOO" << endl;
	gotoxy(17, 11, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << " OOOOO           OOOOOOO     OOOOO                OOOOO     OOOOOOO           OOOOO" << endl;
	gotoxy(17, 12, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << " OOOOO           OOOOOOO     OOOOO                OOOOO     OOOOOOO           OOOOO" << endl;
	gotoxy(17, 13, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "  OOOOO            OOOOOOO   OOOOO                OOOOO   OOOOOOO           OOOOO" << endl;
	gotoxy(17, 14, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "     OOOOOOOOOOOOOOOOOOOOOO    OOOOOOOOOOOOOOOOOOOOOO    OOOOOOOOOOOOOOOOOOOOOO " << endl;
	gotoxy(17, 15, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "        OOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOO " << endl;
	gotoxy(17, 16, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                      OOOOOOO                          OOOOOOO " << endl;
	gotoxy(17, 17, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                       OOOOOOO                        OOOOOOO " << endl;
	gotoxy(17, 18, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                        OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO " << endl;
	gotoxy(17, 19, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                         OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO " << endl;
	gotoxy(17, 20, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                                  OOOOOOOOOOOOOOOO        " << endl;
	gotoxy(17, 21, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                                 OOOOOOOOOOOOOOOOOO         " << endl;
	gotoxy(17, 22, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                                OOOOOOOOOOOOOOOOOOOO         " << endl;
	gotoxy(17, 23, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                               OOOOOOOOOOOOOOOOOOOOOO         " << endl;
}


// Hiển thị X thắng cuộc
void board::Xiswinner()
{
	gotoxy(17, 1, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	gotoxy(17, 2, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	gotoxy(17, 3, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "     XXXXXXXXXXXXXXXXXXX                                    XXXXXXXXXXXXXXXXXXX" << endl;
	gotoxy(17, 4, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "  XXXXXXXXXXXXXXXXXXXXXX                                    XXXXXXXXXXXXXXXXXXXXXX" << endl;
	gotoxy(17, 5, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << " XXXXX           XXXXXXX       XXXXX            XXXXX       XXXXXXX           XXXXX" << endl;
	gotoxy(17, 6, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << " XXXXX           XXXXXXX       XXXXX            XXXXX       XXXXXXX           XXXXX" << endl;
	gotoxy(17, 7, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << " XXXXX           XXXXXXX         XXXXX        XXXXX         XXXXXXX           XXXXX" << endl;
	gotoxy(17, 8, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << " XXXXX           XXXXXXX          XXXXX      XXXXX          XXXXXXX           XXXXX" << endl;
	gotoxy(17, 9, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << " XXXXX           XXXXXXX           XXXXX    XXXXX           XXXXXXX           XXXXX" << endl;
	gotoxy(17, 10, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << " XXXXX           XXXXXXX              XXXXXXX               XXXXXXX           XXXXX" << endl;
	gotoxy(17, 11, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << " XXXXX           XXXXXXX           XXXXX    XXXXX           XXXXXXX           XXXXX" << endl;
	gotoxy(17, 12, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << " XXXXX           XXXXXXX          XXXXX      XXXXX          XXXXXXX           XXXXX" << endl;
	gotoxy(17, 13, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "  XXXXX            XXXXXXX       XXXXX        XXXXX       XXXXXXX           XXXXX" << endl;
	gotoxy(17, 14, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "     XXXXXXXXXXXXXXXXXXXXXX    XXXXX            XXXXX    XXXXXXXXXXXXXXXXXXXXXX " << endl;
	gotoxy(17, 15, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "        XXXXXXXXXXXXXXXXXXXX   XXXXX            XXXXX   XXXXXXXXXXXXXXXXXXXX " << endl;
	gotoxy(17, 16, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                      XXXXXXX                          XXXXXXX " << endl;
	gotoxy(17, 17, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                       XXXXXXX                        XXXXXXX " << endl;
	gotoxy(17, 18, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                        XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX " << endl;
	gotoxy(17, 19, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                         XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX " << endl;
	gotoxy(17, 20, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                                  XXXXXXXXXXXXXXXX        " << endl;
	gotoxy(17, 21, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                                 XXXXXXXXXXXXXXXXXX         " << endl;
	gotoxy(17, 22, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                                XXXXXXXXXXXXXXXXXXXX         " << endl;
	gotoxy(17, 23, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                               XXXXXXXXXXXXXXXXXXXXXX         " << endl;
}

// Hàm Playing
void board::play()
{
PLAY:
	this->init();

	x = 4;    // x ban đầu
	y = 2;    // y ban đầu  
	turn = 0; // Lượt chơi
	while (1)
	{

		// Điều khiển

		// Điểm ban đầu
		gotoxy(x, y);

		// W A S D Space: Vẽ X
		if (this->turn % 2 == 0)
		{
			if (_kbhit())
			{
				key = _getch();

				if (key == 'D' or key == 'd')
				{

					x = x + 4;
					this->Edge();  // Xử lí chạm biên
				}

				if (key == 'S' or key == 's')
				{

					y = y + 2;
					this->Edge();  // Xử lí chạm biên
				}

				if (key == 'A' or key == 'a')
				{

					x = x - 4;
					this->Edge();  // Xử lí chạm biên
				}

				if (key == 'W' or key == 'w')
				{

					y = y - 2;
					this->Edge(); // Xử lí chạm biên
				}
				if (key == 'b' or key == 'B') {
					if (turn != 0 && turn_back == true) {

						turn_back = false;
						gotoxy(this->pr_x, this->pr_y, COLOR_WHITE_BACKGROUND);
						cout << " ";
						a[pr_x][pr_y] = ' ';
						turn--;
						//cout << "turn " << turn << endl;
						//system("pause");
						//goto M;
					}

				}
				if (key == ' ') // Điền X bằng Space
				{



					gotoxy(x, y, COLOR_WHITE_BACKGROUND + COLOR_RED);
					this->drawOX();
				}

				if (key == KEY_ESC)
				{
					break;
				}
			}
		}

		// Up Down Left Right Enter: Vẽ O
		else
		{
			if (_kbhit())
			{
				key = _getch();
				if (key == KEY_RIGHT)
				{
					x = x + 4;
					this->Edge();;  // Xử lí chạm biên
				}

				if (key == KEY_DOWN)
				{
					y = y + 2;
					this->Edge();;  // Xử lí chạm biên
				}

				if (key == KEY_LEFT)
				{
					x = x - 4;
					this->Edge();;  // Xử lí chạm biên
				}

				if (key == KEY_UP)
				{
					y = y - 2;
					this->Edge();;  // Xử lí chạm biên
				}
				if (key == 'b' or key == 'B') {
					if (turn != 0 && turn_back == true) {

						turn_back = false;
						gotoxy(this->pr_x, this->pr_y, COLOR_WHITE_BACKGROUND);
						cout << " ";
						a[pr_x][pr_y] = ' ';
						turn--;
						//cout << "turn " << turn << endl;
						//system("pause");
						//goto M;
					}

				}

				if (key == KEY_ENTER) // Điền O bằng Enter
				{


					gotoxy(x, y, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
					this->drawOX();
				}

				if (key == KEY_ESC)
				{
					break;
				}
			}
		}

		// O thắng
		if (winO() == true)
		{
			system("cls");
			hiddenCursor();
			layout::WhiteConsole();
			_o++;
			board::Oiswinner();

			gotoxy(46.5, 25, COLOR_WHITE_BACKGROUND); cout << "Do you want to play again?"; //Ask to play again
			int choose = 0;
			while (true)
			{
				gotoxy(50, 27, choose % 2 == 0 ? 128 : COLOR_WHITE_BACKGROUND); cout << "Yes";
				gotoxy(63, 27, choose % 2 == 1 ? 128 : COLOR_WHITE_BACKGROUND); cout << "NO";

				unsigned char c = getch();
				if (c == KEY_ENTER)
				{
					if (choose == 0)
					{
						goto PLAY;
					}
					if (choose == 1)
					{
						exit(0);
					}
				}
				if (c == 224 || c == 0)
				{
					c = getch();
					if (c == KEY_LEFT)
					{
						if (choose == 1)
							choose--;
					}
					if (c == KEY_RIGHT)
					{
						if (choose == 0)
							choose++;
					}
				}
			}

			//appearCursor();
		}

		// X thắng
		if (winX() == 1)
		{

			system("cls");
			hiddenCursor();
			layout::WhiteConsole();
			_x++;
			board::Xiswinner();

			gotoxy(46.5, 25, COLOR_WHITE_BACKGROUND); cout << "Do you want to play again?"; //Ask to play again
			int choose = 0;
			while (true)
			{
				gotoxy(50, 27, choose % 2 == 0 ? 128 : COLOR_WHITE_BACKGROUND); cout << "Yes";
				gotoxy(63, 27, choose % 2 == 1 ? 128 : COLOR_WHITE_BACKGROUND); cout << "NO";

				unsigned char c = getch();
				if (c == KEY_ENTER)
				{
					if (choose == 0)
					{
						goto PLAY;
					}
					if (choose == 1)
					{
						exit(0);
					}
				}
				if (c == 224 || c == 0)
				{
					c = getch();
					if (c == KEY_LEFT)
					{
						if (choose == 1)
							choose--;
					}
					if (c == KEY_RIGHT)
					{
						if (choose == 0)
							choose++;
					}
				}
				if (c == KEY_ESC)
				{
					exit(0);
				}
			}

		}

		// Hòa
		if (turn == 144)
		{
			system("cls");
			hiddenCursor();
			layout::WhiteConsole();
			gotoxy(46.5, 10, COLOR_WHITE_BACKGROUND);
			cout << "DRAW ♥" << endl;
			cout << "Such a tense match! Let's decide the winner in next game!";
			



			gotoxy(46.5, 25, COLOR_WHITE_BACKGROUND); cout << "Do you want to play again?"; //Ask to play again
			int choose = 0;

			while (true)
			{
				gotoxy(50, 27, choose % 2 == 0 ? 128 : COLOR_WHITE_BACKGROUND); cout << "Yes";
				gotoxy(63, 27, choose % 2 == 1 ? 128 : COLOR_WHITE_BACKGROUND); cout << "NO";

				unsigned char c = getch();
				if (c == KEY_ENTER)
				{
					if (choose == 0)
					{
						goto PLAY;
					}
					if (choose == 1)
					{
						exit(0);
					}
				}
				if (c == 224 || c == 0)
				{
					c = getch();
					if (c == KEY_LEFT)
					{
						if (choose == 1)
							choose--;
					}
					if (c == KEY_RIGHT)
					{
						if (choose == 0)
							choose++;
					}
				}
				if (c == KEY_ESC)
					break;
			}
		}

		
	}

}

void board::drawBoard()
{
	//đường ngang trên
	int count = 0;
	for (int i = 2; i <= 50; i++)
	{
		if (i == 2)
		{
			gotoxy(2, 1, COLOR_WHITE_BACKGROUND); putchar(218);
		}
		else if (i == 50)
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
	for (int i = 3; i <= 24; i += 2)
	{
		for (int j = 3; j <= 50; j++)
		{
			count++;
			if (count != 4)
			{
				gotoxy(j, i, 240); putchar(196);
			}
			else
			{
				count = 0;
			}
		}
		count = 0;
	}
	gotoxy(27, 27, 240); std::cout << " ";
}


