/*
 * TAccount.cpp
 *
 *  Created on: 28 Oct 2012
 *      Author: karsten
 */

#include "TAccount.h"

using namespace std;

/*TAccount::TAccount() {
	// TODO Auto-generated constructor stub
}*/

TAccount::~TAccount() {
	// TODO Auto-generated destructor stub
}

TAccount::TAccount(TCustomer *customerPtr, TBank *bankPtr, string accountNr, string pin){
	customerPtr->addAccount(this);
	bankPtr->addAccount(this);
	this->bankPtr = bankPtr;
	this->customerPtr = customerPtr;
	this->accountNr = accountNr;
	this->pin = pin;

	//TODO the amount of bookings
	this->sumOfBookings = 0;
	this->balance = 123456;
}

string TAccount::getAccountNr() {
	return accountNr;
}
/*
void TAccount::setAccountNr(string accountNr) {
	this->accountNr = accountNr;
}*/


TCustomer* TAccount::getCustomerPtr() {
	return customerPtr;
}
/*
void TAccount::setCustomerPtr(TCustomer* customerPtr) {
	this->customerPtr = customerPtr;
}*/

string TAccount::getPin() {
	return pin;
}

void TAccount::setPin(string pin) {
	this->pin = pin;
}

int TAccount::getSumOfBookings() {
	return sumOfBookings;
}

/* TODO
void TAccount::setSumOfBookings(int sumOfBookings) {
	this->sumOfBookings = sumOfBookings;
}*/

void TAccount::print() {
	customerPtr->print();
	cout << "Account number:  " << accountNr << endl;
	cout << "Bookings:        " << sumOfBookings << endl;
	cout << "Balance:         " << 00000 << endl;
}

void TAccount::printAccountStatement() {
	//TODO Account statement print with status printed=false
	for(int i = 0; i < sumOfBookings; i++) {
		if(bookingList[i]->isPrinted() == false) {
			cout << "BLA" << endl;
		}
	}
}
