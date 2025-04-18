#pragma once
#include <iostream>

using namespace std;

class User {
protected:
	string username;
	string password;
	string type;
	string id;
public:
	User();
	User(string name, string pass, string typ, string i);
	string get_username();
	string get_password();
	string get_type();
	string get_id();
	void set_username(string U);
	void set_password(string P);
	void set_type(string T);
	void set_id(string I);
};
