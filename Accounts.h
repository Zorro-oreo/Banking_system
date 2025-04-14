#pragma once
#include <vector>
#include <string>

using namespace std;

class Accounts {

private:

	string type;

	long balance;

	string ID;

	vector<long long> debitCards;
	vector<long long> creditCards;

	

public:
	Accounts(string t, string i);

	void displayNumCards();

	void addDebitCard(long long num);
	void addCreditCard(long long num);

	void stopDebitCard(long long num);
	void stopCreditCard(long long num);

	void addToBalance(long amount);

	void subFromBalance(long amount);

	long getBalance();

	string getID();

	void displayAccount();

};