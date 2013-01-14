/*
 * TTransaction.cpp
 *
 *  Created on: 06.12.2012
 *      Author: Runge
 */

#include "TTransaction.h"

namespace std {

TTransaction::TTransaction() {
	accountNr = "0";
	BLZ = 0;
	contraAccountNr = "0";
	contraBLZ = 0;
	amount = 0;
	comment = "";
}

TTransaction::~TTransaction() {
	// TODO Auto-generated destructor stub
}

ostream &operator<<(ostream &ostr, const TTransaction &trans) {
	return ostr;
}
istream &operator>>(istream &istr, TTransaction &trans) {

	vector<string> v(0), te(0);
	TMoney money;

	v.push_back("</Transaction>");		//0
	v.push_back("<AccountNr>");			//1
	v.push_back("</AccountNr>");		//
	v.push_back("<BLZ>");				//3
	v.push_back("</BLZ>");				//
	v.push_back("<ContraAccountNr>");	//5
	v.push_back("</ContraAccountNr>");	//
	v.push_back("<ContraBLZ>");			//7
	v.push_back("</ContraBLZ>");		//
	v.push_back("<TMoney>");			//9
	v.push_back("<Text>");				//10
	v.push_back("</Text>");				//11


	char str[100];
	string s;
	while (istr.getline(str, 100)) {

		s = str;
		int i;
		for (i = 0; i < (int) v.size(); i++) {
			if (s.find(v[0]) <= s.size()) {
				break;
			} else if (s.find(v[i]) <= s.size()) {
				if(s.find(v[i+1])<=s.size())
				break;
			}

		}
		//substring filter
		switch (i) {
			case 1:
				trans.accountNr = insideString(s,v[i],v[i+1]);// s.substr(v[i].size(),s.find(v[i+1])-v[i].size());
				break;
			case 3:
				trans.BLZ = atoi(insideString(s,v[i],v[i+1]).c_str());//(s.substr(v[i].size(),s.find(v[i+1])-v[i].size())).c_str());
				break;
			case 5:
				trans.contraAccountNr = insideString(s,v[i],v[i+1]);//s.substr(v[i].size(),s.find(v[i+1])-v[i].size());
				break;
			case 7:
				trans.contraBLZ = atoi(insideString(s,v[i],v[i+1]).c_str());//(s.substr(v[i].size(),s.find(v[i+1])-v[i].size())).c_str());
				break;
			case 9:
				istr >> money;
				break;
			case 10:
				trans.comment = insideString(s,v[i],v[i+1]);
				break;
			default:
				break;
		}
	}
	return istr;
}


unsigned TTransaction::getBLZ() {
	return this->BLZ;
}

unsigned TTransaction::getContraBLZ() {
	return this->contraBLZ;
}


const TMoney& TTransaction::getAmount() const {
	return amount;
}

const string& TTransaction::getComment() const {
	return comment;
}

const string& TTransaction::getContraAccountNr() const {
	return contraAccountNr;
}

unsigned TTransaction::getContraBlz() const {
	return contraBLZ;
}

unsigned TTransaction::getBlz() {
	return this->BLZ;
}


string TTransaction::getAccountNr() {
	return this->accountNr;
}

string TTransaction::getContraAccountNr() {
	return this->contraAccountNr;
}
TMoney TTransaction::getAmount() {
	return this->amount;
}

string TTransaction::getText() {
	return this->comment;
}

} /* namespace std */

