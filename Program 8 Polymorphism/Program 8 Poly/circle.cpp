/****************************************************************************************
Function:Circle
Inputs:r, a, b
Outputs:
-----------------------------------------------------------------------------------------
Summary:Constructor for circle which uses the point from Point and then creates radius

Pseudo:
Constructor calls for point, then initializes radius
*****************************************************************************************/

#include <iomanip>
#include <iostream>
using namespace std;

using std::ios;

using std::setiosflags;

using std::setprecision;

#include "circle.h"

																						// Constructor for Circle calls constructor for Point

																						// with a member initializer and initializes radius

Circle::Circle(double r, int a, int b)

	: Point(a, b)																		// call base-class constructor
	
{ setRadius(r); }

/****************************************************************************************
Function:setRadius

Summary:sets radius 
-----------------------------------------------------------------------------------------
Pseudo:
sets radius equal to the proper value for r
*****************************************************************************************/

void Circle::setRadius(double r)

{ radius = (r >= 0 ? r : 0); }																//sets radius



/****************************************************************************************
Function:getRadius

Summary:gets radius from current value to output
-----------------------------------------------------------------------------------------
Pseudo:
Returns radius
*****************************************************************************************/

double Circle::getRadius()const { return radius; }											// Get radius



/****************************************************************************************
Function:area

Summary:calculates area
-----------------------------------------------------------------------------------------
Pseudo:
returns pi * radius * radius
*****************************************************************************************/

double Circle::area()const

{return 3.14159 * radius * radius; }														// Calculate area of Circle



/****************************************************************************************
Function:Output

Summary:Creates an output for Main.cpp
-----------------------------------------------------------------------------------------
Pseudo:
Creates the cout to work in the virtual print function in shape.h
*****************************************************************************************/

void Circle::printShape(ostream &output) const {
	cout << "Circle with center : " << '[' << x << ", " << y << ']'

		<< "; Radius = "

		<< setiosflags(ios::fixed | ios::showpoint)											//Creates the cout to work in the virtual print function in shape.h

		<< setprecision(2) << radius << "; Area = " << area();
}