/*
 * TCurrentAccount.h
 *
 *  Created on: 02.12.2012
 *      Author: Runge
 */

#ifndef TCURRENTACCOUNT_H_
#define TCURRENTACCOUNT_H_

#include "TAccount.h"

namespace std {

class TCurrentAccount: public virtual TAccount {
protected:
	//TMoney* Disposit;

public:
	TCurrentAccount(TCustomer*, TBank*, string, string, TMoney);
	virtual ~TCurrentAccount();
	TMoney* getDisposit();

	virtual void printAccountStatement();
	int getAtyp();
};

} /* namespace std */
#endif /* TCURRENTACCOUNT_H_ */
