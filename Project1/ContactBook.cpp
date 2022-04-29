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

//precondition, all poionters in array after size-1 index are NULL
bool ContactBook::addContact(){
	if(size >= MaxSize){
		Grow();
	}
	//TODO make sure I'm not fucking memory leaking here
	contacts[size] = new Contact();
	std::cin >> *contacts[size];
	size++;
	return true;
}

//precondition, all poionters in array after size-1 index are NULL
bool ContactBook::addContact(Contact c){
	if(size >= MaxSize){
		Grow();
	}
	//TODO make sure I'm not fucking memory leaking here
	contacts[size] = new Contact(c);
	size++;
	return true;
}

int ContactBook::find(string first, string last) const {
	for (int i = 0; i < size; i++) {
		if (contacts[i]->getFirst().compare(first) == 0 && contacts[i]->getLast().compare(last) == 0 )
			return i;
	}
	return -1;
}

bool ContactBook::display(int v) const {
	if (v > size - 1 || v < 0){
		return false;
	}
	std::cout << *contacts[v];
	return true;
}

bool ContactBook::deleteContact(int v){
	if (v < 0 || v >= size) {
		std::cout << "Contact not found in book!" << v << std::endl;
		return false;
	}
	delete contacts[v];
	contacts[v] = contacts[size-1];
	contacts[size-1] = NULL;
	size--;
	return true;
}

bool ContactBook::wizard(int v) {
	if (v < 0 || v >= size) {
		std::cout << "Contact not found in book!" << v << std::endl;
		return false;
	}
	contacts[v]->wizard();
	return true;
}

//precondition, this->contacts is null.
void ContactBook::CopyContacts(const ContactBook& a){
	size = a.size;
	MaxSize = a.MaxSize;
	if (a.contacts != NULL) {
		contacts = new Contact*[MaxSize];
		for (int i = 0; i < size; i++) {
			if (a.contacts[i] != NULL) {
				contacts[i] = new Contact(*(a.contacts[i]));
			} else {
				contacts[i] = NULL;
			}
		}
	}
}

ContactBook::ContactBook(const ContactBook& a) {
	fName = a.fName;
	lName = a.lName;
	CopyContacts(a);
}

void ContactBook::NullContacts(){
	if (contacts != NULL) {
		for (int i = 0; i < MaxSize; ++i) {
			if (contacts[i] != NULL) {
				delete contacts[i];
				contacts[i] = NULL;
			}
		}
		delete [] contacts;
	}
}

ContactBook::~ContactBook() {
	NullContacts();
}

const Contact& ContactBook::operator [](int v) const{
	if (v < 0 || v >= size) {
		std::cerr << "indexing contact that does not exist";
		exit(1);
	}
	return *contacts[v];
}

ContactBook& ContactBook::operator =(const ContactBook& a) {
	if (this != &a) {
		NullContacts();
		if (a.contacts != NULL)
			CopyContacts(a);
	}
	return *this;
}

void ContactBook::Grow(int x){
	MaxSize += x;
	Contact** temp = new Contact*[MaxSize];
	for (int i = 0; i < size; i++){
		temp[i] = contacts[i];
	}
	for (int i = size; i < MaxSize; i++) {
		temp[i] = NULL;
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
			<< *(a.contacts[i]);
	}
	return out;
}

std::istream& operator >>(std::istream& in, ContactBook& a){
	std::cerr << "TODO: make >> operator for ContactBook sensible";
	exit(1);
}

std::string ContactBook::stringify() const {
	std::string returnvalue = fName +"|"+ lName +"\n";
	for (int i = 0; i < size; ++i) {
		returnvalue.append(contacts[i]->stringify() + "\n");
	}
	returnvalue.append("endofbook|\n");
	return returnvalue;
}

void ContactBook::SelectionSort() {
	int temp;
	Contact *store;
	for (int i = 0; i < size; i++){
		temp = i;
		for (int j = i + 1; j < size; j++) {
			if (*contacts[j] < *contacts[temp]) {
				temp = j;
			}
		}
		if (temp != i){
			store = contacts[temp];
			contacts[temp] = contacts[i];
			contacts[i] = store;
		}
	}
}

