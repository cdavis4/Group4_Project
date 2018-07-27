//
//  DoodleBug.cpp
//  
//
//  Created by Carrie Davis on 7/25/18.
//

#include "DoodleBug.hpp"


DoodleBug::DoodleBug()
{}


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
void DoodleBug::eat(Ant* inAntLocation)
{
    delete inAntLocation;
    
}
/*********************************************************
 * Critter::move -> this should be DoodleBug, not Critter right?
 * Moves critter one step at its current position
 * changing its position
 * place the Doodle at its new position.
 ****************************************************/
void DoodleBug::move(int &inRow, int &inColumn)
{
    //could randomize here
    //getPostion(inRow,inColumn);  //not sure if this is just an unnecessary step
    //do checks for a doodle bug
   // setPosition(inRow,inColumn);
  //maybe call eat? change to take in row, column? or 2D array?
    
}

