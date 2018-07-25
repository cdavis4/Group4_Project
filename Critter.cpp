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
/********************************************************
 * Critter::getDirection
 * gets Direction the critter should travel
 ********************************************************/
void Critter::getDirection(int& inRow, int& inColumn)
{
    inColumn = column;   //input values will be set to the direction
                        //row and column that the bug should move
    inRow = row;
}
/********************************************************
 * Critter::setDirection
 * sets Direction the critter should travel
 ********************************************************/
void Critter::setDirection(int& inRow, int& inColumn)
{
    column = inColumn;  //setting the location the bug should travel
    row = inRow;
}

