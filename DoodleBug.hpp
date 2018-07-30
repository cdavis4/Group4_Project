/*******************************************************
Doodlebug is a derived class of Critter. Its move method
looks for an Ant to eat in an adjacent cell, if not,
it moves randomly. If the Doodlebug does not eat an
Ant in three steps, then the Doodlebug starves and
dies.
********************************************************/
#ifndef DoodleBug_hpp
#define DoodleBug_hpp

#include "Critter.hpp"
#include "Ant.hpp"
// doodlebug needs to inherit from Critter, not Ant
class DoodleBug: public Critter 
{
 protected:
    int survive;

 public:
    DoodleBug();
    TYPE getType();
    void move(int inRow, int inColumn, Critter*** cBoard, int row, int col);
    void breed(int inRow, int inColumn, Critter*** cBoard, int row, int col);
    
};
#endif /* DoodleBug_hpp */
