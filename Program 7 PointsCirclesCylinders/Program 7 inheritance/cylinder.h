/****************************************************************************************
Function:Cylinder header
Inputs:
Outputs:
-----------------------------------------------------------------------------------------
Summary:Creates base class for cylinder

Pseudo:
Uses friend function for output
Creates default cylinder values at 0
Creates setheight func
Creates getHeight func
Creates area func
Creates volume func
Adds Height to Protected
*****************************************************************************************/

#ifndef CYLINDER_H
#define CYLINDER_H
#include<iostream>
using std::ostream;
#include "circle.h"

class Cylinder : public Circle{

 friend ostream &operator<<(ostream &,const Cylinder &);

 public:

																// default constructor

Cylinder(double h = 0.0,double r = 0.0,

 int x = 0,int y = 0);

  void setHeight(double);										// set height

 double getHeight()const;										// return height

 double area()const;											// calculate and return area

 double volume()const;											// calculate and return volume

 protected:

 double height;													// height of the Cylinder

};
#endif