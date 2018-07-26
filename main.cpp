#include <iostream>

#include "Menu.hpp"
#include "Board.hpp"
using namespace std;

// For Initial Testing Purposes

int main()
{	
	Menu menu;
	int ants = menu.getAnts();
	int doodlebugs = menu.getDoodlebugs();
	int steps = menu.getSteps();
	int row = menu.getRow();
	int col = menu.getCol();
	Board board1(row, col);
}
