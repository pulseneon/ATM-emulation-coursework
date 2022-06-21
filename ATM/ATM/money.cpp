// money.cpp
#include "Money.h"

Money::Money(string Currency, long Sum, long Lim){
	currency = Currency;
	sum = Sum;
	lim = Lim;
}

Money::Money(){
	currency = "Rub";
	sum = 15000;
	lim = 50000;
}

long Money::getSum(){
	return sum;
}

long Money::getLim(){
	return lim;
}

string Money::getCurrency(){
	return currency;
}

void Money::setSum(long Sum){
	sum = Sum;
}

void Money::setLim(long Lim){
	lim = Lim;
}

void Money::setCurrency(string Currency){
	currency = Currency;
}