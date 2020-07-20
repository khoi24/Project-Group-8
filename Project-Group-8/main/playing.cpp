#include <iostream>
#include "layout.h"
#include "playing.h"
using namespace std;

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


// Hàm Playing
void board::play()
{
	board::appearCursor();
	board::BlankMatrix();
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
			gotoxy(46, 16, COLOR_WHITE_BACKGROUND + COLOR_RED); 
			cout << "X: " << _x;
			gotoxy(61, 16, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
			cout << "O: "<<_o;

			gotoxy(43, 24, COLOR_WHITE_BACKGROUND); cout << "Do you want to play again?"; //Ask to play again
			int choose = 0;
			while (true)
			{
				gotoxy(50, 21, choose % 2 == 0 ? 128 : COLOR_WHITE_BACKGROUND); cout << "Yes";
				gotoxy(63, 21, choose % 2 == 1 ? 128 : COLOR_WHITE_BACKGROUND); cout << "NO";

				unsigned char c = getch();
				if (c == KEY_ENTER)
				{
					if (choose == 0)
					{
						layout::WhiteConsole();
						this->drawBoard();
						board::play();
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
			gotoxy(46, 16, COLOR_WHITE_BACKGROUND + COLOR_RED);
			cout << "X " << _x;
			gotoxy(61, 16, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
			cout << "O:"<<_o;

			gotoxy(43, 20, COLOR_WHITE_BACKGROUND); cout << "Do you want to play again?"; //Ask to play again
			int choose = 0;
			while (true)
			{
				gotoxy(50, 21, choose % 2 == 0 ? 128 : COLOR_WHITE_BACKGROUND); cout << "Yes";
				gotoxy(63, 21, choose % 2 == 1 ? 128 : COLOR_WHITE_BACKGROUND); cout << "NO";

				unsigned char c = getch();
				if (c == KEY_ENTER)
				{
					if (choose == 0)
					{
						layout::WhiteConsole();
						board::drawBoard();
						board::play();
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
						if(choose==1)
							choose--;
					}
					if (c == KEY_RIGHT)
					{
						if(choose==0)
							choose++;
					}
				}
			}
		}

		// Hòa
		if (turn == 144)
		{
			system("cls");
			hiddenCursor();
			layout::WhiteConsole();
			gotoxy(50, 16, COLOR_WHITE_BACKGROUND);
			cout << "DRAW";

			gotoxy(43, 24, COLOR_WHITE_BACKGROUND); cout << "Do you want to play again?"; //Ask to play again
			int choose=0;
			while (true)
			{
				gotoxy(50, 21, choose % 2 == 0 ? 128 : COLOR_WHITE_BACKGROUND); cout << "Yes";
				gotoxy(63, 21, choose % 2 == 1 ? 128 : COLOR_WHITE_BACKGROUND); cout << "NO";

				unsigned char c = getch();
				if (c == KEY_ENTER)
				{
					if (choose == 0)
					{
						layout::WhiteConsole();
						board::drawBoard();
						board::play();
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
				/*gotoxy(j, i, 240); putchar(197);
				continue;*/
			}
		}
		count = 0;
	}
	gotoxy(27, 27, 240); std::cout << " ";
}
