/*
* TBooking.cpp
*
* Created on: 1 Nov 2012
* Author: karsten
*/

#include "TBooking.h"

namespace std {

TBooking::TBooking() {
// TODO Auto-generated constructor stub

}

bool TBooking::isPrinted() const {
return printed;
}

void TBooking::setPrinted(bool printed) {
this->printed = printed;
}

TBooking::~TBooking() {
// TODO Auto-generated destructor stub
}

} /* namespace std */
