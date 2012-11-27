/*
 * TBooking.cpp
 *
 * Created on: 1 Nov 2012
 * Author: karsten
 */

#include <iostream>

#include "TBooking.h"

#define DEBUG
using namespace std;

TBooking::TBooking(TBooking *tbp){
	init((tbp->getAmount()), (tbp->getSourcePtr()), (tbp->getDestinPtr()), (tbp->getDate()), (tbp->getTime()), (tbp->getComment()));
	addBooking(this->sourcePtr);
//	sourcePtr->setBalance((sourcePtr->getBalance())+amount);
}

TBooking::TBooking(TMoney amount, TAccount *destinPtr, TAccount *sourcePtr,
		TDate date, TTime time, string comment) {

	init(amount, destinPtr, sourcePtr, date, time, comment);
	addBooking(sourcePtr);
//	sourcePtr->setBalance((sourcePtr->getBalance())-amount);
	new TBooking(this);
}

/*
TBooking::TBooking(TMoney amount, TCurrentAccount *sourcePtr, TAccount *destinPtr, TDate date, TTime time, string comment){
	if(sourcePtr->getBalance()-amount < sourcePtr->getDisposit()){
		cerr << "Dispo nicht gedeckt" << endl;
	}else {
		init(amount,sourcePtr,destinPtr,date,time,comment);
		addBooking(sourcePtr);
//		sourcePtr->setBalance((sourcePtr->getBalance())-amount);
		new TBooking(this);
	}
}
*/

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

void TBooking::printBooking(TAccount * accPTr, int w) {
	//FIXME
	//cout << date << "|" << sourcePtr->customerPtr->getName() << "|" << comment << endl;
#ifndef DEBUG
	this->printed = true;
#endif
	cout.width(w-10); cout << ""; 	this->date.print(); 	cout << '|';
	cout.width(w-4);
	cout.precision(2);
	cout << fixed << this->amount.getAmount() << " ";
	cout.width(w-20);
	cout << this->amount.getCurrency() << '|';
	cout << flush;
//	cout.width(w); cout << this->destinPtr->getCustomerPtr()->getName() << '|';
#ifdef DEBUG
	cout.width(w); cout << this->destinPtr->getCustomerPtr() << '|';
#endif
	cout.width(w); cout << this->comment << endl;
}

/*void TBooking::setPrinted(bool printed) {
 this->printed = printed;
 }*/

void TBooking::init(TMoney amount, TAccount *destinPtr, TAccount *sourcePtr,
		TDate date, TTime time, string comment){
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

	cout << endl <<  bo << "sourcPtr: " << this->sourcePtr->getCustomerPtr()->getName(); cout << endl;
	cout <<  bo << "Add:sourcPtr: " << this->sourcePtr->getCustomerPtr(); cout << endl;
	cout <<  bo << "destinPtr: " << this->destinPtr->getCustomerPtr()->getName(); cout << endl;
	cout <<  bo << "Add:destinPtr: " << this->destinPtr->getCustomerPtr(); cout << endl;
	/*
	cout <<  bo << "date: "; this->date.print() ; cout << endl;
	cout <<  bo << "time: "; this->time.print(); cout << endl;
	cout <<  bo << "comment: " << this->comment; cout << endl;
	cout <<  bo << "printed: " << this->printed; cout << endl;
	*/
#endif
}

void TBooking::addBooking(TAccount *sourcePtr){
	sourcePtr->addBooking(this);
	#ifdef DEBUG
	cout << "TBooking:addBooking:sourcePtr: " << sourcePtr->getCustomerPtr()->getName() << endl;
	cout << "TBooking:addBooking:sourcePtr: " << sourcePtr->getCustomerPtr() << endl;
	#endif
}



TBooking::~TBooking() {
// TODO Auto-generated destructor stub
}
