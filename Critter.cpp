/***********************************************************************
  Critter is the parent class of the derived classes Ant and Doodlebug. 
 It has the following protected data members: survive which counts 
 the number of steps the Critter object has lived through and is used
 for determining if the Critter should breed and for the Doodlebug’s
 starve method, and moveCount that increments when a critter has moved. 
 Critter has the following public methods: a virtual method called move 
 that moves the placement of a Critter object depending on the type and 
 arrangement of the board when called, a virtual method called breed 
 that creates a new derived Critter object if the selected Critter is 
 old enough, a virtual method called starve that checks if a Doodlebug 
 has eaten an ant in the last three steps and deletes the Doodlebug if it 
 has not, and a virtual function called type that returns the type of the
 Critter as assigned by an enum in the Critter class.
*************************************************************************/
#include <iostream>
using namespace std;
#include "Critter.hpp"
//Default Constructor

Critter::Critter()
{	
    	survive = 0;
    	moveCount = 0;
	starveCount = 0;
}

void Critter::setSurvive(int inSurvive)
{
    survive = inSurvive;
}

void Critter::resetMoveCount()
{
	moveCount = 0;
}
int Critter::getStarveCount()
{
	return starveCount;
}


/*********************************************************
starve checks if a doodlebug has eaten an ant in the past
three steps, if not, it deletes the doodlebug.
**********************************************************/

void Critter::starve(int inRow, int inColumn, Critter*** cBoard, int row, int col)
{
	if(cBoard[inRow][inColumn]!=NULL)
	{
	
		if(cBoard[inRow][inColumn]->getType()==DOODLE)
		{
			if(cBoard[inRow][inColumn]->getStarveCount()==3)
			{
				delete cBoard[inRow][inColumn];
				cBoard[inRow][inColumn] = NULL;
			}
		}
	}
}	
