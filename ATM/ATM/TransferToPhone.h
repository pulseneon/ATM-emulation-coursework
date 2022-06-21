// TransferToPhone.h
#pragma once
#include <iostream>
#include "Service.h"
using namespace std;

class TransferToPhone: public Service{
private:
	string serviceName;
	int payNumbers;
public:
	TransferToPhone();
	void showService(Language&Language);
	void payService(User&user, long sum);
	void writeCheck(Database&bd, string address, long sum);
	int getPayNumbers();
};