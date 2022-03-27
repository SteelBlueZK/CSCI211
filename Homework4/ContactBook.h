#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include <string>
#include "Contact.h"

class ContactBook {
	private:
		std::string fName;
		std::string lName;
		Contact contacts[10];
		static const int MAX_SIZE;
		int size;
	public:
		//constructors
		ContactBook();
		ContactBook(std::string first, std::string last);
		//interations
		bool addContact();
		bool addContact(Contact c);
		void display() const;
		int find(std::string first, std::string last) const;
		bool display(int v);
		bool deleteContact(int v);
		Contact* operator [](int v);
		//void Functions
};

#endif
