#include <iostream>
#include <vector>
#include "Accounts.h"

Accounts::Accounts(string t, long long i): type(t), ID(i), balance(0){}

void Accounts::displayNumCards() {

	cout << "Debit cards: " << debitCards.size() << endl;
	cout << "Credit cards: " << creditCards.size() << endl;

}

void Accounts::addDebitCard(long long num) {

	debitCards.push_back(num);

}

void Accounts::stopDebitCard(long long num) {

	for (int i = 0; i < debitCards.size(); i++) {

		if (debitCards.at(i) == num) {

			debitCards.erase(debitCards.begin() + i);

		}

	}

}

void Accounts::addCreditCard(long long num) {

	creditCards.push_back(num);

}

void Accounts::stopCreditCard(long long num) {

	for (int i = 0; i < creditCards.size(); i++) {

		if (creditCards.at(i) == num) {

			creditCards.erase(creditCards.begin() + i);

		}

	}

}

void Accounts::addToBalance(long amount) {

	balance += amount;

}

void Accounts::subFromBalance(long amount) {

	balance -= amount;

}

long Accounts::getBalance() {


	return balance;

}

long long Accounts::getID() {

	return ID;

}

void Accounts::displayAccount() {

	cout << "Account number: " << ID << endl;
	cout << "Account type: " << type << endl;
	cout << "Current balance: " << balance << endl;

}

/*int main() { //Testing

	Accounts myacc("Savings", 202401389);

	myacc.addToBalance(43);
	myacc.subFromBalance(3);
	myacc.addDebitCard(2028);
	myacc.addDebitCard(6732);
	myacc.addCreditCard(252);
	myacc.stopCreditCard(2542);
	myacc.stopDebitCard(2028);

	myacc.displayAccount();
	myacc.displayNumCards();

}*/