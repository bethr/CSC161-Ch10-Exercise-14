/* Beth Reel
February 04, 2017
*/
// Header file for SwimmingPool 
#include <string>
using namespace std;
class SwimmingPool {
public:


	SwimmingPool();
	// default constructors 
	// no input, no output


	~SwimmingPool();
	//destructors 
	// no input, no output


	//setters
	void setLengthPool(int);
	void setWidthPool(int);
	void setDepthPool(int);
	void setRateWaterFillingPool(int);
	void setRateWaterDrainingFromPool(int);


	//getters

	int getLengthPool() const;
	int getWidthPool() const;
	int getDepthPool() const;
	int getRateWaterFillingPool() const;
	int getRateWaterDrainingFromPool() const;


	//other  functions
	//print out the pool information in a nice format 
	void printMember() const;

	//determine the time needed to completely or partially fill, or empty the pool
	double timeNeededToFillorEmpty(string, double) const;

	//determine the amount of water needed to fill an empty or partially filled pool
	double waterNeededToFill(double) const;

	//determine the percentage pool full after adding or draining water
	double addOrDrainWaterResults(string, int, double) const;



private:
	// dimensions of pool in feet
	int lengthPool;
	int widthPool;
	int depthPool;

	// gallon per minute rate for filling pool 
	int rateWaterFillingPool;

	// gallon per minute rate for draining pool 
	int rateWaterDrainingFromPool;


};
