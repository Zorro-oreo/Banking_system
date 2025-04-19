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

	vector<Accounts> accounts;

public:

	Client(string name, string pass, string typ, string i);;

	void deleteAccount(string ID);

	void addaccount(string type);

	void displayAccounts();


};
