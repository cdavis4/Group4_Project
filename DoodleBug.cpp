//
//  DoodleBug.cpp
//  
//
//  Created by Carrie Davis on 7/25/18.
//


#include <iostream>

#include <random>
#include <cstdlib>

#include "DoodleBug.hpp"


DoodleBug::DoodleBug()
{
	survive = 0;
	
}


/*************************************************
 * DoodleBug::getType()
 * gets the type of critter
 **************************************************/
TYPE DoodleBug::getType()
{
    return DOODLE;
}


/*
*************************************************
 * Ant::eat()
 * gets the type of critter
 **************************************************
void DoodleBug::eat(Ant* inAntLocation)
{
    delete inAntLocation;
    
}
*/



/*
int DoodleBug::eat(int inRow, int inColumn, Critter*** cBoard, int row, int col)
{
	// lower right
	if (inRow == row && inColumn == col)
	{
		// Always checks west first
		if(cBoard[inRow][inColumn-1] != NULL)
		{
			if(cBoard[inRow][inColumn-1]->getType() == ANT)
			{
			//if (cBoard[inRow][inColumn-1]->getType() == ANT)
			//{

				// eat the ant
				cout << "A doodlebug just ate an ant at cell " << inRow << ", " << inColumn-1 << "!" << endl;
				std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
				delete cBoard[inRow][inColumn];
				cBoard[inRow][inColumn] = NULL;
				return 1;
			//}
			}
		}
		// check north
		else if(cBoard[inRow-1][inColumn] != NULL)
		{
			if(cBoard[inRow-1][inColumn]->getType() == ANT)
			{
			//if (cBoard[inRow][inColumn-1]->getType() == ANT)
			//{

				// eat the ant
				cout << "A doodlebug just ate an ant at cell " << inRow-1 << ", " << inColumn << "!" << endl;
				std::swap(cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
				delete cBoard[inRow][inColumn];
				cBoard[inRow][inColumn] = NULL;
				return 1;
			//}
			}
		}
	}
	// lower left
	else if(inRow == row && inColumn == 0)
	{
		// check east
		if(cBoard[inRow][inColumn+1] != NULL)
		{
			if(cBoard[inRow][inColumn+1]->getType() == ANT)
			{
			//if (cBoard[inRow][inColumn-1]->getType() == ANT)
			//{

				// eat the ant
				cout << "A doodlebug just ate an ant at cell " << inRow << ", " << inColumn+1 << "!" << endl;
				std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
				delete cBoard[inRow][inColumn];
				cBoard[inRow][inColumn] = NULL;
				return 1;
			//}
			}
		}
		// check north
		else if(cBoard[inRow-1][inColumn] != NULL)
		{
			if(cBoard[inRow-1][inColumn]->getType() == ANT)
			{
			//if (cBoard[inRow][inColumn-1]->getType() == ANT)
			//{

				// eat the ant
				cout << "A doodlebug just ate an ant at cell " << inRow-1 << ", " << inColumn << "!" << endl;
				std::swap(cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
				delete cBoard[inRow][inColumn];
				cBoard[inRow][inColumn] = NULL;
				return 1;
			//}
			}
		}
	// upper left
	else if (inRow == 0 && inColumn == 0)
	{
		// check east
		if(cBoard[inRow][inColumn+1] != NULL)
		{
			if(cBoard[inRow][inColumn+1]->getType() == ANT)
			{
			//if (cBoard[inRow][inColumn-1]->getType() == ANT)
			//{

				// eat the ant
				cout << "A doodlebug just ate an ant at cell " << inRow << ", " << inColumn+1 << "!" << endl;
				std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
				delete cBoard[inRow][inColumn];
				cBoard[inRow][inColumn] = NULL;
				return 1;
			//}
			}
		}
		// check south
		else if(cBoard[inRow+1][inColumn] != NULL)
		{
			if(cBoard[inRow+1][inColumn]->getType() == ANT)
			{
			//if (cBoard[inRow][inColumn-1]->getType() == ANT)
			//{

				// eat the ant
				cout << "A doodlebug just ate an ant at cell " << inRow+1 << ", " << inColumn << "!" << endl;
				std::swap(cBoard[inRow+1][inColumn],cBoard[inRow][inColumn]);
				delete cBoard[inRow][inColumn];
				cBoard[inRow][inColumn] = NULL;
				return 1;
			//}
			}
		}
	}
	// upper right
	else if (inRow == 0 && inColumn == col)
	{
		// check west		
		if(cBoard[inRow][inColumn-1] != NULL)
		{
			if(cBoard[inRow][inColumn-1]->getType() == ANT)
			{
			//if (cBoard[inRow][inColumn-1]->getType() == ANT)
			//{

				// eat the ant
				cout << "A doodlebug just ate an ant at cell " << inRow << ", " << inColumn-1 << "!" << endl;
				std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
				delete cBoard[inRow][inColumn];
				cBoard[inRow][inColumn] = NULL;
				return 1;
			//}
			}
		}
		// check south
		else if(cBoard[inRow+1][inColumn] != NULL)
		{
			if(cBoard[inRow+1][inColumn]->getType() == ANT)
			{
			//if (cBoard[inRow][inColumn-1]->getType() == ANT)
			//{

				// eat the ant
				cout << "A doodlebug just ate an ant at cell " << inRow+1 << ", " << inColumn << "!" << endl;
				std::swap(cBoard[inRow+1][inColumn],cBoard[inRow][inColumn]);
				delete cBoard[inRow][inColumn];
				cBoard[inRow][inColumn] = NULL;
				return 1;
			//}
			}
		}
	}
	return 0;
	
}
*/

