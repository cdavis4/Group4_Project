//
//  Critter.hpp
//  Created by Carrie Davis on 7/25/18.
//

#ifndef Critter_hpp
#define Critter_hpp

using namespace std;

class Critter
{
protected:
  //use with friends and derived
    int row;
    int column;

    virtual void move(); //virutal function
   //member function prototypes
    
    //these are maybe set constant? shouldn't change
    void getDirection(int, int);
    void setDirection(int&, int&);
    
};
#endif /* Critter_hpp */
