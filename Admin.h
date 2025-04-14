#pragma once
#include <iostream>
#include <vector>
#include "User.h"
#include "UI.h"

using namespace std;

class Admin: public User {
protected:
	string username;
	string password;
	long long id;
public:
	Admin(string username, string password);
	void displayUsers(vector<User>* users, UI ui);
	void removeUser(string* id);
	void updateUser(string username, string newPassword, string newRole);
	void displayUserDetails(string* id);
	void searchUser(string* id);

};