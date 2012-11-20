///////////////////////////////////////////////////////////
//  TBank.h
//  Implementation of the Class TBank
//  Created on:      01-Nov-2012 18:19:10
//  Original author: Runge
///////////////////////////////////////////////////////////

#ifndef TBANK_H_
#define TBANK_H_

#include <string>

#include "TAccount.h"
//#include "TBooking.h"

using namespace std;

#define MAXBANKACCOUNTS 100

class TAccount;

class TBank {
private:
	string name;
	unsigned BLZ;
	static TAccount *accountList[MAXBANKACCOUNTS];
	int accountCounter;
public:

	TBank(string, unsigned);
	virtual ~TBank();

	int getAccountCounter();

	void addAccount(TAccount*);

	unsigned getBlz();
	void setBlz(unsigned blz);

	string getName();
	void setName(string name);

	void print();

};
#endif // TBANK_H_
