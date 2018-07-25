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

    virtual void move(int, int); //virutal function
    
    //updated these
    void getPosition(int&,int&);
    void setPosition(int, int);
public:
    virtual TYPE getType() {return NONE;}
    Critter();
    Critter(int inRow, int inColumn);
};
#endif /* Critter_hpp */
