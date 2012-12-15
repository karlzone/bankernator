/*
 * TSavingsAccount.cpp
 *
 *  Created on: 02.12.2012
 *      Author: Runge
 */

#include "TSavingsAccount.h"

namespace std {

TSavingsAccount::~TSavingsAccount() {
	cout << "TSavingsAccount:       " << this->accountNr << "  deleted" << endl;
}

TSavingsAccount::TSavingsAccount(TCustomer *customerPtr, TBank *bankPtr, string accountNr,
		string pin, double interestRate):TAccount(customerPtr,bankPtr,accountNr,pin) {
	this->interestRate = new double(1.5);
}

double* TSavingsAccount::getInterestRate() {
	return interestRate;
}

void TSavingsAccount::setInterestRatePtr(double* interestRate) {
	this->interestRate = interestRate;
}

int TSavingsAccount::getAtyp() {
	return 2; // 2 = TSavingsAccount
}

void TSavingsAccount::printAccountStatement() {
	TAccount::printAccountStatement();
	cout << "Interest rate: ";
	cout.precision(2);
	cout << fixed << *(this->interestRate) <<  " %" << endl;
}

} /* namespace std */
