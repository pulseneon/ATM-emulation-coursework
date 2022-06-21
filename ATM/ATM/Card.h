// Card.h
#pragma once
#include <iostream>
using namespace std;

class Card{
private:
	string cardName;
	string cardNumber;
	string cardTime;
public:
	Card();
	string getCardName();
	string getCardNumber();
	string getCardTime();

	void setCardName(string name);
};