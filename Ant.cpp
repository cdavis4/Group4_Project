/**************************************
 ** Author: Group 4
 ** Date:July 25, 2018
 ** Description: Group Project; Ant Class
 ****************************************/

#include "Ant.hpp"
#include <cstdlib>
#include <iostream>
#include <random>

/*********************************************************
 * Ant no-args contructor:
 * Takes no parameters.  It initializes the member 
 * variable survive to zero.
 ****************************************************/
Ant::Ant()
{
	survive = 0;	
}

/*************************************************
 * Ant::getType()
 * gets the type of critter
 **************************************************/
TYPE Ant::getType()
{
    return ANT;
}


/*************************************************
 * Ant::getSurvive()
 * A getter function that takes no parameters
 * returns an int.  It gets the
 * survival days of Ant
 **************************************************/
int Ant::getSurvive()
{
    return survive;
}


/*************************************************
 * Ant::breed()
 * A function that takes 5 parameters: 2 int 
 * parameters for the coordinates, a 2d array of
 * Critter pointers and two ints for the row
 * and columns of the board.  It returns
 * nothing (void).  It checks the board
 * for the current coordinates of the Ant
 * and returns a pointer to an Ant.
 **************************************************/
void Ant::breed(int inRow, int inColumn, Critter*** cBoard, int row, int col)
{

    int searchCounter = 0;
    random_device rd; //seed needs to be on outside of loop
	
    while(searchCounter < 8 )
     {
        
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(-1,1);
        int genRowNum = dist(gen);
        int genColNum = dist(gen);
      
		
        int randomRow = genRowNum + inRow;
	int randomColumn = genColNum + inColumn;
		
		
        if((randomColumn <= col )&&(randomRow <= row )&&(randomColumn >= 0)&&(randomRow >= 0))
        {
           
            if(cBoard[randomRow][randomColumn] == NULL)
            {
				
                cBoard[randomRow][randomColumn]= new Ant;
                cBoard[randomRow][randomColumn]->setSurvive(0);
		searchCounter = 8;
				
            }
                
            else if ((randomRow ==inRow+1) && (randomColumn == inColumn+1))
            { searchCounter++;}
            else if ((randomRow == inRow) && (randomColumn == inColumn+1))
            { searchCounter++;}
            else if ((randomRow == inRow+1)&&(randomColumn == inColumn))
            { searchCounter++;}
            else if ((randomRow == inRow-1) && (randomRow == inColumn+1))
            { searchCounter++;}
            else if ((randomRow == inRow-1)&&(randomColumn == inColumn))
            { searchCounter++;}
            else if ((randomRow == inRow+1) &&(randomColumn == inColumn-1))
            { searchCounter++;}
            else if ((randomRow == inRow)&& (randomColumn == inColumn-1))
            { searchCounter++;}
            else if ((randomRow == inRow-1)&&(randomColumn == inColumn-1))
            { searchCounter++;}
        }
    }
}

void Ant::move(int inRow, int inColumn, Critter*** cBoard, int row, int col)
{
	row--;
	col--;
	// when these flags are set to true, the direction is no longer available
	bool flagWest = false;
	bool flagNorth = false;
	bool flagEast = false;
	bool flagSouth = false;
	int move = rand()%4+1;
	
	if (moveCount == 0)
	{
		// At southeast corner (lower right)
		if (inRow == row && inColumn == col)
		{
			while(1) 
			{	
				if(move == 3 || move == 4) // can't move east or south b/c they face the edges of the board
				{
					// ant unable to move b/c it hits an edge
					break;
				}
				if( move == 1)
				{//Move west
					if (cBoard[inRow][inColumn-1] == NULL && flagWest == false)
					{
						std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
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
						std::swap (cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
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
		else if(inRow == row && inColumn == 0)
		{
			while(1) 
			{	
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
		else if (inRow == 0 && inColumn == 0)
		{
			while(1) 
			{	
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
		else if (inRow == 0 && inColumn == col)
		{
			while(1) 
			{	
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
		else if ( inRow == row)
		{
			while(1) 
			{	
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
		else if (inColumn == 0)
		{
			while(1) 
			{	
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
						break;
					}
					else
					{
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
		else if(inRow == 0)
		{
			while(1) 
			{	
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
		else
		{	
			while(1) 
			{	
				if( move == 1)
				{//Move west
					if (cBoard[inRow][inColumn-1] == NULL && flagWest==false)
					{
						std::swap(cBoard[inRow][inColumn-1], cBoard[inRow][inColumn]);
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
					if (cBoard[inRow][inColumn+1] == NULL && flagEast == false)
					{
						std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
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
					if (cBoard[inRow+1][inColumn] == NULL && flagSouth == false)
					{
						std::swap(cBoard[inRow+1][inColumn],cBoard[inRow][inColumn]);
						break;
					}
					else
					{
						move = 1; // move was initially 4 so now go back and try the west
						flagSouth = true;
					}
				}
				// If west, north, east, and south cells are all occupied
				if(flagWest && flagNorth && flagEast && flagSouth)
				{
					// All adjacent cells occupied. Break out
					break;
				}
			}	
		}

		moveCount++;
		
		
		if(survive > 0 && survive %3 == 0)
		{ 
			breed(inRow,inColumn,cBoard,row,col);
			//cout <<"Ant just called breed"<<endl;
		}
		survive++; // this is to know if ant can breed
	}
}

