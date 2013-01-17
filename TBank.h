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
#include "bankernatorFktSum.h"
//#include "TBooking.h"

namespace std {

#define MAXBANKACCOUNTS 100

class TAccount;

class TBank {
private:
	string name;
	unsigned BLZ;
	TAccount *accountList[MAXBANKACCOUNTS];
	int accountCounter;
public:

	TBank(string, unsigned);
	virtual ~TBank();

	//friend ostream &operator<< (ostream &ostr, const TBank &a);

	int getAccountCounter();

	void addAccount(TAccount*);

	TAccount* getAccount(int);

	TAccount* getAccountByNr(string);

	unsigned getBlz();
	void setBlz(unsigned blz);

	string getName();
	void setName(string name);

	void print();

	void compare();

	friend ostream& operator<<(ostream &, TBank*);

};
}
#endif // TBANK_H_
