/*******************************************************
 ** Author: group 4
 ** Date:July 27, 2018
 ** Description: Group 4 Project; Board Class
 ******************************************************/


#include "Board.hpp"
#include <cstdlib>


/*********************************************************
 * 	    Board 2-args contructor:
 * Takes two int parameters for the rows and 
 * columns of the board.  It then creates
 * a 2-D dynamic array of Critter pointers. 
 ****************************************************/
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

/*********************************************************
 * 		placeCritters
 * A function that takes no parameters
 * and returns nothing (void).  It
 * loops through the Critter array and 
 * adds ants and doodlebugs at random 
 * locations.
 ********************************************************/
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

/*********************************************************
 * 		   turn
 * A function that takes no parameters
 * and returns nothing (void).  It
 * loops through the Critter array and 
 * checks the cells to see if there is 
 * a critter occupying the cell.  If there
 * is, it calls the critter's move function
 * and also handles breeding, eating and
 * starving.
 **********************************************************/
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
						boardArray[i][j]->starve(i,j,boardArray,row,col);
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

/*********************************************************
 * 		print
 * A function that takes no parameters
 * and returns nothing (void).  It
 * prints out the contents of the 2d 
 * Critter array displaying the board.
 ****************************************************/
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
				
				std::cout << "O";
			}
			
			else if(boardArray[i][j]->getType() == DOODLE)
			{
				std::cout << "X";
			}
			
			
		}
		std::cout << std::endl;
	}
}

/***************************************************************
 *                   setSteps                  
 * A setter function that takes an int parameter for the
 * number of steps and returns nothing (void).
 * It sets steps to the value passed to it.
 **************************************************************/
void Board::setSteps(int steps)
{
	this->steps = steps;
}

/***************************************************************
 *                   setAnts                  
 * A setter function that takes an int parameter for the
 * number of ants and returns nothing (void).
 * It sets the number of ants to the value passed to it.
 **************************************************************/
void Board::setAnts(int numAnts)
{
	this->numAnts = numAnts;
}

/***************************************************************
 *                   setDoodleBugs                  
 * A setter function that takes an int parameter for the
 * number of doodlebugs and returns nothing (void).
 * It sets the number of doodlebugs to the value passed to it.
 **************************************************************/
void Board::setDoodleBugs(int numDBugs)
{
	this->numDBugs = numDBugs;
}

/***************************************************************
 *                   getSteps                  
 * A getter function that takes no parameters and returns
 * an int for the number of steps.
 **************************************************************/
int Board::getSteps()
{
	return steps;
}

/***************************************************************
 *                   getAnts                 
 * A getter function that takes no parameters and returns
 * an int for the number of ants.
 **************************************************************/
int Board::getAnts()
{
	return numAnts;
}

/***************************************************************
 *                   getDoodleBugs                  
 * A getter function that takes no parameters and returns
 * an int for the number of doodlebugs.
 **************************************************************/
int Board::getDoodleBugs()
{
	return numDBugs;
}

/***************************************************************
 *                   getBoardArray                 
 * A getter function that takes no parameters and returns
 * the 2d array of Critter pointers.
 **************************************************************/
Critter*** Board::getBoardArray()
{
	return boardArray;
}


/***************************************************************
 *                   Board Destructor                   
 * A destructor that uses delete to free up the memory
 * allocated to the the Critter array. 
 **************************************************************/
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


