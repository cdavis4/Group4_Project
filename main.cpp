/****************************************************************************************
** Program Name: Group Project - Predator-Prey Simulation
** Authors: Group 4: Patrick Byrne, Carrie Davis, Elizabeth Graalum,
** Devon Rhodes, and Matthew Roemen
** Date: 7/27/2018
** Description: This program runs a Predator-Prey Simulation made
**      up of Ants (prey) and DoodleBugs (predator).  The simulation
**      takes place on a dynamic 2d array.  The Ant and
**      DoodleBug classes inherit from a Critter class. 
*****************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Menu.hpp"
#include "Board.hpp"
using namespace std;


/***********************************************************************************************
**    				main 
**    The main function takes no parameters.  It returns an integer 0.  
**    The purpose of this function is to create an instance of a Menu class that will 
**    provide a menu of options for a user to start a Predator-Prey Simulation.
************************************************************************************************/
int main()
{	

	unsigned seed = time(0);
	srand(seed);
	
	Menu menu;
}
