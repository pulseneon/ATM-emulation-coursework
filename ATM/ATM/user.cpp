// user.cpp
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <String>
#include <Windows.h>
#include "User.h"
#include "Database.h"
#include "Language.h"
using namespace std;

User::User(){
	isPin = false;
	gender = "male";
	birthday = "02/11/1999";
}

User::~User(){
	isPin = false;
}

bool User::getIsPin(){
	if (isPin) return true;
	else return false;
}

void User::setIsPin(){
	isPin ? isPin = false : isPin = true;
}

void User::setIsPin(bool arg){
	arg ? isPin = true : isPin = false;
}

string User::getGender(){
	return gender;
}

string User::getBirthday(){
	return birthday;
}

void User::resetAccount(Language&l, Database&bd){
	//this->operator!();
	!*this;
	bd.addLogOperation(l.getString("reset_log"));
}

void User::checkPin(Language&l){
	int inputPin;
	system("cls");
	cout << "	" << l.getString("check_pin_hub") << "\n";
	cout << l.getString("check_pin_message") << "\n";
	cout << "> ";
	for (;;){
		int answ = scanf("%d", &inputPin); // If answ = 1 -> enter int
		if (answ != 1 || inputPin != getPin()){
			scanf("%*[^\n]");
			system("cls");
			cout << l.getString("check_pin_error") << "\n";
			cout << l.getString("check_pin_reply") << "\n";
			cout << "> ";
		}

		else break;
	}
	system("cls");
	cout << l.getString("check_pin_delay") << "\n";
	Sleep(2500);
	cout << "\n";
	system("pause");
}

void User::addMoneyBal(Language&l){
	system("cls");
	cout << "	" << l.getString("add_money_hub") << "\n";
	cout << l.getString("bal") << getBal() << " " << getCurr() << " | ";
	cout << l.getString("lim") << getLimit() << " " << getCurr() << "\n";
	cout << "\n";
	cout << l.getString("add_money_message") << "\n";
	cout << l.getString("add_money_message_info") << "\n";
	cout << "> ";
	int inputSum;
	for (;;){
		int answ = scanf("%d", &inputSum); // If answ = 1 -> enter int
		if (inputSum == -1){
			cout << l.getString("pause");
			return;
		}
		if (answ != 1 || inputSum < 100 || getLimit() < getBal() + inputSum){
			scanf("%*[^\n]");
			system("cls");
			cout << l.getString("add_money_blocked") << "\n";
			if (answ != 1){ // type error
				l.getString("add_money_blocked_error");
			}
			// errors 
			if (inputSum < 100){ // если слишком малый перевод
				cout << l.getString("add_money_blocked_odd") << "\n";
			}

			if (getLimit() < getBal() + inputSum){
				l.getString("add_money_blocked_limit");
			}
			cout << l.getString("add_money_blocked_reply") << "\n";
			cout << l.getString("add_money_message_info") << "\n";
			cout << "> ";
		}

		else break;
	}
	system("cls");
	cout << l.getString("add_money_delay") << "\n";
	addMoney(inputSum);
	Database bd;
	bd.addLogOperation(l.getString("add_log_addbal") + to_string(inputSum) + " " + getCurr());
	Sleep(2500);
	cout << l.getString("add_money_ok") << "\n";
	cout << "\n";
	cout << l.getString("pause");
}

void User::subMoneyBal(Language&l){
	system("cls");
	cout << "	" << l.getString("sub_money_hub") << "\n";
	cout << l.getString("bal") << getBal() << " " << getCurr() << " | ";
	cout << l.getString("lim") << getLimit() << " " << getCurr() << "\n";
	cout << "\n";
	cout << l.getString("sub_money_message") << "\n";
	cout << l.getString("sub_money_message_info") << "\n";
	cout << "> ";
	int inputSum;
	for (;;){
		int answ = scanf("%d", &inputSum); // If answ = 1 -> enter int
		if (inputSum == -1){
			cout << l.getString("pause");
			return;
		}
		if (answ != 1 || inputSum < 100 || getBal() - inputSum < 0 || inputSum > 50000){
			scanf("%*[^\n]");
			system("cls");
			cout << l.getString("sub_money_blocked") << "\n";
			if (answ != 1){ // type error
				l.getString("sub_money_blocked_error");
			}
			// errors 
			if (inputSum < 100 || inputSum > 50000){ // если слишком малый перевод или слишком большой
				cout << l.getString("sub_money_blocked_odd") << "\n";
			}
			cout << l.getString("sub_money_blocked_reply") << "\n";
			cout << l.getString("sub_money_message_info") << "\n";
			cout << "> ";
		}

		else break;
	}
	// inputSum + Money;
	system("cls");
	cout << l.getString("sub_money_delay") << "\n";
	subMoney(inputSum);
	Database bd;
	bd.addLogOperation(l.getString("add_log_subbal") + to_string(inputSum) + " " + getCurr());
	Sleep(2500);
	cout << l.getString("sub_money_ok") << "\n";
	cout << "\n";
	cout << l.getString("pause");
}

