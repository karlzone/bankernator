/*
 * TTransactionList.cpp
 *
 *  Created on: 06.12.2012
 *      Author: Runge
 */

#include "TTransactionList.h"

namespace std {

TTransactionList::TTransactionList(string dateiname) {
	this->date = TDate();
	this->time = TTime();
	this->transactionsList.resize(0);
	this->transactionCounter = 0;
	ifstream inf(dateiname.c_str());
	char str[100];
	string s;
	while(inf.getline(str,100)){
		s= str;
		if(s.find("<TransactionList>")<=s.size())break;
	}
	while(inf.getline(str,100)){
		s = str;
		if(s.find("<Transaction>")<=s.size()){
			TTransaction trans;// =	new TTransaction();
			inf >> trans;
			transactionsList.push_back(trans);
		}else if (s.find("</Transactionlist>")) {
			break;
		}
	}
	inf.close();

}

TTransactionList::~TTransactionList() {
	// TODO Auto-generated destructor stub
}

TTransaction TTransactionList::operator[](int Index){
	if((Index >= 0)&&(Index < transactionCounter))
		return transactionsList[Index];
	return TTransaction();
}

<<<<<<< HEAD
int TTransactionList::getTransactionCounter() const {
=======
const TDate& TTransactionList::getDate() const {
	return date;
}

const TTime& TTransactionList::getTime() const {
	return time;
}

const vector<TTransaction>& TTransactionList::getTransactionsList() const {
	return transactionsList;
}

unsigned TTransactionList::getTransactionCounter() const {
>>>>>>> 6e3185f6d8e3c19f003ef29a4e275e395a60f8f1
	return transactionCounter;
}

ostream& operator<<(ostream &ostr,TTransactionList&ttl){
	for (unsigned i = 0; i < ttl.getTransactionCounter(); i++) {
		ostr <<"Werte["<<i<<"]" << ttl.transactionsList[i]<<endl;
	}
	return ostr;
}

TDate TTransactionList::getDate() {
	return this->date;
}

TTime TTransactionList::getTime() {
	return this->time;
}

} /* namespace std */
