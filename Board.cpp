#include "Board.hpp"
Board::Board(int row, int col)
{
	boardArray = new Critter **[row];
	for(int i = 0; i < col; i++)
	{
		boardArray[i] = new Critter*;
	}
}
