#pragma once
#include "User.h"
#include <vector>

using namespace std;

class UI {
protected:
	string current_user;
	vector <User> users;
public:
	void main_menu();
	void login();
	void sign_up();
	void admin_menu();
	void add_admin();
	void client_menu();
	void set_user(string U);
	void display_user(User usr);
};
