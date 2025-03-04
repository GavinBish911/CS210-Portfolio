#include "ClockBish.h"
#include <conio.h>

//function to display menu options
void menu() {

	//menu options
	cout << "***********************" << endl;
	cout << "* 1 - Add One Second *" << endl;
	cout << "* 2 - Add One Minutes *" << endl;
	cout << "* 3 - Add One Hours *" << endl;
	cout << "* 4 - Exit *" << endl;
	cout << "***********************" << endl;

}

int main() {
	//creates two clocks
	ClockClass clock12hour(false), clock24hour(true);

	int decision;
	//sees if user wants to exit program
	bool exit = false;
	//while loop to constantly updates display and check for user input
	while (!exit) {

		cout << endl;
		cout << "***************************";

		cout << "* " << setw(12);
		clock12hour.displayTime(cout); //outputs 12 hour clock
		cout << " *";

		cout << "* " << setw(12);
		clock24hour.displayTime(cout); //outputs 24 hour
		cout << " *";

		cout << "***************************";
		cout << endl;

		menu(); //prompts menu
		cin >> decision //takes user input

		switch (decision) {
			case 1 : 
				clock12hour.addSeconds(1);
				clock24hour.addSeconds(1);
			case 2:
				clock12hour.addMinutes(1);
				clock24hour.addMinutes(1);
			case 3:
				clock12hour.addHours(1);
				clock24hour.addHours(1);
			case 4:
				exit = true;
				default
					break;
		}
	}
}