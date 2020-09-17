#include "Evaluate_Board.h"



void Evaluate_Board::findFirstLast(Move& a, Move& b, char board[12][11])
{
	// tim hang 
	int check = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 11; j++) {
			if (board[i][j] != '_') {
				a.row = i;
				check = 1;
				break;
			}
		}
		if (check == 1) break;
	}

	// tim cot cua 
	check = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 11; j++) {
			if (board[j][i] != '_') {
				check = 1;
				a.col = i;
				break;
			}
		}
		if (check == 1) break;
	}
	// tim hang kia
	check = 0;
	for (int i = 11; i >= 0; i--) {
		for (int j = 0; j < 11; j++) {
			if (board[i][j] != '_') {
				check = 1;
				b.row = i;
			}
		}
		if (check == 1) break;
	}
	// tim cot kia
	check = 0;
	for (int i = 10; i >= 0; i--) {
		for (int j = 0; j < 11; j++) {
			if (board[j][i] != '_') {
				check = 1;
				b.col = i;
			}
		}
		if (check == 1) break;
	}
}

// ok .. xxxxx
int Evaluate_Board::FiveInRow(char board[12][11], char xo, Move a, Move b)
{
	// hang ngang
	int dem1, dem2;
	int x, y, x1, y1, test;

	// hang ngang, hang doc
	for (int i = a.row; i <= b.row; i++) {
		for (int j = a.col; j <= b.col; j++) {
			// cho hang ngang
			if (j < 7) {
				if ((board[i][j] == xo) && (board[i][j + 1] == xo) && (board[i][j + 2] == xo) && (board[i][j + 3] == xo) && (board[i][j + 4] == xo)) return 1;
			}
			// cho hang doc
			if (i < 8) {
				if ((board[i][j] == xo) && (board[i + 1][j] == xo) && (board[i + 2][j] == xo) && (board[i + 3][j] == xo) && (board[i + 4][j] == xo)) return 1;
			}
		}
	}
	// duong cheo tu trai qua phai
	if ((b.col - a.row) > (b.row - a.col)) test = b.col - a.row; else test = b.row - a.col;

	for (int i = 0; i <= test; i++) {
		x = i;
		y = 0;

		while ((x <= 7) && (y <= 6)) {
			if ((board[x][y] == xo) && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == xo)) return 1;
			if ((board[y][x] == xo) && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == xo)) return 1;
			x++;
			y++;
		}
	}

	// duong cheo tu phai qua trai
	if ((a.col + a.row) < (b.col - b.row)) test = a.col + a.row; else test = b.col - b.row;

	for (int i = 11; i >= test; i--) {
		x = i;
		y = 0;
		x1 = 11;
		y1 = 11 - x;
		while ((x >= 4) && (y <= 6)) {
			if ((board[x][y] == xo) && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == xo)) return 1;
			if ((board[x1][y1] == xo) && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == xo)) return 1;
			x--;
			y++;
			x1--;
			y1++;
		}
	}

	return 0;
}

// ok .. _xxxx_
int Evaluate_Board::LiveFour(char board[12][11], char xo, Move a, Move b) {

	// hang ngang
	int dem1 = 0, dem2 = 0;
	int x, y, x1, y1, test;
	Move n, m;

	if (a.row > 0) n.row = a.row - 1; else n.row = a.row;
	if (a.col > 0) n.col = a.col - 1; else n.col = a.col;

	if (b.row < 11) m.row = b.row + 1; else m.row = b.row;
	if (b.col < 10) m.col = b.col + 1; else m.col = b.col;

	// hang ngang va hang doc
	for (int i = n.row; i < m.row; i++) {
		for (int j = n.col; j < m.col; j++) {
			// cho hang nhang
			if (j <= 5) {
				if ((board[i][j] == '_') && (board[i][j + 1] == xo) && (board[i][j + 2] == xo) && (board[i][j + 3] == xo) && (board[i][j + 4] == xo) && (board[i][j + 5] == '_')) return 1;
			}
			// cho hang doc
			if (i <= 6) {
				if ((board[i][j] == '_') && (board[i + 1][j] == xo) && (board[i + 2][j] == xo) && (board[i + 3][j] == xo) && (board[i + 4][j] == xo) && (board[i + 5][j] == '_')) return 1;
			}
		}
	}

	// duong cheo tu trai qua phai
	if ((b.col - a.row) > (b.row - a.col)) test = b.col - a.row; else test = b.row - a.col;

	for (int i = 0; i < test; i++) {
		x = i;
		y = 0;
		while ((x <= 6) && (y <= 5)) {
			if ((board[x][y] == '_') && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == xo) && (board[x + 5][y + 5] == '_')) {
				return 1;
			}
			if ((board[y][x] == '_') && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == xo) && (board[y + 5][x + 5] == '_')) return 1;
			x++;
			y++;
		}
	}

	// duong cheo tu phai qua trai
	if ((a.col + a.row) < (b.col - b.row)) test = a.col + a.row; else test = b.col - b.row;

	for (int i = 11; i >= test; i--) {
		x = i;
		y = 0;
		x1 = 11;
		y1 = 11 - x;
		while ((x >= 5) && (y <= 5)) {
			if ((board[x][y] == '_') && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == xo) && (board[x - 5][y + 5] == '_')) {
				return 1;
			}
			if ((board[x1][y1] == '_') && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == xo) && (board[x1 - 5][y1 + 5] == '_')) return 1;
			x--;
			y++;
			x1--;
			y1++;
		}
	}

	return 0;
}

