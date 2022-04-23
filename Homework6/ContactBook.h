#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include <string>
#include "Contact.h"

class ContactBook {
	private:
		std::string fName;
		std::string lName;
		Contact* contacts;
		int MaxSize;
		int size;

		void Grow();
	public:
		//constructors
		ContactBook();

		//sets the first parameter as the first name, 2nd paramerter as the last name.
		ContactBook(std::string first, std::string last);

		ContactBook(const ContactBook&);
		
		~ContactBook();
		//interations

		int getMaxSize() const;
		int getSize() const;
		std::string getFisrtName() const;
		std::string getLastName() const;

		//return true if contact successfully inserted. 
		bool addContact();
		bool addContact(Contact c);
		
		//returns int identifier for a contact of firstnamelastname. 
		int find(std::string first, std::string last) const;
		
		//prints identified contact.
		bool display(int v) const;
		
		//deletes itdentified contact.
		bool deleteContact(int v);
		
		//Mutates identified contact by user cin input.
		bool wizard(int v);
		//overload operators
		ContactBook& operator =(const ContactBook&);
		const Contact& operator [](int v) const;
		friend std::ostream& operator <<(std::ostream& out, const ContactBook&);
		friend std::istream& operator >>(std::istream& in, ContactBook&);
};

#endif
