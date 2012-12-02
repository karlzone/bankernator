/*
 * TCurrentAccount.cpp
 *
 *  Created on: 02.12.2012
 *      Author: Runge
 */

#include "TCurrentAccount.h"

namespace std {

TCurrentAccount::TCurrentAccount(TCustomer *customerPtr, TBank *bankPtr, string accountNr,
		string pin, TMoney*dispo):TAccount(customerPtr,bankPtr,accountNr,pin) {
	this->dispo = dispo;
	this->Atyp = 1;

}

TMoney* TCurrentAccount::getDispo() {
	return this->dispo;
}

TCurrentAccount::~TCurrentAccount() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
