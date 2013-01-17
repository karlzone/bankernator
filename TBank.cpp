///////////////////////////////////////////////////////////
//  TBank.cpp
//  Implementation of the Class TBank
//  Created on:      01-Nov-2012 18:19:11
//  Original author: Runge
///////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>

#include "TBank.h"
#include "bankernatorFktSum.h"
#include "TListe.h"

//#define DEBUG

namespace std {

TBank::~TBank() {
	cout << endl << "All Accounts of Bank: '" << this->name << "' will be deleted" << endl;
	TListe<TAccount*>::Iterator temp = accountList.begin();
	for (; temp != this->accountList.end();temp++) {
			delete *temp;
	}
}

TBank::TBank(string name, unsigned BLZ) {
	this->name = name;
	this->BLZ = BLZ;
	accountCounter = 0;

}

void TBank::addAccount(TAccount *accountPtr) {
#ifdef DEBUG
	cout << "TBank:addAccount:accountPtr: " << accountPtr->getCustomerPtr()->getName() << endl;
	cout << "TBank:addAccount:accountPtr: " << accountPtr->getCustomerPtr() << endl;
#endif

	this->accountList.push_back(accountPtr);

#ifdef DEBUG
	cout << "TBank:addAccount:accountPtr: accountList[" << accountCounter << "]" << accountList[accountCounter]->getCustomerPtr()->getName() << endl;
	cout << "TBank:addAccount:accountPtr: accountList[" << accountCounter << "]" << accountList[accountCounter]->getCustomerPtr() << endl;
	cout << endl;
#endif
	accountCounter++;
}

TAccount* TBank::getAccount(int i) {
	return this->accountList[i];
}


TAccount* TBank::getAccountByNr(string AccNr) {
	for (int i = 0; i < accountCounter; i++) {
		if (accountList[i]->getAccountNr() == AccNr) {
			return this->accountList[i];
		}
	}
	cout << "Account not found.." << endl;
	return NULL;
}

/*ostream &operator<<(ostream &ostr, const TBank &a) {
	//a.print();
	return ostr;
}*/

unsigned TBank::getBlz() {
	return BLZ;
}

void TBank::setBlz(unsigned blz) {
	BLZ = blz;
}

string TBank::getName() {
	return name;
}

int TBank::getAccountCounter() {
	return accountList.size();
}

void TBank::setName(string name) {
	this->name = name;
}

void TBank::print() {

	int w = 20;								//Spaltenbreite in der Anzeige
	cout << name << endl;
	cout << BLZ << endl;
	cout << "Amount of accounts: " << accountCounter << endl;
	cout << "Account list" << endl;

	char oldFill = cout.fill();
	cout.fill(' ');
	//Kopfzeile
	cout.width(w);
	cout << "Accountnr." << '|';
	cout.width(w);
	cout << "Customer name" << '|';
	cout.width(w);
	cout << "Amount of bookings" << '|';
	cout.width(w);
	cout << "Balance" << endl;
	//Tabellenkörper
	for (int i = 0; i < accountCounter; i++) {
		cout.width(w);
		cout << accountList[i]->getAccountNr() << '|';
		cout.width(w);
#ifdef DEBUG
		cout << "Adr. RR: " << accountList[i]->getCustomerPtr() << "|" << flush;
#else
		cout << (accountList[i]->getCustomerPtr())->getName() << '|';
#endif
		cout.width(w);
		cout << accountList[i]->getBookingCounter() << '|';
		cout.width(w);
		accountList[i]->getBalance().print();
		cout << endl;
	}
	cout.fill(oldFill);
}


void TBank::compare() {

}

ostream& operator<<(ostream &ostr, TBank* bank) {
	int w = 20;								//Spaltenbreite in der Anzeige
		ostr << bank->name << endl;
		ostr << bank->BLZ << endl;
		ostr << "Amount of accounts: " << bank->accountCounter << endl;
		ostr << "Account list" << endl;

		char oldFill = ostr.fill();
		ostr.fill(' ');
		//Kopfzeile
		ostr.width(w);
		ostr << "Accountnr." << '|';

		ostr.width(w);
		ostr << "Customer name" << '|';
		ostr.width(w);
		ostr << "Amount of bookings" << '|';
		ostr.width(w);
		ostr << "Balance" << endl;
		//Tabellenkörper
		for (int i = 0; i < bank->accountCounter; i++) {
			ostr.width(w);
			ostr << bank->accountList[i]->getAccountNr() << '|';
			ostr.width(w);
	#ifdef DEBUG
			ostr << "Adr. RR: " << accountList[i]->getCustomerPtr() << "|" << flush;
	#else
			ostr << (bank->accountList[i]->getCustomerPtr())->getName() << '|';
	#endif
			ostr.width(w);
			ostr << bank->accountList[i]->getBookingCounter() << '|';
			ostr.width(w);
			bank->accountList[i]->getBalance().print();
			ostr << endl;
		}
		ostr.fill(oldFill);
	return ostr;
}

} /* namespace std */
