/*
 * TBooking.cpp
 *
 * Created on: 1 Nov 2012
 * Author: karsten
 */

#include <iostream>

#include "TBooking.h"

//#define DEBUG
namespace std {

TBooking::TBooking(TBooking *tbp) {
	init((tbp->getAmount()), (tbp->getSourcePtr()), (tbp->getDestinPtr()),
			(tbp->getDate()), (tbp->getTime()), (tbp->getComment()));
	addBooking(this->sourcePtr);
	sourcePtr->setBalance((sourcePtr->getBalance()) + amount);
}

TBooking::TBooking(TMoney amount, TAccount *sourcePtr, TAccount *destinPtr,
		TDate date, TTime time, string comment) {
	switch (sourcePtr->getAtyp()) {
		case 0:
			init(amount, destinPtr, sourcePtr, date, time, comment);
			addBooking(sourcePtr);
			sourcePtr->setBalance((sourcePtr->getBalance()) - amount);
			new TBooking(this);
			break;
		case 1:
		case 3:
			//FIXME in der Abfrage müsste noch Disposit eingebaut werden. Ist dafür ein neuer Konstruktor nötig?
			if ((sourcePtr->getBalance().getAmount()) - (amount.getAmount()) < 0) {
					cout << endl << endl << "Dispo nicht gedeckt" << endl << endl;
				} else {
					init(amount, sourcePtr, destinPtr, date, time, comment);
					addBooking(sourcePtr);
					cout << endl << endl << "gebucht" << endl << endl;
					sourcePtr->setBalance((sourcePtr->getBalance())-amount);
					new TBooking(this);
				}
			break;
		case 2:
			//FIXME passende operationen bei einem TSavingsAccount
			init(amount, destinPtr, sourcePtr, date, time, comment);
			addBooking(sourcePtr);
			sourcePtr->setBalance((sourcePtr->getBalance()) - amount);
			new TBooking(this);
			break;
		//case 3:
			//FIXME TFixedDepositAccount fehlt noch
			//break;
		default:
			break;
	}

}

bool TBooking::isPrinted() {
	return printed;
}

TMoney TBooking::getAmount() {
	return amount;
}

string TBooking::getComment() {
	return comment;
}

TDate TBooking::getDate() {
	return date;
}

TAccount* TBooking::getDestinPtr() {
	return destinPtr;
}

TAccount* TBooking::getSourcePtr() {
	return sourcePtr;
}

TTime TBooking::getTime() {
	return time;
}

void TBooking::printBooking(int w) {
	//FIXME
	//cout << date << "|" << sourcePtr->customerPtr->getName() << "|" << comment << endl;
#ifndef DEBUG
	this->printed = true;
#endif
	cout.width(w - 10);
	cout << "";
	this->date.print();
	cout << '|';
	cout.width(w - 4);
	cout.precision(2);
	cout << fixed << this->amount.getAmount() << " ";
	cout.width(w - 20);
	cout << this->amount.getCurrency() << '|';
	cout << flush;
#ifdef DEBUG
	cout.width(w); cout << this->destinPtr->getCustomerPtr() << '|';
#else
	cout.width(w);
	cout << this->destinPtr->getCustomerPtr()->getName() << '|';
#endif
	cout.width(w);
	cout << this->comment << endl;
}

/*void TBooking::setPrinted(bool printed) {
 this->printed = printed;
 }*/

void TBooking::init(TMoney amount, TAccount *sourcePtr, TAccount *destinPtr,
		TDate date, TTime time, string comment) {
	this->amount = amount;
	this->sourcePtr = sourcePtr;
	this->destinPtr = destinPtr;
	this->date = date;
	this->time = time;
	this->comment = comment;
	this->printed = false;
#ifdef DEBUG
	string bo = "Booking atributts:";
	//cout <<  bo << "amount: "; this->amount.print(); cout << endl;

	cout << endl << bo << "sourcPtr: " << this->sourcePtr->getCustomerPtr()->getName(); cout << endl;
	cout << bo << "Add:sourcPtr: " << this->sourcePtr->getCustomerPtr(); cout << endl;
	cout << bo << "destinPtr: " << this->destinPtr->getCustomerPtr()->getName(); cout << endl;
	cout << bo << "Add:destinPtr: " << this->destinPtr->getCustomerPtr(); cout << endl;
	/*
	 cout <<  bo << "date: "; this->date.print() ; cout << endl;
	 cout <<  bo << "time: "; this->time.print(); cout << endl;
	 cout <<  bo << "comment: " << this->comment; cout << endl;
	 cout <<  bo << "printed: " << this->printed; cout << endl;
	 */
#endif
}

void TBooking::addBooking(TAccount *sourcePtr) {
	sourcePtr->addBooking(this);
#ifdef DEBUG
	cout << "TBooking:addBooking:sourcePtr: " << sourcePtr->getCustomerPtr()->getName() << endl;
	cout << "TBooking:addBooking:sourcePtr: " << sourcePtr->getCustomerPtr() << endl;
#endif
}

TBooking::~TBooking() {
// TODO Auto-generated destructor stub
}
}
