/*
 * main.cpp
 *
 *  Created on: 6 Oct 2012
 *      Author: karsten weber
 */

#include <iostream>
//#include <stdio.h>

#include "TDate.h"
#include "TMoney.h"
#include "TCustomer.h"
#include "TAccount.h"
#include "TBooking.h"

using namespace std;

int main() {
	char ch[1];
	/*TDate Datum(7, 7, 1977);
	 TMoney Betrag1(150.0);
	 TCustomer Kunde1("Egon Muster", Datum, "Mustergasse", "3a", "99889", "Musterstadt");
	 TBank Bank1("ErsteBank",80090100);

	 TAccount Konto1(&Bank1, &Kunde1, "1234567890", "9999");

	 cout << "Betrag 1: " << endl; Betrag1.print();cout << endl << endl;
	 cout << "Kunde 1: " << endl; Kunde1.print(); cout << endl << endl;
	 cout << "Konto 1; " << endl; Konto1.print(); cout << endl << endl;

	 TAccount Konto2(&Bank1, &Kunde1, "9876543210", "0101");

	 cout << "Kunde 1: " << endl; Kunde1.print(); cout << endl << endl;
	 cout << "Konto 2; " << endl; Konto2.print(); cout << endl << endl;


	 cout << "Bank1: " << endl; Bank1.print();*/

//hallo blabla
	TDate Datum1(7, 7, 1977);
	TDate Datum2(8, 8, 1988);
	TCustomer Bundesdruckerei("Geldquelle", TDate(), "", "", "", "");
	TCustomer Kunde1("Egon Muster", Datum1, "Mustergasse", "3a", "99889",
			"Musterstadt");
	TCustomer Kunde2("Rudolph Rednose", Datum2, "Berliner Str.", "17", "10999",
			"Berlin");
	cout << "Adresse RR: " << &Kunde2 << endl;

	TBank Bank1("Berliner Bank", 10020000);
	TAccount Geldquelle(&Bundesdruckerei, &Bank1, "0", "0000");
	TAccount Konto1(&Kunde1, &Bank1, "1234567890", "9999");
	TAccount Konto2(&Kunde2, &Bank1, "9876543120", "0101");
	TAccount Konto3(&Kunde1, &Bank1, "111333555", "1357");
	TBooking Buchung1(TMoney(150.0), &Konto1, &Geldquelle, TDate(), TTime(),
			string("Startguthaben"));
	TBooking Buchung2(TMoney(50.0), &Konto3, &Konto1, TDate(), TTime(),
			string("Umbuchung"));
	TBooking Buchung3(TMoney(39.9), &Konto2, &Konto1, TDate(), TTime(),
			string("Rechnung 4711"));

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
	Konto1.printAccountStatement(); // darf die Buchungen nicht noch einmal ausdrucken!

	cout << endl << endl << endl;
	cout << "...press return key to close the program..." << endl;

	cin.get(ch[1]);

	return 0;
}

