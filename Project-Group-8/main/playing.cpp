#include <iostream>
#include "layout.h"
#include "playing.h"
using namespace std;
board::board()
{
	turn = 0;
	x = 4; y = 2;
	pr_x = -1;
	pr_y = -1;
	pr_x_ai = -1;
	pr_y_ai = -1;
	BlankMatrix();
}
void board::color_succeede() {
	
	char temp = 27;
	
		for (int j = 2; j < 6; j++) {
			for (int i = 0; i < 5; i++) {
				hiddenCursor();
				gotoxy(line[i].get_x(), line[i].get_y(), COLOR_WHITE_BACKGROUND + j);
				if(a[line[i].get_x()][line[i].get_y()]=='X')
					cout << temp << "[1m" << "X" << temp << "[0m";
				else if(a[line[i].get_x()][line[i].get_y()]=='O')
					cout << temp << "[1m" << "O" << temp << "[0m";
				
			}
			sound_succeeded();
		}
		
	
}
void coor::set_x_y(int x, int y) {
	m_x = x;
	m_y = y;
}
void board::sound_kick() {
	PlaySound(TEXT("kick.wav"), NULL, SND_SYNC | SND_FILENAME);
}

void board::sound_succeeded() {
	PlaySound(TEXT("succeed.wav"), NULL, SND_SYNC | SND_FILENAME);
}

