#pragma once

struct Move
{
	int row, col;
};

void findFirstLast(Move &a, Move &b, char board[12][11]);