#include "Admin.h"

void Admin::displayUsers(vector<User>* users, UI ui) {

	cout << "Users:" << endl;

	for (int i = 0; i < users->size(); i++) {
		
		ui.display_user(users->at(i));

	}
}