// ok .. oxxxx_ xx_xx .. x_xxx .. xxx_x ..
int Evaluate_Board::DeadFour(char board[12][11], char xo, Move a, Move b) {

	// hang ngang
	int dem1 = 0, dem2 = 0, count = 0;
	int x, y, x1, y1, test;
	char ng_ox;
	Move n, m;

	if (a.row > 0) n.row = a.row - 1; else n.row = a.row;
	if (a.col > 0) n.col = a.col - 1; else n.col = a.col;

	if (b.row < 11) m.row = b.row + 1; else m.row = b.row;
	if (b.col < 10) m.col = b.col + 1; else m.col = b.col;

	if (xo == 'x') ng_ox = 'o'; else ng_ox = 'x';

	// hang ngang va hang doc
	for (int i = n.row; i < m.row; i++) {
		for (int j = n.col; j < m.col; j++) {
			// cho hang nhang
			if (j <= 5) {
				// oxxxx_
				if ((board[i][j] == ng_ox) && (board[i][j + 1] == xo) && (board[i][j + 2] == xo) && (board[i][j + 3] == xo) && (board[i][j + 4] == xo) && (board[i][j + 5] == '_')) count++;
				// _xxxxo
				if ((board[i][j] == '_') && (board[i][j + 1] == xo) && (board[i][j + 2] == xo) && (board[i][j + 3] == xo) && (board[i][j + 4] == xo) && (board[i][j + 5] == ng_ox)) count++;

				//  xxx_x
				if ((board[i][j] == xo) && (board[i][j + 1] == xo) && (board[i][j + 2] == xo) && (board[i][j + 3] == '_') && (board[i][j + 4] == xo)) count++;
				// x_xxx
				if ((board[i][j] == xo) && (board[i][j + 1] == '_') && (board[i][j + 2] == xo) && (board[i][j + 3] == xo) && (board[i][j + 4] == xo)) count++;

				//  xx_xx
				if ((board[i][j] == xo) && (board[i][j + 1] == xo) && (board[i][j + 2] == '_') && (board[i][j + 3] == xo) && (board[i][j + 4] == xo)) count++;
			}
			// cho hang doc
			if (i <= 6) {
				// oxxxx_
				if ((board[i][j] == ng_ox) && (board[i + 1][j] == xo) && (board[i + 2][j] == xo) && (board[i + 3][j] == xo) && (board[i + 4][j] == xo) && (board[i + 5][j] == '_')) count++;
				// _xxxxo
				if ((board[i][j] == '_') && (board[i + 1][j] == xo) && (board[i + 2][j] == xo) && (board[i + 3][j] == xo) && (board[i + 4][j] == xo) && (board[i + 5][j] == ng_ox)) count++;

				// xxx_x
				if ((board[i][j] == xo) && (board[i + 1][j] == xo) && (board[i + 2][j] == xo) && (board[i + 3][j] == '_') && (board[i + 4][j] == xo)) count++;
				// x_xxx
				if ((board[i][j] == xo) && (board[i + 1][j] == '_') && (board[i + 2][j] == xo) && (board[i + 3][j] == xo) && (board[i + 4][j] == xo)) count++;

				// xx_xx
				if ((board[i][j] == xo) && (board[i + 1][j] == xo) && (board[i + 2][j] == '_') && (board[i + 3][j] == xo) && (board[i + 4][j] == xo)) count++;

			}
		}
	}

	// duong cheo tu trai qua phai
	if ((b.col - a.row) > (b.row - a.col)) test = b.col - a.row; else test = b.row - a.col;
	for (int i = 0; i < test; i++) {
		x = i;
		y = 0;
		while ((x <= 6) && (y <= 5)) {
			// oxxxx_
			if ((board[x][y] == ng_ox) && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == xo) && (board[x + 5][y + 5] == '_')) {
				if (i == 0) dem1++;
				count++;
			}
			// _xxxxo
			if ((board[x][y] == xo) && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == xo) && (board[x + 5][y + 5] == ng_ox)) {
				if (i == 0) dem1++;
				count++;
			}

			// x_xxx
			if ((board[x][y] == xo) && (board[x + 1][y + 1] == '_') && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == xo)) {
				if (i == 0) dem1++;
				count++;
			}
			// xxx_x
			if ((board[x][y] == xo) && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == '_') && (board[x + 4][y + 4] == xo)) {
				if (i == 0) dem1++;
				count++;
			}

			// xx_xx
			if ((board[x][y] == xo) && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == '_') && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == xo)) {
				if (i == 0) dem1++;
				count++;
			}

			// mat duoi
			   // oxxxx_
			if ((board[y][x] == ng_ox) && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == xo) && (board[y + 5][x + 5] == '_')) count++;
			// _xxxxo
			if ((board[y][x] == '_') && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == xo) && (board[y + 5][x + 5] == ng_ox)) count++;

			// xxx_x
			if ((board[y][x] == xo) && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == '_') && (board[y + 4][x + 4] == xo)) count++;
			// xxx_x
			if ((board[y][x] == xo) && (board[y + 1][x + 1] == '_') && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == xo)) count++;

			// xx_xx
			if ((board[y][x] == xo) && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == '_') && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == xo)) count++;
			x++;
			y++;
		}
	}
	// duong cheo tu phai qua trai
	if ((a.col + a.row) < (b.col - b.row)) test = a.col + a.row; else test = b.col - b.row;
	for (int i = 11; i >= test; i--) {
		x = i;
		y = 0;
		x1 = 11;
		y1 = 11 - x;
		while ((x >= 5) && (y <= 5)) {
			// oxxxx_
			if ((board[x][y] == ng_ox) && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == xo) && (board[x - 5][y + 5] == '_')) {
				if (i == 11) dem2++;
				count++;
			}
			// _xxxxo
			if ((board[x][y] == '_') && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == xo) && (board[x - 5][y + 5] == ng_ox)) {
				if (i == 11) dem2++;
				count++;
			}

			// xxx_x
			if ((board[x][y] == xo) && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == '_') && (board[x - 4][y + 4] == xo)) {
				if (i == 11) dem2++;
				count++;
			}
			// x_xxx
			if ((board[x][y] == xo) && (board[x - 1][y + 1] == '_') && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == xo)) {
				if (i == 11) dem2++;
				count++;
			}

			// xx_xx
			if ((board[x][y] == xo) && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == '_') && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == xo)) {
				if (i == 11) dem2++;
				count++;
			}
			//mat khac
			   // oxxxx_
			if ((board[x1][y1] == ng_ox) && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == xo) && (board[x1 - 5][y1 + 5] == '_')) count++;
			// _xxxxo
			if ((board[x1][y1] == '_') && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == xo) && (board[x1 - 5][y1 + 5] == ng_ox)) count++;

			// xxx_x
			if ((board[x1][y1] == xo) && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == '_') && (board[x1 - 4][y1 + 4] == xo)) count++;
			// x_xxx
			if ((board[x1][y1] == xo) && (board[x1 - 1][y1 + 1] == '_') && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == xo)) count++;

			// xx_xx
			if ((board[x1][y1] == xo) && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == '_') && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == xo)) count++;

			x--;
			y++;
			x1--;
			y1++;
		}
	}

	return count - dem1 - dem2;
}

