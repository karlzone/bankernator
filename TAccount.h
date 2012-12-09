/*
 * TAccount.h
 *
 *  Created on: 28 Oct 2012
 *      Author: karsten
 */

#ifndef TACCOUNT_H_
#define TACCOUNT_H_

#include <iostream>
#include <string>

#include "TBank.h"
#include "bankernatorFktSum.h"
#include "TCustomer.h"
#include "TMoney.h"
#include "TBooking.h"

namespace std {

#define MAXBOOKINGS 1000

class TBank;
class TCustomer;
class TMoney;
class TBooking;

class TAccount {
protected:

	TBank *bankPtr;
	TCustomer *customerPtr;

	string accountNr;
	string pin;

	int bookingCounter;

	TMoney balance;
	TMoney* dispo;

	int Atyp;
	TBooking *bookingList[MAXBOOKINGS];

public:
	//TAccount();
	TAccount(TCustomer*, TBank*, string, string);
	virtual ~TAccount();

	string getAccountNr();
	//void setAccountNr(string accountNr);

	TCustomer* getCustomerPtr();
	//void setCustomerPtr(TCustomer* customerPtr);

	string getPin();
	void setPin(string pin);

	int getBookingCounter();
	void setSumOfBookings(int sumOfBookings);

	void print();

	void printAccountStatement();
	TMoney getBalance();
	void addBooking(TBooking*);
	void setBalance(TMoney balance);

	unsigned getBLZ();
	void printBalance();
	virtual TMoney* getDispo();
	int getAtyp() const;
};
}
#endif /* TACCOUNT_H_ */
