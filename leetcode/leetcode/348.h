#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include "Solution.h"

using namespace std;

/*
Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Example:
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
Follow up:
Could you do better than O(n2) per move() operation?
*/


/*
["TicTacToe","move","move","move","move","move","move","move"]
[[3],[0,0,1],[0,2,2],[2,2,1],[1,1,2],[2,0,1],[1,0,2],[2,1,1]]

|X| |O|
|O|O| |    
|X|X|X|

*/


class TicTacToe {
public:

	vector<vector<char>> board;
	int size;
	/** Initialize your data structure here. */
	TicTacToe(int n) {
		// initialize board

		size = n;
		vector<char> a;

		for (int i = 0; i < n; i++)
		{
			a.push_back(' ');
		}

		for (int i = 0; i < n; i++)
		{
			board.push_back(a);
		}

	}

	/** Player {player} makes a move at ({row}, {col}).
	@param row The row of the board.
	@param col The column of the board.
	@param player The player, can be either 1 or 2.
	@return The current winning condition, can be either:
	0: No one wins.
	1: Player 1 wins.
	2: Player 2 wins. */
	int move(int row, int col, int player) {
		// spot is already occupied
		if (board[row][col] != ' ')
			return 0;

		char mark = ' ';

		if (player == 1)
			mark = 'X';
		else
			mark = 'O';

		board[row][col] = mark;

		// check relevant row

		bool rowVictory = true;
		for (int i = 0; i < size && rowVictory; i++)
		{
			rowVictory = (board[row][i] == mark);
		}

		// check relevant col
		bool colVictory = true;
		for (int i = 0; i < size && colVictory; i++)
		{
			colVictory = (board[col][i] == mark);
		}

		// check top left diagonal if necessary
		bool leftDiagVictory = true;
		if (row == col)
		{
			for (int i = 0; i < size && leftDiagVictory; i++)
			{
				leftDiagVictory = (board[i][i] == mark);
			}
		}
		else
			leftDiagVictory = false;

		// check top right diagonal
		bool rightDiagVictory = true;
		for (int i = 0; i < size && rightDiagVictory; i++)
		{
			rightDiagVictory = (board[size-1-i][i] == mark);
		}

		if (rowVictory || colVictory || leftDiagVictory || rightDiagVictory)
			return player;
		else
			return 0;
	}
};