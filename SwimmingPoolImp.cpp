/* Beth Reel
CSC161C00
Chapter 10 Exercise 14
February 05, 2017
*/

// Implementation file for SwimmingPool class

#include <iostream>
#include <iomanip>
#include "SwimmingPool.h"
using namespace std;
double const GallonsToCubicFeet = 7.48052;

// default constructor, just initialize members to valid values
SwimmingPool::SwimmingPool()
{
	// dimensions of pool in feet
	lengthPool = 10;
	widthPool = 10;
	depthPool = 10;

	// gallon per minute rate for filling pool 
	rateWaterFillingPool = 5;

	// gallon per minute rate for draining pool 
	rateWaterDrainingFromPool = 10;
}

//destructor 
SwimmingPool::~SwimmingPool()
{
}


// ******** setters *******

void SwimmingPool::setLengthPool(int newLength)
{
	lengthPool = newLength;
}
void SwimmingPool::setWidthPool(int newWidth)
{
	widthPool = newWidth;
}
void SwimmingPool::setDepthPool(int newDepth)
{
	depthPool = newDepth;
}
void SwimmingPool::setRateWaterFillingPool(int newRateFilling)
{
	rateWaterFillingPool = newRateFilling;
}
void SwimmingPool::setRateWaterDrainingFromPool(int newRateDraining)
{
	rateWaterDrainingFromPool = newRateDraining;
}


// ***** getters ******


int SwimmingPool::getLengthPool() const
{
	return lengthPool;
}
int SwimmingPool::getWidthPool() const
{
	return widthPool;
}
int SwimmingPool::getDepthPool() const
{
	return depthPool;
}
int SwimmingPool::getRateWaterFillingPool() const
{
	return rateWaterFillingPool;
}
int SwimmingPool::getRateWaterDrainingFromPool() const
{
	return rateWaterDrainingFromPool;
}


// ********* other member functions *******
// print all of the dimensions of the pool to the screen
// along with the rates to fill and drain the pool 
void SwimmingPool::printMember()const
{

	cout << setfill(' ') << setw(10) << endl;
	cout << "Length of pool: " << getLengthPool() << " feet" << endl;
	cout << "Width of pool: " << getWidthPool() << " feet" << endl;
	cout << "Depth of pool: " << getDepthPool() << " feet" << endl;
	cout << "Rate water filling pool: " << getRateWaterFillingPool() << " gpm" << endl;
	cout << "Rate water draining from pool: " << getRateWaterDrainingFromPool() << " gpm" << endl;

}

//determine the time needed to completely or partially fill, or empty the pool
double SwimmingPool::timeNeededToFillorEmpty(string action, double percentFull) const
{
	// find maximum number of gallons the pool can hold
	double maxGallons = (getLengthPool() * getWidthPool() * getDepthPool()) * GallonsToCubicFeet;

	// if filling water, calculate number of gallons needed to fill the pool 
	// and divide by the rate of fill per minute to get total minutes needed to fill the pool 
	if (action == "fill")
		return  (maxGallons - (maxGallons * (percentFull / 100))) / getRateWaterFillingPool();

	// if draining water, divide amount of water in pool by the rate water drains
	// to get the total minutes needed to empty the pool 
	else
		return (maxGallons * (percentFull / 100)) / getRateWaterDrainingFromPool();
}

//determine the amount of water needed to fill an empty or partially filled pool
double SwimmingPool::waterNeededToFill(double percentFull) const
{
	// find maximum number of gallons the pool can hold 
	double maxGallons = (getLengthPool() * getWidthPool() * getDepthPool()) * GallonsToCubicFeet;

	// calculate gallons of water in the pool and subtract from max gallons
	// and return remaining gallons of water needed to fill pool 
	return  (maxGallons - (maxGallons * (percentFull / 100)));

}

//determine the percentage pool full after adding or draining water
double SwimmingPool::addOrDrainWaterResults(string action, int minutes, double percentFull) const
{
	// find the current maximum amount of gallons the pool holds
	double maxGallons = (getLengthPool() * getWidthPool() * getDepthPool()) * GallonsToCubicFeet;

	// use input double percentFull to determine the actual number of gallons in the pool 
	double currentGallons = (maxGallons * (percentFull / 100));

	// if adding water, calculate the new percentage 
	if (action == "add")
	{
		// add the amount of water that can fill to the gallons already in the pool
		// if greater than the maximum number of gallons in the pool 
		// return maximum of 100 percent full
		if (((minutes * getRateWaterFillingPool()) + currentGallons) > maxGallons)
			return 100;
		// if amount of water filling during time period is not enough to fill pool
		// return new percentage of water in the pool 
		else
			return (((minutes * getRateWaterFillingPool()) + currentGallons) / (maxGallons / 100));
	}
	// if draining water, calculate new percentage
	else
	{
		// subtract amount that can drain during that time from the current gallons
		// if all the water can drain during that time return 0

		if (currentGallons - ((minutes * getRateWaterDrainingFromPool())) <= 0)
			return 0;

		// if not all water is drained, calculate new percentage of water in the pool 
		else
			return ((currentGallons - (minutes * getRateWaterDrainingFromPool())) / (maxGallons / 100));
	}

}
