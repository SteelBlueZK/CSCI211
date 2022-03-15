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

int main(){
	Contact contacts[LIST_SIZE];
	int numContacts = 0;
	do {
		cout << "ENTER CONTACTS FOR "<< contacts[numContacts].getID() <<"\n";
		contacts[numContacts].input();
		command = SolicitInst("Continue entering contacts? Y/N");
		numContacts++;
	} while (numContacts < LIST_SIZE && (command == "Y" || command == "y") ); 
	//menu
	cout 
		<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
		<< "          Main Menu" << endl
		<< " Select an option to continue:" << endl
		<< "   a. Search\n"
		<< "   b. Display All\n"
		<< "   e. Exit\n"
		<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	command = SolicitInst("enter option character");

	return 0;
}

string SolicitInst(const string& text) {
	string result;
	cout << text << ": ";
	cin >> result;
	return result;
}
