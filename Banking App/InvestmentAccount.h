#ifndef InvestmentAccount_H_
#define InvestmentAccount_H_

class InvestmentAccount {

	public:
		InvestmentAccount(double investment, double monthDeposit, double rate, int years);
		virtual ~InvestmentAccount();
		void noMonthlyDeposit();
		void withMonthlyDeposit();

	private:
		double initialDeposit();
		double monthlyDeposit();
		double interestRate();
		int numYears();

};

#endif
