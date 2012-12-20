/*
 * TCurrentAccount.cpp
 *
 *  Created on: 02.12.2012
 *      Author: Runge
 */

#include "TCurrentAccount.h"

namespace std {

TCurrentAccount::~TCurrentAccount() {
	cout << "TCurrentAccount:       " << this->accountNr << "  deleted" << endl;
}

TCurrentAccount::TCurrentAccount(TCustomer *customerPtr, TBank *bankPtr,
		string accountNr, string pin, TMoney dispo) : TAccount (customerPtr, bankPtr, accountNr, pin) {

	//FISME kopüierkonstruktor
	this->Disposit = new TMoney(dispo.getAmount());

}

TMoney* TCurrentAccount::getDisposit() {
	return this->Disposit;
}

void TCurrentAccount::printAccountStatement() {
	TAccount::printAccountStatement();
	cout << "max. Dispo: ";
	this->Disposit->print();
	cout << endl;
}

int TCurrentAccount::getAtyp() {
	return 1; //1 = TCurrentAccount
}

} /* namespace std */
