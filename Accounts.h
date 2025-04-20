#pragma once
#include <vector>
#include <string>

using namespace std;

class Accounts {

private:

	string type;

	long balance;

	string ID;

	vector<string> debitCards;
	vector<string> creditCards;

public:

	Accounts();
	Accounts(string t, string i);

	void displayNumCards();

	void addDebitCard(string num);
	void addCreditCard(string num);

	void stopDebitCard(string num);
	void stopCreditCard(string num);

	void addToBalance(long amount);

	void subFromBalance(long amount);

	long getBalance();

	string getID();

	void displayAccount();

	vector<string>& getCreditCard();
	vector<string>& getDebitCard();

};