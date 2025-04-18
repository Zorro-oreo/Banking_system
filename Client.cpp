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