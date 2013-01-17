/*
 * TCustomer.cpp
 *
 *  Created on: 28 Oct 2012
 *      Author: karsten
 */

#include <iostream>
#include <string>

#include "TAccount.h"
#include "TCustomer.h"

//#define DEBUG

namespace std {

TCustomer::TCustomer(string name, TDate birthday, string street,
		string streetnr, string postcode, string city) {
	this->name = name;
	this->street = street;
	this->streetnr = streetnr;
	this->postcode = postcode;
	this->city = city;
	this->birthday = birthday;
	this->accountCounter = 0;
//	accountPtr[0] = getAccountPtr();
}

TCustomer::~TCustomer() {
	// TODO Auto-generated destructor stub
}

ostream &operator<<(ostream &ostr, const TCustomer &a) {
	//return a.print(ostr);
	return ostr;
}

TDate TCustomer::getBirthday() {
	return birthday;
}

void TCustomer::setBirthday(const TDate birthday) {
	this->birthday = birthday;
}

string TCustomer::getCity() {
	return city;
}

void TCustomer::setCity(string city) {
	this->city = city;
}

string TCustomer::getName() {
	return name;
}

void TCustomer::setName(string name) {
	this->name = name;
}

string TCustomer::getPostcode() {
	return postcode;
}

void TCustomer::setPostcode(string postcode) {
	this->postcode = postcode;
}

string TCustomer::getStreet() {
	return street;
}

void TCustomer::setStreet(string street) {
	this->street = street;
}

string TCustomer::getStreetnr() {
	return streetnr;
}

void TCustomer::setStreetnr(string streetnr) {
	this->streetnr = streetnr;
}
/*
 TAccount* TCustomer::getAccountPtr() {
 return accountList[accountCounter];
 }*/
/*
 void TCustomer::setAccountPtr(TAccount* accountPtr) {
 this->accountPtr[0] = accountPtr;
 }*/

int TCustomer::getAccountCounter() {
	return accountCounter;
}
/*
 void TCustomer::setSumOfTAccounts(int sumOfTAccounts) {
 this->sumOfTAccounts = sumOfTAccounts;
 }*/


void TCustomer::addAccount(TAccount* accountPtr) {
#ifdef DEBUG
	cout << "TCustomer:addAccount:accountList: " << accountPtr->getCustomerPtr()->getName() << endl;
	cout << "TCustomer:addAccount:accountList: " << accountPtr->getCustomerPtr() << endl;
#endif

	this->accountList[accountCounter] = accountPtr;

#ifdef DEBUG
	cout << "TCustomer:addAccount:accountList: accountList[" << accountCounter << "]" << accountList[accountCounter]->getCustomerPtr()->getName() << endl;
	cout << "TCustomer:addAccount:accountList: accountList[" << accountCounter << "]" << accountList[accountCounter]->getCustomerPtr() << endl;
#endif
	accountCounter++;

}
void TCustomer::print() {

	cout << name << endl;
	cout << street << endl;
	cout << postcode << " " << city << endl;
	cout << "born on: ";
	birthday.print();
	cout << endl;
	cout << "Accounts:" << endl;
	for (int i = 0; i < accountCounter; i++) {
		cout << "-  Account number:   ";
		//cout << i << endl;
		cout << accountList[i]->getAccountNr() << "  (Balance:    ";
		accountList[i]->printBalance();
		cout << ")" << endl;
		//accountPtr[i] ->printAccountNr();
	}

}
ostream& TCustomer::print(ostream &ostr){

	ostr << name << endl;
	ostr << street << endl;
	ostr << postcode << " " << city << endl;
	ostr << "born on: ";
	birthday.print();
		ostr << endl;
		ostr << "Accounts:" << endl;
		for (int i = 0; i < accountCounter; i++) {
			ostr << "-  Account number:   ";
			ostr << accountList[i]->getAccountNr() << "  (Balance:    ";
			accountList[i]->printBalance();
			ostr << ")" << endl;
		}
	return ostr;
}
}
