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
   
    //draw();  - this could be place method for bug?
    
    // Compute the new postion for the shape by adding a step in
    // the proper direction to the current position
    getDirection(dRow, dCol);
    rowPos += row;
    colPos += column;

}
/*********************************************************
 * Critter::move
 * Moves critter one step at its current position
 * changing its position
 * place the Doodle at its new position.
 ****************************************************/
void Critter::move(int inRow, int inColumn)
{
    setPosition(inRow,inColumn);
}
/*************************************************
 * Ant::setPosition()
 * sets the row and column ant located
 **************************************************/
void Critter::setPosition(int inRow, int Column)
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



