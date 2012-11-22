/*
 * TSavingsAccount.h
 *
 *  Created on: 20.11.2012
 *      Author: Runge
 */

#ifndef TSAVINGSACCOUNT_H_
#define TSAVINGSACCOUNT_H_

#include "TAccount.h"

using namespace std;

class TSavingsAccount: virtual public TAccount {
protected:
	double *interestRate;
public:
	TSavingsAccount(TCustomer*, TBank*, string, string, double*);
	virtual ~TSavingsAccount();
};

#endif /* TSAVINGSACCOUNT_H_ */
