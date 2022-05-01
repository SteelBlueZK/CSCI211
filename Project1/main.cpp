#include "BookMenu.h"
#include "ContactBook.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::ifstream;
using std::ofstream;


using BookMenu::CharCompare;
typedef ContactBook* ContCollection;

void PrintMenu();
void AddNewBook(ContCollection[]);
void RemoveOldBook(ContCollection[]);
void DisplayNames(ContCollection[]);
void DisplayAll(ContCollection[]);
void Merge(ContCollection[]);
void SelectBook(ContCollection[]);
void SaveToFile(ContCollection[]);
void loadFromFile(ContCollection[]);
bool Project1Exit(ContCollection[]);

static int DEFNUM = 5;
std::string FILENAME = "contactbooks.txt";

int main(){
	ContCollection Books[DEFNUM] = {NULL, NULL, NULL, NULL, NULL};
	loadFromFile(Books);
	//TODO
	//initialize five ContactBook object from file]
	//TODO
	//make ContCollection a real fucking class like ContactBook
	string command;
	bool breakloop = false;
	do {
		PrintMenu();
		command = BookMenu::SolicitInst("Enter Option Character");
		if (CharCompare(command,'q')){
			AddNewBook(Books);
		}
		if (BookMenu::CharCompare(command, 'w')) {
			RemoveOldBook(Books);
		}
		if (BookMenu::CharCompare(command, 'e')) {
			DisplayNames(Books);
		}
		if (BookMenu::CharCompare(command, 'r')) {
			DisplayAll(Books);
		}
		if (BookMenu::CharCompare(command, 't')) {
			Merge(Books);
		}
		if (BookMenu::CharCompare(command, 'y')) {
			SelectBook(Books);
		}
		if (BookMenu::CharCompare(command, 'z')) {
			breakloop = Project1Exit(Books);
		}
	} while (!breakloop);
	for (int i = 0; i < 5; i++) {
		if (Books[i] != NULL){
			delete Books[i];
		}
	}
	return 0;
}

void PrintMenu(){
	cout
		<< "==================================" << endl
		<< "             Main Menu\n"
		<< "              Options\n"
		<< "  q. Create New Contact Book\n"
		<< "  w. Remove a Contact Book\n"
		<< "  e. Display Contact Books\n"
		<< "  r. Display All Content in Books\n"
		<< "  t. Merge Two Contact Books\n"
		<< "  y. Select a Contact Book\n"
		<< "  z. Exit\n"
		<< "==================================" << endl;
}

void AddNewBook(ContCollection c[]){
	using BookMenu::SolicitInst;
	string name1, name2;
	name1 = SolicitInst("Input First name of Book owner");
	name2 = SolicitInst("Input Last name of Book Owner");
	for (int i = 0; i < DEFNUM; i++) {
		if (c[i] == NULL){
			c[i] = new ContactBook(name1, name2);
			cout << endl;
			return;
		}
	}
	cout << "No book added cause too many books" << endl;
}

void RemoveOldBook(ContCollection c[]){
	using BookMenu::SolicitInst;
	string name1, name2;
	name1 = SolicitInst("Delete book with first name");
	name2 = SolicitInst("Delete book with last name");
	for (int i = 0; i < DEFNUM; i++) {
		if (c[i] != NULL){
			if (c[i]->getFirstName().compare(name1) == 0 && c[i]->getLastName().compare(name2) == 0) {
				delete c[i];
				c[i] = NULL;
				return;
			}
		}
	}
	cout << "No book removed cause no book found" << endl;
}

void DisplayNames(ContCollection c[]){
	int count = 1;
	for (int i = 0; i < DEFNUM; i++) {
		if (c[i] != NULL){
			cout <<"Contact Book " << count++ << ": "
			       << c[i]->getLastName() << ", " 
			       << c[i]->getFirstName() << endl;
		}
	}
}

void DisplayAll(ContCollection c[]){
	for (int i = 0; i < DEFNUM; i++){
		if (c[i] != NULL){
			cout << *c[i];
		}
	}
}

