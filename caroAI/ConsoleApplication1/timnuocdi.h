#pragma once

#include<iostream>
#include <stdio.h>
#include "Evaluate.h"
#include <fstream>

struct Move
{
	int row, col;
};

char player = 'x', opponent = 'o';
Move a, b;

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

bool isMovesLeft(char board[12][11])
{
	for (int i = 0; i < 12; i++)

		for (int j = 0; j < 11; j++)

			if (board[i][j] == '_')

				return true;
	return false;
}


int Max(int a, int b)
{
	if (a > b) return a;
	return b;
}
int Min(int a, int b)
{
	if (a < b) return a;
	return b;
}
int evaluate(char b[12][11], bool MM)
{
	char position;
	if (MM) position = 'x'; else position = 'o';

	int score = 0;
	int d4, d2, l3, l2;

	d4 = DeadFour(b, position);
	d2 = DeadTwo(b, position);
	l3 = LiveThree(b, position);
	l2 = LiveTwo(b, position);

	if (FiveInRow(b, position)) {
		score += 150000;
		return score;
	}
	if (LiveFour(b, position)) score += 15000;
	if (((d4 >= 1) && (l3 >= 1)) || (l3 >= 2) || (d4 >= 2)) score += 10000;
	if (l3 + JliveThree(b, position) >= 2) {
		score += 5000;
	}
	if ((d4 != 0))  score += 1000;
	if ((l3 != 0))  score += l3 * 2000;
	if (l2 != 0) score += l2 * 50;
	if (d2 != 0) score += d2 * 10;

	return score;
}

struct toado
{
	int X;
	int Y;
};
bool evaluatePosition(char board[12][11], int x, int y)
{
	toado array[8];
	//gan gia tri
	array[0].X = x - 1;
	array[0].Y = y;

	array[1].X = x - 1;
	array[1].Y = y + 1;

	array[2].X = x;
	array[2].Y = y + 1;

	array[3].X = x + 1;
	array[3].Y = y + 1;

	array[4].X = x + 1;
	array[4].Y = y;

	array[5].X = x + 1;
	array[5].Y = y - 1;

	array[6].X = x;
	array[6].Y = y - 1;

	array[7].X = x - 1;
	array[7].Y = y - 1;

	for (int i = 0; i < 8; i++) {
		if ((0 <= array[i].X) && (array[i].X <= 11) && (0 <= array[i].Y) && (array[i].Y <= 10)) {
			if (board[array[i].X][array[i].Y] != '_') {
				return true;
			}
		}
	}
	return false;
}


int minimax(char board[12][11], int depth, bool isMax, int alpha, int beta)
{

	// 3 truong hop xay ra 
	if ((depth == 0)) {
		if (evaluate(board, true) >= 150000) return 300000;
	}
	if (depth == 1) {
		if (evaluate(board, false) >= 150000) return -300000;
	}
	if (depth == 2) {
		if (evaluate(board, true) >= 150000) return 250000;
	}
	if (depth == 3) {
		int score_o = evaluate(board, false);
		if (score_o >= 150000) return -250000;
		int score_x = evaluate(board, true);

		return  score_x - score_o;

	}
	//	if (isMovesLeft(board) == false) return score;

	if (isMax)
	{
		int best = -200000;
		int check;
		for (int i = a.row - 1; i <= b.row + 1; i++)
		{
			for (int j = a.col - 1; j <= b.col + 1; j++)
			{
				check = 0;
				if ((board[i][j] == '_') && (evaluatePosition(board, i, j)))
				{
					board[i][j] = player;
					best = Max(best, minimax(board, depth + 1, !isMax, alpha, beta));
					alpha = Max(alpha, best);
					// tra lai gia tri
					board[i][j] = '_';
					// su dung alpha beta de cat nhanh khong can thiet
					if (alpha >= beta) {
						check = 1;
						break;
					}
				}
			}
			if (check == 1) break;
		}
		return best;
	}
	else
	{
		int best = 200000;
		int check = 0;

		for (int i = a.row - 1; i <= b.row + 1; i++)
		{
			for (int j = a.col - 1; j <= b.col + 1; j++)
			{
				check = 0;
				if ((board[i][j] == '_') && (evaluatePosition(board, i, j)))
				{
					board[i][j] = opponent;

					best = Min(best, minimax(board, depth + 1, !isMax, alpha, beta));
					beta = Min(best, beta);

					//tra lai gia tri
					board[i][j] = '_';
					if (beta <= alpha) {
						check = 1;
						break;
					}
				}
			}
			if (check == 1) break;
		}
		return best;
	}
}

// tim nuoc di hop li nhat
Move findBestMove(char board[12][11])
{
	int bestVal = -2000000;
	Move bestMove;

	bestMove.row = -1;
	bestMove.col = -1;

	findFirstLast(a, b, board);
	for (int i = a.row - 1; i <= b.row + 1; i++)
	{
		for (int j = a.col - 1; j <= b.col + 1; j++)
		{
			// di tim o chua danh
			if ((board[i][j] == '_') && (evaluatePosition(board, i, j)))
			{
				board[i][j] = player;

				int moveVal = minimax(board, 0, false, -200000, 200000);
				// tra lai gia tri 
				board[i][j] = '_';
				// tim nuoc di hop li
			//	cout << moveVal << "  row:" << i << "  col:" << j << endl;
				if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}
	return bestMove;
}

void EmptyBoard(char board[12][11])
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 11; j++)
			board[i][j] = '_';
}