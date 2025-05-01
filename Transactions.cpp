#include "Transactions.h"
#include "Notifications.h"

Notifications Tnotif;

Transactions::Transactions(Accounts& c) : current(c) {}

void Transactions::Send(long amount, Accounts reciever) {

	reciever.addToBalance(amount);
	current.subFromBalance(amount);

	Tnotif.message("Successfully sent ");
	Tnotif.message(amount);
	Tnotif.message(" to ");
	Tnotif.message(reciever.getID(), true);

}