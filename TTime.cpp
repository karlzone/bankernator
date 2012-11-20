/*
 * TTime.cpp
 *
 *  Created on: 11.10.2012
 *      Author: Runge
 */

#include "TTime.h"
#include <time.h>
#include <iostream>

using namespace std;

TTime::TTime() {
	time_t Zeitstempel;
	tm *now;
	Zeitstempel = time(0);
	now = localtime(&Zeitstempel);
	hour = now->tm_hour;
	minute = now->tm_min;
	second = now->tm_sec;
}

TTime::TTime(int hour, int minute, int second) {
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}

int TTime::getHour() const {
	return hour;
}

void TTime::setHour(int hour) {
	//TODO set limits for hour (0-23)
	this->hour = hour;
}

int TTime::getMinute() const {
	return minute;
}

void TTime::setMinute(int minute) {
	//TODO set limits for minute (0-59)
	this->minute = minute;
}

int TTime::getSecond() const {
	return second;
}

void TTime::setSecond(int second) {
	//TODO set limits for seconds (0-59)
	this->second = second;
}

void TTime::print() {
	char oldFill = cout.fill();
	cout.fill('0');

	cout.width(2);	cout << hour << ':';
	cout.width(2);	cout << minute << ':';
	cout.width(2);	cout << second;

	cout.fill(oldFill);
	cout.flush();
}

TTime::~TTime() {
	// TODO Auto-generated destructor stub
}

