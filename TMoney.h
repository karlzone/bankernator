/*
 * TMoney.h
 *
 *  Created on: 18 Oct 2012
 *      Author: karsten
 */

#ifndef TMONEY_H_
#define TMONEY_H_

//#include <stdio.h>
#include <string>

#include "bankernatorFktSum.h"

namespace std {

class TMoney {
private:
	double amount;
	string currency;

public:
	TMoney();
	virtual ~TMoney();
	TMoney(double);
	TMoney operator+(TMoney &b);
	TMoney operator-(TMoney &b);
	bool operator <(TMoney &b);
	void setAmount(double x);
	double getAmount();
	void setCurrency(string cur);
	string getCurrency();
	//TMoney increaseBalance(double);
	//TMoney decreaseBalance(double);
	void print();
};
}
#endif /* TMONEY_H_ */
