#pragma once

#include "Evaluate_Board.h"
#include <fstream>

using namespace std;

class FindTheWay
{
public:
	bool isMovesLeft(char board[12][11]);
	int Max(int a, int b);
	int Min(int a, int b);
	int evaluate(char b[12][11], bool MM);
	bool evaluatePosition(char board[12][11], int x, int y);
	bool attackORdefense(char board[12][11]);
	int minimax(char board[12][11], int depth, bool isMax, int alpha, int beta, bool attack_OR_defense);
	static void EmptyBoard(char board[12][11]);
	Move findBestMove(char board[12][11]);
};

