/*
 * TMoney.cpp
 *
 *  Created on: 18 Oct 2012
 *      Author: karsten
 */

#include <iostream>
#include <ios>

#include "TMoney.h"

namespace std {

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

TMoney TMoney::operator+(TMoney &b) {
	return TMoney(this->amount + b.getAmount());
	//return TMoney(this.amount+b.amount);
}

TMoney TMoney::operator-(TMoney &b) {
	return TMoney(this->amount - b.getAmount());
}

bool TMoney::operator<(TMoney &b) {
	return (this->amount < b.getAmount());
}

void TMoney::print() {
	ios::fmtflags oldCout;
	ios::fmtflags newCout = (ios::dec | ios::fixed);	//decimal and fixed
	oldCout = cout.flags();
	cout.flags(newCout);

	cout.precision(2);
	cout << fixed << amount << " "<< currency;
	cout.flush();

	cout.flags(oldCout);
}
istream &operator>> (istream &istr, TMoney &a)
{

	double am = 0.0;
	char str[100];
		string s;
		while (istr.getline(str, 100)) {
			s = str;
			//cheak Amount tag
			if(s.find("<Amount>")){
				//read Amount
				//istr >> am;
				//set Amount
				a.setAmount(am);
			}//cheak Currency tag
			else if(s.find("<Currency>")){
				//read Currency
				//set Currency
			}//cheak endtag </Money>
			else if(s.find("</Money>")){
				break;
			}
		}
		return istr;
	}
}

