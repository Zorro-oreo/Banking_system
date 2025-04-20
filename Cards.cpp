#include <iostream>
#include <vector>
#include "Cards.h"

void Cards::add_Debit_Card(string card, Accounts &account) {
    account.addDebitCard(card);
}
void Cards::add_Credit_Card(string card, Accounts& account) {
    account.addCreditCard(card);
}
void Cards::stop_Debit_Card(string card_RD, Accounts& account) {
	account.stopDebitCard(card_RD);

}
void Cards::stop_Credit_Card(string card_RC, Accounts& account) {
	account.stopCreditCard(card_RC);
}
void Cards::display_debit_Cards(Accounts& account) {
	vector<string>& debit_cards = account.getDebitCard(); // Get the debit cards from the account
    cout << "Debit Cards: ";
	for (int i = 0; i < debit_cards.size(); i++) {
		cout << debit_cards[i] << " ";
	}

}
void Cards::display_credit_Cards(Accounts& account) {
	vector<string>& credit_cards = account.getCreditCard(); // Get the credit cards from the account
    cout << "Credit Cards: ";
	for (int i = 0; i < credit_cards.size(); i++) {
		cout << credit_cards[i] << " ";
	}
}
