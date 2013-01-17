/*
 * TTransaction.h
 *
 *  Created on: 06.12.2012
 *      Author: Runge
 */

#ifndef TTRANSACTION_H_
#define TTRANSACTION_H_

#include <iostream>
#include <string>
#include <vector>

#include "TBank.h"
#include "bankernatorFktSum.h"
#include "TCustomer.h"
#include "TMoney.h"
#include "TBooking.h"

namespace std {

class TMoney;

class TTransaction {

	string accountNr;
	unsigned BLZ;
	string contraAccountNr;
	unsigned contraBLZ;
	TMoney amount;
	string comment;

public:

	TTransaction();
	virtual ~TTransaction();

	friend ostream &operator<< (ostream &ostr, const TTransaction &a);
	friend istream &operator>> (istream &istr, TTransaction &a);

	unsigned getBLZ() const;
	unsigned getContraBLZ() const;
	const string& getAccountNr() const;
	const string& getContraAccountNr() const;
	const TMoney& getAmount() const;
	const string& getComment() const;

};

} /* namespace std */
#endif /* TTRANSACTION_H_ */
