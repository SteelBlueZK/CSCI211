#include <string>
#include <iostream>
#include <cctype>
#include "ContactBook.h"
#include "BookMenu.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

int OpenMenu(ContactBook& book){
	string command;
	//menu
	bool menu = true;
	do {
		PrintMenu(book);
		command = SolicitInst("enter option character");
		if (CharCompare(command,'q')){
			AddContact(book);
		}
		if (CharCompare(command,'w')){
			DeleteContact(book);
		}
		if (CharCompare(command,'e')){
			DisplayContact(book);
		}
		if (CharCompare(command,'r')){
			UpdateContactInfo(book);
		}
		if (CharCompare(command,'t')){
			DisplayAll(book);
		}
		if (CharCompare(command,'z')){
			menu = false;
		}

	} while(menu);
	return 0;
}

void PrintMenu(const ContactBook& book) {
	cout << endl
		<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n"
		<< "         Contact Book menu" << "\n"
		<< "                 Name:" << "\n"
		<< " " << book.getFisrtName() << " " << book.getLastName() << "\n"
		<< " Select an option to continue:     " << "\n"
		<< "   q. Add New Contact\n"
		<< "   w. Delete Old Contact\n"
		<< "   e. Display Contact Info\n"
		<< "   r. Update Contact Info\n"
		<< "   t. Display Entire Contact List\n"
		<< "   z. Back\n"
		<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

string SolicitInst(const string& text) {
	string result;
	cout << text << ": ";
	std::getline(cin,result);
	return result;
}

bool CharCompare(const string& s, char a) {
	return (s[0] == a) || (s[0] == toupper(a) );
}

//menu options

void AddContact(ContactBook& b){
	b.addContact();
}

void DeleteContact(ContactBook& b){
	int v = SolicitName(b);
	b.deleteContact(v);
}

int SolicitName(ContactBook& b){
	string input, first, last;
	cout << "Enter last name: ";
	cin >> last;
	std::getline(cin,input);
	cout << "Enter first name: ";
	cin >> first;
	std::getline(cin,input);
	int j = b.find(first, last);
	return j;
}

void DisplayContact(ContactBook& b){
	int v = SolicitName(b);
	if (!b.display(v)){
		std::cout << "Contact not found in book!" << std::endl;
	}	
}

void UpdateContactInfo(ContactBook& b){
	int v = SolicitName(b);
	b.wizard(v);
}

void DisplayAll(ContactBook& b) {
	std::cout << b;
}

void MenuQuit(){
	exit(0);
}

