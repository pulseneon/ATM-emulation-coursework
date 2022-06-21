// Interface.cpp
#pragma once
#include "Language.h"
#include "Database.h"

class Interface{
private:
	void alignCout(string &, char*);
	void getWindowSize(int &, int &);
public:
	Interface();
	void zastavka(Language&l);
	void auth(Language&l);
	void showAboutMe(Database&bd);
	void showHelp(Database&bd);
	void showSubjectArea(Database&bd);
};