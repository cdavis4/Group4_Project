/**************************************
 ** Author: carrie davis
 ** Date:July 22, 2018
 ** Description: Project 2; Tiger
 ****************************************/

#include "Ant.hpp"

/*************************************************
 * Ant::getType()
 * gets the type of critter
 **************************************************/
TYPE Ant::getType()
{
    return ANT;
}

/*************************************************
 * Ant::breed()
 * gets the type of critter
 **************************************************/
Ant* Ant::breed(int inRow, int inColumn)
{
    Ant* babyAnt;
    babyAnt = new Ant(inRow,inColumn);
    
    return babyAnt;
}
/*******************************************************
 * Ant::move
 * Moves critter one step at its current position
 * changing its position
 * redrawing the ant at its new position.
 ******************************************************/
void Ant::move()
{
    int row, column; // Direction of motion
    
    //draw();  - this could be place method for bug?
    
    // Compute the new postion for the shape by adding a step in
    // the proper direction to the current position
    getDirection(dRow, dCol);
    rowPos += row;
    colPos += column;
    
}

