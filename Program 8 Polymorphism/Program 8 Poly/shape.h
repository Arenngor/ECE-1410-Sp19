/****************************************************************************
Function: Shape
-----------------------------------------------------------------------------
Summary: Create class and functions for shape
Pseudo: Create base class for shape
Set pointers and operators
Crreate virtual functions for cylinder and cirlce and then for printing
****************************************************************************/

#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;

class Shape {																										//create base class for shape
	friend ostream &operator<<(ostream &output, const Shape &sh) { sh.printShape(output); return output; }			//Set pointers and operators
public:
	virtual double area() const { return 0.0; }																		//Create virtual functions for cylinder and cirlce and then for printing
	virtual double volume() const { return 0.0; }
	virtual void printShape(ostream &output) const = 0;

};
#endif