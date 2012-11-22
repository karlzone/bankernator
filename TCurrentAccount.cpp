/*
 * TCurrentAccount.cpp
 *
 *  Created on: 20.11.2012
 *      Author: Runge
 */

#include "TCurrentAccount.h"

using namespace std;

TCurrentAccount::TCurrentAccount(TCustomer *customerPtr, TBank *bankPtr, string accountNr,
		string pin, TMoney *disposit) {
	customerPtr->addAccount(this);
	bankPtr->addAccount(this);
	this->bankPtr = bankPtr;
	this->customerPtr = customerPtr;
	this->accountNr = accountNr;
	this->pin = pin;
	this->disposit = disposit;
	//TODO the amount of bookings
	this->sumOfBookings = 0;
	this->balance = 0;//Startguthaben
}

TMoney TCurrentAccount::getDisposit() {
	return disposit;
}

void TCurrentAccount::setDisposit(TMoney disposit) {
	this->disposit = disposit;
}

TCurrentAccount::~TCurrentAccount() {
	// TODO Auto-generated destructor stub
}
