#pragma once  
#include <iostream>  
#include <vector>
#include <ctime>
#include "User.h"
#include "UI.h"
#include "Accounts.h"

using namespace std;

class Client: public User {
protected:
	Accounts* currentAccount = new Accounts; //A pointer to recieve the address of the current account from the accounts vector to avoid receiving a copy of it
	vector<Accounts> accounts;

public:

	Client(string name, string pass, string typ, string i);

	void setCurrentAccount(Accounts& acnt);

	Accounts& getCurrentAccount();

	void deleteAccount(string ID);

	void addaccount(string type, string country);

	void displayAccounts();

	vector<Accounts>& getAccounts();


};
