/*******************************************************
Rowan Antonuccio
A02184507
Program 1- Quadratic Roots

input.txt

Begin
Set argc and argv
Create floats a, b, c, two answer variables and then two extras for math parts
Begin if statement for program parameters in argc
Set input file stream
While statement to check for end of file
If statement to set variables to be assigned from the input file
Set output file, and set math to be done
Finish math as long as the answers comply with program 
Finish the math and send the answers to the output file with 4 decimal points
Else, Print "complex" and then close the output file
End if and while statements
If there is no output file, check for end of file again
Re set variables assigned to input values
Compute math again, but instead print as "cout" instead of to the output
Create error scenario for improper running requirements, and print error
End

********************************************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])																											//Set argc and argv
{	
    float a, b, c, x1, x2, part1, part2;																									//Create floats a, b, c, two answer variables and then two extras for math parts
	if(argc == 3)																															//Begin if statement for program parameters in argc
	{
		ifstream ifile (argv[1]);																											//Set input file stream
		while(!ifile.eof())																													//While statement to check for end of file
		{
			if(ifile >> a >> b >> c)																										//If statement to set variables to be assigned from the input file
			{
				ofstream ofile (argv[2], ios::app);																							//Set output file, and set math to be done
				part1 = b*b - 4*a*c;
				if (part1 >= 0)
				{
					x1 = (-b + sqrt(part1)) / (2 * a);
					x2 = (-b - sqrt(part1)) / (2 * a);
					ofile << a << "\t" << b << "\t" << c << "\t" << fixed << setprecision(4) << setw(4) << x1 << "\t" << x2 << endl;		//Finish the math and send the answers to the output file with 4 decimal points
				}
				else if (part1 < 0)
				{
					ofile << a << "\t" << b << "\t" << c << "\t" << "complex" << endl;														//Else, Print "complex" and then close the output file
				}
				ofile.close();
			}
		}
		
	}																																		//End if and while statements
	
	if(argc == 2)																															//If there is no output file, check for end of file again
	{
		ifstream ifile (argv[1]);
		while(!ifile.eof())
		{
			if(ifile >> a >> b >> c)																										//Re set variables assigned to input values
			{
				part1 = b*b - 4*a*c;
				if (part1 >= 0)
				{
					x1 = (-b + sqrt(part1)) / (2 * a);
					x2 = (-b - sqrt(part1)) / (2 * a);
					cout << setprecision(4) << fixed << setw(4) << a << "\t" << b << "\t" << c << "\t" << x1 << "\t" << x2 << endl;			//Compute math again, but instead print as "cout" instead of to the output
					
				}
				else if (part1 < 0)
				{
					cout << a << "\t" << b << "\t" << c << "\t" << "complex" << endl;														//Set to print complex to cout instead of output file
				}
			}
		}
		
	}
	
	
	if(argc !=2 && argc !=3)
	{
		cout << "error" << endl;																											//Create error scenario for improper running requirements, and print error
	}
    return 0;
}

