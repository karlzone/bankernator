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
/*
TTransaction TTransactionList::operator[](int Index){
	if((Index >= 0)&&(Index < transactionCounter))
		return transactionsList[Index];
//	return TTransaction();
}
*/
int TTransactionList::getTransactionCounter() const {
	return transactionCounter;
}

ostream& operator<<(ostream &ostr,TTransactionList&ttl){
	for (int i = 0; i < ttl.getTransactionCounter(); i++) {
		ostr <<"Werte["<<i<<"]" << ttl.transactionsList[i]<<endl;
	}
	return ostr;
}

} /* namespace std */
