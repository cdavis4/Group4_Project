/***********************************************************************
  Critter is the parent class of the derived classes Ant and Doodlebug. 
 It has the following protected data members: survive which counts 
 the number of steps the Critter object has lived through and is used
 for determining if the Critter should breed and for the Doodlebug’s
 starve method, and moveCount that increments when a critter has moved. 
 Critter has the following public methods: a virtual method called move 
 that moves the placement of a Critter object depending on the type and 
 arrangement of the board when called, a virtual method called breed 
 that creates a new derived Critter object if the selected Critter is 
 old enough, a virtual method called starve that checks if a Doodlebug 
 has eaten an ant in the last three steps and deletes the Doodlebug if it 
 has not, and a virtual function called type that returns the type of the
 Critter as assigned by an enum in the Critter class.
*************************************************************************/
#ifndef Critter_hpp
#define Critter_hpp

using namespace std;

enum TYPE{DOODLE,ANT,NONE}; // type of animals that can be added

class Critter
{
 protected:
    int survive;
    int moveCount; 
    int starveCount;
	
 public:
    virtual void move(int inRow, int inColumn, Critter*** cBoard, int row, int col)=0;
    virtual TYPE getType() {return NONE;}
    Critter();
    virtual void starve(int inRow, int inColumn, Critter*** cBoard, int row, int col);
    void setSurvive(int);
    void resetMoveCount();
    void resetStarve();
    int getStarveCount();
    virtual void breed(int inRow, int inColumn, Critter*** cBoard, int row, int col);
	
};
#endif /* Critter_hpp */
