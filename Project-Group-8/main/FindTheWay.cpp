#include "FindTheWay.h"


// ok
bool FindTheWay::isMovesLeft(char board[12][11])
{
	for (int i = 0; i < 12; i++)

		for (int j = 0; j < 11; j++)

			if (board[i][j] == '_')

				return true;
	return false;
}

//ok
int FindTheWay::Max(int a, int b)
{
	if (a > b) return a;
	return b;
}

//ok
int FindTheWay::Min(int a, int b)
{
	if (a < b) return a;
	return b;
}

//ok
void FindTheWay::EmptyBoard(char board[12][11])
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 11; j++)
			board[i][j] = '_';
}

//ok
bool FindTheWay::evaluatePosition(char board[12][11], int x, int y)
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


// loi voi evaluate  // findFirstLast => ok
int FindTheWay::evaluate(char b[12][11], bool MM)
{
	Move Ox, Oy;
	char position;

	if (MM) position = 'x'; else position = 'o';

	int score = 0;
	int d4, d2, l3, l2;

	Evaluate_Board::findFirstLast(Ox, Oy, b);

	d4 = Evaluate_Board::DeadFour(b, position, Ox, Oy);
	d2 = Evaluate_Board::DeadTwo(b, position, Ox, Oy);
	l3 = Evaluate_Board::LiveThree(b, position, Ox, Oy);
	l2 = Evaluate_Board::LiveTwo(b, position, Ox, Oy);

	if (Evaluate_Board::FiveInRow(b, position, Ox, Oy)) {
		score += 150000;
		return score;
	}
	if (Evaluate_Board::LiveFour(b, position, Ox, Oy)) score += 100000;
	if (((d4 >= 1) && (l3 >= 1)) || (l3 >= 2) || (d4 >= 2)) score += 50000;
	if (l3 + Evaluate_Board::JliveThree(b, position, Ox, Oy) >= 2) {
		score += 10000;
	}
	if ((l3 != 0))  score += l3 * 6000;
	if ((d4 != 0))  score += 1000;
	if (l2 != 0) score += l2 * 100;
	if (d2 != 0) score += d2 * 50;

	return score;
}

// loi voi evaluate // findFirstLast => ok
bool FindTheWay::attackORdefense(char board[12][11])
{
	Move Ox, Oy;
	char position;
	int score = 0;
	int d4_x, d4_o, l4_x, l4_o, l3_x, l3_o, d4_x1, l3_x1, d4_o1, l3_o1;

	Evaluate_Board::findFirstLast(Ox, Oy, board);

	d4_x = Evaluate_Board::DeadFour(board, 'x', Ox, Oy);
	d4_o = Evaluate_Board::DeadFour(board, 'o', Ox, Oy);
	l4_x = Evaluate_Board::LiveFour(board, 'x', Ox, Oy);
	l4_o = Evaluate_Board::LiveFour(board, 'o', Ox, Oy);
	l3_x = Evaluate_Board::LiveThree(board, 'x', Ox, Oy);
	l3_o = Evaluate_Board::LiveThree(board, 'o', Ox, Oy);


	// tan cong
	if ((d4_x >= 1) || (l4_x >= 1)) return true;
	// thu
	if ((d4_o >= 1) || (l4_o >= 1)) return false;

	// gia lap truong hop may se danh deadfour va livethree
	for (int i = Ox.row - 1; i <= Oy.row + 1; i++)
	{
		for (int j = Ox.col - 1; j <= Oy.col + 1; j++)
		{
			// di tim o chua danh
			if ((board[i][j] == '_') && (evaluatePosition(board, i, j)))
			{
				board[i][j] = 'o';
				l3_x1 = Evaluate_Board::LiveThree(board, 'x', Ox, Oy);
				d4_x1 = Evaluate_Board::DeadFour(board, 'x', Ox, Oy);
				board[i][j] = '_';
				if ((l3_x1 >= 1) && (d4_x1 >= 1) && (d4_x > d4_x) && (l3_x1 > l3_x)) return true;
			}
		}
	}

	// gia lap truong hop cua nguoi choi se danh deadfour va livethree
	for (int i = Ox.row - 1; i <= Oy.row + 1; i++)
	{
		for (int j = Ox.col - 1; j <= Oy.col + 1; j++)
		{
			// di tim o chua danh
			if ((board[i][j] == '_') && (evaluatePosition(board, i, j)))
			{
				board[i][j] = 'o';
				l3_o1 = Evaluate_Board::LiveThree(board, 'o', Ox, Oy);
				d4_o1 = Evaluate_Board::DeadFour(board, 'o', Ox, Oy);
				board[i][j] = '_';
				if ((l3_o1 >= 1) && (d4_o1 >= 1) && (l3_o1 > l3_o) && (d4_o1 > d4_o)) return false;
			}
		}
	}

	// tan cong
	if (l3_x >= 1) return true;
	// thu
	if (l3_o >= 1) return false;

	// gia lap truong hop cua may se danh 2 livethree
	for (int i = Ox.row - 1; i <= Oy.row + 1; i++)
	{
		for (int j = Ox.col - 1; j <= Oy.col + 1; j++)
		{
			// di tim o chua danh
			if ((board[i][j] == '_') && (evaluatePosition(board, i, j)))
			{
				board[i][j] = 'x';
				l3_x1 = Evaluate_Board::LiveThree(board, 'x', Ox, Oy);
				board[i][j] = '_';
				if ((l3_x1 >= 2) && (l3_x1 > l3_x + 1))return true;
			}
		}
	}

	// gia lap truong hop cua nguoi choi se danh 2 livethree
	for (int i = Ox.row - 1; i <= Oy.row + 1; i++)
	{
		for (int j = Ox.col - 1; j <= Oy.col + 1; j++)
		{
			// di tim o chua danh
			if ((board[i][j] == '_') && (evaluatePosition(board, i, j)))
			{
				board[i][j] = 'o';
				l3_o1 = Evaluate_Board::LiveThree(board, 'o', Ox, Oy);
				board[i][j] = '_';
				if ((l3_o1 >= 2) && (l3_o1 > l3_o + 1)) return false;
			}
		}
	}

	return true;
}

