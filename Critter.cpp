/*******************************************************
 ** Author: carrie davis
 ** Date:July 25, 2018
 ** Description: Group 4 Project; Critter
 ******************************************************/
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

/*********************************************************
 * Critter::move
 * Moves critter one step FROM its current position
 * changing its position
 * place the CRITTER at its new position.
 ****************************************************/

void Critter::move(int inRow, int inColumn, Critter*** cBoard, int row, int col)
{
	
}

/*************************************************
 * Ant::getSurvive()
 * gets survival days of Ant
 **************************************************/
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


void Critter::breed(int inRow, int inColumn, Critter*** cBoard, int row, int col)
{
	
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
