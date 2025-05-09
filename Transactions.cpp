#include "Transactions.h"
#include "Notifications.h"

Notifications Tnotif;

Transactions::Transactions(Accounts& c) : current(c) {}

void Transactions::Send(long amount, Accounts& reciever) {

	if (current.getCountry() == reciever.getCountry()) {

		if (current.getBalance() >= amount) {

			reciever.addToBalance(amount);
			current.subFromBalance(amount);

			log(amount, reciever.getID()); //Add transaction to log

			Tnotif.message("Successfully sent $");
			Tnotif.message(amount);
			Tnotif.message(" to ");
			Tnotif.message(reciever.getID(), true);

		}
		else {

			Tnotif.message("Insufficient balance for transaction.", true);

		}

	}
	else {

		long fee = (amount * 10) / 100; // Calculate a fee of 1.5%

		if (current.getBalance() >= (amount + fee)) {

			reciever.addToBalance(amount);
			current.subFromBalance(amount + fee);

			log(amount, reciever.getID()); //Add transaction to log

			Tnotif.message("Successfully sent $");
			Tnotif.message(amount);
			Tnotif.message(" internationally to ");
			Tnotif.message(reciever.getID());
			Tnotif.message(" with a 1.5% fee of $");
			Tnotif.message(fee, true);

		}
		else {

			Tnotif.message("Insufficient balance for transaction.", true);

		}

	}

}

void Transactions::log(long amnt, string rcvr) {

	auto now = chrono::system_clock::now();

	// Convert to time_t to extract components like hour
	time_t now_time = chrono::system_clock::to_time_t(now);

	// Convert to local time
	tm* local_time = localtime(&now_time);

	// Get hour
	int hour = local_time->tm_hour;

	history.push_back(("At time " + to_string(hour) + ": Sent $ " + to_string(amnt) + " to " + rcvr + "\n"));

}

vector<string> Transactions::getLog() {

	return history;

}