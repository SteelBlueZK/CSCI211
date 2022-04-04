#include "ContactBook.h"
#include "Contact.h"
#include <iostream>
#include <string>

using std::string;

const int ContactBook::MAX_SIZE = 10;


//constructors

ContactBook::ContactBook(){
	fName = "";
	lName = "";
	size = 0;
}

ContactBook::ContactBook(string first, string last){
	fName = first;
	lName = last;
	size = 0;
}

//interations
bool  ContactBook::addContact(){
	return false;
}

bool ContactBook::addContact(Contact c){
	if(size >= MAX_SIZE){
		std::cerr << "you added a contact to a full contactbook, idiot";
		exit(1);// could return false....
	}
	contacts[size] = c;
	size++;
	return true;
}

void ContactBook::display() const{
	for (int i = 0; i < size; i++) {
		cout << contacts[i];
	}
}

int ContactBook::find(string first, string last) const {
	for (int i = 0; i < size; i++) {
		if (contacts[i].getFirst().compare(first) == 0 && contacts[i].getLast().compare(last) == 0 )
			return i;
	}
	return -1;
}

bool ContactBook::display(int v){
	if (v > size - 1 || v < 0){
		return false;
	}
	cout << contacts[v];
	return true;
}

bool ContactBook::deleteContact(int v){
	if (v < 0 || v >= size) {
		std::cout << "Contact not found in book!" << v << std::endl;
		return false;
	}
	contacts[v] = contacts[size-1];
	size--;
	return true;
}

bool ContactBook::wizard(int v) {
	if (v < 0 || v >= size) {
		std::cout << "Contact not found in book!" << v << std::endl;
		return false;
	}
	contacts[v].wizard();
	return true;
}
