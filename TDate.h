///////////////////////////////////////////////////////////
//  TDate.h
//  Implementation of the Class TDate
//  Created on:      11-Okt-2012 21:16:58
//  Original author: Runge
///////////////////////////////////////////////////////////

#ifndef TDATE_H_
#define TDATE_H_

class TDate {
private:
	int day;
	int month;
	int year;

public:
	TDate();
	TDate(int, int, int);
	virtual ~TDate();

	void print();
	int getDay() const;
	void setDay(int day);
	int getMonth() const;
	void setMonth(int month);
	int getYear() const;
	void setYear(int year);
};
#endif /* TDATE_H_ */
