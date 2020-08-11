#include "find_x_y.h"


void findFirstLast(Move &a, Move &b, char board[12][11])
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