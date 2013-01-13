/*
 * TTransactionList.h
 *
 *  Created on: 06.12.2012
 *      Author: Runge
 */

#ifndef TTRANSACTIONLIST_H_
#define TTRANSACTIONLIST_H_

#include <iostream>
#include <fstream>
#include <vector>


#include "TDate.h"
#include "TTransaction.h"
#include "TTime.h"

namespace std {

class TTransaction;
class TDate;
class TTime;

class TTransactionList {
	TDate date;
	TTime time;
	vector<TTransaction> transactionsList;
	int transactionCounter;
public:
	TTransactionList(string);
	virtual ~TTransactionList();
	TTransaction operator[](int);
	friend ostream& operator<<(ostream &,TTransactionList&);
	unsigned getTransactionCounter() const;
	const TDate& getDate() const;
	const TTime& getTime() const;
	const vector<TTransaction>& getTransactionsList() const;
};

} /* namespace std */
#endif /* TTRANSACTIONLIST_H_ */
