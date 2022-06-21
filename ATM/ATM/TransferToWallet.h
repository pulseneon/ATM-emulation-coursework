// TransferToWallet.h
#pragma once
#include <iostream>
#include "Service.h"
using namespace std;

class TransferToWallet : public Service{
private:
	string serviceName;
	int payNumbers;
public:
	TransferToWallet();
	void showService(Language&Language);
	void payService(User&user, long sum);
	void writeCheck(Database&bd, string address, long sum);
	int getPayNumbers();
};