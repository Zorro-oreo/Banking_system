#pragma once
#include <iostream>

using namespace std;

class User {
protected:
	string username;
	string password;
	string type;
	long long id;
public:
	User(string name, string pass, string typ, long long i);
	string get_username();
	string get_password();
	string get_type();
	long long get_id();
	void set_username(string U);
	void set_password(string P);
	void set_type(string T);
	void set_id(long long I);
};
