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
   // this->row = inRow;
   // this->column = inColumn;
    survive = 0;
    moveCount = 0;
}

/*********************************************************
 * Critter::move
 * Moves critter one step FROM its current position
 * changing its position
 * place the CRITTER at its new position.
 ****************************************************/

void Critter::move(int inRow, int inColumn, Critter*** cBoard, int row, int col)
{
	// to be overridden in the derived class
}

/*************************************************
 * Ant::setPosition()
 * sets the row and column ant located
 **************************************************/
/*void Critter::setPosition(int inRow, int inColumn)
{
    row = inRow;
    column = inColumn;
}
*/
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

