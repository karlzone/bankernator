/*
 * TCurrentAccount.h
 *
 *  Created on: 20.11.2012
 *      Author: Runge
 */

#ifndef TCURRENTACCOUNT_H_
#define TCURRENTACCOUNT_H_

#include "TAccount.h"

using namespace std;

class TCurrentAccount: virtual public TAccount {
protected:
	TMoney *disposit;
public:
	TCurrentAccount(TCustomer*, TBank*, string, string, TMoney*);
	virtual ~TCurrentAccount();
	TMoney getDisposit();
	void setDisposit(TMoney disposit);
};
#endif /* TCURRENTACCOUNT_H_ */
