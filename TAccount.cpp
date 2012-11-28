/*
 * TAccount.cpp
 *
 *  Created on: 28 Oct 2012
 *      Author: karsten
 */

#include "TAccount.h"

//#define DEBUG

namespace std {

TAccount::~TAccount() {
	// TODO Auto-generated destructor stub
}

TAccount::TAccount(TCustomer *customerPtr, TBank *bankPtr, string accountNr,
		string pin) {
	this->bankPtr = bankPtr;
	this->customerPtr = customerPtr;
	this->accountNr = accountNr;
	this->pin = pin;
#ifdef DEBUG
	cout << "Adresse RR (" << this->customerPtr->getName() << " TAccount): " << this->customerPtr << endl;
#endif
	customerPtr->addAccount(this);
	bankPtr->addAccount(this);

	//TODO the amount of bookings
	this->bookingCounter = 0;
	this->balance = 0;
}

void TAccount::setBalance(TMoney balance) {
	this->balance = balance;
}

void TAccount::addBooking(TBooking *bookingPtr) {

#ifdef DEBUG
	cout << "TAccount:addBooking:Accountinhaber:" << this->getCustomerPtr()->getName() << endl;
	cout << "TAccount:addBooking:Accountinhaber:" << this->getCustomerPtr() << endl;
	cout << "TAccount:addBooking:bookingPtr: " << bookingPtr->getSourcePtr()->getCustomerPtr()->getName() << endl;
	cout << "TAccount:addBooking:BookingPtr: " << bookingPtr->getSourcePtr()->getCustomerPtr() << endl;
#endif

	this->bookingList[bookingCounter] = bookingPtr;

#ifdef DEBUG
	cout << "TAccount:addBooking:bookingPtr: bookingList[" << bookingCounter << "]" << bookingList[bookingCounter]->getSourcePtr()->getCustomerPtr()->getName() << endl;
	cout << "TAccount:addBooking:BookingPtr: bookingList[" << bookingCounter << "]" << bookingList[bookingCounter]->getSourcePtr()->getCustomerPtr() << endl;
#endif
	bookingCounter++;
}

string TAccount::getAccountNr() {
	return accountNr;
}
/*
 void TAccount::setAccountNr(string accountNr) {
 this->accountNr = accountNr;
 }*/

TCustomer* TAccount::getCustomerPtr() {
	return customerPtr;
}
/*
 void TAccount::setCustomerPtr(TCustomer* customerPtr) {
 this->customerPtr = customerPtr;
 }*/

string TAccount::getPin() {
	return pin;
}

void TAccount::setPin(string pin) {
	this->pin = pin;
}

int TAccount::getBookingCounter() {
	return bookingCounter;
}

/* TODO
 void TAccount::setSumOfBookings(int sumOfBookings) {
 this->sumOfBookings = sumOfBookings;
 }*/

void TAccount::print() {
	customerPtr->print();
	cout << "Account number:  " << accountNr << endl;
	cout << "Bookings:        " << bookingCounter << endl;
	cout << "Balance:         ";
	printBalance();
	cout << endl;
}

TMoney TAccount::getBalance() {
	return balance;
}

void TAccount::printAccountStatement() {
	//TODO Account statement print with status printed=false
	if (bookingCounter == 0)
		return;
	if (!bookingList[bookingCounter - 1]->isPrinted()) {
		int w = 20;

		char oldFill = cout.fill();
		cout.fill(' ');
		//Kopfzeile

		cout << "Kontoauszug vom ";
		TDate().print();
		cout << endl;
		cout << "Kontonr.: " << this->accountNr << "; BLZ "
				<< this->bankPtr->getBlz() << endl;
		cout << "Kontoinhaber: " << (this->customerPtr)->getName() << endl;
#ifdef DEBUG
		cout << "Kontoinhaber: " << (this->customerPtr) << endl;
#endif
		cout.width(w);
		cout << "Datum" << '|';
		cout.width(w);
		cout << "Betrag" << '|';
		cout.width(w);
		cout << "Absender /Empfaenger" << '|';
		cout.width(w);
		cout << "Buchungstext" << endl;

		printHeadLine(w);
		for (int i = 0; i < bookingCounter; i++) {
			if (!bookingList[i]->isPrinted()) {
				bookingList[i]->printBooking(w);
			}

			cout.fill(oldFill);
		}
		printHeadLine(w);
	} else {
		cout << "already printed" << endl;

	}
	cout << "aktueller Kontostand: ";
	this->balance.print();
	cout << endl;
}
unsigned TAccount::getBLZ() {
	return this->bankPtr->getBlz();
}

void TAccount::printBalance() {
	cout << balance.getAmount() << " " << balance.getCurrency();
}
}

