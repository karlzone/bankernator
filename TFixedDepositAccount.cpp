/*
 * TFixedDepositAccount.cpp
 *
 *  Created on: 03.12.2012
 *      Author: Runge
 */

#include "TFixedDepositAccount.h"

namespace std {

TFixedDepositAccount::~TFixedDepositAccount() {
	cout << "TFixedDepositAccount:  " << this->accountNr << "  deleted" << endl;
}

TFixedDepositAccount::TFixedDepositAccount(TCustomer *customerPtr, TBank *bankPtr, string accountNr,
		string pin, TMoney Disposit, double interestRate): TAccount(customerPtr,bankPtr,accountNr,pin), TCurrentAccount(customerPtr,bankPtr,accountNr,pin,Disposit),
				TSavingsAccount(customerPtr,bankPtr,accountNr,pin, interestRate){

}

int TFixedDepositAccount::getAtyp() {
	return 3; // 3 = TFixedDepositAccount
}

void TFixedDepositAccount::printAccountStatement() {
	TAccount::printAccountStatement();
	cout << "max. Dispo: ";
	this->Disposit->print();
	cout << endl << "Interest rate: ";
	cout.precision(2);
	cout << fixed << *(this->interestRate) <<  " %" << endl;
}

} /* namespace std */
