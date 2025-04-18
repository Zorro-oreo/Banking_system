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
		cout << "Account deleted successfully!" << endl;
	}
	else {
		cout << "Account not found!" << endl;
		cout << "Account not found!" << endl;
	}
}

void Client::addaccount(string type) {
   while (true) {  
       if (type != "Savings" && type != "Current") {  
           cout << "Invalid account type!" << endl;  
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
           Accounts newAccount(type, ID);  
           accounts.push_back(newAccount);  
           cout << "Account added successfully with ID: " << ID << endl;  
           return;  
       }  
   }  
}
void Client::displayAccounts() {
	if (accounts.empty()) {
		cout << "No accounts." << endl;
		return;
	}
	for (int i = 0; i < accounts.size(); i++) {
		accounts[i].displayAccount();
	
	}
}