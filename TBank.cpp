///////////////////////////////////////////////////////////
//  TBank.cpp
//  Implementation of the Class TBank
//  Created on:      01-Nov-2012 18:19:11
//  Original author: Runge
///////////////////////////////////////////////////////////

#include "TBank.h"


TBank::TBank(string name, unsigned BLZ){
	this->name = name;
	this->BLZ = BLZ;
	accountCounter = 0;
}

void TBank::addAccount(TAccount* account){
	accountList[accountCounter++] = account;
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

void TBank::print(){
	cout << name << endl;
	cout << BLZ << endl;
	cout << "Anzahl Konten: " << accountCounter << endl;
	cout << "Kontenliste:" << endl;
	cout << "Kontonr. | Kundenname | Anz. Buchungen | Kontostand" << endl;
	for (int i = 0; i < accountCounter; i++) {
		cout << accountList[i]->getAccountNr() << '|';
		cout << accountList[i]->getCustomerPtr()->getName() << '|';
		cout << accountList[i]->getSumOfBookings() << '|';
		cout << "Kontostand";
		cout << endl;
	}

}
TBank::~TBank(){

}
