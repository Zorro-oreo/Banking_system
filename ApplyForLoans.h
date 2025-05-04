#pragma once
#include "Client.h"
using namespace std;

class APLoans {
protected:

	static vector<Accounts> indebtedAccounts;

public:

	APLoans(Accounts& Applier, int amount);

};
