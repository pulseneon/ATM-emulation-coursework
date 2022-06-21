// payTax.cpp
#pragma once
#include <iostream>
#include <string>
#include "PayTax.h"
using namespace std;

PayTax::PayTax(){
	serviceName = "Оплата налогов на ИНН";
	payNumbers = 12;
}

void PayTax::showService(Language&Language){
	cout << "	" << Language.getString("service_pay_tax_hub") << "\n";
	cout << "\n";
	cout << Language.getString("service_pay_tax_message_1") << "\n";
	cout << Language.getString("service_pay_tax_message_2") << "\n";
	cout << Language.getString("service_pay_tax_message_3") << "\n";
	cout << Language.getString("service_pay_tax_message_4") << "\n";
	cout << Language.getString("service_pay_tax_message_5") << "\n";
	cout << "\n";
	cout << Language.getString("service_pay_tax_message_6") << "\n";
	cout << Language.getString("service_pay_tax_message_7") << "\n";
}

void PayTax::payService(User&user, long sum){
	user.subMoney(sum);
}

void PayTax::writeCheck(Database&bd, string address, long sum){
	bd.addLogOperation(serviceName + " " + address + " - " + to_string(sum) + " Руб.");
}

int PayTax::getPayNumbers(){
	return payNumbers;
}