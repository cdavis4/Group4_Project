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
    int breed;


    //updated these
   // void getPosition(int&,int&);
   // void setPosition(int, int);
public:
    virtual void move(int inRow, int inColumn, Critter*** cBoard, int row, int col);
    virtual TYPE getType() {return NONE;}
    Critter();
	virtual void starve(int inRow, int inColumn, Critter*** cBoard, int row, int col);
    Critter(int , int ); // represents survive and moveCount
    void setSurvive(int);
    void resetMoveCount();
};
#endif /* Critter_hpp */
