#include "Client.h"

Client::Client(string name, string pass, string typ, string i) : User(name, pass, typ, i) {}

void Client::deleteAccount(string ID) {

	bool found = false;

	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].getID() == ID) {
			accounts.erase(accounts.begin() + i);

			found = true;
		}
	}

	if (found) {
		cout << "\nAccount deleted successfully!" << endl;
	}
	else {
		cout << "\nAccount not found!" << endl;
	}
}

void Client::addaccount(string type, string country) {
   while (true) {  
       if (type != "Savings" && type != "Current") {  
           cout << "\nInvalid account type!" << endl;  
           return;  
       }  
       string ID = to_string(rand() % 1000000000000);  
       if (ID.length() < 12) {  
           ID.insert(0, 12 - ID.length(), '0');  
       }  
       bool isUnique = true;  
       for (int i = 0; i < accounts.size(); i++) {  
           if (accounts[i].getID() == ID) {  
               isUnique = false;  
               break;  
           }  
       }  
       if (isUnique) {  
           Accounts newAccount(type, ID, country);  
           accounts.push_back(newAccount);  
           cout << "\nAccount added successfully with ID: " << ID << endl;  
           return;  
       }  
   }  
}
void Client::displayAccounts() {
	if (accounts.empty()) {
		cout << "\nNo accounts." << endl;
		return;
	}
	for (int i = 0; i < accounts.size(); i++) {
		accounts[i].displayAccount();
	
	}
}

void Client::setCurrentAccount(Accounts& acnt) {  
   currentAccount = &acnt;  
}

Accounts& Client::getCurrentAccount() {
	return *currentAccount;
}

vector<Accounts>& Client::getAccounts() {
	return accounts;
}

Client::~Client() {

	delete currentAccount; //Delete dynamically allocated memory

}