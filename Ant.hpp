//
//  Ant.hpp
//  
//
//  Created by Carrie Davis on 7/25/18.
//

#ifndef Ant_hpp
#define Ant_hpp

#include "Critter.hpp"
class Ant: public Critter
{
private:
      // counts steps
     int survive; // set this in constructor. Gets this now from Critter. Could be used in Doodle bug to know when he can breed

public:
    Ant();
    void move(int inRow, int inColumn, Critter*** cBoard, int row, int col);
    void breed(int inRow, int inColumn, Critter*** cBoard, int row, int col);
    TYPE getType(); 
    int getSurvive();
    
    
};

#endif /* Ant_hpp */
