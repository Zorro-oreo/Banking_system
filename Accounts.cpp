#include <iostream>
#include <vector>
#include "Accounts.h"
#include "Notifications.h"

Accounts::Accounts() : type(""), balance(0), ID(""), country("") {}
Accounts::Accounts(string t, string i, string c): type(t), ID(i), balance(100), country(c){} //Start with balance 100 for debugging

Notifications Anotif;

void Accounts::displayNumCards() {

	Anotif.message("\nDebit cards: ");
	Anotif.message(debitCards.size(), true);

	Anotif.message("\Credit cards: ");
	Anotif.message(creditCards.size(), true);

}

void Accounts::addDebitCard(string num) {

	debitCards.push_back(num);

}

void Accounts::stopDebitCard(string num) {

	for (int i = 0; i < debitCards.size(); i++) {

		if (debitCards.at(i) == num) {

			debitCards.erase(debitCards.begin() + i);

		}

	}

}

void Accounts::addCreditCard(string num) {

	creditCards.push_back(num);

}

void Accounts::stopCreditCard(string num) {

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

string Accounts::getID() {

	return ID;

}

string Accounts::getCountry() {

	return country;

}

void Accounts::displayAccount() {

	Anotif.message("\nAccount number: ");
	Anotif.message(ID, true);

	Anotif.message("\nAccount type: ");
	Anotif.message(type, true);

	Anotif.message("\nAccount country: ");
	Anotif.message(country, true);

	Anotif.message("\nCurrent balance: ");
	Anotif.message(balance, true);

}

//_______________________________________Loan handling here________________________________________________
void Accounts::Loan() { 

	if ((debt >= 0.05 * loan) && (balance >= 0.05 * loan)) {

		debt -= (0.05 * loan);
		balance -= (0.05 * loan);//Deduce 5% from the loan taken

		Anotif.message("Paid ");
		Anotif.message(0.05 * loan, true);

	}
	else if (((debt < 0.05 * loan) && (debt != 0)) && (balance >= debt)) { //If the account has less than the 5% remaining in their balance, only take what's left to prevent negative balance

		debt -= debt;
		balance -= debt;

		Anotif.message("Paid ");
		Anotif.message(debt);

	}
	else if ((debt != 0) && (balance < 0.05 * loan)) {

		Anotif.message("Can not pay debt due to insufficient balance.\n");

	}

}

void Accounts::APLoan(int amount) {

	if ((balance > (0.5 * amount) && (debt == 0))) { //User can only apply for a loan if they have more than half its amount and if the user has already paid his debts
		
		balance += amount;
		loan = amount;
		debt = amount;

		Anotif.message("Loan granted.\n");

	}
	else {

		Anotif.message("Insufficient balance or debt is not paid.\n");

	}

}

long Accounts::getDebt() {

	return debt;

}

long Accounts::getLoan() {

	return loan;

}
//______________________________________________________________________________________________________

vector<string>& Accounts::getCreditCard() {
	return creditCards;
}

vector<string>& Accounts::getDebitCard() {
	return debitCards;
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