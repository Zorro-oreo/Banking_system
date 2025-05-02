#include "Notifications.h"

void Notifications::message(string m, bool newline) {

	if (newline) {

		cout << m << endl;

	}
	else {

		cout << m;

	}

}

void Notifications::message(long m, bool newline) {

	if (newline) {

		cout << m << endl;

	}
	else {

		cout << m;

	}

}