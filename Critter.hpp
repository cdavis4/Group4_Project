//
//  Critter.hpp
//  Created by Carrie Davis on 7/25/18.
//

#ifndef Critter_hpp
#define Critter_hpp

using namespace std;

enum TYPE{DOODLE,ANT,NONE}; // type of animals that can be added

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
public:
    virtual TYPE getType() {return NONE;}
    Ant();
    Ant(int inRow, int inColumn);
};
#endif /* Critter_hpp */
