/*
 * TAccount.h
 *
 *  Created on: 28 Oct 2012
 *      Author: karsten
 */

#ifndef TACCOUNT_H_
#define TACCOUNT_H_

#include <iostream>
#include <string.h>

#include "TBank.h"
#include "TCustomer.h"


using namespace std;

class TBank;
class TCustomer;

class TAccount {
private:

	TBank *bankPtr;
	TCustomer *customerPtr;

	string accountNr;
	string pin;

	int sumOfBookings;


public:
	TAccount(TBank*, TCustomer *, string, string);
	virtual ~TAccount();


	string getAccountNr();
	//void setAccountNr(string accountNr);

	TCustomer* getCustomerPtr();
	//void setCustomerPtr(TCustomer* customerPtr);

	string getPin();
	void setPin(string pin);

	int getSumOfBookings();
	void setSumOfBookings(int sumOfBookings);

	void print();

};

#endif /* TACCOUNT_H_ */
