//
//  DoodleBug.hpp
//  
//
//  Created by Carrie Davis on 7/25/18.
//

#ifndef DoodleBug_hpp
#define DoodleBug_hpp

#include "Critter.hpp"
class DoodleBug:: public Ant
{
protected:

public:
    DoodleBug(int inRow, int inColumn):Ant(row, column)
    {
        
    }
    DoodleBug();
    void move(int&, int&); //Same as ant except no survive
    void eat(int, int);  //now this should just get Ant* and delete.
    TYPE getType();
    
};
#endif /* DoodleBug_hpp */
