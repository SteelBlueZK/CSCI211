#ifndef CONTACT_H
#define CONTACT_H

#include <string>
using std::string;

class Contact {
	private:
		string nameLast;
		string nameFirst;
		string address;
		string phone;
		string email;
		const int id;
		static int idGenerator; //should probably be a class with one and only one public function int getNextUniqueID() {} so that I couldn't possibly modify it in my code. but I ain't gonna submit more than this.
		
	public:
		//constructors
		Contact(string nameLast, string nameFirst, string address, string phone, string email);
		Contact();

		//general functions
		void Input(); // spits into console and takes input
		void Output() const; // spits into console

		//set and get functs
		const string getFirst() const;
		const string getLast() const;
		const string getAddr() const;
		const string getPhone() const;
		const string getEmail() const;
		const int getID() const;
		void setFirst(const string& set);
		void setLast(const string& set);
		void setAddr(const string& set);
		void setPhone(const string& set);
		void setEmail(const string& set);
		
		//statics
		static bool validatePhone(const string &num);
		static bool validateEmail(const string &num);
};
#endif