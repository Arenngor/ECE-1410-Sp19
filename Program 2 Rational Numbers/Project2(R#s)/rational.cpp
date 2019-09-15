#include "rational.h"
#include <cmath>
#include <iostream>
using namespace std;

/*******************************************************************************************
Func Title: GCD

Summary: Compute lowest common denominator for the fraction entered
input: n, d
output: x, y
********************************************************************************************
Take imput values from Main
If less than 0 change to positive value
While n and d are even
Add 1 to y
while n is not d
Continuously divide as stated in euclidean algorithm until proper value is found
Return x multiplied by 2 to the y power
*******************************************************************************************/

int Rational::gcd(int n, int d)
{
	int x, y;																	//If less than 0 change to positive value
	if (n < 0)
		n -= 2 * n;
	if (d < 0)
		d -= 2 * d;
	y = 0;
while (n % 2 == 0 && d % 2 == 0)												//While n and d are even
	{
		n /= 2;
		d /= 2;
		y += 1;																	//Add 1 to y
	}
while (n != d)																	//while n is not d
	{
		if (n % 2 == 0)
			n /= 2;
		else if (d % 2 == 0)
			d /= 2;
		else if (n > d)
			n = (n - d) / 2;
		else
			d = (d - n) / 2;													//Continuously divide as stated in euclidean algorithm until proper value is found
	}
	x = n;

return (x * pow(2, y));															//Return x multiplied by 2 to the y power
}

/*******************************************************************************************
Func Title:Rational

Summary:sets num and den equal to input values for use in program
input:n, d
output: none
********************************************************************************************
Creates input values for use in class Rational
*******************************************************************************************/

Rational::Rational(int n, int d)
{
	num = n;
	den = d;																	//Creates input values for use in class Rational
}

/*******************************************************************************************
Func Title:add

Summary:adds two fractions together while also getting common denominator and simplifying
input:num, den
output: none
********************************************************************************************
Multiplies num by d and adds it to n times den
then sets den equal to den multiplied by d
Simplifies
*******************************************************************************************/

void Rational::add(int n, int d)
{
	num = (num * d) + (n * den);												//Multiplies num by d and adds it to n times den
	den = den * d;																//then sets den equal to den multiplied by d
	simp();
}

/*******************************************************************************************
Func Title:sub

Summary:subtracts two fractions while also getting common denominator and simplifying
input:num, den
output:
********************************************************************************************
Multiplies num by d and adds it to n times den
then sets den equal to den multiplied by d
Simplifies
*******************************************************************************************/

void Rational::sub(int n, int d)
{
	num = (num * d) - (n * den);												//Multiplies num by d and adds it to n times den
	den = den * d;																//then sets den equal to den multiplied by d
	simp();
}

/*******************************************************************************************
Func Title:mul

Summary: multiplies two fractions together
input:num, den
output:none
********************************************************************************************
Multiply den by d and set den equal to result
Multiply num by n and set num equal to result
simplify result
*******************************************************************************************/

void Rational::mul(int n, int d)
{
	den = den * d;																//Multiply den by d and set den equal to result
	num = num * n;																//Multiply num by n and set num equal to result
	simp();
}

/*******************************************************************************************
Func Title:div

Summary: Divide two fractions
input:num, den
output:none
********************************************************************************************
Multiply den by n and num by d in order to get reciprocal values
Then simplify the result in simp
*******************************************************************************************/

void Rational::div(int n, int d)
{
	den = den * n;																//Multiply den by n and num by d in order to get reciprocal values
	num = num * d;
	simp();
}

/*******************************************************************************************
Func Title:out

Summary:Prints the answer after being simplified
input:none
output:none
********************************************************************************************
Print to screen: num/den
then end line
*******************************************************************************************/

void Rational::out()
{
	std::cout << num << "/" << den << std::endl;									//Print to screen: num/den
}

/*******************************************************************************************
Func Title:simp

Summary:Simplifies the input fractions
input:num, den
output:none
********************************************************************************************
Create a temp variable for num and den in order to not change essential values
set the temps equal to num and den
then, divide the temps by the gcd of the temp numerator and the denominator
*******************************************************************************************/

void Rational::simp()
{
	int tempnum, tempden;															//Create a temp variable for num and den in order to not change essential values
	tempnum = num;																	//set the temps equal to num and den
	tempden = den;

	num = tempnum / gcd(tempnum, den);												//then, divide the temps by the gcd of the temp numerator and the denominator
	den = tempden / gcd(tempnum, den);
}
