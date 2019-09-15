/*****************************************************************
Function:sudoku
Inputs:x , y
Outputs:

Summary:
Makes sure that it is ready to solve next square
then uses x and y counters to move accross board

Pseudocode:
While y is not negative and not over 9, move through y
While x is not negative and not over 9, move through x

*****************************************************************/
#include "Sudoku.h"
#include <iostream>

sudoku::sudoku() 
{
	debug = false;

	for (int y = 0; y < 9; y++) {				//While y is not negative and not over 9, move through y
		for (int x = 0; x < 9; x++) {			//While x is not negative and not over 9, move through x
			board[x][y] = 0;
		}
	}
}

/*****************************************************************
Function:Print
Inputs:board[x][y]
Outputs: cout

Summary:
Prints out the current grid and also prints out the grid styling

Pseudocode:
move through y in order to print proper grid
move through x in order to print proper grid

*****************************************************************/

void sudoku::print() 
{
	for (int y = 0; y < 9; y++)
	{
		if (y % 3 == 0) 
		{
			std::cout << "-------------------------------" << std::endl;			//move through y in order to print proper grid, after every 3 y's print a line through grid
		}

		for (int x = 0; x < 9; x++)													//move through x in order to print proper grid
		{
			if (x % 3 == 0) 
			{
				std::cout << "|";													//after 3rd x print | to make easier viewing
			}

			if (board[x][y] != 0) 
			{
				std::cout << " " << board[x][y] << " ";								//Print board to screen after printing the beginning layout
			}
			else 
			{
				std::cout << " . ";
			}

		}

		
		std::cout << "|" << std::endl;
	}
	std::cout << "-------------------------------" << std::endl;

} 

/*****************************************************************
Function:setval
Inputs:x, y and value
Outputs:

Summary:
When called, will replace current value or * with a new value

Pseudocode:
set the new value at the spefic grid coorinates

*****************************************************************/

void sudoku::setval(int x_cord, int y_cord, int value) 
{
	board[x_cord][y_cord] = value;												//set the new value at the spefic grid coorinates
}


/*****************************************************************
Function:solve bool
Inputs:
Outputs:true, false

Summary:
If solved, solve will return true and allow the program to continue moving on, if false, the program will print the unsolveable message

Pseudocode:
returns value for solve

*****************************************************************/

bool sudoku::solve()
{
	return solve(0, 0);
}


/*****************************************************************
Function:Getboardvalue
Inputs:x and y coordinates
Outputs:

Summary:
Used to get the coordinates of the current location on the board

Pseudocode:
returns the vurrent value of x and y coordinates so that the current location can be found

*****************************************************************/

int sudoku::getBoardValue(int x_cord, int y_cord) 
{
	return board[x_cord][y_cord];													//returns the vurrent value of x and y coordinates so that the current location can be found
}

/*****************************************************************
Function:solve
Inputs: x and y coords
Outputs:

Summary:
moves around the grid verifying and solving boxes

Pseudocode:
Checks to make sure it is in the proper locations
Checks to make sure grid is verified
Checks to make sure there are the proper amount of values on the board
Then, moves down the x coordinates
Once it hits the barrier of board, it will move down the y coordinates
Verifies it is solveable, if not it triggers the error message with bool
For loop
when value is not outside of 1-9, add 1 to value
sets value on board to solved value
verifies again
repeats process moving down the grid

*****************************************************************/

bool sudoku::solve(int x_cord, int y_cord) 
{

	if (board[x_cord][y_cord] != 0)											//Checks to make sure it is in the proper locations
	{

		if (verify(x_cord, y_cord))											//Checks to make sure grid is verified
		{

			if (x_cord == 8 && y_cord == 8)									//Checks to make sure there are the proper amount of values on the board
			{
				return true;
			}

			int next_x = x_cord + 1;										//Then, moves down the x coordinates
			int next_y = y_cord;

			if (next_x >= 9)												//Once it hits the barrier of board, it will move down the y coordinates
			{
				next_x = 0;
				next_y++;
			}
			return solve(next_x, next_y);
		}																	//Verifies it is solveable, if not it triggers the error message with bool

		else {
			return false;
		}

	}
	for (int val = 1; val < 10; val++)										//For loop for when value is in correct parameters
	{																		//when value is not outside of 1-9, add 1 to value

		setval(x_cord, y_cord, val);										//sets value on board to solved value

		if (verify(x_cord, y_cord)) 
		{																	//verifies again


			if (x_cord == 8 && y_cord == 8)									//repeats process moving down the grid
			{
				return true;
			}
			int next_x = x_cord + 1;
			int next_y = y_cord;

			if (next_x >= 9) 
			{
				next_x = 0;
				next_y++;
			}

			if (solve(next_x, next_y))										//trigger bool solve to return true
			{
				return true;
			}
		}
	}


	board[x_cord][y_cord] = 0;


	return false;															//trigger potential error message

}


/*****************************************************************
Function:verify
Inputs:
Outputs:true, false

Summary:
trys the coordinates, and then tries the current value
then runs through and checks if value can be in its row, column and box

Pseudocode:
runs through try coords to verify location
try current value
moves accross grid to verify all locations
if the x coord is appropriate, return true to continue
if the value cannot be placed at the current box, false
move accross grid to try locations
if y coord is appropriatem return true
if value is not proper, return false
verifies the y coord in the box
verifies the x coord in the box
if both are verified, continue
else, false
*****************************************************************/

bool sudoku::verify(int x_cord, int y_cord) 
{

	trycoords(x_cord, y_cord);												//runs through try coords to verify location

	int value = board[x_cord][y_cord];										//try current value

	for (int x_verify = 0; x_verify < 9; x_verify++)						//moves accross grid to verify all locations
	{
		if (x_verify == x_cord) 
		{
			continue;														//if the x coord is appropriate, return true to continue
		}

		int verify = board[x_verify][y_cord];								//if the value cannot be placed at the current box, false
		if (verify == value) 
		{
			return false;
		}
	}

	
	for (int y_verify = 0; y_verify < 9; y_verify++)						//move accross grid to try locations
	{



		if (y_verify == y_cord)												//if y coord is appropriatem return true
		{
			continue;
		}
		int verify = board[x_cord][y_verify];								//if value is not proper, return false
		if (verify == value)
		{
			return false;
		}
	}

	int box_x = x_cord / 3;
	int box_y = y_cord / 3;

	for (int y_verify = box_y * 3; y_verify < box_y * 3 + 3; y_verify++)				//verifies the y coord in the box
	{
		for (int x_verify = box_x * 3; x_verify < box_x * 3 + 3; x_verify++)			//verifies the x coord in the box
		{
			if (x_verify == x_cord && y_verify == y_cord)								//if both are verified, continue
			{
				continue;
			}

			int verify = board[x_verify][y_verify];										//else, false
			if (verify == value)
			{
				return false;
			}
		}
	}

	return true;

}

/*****************************************************************
Function:Trycoords
Inputs:
Outputs:

Summary:
Checks debug status
Helps to verify location while called in verify later

Pseudocode:
Check debug value
Prints * into board where necessary
*****************************************************************/

void sudoku::trycoords(int x_cord, int y_cord) 
{
	if (debug)													//Check debug value
	{
		for (int i = 0; i < x_cord + y_cord; i++)				//verifies its location making the grid
		{
			std::cout << " ";									//Prints * into board where necessary
		}
	}
}