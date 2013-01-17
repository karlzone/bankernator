/*
 * TTransactionList.cpp
 *
 *  Created on: 06.12.2012
 *      Author: Runge
 */

#include "TTransactionList.h"

//#define DEBUG

namespace std {

TTransactionList::TTransactionList(string dateiname) {
	this->date = TDate();
	this->time = TTime();
	this->transactionsList.resize(0);
	this->transactionCounter = 0;

	ifstream inf;
	char str[100] = "";
	string swap, s;

	inf.open(dateiname.c_str());

#ifdef DEBUG
	/* PATHFINDER
	 * ofstream outf("xyzfindme.txt");
	 outf << "fsakhfasfh" << endl;
	 outf.close();*/

	cout << "Datei: " << dateiname << endl;
	cout << inf << endl;
#endif

	inf.getline(str, 100);
	swap = str;

	if (swap.find("<TransactionList>")) {
		while (inf.getline(str, 100)) {
			swap = str;
			if (swap.find("<Transaction>")) {
				TTransaction ta;
				inf >> ta;
				this->transactionsList.push_back(ta);
				//this->transactionCounter = (int) this->transactionsList.size() - 1;
				this->transactionCounter++;
#ifdef DEBUG
				cout << "TransactionList: trans.get..." << endl;
				cout << "AccNr:    " << ta.getAccountNr() << endl;
				cout << "BLZ:      " << ta.getBLZ() << endl;
				cout << "ConAccNr: " << ta.getContraAccountNr() << endl;
				cout << "ConBLZ:   " << ta.getContraBLZ() << endl;
				cout << "Text:     " << ta.getText() << endl;
				cout << "Amount:   " << ta.getAmount().getAmount() << endl;
				cout << "TransactionList: add the Transaction and count up :"
				<< transactionCounter << endl;
#endif
				/*	inf.getline(str, 100);
				 swap = str;

				 if (swap.find("<Transaction>")) {
				 TTransaction trans;
				 } else {
				 cout << "No Transaction or file is broken.." << endl;
				 }
				 }*/
			}
		}
		cout << endl << "TransactionList read sucessfully.." << endl;
	} else {
		cout << "No TransactionList found or file is broken.." << endl;
	}

	/*while (inf.getline(str, 100)) {
	 s = str;
	 if (s.find("<TransactionList>") <= s.size()) {
	 break;
	 }
	 }

	 while (inf.getline(str, 100)) {
	 s = str;
	 if (s.find("<Transaction>") <= s.size()) {
	 TTransaction trans; // = new TTransaction();
	 inf >> trans;
	 transactionsList.push_back(trans);
	 } else if (s.find("</Transactionlist>")) {
	 break;
	 }
	 }*/

	inf.close();

}

TTransactionList::~TTransactionList() {
// TODO Auto-generated destructor stub
}

TTransaction TTransactionList::operator[](int Index) {
	if ((Index >= 0) && (Index < transactionCounter))
		return transactionsList[Index];
	return TTransaction();
}

int TTransactionList::getTransactionCounter() const {
	return this->transactionCounter;
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

ostream& operator<<(ostream &ostr, TTransactionList&ttl) {
	for (int i = 0; i < ttl.getTransactionCounter(); i++) {
		ostr << endl << "Transaction [" << i << "]" << endl;
		ostr << ttl.transactionsList[i] << endl;
	}
	return ostr;
}

} /* namespace std */
