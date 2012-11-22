/*
 * TSavingsAccount.cpp
 *
 *  Created on: 20.11.2012
 *      Author: Runge
 */

#include "TSavingsAccount.h"

using namespace std;

TSavingsAccount::TSavingsAccount(TCustomer *customerPtr, TBank *bankPtr, string accountNr,
		string pin, double *interestRate) {
	customerPtr->addAccount(this);
	bankPtr->addAccount(this);
	this->bankPtr = bankPtr;
	this->customerPtr = customerPtr;
	this->accountNr = accountNr;
	this->pin = pin;
	this->interestRate = interestRate;
	//TODO the amount of bookings
	this->sumOfBookings = 0;
	this->balance = 0;//Startguthaben
	// TODO Auto-generated constructor stub

}

TSavingsAccount::~TSavingsAccount() {
	// TODO Auto-generated destructor stub
}
