// Money.h
#pragma once
#include <iostream>
using namespace std;

class Money{
protected:
	string currency;
	long sum;
	long lim;

public:
	Money(string Currency, long Sum, long Lim);
	Money();

	void setSum(long Sum);
	void setLim(long Lim);
	void setCurrency(string Currency);

	long getSum();
	long getLim();
	string getCurrency();
};