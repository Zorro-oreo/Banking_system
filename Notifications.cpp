#include "Notifications.h"

vector <string> Notifications::History;

void Notifications::message(string m, bool newline) {

	if (newline) {

		cout << m << endl;

		History.push_back(m);
		History.push_back("\n");

	}
	else {

		cout << m;
		History.push_back(m);

	}

}

void Notifications::message(long m, bool newline) {

	if (newline) {

		cout << m << endl;
		History.push_back(to_string(m));
		History.push_back("\n");

	}
	else {

		cout << m;
		History.push_back(to_string(m));

	}

}