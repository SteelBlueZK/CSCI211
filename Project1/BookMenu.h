#ifndef BOOKMENU_H
#define BOOKMENU_H

#include <string>
#include <iostream>
#include <cctype>
#include "ContactBook.h"

// fine place to use a namespace
namespace BookMenu {
	bool CharCompare(const std::string&, char);
	
	std::string SolicitInst(const std::string& text);
	int SolicitName(ContactBook&);
	void PrintMenu(const ContactBook& book);
	int Search();

	void AddContact(ContactBook&);
	void DeleteContact(ContactBook&);
	void DisplayContact(ContactBook&);
	void UpdateContactInfo(ContactBook&);
	void DisplayAll(ContactBook&);
	void MenuQuit();
	
	int OpenMenu(ContactBook& book);
}

#endif
