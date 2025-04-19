#pragma once
#include <iostream>
#include <vector>
#include "User.h"
#include "UI.h"

using namespace std;

class Admin: public User { //Admin user child
public:

	Admin(string name, string pass, string typ, string i);
	void removeUser(string id);

};