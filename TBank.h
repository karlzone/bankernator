///////////////////////////////////////////////////////////
//  TBank.h
//  Implementation of the Class TBank
//  Created on:      01-Nov-2012 18:19:10
//  Original author: Runge
///////////////////////////////////////////////////////////

#if !defined(EA_ABC9D122_9EC7_4555_A420_8FA79E39912F__INCLUDED_)
#define EA_ABC9D122_9EC7_4555_A420_8FA79E39912F__INCLUDED_

#include <string>

#include "TAccount.h"

using namespace std;

#define MAXBANKACCOUNTS 100

class TAccount;
class TBank
{
private:
	string name;
	unsigned BLZ;
	TAccount *accountList[MAXBANKACCOUNTS];
	int accountCounter;
public:
	
	TBank(string,unsigned);
	virtual ~TBank();

	int getAccountCounter();

	void addAccount(TAccount*);
	
	unsigned getBlz() ;
	void setBlz(unsigned blz);
	
	string getName() ;
	void setName( string name);

	void print();

};
#endif // !defined(EA_ABC9D122_9EC7_4555_A420_8FA79E39912F__INCLUDED_)
