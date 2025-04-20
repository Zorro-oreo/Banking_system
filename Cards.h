#pragma once
#include <vector>
#include "Accounts.h"
using namespace std;

class Cards{
public:
    Cards() = default;
    void add_Debit_Card(string card, Accounts &account); // Adds a debit card to the list
    void add_Credit_Card(string card, Accounts& account); // Adds a credit card to the list
    void stop_Debit_Card(string card, Accounts& account); // Stops a debit card from the list
    void stop_Credit_Card(string card, Accounts& account); // Stops a credit card from the list
    void display_debit_Cards(Accounts& account); // Displays all debit cards
    void display_credit_Cards(Accounts& account); // Displays all credit cards
};