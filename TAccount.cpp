/*
 * TAccount.cpp
 *
 *  Created on: 28 Oct 2012
 *      Author: karsten
 */

#include "TAccount.h"


using namespace std;

TAccount::~TAccount() {
	// TODO Auto-generated destructor stub
}

TAccount::TAccount(TCustomer *customerPtr, TBank *bankPtr, string accountNr,
		string pin) {
 	customerPtr->addAccount(this);
	bankPtr->addAccount(this);
	this->bankPtr = bankPtr;
	this->customerPtr = customerPtr;
	this->accountNr = accountNr;
	this->pin = pin;
	cout << "Adresse RR (K TAccount): " << this->customerPtr << endl;

	//TODO the amount of bookings
	this->sumOfBookings = 0;
<<<<<<< HEAD
	this->balance = 0;//Startguthaben
=======
	this->balance = 0;
>>>>>>> e3c5012c156f29f751cc3ed2619bd4c0720a3393
}

void TAccount::setBalance(TMoney balance) {
	this->balance = balance;
}

void TAccount::addBooking(TBooking *bookingPtr){
	cout << "Adr. addbooking Nr. " << sumOfBookings << " Adr. " << (bookingPtr->sourcePtr)->getCustomerPtr() << endl;
	this->bookingList[sumOfBookings++] = bookingPtr;
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

int TAccount::getSumOfBookings() {
	return sumOfBookings;
}

/* TODO
 void TAccount::setSumOfBookings(int sumOfBookings) {
 this->sumOfBookings = sumOfBookings;
 }*/

void TAccount::print() {
	customerPtr->print();
	cout << "Account number:  " << accountNr << endl;
	cout << "Bookings:        " << sumOfBookings << endl;
<<<<<<< HEAD
	cout << "Balance:         "; balance.print(); cout  << endl;
=======
	cout << "Balance:         " ;
	printBalance();
	cout << endl;
>>>>>>> e3c5012c156f29f751cc3ed2619bd4c0720a3393
}

TMoney TAccount::getBalance() {
	return balance;
}

void TAccount::printAccountStatement() {
	//TODO Account statement print with status printed=false

	if(!bookingList[sumOfBookings-1]->isPrinted()){
		int w = 20;

		char oldFill = cout.fill();
		cout.fill(' ');
		//Kopfzeile

		cout << "Kontoauszug vom "; TDate().print(); cout << endl;
		cout << "Kontonr.: " << this->accountNr <<"; BLZ " << this->bankPtr->getBlz() << endl;
		cout << "Kontoinhaber: " << (this->customerPtr)->getName() << endl;

		cout.width(w); cout << "Datum" << '|';
		cout.width(w); cout << "Betrag" << '|';
		cout.width(w); cout << "Absender /Empfaenger" << '|';
		cout.width(w); cout << "Buchungstext" << endl ;

		printHeadLine(w);

		for (int i = 0; i < sumOfBookings; i++) {
			if (!bookingList[i]->isPrinted()) {
				bookingList[i]->printBooking(this, w);
			}

			cout.fill(oldFill);
		}
		printHeadLine(w);
	}else{
		cout << "already printed" << endl;

	}
	cout << "aktueller Kontostand: "; this->balance.print(); cout << endl;

}
unsigned TAccount::getBLZ(){
	return this->bankPtr->getBlz();
}

<<<<<<< HEAD
bool TAccount::equal_to(TAccount *accPtr){
	if( ( (bankPtr->getBlz()) == (accPtr->getBLZ()) ) && ( (accountNr == accPtr->getAccountNr() )) )return true;
=======
void TAccount::printBalance() {
	cout << balance.getAmount() << " " << balance.getCurrency();
}

bool TAccount::equal_to(TAccount *accPTr){
	if( ( this->bankPtr->getBlz() == accPTr->getBLZ() ) && ( this->accountNr == accPTr->getAccountNr() ) )return true;
>>>>>>> e3c5012c156f29f751cc3ed2619bd4c0720a3393
	return false;
}

