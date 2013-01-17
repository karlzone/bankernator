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
	ostr << "AccountNr = " << trans.accountNr << endl;
	ostr << "BLZ = " << trans.BLZ << endl;
	ostr << "ContraAccountNr = " << trans.contraAccountNr << endl;
	ostr << "ContraBLZ = " << trans.contraBLZ << endl;
	ostr << "Amount = " << trans.amount << endl;
	ostr << "Text = " << trans.comment << endl;
	return ostr;
}

istream &operator>>(istream &istr, TTransaction &trans) {

	vector<string> v(0), te(0);
	TMoney money;
	int i, j = 0;
	char str[100];
	string s;

	v.push_back("</Transaction>");		//0
	v.push_back("<AccountNr>");			//1
	v.push_back("</AccountNr>");		//
	v.push_back("<BLZ>");				//3
	v.push_back("</BLZ>");				//
	v.push_back("<ContraAccountNr>");	//5
	v.push_back("</ContraAccountNr>");	//
	v.push_back("<ContraBLZ>");			//7
	v.push_back("</ContraBLZ>");		//
	v.push_back("<Money>");				//9
	v.push_back("<Amount>");			//10
	v.push_back("<Text>");				//11
	v.push_back("</Text>");				//12

	while (istr.getline(str, 100)) {
		s = str;
		// FIXME causes bypass of Money
		for (i = j; i < (int) v.size(); i++) {
			if (s.find(v[0]) <= s.size()) {
				break;
			} else if (s.find(v[i]) <= s.size()) {
				if (s.find(v[i + 1]) <= s.size()) {
					break;
				} else if (s.find(v[9])) {
					break;
				}
			}
		}

		//substring filter
		switch (i) {
		case 0:
			return istr;
		case 1:
			trans.accountNr = insideString(s, v[i], v[i + 1]);// s.substr(v[i].size(),s.find(v[i+1])-v[i].size());
			j = 1;
			break;
		case 3:
			trans.BLZ = atoi(insideString(s, v[i], v[i + 1]).c_str());//(s.substr(v[i].size(),s.find(v[i+1])-v[i].size())).c_str());
			j = 3;
			break;
		case 5:
			trans.contraAccountNr = insideString(s, v[i], v[i + 1]);//s.substr(v[i].size(),s.find(v[i+1])-v[i].size());
			j = 5;
			break;
		case 7:
			trans.contraBLZ = atoi(insideString(s, v[i], v[i + 1]).c_str());//(s.substr(v[i].size(),s.find(v[i+1])-v[i].size())).c_str());
			j = 7;
			break;
		case 9:
			istr >> money;
			trans.amount = money;
			j = 9;
			break;
		case 11:
			trans.comment = insideString(s, v[i], v[i + 1]);
			j = 0;
			break;
		default:
			break;
		}
	}
	return istr;
}

const string& TTransaction::getAccountNr() const {
	return this->accountNr;
}

const TMoney& TTransaction::getAmount() const {
	return amount;
}

unsigned TTransaction::getBLZ() {
	return this->BLZ;
}

const string& TTransaction::getContraAccountNr() const {
	return contraAccountNr;
}

unsigned TTransaction::getContraBLZ() const {
	return contraBLZ;
}

const string& TTransaction::getText() const {
	return comment;
}

} /* namespace std */

