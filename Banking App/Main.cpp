#incoude <iostream>
#iclude <"InvestmentAccount.h">
using namespace std;

int main() {

	while (1 {

		cout << "****************************************" << endl;
		cout << "***************Data Input***************" << endl;
		cout << "Initial Investment Amount: " << endl;
		cout << "Monthly Deposit: " << endl;
		cout << "Annual Ineterest: " << endl;
		cout << "Number of years: " << endl;

		system("read -p 'Press enter to continue....' var");
		cout << endl;

		cout << "****************************************" << endl;
		cout << "***************Data Input***************" << endl;
		cout << "Initial Investment Amount: $" << endl;

		double investment, monthlyDeposit, interestRate;
		int years;

		cin >> investment;
		cout << "Monthly Depsoit: $";
		cin >> monthlyDeposit;
		cout << "Annual Interest: %";
		cin >> interestRate;
		cout << "Number of Years: ";
		cin >> years;

		system("read -p 'Press enter to continue....' var");

		InvestmentAccount myaccount = InvestmentAccount(investment, monthlyDeposit, interestRate, years);
		cout << endl;

		myaccount.noMonthlyDeposit();
		cout << endl;

		if (monthlyDeposit > 0) {
			myaccount.withMonthlyDeposit();
		}

		cout << endl << "DO YOU WANT TO TRY ANOTHER (YES OR NO): ";
		string choice;
		cin >> choice;

		if (choice != "YES") {
			break;
		}

		cout << endl;
	}

	return 0;
}