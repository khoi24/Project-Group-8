#pragma once
#include <iostream>

using namespace std;

int FiveInRow(char board[12][11], char xo);

int LiveFour(char board[12][11], char xo);
int DeadFour(char board[12][11], char xo);

int LiveThree(char board[12][11], char xo);
int DeadThree(char board[12][11], char xo);
int JliveThree(char board[12][11], char xo);

int LiveTwo(char board[12][11], char xo);
int DeadTwo(char board[12][11], char xo);
