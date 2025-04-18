#pragma once  
#include <iostream>  
#include <vector>  
#include "User.h"
#include "UI.h"
#include "Accounts.h"

using namespace std;

class Client: public User {
private:

	vector<Accounts> accounts;

public:

	Client(string name, string pass, string typ, string i);;

	void deleteAccount(string ID);

	bool resetPassword(string& username, string id);

	bool changePassword(string& username, string& oldPassword, string& newPassword);

	void displayCards(string& id);

	void displayAccounts(string& id);

};
