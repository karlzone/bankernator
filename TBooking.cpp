/*
* TBooking.cpp
*
* Created on: 1 Nov 2012
* Author: karsten
*/

#include <iostream>


#include "TBooking.h"


namespace std {

TBooking::TBooking(TMoney amount, TAccount *sourcePtr, TAccount *destinPtr,
		TDate date, TTime time, string comment) {
// TODO Auto-generated constructor stub
	this->amount = amount;
	this->sourcePtr = sourcePtr;
	this->destinPtr = destinPtr;
	this->date = date;
	this->time = time;
	this->comment = comment;

	//TODO Print status for Bookings
	this->printed = false;

}

bool TBooking::isPrinted() {
	return printed;
}

void TBooking::printBooking() {
	//FIXME
	//cout << date << "|" << sourcePtr->customerPtr->getName() << "|" << comment << endl;
	this->printed = true;
}

/*void TBooking::setPrinted(bool printed) {
	this->printed = printed;
}*/

TBooking::~TBooking() {
// TODO Auto-generated destructor stub
}

} /* namespace std */
