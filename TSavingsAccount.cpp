/*
 * TSavingsAccount.cpp
 *
 *  Created on: 02.12.2012
 *      Author: Runge
 */

#include "TSavingsAccount.h"

namespace std {

TSavingsAccount::~TSavingsAccount() {
	cout << "TAccount Konto: " << this->accountNr << "wird vernichtet!" << endl;
}

TSavingsAccount::TSavingsAccount(TCustomer *customerPtr, TBank *bankPtr, string accountNr,
		string pin, double * dPtr):TAccount(customerPtr,bankPtr,accountNr,pin) {
	this->dPtr = dPtr;
}

double* TSavingsAccount::getPtr() {
	return dPtr;
}

void TSavingsAccount::setPtr(double* ptr) {
	dPtr = ptr;
}

int TSavingsAccount::getAtyp() {
	return 2; // 2 = TSavingsAccount
}

} /* namespace std */
