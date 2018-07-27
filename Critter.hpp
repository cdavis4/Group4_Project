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
    int survive;
    int moveCount; //Added to prevent a critter being moved more than once during move loop.
			

    virtual void move();
    virtual void move(int, int); //virutal function
    virtual void move(int inRow, int inColumn, Critter*** cBoard, int row, int col);
    //updated these
    void getPosition(int&,int&);
    void setPosition(int, int);
public:
    virtual TYPE getType() {return NONE;}
    Critter();
    Critter(int inRow, int inColumn);
    void setSurvive(int);
    void resetMoveCount();
};
#endif /* Critter_hpp */