void User::setBirthday(string birth){
	birthday = birth;
}

void User::showHistory(Language&l, Database&bd){
	system("cls");
	cout << "	" << l.getString("history_hub") << "\n";
	cout << l.getString("history_message") << "\n";
	cout << "\n";
	bd.readLogOperation();
	cout << "\n";
	cout << l.getString("pause") << "\n";
}

void User::createTicket(Language&l){
	Database bd;
	int input;
	system("cls");
	cout << "	" << l.getString("ticket_hub") << "\n";
	cout << l.getString("ticket_message") << "\n";
	cout << "\n";
	cout << "1. " << l.getString("ticket_fio") << "\n";
	cout << "2. " << l.getString("ticket_birthday") << "\n";
	cout << "3. " << l.getString("ticket_card_name") << "\n";
	cout << "4. " << l.getString("ticket_card_time") << "\n";
	cout << "5. " << l.getString("ticket_limit") << "\n";
	cout << "6. " << l.getString("ticket_answer") << "\n";
	cout << "\n"; 
	cout << "7. " << l.getString("ticket_back") << "\n";
	cout << "\n";
	cout << l.getString("ticket_ans_message") << "\n";
	for (;;){
		cout << "> ";
		int check = scanf("%d", &input);
		if (check != 1){
			scanf("%*[^\n]");
			cout << l.getString("ticket_error") << "\n";
		}
		else break;
	}

	system("cls");
	string change;
	switch (input)
	{
	case 1:
		cout << l.getString("ticket_ans_message") << "\n";
		cout << "> ";
		cin.ignore();
		getline(cin, change);
		cout << l.getString("ticket_ans_good") << "\n";
		setFIO(change);
		Sleep(3000);
		cout << l.getString("ticket_ans_finish") << "\n";
		bd.addLogOperation(l.getString("add_log_change_name") + change);
		system("pause");
		break;
	case 2:
		cout << l.getString("ticket_ans_message") << "\n";
		cout << "> ";
		cin.ignore();
		getline(cin, change);
		cout << l.getString("ticket_ans_good") << "\n";
		setBirthday(change);
		Sleep(3000);
		cout << l.getString("ticket_ans_finish") << "\n";
		bd.addLogOperation(l.getString("add_log_change_birthday") + change);
		system("pause");
		break;
	case 3:
		cout << l.getString("ticket_ans_message") << "\n";
		cout << "> ";
		cin.ignore();
		getline(cin, change);
		cout << l.getString("ticket_ans_good") << "\n";
		setCardName(change);
		Sleep(3000);
		cout << l.getString("ticket_ans_finish") << "\n";
		bd.addLogOperation(l.getString("add_log_change_card_name") + change);
		system("pause");
		break;
	case 4:
		cout << l.getString("ticket_ans_card_time") << "\n";
		system("pause");
		break;
	case 5: // limit
		long newLimit;
		cout << l.getString("ticket_ans_limit") << "\n";
		cout << "> ";
		cin.ignore();
		for (;;){
			int check = scanf("%d", &newLimit);
			if (check != 1 || newLimit < 5000 || newLimit > 120000){
				scanf("%*[^\n]");
				cout << l.getString("ticket_ans_limit_bad") << "\n";
				cout << "> ";
			}
			else break;
		}
		cout << l.getString("ticket_ans_good") << "\n";
		setLimit(newLimit);
		Sleep(3000);
		cout << l.getString("ticket_ans_finish") << "\n";
		bd.addLogOperation(l.getString("add_log_change_limit") + to_string(newLimit));
		system("pause");
		break;
	case 6:
		cout << l.getString("ticket_ans_tp") << "\n";
		cout << l.getString("ticket_ans_tp_end") << "\n";
		system("pause");
		break;
	case 7:
		cout << l.getString("ticket_back_message") << "\n";
		system("pause");
		return;
		break;
	}
}

void User::showProfile(Language&l){
	system("cls");
	cout << "	" << l.getString("profile_hub") << "\n";
	cout << l.getString("profile_message") << "\n";
	cout << l.getString("profile_edit") << "\n";
	cout << "\n";
	cout << l.getString("profile_id") << getIdent() << "\n";
	cout << l.getString("profile_fio") << getFIO() << "\n";
	cout << l.getString("profile_gender") << l.getString(getGender()) << "\n";
	cout << l.getString("profile_birthday") << getBirthday() << "\n";
	cout << "\n";
	cout << l.getString("profile_card") << getCardNumber() << "\n";
	cout << l.getString("profile_card_name") << getCardName() << "\n";
	cout << l.getString("profile_card_time") << getCardTime() << "\n";
	cout << "\n";
	cout << l.getString("profile_bal") << getBal() << "\n";
	cout << l.getString("profile_limit") << getLimit() << "\n";
	cout << "\n";
}