void Merge(ContCollection c[]){
	using BookMenu::SolicitInst;
	int big = -1, second = -1;
	string namea1, namea2, nameb1, nameb2;
	namea1 = SolicitInst("Merge into Book First Name");
	namea2 = SolicitInst("Merge into Book Last Name");
	nameb1 = SolicitInst("With Contents of Book First Name");
	nameb2 = SolicitInst("With Contents of Book Last Name");
	for (int i = 0; i < DEFNUM; i++) {
		if (c[i] != NULL){
			if (c[i]->getFirstName().compare(namea1) == 0 && c[i]->getLastName().compare(namea2) == 0) {
				big = i;
			}
		}
	}
	for (int i = 0; i < DEFNUM; i++) {
		if (c[i] != NULL){
			if (c[i]->getFirstName().compare(nameb1) == 0 && c[i]->getLastName().compare(nameb2) == 0) {
				second = i;
			}
		}
	}
	if (big != -1 && second != -1){
		c[big]->Merge(*c[second]);
		cout << "Contacts of "<<c[second]->getFirstName()<<" "<<c[second]->getLastName()<<"'s book merged into "<<c[big]->getFirstName()<<" "<<c[big]->getLastName()<<"'s book." << endl;
		string secondfull = c[second]->getFirstName() + " " + c[second]->getLastName();
		string command = SolicitInst("Would you like to delete " + secondfull + "'s Contact Book? y/n" );
		if (BookMenu::CharCompare(command, 'y')) {
			delete c[second];
			c[second] = NULL;
			cout << secondfull << "'s ContactBook Deleted" << endl;
		}
	} else {
		cout << "Error finding at least one book!" << endl;
	}
}

void SelectBook(ContCollection c[]){
	using BookMenu::SolicitInst;
	string name1, name2;
	name1 = SolicitInst("search for Book First Name");
	name2 = SolicitInst("search for Book Last Name");
	for (int i = 0; i < DEFNUM; i++) {
		if (c[i] != NULL){
			if (c[i]->getFirstName().compare(name1) == 0 && c[i]->getLastName().compare(name2) == 0) {
				BookMenu::OpenMenu(*c[i]);
				return;
			}
		}
	}
	cout << "No Contact book with that name found" << endl;
}

void SaveToFile(ContCollection c[]){
	ofstream file;
	file.open(FILENAME);
	for (int i = 0; i < DEFNUM; i++) {
		if (c[i] != NULL){
			//TODO
			file << c[i]->stringify() << endl;
		}
	}
	file.close();
}

void loadFromFile(ContCollection cb[]) {
	ifstream file(FILENAME);
	string stringifiedcb = "";
	int inputsize(5000);
	char input[inputsize];
	int count = 0, errorcheck = 0;
	while (count < 5 && !file.eof()) {	
		stringifiedcb = "";
		do {
			file.getline(input, inputsize, '\n');
			stringifiedcb = stringifiedcb + input + "\n";
			//cout << varav++ << "  " << strcmp(input,"endofbook|")<< endl;
			//cout << stringifiedcb << endl;
			if (errorcheck > 10000) {
				cout << "Extrordinarilly long save data. quitting" << endl;
				exit(1);
			}
		} while ( strcmp(input,"endofbook|") != 0 && !file.eof());
		if (file.eof()) break;
		//cout << "creating ContactBook object and clearing string" << endl;
		cb[count] = new ContactBook();
		cb[count]->setAll(stringifiedcb);
		count++;
	}
	file.close();
}

bool Project1Exit(ContCollection cb[]){
	string command = BookMenu::SolicitInst("Would you like to save your changes? y/n");
	if (BookMenu::CharCompare(command, 'y')) {
		SaveToFile(cb);
		cout << "Changes successfully saved to " << FILENAME << endl;
		return true;
	}
	command = BookMenu::SolicitInst("Are you sure you want to exit without saving? y/n");
	if (BookMenu::CharCompare(command, 'y')) {
		cout << "Changes deleted! " << FILENAME << " not updated!" << endl;
		return true;
	}
	cout << "returning to menu..." << endl;
	return false;
}

