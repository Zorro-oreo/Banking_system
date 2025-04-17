#pragma once
#include "User.h"
#include <vector>

using namespace std;

class UI {
protected:
	static User current_user;
	static vector <User> users;
public:
	void main_menu();
	void login();
	void sign_up();
	void admin_menu();
	void add_admin();
	void client_menu();
	void set_CurrentUser(string CU);
	void display_user(User usr);
	vector <User> get_users();
};
