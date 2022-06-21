// transferToWallet.cpp
#pragma once
#include <iostream>
#include <string>
#include "TransferToWallet.h"
using namespace std;

TransferToWallet::TransferToWallet(){
	serviceName = "Пополнение онлайн-кошелька";
	payNumbers = 8;
}

void TransferToWallet::showService(Language&Language){
	cout << "	" << Language.getString("service_pay_wallet_hub") << "\n";
	cout << Language.getString("service_pay_wallet_message") << "\n";
	cout << Language.getString("service_pay_wallet_help") << "\n";
	cout << "\n";
}

void TransferToWallet::payService(User&user, long sum){
	user.subMoney(sum);
}

void TransferToWallet::writeCheck(Database&bd, string address, long sum){
	bd.addLogOperation(serviceName + " WM" + address + " - " + to_string(sum) + " Руб.");
}

int TransferToWallet::getPayNumbers(){
	return payNumbers;
}