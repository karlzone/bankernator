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

ostream &operator<<(ostream &ostr, const TTransaction &a) {
	return ostr;
}/*
istream &operator>>(istream &istr, TTransaction &a) {

	vector<string> v(0), te(0);

	v.push_back("</Transaction>");		//0
	v.push_back("<AccountNr>");			//
	v.push_back("</AccountNr>");		//
	v.push_back("<BLZ>");				//
	v.push_back("</BLZ>");				//
	v.push_back("<ContraAccountNr>");	//
	v.push_back("</ContraAccountNr>");	//
	v.push_back("<ContraBLZ>");			//
	v.push_back("</ContraBLZ>");		//


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
		switch (i) {
			case 1:
				a.accountNr = s.substr(v[i].size(),s.find(v[i+1])-v[i].size());
				break;
			case 3:
				a.BLZ = (s.substr(v[i].size(),s.find(v[i+1])-v[i].size()));
				break;
			case 5:
				a.contraAccountNr = s.substr(v[i].size(),s.find(v[i+1])-v[i].size());
				break;
			case 7:
				a.contraBLZ = s.substr(v[i].size(),s.find(v[i+1])-v[i].size());
				break;
			default:
				break;
		}
	}
	return istr;
}*/

} /* namespace std */