// ok .. _xxx_
int Evaluate_Board::LiveThree(char board[12][11], char xo, Move a, Move b)
{
	// hang ngang
	int dem1 = 0, dem2 = 0, count = 0;
	int x, y, x1, y1, test;
	Move n, m;

	if (a.row > 0) n.row = a.row - 1; else n.row = a.row;
	if (a.col > 0) n.col = a.col - 1; else n.col = a.col;

	if (b.row < 11) m.row = b.row + 1; else m.row = b.row;
	if (b.col < 10) m.col = b.col + 1; else m.col = b.col;

	// hang ngang hang doc
	for (int i = n.row; i < m.row; i++) {
		for (int j = n.col; j < m.col; j++) {
			// cho hang nhang
			if (j <= 6) {
				//_xxx_
				if ((board[i][j] == '_') && (board[i][j + 1] == xo) && (board[i][j + 2] == xo) && (board[i][j + 3] == xo) && (board[i][j + 4] == '_')) count++;
				if (j <= 5) {
					// _xx_x_
					if ((board[i][j] == '_') && (board[i][j + 1] == xo) && (board[i][j + 2] == xo) && (board[i][j + 3] == '_') && (board[i][j + 4] == xo) && (board[i][j + 5] == '_')) count++;
					// _x_xx_
					if ((board[i][j] == '_') && (board[i][j + 1] == xo) && (board[i][j + 2] == '_') && (board[i][j + 3] == xo) && (board[i][j + 4] == xo) && (board[i][j + 5] == '_')) count++;
				}
			}
			// cho hang doc
			if (i <= 7) {
				//_xxx_
				if ((board[i][j] == '_') && (board[i + 1][j] == xo) && (board[i + 2][j] == xo) && (board[i + 3][j] == xo) && (board[i + 4][j] == '_')) count++;
				if (i <= 6) {
					// _xx_x_
					if ((board[i][j] == '_') && (board[i + 1][j] == xo) && (board[i + 2][j] == xo) && (board[i + 3][j] == '_') && (board[i + 4][j] == xo) && (board[i + 5][j] == '_')) count++;
					// _x_xx_
					if ((board[i][j] == '_') && (board[i + 1][j] == xo) && (board[i + 2][j] == '_') && (board[i + 3][j] == xo) && (board[i + 4][j] == xo) && (board[i + 5][j] == '_')) count++;
				}
			}
		}
	}
	// duong cheo tu trai qua phai
	if ((b.col - a.row) > (b.row - a.col)) test = b.col - a.row; else test = b.row - a.col;
	for (int i = 0; i < test; i++) {
		x = i;
		y = 0;
		while ((x <= 7) && (y <= 6)) {
			// mat tren
			  //_xxx_
			if ((board[x][y] == '_') && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == '_')) {
				count++;
				if (x == y) dem1++;
			}
			if ((x <= 6) && (y <= 5)) {
				// _xx_x_
				if ((board[x][y] == '_') && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == '_') && (board[x + 4][y + 4] == xo) && (board[x + 5][y + 5] == '_')) {
					count++;
					if (x == y) dem1++;
				}
				// _x_xx_
				if ((board[x][y] == '_') && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == '_') && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == xo) && (board[x + 5][y + 5] == '_')) {
					count++;
					if (x == y) dem1++;
				}
			}
			// mat duoi
			//_xxx_
			if ((board[y][x] == '_') && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == '_')) count++;
			if ((x <= 6) && (y <= 5)) {
				// _xx_x_
				if ((board[y][x] == '_') && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == '_') && (board[y + 4][x + 4] == xo) && (board[y + 5][x + 5] == '_')) count++;
				// _x_xx_
				if ((board[y][x] == '_') && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == '_') && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == xo) && (board[y + 5][x + 5] == '_')) count++;
			}
			x++;
			y++;
		}
	}
	// duong cheo tu phai qua trai
	if ((a.col + a.row) < (b.col - b.row)) test = a.col + a.row; else test = b.col - b.row;
	for (int i = 11; i >= test; i--) {
		x = i;
		y = 0;
		x1 = 11;
		y1 = 11 - x;
		while ((x >= 4) && (y <= 6)) {
			// mat tren
			  // _xxx_
			if ((board[x][y] == '_') && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == '_'))
			{
				count++;
				if (x == 11) dem1++;
			}
			if ((x >= 5) && (y <= 5)) {
				// _xx_x_
				if ((board[x][y] == '_') && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == '_') && (board[x - 4][y + 4] == xo) && (board[x - 5][y + 5] == '_'))
				{
					count++;
					if (x == 11) dem1++;
				}
				// _x_xx_
				if ((board[x][y] == '_') && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == '_') && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == xo) && (board[x - 5][y + 5] == '_'))
				{
					count++;
					if (x == 11) dem1++;
				}
			}
			// mat duoi
			//_xxx_
			if ((board[x1][y1] == '_') && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == '_')) count++;
			if ((x1 >= 5) && (y1 <= 5)) {
				// _xx_x_
				if ((board[x1][y1] == '_') && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == '_') && (board[x1 - 4][y1 + 4] == xo) && (board[x1 - 5][y1 + 5] == '_')) count++;
				// _x_xx_
				if ((board[x1][y1] == '_') && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == '_') && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == xo) && (board[x1 - 5][y1 + 5] == '_')) count++;
			}
			x--;
			y++;
			x1--;
			y1++;
		}
	}

	return (count - dem1);
}

