#include "Admin.h"

UI ui;

Admin::Admin(string name, string pass, string typ, string i) : User(name, pass, typ, i) {} //Constructor for admin

void Admin::displayUsers(vector<User>* users) { //Using UI ui to access the users
	cout << "Users:" << endl;

	for (int i = 0; i < users->size(); i++) {
		
		ui.display_user(users->at(i));

	}
}
void Admin::removeUser(string* id) { //Using UI ui to access the users
	for (int i = 0; i < ui.get_users().size(); i++) {
		if (ui.get_users()[i].get_id() == *id) {
			ui.get_users().erase(ui.get_users().begin() + i);
			cout << "User removed successfully!" << endl;
		}
	}
	cout << "User not found!" << endl;
}
void Admin::displayUserDetails(string* id) {
	for (int i = 0; i < ui.get_users().size(); i++) {
		if (ui.get_users()[i].get_id() == *id) {
			cout << "Username: " << ui.get_users()[i].get_username() << endl;
			cout << "ID: " << ui.get_users()[i].get_id() << endl;
			cout << "Type: " << ui.get_users()[i].get_type() << endl;
			cout << "Password: " << ui.get_users()[i].get_password() << endl;
		}
	}
}