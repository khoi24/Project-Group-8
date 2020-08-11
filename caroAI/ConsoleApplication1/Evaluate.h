#pragma once
#include "find_x_y.h"

int FiveInRow(char board[12][11], char xo, Move a, Move b);

int LiveFour(char board[12][11], char xo, Move a, Move b);
int DeadFour(char board[12][11], char xo, Move a, Move b);

int LiveThree(char board[12][11], char xo, Move a, Move b);
int DeadThree(char board[12][11], char xo, Move a, Move b);
int JliveThree(char board[12][11], char xo, Move a, Move b);

int LiveTwo(char board[12][11], char xo, Move a, Move b);
int DeadTwo(char board[12][11], char xo, Move a, Move b);