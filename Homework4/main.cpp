#include <string>
#include <iostream>
#include <cctype>
#include "Contact.h"
//remove this contact when you implement Contactbook
#include "ContactBook.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

static const char COMMAND_ARRAY[] = {'a','b','c','d','e'};

static string command;
static bool CharCompare(const string&, char);
string SolicitInst(const string& text);
void PrintMenu();
int Search(const Contact*, const int);
void DisplayAll(const Contact*, const int);
void MenuQuit();

int main(){

	//menu
	do {
		PrintMenu();
		command = SolicitInst("enter option character");
		if (CharCompare(command,'q')){
			//option1
		}
		if (CharCompare(command,'w')){
			//option1
		}
		if (CharCompare(command,'e')){
			//option1
		}
		if (CharCompare(command,'r')){
			//option1
		}
		if (CharCompare(command,'t')){
			//option1
		}
		if (CharCompare(command,'z')){
			//option1
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
	cin >> result;
	return result;
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

bool CharCompare(const string& s, char a) {
	return (s[0] == a) || (s[0] == toupper(a) );
}
