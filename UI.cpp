#include <iostream>
#include "UI.h"
#include "User.h"
#include "Admin.h"
#include "Client.h"
#include "Accounts.h"
#include "Cards.h"
#include "Transactions.h"

User UI::current_user;

vector <User> UI::users;

void UI::main_menu() {
	int c;
	cout << "\nWelcome!\n";
	cout << "1. Login\n";
	cout << "2. Sign Up\n";
	cout << "3. Exit\n";
	cout << "\nEnter your choice: \n";
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
		break;
	case 2:
		sign_up();
		cout << "\nSign up successful. Please login.\n";
		main_menu();
		break;
	case 3:
		cout << "Exiting...\n";
		exit(0);
	default:
		cout << "\nInvalid Choice. Try again.\n";
		main_menu();
		break;
	}
}
void UI::login() {
	string username, password;
	cout << "\nEnter username: "<< endl;
	cin >> username;
	cout << "\nEnter password: " << endl;
	cin >> password;
	bool logged_in = false;

	for (int i = 0; i < users.size(); i++) {
		if (users[i].get_username() == username && users[i].get_password() == password) {
			current_user = users[i];
			cout << "\nLogin successful!\n";
			logged_in = true;
			break;
		}
	}
	if (!logged_in) {
		cout << "\nInvalid username or password. Please try again.\n";
		main_menu();
	}
}
void UI::sign_up() { //Main menu. Anyone can do it...
	string username, password, id;
	cout << "\nEnter username: " << endl;
	cin >> username;
	for (int i = 0; i < users.size(); i++) {
		if (users[i].get_username() == username) {
			cout << "\nUsername already exists. Please try again.\n";
			sign_up();
		}
	}
	cout << "\nEnter password: " << endl;
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
	cout << "\nEnter username: " << endl;
	cin >> username;
	for (int i = 0; i < users.size(); i++) { //Checks if the name is taken
		if (users[i].get_username() == username) {
			cout << "\nAdmin already exists. Please try again.\n";
			sign_up();
		}
	}
	cout << "\nEnter password: " << endl;
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
	users.push_back(new_user); //Add new admin to the users vector
	cout << "\nNew admin added.\n"; //Add "with ID:" later

}
void UI::admin_menu() {
	Admin admin(current_user.get_username(), current_user.get_password(), current_user.get_type(), current_user.get_id()); //Create instance for admin
	
	while (true) {
		int choice;
		cout << "\n1. Display Admins\n2. Add New Admin\n3. Display Clients\n4. Remove User \n5. Log out\n6. Exit\nEnter your choice: \n";
		cin >> choice;
		if (choice == 1) {
			cout << "Admins: " << endl;
			for (int i = 0; i < users.size(); i++) {
				if (users[i].get_type() == "Admin") {
					display_user(users[i]);
				}
			}
		}
		else if (choice == 2) {
			add_admin();
		}
		else if (choice == 3) {

			cout << "Clients: " << endl; //List the users stored in the users vector

			for (int i = 0; i < users.size(); i++) {
				if (users[i].get_type() == "Client") {
					display_user(users[i]);
				}
			}

		}
		else if (choice == 4) {
			string id;
			cout << "\nEnter user ID to remove: ";
			cin >> id;
			admin.removeUser(id); //Goes to the remove function in the admin class
		}
		else if (choice == 5) {
			main_menu();
		}
		else if (choice == 6) {
			cout << "Exiting...\n";
			exit(0);
		}
		else {
			cout << "\nInvalid choice. Please try again.\n";
		}

	}
}
void UI::display_user(User usr) {

	cout << "\nUsername: " << usr.get_username() << endl;
	//cout << "User type: " << usr.get_type() << endl;
	cout << "User ID: " << usr.get_id() << endl;

}
vector <User>& UI::get_users() {
	return users;
}

