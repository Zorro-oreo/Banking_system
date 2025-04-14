#include "User.h"

User::User(string name, string pass, string typ, long long i): username(name), password(pass), type(typ), id(i){}

string User::get_username() {
	return username;
}
string User::get_password() {
	return password;
}
string User::get_type() {
	return type;
}
long long User::get_id() {
	return id;
}
void User::set_username(string U) {
	username = U;
}
void User::set_password(string P) {
	password = P;
}
void User::set_type(string T) {
	type = T;
}
void User::set_id(long long I) {
	id = I;
}