//error : a, b la gi , player va opponent
int FindTheWay::minimax(char board[12][11], int depth, bool isMax, int alpha, int beta, bool attack_OR_defense)
{
	Move a, b;

	Evaluate_Board::findFirstLast(a, b, board);

	// tan cong
	if (attack_OR_defense) {
		int score_x = evaluate(board, true);

		if ((depth == 0) && (score_x >= 100000)) return 300000;
		if ((depth == 2)) return score_x;
	}
	// phong thu  
	if (!attack_OR_defense) {
		// 3 truong hop xay ra 
		if (depth == 1) {
			int score_o = evaluate(board, false);
			return -score_o;
		}

	}
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
					board[i][j] = 'x'; // player
					best = Max(best, minimax(board, depth + 1, !isMax, alpha, beta, attack_OR_defense));
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
					board[i][j] = 'o'; //opponent

					best = Min(best, minimax(board, depth + 1, !isMax, alpha, beta, attack_OR_defense));
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

//error : a, b la gi , player va opponent
Move FindTheWay::findBestMove(char board[12][11])
{
	int bestVal = -2000000;
	Move bestMove;
	Move a, b;
	bool attack_defense;
	fstream output;

	output.open("d:\\board.txt", ios::out | ios::app);

	bestMove.row = -1;
	bestMove.col = -1;

	Evaluate_Board::findFirstLast(a, b, board);

	// danh gia nen tan cong hay phong thu
	attack_defense = attackORdefense(board);

	output << "trang thai:";
	if (attack_defense) output << "attack" << endl; else  output << "defense" << endl;
	output << "Live Three of x: " << Evaluate_Board::LiveThree(board, 'x', a, b) << endl;
	output << "Live Three of o: " << Evaluate_Board::LiveThree(board, 'o', a, b) << endl;

	for (int i = a.row - 1; i <= b.row + 1; i++)
	{
		for (int j = a.col - 1; j <= b.col + 1; j++)
		{
			// di tim o chua danh
			if ((board[i][j] == '_') && (evaluatePosition(board, i, j)))
			{
				board[i][j] = 'x'; // player

				int moveVal = minimax(board, 0, false, -200000, 200000, attack_defense);
				// tra lai gia tri 
				board[i][j] = '_';
				// tim nuoc di hop li
				output << "row: " << i << "  Col: " << j << "  score:" << moveVal << endl;
				if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}

	output.close();

	return bestMove;
}