int Evaluate_Board::JliveThree(char board[12][11], char xo, Move a, Move b)
{
	int dem1 = 0, dem2 = 0, count = 0;
	int x, y, x1, y1, test;

	Move n, m;

	if (a.row > 0) n.row = a.row - 1; else n.row = a.row;
	if (a.col > 0) n.col = a.col - 1; else n.col = a.col;

	if (b.row < 11) m.row = b.row + 1; else m.row = b.row;
	if (b.col < 10) m.col = b.col + 1; else m.col = b.col;

	// hang ngang hang doc
	for (int i = n.row; i < m.row; i++) {
		for (int j = n.col; j < m.col; j++) {
			// cho hang nhang
			if (j <= 6) {
				//xx__x
				if ((board[i][j] == xo) && (board[i][j + 1] == xo) && (board[i][j + 2] == '_') && (board[i][j + 3] == '_') && (board[i][j + 4] == xo)) count++;
				//x__xx
				if ((board[i][j] == xo) && (board[i][j + 1] == '_') && (board[i][j + 2] == '_') && (board[i][j + 3] == xo) && (board[i][j + 4] == xo)) count++;

				// x_x_x
				if ((board[i][j] == xo) && (board[i][j + 1] == '_') && (board[i][j + 2] == xo) && (board[i][j + 3] == '_') && (board[i][j + 4] == xo)) count++;
			}
			// cho hang doc
			if (i <= 7) {
				//x__xx
				if ((board[i][j] == xo) && (board[i + 1][j] == '_') && (board[i + 2][j] == '_') && (board[i + 3][j] == xo) && (board[i + 4][j] == xo)) count++;
				// xx__x
				if ((board[i][j] == xo) && (board[i + 1][j] == xo) && (board[i + 2][j] == '_') && (board[i + 3][j] == '_') && (board[i + 4][j] == xo)) count++;

				// x_x_x
				if ((board[i][j] == xo) && (board[i + 1][j] == '_') && (board[i + 2][j] == xo) && (board[i + 3][j] == '_') && (board[i + 4][j] == xo)) count++;
			}
		}
	}
	// duong cheo tu trai qua phai
	if ((b.col - a.row) > (b.row - a.col)) test = b.col - a.row; else test = b.row - a.col;
	for (int i = 0; i < test; i++) {
		x = i;
		y = 0;
		while ((x <= 7) && (y <= 6)) {
			// mat tren
			//x__xx
			if ((board[x][y] == xo) && (board[x + 1][y + 1] == '_') && (board[x + 2][y + 2] == '_') && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == xo)) {
				count++;
				if (i == 0) dem1++;
			}
			//xx__x
			if ((board[x][y] == xo) && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == '_') && (board[x + 3][y + 3] == '_') && (board[x + 4][y + 4] == xo)) {
				count++;
				if (i == 0) dem1++;

			}
			// x_x_x
			if ((board[x][y] == xo) && (board[x + 1][y + 1] == '_') && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == '_') && (board[x + 4][y + 4] == xo)) {
				count++;
				if (i == 0) dem1++;
			}
			// mat duoi
			//x__xx
			if ((board[y][x] == xo) && (board[y + 1][x + 1] == '_') && (board[y + 2][x + 2] == '_') && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == xo)) count++;
			// xx__x
			if ((board[y][x] == xo) && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == '_') && (board[y + 3][x + 3] == '_') && (board[y + 4][x + 4] == xo)) count++;
			// x_x_x
			if ((board[y][x] == xo) && (board[y + 1][x + 1] == '_') && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == '_') && (board[y + 4][x + 4] == xo)) count++;
			x++;
			y++;
		}
	}
	// duong cheo tu phai qua trai
	if ((a.col + a.row) < (b.col - b.row)) test = a.col + a.row; else test = b.col - b.row;
	for (int i = 11; i >= test; i--) {
		x = i;
		y = 0;
		x1 = 11;
		y1 = 11 - x;
		while ((x >= 4) && (y <= 6)) {
			// mat tren
			 // x__xx
			if ((board[x][y] == xo) && (board[x - 1][y + 1] == '_') && (board[x - 2][y + 2] == '_') && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == xo))
			{
				count++;
				if (i == 11) dem1++;
			}
			// xx__x
			if ((board[x][y] == xo) && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == '_') && (board[x - 3][y + 3] == '_') && (board[x - 4][y + 4] == xo))
			{
				count++;
				if (i == 11) dem1++;
			}

			// x_x_x
			if ((board[x][y] == xo) && (board[x - 1][y + 1] == '_') && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == '_') && (board[x - 4][y + 4] == xo))
			{
				count++;
				if (i == 11) dem1++;
			}
			// mat duoi
			//x__xx
			if ((board[x1][y1] == xo) && (board[x1 - 1][y1 + 1] == '_') && (board[x1 - 2][y1 + 2] == '_') && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == xo)) count++;
			// xx__x
			if ((board[x1][y1] == xo) && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == '_') && (board[x1 - 3][y1 + 3] == '_') && (board[x1 - 4][y1 + 4] == xo)) count++;

			// x_x_x
			if ((board[x1][y1] == xo) && (board[x1 - 1][y1 + 1] == '_') && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == '_') && (board[x1 - 4][y1 + 4] == xo)) count++;
			x--;
			y++;
			x1--;
			y1++;
		}
	}

	return (count - dem1);
}
// ok 
int Evaluate_Board::DeadThree(char board[12][11], char xo, Move a, Move b)
{
	// hang ngang
	int dem1 = 0, dem2 = 0, count = 0;
	int x, y, x1, y1, test;
	char ng_ox;
	Move n, m;

	if (a.row > 0) n.row = a.row - 1; else n.row = a.row;
	if (a.col > 0) n.col = a.col - 1; else n.col = a.col;

	if (b.row < 11) m.row = b.row + 1; else m.row = b.row;
	if (b.col < 10) m.col = b.col + 1; else m.col = b.col;
	if (xo == 'x') ng_ox = 'o'; else ng_ox = 'x';

	// hang ngang hang doc
	for (int i = n.row; i < m.row; i++) {
		for (int j = n.col; j < m.col; j++) {
			// cho hang ngang
			if (j <= 6) {
				if (j <= 5) {
					// _xx_x_
					if ((board[i][j] == '_') && (board[i][j + 1] == xo) && (board[i][j + 2] == xo) && (board[i][j + 3] == '_') && (board[i][j + 4] == xo) && (board[i][j + 5] == '_')) count++;
					// _x_xx_
					if ((board[i][j] == '_') && (board[i][j + 1] == xo) && (board[i][j + 2] == '_') && (board[i][j + 3] == xo) && (board[i][j + 4] == xo) && (board[i][j + 4] == '_')) count++;
				}
				//oxxx_
				if ((board[i][j] == ng_ox) && (board[i][j + 1] == xo) && (board[i][j + 2] == xo) && (board[i][j + 3] == xo) && (board[i][j + 4] == '_')) count++;
				//_xxxo
				if ((board[i][j] == '_') && (board[i][j + 1] == xo) && (board[i][j + 2] == xo) && (board[i][j + 3] == xo) && (board[i][j + 4] == ng_ox)) count++;

				//oxx_x
				if ((board[i][j] == ng_ox) && (board[i][j + 1] == xo) && (board[i][j + 2] == xo) && (board[i][j + 3] == '_') && (board[i][j + 4] == xo)) count++;
				// x_xxo
				if ((board[i][j] == xo) && (board[i][j + 1] == '_') && (board[i][j + 2] == xo) && (board[i][j + 3] == xo) && (board[i][j + 4] == ng_ox)) count++;

				// xx__x
				if ((board[i][j] == xo) && (board[i][j + 1] == xo) && (board[i][j + 2] == '_') && (board[i][j + 3] == '_') && (board[i][j + 4] == xo)) count++;
				// x__xx
				if ((board[i][j] == xo) && (board[i][j + 1] == '_') && (board[i][j + 2] == '_') && (board[i][j + 3] == xo) && (board[i][j + 4] == xo)) count++;

				// x_x_x
				if ((board[i][j] == xo) && (board[i][j + 1] == '_') && (board[i][j + 2] == xo) && (board[i][j + 3] == '_') && (board[i][j + 4] == xo)) count++;
			}
			// cho hang doc
			if (i <= 7) {
				// xx_x_
				if ((board[i][j] == xo) && (board[i + 1][j] == xo) && (board[i + 2][j] == '_') && (board[i + 3][j] == xo) && (board[i + 4][j] == '_')) count++;
				// _x_xx
				if ((board[i][j] == '_') && (board[i + 1][j] == xo) && (board[i + 2][j] == '_') && (board[i + 3][j] == xo) && (board[i + 4][j] == xo)) count++;

				//oxxx_
				if ((board[i][j] == ng_ox) && (board[i + 1][j] == xo) && (board[i + 2][j] == xo) && (board[i + 3][j] == xo) && (board[i + 4][j] == '_')) count++;
				//_xxxo
				if ((board[i][j] == '_') && (board[i + 1][j] == xo) && (board[i + 2][j] == xo) && (board[i + 3][j] == xo) && (board[i + 4][j] == ng_ox)) count++;

				//oxx_x
				if ((board[i][j] == ng_ox) && (board[i + 1][j] == xo) && (board[i + 2][j] == xo) && (board[i + 3][j] == '_') && (board[i + 4][j] == xo)) count++;
				// x_xxo
				if ((board[i][j] == xo) && (board[i + 1][j] == '_') && (board[i + 2][j] == xo) && (board[i + 3][j] == xo) && (board[i + 4][j] == ng_ox)) count++;

				// xx__x
				if ((board[i][j] == xo) && (board[i + 1][j] == xo) && (board[i + 2][j] == '_') && (board[i + 3][j] == '_') && (board[i + 4][j] == xo)) count++;
				// x__xx
				if ((board[i][j] == xo) && (board[i + 1][j] == '_') && (board[i + 2][j] == '_') && (board[i + 3][j] == xo) && (board[i + 4][j] == xo)) count++;

				// x_x_x
				if ((board[i][j] == xo) && (board[i + 1][j] == '_') && (board[i + 2][j] == xo) && (board[i + 3][j] == '_') && (board[i + 4][j] == xo)) count++;
			}
		}
	}
	// duong cheo tu trai qua phai
	if ((b.col - a.row) > (b.row - a.col)) test = b.col - a.row; else test = b.row - a.col;
	for (int i = 0; i < test; i++) {
		x = i;
		y = 0;
		while ((x <= 7) && (y <= 6)) {
			// mat tren
			  //x_xx_
			if ((board[x][y] == xo) && (board[x + 1][y + 1] == '_') && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == '_')) {
				count++;
				if (x == 0) dem1++;
			}
			//_xx_x
			if ((board[x][y] == '_') && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == '_') && (board[x + 4][y + 4] == xo)) {
				count++;
				if (x == 0) dem1++;
			}

			//oxxx_
			if ((board[x][y] == ng_ox) && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == '_')) {
				count++;
				if (x == 0) dem1++;
			}
			//_xxxo
			if ((board[x][y] == '_') && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == ng_ox)) {
				count++;
				if (x == 0) dem1++;
			}

			//oxx_x
			if ((board[x][y] == ng_ox) && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == '_') && (board[x + 4][y + 4] == xo)) {
				count++;
				if (x == 0) dem1++;
			}
			// x_xxo
			if ((board[x][y] == xo) && (board[x + 1][y + 1] == '_') && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == ng_ox)) {
				count++;
				if (x == 0) dem1++;
			}

			// ox_xx
			if ((board[x][y] == ng_ox) && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == '_') && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == xo)) {
				count++;
				if (x == 0) dem1++;
			}
			// xx_xo
			if ((board[x][y] == xo) && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == '_') && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == ng_ox)) {
				count++;
				if (x == 0) dem1++;
			}

			// xx__x
			if ((board[x][y] == xo) && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == '_') && (board[x + 3][y + 3] == '_') && (board[x + 4][y + 4] == xo)) {
				count++;
				if (x == 0) dem1++;
			}
			// x__xx
			if ((board[x][y] == xo) && (board[x + 1][y + 1] == '_') && (board[x + 2][y + 2] == '_') && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == xo)) {
				count++;
				if (x == 0) dem1++;
			}

			// x_x_x
			if ((board[x][y] == xo) && (board[x + 1][y + 1] == '_') && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == '_') && (board[x + 4][y + 4] == xo)) {
				count++;
				if (x == 0) dem1++;
			}

			// mat duoi
			 //x_xx_
			if ((board[y][x] == xo) && (board[y + 1][x + 1] == '_') && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == '_')) {
				count++;
				if (x == 0) dem1++;
			}
			//_xx_x
			if ((board[y][x] == '_') && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == '_') && (board[y + 4][x + 4] == xo)) {
				count++;
				if (x == 0) dem1++;
			}

			//oxxx_
			if ((board[y][x] == ng_ox) && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == '_')) {
				count++;
				if (x == 0) dem1++;
			}
			//_xxxo
			if ((board[y][x] == '_') && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == ng_ox)) {
				count++;
				if (x == 0) dem1++;
			}

			//oxx_x
			if ((board[y][x] == ng_ox) && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == '_') && (board[y + 4][x + 4] == xo)) {
				count++;
				if (x == 0) dem1++;
			}
			// x_xxo
			if ((board[y][x] == xo) && (board[y + 1][x + 1] == '_') && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == ng_ox)) {
				count++;
				if (x == 0) dem1++;
			}

			// ox_xx
			if ((board[y][x] == ng_ox) && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == '_') && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == xo)) {
				count++;
				if (x == 0) dem1++;
			}
			// xx_xo
			if ((board[y][x] == xo) && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == '_') && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == ng_ox)) {
				count++;
				if (x == 0) dem1++;
			}

			// xx__x
			if ((board[y][x] == xo) && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == '_') && (board[y + 3][x + 3] == '_') && (board[y + 4][x + 4] == xo)) {
				count++;
				if (x == 0) dem1++;
			}
			// x__xx
			if ((board[y][x] == xo) && (board[y + 1][x + 1] == '_') && (board[y + 2][x + 2] == '_') && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == xo)) {
				count++;
				if (x == 0) dem1++;
			}

			// x_x_x
			if ((board[y][x] == xo) && (board[y + 1][x + 1] == '_') && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == '_') && (board[y + 4][x + 4] == xo)) {
				count++;
				if (x == 0) dem1++;
			}
			x++;
			y++;
		}
	}
	// duong cheo tu phai qua trai
	if ((a.col + a.row) < (b.col - b.row)) test = a.col + a.row; else test = b.col - b.row;
	for (int i = 11; i >= test; i--) {
		x = i;
		y = 0;
		x1 = 11;
		y1 = 11 - x;
		while ((x >= 4) && (y <= 6)) {
			// mat tren
			  // xx_x_
			if ((board[x][y] == xo) && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == '_') && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == '_'))
			{
				count++;
				if (x == 11) dem1++;
			}
			// _x_xx
			if ((board[x][y] == '_') && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == '_') && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == xo))
			{
				count++;
				if (x == 11) dem1++;
			}

			//oxxx_
			if ((board[x][y] == ng_ox) && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == '_'))
			{
				count++;
				if (x == 11) dem1++;
			}
			// _xxxo
			if ((board[x][y] == '_') && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == ng_ox))
			{
				count++;
				if (x == 11) dem1++;
			}

			//oxx_x
			if ((board[x][y] == ng_ox) && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == '_') && (board[x - 4][y + 4] == xo))
			{
				count++;
				if (x == 11) dem1++;
			}
			// x_xxo
			if ((board[x][y] == xo) && (board[x - 1][y + 1] == '_') && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == ng_ox))
			{
				count++;
				if (x == 11) dem1++;
			}

			// xx__x
			if ((board[x][y] == xo) && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == '_') && (board[x - 3][y + 3] == '_') && (board[x - 4][y + 4] == xo))
			{
				count++;
				if (x == 11) dem1++;
			}
			// x__xx
			if ((board[x][y] == xo) && (board[x - 1][y + 1] == '_') && (board[x - 2][y + 2] == '_') && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == xo))
			{
				count++;
				if (x == 11) dem1++;
			}
			// x_x_x
			if ((board[x][y] == xo) && (board[x - 1][y + 1] == '_') && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == '_') && (board[x - 4][y + 4] == xo))
			{
				count++;
				if (x == 11) dem1++;
			}
			// mat duoi
					// xx_x_
			if ((board[x1][y1] == xo) && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == '_') && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == '_')) count++;
			// _x_xx
			if ((board[x1][y1] == '_') && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == '_') && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == xo)) count++;
			//oxxx_
			if ((board[x1][y1] == ng_ox) && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == '_')) count++;
			// _xxxo
			if ((board[x1][y1] == '_') && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == ng_ox)) count++;
			//oxx_x
			if ((board[x1][y1] == ng_ox) && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == '_') && (board[x1 - 4][y1 + 4] == xo)) count++;
			// x_xxo
			if ((board[x1][y1] == xo) && (board[x1 - 1][y1 + 1] == '_') && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == ng_ox)) count++;
			// xx__x
			if ((board[x1][y1] == xo) && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == '_') && (board[x1 - 3][y1 + 3] == '_') && (board[x1 - 4][y1 + 4] == xo)) count++;
			// x__xx
			if ((board[x1][y1] == xo) && (board[x1 - 1][y1 + 1] == '_') && (board[x1 - 2][y1 + 2] == '_') && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == xo)) count++;
			// x_x_x
			if ((board[x1][y1] == xo) && (board[x1 - 1][y1 + 1] == '_') && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == '_') && (board[x1 - 4][y1 + 4] == xo)) count++;
			x--;
			y++;
			x1--;
			y1++;
		}
	}

	return (count - dem1);
}
// ok 
int Evaluate_Board::LiveTwo(char board[12][11], char xo, Move a, Move b) {
	// hang ngang
	int dem1 = 0, dem2 = 0, count = 0;
	int x, y, x1, y1, test;
	// hang ngang hang doc
	Move n, m;

	if (a.row > 0) n.row = a.row - 1; else n.row = a.row;
	if (a.col > 0) n.col = a.col - 1; else n.col = a.col;

	if (b.row < 11) m.row = b.row + 1; else m.row = b.row;
	if (b.col < 10) m.col = b.col + 1; else m.col = b.col;

	for (int i = n.row; i < m.row; i++) {
		for (int j = n.col; j < m.col; j++) {
			// cho hang nhang
			if (j <= 7) {
				//_xx_
				if ((board[i][j] == '_') && (board[i][j + 1] == xo) && (board[i][j + 2] == xo) && (board[i][j + 3] == '_')) count++;
				//x_x_
				if ((board[i][j] == xo) && (board[i][j + 1] == '_') && (board[i][j + 2] == xo) && (board[i][j + 3] == '_')) count++;
			}
			// cho hang doc
			if (i <= 8) {
				//_xx_
				if ((board[i][j] == '_') && (board[i + 1][j] == xo) && (board[i + 2][j] == xo) && (board[i + 3][j] == '_')) count++;
				// x_x_
				if ((board[i][j] == xo) && (board[i + 1][j] == '_') && (board[i + 2][j] == xo) && (board[i + 3][j] == '_')) count++;
			}
		}
	}
	// duong cheo tu trai qua phai
	if ((b.col - a.row) > (b.row - a.col)) test = b.col - a.row; else test = b.row - a.col;
	for (int i = 0; i < test; i++) {
		x = i;
		y = 0;
		while ((x <= 8) && (y <= 7)) {
			// mat tren
			  //_xx_
			if ((board[x][y] == '_') && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == '_')) {
				count++;
				if (i == 0) dem1++;
			}
			// x_x_
			if ((board[x][y] == xo) && (board[x + 1][y + 1] == '_') && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == '_')) {
				count++;
				if (i == 0) dem1++;
			}
			// mat duoi
			//_xx_
			if ((board[y][x] == '_') && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == '_')) count++;

			//_x_x
			if ((board[y][x] == '_') && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == '_') && (board[y + 3][x + 3] == xo)) count++;

			x++;
			y++;
		}
	}
	// duong cheo tu phai qua trai
	if ((a.col + a.row) < (b.col - b.row)) test = a.col + a.row; else test = b.col - b.row;
	for (int i = 11; i >= test; i--) {
		x = i;
		y = 0;
		x1 = 11;
		y1 = 11 - x;
		while ((x >= 3) && (y <= 7)) {
			// mat tren
			 // _xx_
			if ((board[x][y] == '_') && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == '_'))
			{
				count++;
				if (i == 11) dem1++;
			}

			// x_x_
			if ((board[x][y] == xo) && (board[x - 1][y + 1] == '_') && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == '_'))
			{
				count++;
				if (i == 11) dem1++;
			}
			// mat duoi
			//_xx_
			if ((board[x1][y1] == '_') && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == '_')) count++;

			//_x_x
			if ((board[x1][y1] == '_') && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == '_') && (board[x1 - 3][y1 + 3] == xo)) count++;
			x--;
			y++;
			x1--;
			y1++;
		}
	}

	return (count - dem1);
}

