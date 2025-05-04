#include "ApplyForLoans.h"

vector<Accounts> APLoans::indebtedAccounts;

APLoans::APLoans(Accounts& Applier, int amount) {

	if (Applier.getBalance() > (0.5 * amount)) {

		indebtedAccounts.push_back(Applier);

	}

}
