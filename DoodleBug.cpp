//
//  DoodleBug.cpp
//  
//
//  Created by Carrie Davis on 7/25/18.
//

#include "DoodleBug.hpp"
#include "Ant.hpp"
/*************************************************
 * DoodleBug::getType()
 * gets the type of critter
 **************************************************/
TYPE DoodleBug::getType()
{
    return DOODLE;
}
/*************************************************
 * Ant::eat()
 * gets the type of critter
 **************************************************/
void DoodleBug::eat(vector<shared_ptr<Ant>>& bugCollection)
{
    //bugCollection[inRow][inColumn].clear();
    //However if we move the Doodle bug to the ant location the ant should be removed anyways? So no real need to eat? or clear ant?
    //vector shared pointers c++ library  http://www.cplusplus.com/reference/vector/vector
    if(bugCollection[row][column]->getType() == ANT)
    {
        bugCollection[row][column].clear();
    };
    move();
}
/*********************************************************
 * Critter::move
 * Moves critter one step at its current position
 * changing its position
 * place the Doodle at its new position.
 ****************************************************/
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
