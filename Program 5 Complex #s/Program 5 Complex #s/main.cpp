#include <iostream>
#include "MyComplex.h"
using namespace std;
int main()
{
	MyComplex a(3.0, 2.5);
	MyComplex b(1.2, 4.4);
	MyComplex c;
	c = a - b;
	c.printMyComplex();
	system("pause");
	return 0;
}