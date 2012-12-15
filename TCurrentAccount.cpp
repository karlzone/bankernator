/*
 * TCurrentAccount.cpp
 *
 *  Created on: 02.12.2012
 *      Author: Runge
 */

#include "TCurrentAccount.h"

namespace std {

TCurrentAccount::~TCurrentAccount() {
	cout << "TCurrentAccount Konto: " << this->accountNr << "wird vernichtet!" << endl;
}

TCurrentAccount::TCurrentAccount(TCustomer *customerPtr, TBank *bankPtr,
		string accountNr, string pin, TMoney dispo) : TAccount (customerPtr, bankPtr, accountNr, pin) {

	this->Disposit = dispo;

}

TMoney TCurrentAccount::getDisposit() {
	return this->Disposit;
}

void TCurrentAccount::printAccountStatement() {
	TAccount::printAccountStatement();
	cout << "max. Dispo" << Disposit.getAmount() << endl;
}
int TCurrentAccount::getAtyp() {
	return 1; //1 = TCurrentAccount
}

} /* namespace std */
