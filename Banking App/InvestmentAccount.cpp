#include <iomanip>
#include <iostream>
#include "InvestmentAccount.h"
using namespace std;


//Constructor

InvestmentAccount::InvestmentAccount(double investment, double monthDeposit, double rate, int years) {
	this->initialDeposit = investment;
	this->monthlyDeposit = monthDeposit;
	this->interestRate = rate;
	this->numYears = years;
}

//Destructor

InvestmentAccount :: ~InvestmentAccount() {

}

//Prints with no monthly deposit included

void InvestmentAccount::noMonthlyDeposit() {

	cout << "Balance and Interest without Monthly Deposit" << endl;
	cout << "********************************************" << endl;
	cout << setw(10) << "Year" << setw(20) << "Yearly end balance" << setw(35) << "Yearly Interest earned" << endl;
	cout << "********************************************" << endl;

	//while loop to interate through the years

	int currentYear = 1;
	double yearlyEndBalance = this->initialDeposit;

	while (currentYear <= this->numYears) {
		double interestEarned = yearlyEndBalance * this->interestRate / 100;
		yearlyEndBalance = interestEarned;
		cout << right << setw(10) << currentYear << fixed << setprecision(2) << setw(20) << yearlyEndBalance << setw(35) << interestEarned << endl;

		currentYear++;
	}
}

//Prints with monthly deposit included

void InvestmentAccount::withMonthlyDeposit() {

	cout << "Balance and Interest with Monthly Deposit" << endl;
	cout << "********************************************" << endl;
	cout << setw(10) << "Year" << setw(20) << "Yearly end balance" << setw(35) << "Yearly Interest earned" << endl;
	cout << "********************************************" << endl;

	//while loop to interate through the years

	int currentYear = 1;
	double yearlyEndBalance = this->initialDeposit;

	while (currentYear <= this->numYears) {
		int month = 1;
		double interestEarned = 0.0;
		double monthEndBalance = yearlyEndBalance;

		while (month <= 12) {
			monthEndBalance += this->monthlyDeposit;
			double monthlyInterest = monthEndBalance * this->interestRate / (100 * 12);
			interestEarned += monthlyInterest;
			monthEndBalance += monthlyInterest;

			month++;
		}
		
		yearlyEndBalance = interestEarned;
		cout << right << setw(10) << currentYear << fixed << setprecision(2) << setw(20) << yearlyEndBalance << setw(35) << interestEarned << endl;

		currentYear++;
	}
}