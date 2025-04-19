#include <iostream>
#include <vector>
#include "Cards.h"

void Cards::add_PrePaid_Card(string card) {
    cout <<"Add a new PrePaid Card: " << endl;
    cin >> card;
    prepaid_cards.push_back(card);
    // Using push_back to add a card to the vector
}
void Cards::add_Debit_Card(string card, Accounts &account) {
    account.addDebitCard(card);
}
void Cards::add_Credit_Card(string card) {
    credit_cards.push_back(card);
}
void Cards::stop_Pre_Paid_Card(string card_RP) {
    cout << "Stop PrePaid Card: " << endl;
    cin >> card_RP;
    // Using cin to get the card number from the user
    for(int i = 0; i < prepaid_cards.size(); i++) {
        if(prepaid_cards[i] == card_RP) {
            prepaid_cards.erase(prepaid_cards.begin() + i);
            break;
        }
    }
    // Using erase to remove the card from the vector
    // The loop iterates through the vector to find the card and remove it
}
void Cards::stop_Debit_Card(string card_RD) {
    for(int i = 0; i < debit_cards.size(); i++) {
        if(debit_cards[i] == card_RD) {
            debit_cards.erase(debit_cards.begin() + i);
            break;
        }
    }

}
void Cards::stop_Credit_Card(string card_RC) {
    for(int i = 0; i < credit_cards.size(); i++) {
        if(credit_cards[i] == card_RC) {
            credit_cards.erase(credit_cards.begin() + i);
            break;
        }
    }
}
void Cards::display_Pre_Paid_Cards() {
    cout << "Prepaid Cards: ";
    for (string card : prepaid_cards) {
        cout << card << " ";
    }
    cout << endl;
    // Using a range-based for loop to display all prepaid cards
    // The loop iterates through the vector and prints each card
}
void Cards::display_debit_Cards() {
    cout << "Debit Cards: ";
    for (string card : debit_cards) {
        cout << card << " ";
    }
    cout << endl;
}
void Cards::display_credit_Cards() {
    cout << "Credit Cards: ";
    for (string card : credit_cards) {
        cout << card << " ";
    }
    cout << endl;
}

/*int main() {
    Cards myCards;
    long long card;
    long long card_RP;
    myCards.add_PrePaid_Card(card);
    myCards.display_Pre_Paid_Cards();
    myCards.display_debit_Cards();
    myCards.display_credit_Cards();
    
    myCards.stop_Pre_Paid_Card(card_RP);
    myCards.stop_Credit_Card(9876543210987654);
    
    myCards.display_Pre_Paid_Cards();
    myCards.display_debit_Cards();
    myCards.display_credit_Cards();
    
    return 0;
}*/