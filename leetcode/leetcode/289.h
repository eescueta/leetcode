#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up:
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/

/*
[]
[[]]
[[1]]
[[1,1,0], [0,1,0], [1,0,0]]
*/

void gameOfLife(vector<vector<int>>& board) {
	if (board.size() == 0)
		return;

	int n = board.size(); // column size
	int m = board[0].size(); // row size

	for (int i = 0; i < n; i++) // col
	{
		for (int j = 0; j < m; j++) // row
		{
			int count = 0;

			for (int a = max(i - 1, 0); a < min(n, i + 2); a++)
			{
				for (int b = max(j - 1, 0); b < min(m, j + 2); b++)
				{
					if (!(a == i && j == b))
					{
						count += board[a][b] & 1;
					}
				}
			}

			if (count == 2 && board[i][j] & 1)
			{
				board[i][j] |= 2;
			}
			if (count == 3)
			{
				board[i][j] |= 2;
			}
		}
	}

	for (int i = 0; i < n; i++) // col
	{
		for (int j = 0; j < m; j++) // row
		{
			board[i][j] = board[i][j] >> 1;
		}
	}

}