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
 * Ant::getSurvive()
 * gets survival days of Ant
 **************************************************/
int Ant::getSurvive()
{
    return survive;
}

/*************************************************
 * Ant::breed()
 * gets the type of critter
 **************************************************/
Ant* Ant::breed(int inRow, int inColumn)
{

    Ant* babyAnt;
    babyAnt = new Ant(inRow,inColumn,0);  // zero represents survival
    
    return babyAnt;
 
}
/***************
 * Ant::move
 * Moves critter one step at its current position
 * changing its position
 * place the Doodle at its new position.
 ****************************************************/
void Ant::move(int &inRow, int &inColumn)
{
    //could randomize here
    getPostion(inRow,inColumn);  //not sure if this is just an unnecessary step
    //do checks then
    setPosition(inRow,inColumn);
    survival++; //update that the ant has survived to move again
    
}
