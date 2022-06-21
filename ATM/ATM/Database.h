// Database.h
#pragma once
#include <iostream>
using namespace std;

class Database{
private:
	const string settingsPath = "D:\\course work list\\Config.txt";
	friend class Language;
public:
	Database();
	string getSettingsPath();
	string getPath(string path);
	void addLogOperation(string type);
	void readLogOperation();
	void readTxt(string path);
	void createFileLogs();
	void showCardsFile();
	void showCardsFile(int amount);
	bool findCard(string desired);
};