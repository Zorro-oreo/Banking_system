#include <iostream>
#include <vector>
#include "Accounts.h"
#include "Client.h"
#include "Admin.h"
using namespace std;

void Admin::admins() {
    username = { "Youssof", "Hazem", "Yaseen", "Maya" };
	password = { 1234, 5678, 9101, 1121 };
	// Initializing the admin usernames and passwords
	// This can be replaced with a database or file read in a real application
}
void Admin::display_Admins() {
	cout << "Admins:\n";
	for (size_t i = 0; i < username.size(); ++i) {
		cout << username[i] << endl;
    }
    
}
pair<string, long long> Admin::login() {
	cout << "Sign in\n";
	cout << "Enter username: ";  
	string input_username;  
	cin >> input_username;  
	cout << "Enter password: ";  
	long long input_password;  
	cin >> input_password;  
	for (size_t i = 0; i < username.size(); ++i) {  
		if (username[i] == input_username && password[i] == input_password) {  
			cout << "Login successful!\n";  
			return make_pair(input_username, input_password);  
		}  
	}  
	cout << "Invalid username or password!\n";  
	return make_pair("", -1);  
}
pair<string, long long> Admin::add_Admin() {
	cout << "Enter new admin username: ";
	string new_username;
	cin >> new_username;
	cout << "Enter new admin password: ";
	long long new_password;
	cin >> new_password;
	username.push_back(new_username);
	password.push_back(new_password);
	return make_pair(new_username, new_password);
}
void Admin::display_clients() {
	Client client;
	client.clients();
	client.displayClients();
}
void Admin::display_Cards(Cards &card) {
    card.display_Pre_Paid_Cards();
    card.display_debit_Cards();
    card.display_credit_Cards();
}
/*void Admin::display_Accounts_Transactions(Accounts &account) {
    account.display_Accounts_Transactions();
}*/
/*void Admin::display_Cards_Transactions(Cards &card) {
    card.display_Cards_Transactions();
}*/
void Admin::display_Accounts(Accounts &account) {
    account.displayAccount();
}
/*void Admin::display_Cards_details(Cards &card) {
    card.displayDetails();
}*/
void Admin::get_username() {
    cout << "Enter admin username: ";
    string input_username;
    cin >> input_username;
    username.push_back(input_username);
    // Using cin to get the username from the user
}
void Admin::get_password() {
    cout << "Enter admin password: ";
    long long input_password;
    cin >> input_password;
    password.push_back(input_password);
    // Using cin to get the password from the user
}

int main() {
	Admin admin;
	admin.admins();
	Cards card;
	Accounts account("DefaultType", 0);
	int choice;
	long long card_num, account_num;
	string username;
	long long password;

	auto credentials = admin.login();
	username = credentials.first;
	password = credentials.second;

	while (true) {

		if ((username == "Youssof" && password == 1234) ||
			(username == "Hazem" && password == 5678) ||
			(username == "Yaseen" && password == 9101) ||
			(username == "Maya" && password == 1121)) {
			cout << "Welcome " << username << "\n";
			break;
		}
		else {
			while (true) {
				cout << "1. Try again\n2. Exit\nEnter choice (1 or 2): ";
				cin >> choice;
				if (choice == 1) {
					credentials = admin.login();
					username = credentials.first;
					password = credentials.second;
					if ((username == "Youssof" && password == 1234) ||
						(username == "Hazem" && password == 5678) ||
						(username == "Yaseen" && password == 9101) ||
						(username == "Maya" && password == 1121)) {
						break;
					}
					else {
						cout << "Invalid username or password!\n";
					}
				}
				else if (choice == 2) {
					cout << "Exiting...\n";
					return 0;
				}
				else {
					cout << "Invalid choice! Please try again.\n";
				}
			}
		}
	}
	while (true) {
		
		cout << "\n1. Display Admins\n2. Add new Admin\n3. Display Clients\n4. Display Accounts\n5. Display Cards\n6. Exit\nEnter choice (1, 2, 3, 4, 5 or 6): ";
		cin >> choice;

		if (choice == 1) {
			admin.display_Admins();
			continue;
		}
		else if (choice == 2) {
			auto new_admin = admin.add_Admin();
			cout << "New admin added: " << new_admin.first << ", with password: " << new_admin.second << "\n";
			continue;
		}
		else if (choice == 3) {
			admin.display_clients();
			continue;
		}
		else if (choice == 4) {
			admin.display_Accounts(account);
			continue;
		}
		else if (choice == 5) {
			admin.display_Cards(card);
			continue;
		}
		else if (choice == 6) {
			cout << "Exiting...\n";
			break;
		}
		else {
			cout << "Invalid choice! Please try again.\n";
			continue;
		}
		

	return 0;
	}
}