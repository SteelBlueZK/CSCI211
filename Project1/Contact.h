#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include "Address.h"

class Contact {
	private:
		std::string nameLast;
		std::string nameFirst;
		Address address;
		std::string phone;
		std::string email;
		const int id;
		static int idGenerator; //should probably be a class with one and only one public function int getNextUniqueID() {} so that I couldn't possibly modify it in my code. but I ain't gonna submit more than this.
		
		static int GeneralComparison(const Contact& l, const Contact& r);
		
	public:
		//constructors
		Contact(std::string nameLast, std::string nameFirst, std::string phone, std::string email);
		// creates a contact with default initialization.
		Contact();

		//general functions
		//solicits user input to change data of contact.
		void wizard();
		void input(std::string nameLast, std::string nameFirst, std::string phone, std::string email);

		//set and get functs
		const std::string getFirst() const;
		const std::string getLast() const;
		const Address getAddr() const;
		const std::string getPhone() const;
		const std::string getEmail() const;
		const int getID() const;
		void setFirst(const std::string& set);
		void setLast(const std::string& set);
		void setAddr(const Address& set);
		void setPhone(const std::string& set);
		void setEmail(const std::string& set);
		std::string stringify();
		
		//statics
		static bool validatePhone(const std::string &num);
		static bool validateEmail(const std::string &num);

		//operators
		Contact& operator =(const Contact&);
		bool operator <(const Contact&);
		bool operator >(const Contact&);
		bool operator ==(const Contact&);
		bool operator !=(const Contact&);
		bool operator <=(const Contact&);
		bool operator >=(const Contact&);
		friend std::istream& operator >>(std::istream& in, Contact& c); // spits into console and takes input
		friend std::ostream& operator <<(std::ostream& out, const Contact& c); // spits into console
};
#endif

