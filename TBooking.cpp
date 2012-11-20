/*
 * TBooking.cpp
 *
 * Created on: 1 Nov 2012
 * Author: karsten
 */

#include <iostream>

#include "TBooking.h"

using namespace std;

TBooking::TBooking(TMoney amount, TAccount *sourcePtr, TAccount *destinPtr,
		TDate date, TTime time, string comment) {
// TODO Auto-generated constructor stub
	sourcePtr->addBooking(this);
	destinPtr->addBooking(this);
	sourcePtr->setBalance((sourcePtr->getBalance())-amount);
	destinPtr->setBalance((destinPtr->getBalance())+amount);
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

void TBooking::printBooking(TAccount * accPTr, int w) {
	//FIXME
	//cout << date << "|" << sourcePtr->customerPtr->getName() << "|" << comment << endl;
	this->printed = true;
	cout.width(w-10); cout << ""; 	this->date.print(); 	cout << '|';
	cout.width(w); 	cout << this->amount.getAmount() << '|';
	if(accPTr->equal_to(destinPtr)){
		cout.width(w); cout << this->sourcePtr->getCustomerPtr()->getName() << '|';
	}else {
		cout.width(w); cout << this->destinPtr->getCustomerPtr()->getName() << '|';
	}
	cout.width(w); cout << this->comment << endl;
}


/*void TBooking::setPrinted(bool printed) {
 this->printed = printed;
 }*/

TBooking::~TBooking() {
// TODO Auto-generated destructor stub
}
