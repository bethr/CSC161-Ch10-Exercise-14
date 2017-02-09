/* Beth Reel
CSC161C00
Chapter 10 Exercise 14
February 05, 2017

This program will:
1) determine the amount of water needed to fill an empty or partially filled pool.
2) determine the time needed to completely or partially fill or empty the pool.
3) add or drain water for a specified amount of time.

Steps:
a) Write the definition of a class, swimmingPool, to implement the properties of a swimming pool.

b) Your class should have the instance variables to store:
the length(in feet),
width(in feet),
depth(in feet),
the rate(in gallons per minute) at which the water is filling the pool,
the rate(in gallons per minute) at which the water is draining from the pool.

c) Add appropriate constructors to initialize the instance variables.

d) Also, add member functions to do the following :
- determine the amount of water needed to fill an empty or partially filled pool,
- determine the time needed to completely or partially fill or empty the pool, and
- add or drain water for a specific amount of time.

*/

// Test file for SwimmingPool
#include <iomanip>
#include <string>
#include <fstream>
#include <iostream>
#include "SwimmingPool.h"
using namespace std;



int main()
{
	// initialize object swimmingPool to default values
	SwimmingPool swimmingPool;
	SwimmingPool();

	// initialize placeholders for input 
	string inputString = "";
	int inputInteger = 0;
	int inputInteger2 = 0;

	// advise user of default values and print to screen 
	cout << "This program calculates the rate of time it will take to fill/empty a pool " << endl;
	cout << "Default pool measurements are as follows:" << endl;
	swimmingPool.printMember();

	// ask if user wants to continue with default values or enter his own
	// save all new values to object swimmingPool
	do
	{
		cout << setfill(' ') << setw(10) << endl;
		cout << "Do you want to continue with default pool measurements? y/n" << endl;
		cin >> inputString;
		if (inputString == "n")
		{
			cout << "Enter length of pool in feet: ";
			cin >> inputInteger;
			swimmingPool.setLengthPool(inputInteger);

			cout << "Enter width of pool in feet: ";
			cin >> inputInteger;
			swimmingPool.setWidthPool(inputInteger);

			cout << "Enter depth of pool in feet: ";
			cin >> inputInteger;
			swimmingPool.setDepthPool(inputInteger);

			cout << "Enter rate water filling pool in gallons per minute: ";
			cin >> inputInteger;
			swimmingPool.setRateWaterFillingPool(inputInteger);

			cout << "Enter rate water draining from pool in gallons per minute: ";
			cin >> inputInteger;
			swimmingPool.setRateWaterDrainingFromPool(inputInteger);

			cout << "\nThe new pool measurements are as follows:" << endl;
			swimmingPool.printMember();
		}
	} while (inputString != "n" && inputString != "y");


	// ask user how full the pool currently is  
	do {
		cout << "\nPlease enter current percent that pool is full of water? (0 to 100)" << endl;
		cout << "i.e., '0' for empty,  '100' for full,  '25' for 25% full: ";
		cin >> inputInteger;
	} while (inputInteger < 0 || inputInteger >100);


	cout << fixed << showpoint << setprecision(2);

	// Print to screen amount of Water needed to fill an empty or partially filled pool
	cout << "It will require " << swimmingPool.waterNeededToFill(inputInteger)
		<< " gallons to fill the pool.\n" << endl;

	// Print to screen amount of Time needed to completely or partially fill the pool
	cout << "It will require " << swimmingPool.timeNeededToFillorEmpty("fill", inputInteger)
		<< " minutes to fill the pool." << endl;
	cout << "It will require " << swimmingPool.timeNeededToFillorEmpty("empty", inputInteger)
		<< " minutes to empty the pool.\n" << endl;

	// ask user how many minutes to drain or fill the pool of water 
	do {
		cout << "\nPlease enter an amount of minutes to drain or fill water: " << endl;
		cin >> inputInteger2;
	} while (inputInteger2 < 0 || inputInteger2 >100000);

	// Display Results of draining water for a specified amount of time
	cout << "Draining the pool for " << inputInteger2 << " minutes will leave the pool "
		<< swimmingPool.addOrDrainWaterResults("drain", inputInteger2, inputInteger)
		<< "% full." << endl;

	// Display Results of draining water for a specified amount of time
	cout << "Adding water to the pool for " << inputInteger2 << " minutes will make the pool "
		<< swimmingPool.addOrDrainWaterResults("add", inputInteger2, inputInteger)
		<< "% full." << endl;


	return 0;
}



