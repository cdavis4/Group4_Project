/**************************************
 ** Author: carrie davis
 ** Date:July 22, 2018
 ** Description: Project 2; Tiger
 ****************************************/
#include <iostream>
#include <cstdlib>

#include "Ant.hpp"


Ant::Ant()
{}

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
Ant* Ant::breed(int inRow, int inColumn)
{

    Ant* babyAnt;
    babyAnt = new Ant(inRow,inColumn,0);  // zero represents survival
    
    return babyAnt;
 
}
/***************
 * Ant::move
 * Moves critter one step at its current position
 * changing its position
 * place the Doodle at its new position.
 ****************************************************/
void Ant::move(int &inRow, int &inColumn)
{
    //could randomize here
	// COMMENTED THIS OUT TEMPORARILY UNTIL WE HAVE IT WORKING - Patrick 5:17pm 7/26
    //getPosition(inRow,inColumn);  //not sure if this is just an unnecessary step 
    //do checks then
    setPosition(inRow,inColumn);
    survive++; //update that the ant has survived to move again 
    /* could call breed from here 
    int babyrow = inRow; int babycolumn = inColumn
    if(survival >= 3)
    {
     //randomize check if cell is empty (our array should be bool? Using NULL to initalize.
     breed(2DArraylocation);
     */
}
void Ant::move(int inRow, int inColumn, Critter*** cBoard, int row, int col)
{
		row--;
		col--;
		if (moveCount == 0)
		{
		//Critter *antTemp = **cBoard;
		//unsigned seed = time(0);  -> only need to set srand() once in main
		//srand(seed);
		
		
		
		if (inRow == row && inColumn == col)
		{
			
			bool searchFlag = true;
			bool flag1 = false;
			bool flag2 = false;
			int move = rand()%2+1;
			while(searchFlag == true )
			{	if( move == 1)
			{//Move west
				if (cBoard[inRow][inColumn-1] == NULL && flag1 == false)
				{
					std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
					//	delete []cBoard[inRow][inColumn];
					flag1 = true;
					searchFlag = false;
				}
				else
				{
					move = 2;
					flag1 = true;
				}
			}
				
				if(move ==2)
				{//Move north
					if (cBoard[inRow-1][inColumn] == NULL && flag2 == false)
					{
						std::swap (cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
						//		delete []cBoard[inRow][inColumn];
						searchFlag = false;
					}
					else
					{
						move = 1;
						flag2 = true;
					}
				}
			}
		}
		else if(inRow == row && inColumn == 0)
		{
			
			bool searchFlag = true;
			bool flag1 = false;
			bool flag2 = false;
			int move = rand()%2+1;
			while(searchFlag == true )
			{	if( move == 1)
			{//Move east
				if (cBoard[inRow][inColumn+1] == NULL && flag1 == false)
				{
					std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
					//	delete []cBoard[inRow][inColumn];
					flag1 = true;
					searchFlag = false;
				}
				else
				{
					move = 2;
					flag1 = true;
				}
			}
				
				if(move ==2)
				{//Move north
					if (cBoard[inRow-1][inColumn] == NULL && flag2 == false)
					{
						std::swap(cBoard[inRow-1][inColumn], cBoard[inRow][inColumn]);
						//	delete []cBoard[inRow][inColumn];
						searchFlag = false;
					}
					else
					{
						move = 1;
						flag2 = true;
					}
				}
			}
			
		}
		
		
		
		
		
		else if (inRow == 0 && inColumn == 0)
		{
			
			bool searchFlag = true;
			bool flag1 = false;
			bool flag2 = false;
			int move = rand()%2+1;
			while(searchFlag == true)
			{	if( move == 1)
			{//Move east
				if (cBoard[inRow][inColumn+1] == NULL && flag1 == false)
				{
					std::swap(cBoard[inRow][inColumn+1], cBoard[inRow][inColumn]);
				//	delete []cBoard[inRow][inColumn];
					flag1 = true;
					searchFlag = false;
				}
				else
				{
					move = 2;
					flag1 = true;
				}
			}
				if (move == 2)
				{//Move south
					if (cBoard[inRow+1][inColumn] == NULL && flag2 == false)
					{
						std::swap(cBoard[inRow+1][inColumn],cBoard[inRow][inColumn]);
					//	delete []cBoard[inRow][inColumn];
						searchFlag = false;
					}
					else
					{
						move = 1;
						flag2 = true;
					}
				}
			}
		}
		else if (inRow == 0 && inColumn == col)
		{
			bool searchFlag = true;
			bool flag1 = false;
			bool flag2 = false;
			int move = rand()%2+1;
			while(searchFlag == true )
			{	if( move == 1)
			{//Move west
				if (cBoard[inRow][inColumn-1] == NULL && flag1 == false)
				{
					std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
				//	delete []cBoard[inRow][inColumn];
					flag1 = true;
					searchFlag = false;
				}
				else
				{
					move = 2;
					flag1 = true;
				}
			}
				if (move == 2)
				{//Move south
					if (cBoard[inRow+1][inColumn] == NULL && flag2== false)
					{
						std::swap(cBoard[inRow+1][inColumn], cBoard[inRow][inColumn]);
				//		delete []cBoard[inRow][inColumn];
						searchFlag = false;
					}
					else
					{
						move = 1;
						flag2 = true;
					}
				}
			}
		}
		else if ( inRow == row)
		{
			bool searchFlag = true;
			bool flag1 = false;
			bool flag2 = false;
			bool flag3 = false;
			int move = rand()%3+1;
			while(searchFlag == true)
			{	if( move == 1)
			{//Move west
				if (cBoard[inRow][inColumn-1] == NULL && flag1 == false)
				{
					std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
					//delete []cBoard[inRow][inColumn];
					flag1 = true;
					searchFlag = false;
				}
				else
				{
					move = 2;
					flag1 = true;
				}
			}
				if (move == 2)
				{//Move north
					if (cBoard[inRow-1][inColumn] == NULL && flag2 == false)
					{
						std::swap(cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
						//delete []cBoard[inRow][inColumn];
						searchFlag = false;
					}
					else
					{
						move = 3;
						flag2 = true;
					}
				}
				if(move ==3)
				{//Move east
					if (cBoard[inRow][inColumn+1] == NULL && flag3== false)
					{
						std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
						//delete []cBoard[inRow][inColumn];
						searchFlag = false;
					}
					else
					{
						move = 1;
						flag3 = true;
					}
				}
			}
		}
		else if (inColumn == 0)
		{
			bool searchFlag = true;
			bool flag1 = false;
			bool flag2 = false;
			bool flag3 = false;
			int move = rand()%3+1;
			while(searchFlag == true)
			{	if( move == 1)
				{//Move east
					if (flag1==false)
					{
						if (cBoard[inRow][inColumn+1] == NULL)
						{
							std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
							//delete []cBoard[inRow][inColumn];
							//flag1 = true;
							searchFlag = false;
						}
						else
						{
							move = 2;
							flag1 = true;
						}
					}
				}
				if (move == 2)
				{//Move south
					if(flag2==false)
					{
						if (cBoard[inRow+1][inColumn] == NULL)
						{
							std::swap(cBoard[inRow+1][inColumn], cBoard[inRow][inColumn]);
							//	delete []cBoard[inRow][inColumn];
							searchFlag = false;
						}
						else
						{
							move = 3;
							flag2 = true;
						}
					}
				}
				if(move ==3)
				{//Move north
					if(flag3==false)
					{
						if (cBoard[inRow-1][inColumn] == NULL )
						{
							std::swap(cBoard[inRow-1][inColumn], cBoard[inRow][inColumn]);
							//	delete []cBoard[inRow][inColumn];
							searchFlag = false;
						}
						else
						{
							move = 1;
							flag3 = true;
						}
					}
				}
			}
		}
		
		else if (inColumn == col)
		{
			
			bool searchFlag = true;
			bool flag1 = false;
			bool flag2 = false;
			bool flag3 = false;
			int move = rand()%3+1;
			while(searchFlag == true )
			{	if( move == 1)
			{//Move west
				if (cBoard[inRow][inColumn-1] == NULL && flag1 == false)
				{
					std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
					//delete []cBoard[inRow][inColumn];
					flag1 = true;
					searchFlag = false;
				}
				else
				{
					move = 2;
					flag1 = true;
				}
			}
				if (move == 2)
				{//Move south
					if (cBoard[inRow+1][inColumn] == NULL && flag2 == false)
					{
						std::swap(cBoard[inRow+1][inColumn], cBoard[inRow][inColumn]);
						//	delete []cBoard[inRow][inColumn];
						searchFlag = false;
					}
					else
					{
						move = 3;
						flag2 = true;
					}
				}
				if(move ==3)
				{//Move north
					if (cBoard[inRow-1][inColumn] == NULL && flag3 == false)
					{
						std::swap(cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
						//	delete []cBoard[inRow][inColumn];
						searchFlag = false;
					}
					else
					{
						move = 1;
						flag3 = true;
					}
				}
			}
		}
		else if(inRow == 0)
		{
			bool searchFlag = true;
			bool flag1 = false;
			bool flag2 = false;
			bool flag3 = false;
			int move = rand()%3+1;
			while(searchFlag == true)
			{	if( move == 1)
			{//Move west
				if (cBoard[inRow][inColumn-1] == NULL && flag1 == false)
				{
					std::swap(cBoard[inRow][inColumn-1],cBoard[inRow][inColumn]);
					//delete []cBoard[inRow][inColumn];
					flag1 = true;
					searchFlag = false;
				}
				else
				{
					move = 2;
					flag1 = true;
				}
			}
				if (move == 2)
				{//Move south
					if (cBoard[inRow+1][inColumn] == NULL && flag2 == false)
					{
						std::swap(cBoard[inRow+1][inColumn], cBoard[inRow][inColumn]);
						//delete []cBoard[inRow][inColumn];
						searchFlag = false;
					}
					else
					{
						move = 1;
						flag2 = true;
					}
				}
				if(move ==3)
				{//Move east
					if (cBoard[inRow][inColumn+1] == NULL && flag3 == false)
					{
						std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
						//delete []cBoard[inRow][inColumn];
						searchFlag = false;
					}
					else
					{
						move = 1;
						flag3 = true;
					}
				}
			}
		}
		else
		{	bool searchFlag = true;
		bool flag1 = false;
		bool flag2 = false;
		bool flag3 = false;
			bool flag4 = false;
		int move = rand()%4+1;
		while(searchFlag == true )
		{	if( move == 1)
		{//Move west
			if (cBoard[inRow][inColumn-1] == NULL && flag1==false)
			{
				std::swap(cBoard[inRow][inColumn-1], cBoard[inRow][inColumn]);
				//delete []cBoard[inRow][inColumn];
				flag1 = true;
				searchFlag = false;
			}
			else
			{
				move = 2;
				flag1 = true;
			}
		}
			if (move == 2)
			{//Move south
				if (cBoard[inRow+1][inColumn] == NULL && flag2 == false)
				{
					//Critter *temp = ***cBoard[inRow][inColumn];
					std::swap(cBoard[inRow+1][inColumn],cBoard[inRow][inColumn]);
					//delete []cBoard[inRow][inColumn];
					searchFlag = false;
				}
				else
				{
					move = 3;
					flag2 = true;
				}
			}
			if(move ==3)
			{//Move east
				if (cBoard[inRow][inColumn+1] == NULL && flag3 == false)
				{
					std::swap(cBoard[inRow][inColumn+1],cBoard[inRow][inColumn]);
					//delete []cBoard[inRow][inColumn];
					searchFlag = false;
				}
				else
				{
					move = 4;
					flag3 = true;
				}
			}
			if(move ==4)
			{//Move north
				if (cBoard[inRow-1][inColumn] == NULL && flag4 == false)
				{
					std::swap(cBoard[inRow-1][inColumn],cBoard[inRow][inColumn]);
				//	delete cBoard[inRow][inColumn];
					searchFlag = false;
				}
				else
				{
					move = 1;
					flag4 = true;
				}
			}
		}
			
		}
	
 
		moveCount++;
	}

}
