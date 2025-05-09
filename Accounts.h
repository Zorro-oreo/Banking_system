#pragma once
#include <vector>
#include <string>

using namespace std;

class Accounts {

private:

	string type;

	string country;

	long balance;

	string ID;

	vector<string> debitCards;
	vector<string> creditCards;

	long debt = 0;
	long loan = 0; // To remember the loan taken originally

public:

	Accounts();
	Accounts(string t, string i, string c);

	void displayNumCards();

	void addDebitCard(string num);
	void addCreditCard(string num);

	void stopDebitCard(string num);
	void stopCreditCard(string num);

	void addToBalance(long amount);

	void subFromBalance(long amount);

	long getBalance();

	string getCountry();

	string getID();

	void displayAccount();

	vector<string>& getCreditCard();
	vector<string>& getDebitCard();

	long getDebt();

	long getLoan();

	void Loan(); //Will handle the loans by checking the debt of the account saved and deducing the required amount. It will be called periodically 

	void APLoan(int amount); //Apply for a loan

};