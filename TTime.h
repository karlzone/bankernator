/*
 * TTime.h
 *
 *  Created on: 11.10.2012
 *      Author: Runge
 */

#ifndef TTIME_H_
#define TTIME_H_

#include <string>
#include <stdio.h>

class TTime {
private:
	int hour;
	int minute;
	int second;

public:
	TTime();
	TTime(int, int, int);
	virtual ~TTime();

	int getHour() const;
	void setHour(int hour);
	int getMinute() const;
	void setMinute(int minute);
	int getSecond() const;
	void setSecond(int second);
	void print();

};

#endif /* TTIME_H_ */
