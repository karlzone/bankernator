/*
 * TBooking.h
 *
 *  Created on: 1 Nov 2012
 *      Author: karsten
 */

#ifndef TBOOKING_H_
#define TBOOKING_H_

#include <string.h>

#include "TAccount.h"
#include "TCurrentAccount.h"
#include "TDate.h"
#include "TFixedDepositAccount.h"
#include "TMoney.h"
#include "TSavingsAccount.h"
#include "TTime.h"


using namespace std;

class TBooking {

private:
	TMoney amount;
	TAccount* sourcePtr;
	TAccount* destinPtr;
	TDate date;
	TTime time;
	string comment;
	bool printed;

	void init(TMoney, TAccount*, TAccount*, TDate, TTime, string);
	void addBooking(TAccount*,TAccount*);

public:
	TBooking(TMoney, TAccount*, TAccount*, TDate, TTime, string);
	TBooking(TMoney, TCurrentAccount*, TAccount*, TDate, TTime, string);
	TBooking(TMoney, TSavingsAccount*, TAccount*, TDate, TTime, string);
	TBooking(TMoney, TFixedDepositAccount*, TAccount*, TDate, TTime, string);


	virtual ~TBooking();
	bool isPrinted();
	void printBooking(TAccount*, int w);
	//void setPrinted(bool printed);
};

#endif /* TBOOKING_H_ */
