//ClockBish.h
#ifndef ClockBish_H_
#define ClockBish_H_

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

//Defining Clock Class to maintain private values for time keeping
class ClockClass
{
public:
	ClockClass(bool hours_24);
	//methods to add hours, minutes, and seconds to clock
	void addHours(int hours);
	void addMinutes(int minutes);
	void addSeconds(int seconds);
	//method to reset clock and display time
	void resetClock();
	void displayTime (ostream &out);

private:
	//structing to store time with private values
	struct tm* localTime;
	//private variables for storing hours, minutes, and seconds of the clock
	int p_hours;
	int p_minutes;
	int p_seconds;
	// boolean value to decided if it is for the 24 clock or 12 hour clock
	bool hours_24;

};

#endif // !ClockBish_H_

