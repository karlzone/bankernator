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
}
