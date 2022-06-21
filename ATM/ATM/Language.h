// Language.h
#pragma once
#include <iostream>
using namespace std;

class Language{
                     
private:
	static const int languagesNum = 3;
	string languageName;
	string languages[languagesNum];
public:
	Language();
	string getString(string arg);
	string getPath();
	string getLanguageName();
	void changeLang();
	void setLanguageName(string arg);
};