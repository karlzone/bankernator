/*
 * TMoney.cpp
 *
 *  Created on: 18 Oct 2012
 *      Author: karsten
 */

#include <iostream>
#include <ios>

#include "TMoney.h"

using namespace std;

TMoney::TMoney() {
	// TODO Auto-generated constructor stub
	this->amount = 0;
	this->currency = "EUR";
}

TMoney::~TMoney() {
	// TODO Auto-generated destructor stub
}

TMoney::TMoney(double x) {
	this->amount = x;
	this->currency = "EUR";
}

void TMoney::setAmount(double x) {
	this->amount = x;
}

double TMoney::getAmount() {
	return amount;
}

void TMoney::setCurrency(string cur) {
	this->currency = cur;
}

string TMoney::getCurrency() {
	return currency;
}

void TMoney::print() {
	ios::fmtflags oldCout;
	ios::fmtflags newCout = (ios::dec | ios::fixed);	//decimal and fixed
	oldCout = cout.flags();
	cout.flags(newCout);

	cout.precision(2);
	cout << fixed << amount << currency;
	cout.flush();

	cout.flags(oldCout);
}
