#pragma once
#include "Accounts.h"

class Transactions {

private:

	Accounts& current;

public:

	Transactions(Accounts& c);

	void Send(long amount,Accounts reciever); //use addtobalance function in the reciever account to add the amount, subtract it from the current account and add the transaction to the logs

};