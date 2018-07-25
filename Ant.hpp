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
protected:
 
public:
    
    Ant(int inRow, int inColumn):Critter(row, column)
    {
        
    }
    Ant();
    void move();
    Ant* breed(int, int);
    TYPE getType();
   
    
    
    
};

#endif /* Ant_hpp */
