#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Notifications {

public:

	void message(string m, bool newline = false); //For other classes to print to screen
	void message(long m, bool newline = false);

};