#pragma once
#include <iostream>
#include "Account.h"
#include "Language.h"
#include "Database.h"
#include "Card.h"
using namespace std;

class User: public Account, public Card{
private:
	bool isPin; // Card is ATM?
	string gender;
	string birthday;
public:
	User();
	~User();

	void checkPin(Language&l);
	void addMoneyBal(Language&l);
	void subMoneyBal(Language&l);
	void showHistory(Language&l, Database&bd);
	void showProfile(Language&l);
	void createTicket(Language&l);

	bool getIsPin();
	string getGender();
	string getBirthday();

	void resetAccount(Language&l, Database&bd);
	void setIsPin();
	void setIsPin(bool arg);
	void setBirthday(string birth);
};

