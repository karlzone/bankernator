/*
 * TFixedDepositAccount.h
 *
 *  Created on: 20.11.2012
 *      Author: Runge
 */

#ifndef TFIXEDDEPOSITACCOUNT_H_
#define TFIXEDDEPOSITACCOUNT_H_

#include "TSavingsAccount.h"
#include "TCurrentAccount.h"

using namespace std;

class TFixedDepositAccount: public TCurrentAccount, public TSavingsAccount {
public:
	TFixedDepositAccount(TCustomer*, TBank*, string, string, TMoney*, double*);
	virtual ~TFixedDepositAccount();
};

#endif /* TFIXEDDEPOSITACCOUNT_H_ */
