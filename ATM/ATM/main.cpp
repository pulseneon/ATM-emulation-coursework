// main.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "Interface.h"
#include "Database.h"
#include "TransferToPhone.h"
#include "TransferToWallet.h"
#include "TransferToCard.h"
#include "PayTax.h"
#include "User.h"
using namespace std;

static int existingСlasses = 0; // количество классов в текущий момент

Language l;
Database bd;
TransferToCard toCard;
string card;

User *user = new User();

int getInt(int num){
	for (;;){
		int answ = scanf("%d", &num); // If answ = 1 -> enter int
		if (answ != 1){
			scanf("%*[^\n]"); // clear buffer
			cout << "> ";
		}
		else
			return num;
	}
}

int isInt(string str){
	for (int i = 0; i<str.size(); i++){
		if (str[i] < '0' || str[i] > '9'){
			return 0;
		}
	}
	return 1;
}

void titulMenu(){
	Interface c;
	existingСlasses++;
	int key;
	do{
		c.zastavka(l);
		key = _getch();
		switch (key){
		case '\t': // Изменить язык
			l.changeLang();
			break;

		case 'a': // О авторе
			c.showAboutMe(bd);
			break;

		case 'd': // О авторе
			c.showSubjectArea(bd);
			break;


		case 's': // Руководство оператора
			c.showHelp(bd);
			break;
		
		case 'q':
			exit(0);
			break;

		case 13: // Продолжить
			existingСlasses--;
			return; // exit
			break;
		}

		fflush(stdin);
	} while (key != 27);
}

void auth(){
	int key;
	do{
		system("cls");
		cout << "	" << l.getString("auth_hub") << "\n";
		cout << l.getString("auth_message") << "\n";
		cout << "\n";
		cout << l.getString("auth_card");
		/* If card in atm */
		if (user->getIsPin()){
			cout << l.getString("auth_card_status_t") << "\n"; // В банкомате.
			cout << "\n";
			cout << l.getString("auth_logoff") << "\n"; // Нажмите <d>, чтобы достать карту.
			cout << l.getString("auth_proceed") << "\n"; // Нажмите <s>, чтобы продолжить.
		}

		/* else */
		else{
			cout << l.getString("auth_card_status_f") << "\n";
			cout << "\n";
			cout << l.getString("auth_enter_card") << "\n";
			cout << l.getString("auth_leave") << "\n";
		}

		key = _getch();
		switch (key){
		case 's':
			user->setIsPin();
			break;
		case 'd':
			if (user->getIsPin()){
				key = 27;
			}
			else{
				system("cls");
				user->setIsPin(false);
				titulMenu();
			}
			break;
		}

		fflush(stdin);
	} while (key != 27);
	
	/* Enter pin */
	int inputPin;
	system("cls");
	cout << "	" << l.getString("auth_get_pin_hub") << "\n";
	cout << l.getString("auth_get_pin_message") << "\n";
	cout << l.getString("auth_get_pin_tip") << "\n";
	cout << "\n";
	cout << "> ";
	for (;;){
		int answ = scanf("%d", &inputPin);
		if (answ != 1 || inputPin < 1000 || inputPin > 9999){
			if (inputPin == 0)
				break;
			scanf("%*[^\n]"); 
			system("cls");
			cout << l.getString("auth_get_pin_error") << "\n";
			cout << l.getString("auth_get_pin_reply") << "\n";
			cout << "> ";
		}

		else break;
	}

	system("cls");
	user->setPin(inputPin);
	user->setFIO(l.getString("user_name"));
	user->setCurr(l.getString("currency"));
	cout << "	" << l.getString("auth_hello_hub") << "\n";
	cout << l.getString("auth_delay") << "\n";
	Sleep(2500); // delay 2.5s
	system("cls");
	cout << "	" << l.getString("auth_hello_hub") << "\n";
	cout << user->getFIO() << l.getString("auth_hello") << "\n";
	cout << "\n";
	cout << l.getString("pause") << "\n";
}

