#ifndef Board_hpp
#define Board_hpp
#include "DoodleBug.hpp"
#include "Ant.hpp"
#include "Critter.hpp"
#include "Menu.hpp"
#include <stdio.h>
#include <iostream>

class Board
{
	private:
	Critter ***boardArray;
	int row;
	int col;
	
	// added July 26
	int steps;
	int numAnts;
	int numDBugs;
	
	public:
	Board();
	Board(int row, int column);
	void print();
	void freeMemory();
	friend class Critter;
	friend class Ant;
	//friend class Doodlebug;
	
	// functions added July 26
	void setSteps(int);
	void setAnts(int);
	void setDoodleBugs(int);
	int getSteps();
	int getAnts();
	int getDoodleBugs();
	void placeCritters();
	Critter*** getBoardArray();
	void turn();
	~Board();
	
	
	
	
};

#endif /* Board_hpp */
