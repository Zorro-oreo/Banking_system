#include <iostream>
#include "UI.h"
#include "User.h"
#include "Admin.h"
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
		break;
	case 2:
		sign_up();
		break;
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
	for (int i = 0; i < users.size(); i++) {

		bool logged_in = false;

		if (users[i].get_username() == username && users[i].get_password() == password) {
			current_user = users.at(i);
			cout << "Login successful!\n";
			logged_in = true;
			break;
		}

		if (!logged_in) {
			cout << "Invalid username or password. Please try again.\n";
			main_menu();
		}

	}
}
void UI::sign_up() { //Main menu. Anyone can do it...
	string username, password;
	cout << "Enter username: " << endl;
	cin >> username;
	cout << "Enter password: " << endl;
	cin >> password;
	User new_user(username, password, "Client", "123456789");
	users.push_back(new_user);
	cout << "Sign up successful.\n";
}

void UI::add_admin() { //Only accessed when the current_user is an admin...

	string username, password;
	cout << "Enter username: " << endl;
	cin >> username;
	cout << "Enter password: " << endl;
	cin >> password;
	User new_user(username, password, "Admin", "123456788");
	users.push_back(new_user);
	cout << "New admin added.\n";

}
void UI::admin_menu() {
	Admin admin(current_user.get_username(), current_user.get_password(), current_user.get_type(), current_user.get_id());
	
	while (true) {
		int choice;
		cout << "\n1. Display Admins\n2. Add New Admin\n3. Display Clients\n4.Remove User \n5. Log out\n6. Exit\nEnter choice (1, 2, 3, 4, 5, 6): ";
		cin >> choice;
		switch (choice) {
		case 1:
			admin.displayUsers(&users);
			break;
		case 2:
			add_admin();
			break;
		case 3:
			admin.displayUsers(&users);
			break;
		case 4:
			string id;
			cout << "Enter user ID to remove: ";
			cin >> id;
			admin.removeUser(&id);
			break;
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