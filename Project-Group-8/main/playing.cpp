#include <iostream>
#include "layout.h"
#include "playing.h"
using namespace std;

// Xét chẵn lẻ
bool playing::even_odd(long turn)
{
	if (turn % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Ẩn con trỏ
void playing::hiddenCursor()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}

//Hiện con trỏ
void playing::appearCursor()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = TRUE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}

// Tạo ma trận trống
void playing::BlankMatrix()
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
void playing::Edge(int& x, int& y)
{
	if (x > 48) x = 4;
	if (x < 4) x = 48;
	if (y < 2) y = 24;
	if (y > 24) y = 2;
}

// Check O hoặc X
char playing::checkOX(long i)
{
	if (playing::even_odd(i) == true)
	{
		return 'X';
	}
	else
	{
		return 'O';
	}
}

// Vẽ O hoặc X
void playing::drawOX(long x, long y)
{
	if (a[x][y] != 'X' && a[x][y] != 'O')
	{
		a[x][y] = playing::checkOX(turn);

		if (a[x][y] == 'X')
		{
			cout << a[x][y];
		}

		if (a[x][y] == 'O')
		{
			cout << a[x][y];
		}

		turn += 1;
	}
	colorizing(COLOR_DEFAULT);
}

// Điều kiện O win
bool playing::winO()
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
bool playing::winX()
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


// Hàm Playing
void playing::play()
{
	playing::appearCursor();
	playing::BlankMatrix();
	x = 4;    // x ban đầu
	y = 2;    // y ban đầu  
	turn = 0; // Lượt chơi

	while (1)
	{

		// Điều khiển

		// Điểm ban đầu
		gotoxy(x, y);

		// W A S D Space: Vẽ X
		if (turn % 2 == 0)
		{
			if (_kbhit())
			{
				key = _getch();

				if (key == 'D' or key == 'd')
				{
					x = x + 4;
					Edge(x, y);  // Xử lí chạm biên
				}

				if (key == 'S' or key == 's')
				{
					y = y + 2;
					Edge(x, y);  // Xử lí chạm biên
				}

				if (key == 'A' or key == 'a')
				{
					x = x - 4;
					Edge(x, y);  // Xử lí chạm biên
				}

				if (key == 'W' or key == 'w')
				{
					y = y - 2;
					Edge(x, y);  // Xử lí chạm biên
				}

				if (key == ' ') // Điền X bằng Space
				{
					gotoxy(x, y, COLOR_WHITE_BACKGROUND + COLOR_RED);
					drawOX(x, y);
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
					Edge(x, y);  // Xử lí chạm biên
				}

				if (key == KEY_DOWN)
				{
					y = y + 2;
					Edge(x, y);  // Xử lí chạm biên
				}

				if (key == KEY_LEFT)
				{
					x = x - 4;
					Edge(x, y);  // Xử lí chạm biên
				}

				if (key == KEY_UP)
				{
					y = y - 2;
					Edge(x, y);  // Xử lí chạm biên
				}

				if (key == KEY_ENTER) // Điền O bằng Enter
				{
					gotoxy(x, y, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
					drawOX(x, y);
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
			WhiteConsole();
			_o++;
			gotoxy(46, 16, COLOR_WHITE_BACKGROUND + COLOR_RED); 
			cout << "X " << _x;
			gotoxy(61, 16, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
			cout << _o << " O";

			gotoxy(43, 24, COLOR_WHITE_BACKGROUND); cout << "Do you want to play again?"; //Ask to play again
			gotoxy(43, 25, COLOR_WHITE_BACKGROUND); cout << "(Y) Yes";
			gotoxy(63, 25, COLOR_WHITE_BACKGROUND); cout << "(N) NO";


			again = _getch();

			if (again == 'y' or again == 'Y')
			{
				WhiteConsole();
				layout::drawBoard();
				play();
			}
			if (again == 'n' or again == 'N')
			{
				exit(0);
			}

			//appearCursor();
		}

		// X thắng
		if (winX() == 1)
		{

			system("cls");
			hiddenCursor();
			WhiteConsole();
			_x++;
			gotoxy(46, 16, COLOR_WHITE_BACKGROUND + COLOR_RED);
			cout << "X " << _x;
			gotoxy(61, 16, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
			cout << _o << " O";

			gotoxy(43, 24, COLOR_WHITE_BACKGROUND); cout << "Do you want to play again?"; //Ask to play again
			gotoxy(43, 25, COLOR_WHITE_BACKGROUND); cout << "(Y) Yes";
			gotoxy(63, 25, COLOR_WHITE_BACKGROUND); cout << "(N) NO";


			again = _getch();

			if (again == 'y' or again == 'Y')
			{
				WhiteConsole();
				layout::drawBoard();
				play();
			}
			if (again == 'n' or again == 'N')
			{
				exit(0);
			}

			//appearCursor();
		}

		// Hòa
		if (turn == 144)
		{
			system("cls");
			hiddenCursor();
			WhiteConsole();
			gotoxy(50, 16, COLOR_WHITE_BACKGROUND);
			cout << "DRAW";

			gotoxy(43, 24, COLOR_WHITE_BACKGROUND); cout << "Do you want to play again?"; //Ask to play again
			gotoxy(43, 25, COLOR_WHITE_BACKGROUND); cout << "(Y) Yes";
			gotoxy(63, 25, COLOR_WHITE_BACKGROUND); cout << "(N) NO";


			again = _getch();

			if (again == 'y' or again == 'Y')
			{
				WhiteConsole();
				layout::drawBoard();
				play();
			}
			if (again == 'n' or again == 'N')
			{
				exit(0);
			}

			//appearCursor();
		}
	}
}