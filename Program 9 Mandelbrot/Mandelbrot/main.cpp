/**************************************************************************************************
Rowan Antonuccio
Mandelbrot
Function: main.cpp
---------------------------------------------------------------------------------------------------
Summary: Uses a binary header to create a BMP image file and then chooses randomly between 1 and 3 to pick a color scheme for the mandelbrot to be generated with

Pseudo:
Create unsigned chars for RGB
Create ints for i, j, and iterations and color
Initialize doubles to use for counters and coords
Create Bitmpap header in hex
Create DIB header in 40 hex values
Create value of current clock
Create seed
create random number generator
create rando for use as a random number
Create beggining print statements and print which variant was chosen
Variant 1
Open file and write to in binary if good
creates bmp header
creates dib header
creates x and y axis and creates plotting points for coords
initialize variables
begin mandelbrot
increment iteration
sets color scheme
print loading percentages
close file
repeat exact process for Variant 2 and 3
end
**************************************************************************************************/

#include <iostream>
#include <fstream>
#include <complex>
#include <random>
#include <array>
#include <iomanip>
#include <chrono>
using namespace std;



int main()
{
	unsigned char b = 0;																													//Create unsigned chars for RGB
	unsigned char g = 0;
	unsigned char r = 0;
	
	
	int i, j, iteration, max_iteration, color;																								//Create ints for i, j, and iterations and color
	
	double x0 = 0.00;																														//Initialize doubles to use for counters and coords
	double y0 = 0.00;
	double x, y, xtemp = 0.0;


	array<unsigned char, 14> bmp_header = { 0x42, 0x4D, 0x76, 0xF3, 0x89, 0x06, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00 };			//Create Bitmpap header in hex

	array<unsigned char, 40> dib_header = { 0x28, 0x00, 0x00, 0x00, 0x40, 0x1F, 0x00, 0x00, 0xDB, 0x11,
											0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
											0x40, 0xF3, 0x89, 0x06, 0x13, 0x0B, 0x00, 0x00, 0x13, 0x0B,
											0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };									//Create DIB header in 40 hex values


	typedef std::chrono::high_resolution_clock myclock;
	myclock::time_point beginning = myclock::now();																							//Create value of current clock

	myclock::duration d = myclock::now() - beginning;
	unsigned seed2 = d.count();																												//Create seed

	default_random_engine generator;
	uniform_int_distribution<int> distribution(1, 3);																						//create random number generator

	generator.seed(seed2);
	int rando = distribution(generator);																									//create rando for use as a random number

	cout << "~~~~ WELCOME TO MANDELBROT GENERATOR ~~~~" << endl;
	cout << "Program has chosen variant " << rando << endl;
	cout << "Press any button to continue loading..." << endl;																				//Create beggining print statements and print which variant was chosen
	cin.ignore();

	if (rando == 1)																															//Variant 1
	{
		ofstream f1; f1.open("mandelbrot_1.bmp", ios::out | ios::binary);
		if (f1.good())																														//Open file and write to in binary if good
		{
			for (i = 0; i < 14; i++)																										//creates bmp header
			{
				f1 << bmp_header[i];
			}

			for (i = 0; i < 40; i++)																										//creates dib header
			{
				f1 << dib_header[i];
			}

			for (i = 0, y0 = -1; i < 4571; i++, y0 = y0 + 2.0 / 4571)																		//creates y axis and creates plotting points for coords
			{
				for (j = 0, x0 = -2.5; j < 8000; j++, x0 = x0 + 3.5 / 8000)																	//creates x axis and plots on proper coords
				{
					x = 0.0;
					y = 0.0;
					iteration = 0;
					max_iteration = 1000;																									//initialize variables
					
					while (x * x + y * y <= 2 * 2 && iteration < max_iteration)																//begin mandelbrot
					{
						xtemp = x * x - y * y + x0;
						y = 2 * x * y + y0;
						x = xtemp;
						iteration = iteration + 1;																							//increment iteration

					}
					

					iteration = (iteration - 1000) * -1;																					//creates coloring
					color = (float)iteration / 255000 * 255 * 255;

					f1.put(color);																											//sets color scheme
					f1.put(0x00);
					f1.put(0x00);

				}

				std::cout << fixed << setprecision(0) << "loading..." << (float)i / 4570 * 100 << "%" << endl;								//loading percentages to be printed
			}

			f1.close();																														//close file

		}
	}

	if (rando == 2)																															//Variant 2
	{
		ofstream f2; f2.open("mandelbrot_2.bmp", ios::out | ios::binary);
		if (f2.good())
		{
			for (i = 0; i < 14; i++)
			{
				f2 << bmp_header[i];
			}
																																			//Create binary headers
			for (i = 0; i < 40; i++)
			{
				f2 << dib_header[i];
			}

			for (i = 0, y0 = -1; i < 4571; i++, y0 = y0 + 2.0 / 4571)
			{																																//Create x and y axis and plot points on proper coords for pixels
				for (j = 0, x0 = -2.5; j < 8000; j++, x0 = x0 + 3.5 / 8000)
				{
					x = 0.0;
					y = 0.0;
					iteration = 0;
					max_iteration = 1000;																									//Initialize variables

					while (x * x + y * y <= 2 * 2 && iteration < max_iteration)
					{
						xtemp = x * x - y * y + x0;
						y = 2 * x * y + y0;
						x = xtemp;
						iteration = iteration + 1;																							//Create mandelbrot

					}


					iteration = (iteration - 1000) * -1;
					color = (float)iteration / 255000 * 255 * 255;																			//Create color

					f2.put(0x00);
					f2.put(color);
					f2.put(0x00);																											//Set color scheme

				}

				std::cout << fixed << setprecision(0) << "loading..." << (float)i / 4570 * 100 << "%" << endl;								//Print loading percent
			}

			f2.close();																														//Close file

		}
	}

	if (rando == 3)																															//Variant 3
	{
		ofstream f3; f3.open("mandelbrot_3.bmp", ios::out | ios::binary);
		if (f3.good())
		{
			for (i = 0; i < 14; i++)
			{
				f3 << bmp_header[i];
			}
																																			//Create binary header
			for (i = 0; i < 40; i++)
			{
				f3 << dib_header[i];
			}

			for (i = 0, y0 = -1; i < 4571; i++, y0 = y0 + 2.0 / 4571)
			{																																//Create x and y axis for plotting points and printing pixels
				for (j = 0, x0 = -2.5; j < 8000; j++, x0 = x0 + 3.5 / 8000)
				{
					x = 0.0;
					y = 0.0;
					iteration = 0;
					max_iteration = 1000;																									//Initialize variables

					while (x * x + y * y <= 2 * 2 && iteration < max_iteration)
					{
						xtemp = x * x - y * y + x0;
						y = 2 * x * y + y0;
						x = xtemp;
						iteration = iteration + 1;
																																			//Create mandelbrot
					}


					iteration = (iteration - 1000) * -1;
					color = (float)iteration / 255000 * 255 * 255;

					f3.put(0x00);
					f3.put(0x00);
					f3.put(color);																											//Create color scheme

				}

				std::cout << fixed << setprecision(0) << "loading..." << (float)i / 4570 * 100 << "%" << endl;								//Create loading percent
			}

			f3.close();																														//Close file

		}
	}

}