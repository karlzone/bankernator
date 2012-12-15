/*
 * TFixedDepositAccount.h
 *
 *  Created on: 03.12.2012
 *      Author: Runge
 */

#ifndef TFIXEDDEPOSITACCOUNT_H_
#define TFIXEDDEPOSITACCOUNT_H_

#include "TCurrentAccount.h"
#include "TSavingsAccount.h"

namespace std {

class TFixedDepositAccount: virtual public std::TCurrentAccount,
		public std::TSavingsAccount {
public:
	TFixedDepositAccount(TCustomer*, TBank*, string, string, TMoney,double);
	virtual ~TFixedDepositAccount();

	int getAtyp();
	virtual void printAccountStatement();
};

} /* namespace std */
#endif /* TFIXEDDEPOSITACCOUNT_H_ */
