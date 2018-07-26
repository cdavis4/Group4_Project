#include "Board.hpp"
Board::Board(int row, int col)
{
	this -> row = row;
	this -> col = col;
	
	boardArray = new Critter **[row];
	for(int i = 0; i < col; i++)
	{
		boardArray[i] = new Critter*;
		*boardArray[i] = Critter;
	}
	
}
void Board::print()
{
	for (int i = 0; i < row; i++)
	 {for ( int j = 0; j < col; j++)
		{
			std::cout << std::setw(1) << boardArray[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void Board::freeMemory
{

}

