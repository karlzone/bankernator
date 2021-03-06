/*
 * TCustomer.h
 *
 *  Created on: 28 Oct 2012
 *      Author: karsten
 */

#ifndef TCUSTOMER_H_
#define TCUSTOMER_H_

#include <string>

#include "TAccount.h"
#include "bankernatorFktSum.h"
#include "TDate.h"

namespace std {

#define MAXACCOUNTS 10

class TAccount;

class TCustomer {
private:
	string name, street, streetnr, postcode, city;
	TDate birthday;
	int accountCounter;
	TAccount *accountList[MAXACCOUNTS];

public:
	TCustomer();
	TCustomer(string name, TDate birthday, string street, string streetnr,
			string postcode, string city);
	virtual ~TCustomer();

	friend ostream &operator<< (ostream &ostr, const TCustomer &a);

	TDate getBirthday();
	void setBirthday(TDate birthday);

	string getCity();
	void setCity(string city);

	string getName();
	void setName(string name);

	string getPostcode();
	void setPostcode(string postcode);

	string getStreet();
	void setStreet(string street);

	string getStreetnr();
	void setStreetnr(string streetnr);

	TAccount* getAccountPtr();
//	void setAccountPtr(TAccount* accountPtr);

	int getAccountCounter();
//	void setSumOfTAccounts(int sumOfTAccounts);

	void addAccount(TAccount * accountPtr);

	void print();

	friend ostream& operator<<(ostream &, TCustomer&);
};
}
#endif /* TCUSTOMER_H_ */
