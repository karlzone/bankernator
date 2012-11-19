/*
 * TBooking.h
 *
 *  Created on: 1 Nov 2012
 *      Author: karsten
 */

#ifndef TBOOKING_H_
#define TBOOKING_H_

#include <string.h>

#include "TDate.h"
#include "TMoney.h"
#include "TTime.h"

namespace std {

class TAccount;

class TBooking {
	TMoney amount;
	TAccount* sourcePtr;
	TAccount* destinPtr;
	TDate date;
	TTime time;
	string comment;
	bool printed;


public:
	TBooking();
	virtual ~TBooking();
	bool isPrinted() const;
	void setPrinted(bool printed);
};

} /* namespace std */
#endif /* TBOOKING_H_ */
