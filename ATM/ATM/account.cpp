// account cpp
#include "Account.h"

	/* Constructors */
Account::Account(){
	Money M;
	m = M;
	id = 532125; // 6 simvolov
}

Account::Account(string FIO, long Ident, int Pin, Money M){
	fio = FIO;
	id = Ident;
	pin = Pin;
	m = M;
}

	/* Set-metods */
void Account::setPin(int Pin){
	pin = Pin;
}

void Account::setFIO(string FIO){
	fio = FIO;
}

void Account::setCurr(string Curr){
	m.setCurrency(Curr);
}

void Account::setLimit(long limit){
	m.setLim(limit);
}

	/* Get-metods */
string Account::getFIO(){
	return fio;
}

Account Account::operator!(){
	this->m.setSum(0);
	return *this;
}

int Account::getPin(){
	return pin;
}

long Account::getIdent(){
	return id;
}

long Account::getBal(){
	return m.getSum();
}

long Account::getLimit(){
	return m.getLim();
}

string Account::getCurr(){
	return m.getCurrency();
}

	/* Other */
void Account::addMoney(long Sum){
	m.setSum(m.getSum() + Sum);
}

void Account::subMoney(long Sum){
	m.setSum(m.getSum() - Sum);
}

	