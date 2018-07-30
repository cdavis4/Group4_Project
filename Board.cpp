/*******************************************************
 ** Author: group 4
 ** Date:July 27, 2018
 ** Description: Group 4 Project; Board Class
*******************************************************/

#include "Board.hpp"
#include <cstdlib>


/*********************************************************
 * Board 2-args contructor:
 * Takes two int parameters for the rows and 
 * columns of the board.  It then creates
 * a 2-D dynamic array of Critter pointers. 
 *******************************************************/
Board::Board(int row, int col)
{
	this -> row = row;
	this -> col = col;
	
	
	// create 2d dynamic array of Critter pointers
	boardArray = new Critter **[row];
	for(int i = 0; i < row; i++)
	{
		boardArray[i] = new Critter *[col];
	}
	
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			// Set each cell initially to NULL
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
					
					// Doodlebug moves first
					
					if(boardArray[i][j]->getType()== DOODLE)
					{
						//cout << "Before Doodle move at point " << i << ", " << j << endl;
						boardArray[i][j]->move(i,j,boardArray,row,col);
						//cout << "After Doodle move at point " << i << ", " << j << endl;
						//cout << boardArray[i][j]->getNewRow() << endl;
						//cout << boardArray[i][j]->getNewCol() << endl;
						//boardArray[i][j]->resetMoveCount();
								
					}
					
					else if(boardArray[i][j]->getType()== ANT)
					{
						//cout << "Before Ant move at point " << i << ", " << j << endl;
						boardArray[i][j]->move(i,j,boardArray,row,col);
						//cout << "After Ant move at point " << i << ", " << j << endl;
						//cout << boardArray[i][j]->getNewRow() << endl;
						//cout << boardArray[i][j]->getNewCol() << endl;
						//boardArray[i][j]->resetMoveCount();		
					}
				}
						
			}
		}
			for(int i = 0; i < row; i++)
			{
				for(int j = 0; j <col ; j++)
				{
					if (boardArray[i][j]!= NULL)
					{
						
						// Doodlebug moves first
						
						if(boardArray[i][j]->getType()== DOODLE)
						{
							//cout << "Before Doodle move at point " << i << ", " << j << endl;
							boardArray[i][j]->starve(i,j,boardArray,row,col);
							//cout << "After Doodle move at point " << i << ", " << j << endl;
							//cout << boardArray[i][j]->getNewRow() << endl;
							//cout << boardArray[i][j]->getNewCol() << endl;
							//boardArray[i][j]->resetMoveCount();
							
						}
					}
		 		}
			}
	
		
		//cout << "outside move loop - resetting count" << endl;
		for(int i = 0; i < row; i++)
		{
			
			//cout << "Loop 1" << endl;
			
			for(int j = 0; j <col ; j++)
			{
				//cout << "Loop 2" << endl;
				//cout << "Grid cell " << i << ", " << j << endl;
				if (boardArray[i][j] != NULL)
				{
					
					
					// Reset the moveCount variable
					//cout << "Did NULL check" << endl;
					if(boardArray[i][j]->getType()== ANT || boardArray[i][j]->getType()== DOODLE)
					{
						//cout << "Did ANT check" << endl;
						boardArray[i][j]->resetMoveCount();
					}
					
				}
			}
		}
			
		cout << "Time step: " << x << "." << endl;
		//Remove doodlebugs and this can show a test of ant movement.
		print();
		
		/* Uncomment to add a timer that pauses between each screen print
		for (int k = 0; k < 147483647; k++)

		{

			__asm__("nop");

		}
		*/
		
		
	}
}


void Board::print()
{
	std::cout << "\n" << std::endl; 
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