void board::sound_winner() {
	PlaySound(TEXT("winner.wav"), NULL, SND_SYNC | SND_FILENAME);
}

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
	pr_x_ai=this->pr_x;
	pr_y_ai = this->pr_y;
	if (a[this->x][this->y] != 'X' && a[this->x][this->y] != 'O')
	{
		sound_kick();
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
				
				for (int i = 0; i < 5; i++) {
					line[i].set_x_y(h + i * 4, t);
				}
				return true;
			}

			// Thắng theo hàng dọc
			if ((a[h][t] == 'O') && (a[h][t + 2] == 'O') && (a[h][t + 4] == 'O') && (a[h][t + 6] == 'O') && (a[h][t + 8] == 'O') && ((a[h][t + 10] != 'X') || (a[h][t - 2] != 'X')))
			{
				for (int i = 0; i < 5; i++) {
					line[i].set_x_y(h, t + i * 2);
				}
				return true;
			}

			// Thắng theo hàng chéo qua phải
			if ((a[h][t] == 'O') && (a[h + 4][t + 2] == 'O') && (a[h + 8][t + 4] == 'O') && (a[h + 12][t + 6] == 'O') && (a[h + 16][t + 8] == 'O') && ((a[h + 20][t + 10] != 'X') || (a[h - 4][t - 2] != 'X')))
			{
				for (int i = 0; i < 5; i++) {
					line[i].set_x_y(h + i * 4, t + i * 2);
				}
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
				for (int i = 0; i < 5; i++) {
					line[i].set_x_y(h - i * 4, t + i * 2);
				}
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
				for (int i = 0; i < 5; i++) {
					line[i].set_x_y(h + i * 4, t);
				}
				return true;
			}

			// Thắng theo hàng dọc
			if ((a[h][t] == 'X') && (a[h][t + 2] == 'X') && (a[h][t + 4] == 'X') && (a[h][t + 6] == 'X') && (a[h][t + 8] == 'X') && ((a[h][t + 10] != 'O') || (a[h][t - 2] != 'O')))
			{
				for (int i = 0; i < 5; i++) {
					line[i].set_x_y(h, t + i * 2);
				}
				return true;
			}

			// Thắng theo hàng chéo qua phải
			if ((a[h][t] == 'X') && (a[h + 4][t + 2] == 'X') && (a[h + 8][t + 4] == 'X') && (a[h + 12][t + 6] == 'X') && (a[h + 16][t + 8] == 'X') && ((a[h + 20][t + 10] != 'O') || (a[h - 4][t - 2] != 'O')))
			{
				for (int i = 0; i < 5; i++) {
					line[i].set_x_y(h + i * 4, t + i * 2);
				}
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
				for (int i = 0; i < 5; i++) {
					line[i].set_x_y(h - i * 4, t + i * 2);
				}
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
	Sleep(50);
	gotoxy(17, 2, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                 OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
	Sleep(50);
	gotoxy(17, 3, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "     OOOOOOOOOOOOOOOOOOO                                    OOOOOOOOOOOOOOOOOOO" << endl;
	Sleep(50);
	gotoxy(17, 4, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "  OOOOOOOOOOOOOOOOOOOOOO                                    OOOOOOOOOOOOOOOOOOOOOO" << endl;
	Sleep(50);
	gotoxy(17, 5, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << " OOOOO           OOOOOOO       OOOOOOOOOOOOOOOOOOOOOO       OOOOOOO           OOOOO" << endl;
	Sleep(50);
	gotoxy(17, 6, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << " OOOOO           OOOOOOO       OOOOOOOOOOOOOOOOOOOOOO       OOOOOOO           OOOOO" << endl;
	Sleep(50);
	gotoxy(17, 7, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << " OOOOO           OOOOOOO     OOOOO                OOOOO     OOOOOOO           OOOOO" << endl;
	Sleep(50);
	gotoxy(17, 8, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << " OOOOO           OOOOOOO     OOOOO                OOOOO     OOOOOOO           OOOOO" << endl;
	Sleep(50);
	gotoxy(17, 9, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << " OOOOO           OOOOOOO     OOOOO                OOOOO     OOOOOOO           OOOOO" << endl;
	Sleep(50);
	gotoxy(17, 10, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << " OOOOO           OOOOOOO     OOOOO                OOOOO     OOOOOOO           OOOOO" << endl;
	Sleep(50);
	gotoxy(17, 11, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << " OOOOO           OOOOOOO     OOOOO                OOOOO     OOOOOOO           OOOOO" << endl;
	Sleep(50);
	gotoxy(17, 12, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << " OOOOO           OOOOOOO     OOOOO                OOOOO     OOOOOOO           OOOOO" << endl;
	Sleep(50);
	gotoxy(17, 13, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "  OOOOO            OOOOOOO   OOOOO                OOOOO   OOOOOOO           OOOOO" << endl;
	Sleep(50);
	gotoxy(17, 14, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "     OOOOOOOOOOOOOOOOOOOOOO    OOOOOOOOOOOOOOOOOOOOOO    OOOOOOOOOOOOOOOOOOOOOO " << endl;
	Sleep(50);
	gotoxy(17, 15, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "        OOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOO " << endl;
	Sleep(50);
	gotoxy(17, 16, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                      OOOOOOO                          OOOOOOO " << endl;
	Sleep(50);
	gotoxy(17, 17, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                       OOOOOOO                        OOOOOOO " << endl;
	Sleep(50);
	gotoxy(17, 18, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                        OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO " << endl;
	Sleep(50);
	gotoxy(17, 19, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                         OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO " << endl;
	Sleep(50);
	gotoxy(17, 20, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                                  OOOOOOOOOOOOOOOO        " << endl;
	Sleep(50);
	gotoxy(17, 21, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                                 OOOOOOOOOOOOOOOOOO         " << endl;
	Sleep(50);
	gotoxy(17, 22, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                                OOOOOOOOOOOOOOOOOOOO         " << endl;
	Sleep(50);
	gotoxy(17, 23, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
	cout << "                               OOOOOOOOOOOOOOOOOOOOOO         " << endl;
	sound_winner();
}


// Hiển thị X thắng cuộc
void board::Xiswinner()
{
	gotoxy(17, 1, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	Sleep(50);
	gotoxy(17, 2, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	Sleep(50);
	gotoxy(17, 3, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "     XXXXXXXXXXXXXXXXXXX                                    XXXXXXXXXXXXXXXXXXX" << endl;
	Sleep(50);
	gotoxy(17, 4, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "  XXXXXXXXXXXXXXXXXXXXXX                                    XXXXXXXXXXXXXXXXXXXXXX" << endl;
	Sleep(50);
	gotoxy(17, 5, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << " XXXXX           XXXXXXX       XXXXX            XXXXX       XXXXXXX           XXXXX" << endl;
	Sleep(50);
	gotoxy(17, 6, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << " XXXXX           XXXXXXX       XXXXX            XXXXX       XXXXXXX           XXXXX" << endl;
	Sleep(50);
	gotoxy(17, 7, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << " XXXXX           XXXXXXX         XXXXX        XXXXX         XXXXXXX           XXXXX" << endl;
	Sleep(50);
	gotoxy(17, 8, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << " XXXXX           XXXXXXX          XXXXX      XXXXX          XXXXXXX           XXXXX" << endl;
	Sleep(50);
	gotoxy(17, 9, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << " XXXXX           XXXXXXX           XXXXX    XXXXX           XXXXXXX           XXXXX" << endl;
	Sleep(50);
	gotoxy(17, 10, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << " XXXXX           XXXXXXX              XXXXXXX               XXXXXXX           XXXXX" << endl;
	Sleep(50);
	gotoxy(17, 11, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << " XXXXX           XXXXXXX           XXXXX    XXXXX           XXXXXXX           XXXXX" << endl;
	Sleep(50);
	gotoxy(17, 12, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << " XXXXX           XXXXXXX          XXXXX      XXXXX          XXXXXXX           XXXXX" << endl;
	Sleep(50);
	gotoxy(17, 13, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "  XXXXX            XXXXXXX       XXXXX        XXXXX       XXXXXXX           XXXXX" << endl;
	Sleep(50);
	gotoxy(17, 14, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "     XXXXXXXXXXXXXXXXXXXXXX    XXXXX            XXXXX    XXXXXXXXXXXXXXXXXXXXXX " << endl;
	Sleep(50);
	gotoxy(17, 15, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "        XXXXXXXXXXXXXXXXXXXX   XXXXX            XXXXX   XXXXXXXXXXXXXXXXXXXX " << endl;
	Sleep(50);
	gotoxy(17, 16, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                      XXXXXXX                          XXXXXXX " << endl;
	Sleep(50);
	gotoxy(17, 17, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                       XXXXXXX                        XXXXXXX " << endl;
	Sleep(50);
	gotoxy(17, 18, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                        XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX " << endl;
	Sleep(50);
	gotoxy(17, 19, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                         XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX " << endl;
	Sleep(50);
	gotoxy(17, 20, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                                  XXXXXXXXXXXXXXXX        " << endl;
	Sleep(50);
	gotoxy(17, 21, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                                 XXXXXXXXXXXXXXXXXX         " << endl;
	Sleep(50);
	gotoxy(17, 22, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                                XXXXXXXXXXXXXXXXXXXX         " << endl;
	Sleep(50);
	gotoxy(17, 23, COLOR_WHITE_BACKGROUND + COLOR_RED);
	cout << "                               XXXXXXXXXXXXXXXXXXXXXX         " << endl;
	sound_winner();
}

// Hàm Playing
void board::play()
{
	board temp;
	x = 4;    // x ban đầu
	y = 2;    // y ban đầu  
	turn = 0; // Lượt chơi
PLAY:
	this->init();
	if (turn != 0)
	{
		load(temp);
	}
LAYOUT:
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
				if (key == 112)
				{
					temp = save();
					pause();
					goto PLAY;
				}
				if (key == KEY_SAVE)
				{
					temp=save();
				}
				if (key==108)
				{
					goto PLAY;
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
				if (key==112)
				{
					temp=save();
					pause();
					goto PLAY;
				}
				if (key == KEY_SAVE)
				{
					temp=save();
				}
				if (key==108)
				{
					goto PLAY;
				}
			}
		}

		// O thắng
		if (winO() == true)
		{
			color_succeede();

			system("cls");
			hiddenCursor();
			layout::WhiteConsole();
			_o++;
			Oiswinner();

			gotoxy(46, 25, COLOR_WHITE_BACKGROUND); cout << "Do you want to play again?"; //Ask to play again
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
			color_succeede();
			system("cls");
			hiddenCursor();
			layout::WhiteConsole();
			_x++;
			board::Xiswinner();

			gotoxy(46, 25, COLOR_WHITE_BACKGROUND); cout << "Do you want to play again?"; //Ask to play again
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
			gotoxy(46, 10, COLOR_WHITE_BACKGROUND);
			cout << "DRAW ♥" << endl;
			cout << "Such a tense match! Let's decide the winner in next game!";
			



			gotoxy(46, 25, COLOR_WHITE_BACKGROUND); cout << "Do you want to play again?"; //Ask to play again
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

void board::playWithComputer()
{
	char BoardGame[12][11];
	board temp;

	// tao mang 2 chieu board game rong
	FindTheWay::EmptyBoard(BoardGame);

	x = 4;    // x ban đầu
	y = 2;    // y ban đầu  
	turn = 0; // Lượt chơi
PLAY:
	this->init();
	if (turn != 0)
	{
		// khoi tao lai mang boardgame
		FindTheWay::EmptyBoard(BoardGame);

		load(temp);
	}
LAYOUT:
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
						gotoxy(this->pr_x, this->pr_y, COLOR_WHITE_BACKGROUND);
						cout << " ";
						a[pr_x][pr_y] = ' ';
						BoardGame[this->pr_y / 2 - 1][this->pr_x / 4 - 1] = '_';
						turn--;

						gotoxy(this->pr_x_ai, this->pr_y_ai, COLOR_WHITE_BACKGROUND);
						cout << " ";
						a[pr_x_ai][pr_y_ai] = ' ';
						BoardGame[this->pr_y_ai / 2 - 1][this->pr_x_ai / 4 - 1] = '_';
						turn--;

					}
				turn_back = false;

				}
				if (key == ' ') // Điền X bằng Space
				{
					gotoxy(x, y, COLOR_WHITE_BACKGROUND + COLOR_RED);
					this->drawOX();

					BoardGame[y / 2 - 1][x / 4 - 1] = 'o';
				}

				if (key == KEY_ESC)
				{
					break;
				}
				if (key == 112)
				{
					temp = save();
					pause();
					goto PLAY;
				}
				if (key == KEY_SAVE)
				{
					temp = save();
				}
				if (key == 108)
				{
					goto PLAY;
				}
			}
		}

		// Up Down Left Right Enter: Vẽ O
		else
		{
			FindTheWay Way;
			// tim duong di tot nhat
			Move bestMove = Way.findBestMove(BoardGame);

			// dien board
			BoardGame[bestMove.row][bestMove.col] = 'x';

			x = 4 * bestMove.col + 4;
			y = 2 * bestMove.row + 2;

			gotoxy(x, y, COLOR_WHITE_BACKGROUND + COLOR_BLUE);
			this->drawOX();
		}

		// O thắng
		if (winO() == true)
		{
			// khoi tao lai mang boardgame
			FindTheWay::EmptyBoard(BoardGame);

			color_succeede();

			system("cls");
			hiddenCursor();
			layout::WhiteConsole();
			_o++;
			Oiswinner();

			gotoxy(46, 25, COLOR_WHITE_BACKGROUND); cout << "Do you want to play again?"; //Ask to play again
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
			// khoi tao lai mang boardgame
			FindTheWay::EmptyBoard(BoardGame);

			color_succeede();
			system("cls");
			hiddenCursor();
			layout::WhiteConsole();
			_x++;
			board::Xiswinner();

			gotoxy(46, 25, COLOR_WHITE_BACKGROUND); cout << "Do you want to play again?"; //Ask to play again
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
			// khoi tao lai mang boardgame
			FindTheWay::EmptyBoard(BoardGame);

			system("cls");
			hiddenCursor();
			layout::WhiteConsole();
			gotoxy(46, 10, COLOR_WHITE_BACKGROUND);
			cout << "DRAW ♥" << endl;
			cout << "Such a tense match! Let's decide the winner in next game!";

			gotoxy(46, 25, COLOR_WHITE_BACKGROUND); cout << "Do you want to play again?"; //Ask to play again
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
void board::pause()
{
NO_CHANGE:
	gotoxy(18, 9, 128); cout << "                                                            ";
	gotoxy(18, 10, 128); cout << "                                                            ";
	gotoxy(18, 11, 128); cout << "                                                            ";
	gotoxy(18, 12, 128); cout << "                                                            ";
	gotoxy(18, 13, 128); cout << "                                                            ";
	gotoxy(18, 14, 128); cout << "                                                            ";
	gotoxy(18, 15, 128); cout << "                                                            ";
	gotoxy(18, 16, 128); cout << "                                                            ";
	gotoxy(20, 9, 128); cout << "@@@@@@@@";
	gotoxy(20, 10, 128); cout << "@@     @@";
	gotoxy(20, 11, 128); cout << "@@     @@";
	gotoxy(20, 12, 128); cout << "@@     @@";
	gotoxy(20, 13, 128); cout << "@@@@@@@@";
	gotoxy(20, 14, 128); cout << "@@";
	gotoxy(20, 15, 128); cout << "@@";
	gotoxy(20, 16, 128); cout << "@@";

	gotoxy(34, 9, 128); cout << "@@@@";
	gotoxy(33, 10, 128); cout << "@@  @@";
	gotoxy(32, 11, 128); cout << "@@    @@";
	gotoxy(31, 12, 128); cout << "@@      @@";
	gotoxy(30, 13, 128); cout << "@@@@@@@@@@@@";
	gotoxy(29, 14, 128); cout << "@@          @@";
	gotoxy(28, 15, 128); cout << "@@            @@";
	gotoxy(27, 16, 128); cout << "@@              @@";

	gotoxy(46, 9, 128); cout << "@@      @@";
	gotoxy(46, 10, 128); cout << "@@      @@";
	gotoxy(46, 11, 128); cout << "@@      @@";
	gotoxy(46, 12, 128); cout << "@@      @@";
	gotoxy(46, 13, 128); cout << "@@      @@";
	gotoxy(46, 14, 128); cout << "@@      @@";
	gotoxy(46, 15, 128); cout << "@@      @@";
	gotoxy(46, 16, 128); cout << "@@@@@@@@";

	gotoxy(58, 9, 128); cout << "@@@@@@";
	gotoxy(57, 10, 128); cout << "@@";
	gotoxy(57, 11, 128); cout << "@@";
	gotoxy(57, 12, 128); cout << "@@";
	gotoxy(57, 13, 128); cout << "@@@@@@@";
	gotoxy(57, 14, 128); cout << "     @@";
	gotoxy(57, 15, 128); cout << "     @@";
	gotoxy(57, 16, 128); cout << "@@@@@@@";

	gotoxy(66, 9, 128); cout << "@@@@@@@@";
	gotoxy(66, 10, 128); cout << "@@";
	gotoxy(66, 11, 128); cout << "@@";
	gotoxy(66, 12, 128); cout << "@@";
	gotoxy(66, 13, 128); cout << "@@@@@@@@";
	gotoxy(66, 14, 128); cout << "@@";
	gotoxy(66, 15, 128); cout << "@@";
	gotoxy(66, 16, 128); cout << "@@@@@@@@";
	unsigned char c;
	c = getch();
	if (KEY_PAUSE(c))
	{
		return;
	}
	else
	{
		goto NO_CHANGE;
	}
}
board &board::load(const board &temp)
{

	pr_x = temp.pr_x;
	pr_y = temp.pr_y;
	y = temp.y;
	turn = temp.turn;
	turn_back = temp.turn_back;
	x = temp.x;
	_o = temp._o;
	_x = temp._x;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			this->a[i][j] = temp.a[i][j];
		}
	}
	for (int i = 0; i < 6; i++)
	{
		line[i] = temp.line[i];
	}
	for (int i = 4; i < 100; i+=4)
	{
		for (int j = 2; j < 25; j += 2)
		{
			if (this->a[i][j] == 'X')
			{
				gotoxy(i, j,COLOR_RED+COLOR_WHITE_BACKGROUND);
				cout << this->a[i][j];
			}
			else if (this->a[i][j] == 'O')
			{
				gotoxy(i, j, COLOR_BLUE + COLOR_WHITE_BACKGROUND);
				cout << this->a[i][j];
			}
		}
	}
	return *this;
}

board board::save()
{
	board temp;
	temp.pr_x = pr_x;
	temp.pr_y = pr_y;
	temp.y = y;
	temp.turn = turn;
	temp.turn_back = turn_back;
	temp.x = x;
	temp._o = _o;
	temp._x = _x;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			temp.a[i][j] = this->a[i][j];
		}
	}
	for (int i = 0; i < 6; i++)
	{
		temp.line[i] = line[i];
	}
	return temp;
}


