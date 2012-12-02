/*
 * TSavingsAccount.cpp
 *
 *  Created on: 02.12.2012
 *      Author: Runge
 */

#include "TSavingsAccount.h"

namespace std {

TSavingsAccount::TSavingsAccount(TCustomer *customerPtr, TBank *bankPtr, string accountNr,
		string pin, double * dPtr):TAccount(customerPtr,bankPtr,accountNr,pin) {
	this->dPtr = dPtr;
	this->Atyp = 2;
}

double* TSavingsAccount::getPtr() {
	return dPtr;
}

void TSavingsAccount::setPtr(double* ptr) {
	dPtr = ptr;
}

TSavingsAccount::~TSavingsAccount() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
