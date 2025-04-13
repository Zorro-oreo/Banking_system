#pragma once
#include <vector>
#include "Cards.h"
using namespace std;

class Admin{
private:
    vector<string> password;
    vector<string> username;
    // Using list for dynamic size and easy insertion/deletion
public:
    Admin() = default;
    void admins(); // Admin constructor
	pair<string, string> login(); // Admin login
	void logout(); // Admin logout
	pair<string, string> add_Admin(); // Adds a new admin
    void display_Admins(); // Displays all admins
	void display_clients(); // Displays all clients
    void display_Accounts(Accounts &account); // Displays all accounts
    void display_Cards(Cards &card); // Displays all cards
    void display_Accounts_Transactions(Accounts &account); // Displays all account transactions
    void display_Cards_Transactions(Cards &card); // Displays all card transactions
    void get_username(); // Gets the username of the admin
    void get_password(); // Gets the password of the admin
};
