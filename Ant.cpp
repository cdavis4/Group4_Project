/**************************************
 ** Author: carrie davis
 ** Date:July 22, 2018
 ** Description: Project 2; Tiger
 ****************************************/

#include "Ant.hpp"
#include <cstdlib>
#include <iostream>
#include <random>

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
 * gets survival days of Ant
 **************************************************/
int Ant::getSurvive()
{
    return survive;
}

/*************************************************
 * Ant::breed()
 * gets the type of critter
 **************************************************/
 /*
Ant* Ant::breed(int inRow, int inColumn)
{

    Ant* babyAnt;
    babyAnt = new Ant(inRow,inColumn,0);  // zero represents survival
    
    return babyAnt;
 
}
*/
/***************
 * Ant::move
 * Moves critter one step at its current position
 * changing its position
 * place the Doodle at its new position.
 ****************************************************/
/*
void Ant::move(int &inRow, int &inColumn)
{
    //could randomize here
	// COMMENTED THIS OUT TEMPORARILY UNTIL WE HAVE IT WORKING - Patrick 5:17pm 7/26
    //getPosition(inRow,inColumn);  //not sure if this is just an unnecessary step 
    //do checks then
    setPosition(inRow,inColumn);
    survive++; //update that the ant has survived to move again 

    //could call breed from here 
    int babyrow = inRow; int babycolumn = inColumn
    if(survival >= 3)
    {
     //randomize check if cell is empty (our array should be bool? Using NULL to initalize.
     breed(2DArraylocation);
	
}
*/


/*************************************************
 * Ant::breed()
 * gets the type of critter
 **************************************************/
void Ant::breed(int inRow, int inColumn, Critter*** cBoard, int row, int col)
{

 //cout <<"Ant is inprocess of breeding"<<endl;
	
	
    int searchCounter = 0;
	random_device rd; //seed needs to be on outside of loop
	
    while(searchCounter < 8 )
     {
        
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(-1,1);
        int genRowNum = dist(gen);
        int genColNum = dist(gen);
        //cout << genRowNum << genColNum <<endl;
		
        int randomRow = genRowNum + inRow;
		int randomColumn = genColNum + inColumn;
		
		//cout << "Row: " << row << " Column: " << col << endl; 
       // cout <<"RandomRow " <<randomRow <<" RandomColumn "<<randomColumn <<endl;
        if((randomColumn <= col )&&(randomRow <= row )&&(randomColumn >= 0)&&(randomRow >= 0))
        {
           // if(cBoard[randomRow][randomColumn] != NULL);
            //cout << "inRow: " << inRow << " inColumn: " << inColumn << endl;
            if(cBoard[randomRow][randomColumn] == NULL)
            {
				//cout << "1" << endl;
                cBoard[randomRow][randomColumn]= new Ant;
                cBoard[randomRow][randomColumn]->setSurvive(0);
				searchCounter = 8;
				//cout <<"had baby" <<endl;
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

void Ant::move(int inRow, int inColumn, Critter*** cBoard, int row, int col)
{
		//bool hasMoved = false;
		
		/*
		if(inRow >= 0 && inRow+1 <= row && inColumn >= 0 && inColumn+1 <= col)
		{
			
			if(cBoard[inRow][inColumn+1] == NULL) //&& !hasMoved)
			{
				//cout << "Moved from " << inRow << "," << inColumn << " to " << inRow << "," << inColumn+1 << endl;
				std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
				hasMoved = true;
				//cBoard[inRow+1][inColumn+1] = new Ant;
				//delete cBoard[inRow][inColumn];
				//cBoard[inRow][inColumn] = NULL;
			}
		}
		
		
		*/
		
	// Sets row and column to a value in range 0 to row-1/col-1 (exclusive range)
	
	// 1 west, 2 north, 3 east, 4 south
	// the if-else statements follow a clockwise pattern (ie if first checking west: west->north->east->south)
	
	
	
	//cout << "Moving ant number " << antNum << endl;

	row--;
	col--;
	// when these flags are set to true, the direction is no longer available
	bool flagWest = false;
	bool flagNorth = false;
	bool flagEast = false;
	bool flagSouth = false;
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
				//cout << "In loop 6" << endl;
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
				//cout << "In loop 9" << endl;
				if( move == 1)
				{//Move west
					//cout << "In west" << endl;
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
					//cout << "In north" << endl;
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
					//cout << "In east" << endl;
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
					//cout << "In south" << endl;
					if (cBoard[inRow+1][inColumn] == NULL && flagSouth == false)
					{
						//Critter *temp = ***cBoard[inRow][inColumn];
						std::swap(cBoard[inRow+1][inColumn],cBoard[inRow][inColumn]);
						//delete []cBoard[inRow][inColumn];
						//searchFlag = false;
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
