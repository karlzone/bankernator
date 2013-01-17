///////////////////////////////////////////////////////////
//  TBank.cpp
//  Implementation of the Class TBank
//  Created on:      01-Nov-2012 18:19:11
//  Original author: Runge
///////////////////////////////////////////////////////////

#include "TBank.h"
#include "bankernatorFktSum.h"

//#define DEBUG

namespace std {

TBank::~TBank() {
	cout << endl << "All Accounts of Bank: '" << this->name << "' will be deleted" << endl;
	for (int i = 0; i<this->accountCounter; i++) {
			delete accountList[i];
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
	//l.push_front(accountPtr);
	this->accountList[accountCounter] = accountPtr;

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
#ifdef DEBUG
	cout << "TBank: getAccountByNr("<<AccNr<<")" << endl;
#endif
	for (int i = 0; i <= accountCounter; i++) {
#ifdef DEBUG
		cout << "TBank: getAccountByNr("<<AccNr<<"): for ("<<i<<"<="<<accountCounter<<")" << endl;
#endif
		if (accountList[i]->getAccountNr() == AccNr) {
#ifdef DEBUG
	cout << "TBank: getAccountByNr("<<AccNr<<") Acc found" << endl;
#endif
			return this->accountList[i];
		}
	}
	cout << "Account not found.." << endl;
	return NULL;
}

ostream &operator<<(ostream &ostr, const TBank &a) {
	TBank tmp = a;
	tmp.print();
	return ostr;
}

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
	return accountCounter;
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
} /* namespace std */
