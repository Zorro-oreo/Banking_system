#pragma once
#include <vector>
#include "Accounts.h"
#include "Accounts.cpp"
using namespace std;

class Cards{
private:
    vector<long long> prepaid_cards, debit_cards, credit_cards;
    // Using list for dynamic size and easy insertion/deletion  
public:
    Cards() = default;
    void add_PrePaid_Card(long long card); // Adds a prepaid card to the list
    void add_Debit_Card(long long card, Accounts &account); // Adds a debit card to the list
    void add_Credit_Card(long long card); // Adds a credit card to the list
    void stop_Pre_Paid_Card(long long card); // Stops a prepaid card from the list
    void stop_Debit_Card(long long card); // Stops a debit card from the list
    void stop_Credit_Card(long long card); // Stops a credit card from the list
    void display_Pre_Paid_Cards(); // Displays all prepaid cards
    void display_debit_Cards(); // Displays all debit cards
    void display_credit_Cards(); // Displays all credit cards
};