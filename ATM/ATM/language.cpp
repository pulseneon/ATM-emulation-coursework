// Language.cpp
#include "Language.h"
#include "Database.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Language::Language(){
	languages[0] = "RU";
	languages[1] = "EN";
	languages[2] = "NL";
	languageName = languages[0];
}

string Language::getPath(){
	Database d;
	string path = d.getSettingsPath();
	ifstream file(path);
	if (!file){
		cout << "\nConfig file not found.\n" << "\n";
		system("pause");
	}

	string str;
	while (getline(file, str)){
		auto pos = str.find("|");
		if (pos != string::npos){
			string checkStr = str.substr(0, pos);
			string returnStr = str.substr(pos + 1);
			if (checkStr == languageName)
				return(returnStr);
		}
	}
	return("Error");
}

string Language::getString(string arg){
	string path = this->getPath();

	if (path != "Error"){
		ifstream file(path);
		if (!file){
			cout << "\nPath file not found.\n" << "\n";
			system("pause");
		}

		string str;
		while (getline(file, str)){
			auto pos = str.find("|");
			if (pos != string::npos){
				string checkStr = str.substr(0, pos);
				string returnStr = str.substr(pos + 1);
				if (checkStr == arg)
					return(returnStr);
			}
		}
	}

	else{
		cout << "\nPath find error.\n" << "\n";
		system("pause");
		return("Error");
	}
	return("String Error: <" + arg + "> ");
}

string Language::getLanguageName(){
	return languageName;
}

void Language::setLanguageName(string arg){
	languageName = arg;
}

void Language::changeLang(){
	system("cls");
	cout << getString("switch_lang_sharp") << "\n";
	cout << getString("switch_lang_name") << "\n";
	cout << "\n";
	cout << getString("switch_lang_all") << "\n";
	for (int i = 0; i < languagesNum; i++){
		cout << languages[i] << "; ";
	}
	cout << "\n";
	cout << getString("switch_lang_now") << languageName << "\n";
	cout << getString("switch_lang_sm") << "\n";
	string findLang;
	cin >> findLang;

	bool isFind = false;
	for (int i = 0; i < languagesNum; i++){
		if (findLang == languages[i]){
			setLanguageName(languages[i]);
			cout << getString("switch_lang_ok") << "\n";
			isFind = true;
			break;
		}
	}

	if (!isFind) cout << getString("switch_lang_er") << "\n";
	system("pause");
	system("cls");
}