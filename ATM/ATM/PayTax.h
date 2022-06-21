// PayTax.h

#pragma once
#include <iostream>
#include "Service.h"
using namespace std;

class PayTax: public Service{
private:
	string serviceName;
	int payNumbers;
public:
	PayTax();
	void showService(Language&Language);
	void payService(User&user, long sum);
	void writeCheck(Database&bd, string address, long sum);
	int getPayNumbers();
};