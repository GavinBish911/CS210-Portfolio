//Calls header file
#include "ClockBish.h"

//Starts with the beginning time

ClockClass::ClockClass(bool hours_24) {
	//Starting time
	time_t seconds = time(0);
	localTime = localtime(&seconds);
	p_hours = 0;
	p_minutes = 0;
	p_seconds = 0;

	this->hours_24 = hours_24;
}

//functions to operate clock

//function to add hours
void ClockClass::addHours(int hours) {
	p_hours += hours;
}

//function to add minutes
void ClockClass::addMinutes(int minutes) {
	p_minutes += minutes;
}

//function to add seconds
void ClockClass::addSeconds(int seconds) {
	p_seconds += seconds;
}

//function to reset clock
void ClockClass::resetClock() {
	p_hours = 0;
	p_minutes = 0;
	p_seconds = 0;
}

//function to display clock
void ClockClass::displayTime(ostream& out) {
	int seconds = 0;
	int minutes = 0;
	int hours = 0;

	//calculates the total numbers of seconds, how many seconds go into a minutes, and the remainder of seconds
	seconds = localTime->tm_sec + p_seconds;
	minutes += seconds / 60;
	seconds = seconds % 60;

	//does the same as above but for minutes with hours
	minutes = localTime->tm_min + p_minutes;
	hours += minutes / 60;
	minutes = minutes % 60;

	//add to the totals number of hours and handles the additional hours for the 24 hour clock
	hours = (hours + localTime->tm_hour + p_hours) % 24;

	//Sets the display to the desired format
	string timestring = "";
	out << setw(2) << setfill('0') << (hours_24 ? hours : (hours % 12)) << ":";
	out << setw(2) << setfill('0') << minutes << ":";
	out << setw(2) << setfill('0') << seconds << "";
	
	//decides if clock is 12 or 24 hours
	if (!hours_24) {
		if (hours > 12) {
			out << "PM";
		}
		else {
			out << "AM";
		}
	}

}