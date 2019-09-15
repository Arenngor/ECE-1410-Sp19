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
Function:output

Summary:creates an output for printing
-----------------------------------------------------------------------------------------
Pseudo:
Uses overloaded operators to output the location of the point.
*****************************************************************************************/

ostream &operator<<(ostream &output, const Point &p)
{																			// Output Point (with overloaded stream insertion operator)
		output << "Point at" << '[' << p.x << ", " << p.y << ']';
		return output;
}