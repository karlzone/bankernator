/*
 * TMoney.cpp
 *
 *  Created on: 18 Oct 2012
 *      Author: karsten
 */
//#define DEBUG

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
ostream &operator<< (ostream &ostr, const TMoney &a){
	ios::fmtflags oldCout;
	ios::fmtflags newCout = (ios::dec | ios::fixed);	//decimal and fixed
	oldCout = ostr.flags();
	ostr.flags(newCout);

	ostr.precision(2);
	ostr << fixed << a.amount << " "<< a.currency;

	ostr.flags(oldCout);
	return ostr;
}

istream &operator>> (istream &istr, TMoney &a)
{
#ifdef DEBUG
	cout << "TMoney: operator>>" << endl;
#endif
	char str[100];
	string s;
	unsigned size;
	while (istr.getline(str, 100)) {
			s = str;
			size = s.size();
			//cheak Amount tag

			if(s.find("<Amount>") <= size){
#ifdef DEBUG
	cout << "TMoney: <Amount>tag find" << endl;
#endif
				a.amount = atof(insideString(s,"<Amount>","</Amount>").c_str());;
#ifdef DEBUG
	cout << "TMoney: a.amount = "<< a.amount <<";" << endl;
#endif
			}//cheak Currency tag
			else if(s.find("<Currency>") <= size){
#ifdef DEBUG
	cout << "TMoney: <Currency>tag find" << endl;
#endif
				a.currency = insideString(s,"<Currency>","</Currency");
#ifdef DEBUG
	cout << "TMoney: a.currency = "<< a.currency <<";" << endl;
#endif
			}//cheak endtag </Money>
			else if(s.find("</Money>") <= size){
#ifdef DEBUG
	cout << "TMoney: </Money>tag find" << endl;
#endif
				return istr;
				break;
			}
		}
		return istr;
	}
}

