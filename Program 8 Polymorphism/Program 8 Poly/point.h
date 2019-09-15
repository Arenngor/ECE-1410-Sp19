/****************************************************************************************
Function:Point header
Inputs:
Outputs:
-----------------------------------------------------------------------------------------
Summary:Creates functions for Point.cpp to use and holds x and y

Pseudo:
Create default constructor
Create set coordiantes func
Create get coordinates func
Set virtual print function from shape
Add x and y to protected
*****************************************************************************************/


#ifndef POINT_H
#define POINT_H
#include<iostream>
#include "shape.h"

using std::ostream;

class Point: public Shape {
//friend ostream &operator<<(ostream &output,const Point &p);

 public:
Point(int = 0,int = 0);										// default constructor
  void setPoint(int,int);									// set coordinates
 
  int getX()const { return x; }								// get x coordinate
 
  int getY()const { return y; }								// get y coordinate

  virtual void printShape(ostream &output) const;			//Set the virtual print from shape.h
															
 protected:													// accessible by derived classes
 int x, y;													// x and y coordinates of the Point
};
#endif