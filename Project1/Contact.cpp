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

std::istream& operator >>(std::istream& in, Contact& c) { // spits into console and takes input
	string input;
	cout << "Input for contact number " << c.id << endl
		<< "Input First Name: ";
	std::getline(cin, input);
	c.setFirst(input);
	cout << "Input Last Name: ";
	std::getline(cin, input);
	c.setLast(input);
	cout << "Input Address: ";
	cin >> c.address;
	cout << "Input Phone Number(10 digits): ";
	std::getline(cin, input);
	c.setPhone(input);
	cout << "Input email(example@website.com): ";
	std::getline(cin, input);
	c.setEmail(input);
	return in;
}

std::ostream& operator <<(std::ostream& out, const Contact& c) { // spits into console
	cout 	<< "Name: " << c.nameLast << ", " << c.nameFirst << endl
		<< "Address: " << c.address;
	if (c.validatePhone(c.phone))
		cout << "Phone Contact: " << c.phone << endl;
	else
		cout << "Phone number invalid!" << endl;
	if (c.validateEmail(c.email))
		cout << "Email Contact: " << c.email << endl;
	else
		cout << "Email invalid!" << endl;
	cout << endl;
	return out;
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

Contact& Contact::operator =(const Contact& c) {
	nameLast = c.nameLast;
	nameFirst = c.nameFirst;
	address = c.address;
	phone = c.phone;
	email = c.email;
	return *this;
}

void Contact::wizard(){
	cout << *this;
	string i;
	cout << "Would you like to update first name? y/n: ";
	std::getline(cin,i);
	if (i == "y" || i == "Y") {
		cout << "enter first: ";
		std::getline(cin,i);
		setFirst(i);
	}
	cout << "Would you like to update last name? y/n: ";
	std::getline(cin,i);
	if (i == "y" || i == "Y") {
		cout << "enter last: ";
		std::getline(cin,i);
		setLast(i);
	}
	cout << "Would you like to update Address? y/n: ";
	std::getline(cin,i);
	if (i == "y" || i == "Y") {
		cout << "enter address \n";
		Address a;
		cin >> a;
		setAddr(a);
	}
	cout << "Would you like to update phone? y/n: ";
	std::getline(cin,i);
	if (i == "y" || i == "Y") {
		cout << "enter phone: ";
		std::getline(cin,i);
		setPhone(i);
	}
	cout << "Would you like to update email address? y/n: ";
	std::getline(cin,i);
	if (i == "y" || i == "Y") {
		cout << "enter email: ";
		std::getline(cin,i);
		setEmail(i);
	}
}

int Contact::GeneralComparison(const Contact& l, const Contact& r) {
	int value;
	value = l.nameLast.compare(r.nameLast);
	if (value == 0)
		value = l.nameFirst.compare(r.nameFirst);
	return value;
}

bool Contact::operator <(const Contact& c){
	return GeneralComparison(*this,c) < 0;
}

bool Contact::operator >(const Contact& c){
	return GeneralComparison(*this,c) > 0;
}

bool Contact::operator ==(const Contact& c){
	return GeneralComparison(*this,c) == 0;
}

bool Contact::operator !=(const Contact& c){
	return GeneralComparison(*this,c) != 0;
}

bool Contact::operator <=(const Contact& c){
	return GeneralComparison(*this,c) <= 0;
}

bool Contact::operator >=(const Contact& c){
	return GeneralComparison(*this,c) >= 0;
}

std::string Contact::stringify(){
	std::string result = nameFirst + "|" + nameLast + "|" + phone + "|" + email + "|" + address.stringify();
	return result;
}

