/*
 * main.cpp
 *
 *  Created on: 6 Oct 2012
 *      Author: karsten weber
 */

//#define DEBUG

#include <iostream>
//#include <stdio.h>

using namespace std;

#include "bankernatorFktSum.h"
#include "TDate.h"
#include "TMoney.h"
#include "TCustomer.h"
#include "TAccount.h"
#include "TBooking.h"
#include "TCurrentAccount.h"
#include "TSavingsAccount.h"
#include "TFixedDepositAccount.h"
#include "TTransaction.h"
#include "TTransactionList.h"

//#define DEBUG

TBank* getBank(TBank*, TBank*, unsigned);

int main() {
	//char ch[1];

	char *Dateiname = (char *) "transactions.list";
	TDate Datum1(7, 7, 1977);
	TDate Datum2(8, 8, 1988);
	TDate Datum3(6, 6, 1966);
	TCustomer Bundesdruckerei("Geldquelle", TDate(), "", "", "", "");
	TCustomer Kunde1("Egon Muster", Datum1, "Mustergasse", "3a", "99889",
			"Musterstadt");
	TCustomer Kunde2("Rudolph Rednose", Datum2, "Berliner Str.", "17", "10999",
			"Berlin");
	TCustomer Kunde3("Karin Kunze", Datum3, "Muenchner Str.", "39", "90123",
			"Muenchen");
	TBank *Bank = NULL;
	TBank *Bank1 = new TBank("Berliner Bank", 10020000);
	TBank *Bank2 = new TBank("Muenchner Bank", 10090099);
	TAccount *Geldquelle = new TAccount(&Bundesdruckerei, Bank1, "0", "0000");
	Geldquelle->getAtyp();
	TAccount *Konto1 = new TCurrentAccount(&Kunde1, Bank1, "1234567890", "9999",
			TMoney(100.0));
	Konto1->getAtyp();
	TAccount *Konto2 = new TSavingsAccount(&Kunde2, Bank1, "9876543120", "0101",
			1.5);
	Konto2->getAtyp();
	TAccount *Konto3 = new TFixedDepositAccount(&Kunde1, Bank2, "111333555",
			"1357", TMoney(100.0), 1.5);
	Konto3->getAtyp();
	TAccount *Konto4 = new TCurrentAccount(&Kunde3, Bank2, "999777555", "4444",
			TMoney(200.0));
	Konto4->getAtyp();
	TTransactionList TL(Dateiname);
	for (unsigned i = 0; i < TL.getTransactionCounter(); i++) {
#ifdef DEBUG
		cout << "main: durch die TransactionList" << endl;
#endif
		TAccount *Konto = NULL, *Gegenkonto = NULL;
		Konto = NULL;
		Bank = getBank(Bank1, Bank2, TL[i].getBLZ());
#ifdef DEBUG
		cout << "main: getBank(Bank1: "<<Bank1->getBlz()<<", Bank2: "<<Bank2->getBlz()<<
				", TL["<<i<<"].getBLZ(): "<<TL[i].getBLZ() <<" returns "<<Bank->getBlz()<< endl;
#endif
		if (Bank){
#ifdef DEBUG
		cout << "main: next Bank->getAccountByNr("<<TL[i].getAccountNr()<<")" << endl;
#endif
			Konto = Bank->getAccountByNr(TL[i].getAccountNr());
		}
#ifdef DEBUG
		cout << "main: 2" << endl;
#endif
		Gegenkonto = NULL;
		Bank = getBank(Bank1, Bank2, TL[i].getContraBLZ()); //
#ifdef DEBUG
		cout << "main:TL["<<i<<"].getContraBLZ()" << endl;
#endif
		if (Bank)
			Gegenkonto = Bank1->getAccountByNr (TL[i].getContraAccountNr());
		if (Konto && Gegenkonto){
			TBooking *Buchung = new TBooking(TL[i].getAmount(), Konto,
					Gegenkonto, TL.getDate(), TL.getTime(), TL[i].getComment());
			Buchung->getTime();
		}
	}
	// Ausgaben:
	cout << "Transaktionsliste:" << endl << TL << endl;
	/*cout << "Kunde 1:" << endl << Kunde1 << endl;
	cout << "Kunde 2:" << endl << Kunde2 << endl;
	cout << "Kunde 3:" << endl << Kunde3 << endl;
	cout << "Bank 1: " << endl << *Bank1 << endl;
	cout << "Bank 2: " << endl << *Bank2 << endl;*/
	cout << "Kunde 1:" << endl; Kunde1.print();cout << endl;
	cout << "Kunde 2:" << endl; Kunde2.print();cout << endl;
	cout << "Kunde 3:" << endl; Kunde3.print();cout << endl;
	cout << "Bank 1: " << endl; Bank1->print();cout << endl;
	cout << "Bank 2: " << endl; Bank2->print();cout << endl;
	for (int i = 0; i < Bank1->getAccountCounter(); i++) {
		(Bank1->getAccount(i))->printAccountStatement();
		cout << endl;
	}
	for (int i = 0; i < Bank2->getAccountCounter(); i++) {
		(Bank2->getAccount(i))->printAccountStatement();
		cout << endl;
	}
	cout
			<< "Jetzt werden die Banken vernichtet und damit auch die Konten der Banken:"
			<< endl;
	delete Bank1;
	delete Bank2;

	cout << endl << endl << endl;
	cout << "...press return key to close the program..." << endl;

//cin.get(ch[1]);

	return 0;
}

TBank *getBank(TBank *B1, TBank *B2, unsigned BLZ) {
	if ((B1->getBlz()) == BLZ)
		return B1;
	if ((B2->getBlz()) == BLZ)
		return B2;
	return NULL;
}

