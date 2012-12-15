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

class TFixedDepositAccount: public std::TCurrentAccount,
		public std::TSavingsAccount {
public:
	//TFixedDepositAccount(TCustomer*, TBank*, string, string, TMoney*,double*);
	virtual ~TFixedDepositAccount();
};

} /* namespace std */
#endif /* TFIXEDDEPOSITACCOUNT_H_ */
