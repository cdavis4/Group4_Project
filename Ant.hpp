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
   // int survive = 0; gets this now from Critter. Could be used in Doodle bug to know when he can breed

public:
    Ant();
    ~Ant();
    void move(int inRow, int inColumn, Critter*** cBoard, int row, int col);
    Ant* breed();
    TYPE getType(); 
    void setSurvive(int);
    int getSurvive();
    
    
};

#endif /* Ant_hpp */
