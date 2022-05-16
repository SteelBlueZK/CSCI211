#include "menu.h"
#include <string>
#include <iostream>
using namespace std;

string Menu::SolicitInst(const string& text) {
	string result;
	cout << text << ": ";
	std::getline(cin,result);
	return result;
}

bool Menu::CharCompare(const string& s, char a) {
	return (s[0] == a) || (s[0] == toupper(a) );
}