/*************************************************
 * DoodleBug::breed()
 * gets the type of critter
 **************************************************/
void DoodleBug::breed(int inRow, int inColumn, Critter*** cBoard, int row, int col)
{

 //cout <<"DoodleBug is inprocess of breeding"<<endl;
	
	
    int searchCounter = 0;
	random_device rd; //seed needs to be on outside of loop
	
    while(searchCounter < 8 )
     {
        
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(-1,1);
        int genRowNum = dist(gen);
        int genColNum = dist(gen);
        cout << genRowNum << genColNum <<endl;
		
        int randomRow = genRowNum + inRow;
		int randomColumn = genColNum + inColumn;
		
		//cout << "Row: " << row << " Column: " << col << endl; 
        //cout <<"RandomRow " <<randomRow <<" RandomColumn "<<randomColumn <<endl;
        if((randomColumn <= col )&&(randomRow <= row )&&(randomColumn >= 0)&&(randomRow >= 0))
        {
           // if(cBoard[randomRow][randomColumn] != NULL);
            //cout << "inRow: " << inRow << " inColumn: " << inColumn << endl;
            if(cBoard[randomRow][randomColumn] == NULL)
            {
				//cout << "1" << endl;
                cBoard[randomRow][randomColumn]= new DoodleBug;
                cBoard[randomRow][randomColumn]->setSurvive(0);
				searchCounter = 8;
				cout <<"had baby" <<endl;
            }
                
            else if ((randomRow ==inRow+1) && (randomColumn == inColumn+1))
                { searchCounter++;
			//cout << "2" << endl;
			}
            else if ((randomRow == inRow) && (randomColumn == inColumn+1))
                { searchCounter++;
			//cout << "3" << endl;
			}
            else if ((randomRow == inRow+1)&&(randomColumn == inColumn))
                { searchCounter++;
			//cout << "4" << endl;
			}
            else if ((randomRow == inRow-1) && (randomRow == inColumn+1))
                { searchCounter++;
			//cout << "5" << endl;
			}
            else if ((randomRow == inRow-1)&&(randomColumn == inColumn))
                { searchCounter++;
			//cout << "6" << endl;
			}
            else if ((randomRow == inRow+1) &&(randomColumn == inColumn-1))
                { searchCounter++;
			//cout << "7" << endl;
			}
            else if ((randomRow == inRow)&& (randomColumn == inColumn-1))
            { searchCounter++;
			//cout << "8" << endl;
			}
            else if ((randomRow == inRow-1)&&(randomColumn == inColumn-1))
            { searchCounter++;
			//cout << "9" << endl;
			}
        }
		
    //cout << searchCounter << endl;
    }
}

/*********************************************************
 * Critter::move -> this should be DoodleBug, not Critter right?
 * Moves critter one step at its current position
 * changing its position
 * place the Doodle at its new position.
 ****************************************************/

 	
