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
    int survive = 0;

public:
    
    Ant(int inRow, int inColumn, int inSurvive):Critter(row, column)
    {
        survive = inSurvive;
        
    }
    Ant();
    void move(int&, int&);
    void move(int inRow, int inColumn, Critter*** cBoard, int row, int col);
    Ant* breed(int, int);
    TYPE getType(); 
    void setSurvive(int);
    int getSurvive();
    
    
};

#endif /* Ant_hpp */
