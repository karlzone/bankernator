/*
 * TTransactionList.cpp
 *
 *  Created on: 06.12.2012
 *      Author: Runge
 */
//#define DEBUG
#include "TTransactionList.h"

namespace std {

TTransactionList::TTransactionList(string dateiname) {
#ifdef DEBUG
	cout << "TransactionList: new TTransactionList" << endl;
#endif
	this->date = TDate();

	this->time = TTime();
	this->transactionsList.resize(0);
	this->transactionCounter = 0;
	ifstream inf(dateiname.c_str());
	char str[100];
	string s;
	while(inf.getline(str,100)){
		s= str;
		if(s.find("<Transactionlist>")<=s.size())break;
	}
#ifdef DEBUG
	cout << "TransactionList: <TransactionList>tag find" << endl;
#endif
	while(inf.getline(str,100)){
		s = str;
#ifdef DEBUG
	cout << "TransactionList: getline:"<< s << endl;
#endif
		if(s.find("<Transaction>")<=s.size()){
#ifdef DEBUG
	cout << "TransactionList: <Transaction>tag find" << endl;
#endif
			TTransaction trans;// =	new TTransaction();
#ifdef DEBUG
	cout << "TransactionList: new TTransaction Nr." << transactionCounter << endl;
#endif
			inf >> trans;
			transactionsList.push_back(trans);
			transactionCounter++;
#ifdef DEBUG
	cout << "TransactionList: trans.get..." << endl;
	cout << "AccNr: " << trans.getAccountNr() << endl;
	cout << "BLZ: " << trans.getBLZ() << endl;
	cout << "ConAccNr: " << trans.getContraAccountNr() << endl;
	cout << "ConBLZ: " << trans.getContraBLZ() << endl;
	cout << "Text: " << trans.getComment() << endl;
	cout << "Amount: " << trans.getAmount() << endl;
	cout << "TransactionList: add the Transaction and count up :" << transactionCounter << endl;
#endif
		}else if (s.find("</Transactionlist>")) {
#ifdef DEBUG
	cout << "TransactionList: find </Transactionlist>tag Listend" << endl;
#endif
			break;
		}
	}
#ifdef DEBUG
	cout << "TranactionList: datei schließen" << endl;
#endif
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

ostream& operator<<(ostream &ostr,TTransactionList&ttl){
	for (unsigned i = 0; i < ttl.getTransactionCounter(); i++) {
		ostr <<"Werte["<<i<<"]" << ttl.transactionsList[i]<<endl;
	}
	return ostr;
}

unsigned TTransactionList::getTransactionCounter() const {
	return transactionCounter;
}

const TDate& TTransactionList::getDate() const {
	return date;
}

const TTime& TTransactionList::getTime() const {
	return time;
}

const vector<TTransaction>& TTransactionList::getTransactionsList() const {
	return transactionsList;
}






} /* namespace std */
