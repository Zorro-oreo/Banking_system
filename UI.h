#pragma once
#include "User.h"
#include <vector>

using namespace std;

class Client; // Forward declaration of Client class

class UI {
protected:
	static User current_user;
	static vector <User> users; //Store the users
public:
	void main_menu();
	void login();
	void sign_up();
	void admin_menu();
	void add_admin();
	void client_menu();
	void Account_menu(Client& client);
	void display_user(User usr);
	vector <User>& get_users();

};