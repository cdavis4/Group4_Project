#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

class Menu 
{
	
	private:
		std::string userInput;
		int question;
		int maxAnt;
		int maxDoodle;
		int steps;
		int row;
		int col;
		int ants;
		int doodlebugs; 
		//Critter*** cBoard;
		
	
	public:
		Menu();
		int inputVal();
		int getSteps();
		int getRow();
		int getCol();
		int getAnts();
		int getDoodlebugs();


};
#endif // MENU_HPP
