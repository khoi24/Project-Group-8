#pragma once

#include "Struct.h"

class Evaluate_Board
{
public:
	static void findFirstLast(Move& a, Move& b, char board[12][11]);

	static int FiveInRow(char board[12][11], char xo, Move a, Move b);
	static int LiveFour(char board[12][11], char xo, Move a, Move b);
	static int DeadFour(char board[12][11], char xo, Move a, Move b);

	static int LiveThree(char board[12][11], char xo, Move a, Move b);
	static int DeadThree(char board[12][11], char xo, Move a, Move b);
	static int JliveThree(char board[12][11], char xo, Move a, Move b);

	static int LiveTwo(char board[12][11], char xo, Move a, Move b);
	static int DeadTwo(char board[12][11], char xo, Move a, Move b);
};

