/********************************************************************************
** Author: Patrick Byrne
** Date: 7/24/2018
** Description: Menu class function implementation file.
**        This file describes a Menu class that creates
**        a Menu object.  A Menu object has a main menu that
**        presents options to initialize a Predator-Prey
**        Simulation involving ants and doodlebugs on a 
**        2-d grid. It also contains an input validation 
**        function to ensure that the user only enters 
**        valid integers.
*********************************************************************************/

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <ctime>

#include "Menu.hpp"
#include "Board.hpp"
#include "Critter.hpp"


using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::stringstream;


/*******************************************************************
 * 				No-args Menu constructor
 * This constructor is used to initialize all the member
 * variables and user inputs. It does not take any parameters.  
 ******************************************************************/
Menu::Menu()
{	
	question = 1;
	
	// variable only used by mainMenu function
	string choice;
	
	
	
	
	cout << "********************************************************************" << endl;
	cout << "*                                                                  *" << endl;
	cout << "*                        PREDATOR-PREY GAME                        *" << endl; 
	cout << "*                                                                  *" << endl;
	cout << "********************************************************************" << endl;
	cout << endl;
	
	cout << "\n\nDear grader:" << endl;
	cout << "We attempted the Extra Credit menu options.\n\n" << endl;
	 
	cout << "This game is a 2-D predator-prey simulation." << endl;
	cout << "It involves ants and doodlebugs that live on a 2-D grid." << endl;
	cout << "The ants are prey and the doodlebugs are predators.\n" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << endl;				
	// Game options (steps, grid size, ants, doodlebugs)
	// These inputs are validated by the inputVal function

	// mandatory user input
	// question 1
	cout << "Please enter the number of steps (not less than 1 or greater than 12000): " << endl;
	cin.clear();
	getline(cin, userInput);
	steps = inputVal();
	question++;
	
	// questions 2-5 are for Extra Credit options 
	// question 2
	cout << "Please enter the number of rows (not less than 10 or greater than 100): " << endl;
	cin.clear();
	getline(cin, userInput);
	row = inputVal();
	question++;
	
	// question 3
	cout << "Please enter the number of columns (not less than 10 or greater than 100): " << endl;
	cin.clear();
	getline(cin, userInput);
	col = inputVal();
	question++;
	
	// question 4
	maxAnt = 0.25*row*col; // calculate the max number of ants based on the size of the grid
	maxDoodle = 0.02*row*col; // calculate the max number of ants based on the size of the grid
	// the number of ants cannot be greater than 25% of the grid size (maxAnt)
	cout << "Please enter the number of ants (not less than 1 or greater than " << maxAnt << ")" << endl;
	cin.clear();
	getline(cin, userInput);
	ants = inputVal();
	question++;
	
	// question 5
	// the number of doodlebugs cannot be greater than 2% of the grid size (maxDoodle)
	cout << "Please enter the number of doodlebugs (not less than 1 or greater than " << maxDoodle << ")" << endl; // only 2 doodlebugs for a 10x10 board to start
	cin.clear();
	getline(cin, userInput);
	doodlebugs = inputVal();
	question++;
	
	// Instantiate a board and necessary call functions to set values
	Board board1(row, col);
	board1.setSteps(steps);
	board1.setAnts(ants);
	board1.setDoodleBugs(doodlebugs);
	board1.placeCritters();
	// Once values are set, print out the board
	board1.print();
	// After an initial printing of the board, run the simulation
	board1.turn();
	
	// After one run of the simulation, ask the user
	// if they would like to continue running the simulation.  If so,
	// the user enters a new number of steps. If not, they press 'q' to quit.
	while(1)
	{
		cout << "\nTo continue running the simulation, enter a new number of steps." << endl;
		cout << "Press 'q' to quit. " << endl;
		cin.clear();
		getline(cin, userInput);
		
		if(userInput == "q" || userInput == "Q")
		{
			exit(0);
		}
		question = 1;
		steps = inputVal();
		board1.setSteps(steps);
		board1.turn();
	}
	
}

/***************************************************************
 *                   getSteps                 
 * A getter function that takes no parameters and 
 * returns an int value for the number of steps.
 **************************************************************/
int Menu::getSteps()
{
	return steps;
}

/***************************************************************
 *                   getRow                 
 * A getter function that takes no parameters and 
 * returns an int value for the number of rows.
 **************************************************************/
int Menu::getRow()
{
	return row;
}
	
/***************************************************************
 *                   getCol                 
 * A getter function that takes no parameters and 
 * returns an int value for the number of columns.
 **************************************************************/	
int Menu::getCol()
{
	return col;
}

/***************************************************************
 *                   getAnts                 
 * A getter function that takes no parameters and 
 * returns an int value for the number of ants.
 **************************************************************/
int Menu::getAnts()
{
	return ants;
}

/***************************************************************
 *                   getName                  
 * A getter function that takes no parameters and 
 * returns an int value for the number of doodlebugs.
 **************************************************************/
int Menu::getDoodlebugs()
{
	return doodlebugs;
}


/***************************************************************
 *                inputVal                        
 * 	  This function takes no parameters.  It uses two
 *    member variables: a string for the user's input 
 *    (userInput) and an integer to keep track of which 
 *    question the menu is validating the input for 
 *    (question).  It checks to make sure the input is 
 *    an integer and also checks to make sure the integer 
 *    is in the correct range.  The function returns an 
 *    int which is the actual integer being asked for 
 *    from the user.
 **************************************************************/
int Menu::inputVal()
{
	
	bool isInt = false; // boolean to verify if string contains only digits
	bool isValidRange = false; // boolean to verify if int is in correct range
	
	int userNum;
	
	while(!isInt || !isValidRange) 
	{
		int count = 0; // count is used to keep track of which input values are digits
		
		// loop through the userInput string to see if it contains non-digit values
		// this also eliminates negative numbers and floats since they are invalid input
		for(int i=0; i<userInput.length(); i++) 
		{	
			if(isdigit(userInput[i])) 
			{
				count++; 
			}
		}
		// if all the values are digits, count will equal the length of the string.
		// it also checks for a zero-length string which means the user just hit the ENTER key.
		if(count == userInput.length() && userInput.length() > 0) 
		{  
			isInt = true;
			// convert the userInput string into an integer (userNum)
			stringstream ss(userInput);
			ss >> userNum;
		}
		if(isInt)
		{
			// test to see if the user chose a number of steps in the range 1 to 12000
			if(question == 1) 
			{
				if(userNum >= 1 && userNum <= 12000)
				{
					isValidRange = true; // setting isValid equal to true will break out of the loop 
				}
			}
			// test to see if the number of rows or number of columns is in the range 10 to 100
			else if(question == 2 || question == 3)
			{
				if(userNum >= 10 && userNum <= 100) 
				{
					isValidRange = true;
				}
			}
			// test to see if the number of ants is in the range 1 to 25% of the grid size (maxAnt)
			else if(question == 4)
			{
				if(userNum >= 1 && userNum <= maxAnt) 
				{
					isValidRange = true;
				}
			}
			// test to see if the number of doodlebugs is in the range 1 to 2% of the grid size (maxDoodle)
			else if(question == 5)
			{
				if(userNum >= 1 && userNum <= maxDoodle) 
				{
					isValidRange = true;
				}
			}
			
		}
		// isValid will never be true unless isInt is true
		if(!isValidRange)
		{
			cout << "Invalid input.  Please enter an integer within the correct range." << endl;
			cin.clear();
			getline(cin, userInput);
		}
	}	
	return userNum; // this is the actual validated number asked for in the menu
}