void menu(){
	int key;
	do{
		key = _getch();
		system("cls");
		cout << "	" << l.getString("menu_hub") << "\n";
		cout << l.getString("bal") << user->getBal() << " " << user->getCurr() << " | ";
		cout << l.getString("lim") << user->getLimit() << " " << user->getCurr() << "\n";
		cout << "\n";
		cout << "1. " << l.getString("menu_list_addBal") << "\n";
		cout << "2. " << l.getString("menu_list_subBal") << "\n";
		cout << "3. " << l.getString("menu_list_history") << "\n";
		cout << "\n";
		cout << "4. " << l.getString("menu_list_transfer") << "\n";
		cout << "5. " << l.getString("menu_list_service") << "\n";
		cout << "\n";
		cout << "6. " << l.getString("menu_list_cabinet") << "\n";
		cout << "7. " << l.getString("menu_list_info") << "\n";
		cout << "\n";
		cout << "8. " << l.getString("menu_list_exit") << "\n";
		switch (key){
		case '1':
			user->checkPin(l);
			user->addMoneyBal(l);
			break;

		case '2':
			user->checkPin(l);
			user->subMoneyBal(l);
			break;

		case '3':
			user->showHistory(l, bd);
			break;

		case '4':
			user->checkPin(l);
			toCard.showInfo(l);
			cout << "\n";
			cout << l.getString("transfer_card_message_help") << "\n";
			cout << "\n";
			system("pause");
			system("cls");
			cout << "	" << l.getString("transfer_card_hub") << "\n";
			cout << "\n";
			cout << l.getString("transfer_card_recent") << "\n";
			toCard.showRecentTrans(bd);
			cout << "\n";
			cout << l.getString("transfer_card_get_card") << "\n";
			cout << l.getString("transfer_card_help") << "\n";
			for (;;){
				cin.clear();
				getline(cin, card);
				if (toCard.checkCardOnValid(bd, card))
					break;
				cout << "> ";
			}
			cout << "\n";
			system("cls");
			cout << "	" << l.getString("transfer_card_hub") << "\n"; 
			cout << l.getString("transfer_card_to_card") << card << "\n";
			cout << "\n";
			cout << l.getString("bal") << user->getBal() << " " << user->getCurr() << " | ";
			cout << l.getString("lim") << user->getLimit() << " " << user->getCurr() << "\n";
			cout << "\n";
			cout << l.getString("transfer_card_sum") << "\n";
			cout << l.getString("transfer_card_send_info") << "\n";
			for (;;){
				long toCardSum = 0;
				cout << "> ";
				cin.clear();
				toCardSum = getInt(toCardSum);
				if (toCardSum == -1){
					cout << l.getString("pause") << "\n";
					break;
				}
				if (toCardSum <= user->getBal() && toCardSum >= 100){
					toCard.payService(*user, toCardSum);
					cout << l.getString("transfer_card_sum_good") << "\n";
					toCard.writeCheck(bd, card, toCardSum);	
					cout << l.getString("pause") << "\n";
					break;
				}
				if (toCardSum < 100){
					cout << l.getString("transfer_card_sum_error") << "\n";
				}
				if (toCardSum > user->getBal()){
					cout << l.getString("transfer_card_sum_bad") << "\n";
				}
				
			}
			break;

		case '5':
			user->checkPin(l);
			for (;;){
				system("cls");
				cout << "	" << l.getString("service_hub") << "\n";
				cout << "\n";
				cout << l.getString("service_message") << "\n";;
				cout << "1. " << l.getString("service_to_phone") << "\n";
				cout << "2. " << l.getString("service_pay_tax") << "\n";
				cout << "3. " << l.getString("service_to_wallet") << "\n";
				cout << "\n";
				cout << "4. " << l.getString("service_back") << "\n";
				cout << "\n";
				cout << "> "; 
				int inputSer = 0;
				inputSer = getInt(inputSer);
				if (inputSer == 1){ // Пополнение телефона
					TransferToPhone toPhone;
					existingСlasses++;

					system("cls");
					toPhone.showService(l);
					string phone;
					int innSize = toPhone.getPayNumbers();
					for (;;){
						getline(cin, phone);
						int strlenght = phone.length();
						if (strlenght == innSize && isInt(phone) == 1)
							break;
						cout << "> ";
					}
					system("cls");
					cout << "	" << l.getString("service_pay_tax_hub") << "\n";
					cout << "\n" << l.getString("bal") << user->getBal() << " " << user->getCurr() << " | ";
					cout << l.getString("lim") << user->getLimit() << " " << user->getCurr() << "\n";
					for (;;){
						cout << "\n";
						cout << l.getString("service_to_phone_sum") << "\n";
						cout << l.getString("service_to_phone_sum_help") << "\n";
						cout << "> ";
						long getSum = 0;
						getSum = getInt(getSum);
						if (getSum == -1){
							existingСlasses--;
							break;
						}
						if (getSum <= user->getBal() && getSum > 0){
							toPhone.payService(*user, getSum);
							cout << l.getString("service_to_phone_good") << "\n";
							toPhone.writeCheck(bd, phone, getSum);
							system("pause");
							existingСlasses--;
							break;
						}
						else{
							cout << l.getString("service_to_phone_bad") << "\n";
						}
					}
				}
				if (inputSer == 2){
					system("cls");
					PayTax payTax;
					existingСlasses++;

					payTax.showService(l);
					string inn;
					int innSize = payTax.getPayNumbers();
					for (;;){ // проверка на 10 символов и на буквы
						//cin.ignore();

						getline(cin, inn);
						int strlenght = inn.length();
						if (strlenght == innSize && isInt(inn) == 1)
							break;
						cout << "> ";
					}
					system("cls");
					cout << "	" << l.getString("service_pay_tax_hub") << "\n";
					cout << "\n" << l.getString("bal") << user->getBal() << " " << user->getCurr() << " | ";
					cout << l.getString("lim") << user->getLimit() << " " << user->getCurr() << "\n";
					for (;;){ // ввод суммы
						cout << "\n";
						cout << l.getString("service_pay_tax_sum") << "\n";
						cout << l.getString("service_pay_tax_sum_help") << "\n";
						cout << "> ";
						long getSum = 0;
						getSum = getInt(getSum);
						if (getSum == -1){
							existingСlasses--;
							break;
						}
						if (getSum <= user->getBal() && getSum > 0){
							payTax.payService(*user, getSum);
							cout << l.getString("service_pay_tax_good") << "\n";
							payTax.writeCheck(bd, inn, getSum);
							existingСlasses--;
							system("pause");
							break;
						}
						else{
							cout << l.getString("service_pay_tax_bad") << "\n";
						}
					}
				}
				if (inputSer == 3){ // Online wallet
					TransferToWallet toWallet;
					existingСlasses++;

					system("cls");
					toWallet.showService(l);
					string wallet;
					int innSize = toWallet.getPayNumbers();
					for (;;){
						getline(cin, wallet);
						int strlenght = wallet.length();
						if (strlenght == innSize && isInt(wallet) == 1)
							break;
						cout << "> ";
					}
					system("cls");
					cout << "	" << l.getString("service_pay_tax_hub") << "\n";
					cout << "\n" << l.getString("bal") << user->getBal() << " " << user->getCurr() << " | ";
					cout << l.getString("lim") << user->getLimit() << " " << user->getCurr() << "\n";
					for (;;){
						cout << "\n";
						cout << l.getString("service_pay_wallet_sum") << "\n";
						cout << l.getString("service_pay_wallet_sum_help") << "\n";
						cout << "> ";
						long getSum = 0;
						getSum = getInt(getSum);
						if (getSum == -1){
							existingСlasses--;
							break;
						}
						if (getSum <= user->getBal() && getSum > 0){
							toWallet.payService(*user, getSum);
							cout << l.getString("service_pay_wallet_good") << "\n";
							toWallet.writeCheck(bd, wallet, getSum);
							existingСlasses--;
							system("pause");
							break;
						}
						else{
							cout << l.getString("service_pay_wallet_bad") << "\n";
						}
					}
				}
				if (inputSer == 4){
					cout << l.getString("pause") << "\n";
					break;
				}
				
			}
			break;

		case '6':
			for (;;){
				user->showProfile(l);
				cout << "1. " << l.getString("profile_menu_ticket") << "\n";
				cout << "2. " << l.getString("profile_menu_back") << "\n";
				cout << "\n";
				cout << "> ";
				int input = 0;
				input = getInt(input);
				if (input == 1){ 
					user->checkPin(l);
					user->createTicket(l);
				}
				if (input == 2){
					cout << l.getString("pause");
					break;
				}
			}
			break;
		
		case '7':                                                                    
			user->checkPin(l);
			for (;;){
				system("cls");
				cout << "	" << l.getString("settings_hub") << "\n";
				cout << "1. " << l.getString("settings_lang") << "\n";
				cout << "2. " << l.getString("settings_clear") << "\n";
				cout << "3. " << l.getString("settings_null") << "\n";
				cout << "4. " << l.getString("settings_cards") << "\n\n";
				cout << "5. " << l.getString("settings_back") << "\n\n";
				cout << "<" << l.getString("settings_classes_info") << to_string(existingСlasses) << ">" << "\n";
				int getInput = 0;
				cout << "\n";
				cout << "> ";
				getInput = getInt(getInput);
				if (getInput == 1){
					l.changeLang();
					system("pause");
				}

				if (getInput == 2){
					user->resetAccount(l, bd);
					cout << l.getString("settings_clear_message") << "\n";
					system("pause");
				}

				if (getInput == 3){
					bd.createFileLogs();
					cout << l.getString("settings_null_message") << "\n";
					system("pause");
				}

				if (getInput == 4){
					bd.showCardsFile();
					system("pause");
				}

				if (getInput == 5)
					break;
			}
			cout << "\n";
			cout << l.getString("pause") << "\n";
			break;

		case '8':
			key = 27;
			break;
		}
		fflush(stdin);
	} while (key != 27);
}

void main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color F0");
	existingСlasses += 5; // изначально объявленные классы
	bd.createFileLogs();
	titulMenu();
	auth();
	menu();
}