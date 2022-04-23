#include "ContactBook.h"
#include "Contact.h"
#include <iostream>
#include <string>

using std::string;

//constructors

ContactBook::ContactBook(){
	contacts = NULL;
	fName = "";
	lName = "";
	size = 0;
	MaxSize = 0;
}

ContactBook::ContactBook(string first, string last):
		fName(first), lName(last) {
	contacts = NULL;
	size = 0;
	MaxSize = 0;
}

//interations
bool ContactBook::addContact(){
	if(size >= MaxSize){
		Grow();
	}
	std::cin >> contacts[size];
	size++;
	return true;
}

bool ContactBook::addContact(Contact c){
	if(size >= MaxSize){
		Grow();
	}
	contacts[size] = c;
	size++;
	return true;
}

int ContactBook::find(string first, string last) const {
	for (int i = 0; i < size; i++) {
		if (contacts[i].getFirst().compare(first) == 0 && contacts[i].getLast().compare(last) == 0 )
			return i;
	}
	return -1;
}

bool ContactBook::display(int v) const {
	if (v > size - 1 || v < 0){
		return false;
	}
	std::cout << contacts[v];
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

ContactBook::ContactBook(const ContactBook& a) {
	size = a.size;
	MaxSize = a.MaxSize;
	fName = a.fName;
	lName = a.lName;
	if (a.contacts != NULL) {
		contacts = new Contact[MaxSize];
		for (int i = 0; i < size; i++) {
			contacts[i] = a.contacts[i];
		}
	} else {
		contacts = NULL;
	}
}

ContactBook::~ContactBook() {
	if (contacts != NULL) {
		delete [] contacts;
	}
}

const Contact& ContactBook::operator [](int v) const{
	if (v < 0 || v >= size) {
		std::cerr << "indexing contact that does not exist";
		exit(1);
	}
	return contacts[v];
}

ContactBook& ContactBook::operator =(const ContactBook& a) {
	if (this != &a) {
		if (contacts != NULL) {
			delete [] contacts;
			contacts = NULL;
		}
		size = a.size;
		MaxSize = a.MaxSize;
		if (MaxSize > 0)
			contacts = new Contact[MaxSize];
		if (a.contacts != NULL) {
			for (int i = 0; i < a.size; i++) {
				contacts[i] = a.contacts[i];
			}
		}
	}
	return *this;
}

void ContactBook::Grow(){
	MaxSize += 10;
	Contact* temp = new Contact[MaxSize];
	for (int i = 0; i < size; i++){
		temp[i] = contacts[i];
	}
	delete [] contacts;
	contacts = temp;
}

int ContactBook::getMaxSize() const {
	return MaxSize;
}

int ContactBook::getSize() const{
	return size;
}

std::string ContactBook::getFisrtName() const{
	return fName;
}

std::string ContactBook::getLastName() const{
	return lName;
}

std::ostream& operator <<(std::ostream& out, const ContactBook& a){
	out << "Contact Book of " << a.lName << ", " << a.fName << std::endl; 
	for (int i = 0; i < a.size; i++) {
		out 	<< "Contact " << i+1 << ":" << std::endl
			<< a[i];
	}
	return out;
}

std::istream& operator >>(std::istream& in, ContactBook& a){
	std::cerr << "TODO: make >> operator for ContactBook sensible";
	exit(1);
}

