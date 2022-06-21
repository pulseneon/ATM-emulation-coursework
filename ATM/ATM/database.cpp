// database.cpp
#include "Database.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Database::Database() {};

string Database::getSettingsPath(){
	return settingsPath;
}

string Database::getPath(string path){
	ifstream file(settingsPath);
	if (!file){
		cout << "\nConfig file not found.\n" << "\n";
		system("pause");
		return("Error.");
	}

	string str;
	while (getline(file, str)){
		auto pos = str.find("|");
		if (pos != string::npos){
			string checkStr = str.substr(0, pos);
			string returnStr = str.substr(pos + 1);
			if (checkStr == path)
				return(returnStr);
		}
	}
}

void Database::createFileLogs(){
	string operPath = getPath("Operations");
	ofstream ost(operPath); // create file
}

void Database::addLogOperation(string type){
	string path = getPath("Operations");
	ofstream file(path, ios::app);
	if (!file){
		cout << "\nWrite file error.\n" << "\n";
		system("pause");
		return;
	}
	file << type << "\n";
	file.close();
}

void Database::readLogOperation(){
	string path = getPath("Operations");
	ifstream file(path);
	if (!file){
		cout << "\nConfig file not found.\n" << "\n";
		system("pause");
	}

	string str;
	while (getline(file, str)){
		cout << str << "\n";
	}
}

void Database::showCardsFile(int amount){
	string path = getPath("Cards");
	ifstream file(path);
	if (!file){
		cout << "\nConfig file not found.\n" << "\n";
		system("pause");
		return;
	}

	if (amount == -1){ // вывод всего
		string str;
		while (getline(file, str)){
			cout << " " << str << "\n";
		}
	}

	else{
		for (int i = 0; i < amount; i++){
			string str;
			getline(file, str);
			cout << " " << str << "\n";
		}
	}
}

void Database::showCardsFile(){
	string path = getPath("Cards");
	ifstream file(path);
	if (!file){
		cout << "\nConfig file not found.\n" << "\n";
		system("pause");
		return;
	}
	string str;
	int i = 1;
	system("cls");
	while (getline(file, str)){
		cout << to_string(i) + ". " << str << "\n";
		i++;
	}
}

void Database::readTxt(string type){
	string path = getPath(type);
	ifstream file(path);
	if (!file){
		cout << "\nConfig file not found.\n" << "\n";
		system("pause");
		return;
	}
	string str;
	while (getline(file, str)){
		cout << str << "\n";
	}
}

bool Database::findCard(string desired){
	string path = getPath("Cards");
	ifstream file(path);
	if (!file){
		cout << "\nConfig file not found.\n" << "\n";
		system("pause");
		return false;
	}

	string str;
	while (getline(file, str)){
		if (str == desired)
			return true;
	}
	return false;
}