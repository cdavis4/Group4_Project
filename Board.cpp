#include "Board.hpp"
#include <cstdlib>



Board::Board(int row, int col)
{
	this -> row = row;
	this -> col = col;
	
	
	
	boardArray = new Critter **[row];
	for(int i = 0; i < col; i++)
	{
		
	
		boardArray[i] = new Critter*[row];
	
		//*boardArray[i] = new Ant;
	}
	
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			// Originally set board to NULL (tried setting to Critters but ran into issues)
			boardArray[i][j] = NULL;
		}
	}
	
	
	
}

// Should ants be placed first?  Does this matter?
void Board::placeCritters()
{

	int x, y;

	for(int i=0; i<numAnts; i++)
	{
		
		x = rand()%row; 
		y = rand()%col;

		// Check if x,y cell already contains a newly placed Ant 
		if(boardArray[x][y] == NULL)
		{
			boardArray[x][y] = new Ant;
		}
		else
		{
			i -= 1; // set i back to previous value and start over
		}
	}
	
	for(int i=0; i<numDBugs; i++)
	{
		
		x = rand()%row; 
		y = rand()%col;

		// Check if x,y cell already contains an Ant or newly placed Doodlebug
		if(boardArray[x][y] == NULL)
		{
			boardArray[x][y] = new DoodleBug;
		}
		else
		{
			i -= 1; // set i back to previous value and start over
		}
	}
}

void Board::turn()
{
	
	for(int x =0; x < steps; x++)
	{
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j <col ; j++)
			{
				if (boardArray[i][j]!= NULL)
				{
					if(boardArray[i][j]->getType()== ANT)
					{
						boardArray[i][j]->move(i,j,boardArray,row,col);				
					}
				}			
			}		
		}
	
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j <col ; j++)
			{
				if (boardArray[i][j] != NULL)
				{
						
					if(boardArray[i][j]->getType()== ANT)
					{
						boardArray[i][j]->resetMoveCount();
					}
				}
			}
		}	
		//Remove doodlebugs and this can show a test of ant movement.
		print();
	}	
}


void Board::print()
{
	std::cout << "\n" << endl;
	for (int i = 0; i < row; i++)
	{
		for ( int j = 0; j < col; j++)
		{
			// check for NULL first or it will give null-pointer exceptions
			if(boardArray[i][j] == NULL)
			{
				std::cout << "*";
			}
			else if(boardArray[i][j]->getType() == ANT)
			{
				//boardArray[i][j]->Ant::draw();
				std::cout << "O";
			}
			
			else if(boardArray[i][j]->getType() == DOODLE)
			{
				std::cout << "X";
			}
			
			//std::cout << std::setw(1) << boardArray[i][j]->draw() << " ";
		}
		std::cout << std::endl;
	}
}

void Board::setSteps(int steps)
{
	this->steps = steps;
}
void Board::setAnts(int numAnts)
{
	this->numAnts = numAnts;
}
void Board::setDoodleBugs(int numDBugs)
{
	this->numDBugs = numDBugs;
}
int Board::getSteps()
{
	return steps;
}
int Board::getAnts()
{
	return numAnts;
}
int Board::getDoodleBugs()
{
	return numDBugs;
}



// Free up memory
Board::~Board()
{
	for(int i=0 ;i < row ;i++ ) 
	{
		for(int j=0; j< col; j++)
		{
			delete boardArray[i][j]; // frees up memory at 2-D array cell
			boardArray[i][j] = NULL;
		}
		delete[] boardArray[i]; // frees up memory used by inner arrays/pointers
		boardArray[i] = NULL;
	}
	// frees up memory of outer array/pointer
	delete[] boardArray;
	boardArray = NULL;
}



Critter*** Board::getBoardArray()
{
	return boardArray;
}
