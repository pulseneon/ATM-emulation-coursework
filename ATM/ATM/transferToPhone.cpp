// transferToPhone.cpp
#pragma once
#include <iostream>
#include <string>
#include "TransferToPhone.h"
using namespace std;

TransferToPhone::TransferToPhone(){
	serviceName = "Пополнение номера телефона";
	payNumbers = 10;
}

void TransferToPhone::showService(Language&Language){
	cout << "	" << Language.getString("service_to_phone_hub") << "\n";
	cout << Language.getString("service_to_phone_message") << "\n";
	cout << Language.getString("service_to_phone_help") << "\n";
	cout << "\n";
}

void TransferToPhone::payService(User&user, long sum){
	user.subMoney(sum);
}

void TransferToPhone::writeCheck(Database&bd, string address, long sum){
	bd.addLogOperation(serviceName + " +" + address + " - " + to_string(sum) + " Руб.");
}

int TransferToPhone::getPayNumbers(){
	return payNumbers;
}