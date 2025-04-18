#include <iostream>
#include "UI.h"
#include "User.h"
#include "Admin.h"
#include "Client.h"
#include "Accounts.h"

User UI::current_user;
vector<User> UI::users;

void UI::main_menu() {
	int c;
	cout << "Welcome!\n";
	cout << "1. Login\n";
	cout << "2. Sign Up\n";
	cout << "3. Exit\n";
	cout << "Enter your choice: ";
	cin >> c;
	switch (c) {
	case 1:
		login();
		if (current_user.get_type() == "Admin") {
			admin_menu();
		}
		else if (current_user.get_type() == "Client") {
			client_menu();
		}
	case 2:
		sign_up();
		cout << "Sign up successful. Please login.\n";
		main_menu();
		
	case 3:
		cout << "Exiting...\n";
		exit(0);
	}
}
void UI::login() {
	string username, password;
	cout << "Enter username: "<< endl;
	cin >> username;
	cout << "Enter password: " << endl;
	cin >> password;
	bool logged_in = false;

	for (int i = 0; i < users.size(); i++) {
		if (users[i].get_username() == username && users[i].get_password() == password) {
			current_user = users[i];
			cout << "Login successful!\n";
			logged_in = true;
			break;
		}
	}
	if (!logged_in) {
		cout << "Invalid username or password. Please try again.\n";
		main_menu();
	}
}
void UI::sign_up() { //Main menu. Anyone can do it...
	string username, password, id;
	cout << "Enter username: " << endl;
	cin >> username;
	for (int i = 0; i < users.size(); i++) {
		if (users[i].get_username() == username) {
			cout << "Username already exists. Please try again.\n";
			sign_up();
		}
	}
	cout << "Enter password: " << endl;
	cin >> password;
	while (true) {
		id = to_string(rand() % 1000000000000);
		if (id.length() < 12) {
			id.insert(0, 12 - id.length(), '0');
		}
		bool isUnique = true;
		for (int i = 0; i < users.size(); i++) {
			if (users[i].get_id() == id) {
				isUnique = false;
				break;
			}
		}
		if (isUnique) {
			break;
		}
	}
	User new_user(username, password, "Client", id);
	users.push_back(new_user);
}

void UI::add_admin() { //Only accessed when the current_user is an admin...

	string username, password, id;
	cout << "Enter username: " << endl;
	cin >> username;
	for (int i = 0; i < users.size(); i++) {
		if (users[i].get_username() == username) {
			cout << "Username already exists. Please try again.\n";
			sign_up();
		}
	}
	cout << "Enter password: " << endl;
	cin >> password;
	while (true) {
		id = to_string(rand() % 1000000000000);
		if (id.length() < 12) {
			id.insert(0, 12 - id.length(), '0');
		}
		bool isUnique = true;
		for (int i = 0; i < users.size(); i++) {
			if (users[i].get_id() == id) {
				isUnique = false;
				break;
			}
		}
		if (isUnique) {
			break;
		}
	}
	User new_user(username, password, "Admin", id);
	users.push_back(new_user);
	cout << "New admin added.\n";

}
void UI::admin_menu() {
	Admin admin(current_user.get_username(), current_user.get_password(), current_user.get_type(), current_user.get_id());
	
	while (true) {
		int choice;
		cout << "\n1. Display Admins\n2. Add New Admin\n3. Display Clients\n4. Remove User \n5. Log out\n6. Exit\nEnter choice (1, 2, 3, 4, 5, 6): ";
		cin >> choice;
		if (choice == 1) {
			for (int i = 0; i < users.size(); i++) {
				if (users[i].get_type() == "Admin") {
					display_user(users[i]);
				}
			}
		}
		else if (choice == 2) {
			add_admin();
		}
		else if (choice == 2) {
			add_admin();
		}
		else if (choice == 3) {
			for (int i = 0; i < users.size(); i++) {
				if (users[i].get_type() == "Client") {
					display_user(users[i]);
				}
			}
		}
		else if (choice == 4) {
			string id;
			cout << "Enter user ID to remove: ";
			cin >> id;
			admin.removeUser(&id);
		}
		else if (choice == 5) {
			main_menu();
		}
		else if (choice == 6) {
			cout << "Exiting...\n";
			exit(0);
		}
		else {
			cout << "Invalid choice. Please try again.\n";
		}

	}
}
void UI::display_user(User usr) {

	cout << "Username: " << usr.get_username() << endl;
	cout << "User type: " << usr.get_type() << endl;
	cout << "User ID: " << usr.get_id() << endl;

}
vector <User> UI::get_users() {
	return users;
}

void UI::client_menu() {
	Client client(current_user.get_username(), current_user.get_password(), current_user.get_type(), current_user.get_id());

	while (true) {
		int choice;
		cout << "\n1. Add Account\n2. Delete Account\n3. Display Accounts\n4. Log out\n5. Exit\nEnter choice (1, 2, 3, 4, 5): ";
		cin >> choice;
		if (choice == 1) {
			string type;
			cout << "Enter account type (Savings/Current): ";
			cin >> type;
			client.addaccount(type);
		}
		else if (choice == 2) {
			string ID;
			cout << "Enter account ID to delete: ";
			cin >> ID;
			client.deleteAccount(ID);
		}
		else if (choice == 3) {
			cout << "Accounts: " << endl;
			client.displayAccounts();
		}
		else if (choice == 4) {
			main_menu();
		}
		else if (choice == 5) {
			cout << "Exiting...\n";
			exit(0);
		}
		else {
			cout << "Invalid choice. Please try again.\n";
		}
	}
}