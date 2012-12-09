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

class TCurrentAccount: public virtual std::TAccount {
protected:

public:
	TCurrentAccount(TCustomer*, TBank*, string, string, TMoney*);
	virtual ~TCurrentAccount();
	TMoney* getDispo();
};

} /* namespace std */
#endif /* TCURRENTACCOUNT_H_ */
