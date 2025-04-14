#pragma once
#include <iostream>
#include <vector>
#include "User.h"
#include "UI.h"

using namespace std;

class Admin: public User {
public:
	Admin();
	void displayUsers(vector<User>* users);
	void removeUser(string* id);
	void displayUserDetails(string* id);

};