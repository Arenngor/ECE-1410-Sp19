/****************************************************************************************
Function:Point
Inputs:a, b
Outputs:
-----------------------------------------------------------------------------------------
Summary: Create constructor for point and then intake values to use as the coordinates.

Pseudo:
Create constructor for Point.
*****************************************************************************************/

#include<iostream>
#include"point.h"
																			// Constructor for class Point
Point::Point(int a, int b) { setPoint(a, b); }
																			
/****************************************************************************************
Function:setPoint

Summary:sets x and y equal to the input values
-----------------------------------------------------------------------------------------
Pseudo:
sets x = a and y = b
*****************************************************************************************/

void Point::setPoint(int a, int b)
{

		x = a;

		y = b;																// Set x and y coordinates of Point
}
	
/****************************************************************************************
Function:printShape

Summary:creates an output for printing
-----------------------------------------------------------------------------------------
Pseudo:
Prints point in readable format used in virtual printing func
*****************************************************************************************/

void Point::printShape(ostream &output) const { cout << "Point at : " << '[' << x << ", " << y << ']';
}
