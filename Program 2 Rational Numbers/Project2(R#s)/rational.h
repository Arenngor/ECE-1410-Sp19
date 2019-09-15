/*******************************************************************************************

Summary: Creates rational class
input: num, den
output:none
********************************************************************************************
Creates Rational class to be used throughout funtion
Stores variables for Rational
Set ifndef and endif for Rational.h
*******************************************************************************************/

#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;
									//begin
class Rational						//Creates Rational class to be used throughout funtion
{
private:							//stores functions to be called
	int num, den;

public:
	Rational(int n, int d);
	int gcd(int, int d);
	void add(int n, int d);
	void sub(int n, int d);
	void mul(int n, int d);
	void div(int n, int d);
	void simp();
	void out();

};
#endif