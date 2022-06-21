// card.cpp
#pragma once
#include <iostream>
#include "Card.h"
using namespace std;

Card::Card(){
	cardNumber = "4890 4947 5490 6015";
	cardTime = "04/23";
	cardName = "Дебитовая карта";
}

string Card::getCardName(){
	return cardName;
}

string Card::getCardNumber(){
	return cardNumber;
}


string Card::getCardTime(){
	return cardTime;
}

void Card::setCardName(string name){
	cardName = name;
}
