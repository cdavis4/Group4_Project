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
	int steps;
	int numAnts;
	int numDBugs;
	
	public:
	Board(int row, int column);
	void print();
	friend class Critter;
	friend class Ant;
	//friend class Doodlebug;
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
