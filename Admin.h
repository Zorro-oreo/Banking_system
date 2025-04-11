#pragma once
#include <vector>
#include "Cards.h"
using namespace std;

class Admin{
private:
    vector<long long> password;
    vector<string> username;
    // Using list for dynamic size and easy insertion/deletion
public:
    Admin() = default;
    void admins(); // Admin constructor
    void display_Admins(); // Displays all admins
    void display_Accounts(Accounts &account); // Displays all accounts
    void display_Cards(Cards &card); // Displays all cards
    void display_Accounts_Transactions(Accounts &account); // Displays all account transactions
    void display_Cards_Transactions(Cards &card); // Displays all card transactions
    void get_username(); // Gets the username of the admin
    void get_password(); // Gets the password of the admin
};
