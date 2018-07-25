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
    void move(); //Same as ant
    void eat(vector<shared_ptr<Ant>>&);  // use getType of surrounding vector Critters to determine if ANT. Then call eat on that object pointer to Critter. Input needs to be the vector reference so it can clear it. could start with North,NorthEast,East, etc. eat first ANT encountered. or could eat all?
    TYPE getType();
    
};
#endif /* DoodleBug_hpp */
