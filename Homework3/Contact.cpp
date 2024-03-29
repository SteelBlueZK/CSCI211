#include <string>
#include <iostream>
#include <ctype.h>
#include "Contact.h"
#include "Address.h"

using std::cin;
using std::cerr;
using std::cout;
using std::string;
using std::endl;

const string topLevelDomain[5] = {".gov", ".edu", ".org", ".com", ".net" };

int Contact::idGenerator = 1;

//constructors
Contact::Contact(string a, string b, string d, string e) : id(Contact::idGenerator) {
	Contact::idGenerator += 1;
	setLast(a);
	setFirst(b);
	setPhone(d);
	setEmail(e);
	setAddr(Address());
	//Blank;
}

Contact::Contact() : id(Contact::idGenerator) {
	Contact::idGenerator += 1;
	setLast("N/A");
	setFirst("N/A");
	setAddr(Address());
	phone = "N/A";
	email = "N/A";
	//blank;
}

void Contact::input() { // spits into console and takes input
	string input;
	cout << "Input for contact number " << id << endl
		<< "Input First Name: ";
	cin >> input;
	setFirst(input);
	cout << "Input Last Name: ";
	cin >> input;
	setLast(input);
	cout << "Input Address: ";
	address.input();
	cout << "Input Phone Number(10 digits): ";
	cin >> input;
	setPhone(input);
	cout << "Input email(example@website.com): ";
	cin >> input;
	setEmail(input);
}

void Contact::output() const { // spits into console
	cout << "Contact ID: " << id << endl
		<< "Name: " << nameFirst << " " << nameLast << endl
		<< "Address: ";
	address.output();
	if (validatePhone(phone))
		cout << "Phone Contact: " << phone << endl;
	else
		cout << "Phone number invalid!" << endl;
	if (validateEmail(email))
		cout << "Email Contact: " << email << endl;
	else
		cout << "Email invalid!" << endl;
	cout << endl;
}

void Contact::input(string a, string b, string d, string e) {
	setLast(a);
	setFirst(b);
	setPhone(d);
	setEmail(e);
	setAddr(Address());
}

const string Contact::getFirst() const {
	return nameFirst;
}

const string Contact::getLast() const {
	return nameLast;
}

const Address Contact::getAddr() const {
	return address;
}

const string Contact::getPhone() const {
	return phone;
}

const string Contact::getEmail() const {
	return email;
}

const int Contact::getID() const {
	return id;
}

void Contact::setFirst(const string& set) {
	nameFirst = set;
}

void Contact::setLast(const string& set) {
	nameLast = set;
}

void Contact::setAddr(const Address& set) {
	address = set;
}

void Contact::setPhone(const string& set) {
	if(!Contact::validatePhone(set)) {
		cerr << "Contact id#[" << id << "] set to invalid phone number!" << endl;
	}
	phone = set;
}

void Contact::setEmail(const string& set) {
	if(!Contact::validateEmail(set)) {
		cerr << "Contact id#[" << id << "] set to invalid email!" << endl;
	}
	email = set;
}

bool Contact::validatePhone(const string &num){
	string::const_iterator iter, iterEnd;
	iter = num.begin();
	iterEnd = num.end();
	while (iter != iterEnd){
	//	*iter.isDigit
		if (!isdigit(*iter)) {
			return false;
		}
		iter++;
	}
	return num.length() == 10;
}

bool Contact::validateEmail(const string &num){
	string::const_iterator front, end, temp;
	string last4;
	front = num.begin();
	end = num.end();
	while ( isalnum(*front) || *front == '.' ) {
		front++;
	}
	if (*front != '@'){
		return false;
	}
	front++;//char after '@'
	temp = end - 4;
	while (temp != end){
		last4 = last4 + *temp;
		temp++;
	}
	for(string s : topLevelDomain ) {
		if ( s == last4 && front < end - 4){
			while ( isalnum(*front) || *front == '.' ) {
				front++;
			}
			return front == end;
		}
	}
	return false;
}

