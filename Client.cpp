#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib> 
#include <ctime>   
#include <limits>
#include <algorithm>
#include "Client.h"

using namespace std;

void Client::loadUsers() {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file for reading.\n";
        return;
    }

    string user, pass;
    long long id;
    while (file >> user >> pass >> id) {
        usernames.push_back(user);
        passwords.push_back(pass);
        ids.push_back(id);
    }
}

void Client::saveUsers() {
    ofstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file for writing.\n";
        return;
    }
    for (size_t i = 0; i < usernames.size(); ++i) {
        file << usernames[i] << " " << passwords[i] << " " << ids[i] << "\n";
    }
}

long long Client::generateRandomId() {
    long long newId;
    bool unique;
    do {
        unique = true;
        newId = 100000000000LL + rand() % 900000000000LL; // Generates a 12-digit ID
        if (find(ids.begin(), ids.end(), newId) != ids.end()) {
            unique = false;
        }
    } while (!unique);
    return newId;
}

Client::Client() {
    srand(static_cast<unsigned>(time(0)));
    loadUsers();
}
Client::~Client() { saveUsers(); }

void Client::registerAccount(const string& username, const string& password) {
    if (username.empty() || password.empty()) {
        cout << "Error: Username and password cannot be empty.\n";
        return;
    }
    usernames.push_back(username);
    passwords.push_back(password);
    ids.push_back(generateRandomId());
    cout << "Account registered successfully! Your ID is: " << ids.back() << endl;
}

bool Client::login(const string& username, const string& password) {
    for (size_t i = 0; i < usernames.size(); ++i) {
        if (usernames[i] == username && passwords[i] == password) {
            cout << "Login successful! Your ID is: " << ids[i] << endl;
            return true;
        }
    }
    cout << "Login failed: Invalid username or password.\n";
    return false;
}

bool Client::deleteAccount(const string& username, const string& password) {
    for (size_t i = 0; i < usernames.size(); ++i) {
        if (usernames[i] == username && passwords[i] == password) {
            usernames.erase(usernames.begin() + i);
            passwords.erase(passwords.begin() + i);
            ids.erase(ids.begin() + i);
            cout << "Account deleted successfully!" << endl;
            return true;
        }
    }
    cout << "Account not found or credentials incorrect!" << endl;
    return false;
}

bool Client::resetPassword(const string& username, long long id) {
    for (size_t i = 0; i < usernames.size(); ++i) {
        if (usernames[i] == username && ids[i] == id) {
            string newPassword;
            cout << "Enter new password: ";
            cin >> newPassword;
            if (newPassword.empty()) {
                cout << "Error: New password cannot be empty.\n";
                return false;
            }
            passwords[i] = newPassword;
            cout << "Password reset successfully!" << endl;
            return true;
        }
    }
    cout << "Username or ID not found!" << endl;
    return false;
}

bool Client::changePassword(const string& username, const string& oldPassword, const string& newPassword) {
    for (size_t i = 0; i < usernames.size(); ++i) {
        if (usernames[i] == username && passwords[i] == oldPassword) {
            if (newPassword.empty()) {
                cout << "Error: New password cannot be empty.\n";
                return false;
            }
            passwords[i] = newPassword;
            cout << "Password changed successfully!" << endl;
            return true;
        }
    }
    cout << "Invalid username or old password.\n";
    return false;
}

/*int main() {
    Client client;
    string username, password, newPassword;
    long long id;
    int choice;

    while (true) {
        cout << "\n1. Sign Up\n2. Login\n3. Delete Account\n4. Reset Password\n5. Change Password\n6. Exit\nEnter choice (1, 2, 3, 4, 5 or 6): ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            client.registerAccount(username, password);
        }
        else if (choice == 2) {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            client.login(username, password);
        }
        else if (choice == 3) {
            cout << "Enter username to delete: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            client.deleteAccount(username, password);
        }
        else if (choice == 4) {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter your ID: ";
            cin >> id;
            client.resetPassword(username, id);
        }
        else if (choice == 5) {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter old password: ";
            cin >> password;
            cout << "Enter new password: ";
            cin >> newPassword;
            client.changePassword(username, password, newPassword);
        }
        else if (choice == 6) {
            cout << "Exiting the program.\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}*/