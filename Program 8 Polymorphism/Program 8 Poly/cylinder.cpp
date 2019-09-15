/****************************************************************************************
Function:Cylinder
Inputs:
Outputs:
-----------------------------------------------------------------------------------------
Summary:Call circles constructor to pass in values

Pseudo:
Call base constructor
then use Setheight func for the cylinder
*****************************************************************************************/

#include "cylinder.h"
#include <iostream>
using namespace std;

															// Cylinder constructor calls Circle constructor

Cylinder::Cylinder(double h, double r, int x, int y)

	: Circle(r, x, y)										// call base constructor
	
{ setHeight(h); }

															
/****************************************************************************************
Function:setHeight

Summary:sets height of cylinder to h
-----------------------------------------------------------------------------------------
Pseudo:
Sets height equal to h
*****************************************************************************************/
void Cylinder::setHeight(double h)

{ height = (h >= 0 ? h : 0); }								// Set height of Cylinder

															
/****************************************************************************************
Function:getHeight

Summary:gets height of cylinder for output
-----------------------------------------------------------------------------------------
Pseudo:
returns height

*****************************************************************************************/
double Cylinder::getHeight()const { return height; }		// Get height of Cylinder

															
/****************************************************************************************
Function:area

Summary:Calculates area of cylinder
-----------------------------------------------------------------------------------------
Pseudo:
Calculates the area using the area function and then returns it as area
*****************************************************************************************/
double Cylinder::area()const

{
	
		return 2 * Circle::area() +
		
		2 * 3.14159 * radius * height;						// Calculate area of Cylinder
	
}

															
/****************************************************************************************
Function:volume

Summary:Calculates volume of the cylinder
-----------------------------------------------------------------------------------------
Pseudo:
returns the area multiplied by the height of cylinder. 
*****************************************************************************************/
double Cylinder::volume()const

{return Circle::area() * height; }							// Calculate volume of Cylinder

															
/****************************************************************************************
Function:Output

Summary:Uses static casting and current values to output the dimensions of cylinder
-----------------------------------------------------------------------------------------
Pseudo:
Use the virtual printing function to display the values for the cylinder along with the values from point and circle
*****************************************************************************************/

void Cylinder ::printShape(ostream &output) const { cout << "Cylinder with center : " << '[' << x << ", " << y << ']' << "; Height = " << height << "; Area = " << area() << "; Volume = " << volume(); }