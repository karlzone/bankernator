/*
 * TBooking.h
 *
 *  Created on: 1 Nov 2012
 *      Author: karsten
 */

#ifndef TBOOKING_H_
#define TBOOKING_H_

#include <string.h>

#include "bankernatorFktSum.h"
#include "TDate.h"
#include "TMoney.h"
#include "TTime.h"
#include "TAccount.h"

namespace std {

class TAccount;
class TDate;
class TTime;

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
	void addBooking(TAccount*);
public:
	TBooking(TBooking*);
	TBooking(TMoney, TAccount*, TAccount*, TDate, TTime, string);

	virtual ~TBooking();
	bool isPrinted();
	void printBooking(int w);

	//void setPrinted(bool printed);
	TMoney getAmount();
	string getComment();
	TDate getDate();
	TAccount* getDestinPtr();
	TAccount* getSourcePtr();
	TTime getTime();
};
}
#endif /* TBOOKING_H_ */
