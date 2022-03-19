#include <string>
#include <iostream>
#include "Contact.h"
#include "Address.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

static const int LIST_SIZE = 10;//POSITIVE NUMBER

static string command;
string SolicitInst(const string& text);
void PrintMenu();
int Search(const Contact*, const int);
void DisplayAll(const Contact*, const int);
void MenuQuit();

int main(){
	Contact contacts[LIST_SIZE];
	// initialization of list
	cout << "Prepopulate list with how many contacts?(1-10)";
	int j;
	cin >> j;
	if (j > 10)
		j = 10;
	if (j < 0)
		j == 0;
	do {
		int i = 0;
		if(j == i)
			break;
		contacts[i++].input("Doe", "Jane", "6543217890", "account1@protonmail.com");
		if(j == i)
			break;
		contacts[i++].input("Johnson", "Mavis", "1231234567", "account2@protonmail.com");
		if(j == i)
			break;
		contacts[i++].input("Hoover", "Harry", "6545434312", "account3@protonmail.com");
		if(j == i)
			break;
		contacts[i++].input("O'Keef", "Frank", "3456769098", "account4@protonmail.com");
		if(j == i)
			break;
		contacts[i++].input("Gott", "Maelk", "1234123443", "account5@protonmail.com");
		if(j == i)
			break;
		contacts[i++].input("Cornish", "Wess", "9431078899", "account6@protonmail.com");
		if(j == i)
			break;
		contacts[i++].input("Umbridge", "Hally", "4443335555", "account7@protonmail.com");
		if(j == i)
			break;
		contacts[i++].input("Ma", "Jack", "9871018832", "account8@protonmail.com");
		if(j == i)
			break;
		contacts[i++].input("Park", "Kenny", "6462127774", "account9@protonmail.com");
		if(j == i)
			break;
		contacts[i++].input("Pendleton", "Victor", "7189919192", "account10@prot.com");
	} while(false);


	int numContacts = j;
	command = SolicitInst("Would you like to enter remaining contacts? y/n");
	while ((numContacts < LIST_SIZE) && (command == "Y" || command == "y") ) { 
		cout << "ENTER CONTACTS FOR " << contacts[numContacts].getID() <<"\n";
		contacts[numContacts].input();
		numContacts++;
		command = SolicitInst("Continue entering contacts? Y/N");
	}
	//menu
	do {
		PrintMenu();
		command = SolicitInst("enter option character");
		if (command == "a" || command == "A"){
			int index = Search(contacts, numContacts);
			if (index == -1)
				cout << "Contact not found!" << endl;
			if (index >= 0)
				contacts[index].output();
		}
		if (command == "b" || command == "B")
			DisplayAll(contacts, numContacts);
		if (command == "e" || command == "E")
			MenuQuit();

	} while(true);
	return 0;
}

string SolicitInst(const string& text) {
	string result;
	cout << text << ": ";
	cin >> result;
	return result;
}

void PrintMenu() {
	cout 
		<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
		<< "          Main Menu" << endl
		<< " Select an option to continue:" << endl
		<< "   a. Search\n"
		<< "   b. Display All\n"
		<< "   e. Exit\n"
		<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

int Search(const Contact* list, const int size){
	string a, search;
	int signal; // 1 first, 2 l, both is 3
	do {
		a = SolicitInst("Search by first, last, or both names f/l/b");
	} while ( !(a == "f" || a == "l" || a == "b"));
	
	if (a == "f"){
		signal = 1;
		search = SolicitInst("enter first name");
	}
	if (a == "l"){
		signal = 2;
		search = SolicitInst("enter last name");
	}
	if (a == "b"){
		signal = 3;
		search = SolicitInst("enter first name then last name");
		string temp;
		cin >> temp;
		search += temp;
	}
	
	for (int i = 0; i < size; i++) {
		string s = "";
		if (signal % 2 == 1)
			s = list[i].getFirst();
		if (signal > 1)
			s += list[i].getLast();
		if (search == s) {
			return i;
		}
	}
	return -1;
}

void DisplayAll(const Contact* list, const int size){
	for (int i = 0; i < size; i++) {
		list[i].output();
	}
}

void MenuQuit(){
	exit(0);
}

