#include <string>
#include <iostream>
#include <cctype>
#include "Contact.h"
#include "ContactBook.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

static bool CharCompare(const string&, char);

string SolicitInst(const string& text);
int SolicitName(ContactBook&);
void PrintMenu();
int Search();

void AddContact(ContactBook&);
void DeleteContact(ContactBook&);
void DisplayContact(ContactBook&);
void UpdateContactInfo(ContactBook&);
void DisplayAll(ContactBook&);
void MenuQuit();

int main(){
	string command;
	ContactBook book("Joe", "Dirt");
	//menu
	do {
		PrintMenu();
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
			MenuQuit();
		}

	} while(true);
	return 0;
}

void PrintMenu() {
	cout 
		<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
		<< "            Main Menu" << endl
		<< " Select an option to continue:     " << endl
		<< "   q. Add New Contact\n"
		<< "   w. Delete Old Contact\n"
		<< "   e. Display Contact Info\n"
		<< "   r. Update Contact Info\n"
		<< "   t. Display Entire Contact List\n"
		<< "   z. Exit\n"
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
	Contact a;
	cin >> a;
	b.addContact(a);
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
	b.display();
}

void MenuQuit(){
	exit(0);
}

