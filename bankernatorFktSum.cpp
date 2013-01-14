/*
 * bankernatorFktSum.cpp
 *
 *  Created on: 20.11.2012
 *      Author: Runge
 */

#include "bankernatorFktSum.h"

namespace std {

void printHeadLine(int w) {
	char oldFill = cout.fill();
	cout.fill('-');
	cout.width(w);
	cout << "" << '|';
	cout.width(w);
	cout << "" << '|';
	cout.width(w);
	cout << "" << '|';
	cout.width(w);
	cout << "" << endl;
	;
	cout.fill(oldFill);
}
string insideString(string s, string sA, string sB){
	unsigned sizeS,sizeA,sizeB,findIdxA,findIdxB;
	sizeS = findIdxA = findIdxB = 0;
	bool findA,findB;
	findA = findB = false;
	sizeS = s.size();
	sizeA = sA.size();
	sizeB = sB.size();

	if(s.find(sA)<= sizeS){findIdxA = s.find(sA);findA = true;}
	if(s.find(sB)<= sizeS){findIdxB = s.find(sB);findB = true;}

	if(findA){
#ifdef DEBUG
		cout << "length of substring:" << findIdxB-findIdxA-sizeA << endl;
		cout << "Amount: " << s.substr(findIdxA+sizeA,findIdxB-findIdxA-sizeA) << endl;
#endif
		return s.substr(findIdxA+sizeA,findIdxB-findIdxA-sizeA);

	}
	return "";
}

string insideString(string s, string sA){
	return insideString(s,sA,"");
}

}//namespace std
