// Service.h
#pragma once
#include <iostream>
#include "User.h"
using namespace std;

class Service{
private:
	string serviceName;
	int payNumbers;
public:
	Service();
	virtual void showService(Language&Language) = 0;
	virtual void payService(User&user, long sum) = 0;
	virtual void writeCheck(Database&bd, string address, long sum) = 0;
	virtual int getPayNumbers() = 0;
};