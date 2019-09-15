/****************************************************************************************
Function:Circle header
Inputs:
Outputs:
-----------------------------------------------------------------------------------------
Summary:Creates base class for circle

Pseudo:
Uses friend function for output
Uses values from point
Creates Constructor with default values at 0
Creates setRadius func
Creates getRadius func
Creates area func
Adds Radius to Protected
*****************************************************************************************/
#ifndef CIRCLE_H
#define CIRCLE_H

#include<iostream>

using std::ostream;

#include "point.h"

class Circle: public Point{

 friend ostream &operator<<(ostream &,const Circle &);

 public:

																			// default constructor

Circle(double r = 0.0, int x = 0, int y = 0);

 void setRadius(double);													// set radius

 double getRadius()const;													// return radius

 double area()const;														// calculate area

 protected:																	// accessible to derived classes

 double radius;																// radius of the Circle

};
#endif