void UI::client_menu() {
	Client client(current_user.get_username(), current_user.get_password(), current_user.get_type(), current_user.get_id());

	while (true) {
		int choice;
		cout << "\n1. Add Account\n2. Delete Account\n3. Display Accounts\n4. Get into Account\n5. Log out\n6. Exit\nEnter your choice: ";
		cin >> choice;
		if (choice == 1) {
			string type;
			string country;
			cout << "\nEnter account type (Savings/Current): ";
			cin >> type;
			cout << "\nEnter account Country: ";
			cin >> country;
			client.addaccount(type, country);
		}
		else if (choice == 2) {
			string ID;
			cout << "\nEnter account ID to delete: ";
			cin >> ID;
			client.deleteAccount(ID);
		}
		else if (choice == 3) {
			cout << "\nAccounts: \n" << endl;
			client.displayAccounts();
		}
		else if (choice == 4) {
			string ID;
			cout << "\nEnter account ID to get into: ";
			cin >> ID;
			bool found = false;
			for (int i = 0; i < client.getAccounts().size(); i++) {
				if (client.getAccounts()[i].getID() == ID) {
					found = true;
					client.setCurrentAccount(client.getAccounts()[i]); //fix this
					Account_menu(client);
				}
			}
			if (!found) {
				cout << "\nAccount not found.\n";
				client_menu();
			}
		}
		else if (choice == 5) {
			main_menu();
		}
		else if (choice == 6) {
			cout << "Exiting...\n";
			exit(0);
		}
		else {
			cout << "\nInvalid choice. Please try again.\n";
		}
	}
}
void UI::Account_menu(Client& client) {

	Transactions transact(client.getCurrentAccount());

	while (true) {
		int choice;
		cout << "\n1. Add Debit Card\n2. Add Credit Card\n3. Remove Debit Card\n4. Remove Credit Card\n5. Display Debit Cards\n6. Display Credit Cards\n7. Send funds\n8. Apply for loan\n9. View loan details\n10. Pay loan installment\n11. Show log\n12. Withdraw\n13. Deposit\n14. Back\nEnter Choice: ";
		cin >> choice;

		Cards cards;
		string card;
		bool Rfound = false; //For transactions

		string recieverID;
		long amount;

		switch (choice) { //Do NOT declare variables inside switch
		case 1:
			cout << "\nEnter Debit Card number: ";
			cin >> card;
			cards.add_Debit_Card(card, client.getCurrentAccount());
			break;
		case 2:
			cout << "\nEnter Credit Card number: ";
			cin >> card;
			cards.add_Credit_Card(card, client.getCurrentAccount());
			break;
		case 3:
			cout << "\nEnter Debit Card number to remove: ";
			cin >> card;
			cards.stop_Debit_Card(card, client.getCurrentAccount());
			break;
		case 4:
			cout << "\nEnter Credit Card number to remove: ";
			cin >> card;
			cards.stop_Credit_Card(card, client.getCurrentAccount());
			break;
		case 5:
			cards.display_debit_Cards(client.getCurrentAccount());
			cout << endl;
			break;
		case 6:
			cards.display_credit_Cards(client.getCurrentAccount());
			cout << endl;
			break;

		case 7:

			cout << "Enter beneficiary account ID: ";
			cin >> recieverID;

			cout << "Enter amount to send: ";
			cin >> amount;

			for (int i = 0; i < client.getAccounts().size(); i++) {
				if (client.getAccounts()[i].getID() == recieverID) {
					Rfound = true;
					
					transact.Send(amount, client.getAccounts()[i]);

				}
			}
			if (!Rfound) {
				cout << "\nAccount not found.\n";
				client_menu();
			}

			break;

		case 8:

			cout << "Enter amount for loan (you need to have more than half that amount currently in your balance): ";
			int amnt;
			cin >> amnt;

			client.getCurrentAccount().APLoan(amnt); //Appy for a loan
			break;

		case 9:

			if (client.getCurrentAccount().getLoan() != 0) { //Inquire about loan

				cout << "Loan taken: " << client.getCurrentAccount().getLoan() << endl;
				cout << "Debt to pay: " << client.getCurrentAccount().getDebt() << endl;

			}
			else {

				cout << "No loans taken.";

			}
			break;

		case 10:

			client.getCurrentAccount().Loan();
			break;

		case 11:

			for (int i = 0; i < transact.getLog().size(); i++) { //Print out the log

				cout << transact.getLog()[i];

			}

			break;

		case 12:

			cout << "Enter amount to withdraw:";

			int withdraw;
			cin >> withdraw;


			if (withdraw > client.getCurrentAccount().getBalance()) {
				cout << "low funds." << endl;
			}
			client.getCurrentAccount().subFromBalance(withdraw);
			cout << "Withdraw done. balance: " << client.getCurrentAccount().getBalance() << endl;

			break;

		case 13:

			cout << "Enter deposit amount: $";
			int dep;
			cin >> dep;
			client.getCurrentAccount().addToBalance(dep);
			cout << "Deposit successful!\n";

			break;

		case 14:
			return; // Return to the previous menu
		default:
			cout << "\nInvalid choice. Please try again.\n";
		}
	}
}