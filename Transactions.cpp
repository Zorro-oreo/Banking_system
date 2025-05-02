#include "Transactions.h"
#include "Notifications.h"

Notifications Tnotif;

Transactions::Transactions(Accounts& c) : current(c) {}

void Transactions::Send(long amount, Accounts& reciever) {

	if (current.getCountry() == reciever.getCountry()) {

		if (current.getBalance() >= amount) {

			reciever.addToBalance(amount);
			current.subFromBalance(amount);

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