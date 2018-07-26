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
	
	public:
	Board(int row, int column);
	friend class Critter;
	friend class Ant;
	friend class Doodlebug;
};
#endif
