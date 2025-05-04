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

	long debt;

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

	long getDebt() {

		return debt;

	}

	void giveLoan(int val) {

		balance += val;
		debt = val;

	}

	void payDebt(int val) {

		debt -= val;
		balance -= val;

	}

};