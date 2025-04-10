#include <iostream>
#include <vector>
#include "Accounts.h"
#include "Admin.h"
using namespace std;

void Admin::admins() {
    username.push_back("Youssef");
    username.push_back("Hazem");
    username.push_back("Yaseen");
    username.push_back("Maya");
    password.push_back(1234);
    password.push_back(5678);
    password.push_back(91011);
    password.push_back(121314);
}
void Admin::display_Admins() {
    cout << "Admins: " << endl;
    for (size_t i = 0; i < username.size(); i++) {
        cout << username[i] << endl;
    }
    
}
/*void Admin::display_Accounts(Accounts &account) {
    account.display_Accounts();
}*/
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
/*void Admin::display_Accounts_details(Accounts &account) {
    account.display_Accounts_details();
}*/
void Admin::display_Accounts(Accounts &account) {
    account.displayAccount();
}
/*void Admin::display_Accounts_Transactions(Accounts &account) {
    account.displayTransactions();
}*/
/*void Admin::display_Accounts_details(Accounts &account) {
    account.displayDetails();
}*/
/*void Admin::display_Cards_Transactions(Cards &card) {
    card.displayTransactions();
}*/
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
    Cards card;
    Accounts account("DefaultType", 0);
    int choice;
    long long card_num, account_num, password;
    string username;

    while (true) {
        cout << "\n1. Display Admins\n2. Display Accounts\n3. Display Cards\n4. Exit\nEnter choice (1, 2, 3 or 4): ";
        cin >> choice;

        if (choice == 1) {
            admin.display_Admins();
        } else if (choice == 2) {
            admin.display_Accounts(account);
        } else if (choice == 3) {
            admin.display_Cards(card);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}