int Evaluate_Board::DeadTwo(char board[12][11], char xo, Move a, Move b)
{
	// hang ngang
	int dem1 = 0, dem2 = 0, count = 0;
	int x, y, x1, y1, test;
	char ng_ox;
	Move n, m;

	if (a.row > 0) n.row = a.row - 1; else n.row = a.row;
	if (a.col > 0) n.col = a.col - 1; else n.col = a.col;

	if (b.row < 11) m.row = b.row + 1; else m.row = b.row;
	if (b.col < 10) m.col = b.col + 1; else m.col = b.col;

	if (xo == 'x') ng_ox = 'o'; else ng_ox = 'x';

	// hang ngang hang doc
	for (int i = n.row; i < m.row; i++) {
		for (int j = n.col; j < m.col; j++) {
			// cho hang nhang
			if (j <= 6) {
				//oxx__
				if ((board[i][j] == ng_ox) && (board[i][j + 1] == xo) && (board[i][j + 2] == xo) && (board[i][j + 3] == '_') && (board[i][j + 4] == '_')) count++;
				//__xxo
				if ((board[i][j] == '_') && (board[i][j + 1] == '_') && (board[i][j + 2] == xo) && (board[i][j + 3] == xo) && (board[i][j + 4] == ng_ox)) count++;

				//ox_x_
				if ((board[i][j] == ng_ox) && (board[i][j + 1] == xo) && (board[i][j + 2] == '_') && (board[i][j + 3] == xo) && (board[i][j + 4] == '_')) count++;
				// _x_xo
				if ((board[i][j] == '_') && (board[i][j + 1] == xo) && (board[i][j + 2] == '_') && (board[i][j + 3] == xo) && (board[i][j + 4] == ng_ox)) count++;

				//ox__x
				if ((board[i][j] == ng_ox) && (board[i][j + 1] == xo) && (board[i][j + 2] == '_') && (board[i][j + 3] == '_') && (board[i][j + 4] == xo)) count++;
				// x__xo
				if ((board[i][j] == xo) && (board[i][j + 1] == '_') && (board[i][j + 2] == '_') && (board[i][j + 3] == xo) && (board[i][j + 4] == ng_ox)) count++;
			}
			// cho hang doc
			if (i <= 7) {
				//oxx__
				if ((board[i][j] == ng_ox) && (board[i + 1][j] == xo) && (board[i + 2][j] == xo) && (board[i + 3][j] == '_') && (board[i + 4][j] == '_')) count++;
				// __xxo
				if ((board[i][j] == '_') && (board[i + 1][j] == '_') && (board[i + 2][j] == xo) && (board[i + 3][j] == xo) && (board[i + 4][j] == ng_ox)) count++;

				//ox_x_
				if ((board[i][j] == ng_ox) && (board[i + 1][j] == xo) && (board[i + 2][j] == '_') && (board[i + 3][j] == xo) && (board[i + 4][j] == '_')) count++;
				// _x_xo
				if ((board[i][j] == '_') && (board[i + 1][j] == xo) && (board[i + 2][j] == '_') && (board[i + 3][j] == xo) && (board[i + 4][j] == ng_ox)) count++;

				//ox__x
				if ((board[i][j] == ng_ox) && (board[i + 1][j] == xo) && (board[i + 2][j] == '_') && (board[i + 3][j] == '_') && (board[i + 4][j] == xo)) count++;
				//x__xo
				if ((board[i][j] == xo) && (board[i + 1][j] == '_') && (board[i + 2][j] == '_') && (board[i + 3][j] == xo) && (board[i + 4][j] == ng_ox)) count++;
			}
		}
	}
	// duong cheo tu trai qua phai
	if ((b.col - a.row) > (b.row - a.col)) test = b.col - a.row; else test = b.row - a.col;
	for (int i = 0; i < 12; i++) {
		x = i;
		y = 0;
		while ((x <= 7) && (y <= 6)) {
			// mat tren
			//oxx__
			if ((board[x][y] == ng_ox) && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == '_') && (board[x + 4][y + 4] == '_')) {
				count++;
				if (i == 0) dem1++;
			}
			//__xxo
			if ((board[x][y] == '_') && (board[x + 1][y + 1] == '_') && (board[x + 2][y + 2] == xo) && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == ng_ox)) {
				count++;
				if (i == 0) dem1++;
			}

			//ox_x_
			if ((board[x][y] == ng_ox) && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == '_') && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == '_')) {
				count++;
				if (i == 0) dem1++;
			}
			// _x_xo
			if ((board[x][y] == '_') && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == '_') && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == ng_ox)) {
				count++;
				if (i == 0) dem1++;
			}

			//ox__x
			if ((board[x][y] == ng_ox) && (board[x + 1][y + 1] == xo) && (board[x + 2][y + 2] == '_') && (board[x + 3][y + 3] == '_') && (board[x + 4][y + 4] == xo)) {
				count++;
				if (i == 0) dem1++;
			}
			// x__xo
			if ((board[x][y] == xo) && (board[x + 1][y + 1] == '_') && (board[x + 2][y + 2] == '_') && (board[x + 3][y + 3] == xo) && (board[x + 4][y + 4] == ng_ox)) {
				count++;
				if (i == 0) dem1++;
			}
			// mat duoi

			//oxx__
			if ((board[y][x] == ng_ox) && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == '_') && (board[y + 4][x + 4] == '_')) count++;
			//__xxo
			if ((board[y][x] == '_') && (board[y + 1][x + 1] == '_') && (board[y + 2][x + 2] == xo) && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == ng_ox)) count++;

			//ox_x_
			if ((board[y][x] == ng_ox) && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == '_') && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == '_')) count++;
			// _x_xo
			if ((board[y][x] == '_') && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == '_') && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == ng_ox)) count++;

			//ox__x
			if ((board[y][x] == ng_ox) && (board[y + 1][x + 1] == xo) && (board[y + 2][x + 2] == '_') && (board[y + 3][x + 3] == '_') && (board[y + 4][x + 4] == xo)) count++;
			// x__xo
			if ((board[y][x] == xo) && (board[y + 1][x + 1] == '_') && (board[y + 2][x + 2] == '_') && (board[y + 3][x + 3] == xo) && (board[y + 4][x + 4] == ng_ox)) count++;

			x++;
			y++;
		}
	}
	// duong cheo tu phai qua trai
	if ((a.col + a.row) < (b.col - b.row)) test = a.col + a.row; else test = b.col - b.row;
	for (int i = 11; i >= 0; i--) {
		x = i;
		y = 0;
		x1 = 11;
		y1 = 11 - x;
		while ((x >= 3) && (y <= 7)) {
			// mat tren
			//oxx__
			if ((board[x][y] == ng_ox) && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == '_') && (board[x - 4][y + 4] == '_'))
			{
				count++;
				if (i == 11) dem1++;
			}
			//__xxo
			if ((board[x][y] == '_') && (board[x - 1][y + 1] == '_') && (board[x - 2][y + 2] == xo) && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == ng_ox))
			{
				count++;
				if (i == 11) dem1++;
			}

			//ox_x_
			if ((board[x][y] == ng_ox) && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == '_') && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == '_'))
			{
				count++;
				if (i == 11) dem1++;
			}
			//_x_xo
			if ((board[x][y] == '_') && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == '_') && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == ng_ox))
			{
				count++;
				if (i == 11) dem1++;
			}

			//ox__x
			if ((board[x][y] == ng_ox) && (board[x - 1][y + 1] == xo) && (board[x - 2][y + 2] == '_') && (board[x - 3][y + 3] == '_') && (board[x - 4][y + 4] == xo))
			{
				count++;
				if (i == 11) dem1++;
			}
			//x__xo
			if ((board[x][y] == xo) && (board[x - 1][y + 1] == '_') && (board[x - 2][y + 2] == '_') && (board[x - 3][y + 3] == xo) && (board[x - 4][y + 4] == ng_ox))
			{
				count++;
				if (i == 11) dem1++;
			}

			// mat duoi
			  //oxx__
			if ((board[x1][y1] == ng_ox) && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == '_') && (board[x1 - 4][y1 + 4] == '_')) count++;
			//__xxo
			if ((board[x1][y1] == '_') && (board[x1 - 1][y1 + 1] == '_') && (board[x1 - 2][y1 + 2] == xo) && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == ng_ox)) count++;

			//ox_x_
			if ((board[x1][y1] == ng_ox) && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == '_') && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == '_')) count++;
			//_x_xo
			if ((board[x1][y1] == '_') && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == '_') && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == ng_ox)) count++;

			//ox__x
			if ((board[x1][y1] == ng_ox) && (board[x1 - 1][y1 + 1] == xo) && (board[x1 - 2][y1 + 2] == '_') && (board[x1 - 3][y1 + 3] == '_') && (board[x1 - 4][y1 + 4] == xo)) count++;
			//x__xo
			if ((board[x1][y1] == xo) && (board[x1 - 1][y1 + 1] == '_') && (board[x1 - 2][y1 + 2] == '_') && (board[x1 - 3][y1 + 3] == xo) && (board[x1 - 4][y1 + 4] == ng_ox)) count++;
			x--;
			y++;
			x1--;
			y1++;
		}
	}
	return (count - dem1);
}