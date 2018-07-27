/**************************************
 ** Author: Group 4 Project
 ** Date:July 22, 2018
 ** Description: Ant Class
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
 * Ant::setType()
 * gets the type of critter
 **************************************************/
void Ant::setSurvive(int inSurviveSteps)
{
    survive = inSurviveSteps;
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
Ant* Ant::breed()
{

  Ant* babyAnt;
    babyAnt = new Ant;
    
    return babyAnt;
    
 
}
/***************
 * Ant::move
 * Moves critter one step at its current position
 * changing its position
 * place the Ant at its new position.
 ****************************************************/

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
        survive++; // this is to know if ant can breed
        if(survive >= 3)
        { breed();}
	}

}
