/*
 * main.cpp
 *
 *  Created on: 6 Oct 2012
 *      Author: karsten weber
 */

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

//#define DEBUG



int main() {
	char ch[1];

	/* Aufgabe 3
	TDate Datum1(7, 7, 1977);
	TDate Datum2(8, 8, 1988);
	TCustomer Bundesdruckerei("Geldquelle", TDate(), "", "", "", "");
	TCustomer Kunde1("Egon Muster", Datum1, "Mustergasse", "3a", "99889",
			"Musterstadt");
	TCustomer Kunde2("Rudolph Rednose", Datum2, "Berliner Str.", "17", "10999",
			"Berlin");
#ifdef DEBUG
	cout << "Adressen der KundenPtr" << endl;
	cout << Bundesdruckerei.getName() << ": " <<endl;
	cout << "Adresse RR: " << &Bundesdruckerei << endl;
	cout << Kunde1.getName() << ": "<<endl;
	cout << "Adresse RR: " << &Kunde1 << endl;
	cout << Kunde2.getName() << ": " <<endl;
	cout << "Adresse RR: " << &Kunde2 << endl;
	cout << endl;
#endif

	TBank Bank1("Berliner Bank", 10020000);
#ifdef DEBUG
	cout << "Erstellen der Konten:" << endl;
	cout << "Geldquelle:"<<endl;
#endif
	TAccount Geldquelle(&Bundesdruckerei, &Bank1, "0", "0000");
#ifdef DEBUG
	cout << endl;
	cout << "Konto1:"<<endl;
#endif
	TAccount Konto1(&Kunde1, &Bank1, "1234567890", "9999");
#ifdef DEBUG
	cout << endl;
	cout << "Konto2:"<<endl;
#endif
	TAccount Konto2(&Kunde2, &Bank1, "9876543120", "0101");
#ifdef DEBUG
	cout << endl;
	cout << "Konto3:"<<endl;
#endif
	TAccount Konto3(&Kunde1, &Bank1, "111333555", "1357");

#ifdef DEBUG
	cout << "Erstellen der Buchungen" << endl;
	cout << "Geldquelle->Konto1" << endl;
#endif
	TBooking Buchung1(TMoney(150.0), &Geldquelle, &Konto1, TDate(), TTime(),
			string("Startguthaben"));
#ifdef DEBUG
	cout << endl;
	cout << "Bank 1: " << endl;
	Bank1.print();
	cout << endl;
	cout << endl;
	Konto1.printAccountStatement();
	cout << endl;

	cout << "Konto1->Konto3"<<endl;
#endif
	TBooking Buchung2(TMoney(50.0), &Konto1, &Konto3, TDate(), TTime(),
			string("Umbuchung"));
#ifdef DEBUG
	cout << endl;
	cout << "Bank 1: " << endl;
	Bank1.print();
	cout << endl;
	cout << endl;
	Konto1.printAccountStatement();
	cout << endl;
	cout << "Konto1->Konto2"<<endl;
#endif
	TBooking Buchung3(TMoney(39.9), &Konto1, &Konto2, TDate(), TTime(),
			string("Rechnung 4711"));
#ifdef DEBUG
	cout << endl;
	cout << "Bank 1: " << endl;
	Bank1.print();
	cout << endl;
	cout << endl;
	Konto1.printAccountStatement();
	cout << endl;
	cout << "Ausgabe Hauptprogramm"<<endl;
#endif
// Ausgaben:
	cout << "Kunde 1:" << endl;
	Kunde1.print();
	cout << endl;
	cout << "Kunde 2:" << endl;
	Kunde2.print();
	cout << endl;
	cout << "Bank 1: " << endl;
	Bank1.print();
	cout << endl;
	cout << endl;
	Konto1.printAccountStatement();
	cout << endl;
	Konto1.printAccountStatement(); // darf die Buchungen nicht noch einmal ausdrucken!*/

	TDate Datum1(7, 7, 1977);
	TDate Datum2(8, 8, 1988);
	TCustomer Bundesdruckerei("Geldquelle", TDate(),"", "", "", "");
	TCustomer Kunde1("Egon Muster", Datum1, "Mustergasse", "3a", "99889", "Musterstadt");
	TCustomer Kunde2("Rudolph Rednose", Datum2, "Berliner Str.", "17", "10999", "Berlin");
	TBank *Bank1 = new TBank("Berliner Bank", 10020000);
	TAccount *Geldquelle = new TAccount(&Bundesdruckerei, Bank1, "0", "0000");
	TCurrentAccount *Konto1 = new TCurrentAccount(&Kunde1, Bank1, "1234567890", "9999", TMoney(100.0));
	TSavingsAccount *Konto2 = new TSavingsAccount(&Kunde2, Bank1, "9876543120", "0101", 1.5);
	TFixedDepositAccount *Konto3 = new TFixedDepositAccount(&Kunde1, Bank1, "111333555", "1357", TMoney(100.0), 1.5);
	TBooking Buchung1(TMoney(150.0), Konto1, Geldquelle, TDate(), TTime(), string("Startguthaben"));
	TBooking Buchung2(TMoney(50.0), Konto3, Konto1, TDate(), TTime(), string("Umbuchung"));
	TBooking Buchung3(TMoney(39.9), Konto2, Konto1, TDate(), TTime(), string("Rechnung 4711"));
	// Ausgaben:
	cout << "Kunde 1:" << endl; Kunde1.print();  cout << endl;
	cout << "Kunde 2:" << endl; Kunde2.print();  cout << endl;
	cout << "Bank 1: " << endl; Bank1->print();  cout << endl;

	for (int i = 0; i < Bank1->getAccountCounter(); i++)
	{
	(*Bank1->getAccount(i)).printAccountStatement();
	cout << endl;
	}
#ifdef DEBUG
	Bank1->getAccount(0)->printAccountStatement();
	(*Bank1->getAccount(0)).printAccountStatement();
#endif
	cout << "Jetzt wird die Bank vernichtet und damit auch die Konten der Bank:" << endl;
	delete Bank1;



	cout << endl << endl << endl;
	cout << "...press return key to close the program..." << endl;

	//cin.get(ch[1]);

	return 0;
}

