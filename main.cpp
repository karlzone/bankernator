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

using namespace std;


int main()
{
char ch[1];
TDate Datum(7, 7, 1977);
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


cout << "Bank1: " << endl; Bank1.print();
cout << endl << endl << endl;
cout << "...press return key to close the program..." << endl;
//hallo blabla

cin.get(ch[1]);

return 0;
}

