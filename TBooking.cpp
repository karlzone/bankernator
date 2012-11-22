/*
 * TBooking.cpp
 *
 * Created on: 1 Nov 2012
 * Author: karsten
 */

#include <iostream>

#include "TBooking.h"
//#include "TAccount.h"

using namespace std;

TBooking::TBooking(TMoney amount, TAccount *destinPtr, TAccount *sourcePtr,
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

	cout << "Adr. K TBooking vorher Dest: " << this->destinPtr->getCustomerPtr() << endl;
	cout << "Adr. K TBooking vorher Sour: " << this->sourcePtr->getCustomerPtr() << endl;

	this->sourcePtr->addBooking(this);
	this->destinPtr->addBooking(this);
//	sourcePtr->setBalance((sourcePtr->getBalance())-amount);
//	destinPtr->setBalance((destinPtr->getBalance())+amount);

	cout << "Adr. K TBooking nachher Dest: " << this->destinPtr->getCustomerPtr() << endl;
	cout << "Adr. K TBooking nachher Sour: " << this->sourcePtr->getCustomerPtr() << endl;

}

bool TBooking::isPrinted() {
	return printed;
}

void TBooking::printBooking(TAccount * accPTr, int w) {
	//FIXME
	//cout << date << "|" << sourcePtr->customerPtr->getName() << "|" << comment << endl;
	this->printed = true;
	cout.width(w-10); cout << ""; 	this->date.print(); 	cout << '|';

	cout.width(w-4);
	cout.precision(2);
	cout << fixed << this->amount.getAmount() << " ";
	cout.width(w-20);
	cout << this->amount.getCurrency() << '|';


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
