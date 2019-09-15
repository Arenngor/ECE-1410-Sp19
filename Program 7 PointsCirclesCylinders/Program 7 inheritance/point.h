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
Add x and y to protected
*****************************************************************************************/


#ifndef POINT_H
#define POINT_H
#include<iostream>

using std::ostream;

class Point{
 friend ostream &operator<<(ostream &,const Point &);

 public:
Point(int = 0,int = 0);// default constructor
  void setPoint(int,int);// set coordinates
 
  int getX()const { return x; }// get x coordinate
 
  int getY()const { return y; }// get y coordinate
 protected: // accessible by derived classes
 int x, y;// x and y coordinates of the Point
};
#endif