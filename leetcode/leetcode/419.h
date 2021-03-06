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
Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
Follow up:
Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
*/


/*
["X..X",".X.X","...X"]
["X..X","...X",".X.X"]
["X..X",".X..","..X."]
["....","....","...."]
["X.XX",".X.X","...X"]
*/


// solution: every X without an X to the left or above is a new battleship
int countBattleships(vector<vector<char>>& board) {

	int battleships = 0;

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] != 'X')
				continue;

			// check space above and to the left is not an X
			bool left = (j == 0 || board[i][j - 1] != 'X');
			bool up = (i == 0 || board[i - 1][j] != 'X');

			if (!left && !up)
				return -1;
			else if (left && up)
				battleships++;

		}
	}

	return battleships;
}