void DoodleBug::move(int inRow, int inColumn, Critter*** cBoard, int row, int col)
{
		
	
	
	// 1 west, 2 north, 3 east, 4 south
	// the if-else statements follow a clockwise pattern (ie if first checking west: west->north->east->south)

	// Sets row and column to a value in range 0 to row-1/col-1 (exclusive range)
	row--;
	col--;
	// when these flags are set to true, the direction is no longer available
	bool flagWest = false;
	bool flagNorth = false;
	bool flagEast = false;
	bool flagSouth = false;
	bool ateAnt = false;
	int move = rand()%4+1;
	//cout << "Move: " << move << endl;
	
	if (moveCount == 0)
	{
		//cout << "Move: " << move << endl;
	//Critter *antTemp = **cBoard;
	//unsigned seed = time(0);
	//srand(seed);
	
	
		// At southeast corner (lower right)
		if (inRow == row && inColumn == col)
		{
			while(1) 
			{	
				//cout << "In eating loop 1" << endl;
				if(move == 3 || move == 4) // can't move east or south b/c they face the edges of the board
				{
					// ant unable to move b/c it hits an edge
					break;
				}
				if( move == 1)
				{//Move west
					//cout << "here in move 1" << endl;
					if (cBoard[inRow][inColumn-1] != NULL)
					{
						if (cBoard[inRow][inColumn-1]->getType() == ANT  && flagWest == false)
						{
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow << ", " << inColumn-1 << "!" << endl;
							std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					
					else
					{
						//cout << "still in move 1 " << endl;
						move = 2; // try the north next
						flagWest = true;
					}
				}
				
				if(move ==2)
				{//Move north
					//cout << "here in move 2 " << endl;
					if(cBoard[inRow-1][inColumn] != NULL)
					{
						if (cBoard[inRow-1][inColumn]->getType() == ANT && flagNorth == false)
						{
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow-1 << ", " << inColumn << "!" << endl;
							std::swap(cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							//break;
							break;
						}
					}
					
					else
					{
						//cout << "still in move 2 " << endl;
						move = 1; // move was initially 2 so now go back and try the west
						flagNorth = true;
					}
				}
				cout << flagWest << " " << flagNorth << endl;
				// If east and north cells are both occupied
				if(flagWest && flagNorth)
				{
					// both possible spaces occupied so ant does not move
					//break;
					break;
				}
				
			}
		}
		
		// At southwest corner (lower left)
		else if(inRow == row && inColumn == 0)
		{
			while(1) 
			{	
				//cout << "In eating loop 2" << endl;
				if(move == 1 || move == 4) // can't move west or south b/c they face the edges of the board
				{
					// ant unable to move b/c it hits an edge
					//cout << "In if 1" << endl;
					//break;
					break;
				}
				if(move ==2)
				{//Move north
					//cout << "In if 2" << endl;
					
					if(cBoard[inRow-1][inColumn] != NULL)
					{
						if (cBoard[inRow-1][inColumn]->getType() == ANT  && flagNorth == false)
						{
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow-1 << ", " << inColumn << "!" << endl;
							std::swap(cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 3; // try the east next
						flagNorth = true;
					}
					
				}
				if( move == 3)
				{//Move east
					//cout << "In if 3" << endl;
					if(cBoard[inRow][inColumn+1] != NULL)
					{
						if (cBoard[inRow][inColumn+1]->getType() == ANT && flagEast == false)
						{
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow << ", " << inColumn+1 << "!" << endl;
							std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 2; // move was initially 3 so now go back and try the north
						flagEast = true;
					}	
				}
				
				// If north and east are both occupied
				if(flagNorth && flagEast)
				{
					// both possible spaces occupied so ant does not move
					break;
				}
			}
			
		}
	
		// at northwest corner (upper left)
		else if (inRow == 0 && inColumn == 0)
		{
			while(1) 
			{	
				//cout << "In eating loop 3" << endl;
				if(move == 1 || move == 2) // can't move west or north b/c they face the edges of the board
				{
					// ant unable to move b/c it hits an edge
					break;
				}
				if( move == 3)
				{//Move east
					
					if(cBoard[inRow][inColumn+1] != NULL)
					{
						if (cBoard[inRow][inColumn+1]->getType() == ANT   && flagEast == false)
						{
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow << ", " << inColumn+1 << "!" << endl;
							std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 4; // try the south next
						flagEast = true;
					}
				}
				if (move == 4)
				{//Move south
					if(cBoard[inRow+1][inColumn] != NULL)
					{
						if (cBoard[inRow+1][inColumn]->getType() == ANT  && flagSouth == false)
						{
							ateAnt = true;
							// eat the ant
							//cout << "A doodlebug just ate an ant at cell " << inRow+1 << ", " << inColumn << "!" << endl;
							std::swap(cBoard[inRow+1][inColumn],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 3; // move was initially 4 so now go back and try the east
						flagSouth = true;
					}
				}
				// If east and south cells are both occupied
				if(flagEast && flagSouth)
				{
					// both possible spaces occupied so ant does not move
					break;
				}
			}
		}
		
		// at northeast corner (upper right) 
		else if (inRow == 0 && inColumn == col)
		{
			while(1) 
			{	
				//cout << "In eating loop 4" << endl;
				if(move == 2 || move == 3) // can't move north or east b/c they face the edges of the board
				{
					// ant unable to move b/c it hits an edge
					break;
				}
				if( move == 1)
				{//Move west
					if(cBoard[inRow][inColumn-1] != NULL)
					{
						if (cBoard[inRow][inColumn-1]->getType() == ANT && flagWest == false)
						{
							
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow << ", " << inColumn-1 << "!" << endl;
							std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 4; // try the south next
						flagWest = true;
					}
				}
				if (move == 4)
				{//Move south
					if(cBoard[inRow+1][inColumn] != NULL)
					{
						if (cBoard[inRow+1][inColumn]->getType() == ANT  && flagSouth == false)
						{
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow+1 << ", " << inColumn << "!" << endl;
							std::swap(cBoard[inRow+1][inColumn],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 1; // move was initially 4 so now go back and try the west
						flagSouth = true;
					}
				}
				// If west and south cells are both occupied
				if(flagWest && flagSouth)
				{
					// both possible spaces occupied so ant does not move
					break;
				}
			}
		}
		
		// southern edge
		else if ( inRow == row)
		{
			while(1) 
			{	
				//cout << "In eating loop 5 at move " << move << endl;
				if(move == 4) // can't move south
				{
					// ant unable to move b/c it hits an edge
					break;
				}
				if( move == 1)
				{//Move west
					
					if(cBoard[inRow][inColumn-1] != NULL)
					{
						if (cBoard[inRow][inColumn-1]->getType() == ANT  && flagWest == false)
						{
							
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow << ", " << inColumn-1 << "!" << endl;
							std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 2; // try the north next
						flagWest = true;
					}
				}
				if (move == 2)
				{//Move north
					
					if(cBoard[inRow-1][inColumn] != NULL )
					{
						if (cBoard[inRow-1][inColumn]->getType() == ANT && flagNorth == false)
						{
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow-1 << ", " << inColumn << "!" << endl;
							std::swap(cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 3; // try the east next
						flagNorth = true;
					}
				}
				if(move ==3)
				{//Move east
					
					if(cBoard[inRow][inColumn+1] != NULL )
					{
						if (cBoard[inRow][inColumn+1]->getType() == ANT  && flagEast == false)
						{
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow << ", " << inColumn+1 << "!" << endl;
							std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 1; // move was initially 3 so now go back and try the west
						flagEast = true;
					}
				}
				// If west, north, and east cells are all occupied
				if(flagWest && flagNorth && flagEast)
				{
					// all possible spaces occupied so ant does not move
					break;
				}
			}
		}
		
		// western edge
		else if (inColumn == 0)
		{
			while(1) 
			{	
				//cout << "In eating loop 6" << endl;
				if(move == 1) //can't move west
				{
					// ant unable to move b/c it hits an edge
					break;
				}
				//cout << "MOve: " << move << endl;
				if(move ==2)
				{//Move north

					if(cBoard[inRow-1][inColumn] != NULL )
					{
						if (cBoard[inRow-1][inColumn]->getType() == ANT  && flagNorth == false)
						{
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow-1 << ", " << inColumn << "!" << endl;
							std::swap(cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							//cout << "made it to break" << endl;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 3; // try the east next
						flagNorth = true;
					}
				}
				//cout << "MOve: " << move << endl;
				if( move == 3)
				{//Move east
					
					if(cBoard[inRow][inColumn+1] != NULL)
					{
						if (cBoard[inRow][inColumn+1]->getType() == ANT   && flagEast == false)
						{
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow << ", " << inColumn+1 << "!" << endl;
							std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 4; // try the south next
						flagEast = true;
					}
				}
				//cout << "MOve: " << move << endl;
				if (move == 4)
				{//Move south		
					
					if(cBoard[inRow+1][inColumn] != NULL )
					{
						//cout << "Inside move 4 if statement" << endl;
						if (cBoard[inRow+1][inColumn]->getType() == ANT  && flagSouth == false)
						{
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow+1 << ", " << inColumn << "!" << endl;
							std::swap(cBoard[inRow+1][inColumn],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						//cout << "In else statmeent " << endl;
						move = 2; // move was initially 4 so now go back and try the north
						flagSouth = true;
					}
				}
				
				// If north, east, and south cells are all occupied
				if(flagNorth && flagEast && flagSouth)
				{
					// all possible spaces occupied so ant does not move
					break;
				}
			}
		}
	
		// eastern edge
		else if (inColumn == col)
		{
			while(1) 
			{	
				//cout << "In eating loop 7" << endl;
				if(move == 3) // can't move east
				{
					// ant unable to move b/c it hits an edge
					break;
				}
				
				if( move == 1)
				{//Move west
				
					if(cBoard[inRow][inColumn-1] != NULL )
					{
						if (cBoard[inRow][inColumn-1]->getType() == ANT && flagWest == false)
						{
							
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow << ", " << inColumn-1 << "!" << endl;
							std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 2; // try the north next
						flagWest = true; 
					}
				}
				if(move ==2)
				{//Move north
					
					if(cBoard[inRow-1][inColumn] != NULL)
					{
						if (cBoard[inRow-1][inColumn]->getType() == ANT  && flagNorth == false)
						{
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow-1 << ", " << inColumn << "!" << endl;
							std::swap(cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 4; // try the south next
						flagNorth = true;
					}
				}
				if (move == 4)
				{//Move south
					if(cBoard[inRow+1][inColumn] != NULL)
					{
						if (cBoard[inRow+1][inColumn]->getType() == ANT  && flagSouth == false)
						{
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow+1 << ", " << inColumn << "!" << endl;
							std::swap(cBoard[inRow+1][inColumn],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 1; // move was initially 4 so now go back and try the west
						flagSouth = true;
					}
				}
				
				// If west, north, and south cells are all occupied
				if(flagWest && flagNorth && flagSouth)
				{
					// all possible spaces occupied so ant does not move
					break;
				}
			}
		}
		
		// northern edge
		else if(inRow == 0)
		{
			while(1) 
			{	
				//cout << "In eating loop 8 with a value of " << move << "." << endl;
				if(move == 2) // can't move north
				{
					// ant unable to move b/c it hits an edge
					break;
				}
				
				if( move == 1)
				{//Move west
					//cout <<"I'm here" << endl;
					if (cBoard[inRow][inColumn-1] != NULL)
					{
						//cout << "Not NULL " << endl;
						if (cBoard[inRow][inColumn-1]->getType() == ANT  && flagWest == false)
						{
							
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow << ", " << inColumn-1 << "!" << endl;
							std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							flagWest = true;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
							
					}
					else
					{
						//cout << "Move to this else statement" << endl;
						move = 3; // try the east next
						flagWest = true;
						//cout << "Move is now " << move << endl;
					}
				}
				if(move == 3)
				{//Move east
					//cout <<"I'm actually here" << endl;
					if(cBoard[inRow][inColumn+1] != NULL)
					{
						//cout << "Not NULL " << endl;
						if (cBoard[inRow][inColumn+1]->getType() == ANT  && flagEast == false)
						{
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow << ", " << inColumn+1 << "!" << endl;
							std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							flagEast = true;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							flagEast = true;
							break;
						}
					}
					else
					{
						move = 4; // try the south next
						flagEast = true;
						
					}
				}
				if (move == 4)
				{//Move south
					//cout <<"NOPE I'm here" << endl;
					if(cBoard[inRow+1][inColumn] != NULL)
					{
						//cout << "Not NULL " << endl;
						if (cBoard[inRow+1][inColumn]->getType() == ANT  && flagSouth == false)
						{
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow+1 << ", " << inColumn << "!" << endl;
							std::swap(cBoard[inRow+1][inColumn],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							flagEast = true;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							flagSouth = true;
							break;
						}
					}
					else
					{
						move = 1; // started with 4, go back to 1
						flagSouth = true;
						
					}
				}
				//cout << "Am I even here???" << endl;
				// If west, east, and south cells are all occupied
				if(flagWest && flagEast && flagSouth)
				{
					// all possible spaces occupied so ant does not move
					break;
				}
				//cout << "Value of move at end of loop 8 : " << move << endl;
				
			}
		}
		// Not adjacent to any edge
		else 
		{	
			while(1) 
			{	
				
				//cout << "In eating loop 9 with a value of " << move << "." << endl;
				if( move == 1)
				{//Move west
					//cout << "In west" << endl;
					
					if(cBoard[inRow][inColumn-1] != NULL )
					{
						if (cBoard[inRow][inColumn-1]->getType() == ANT && flagWest == false)
						{
							
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow << ", " << inColumn-1 << "!" << endl;
							std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 2; // try the north next
						flagWest = true;
					}
				}
				if(move ==2)
				{//Move north
					//cout << "In north" << endl;
					
					if(cBoard[inRow-1][inColumn] != NULL)
					{
						if (cBoard[inRow-1][inColumn]->getType() == ANT  && flagNorth == false)
						{
							
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow-1 << ", " << inColumn << "!" << endl;
							std::swap(cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 3;
						flagNorth = true;
					}
				}
				if(move ==3)
				{//Move east
					//cout << "In east" << endl;
					
					if(cBoard[inRow][inColumn+1] != NULL )
					{
						if (cBoard[inRow][inColumn+1]->getType() == ANT && flagEast == false)
						{
							
							ateAnt = true;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow << ", " << inColumn+1 << "!" << endl;
							std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						move = 4;
						flagEast = true;
					}
				}
				
				if (move == 4)
				{//Move south
					//cout << "In south" << endl;
					
					if(cBoard[inRow+1][inColumn] != NULL)
					{
						if (cBoard[inRow+1][inColumn]->getType() == ANT  && flagSouth == false)
						{
							ateAnt = true;
							//cout << "2nd if statement" << endl;
							// eat the ant
							cout << "A doodlebug just ate an ant at cell " << inRow+1 << ", " << inColumn << "!" << endl;
							std::swap(cBoard[inRow+1][inColumn],cBoard[inRow][inColumn]);
							delete cBoard[inRow][inColumn];
							cBoard[inRow][inColumn] = NULL;
							starveCount = 0;
							//moveCount++;
							break;
						}
						else
						{
							//cout << "It's a doodle" << endl;
							break;
						}
					}
					else
					{
						//cout << "3rd if statement " << endl;
						move = 1; // move was initially 4 so now go back and try the west
						flagSouth = true;
					}
				}
				// If west, north, east, and south cells are all occupied
				//cout << "Made it this far in loop 9" << endl;
				if(flagWest && flagNorth && flagEast && flagSouth)
				{
					// All adjacent cells occupied. Break out
					break;
				}
				//cout << "Value of move at end of loop 9 : " << move << endl;
			}	
		}
		if(ateAnt)
		{
			moveCount++;
		}
		
		
		
	}
	
	// if moveCount > 0, then the doodlebug ate an ant and the code below will not run
	//
	
	if(moveCount == 0)	
	{
		// At southeast corner (lower right)
		if (inRow == row && inColumn == col) // && !noAnt)
		{
			while(1) 
			{	
				//cout << "In loop 1" << endl;
				if(move == 3 || move == 4) // can't move east or south b/c they face the edges of the board
				{
					// ant unable to move b/c it hits an edge
					break;
				}
				if( move == 1)
				{//Move west
					if (cBoard[inRow][inColumn-1] == NULL && flagWest == false)
					{
						//cout << "Attempting swap on move 1" << endl;
						std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 2; // try the north next
						flagWest = true;
					}
				}
				
				if(move ==2)
				{//Move north
					if (cBoard[inRow-1][inColumn] == NULL && flagNorth == false)
					{
						//cout << "Attempting swap on move 2" << endl;
						std::swap (cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 1; // move was initially 2 so now go back and try the west
						flagNorth = true;
					}
				}
				// If east and north cells are both occupied
				if(flagWest && flagNorth)
				{
					// both possible spaces occupied so ant does not move
					break;
				}
				
			}
		}
		
		// At southwest corner (lower left)
		else if(inRow == row && inColumn == 0) // && !noAnt)
		{
			while(1) 
			{	
				//cout << "In loop 2" << endl;
				if(move == 1 || move == 4) // can't move west or south b/c they face the edges of the board
				{
					// ant unable to move b/c it hits an edge
					break;
				}
				if(move ==2)
				{//Move north
					if (cBoard[inRow-1][inColumn] == NULL && flagNorth == false)
					{
						std::swap(cBoard[inRow-1][inColumn], cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 3; // try the east next
						flagNorth = true;
					}
				}
				if( move == 3)
				{//Move east
					if (cBoard[inRow][inColumn+1] == NULL && flagEast == false)
					{
						std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 2; // move was initially 3 so now go back and try the north
						flagEast = true;
					}	
				}
				// If north and east are both occupied
				if(flagNorth && flagEast)
				{
					// both possible spaces occupied so ant does not move
					break;
				}
			}
			
		}

		// at northwest corner (upper left)
		else if (inRow == 0 && inColumn == 0) // && !noAnt)
		{
			while(1) 
			{	
				//cout << "In loop 3" << endl;
				if(move == 1 || move == 2) // can't move west or north b/c they face the edges of the board
				{
					// ant unable to move b/c it hits an edge
					break;
				}
				if( move == 3)
				{//Move east
					if (cBoard[inRow][inColumn+1] == NULL && flagEast == false)
					{
						std::swap(cBoard[inRow][inColumn+1], cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 4; // try the south next
						flagEast = true;
					}
				}
				if (move == 4)
				{//Move south
					if (cBoard[inRow+1][inColumn] == NULL && flagSouth == false)
					{
						std::swap(cBoard[inRow+1][inColumn],cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 3; // move was initially 4 so now go back and try the east
						flagSouth = true;
					}
				}
				// If east and south cells are both occupied
				if(flagEast && flagSouth)
				{
					// both possible spaces occupied so ant does not move
					break;
				}
			}
		}
		
		// at northeast corner (upper right) 
		else if (inRow == 0 && inColumn == col) // && !noAnt)
		{
			while(1) 
			{	
				//cout << "In loop 4" << endl;
				if(move == 2 || move == 3) // can't move north or east b/c they face the edges of the board
				{
					// ant unable to move b/c it hits an edge
					break;
				}
				if( move == 1)
				{//Move west
					if (cBoard[inRow][inColumn-1] == NULL && flagWest == false)
					{
						std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 4; // try the south next
						flagWest = true;
					}
				}
				if (move == 4)
				{//Move south
					if (cBoard[inRow+1][inColumn] == NULL && flagSouth== false)
					{
						std::swap(cBoard[inRow+1][inColumn], cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 1; // move was initially 4 so now go back and try the west
						flagSouth = true;
					}
				}
				// If west and south cells are both occupied
				if(flagWest && flagSouth)
				{
					// both possible spaces occupied so ant does not move
					break;
				}
			}
		}
		
		// southern edge
		else if ( inRow == row) // && !noAnt)
		{
			while(1) 
			{	
				//cout << "In loop 5" << endl;
				if(move == 4) // can't move south
				{
					// ant unable to move b/c it hits an edge
					break;
				}
				if( move == 1)
				{//Move west
					if (cBoard[inRow][inColumn-1] == NULL && flagWest == false)
					{
						std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 2; // try the north next
						flagWest = true;
					}
				}
				if (move == 2)
				{//Move north
					if (cBoard[inRow-1][inColumn] == NULL && flagNorth == false)
					{
						std::swap(cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 3; // try the east next
						flagNorth = true;
					}
				}
				if(move ==3)
				{//Move east
					if (cBoard[inRow][inColumn+1] == NULL && flagEast== false)
					{
						std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 1; // move was initially 3 so now go back and try the west
						flagEast = true;
					}
				}
				// If west, north, and east cells are all occupied
				if(flagWest && flagNorth && flagEast)
				{
					// all possible spaces occupied so ant does not move
					break;
				}
			}
		}
		
		// western edge
		else if (inColumn == 0) // && !noAnt)
		{
			while(1) 
			{	
				//cout << "In loop 6 and move " << move << endl;
				if(move == 1) //can't move west
				{
					// ant unable to move b/c it hits an edge
					break;
				}
				if(move ==2)
				{//Move north
					if (cBoard[inRow-1][inColumn] == NULL && flagNorth == false)
					{
						std::swap(cBoard[inRow-1][inColumn], cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 3; // try the east next
						flagNorth = true;
					}
				}
				if( move == 3)
				{//Move east
					
					if (cBoard[inRow][inColumn+1] == NULL && flagEast==false)
					{
						std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 4; // try the south next
						flagEast = true;
					}
				}
				if (move == 4)
				{//Move south		
					if (cBoard[inRow+1][inColumn] == NULL && flagSouth==false)
					{
						std::swap(cBoard[inRow+1][inColumn], cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 2; // move was initially 4 so now go back and try the north
						flagSouth = true;
						
					}
				}
				//cout << "All should be TRUE " << endl;
				// If north, east, and south cells are all occupied
				if(flagNorth && flagEast && flagSouth)
				{
					// all possible spaces occupied so ant does not move
					break;
				}
			}
		}

		// eastern edge
		else if (inColumn == col) // && !noAnt)
		{
			while(1) 
			{	
				//cout << "In loop 7" << endl;
				if(move == 3) // can't move east
				{
					// ant unable to move b/c it hits an edge
					break;
				}
				if( move == 1)
				{//Move west
					if (cBoard[inRow][inColumn-1] == NULL && flagWest == false)
					{
						std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 2; // try the north next
						flagWest = true; 
					}
				}
				if(move ==2)
				{//Move north
					if (cBoard[inRow-1][inColumn] == NULL && flagNorth == false)
					{
						std::swap(cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 4; // try the south next
						flagNorth = true;
					}
				}
				if (move == 4)
				{//Move south
					if (cBoard[inRow+1][inColumn] == NULL && flagSouth == false)
					{
						std::swap(cBoard[inRow+1][inColumn], cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 1; // move was initially 4 so now go back and try the west
						flagSouth = true;
					}
				}
				
				// If west, north, and south cells are all occupied
				if(flagWest && flagNorth && flagSouth)
				{
					// all possible spaces occupied so ant does not move
					break;
				}
			}
		}
		
		// northern edge
		else if(inRow == 0 ) //&& !noAnt)
		{
			while(1) 
			{	
				//cout << "In loop 8" << endl;
				if(move == 2) // can't move north
				{
					// ant unable to move b/c it hits an edge
					break;
				}
				if( move == 1)
				{//Move west
					if (cBoard[inRow][inColumn-1] == NULL && flagWest == false)
					{
						std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 3; // try the east next
						flagWest = true;
					}
				}
				if(move ==3)
				{//Move east
					if (cBoard[inRow][inColumn+1] == NULL && flagEast == false)
					{
						std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 4; // try the south next
						flagEast = true;
					}
				}
				if (move == 4)
				{//Move south
					if (cBoard[inRow+1][inColumn] == NULL && flagSouth == false)
					{
						std::swap(cBoard[inRow+1][inColumn], cBoard[inRow][inColumn]);
						starveCount++;
						break;
						
					}
					else
					{
						move = 1; // move was initially 4 so now go back and try the west
						flagSouth = true;
					}
				}
				
				// If west, east, and south cells are all occupied
				if(flagWest && flagEast && flagSouth)
				{
					// all possible spaces occupied so ant does not move
					break;
				}
			}
		}
		
		// Not adjacent to any edge
		else //if(!noAnt)
		{	
			while(1) 
			{	
				//cout << "In loop 9" << endl;
				if( move == 1)
				{//Move west
					//cout << "In west" << endl;
					if (cBoard[inRow][inColumn-1] == NULL && flagWest==false)
					{
						//cout << " In if 1" << endl;
						starveCount++;
						std::swap(cBoard[inRow][inColumn-1], cBoard[inRow][inColumn]);
						break;
					}
					else
					{
						//cout << " in else 1" << endl;			
						move = 2; // try the north next
						flagWest = true;
					}
				}
				if(move ==2)
				{//Move north
					//cout << "In north" << endl;
					if (cBoard[inRow-1][inColumn] == NULL && flagNorth == false)
					{
						//cout << " In if 2" << endl;
						std::swap(cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 3;
						flagNorth = true;
					}
				}
				if(move ==3)
				{//Move east
					//cout << "In east" << endl;
					if (cBoard[inRow][inColumn+1] == NULL && flagEast == false)
					{
						//cout << " In if 3" << endl;
						std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 4;
						flagEast = true;
					}
				}
				
				if (move == 4)
				{//Move south
					//cout << "In south" << endl;
					if (cBoard[inRow+1][inColumn] == NULL && flagSouth == false)
					{
						//cout << " In if 4" << endl;
						std::swap(cBoard[inRow+1][inColumn],cBoard[inRow][inColumn]);
						starveCount++;
						break;
					}
					else
					{
						move = 1; // move was initially 4 so now go back and try the west
						flagSouth = true;
					}
				}
				//cout << "Still in 9" << endl;
				// If west, north, east, and south cells are all occupied
				if(flagWest && flagNorth && flagEast && flagSouth)
				{
					// All adjacent cells occupied. Break out
					starveCount++;
					break;
				}
			}	
		}

		moveCount++;
		
	}
	survive++; // this is to know if doodlebug can breed
	if(survive > 0 && survive%8 == 0)
	{ 
		breed(inRow,inColumn,cBoard,row,col);
		//cout <<"DoodleBug just called breed"<<endl;
	}
	//survive++; // this is to know if doodlebug can breed
}


