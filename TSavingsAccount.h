/*
 * TSavingsAccount.h
 *
 *  Created on: 02.12.2012
 *      Author: Runge
 */

#ifndef TSAVINGSACCOUNT_H_
#define TSAVINGSACCOUNT_H_

#include "TAccount.h"

namespace std {

class TSavingsAccount: public virtual std::TAccount {
protected:
	double* interestRate;
public:
	TSavingsAccount(TCustomer*, TBank*, string, string, double);
	virtual ~TSavingsAccount();
	double* getInterestRate();
	void setInterestRatePtr(double* interestRate);

	int getAtyp();
	virtual void printAccountStatement();
};

} /* namespace std */
#endif /* TSAVINGSACCOUNT_H_ */
