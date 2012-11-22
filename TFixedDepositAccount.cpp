/*
 * TFixedDepositAccount.cpp
 *
 *  Created on: 20.11.2012
 *      Author: Runge
 */

#include "TFixedDepositAccount.h"

using namespace std;

TFixedDepositAccount::TFixedDepositAccount(TCustomer *customerPtr, TBank *bankPtr, string accountNr,
		string pin, TMoney *disposit, double *interestRate) {
	customerPtr->addAccount(this);
	bankPtr->addAccount(this);
	this->bankPtr = bankPtr;
	this->customerPtr = customerPtr;
	this->accountNr = accountNr;
	this->pin = pin;
	this->disposit = disposit;
	this->interestRate = interestRate;
	//TODO the amount of bookings
	this->sumOfBookings = 0;
	this->balance = 0;//Startguthaben
}

TFixedDepositAccount::~TFixedDepositAccount() {
	// TODO Auto-generated destructor stub
}
