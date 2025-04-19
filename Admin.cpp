#include "Admin.h"

Admin::Admin(string name, string pass, string typ, string i) : User(name, pass, typ, i) {} //Constructor for admin

void Admin::removeUser(string id) { // Using UI ui to access the users

	UI ui;

	vector<User>& users = ui.get_users(); // Point at the users vector in UI

	for (int i = 0; i < users.size(); i++) {

		if (users[i].get_id() == id) {

			users.erase(users.begin() + i); 

			cout << "\nUser removed successfully!" << endl;

			return;
		}
	}
	cout << "\nUser not found!" << endl;
}