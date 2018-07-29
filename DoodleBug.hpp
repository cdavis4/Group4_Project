//
//  DoodleBug.hpp
//  
//
//  Created by Carrie Davis on 7/25/18.
//

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
    void move(int&, int&); //Same as ant except no survive
    void eat(Ant*);  //now this should just get Ant* and delete.
    TYPE getType();
    void move(int inRow, int inColumn, Critter*** cBoard, int row, int col);
    void breed(int inRow, int inColumn, Critter*** cBoard, int row, int col);
    
};
#endif /* DoodleBug_hpp */
