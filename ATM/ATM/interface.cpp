// Interface.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Interface.h"
#include <string>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
using namespace std;

Interface::Interface(){}

void Interface::zastavka(Language&l){
	alignCout(l.getString("zastavka_name"), "center");
	alignCout(l.getString("zastavka_fac"), "left");
	alignCout(l.getString("zastavka_kaf"), "left");
	cout << "" << "\n";
	cout << "" << "\n";
	cout << "" << "\n";
	cout << "" << "\n";
	cout << "" << "\n";
	alignCout(l.getString("zastavka_curs"), "center");
	alignCout(l.getString("zastavka_disciplina"), "center");
	alignCout(l.getString("zastavka_tema"), "center");
	cout << "" << "\n";
	cout << "" << "\n";
	cout << "" << "\n";
	cout << l.getString("zastavka_rucovoditel");
	alignCout(l.getString("zastavka_vipolnil"), "longcenter");
	cout << l.getString("zastavka_prepod");
	alignCout(l.getString("zastavka_student"), "longcenter");
	cout << l.getString("zastavka_morozova");
	alignCout(l.getString("zastavka_rudnev"), "longcenter");
	cout << l.getString("zastavka_assistent") << "\n";
	cout << l.getString("zastavka_artemenko");
	cout << "" << "\n";
	cout << "" << "\n";
	cout << "" << "\n";
	alignCout(l.getString("zastavka_doneck"), "center");
	cout << "" << "\n";
	cout << "" << "\n";
	cout << "" << "\n";
	cout << l.getString("zastavka_start");
	alignCout(l.getString("zastavka_lang"), "longcenter");
	cout << l.getString("zastavka_help");
	alignCout(l.getString("zastavka_about_prog"), "longcenter");
	cout << l.getString("zastavka_exit");
	alignCout(l.getString("zastavka_about_author"), "longcenter");
}

void Interface::showAboutMe(Database&bd){
	system("cls");
	bd.readTxt("About me");
	cout << "\n";
	system("pause");
}

void Interface::showHelp(Database&bd){
	system("cls");
	bd.readTxt("Help");
	cout << "\n";
	system("pause");
}

void Interface::showSubjectArea(Database&bd){
	system("cls");
	bd.readTxt("Subject Area");
	cout << "\n";
	system("pause");
}

/////////////////////////////////////////////////////////////////

void Interface::alignCout(string &s, char *type){
	int buffer_x_size, buffer_y_size;
	size_t width = s.length();
	size_t bord = 0;
	getWindowSize(buffer_x_size, buffer_y_size);
	if (strcmp("right", type) == 0) bord = (buffer_x_size - width);
	if (strcmp("center", type) == 0) bord = (buffer_x_size - width) / 2;
	if (strcmp("longcenter", type) == 0) bord = (buffer_x_size - width) / 1.2;
	for (;;)
	{
		cout << setw(bord) << "";
		cout << s.substr(0u, width) << "\n";
		s.erase(s.begin(), s.begin() + (s.size() < width ? s.size() : width));
		if (s.empty())
		{
			break;
		}
	}
}

void Interface::getWindowSize(int &x, int &y){
	HANDLE hWndConsole;
	if (hWndConsole = GetStdHandle(-12))
	{
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
		{
			x = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
			y = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
		}
		else
			printf("Error: %d\n", GetLastError());
	}
	else
		printf("Error: %d\n", GetLastError());
}