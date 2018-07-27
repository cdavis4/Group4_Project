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
    this->row = 0;
    this->column = 0;
	survive = 0;
	moveCount = 0;
}


Critter::Critter(int inRow, int inColumn)
{
    this->row = inRow;
    this->column = inColumn;
	survive = 0;
}


/*************************************************************
 * Critter::move
 * Moves critter one step at its current position
* changing its position
* redrawing the ant at its new position.
*************************************************************/
void Critter::move()
{
    int row, column; // Direction of motion
	int direction;
	direction = 4;
	if(direction == 4)
	{
		row += 1;
		column += 1;
	}
	
   
    //draw();  //- this could be place method for bug?
    
    // Compute the new postion for the shape by adding a step in
    // the proper direction to the current position
    //getDirection(dRow, dCol);
    //rowPos += row;
   // colPos += column;

}
/*********************************************************
 * Critter::move
 * Moves critter one step FROM its current position
 * changing its position
 * place the CRITTER at its new position.
 ****************************************************/
void Critter::move(int inRow, int inColumn)
{
    setPosition(inRow,inColumn);
}



/*************************************************
 * Ant::setPosition()
 * sets the row and column ant located
 **************************************************/
void Critter::setPosition(int inRow, int inColumn)
{
    row = inRow;
    column = inColumn;
}

/*************************************************
 * Ant::getSurvive()
 * gets survival days of Ant
 **************************************************/
void Critter::setSurvive(int inSurvive)
{
    survive = inSurvive;
}



