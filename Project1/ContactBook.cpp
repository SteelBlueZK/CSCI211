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

ContactBook::ContactBook(const ContactBook& a) {
	fName = a.fName;
	lName = a.lName;
	contacts = NULL;
	CopyContacts(a);
}

ContactBook::ContactBook(std::string loadData) {
	using std::size_t;
	contacts = NULL;
	size = 0;
	MaxSize = 0;
	//end of the simple part
	size_t last, curr;
	last = 0;
	curr = loadData.find('|', last);
	fName = loadData.substr(last, curr - last);
	last = curr + 1;
	curr = loadData.find('\n', last);
	lName = loadData.substr(last, curr - last);
	last = curr + 1;
	Contact c;
	while (loadData.substr(last).compare("endofbook|") != 0) {
		//std::cout << loadData.substr(last).length() << std::endl;
		if (loadData.substr(last).length() <= 11) {
			//std::cerr << "FAILURE IN LOADING CONTACTBOOK FROM STRING";
			//scuffed
			break;
		}
		curr = loadData.find('\n', last);
		string stringc(loadData.substr(last, curr - last));
		//std::cout <<"stringified thing to set" << stringc << std::endl;
		c.setAll(stringc);
		addContact(c);
		last = curr + 1;
	}
	SelectionSort();
}

//precondition, all poionters in array after size-1 index are NULL
bool ContactBook::addContact(){
	Contact c;
	std::cin >> c;
	return addContact(c);
}

//precondition, all poionters in array after size-1 index are NULL
bool ContactBook::addContact(Contact c){
	if(size >= MaxSize){
		Grow();
	}
	//TODO make sure I'm not fucking memory leaking here
	Contact* insert = new Contact(c);
	Contact* temp;
	int x(-1);
	for (int i = size-1; i >= 0; i-- ){
		if (*insert < *contacts[i]) {
			x = i;
		}
	}
	if (x == -1) {
		contacts[size] = insert;
	} else {
		for (int i = x; i < size + 1; i++){
			temp = contacts[i];
			contacts[i] = insert;
			insert = temp;
		}
	}
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
	for (int i = v; i < size - 1; i++){
		contacts[i] = contacts[i+1];
	}
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
	size = 0;
	MaxSize = 0;
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
	if (contacts != NULL)
		delete [] contacts;
	contacts = temp;
}

int ContactBook::getMaxSize() const {
	return MaxSize;
}

int ContactBook::getSize() const{
	return size;
}

std::string ContactBook::getFirstName() const{
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
	returnvalue.append("endofbook|");
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

void ContactBook::setAll(std::string loadData){
	using std::size_t;
	NullContacts();
	//end of the simple part
	size_t last, curr;
	last = 0;
	curr = loadData.find('|', last);
	fName = loadData.substr(last, curr - last);
	last = curr + 1;
	curr = loadData.find('\n', last);
	lName = loadData.substr(last, curr - last);
	last = curr + 1;
	Contact c;
	while (loadData.substr(last).compare("endofbook|") != 0) {
		//std::cout << loadData.substr(last).length() << std::endl;
		if (loadData.substr(last).length() <= 11) {
			//std::cerr << "FAILURE IN LOADING CONTACTBOOK FROM STRING";
			//scuffed
			break;
		}
		curr = loadData.find('\n', last);
		string stringc(loadData.substr(last, curr - last));
		//std::cout <<"stringified thing to set" << stringc << std::endl;
		c.setAll(stringc);
		addContact(c);
		last = curr + 1;
	}
	SelectionSort();
}

bool ContactBook::Merge(const ContactBook& cb){
	if (MaxSize - size < cb.size) {
		Grow(cb.size);
	}
	for (int i = 0; i < cb.size; i++) {
		addContact(cb[i]);
	}
	return true;
}

