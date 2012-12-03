/*
 * TFixedDepositAccount.cpp
 *
 *  Created on: 03.12.2012
 *      Author: Runge
 */

#include "TFixedDepositAccount.h"

namespace std {

TFixedDepositAccount::TFixedDepositAccount(TCustomer *customerPtr, TBank *bankPtr, string accountNr,
		string pin, TMoney*dispo, double *dPtr): TAccount(customerPtr,bankPtr,accountNr,pin), TCurrentAccount(customerPtr,bankPtr,accountNr,pin,dispo),
				TSavingsAccount(customerPtr,bankPtr,accountNr,pin,dPtr){
	this->Atyp = 3;
}

TFixedDepositAccount::~TFixedDepositAccount() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
