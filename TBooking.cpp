/*
 * TBooking.cpp
 *
 * Created on: 1 Nov 2012
 * Author: karsten
 */
//#define DEBUG

#include <iostream>

#include "TBooking.h"

using namespace std;

TBooking::TBooking(TMoney amount, TAccount *sourcePtr, TAccount *destinPtr,
		TDate date, TTime time, string comment) {
// TODO Auto-generated constructor stub

	addBooking(sourcePtr,destinPtr);

	sourcePtr->setBalance((sourcePtr->getBalance())-amount);
	destinPtr->setBalance((destinPtr->getBalance())+amount);

	#ifdef DEBUG
	cout << "after addBooking:destinPtr: " << destinPtr->getCustomerPtr()->getName() << endl;
	cout << "after addBooking:sourcePtr: " << sourcePtr->getCustomerPtr()->getName() << endl;
	#endif

	init(amount,sourcePtr,destinPtr,date,time,comment);
}
TBooking::TBooking(TMoney amount, TCurrentAccount *sourcePtr, TAccount *destinPtr, TDate date, TTime time, string comment){
	if(sourcePtr->getBalance()-amount < sourcePtr->getDisposit()){
		cerr << "Dispo nicht gedeckt" << endl;
	}else {
		addBooking(sourcePtr,destinPtr);
		sourcePtr->setBalance((sourcePtr->getBalance())-amount);
		destinPtr->setBalance((destinPtr->getBalance())+amount);
		init(amount,sourcePtr,destinPtr,date,time,comment);
	}

}
TBooking::TBooking(TMoney amount, TSavingsAccount *sourcePtr, TAccount *destinPtr, TDate date, TTime time, string comment){
	init(amount,sourcePtr,destinPtr,date,time,comment);
}
TBooking::TBooking(TMoney amount, TFixedDepositAccount*sourcePtr, TAccount *destinPtr, TDate date, TTime time, string comment){
	init(amount,sourcePtr,destinPtr,date,time,comment);
}
void TBooking::addBooking(TAccount *sourcePtr,TAccount *destinPtr){
	sourcePtr->addBooking(this);
		destinPtr->addBooking(this);

		#ifdef DEBUG
		cout << "befor addBooking:destinPtr: " << destinPtr->getCustomerPtr()->getName() << endl;
		cout << "befor addBooking:sourcePtr: " << sourcePtr->getCustomerPtr()->getName() << endl;
		#endif

}
void TBooking::init(TMoney amount, TAccount *sourcePtr, TAccount *destinPtr,
		TDate date, TTime time, string comment){
	this->amount = amount;
	this->sourcePtr = sourcePtr;
	this->destinPtr = destinPtr;
	this->date = date;
	this->time = time;
	this->comment = comment;

	#ifdef DEBUG
	string bo = "Booking atributts:";
	cout <<  bo << "amount: "; this->amount.print(); cout << endl;
	cout <<  bo << "sourcPtr: " << this->sourcePtr->getCustomerPtr()->getName(); cout << endl;
	cout <<  bo << "destinPtr: " << this->destinPtr->getCustomerPtr()->getName(); cout << endl;
	cout <<  bo << "date: "; this->date.print() ; cout << endl;
	cout <<  bo << "time: "; this->time.print(); cout << endl;
	cout <<  bo << "comment: " << this->comment; cout << endl;
	#endif

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
	cout.width(w); 	cout << this->amount.getAmount()<< '|';
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
