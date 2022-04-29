// Address.cpp

/**
 * Defenition of class Address. It is used to store and retrieve 
 * information on Address such as home number, street, apt#, city,
 * state, and zip.
 *
 * Author: Yosef Alayev
 */


#include "Address.h"
#include <string>
#include <iostream>

using namespace std;

Address::Address() : home(""),
                     street(""),
                     apt("none"),
                     city(""),
                     state(""),
                     zip("")
{
   // empty
}

string Address::getHome() const
{
   return home;
}

string Address::getStreet() const
{
   return street;
}

string Address::getApt() const
{
   return apt;
}

string Address::getCity() const
{
   return city;
}

string Address::getState() const
{
   return state;
}

string Address::getZip() const
{
   return zip;
}

std::ostream& operator <<(std::ostream& out, const Address& a){
   out << a.home << " " << a.street;
   if (a.apt != "none")
      out << ", Apt# " << a.apt;
   out << endl;
   out << a.city << ", " << a.state << " " << a.zip << endl;
   return out;
}

std::istream& operator >>(std::istream& in, Address& a){
   char choice;
   cout << "Apartment or House (a/h):> ";
   in >> choice;
   cout << endl;

   in.ignore(10, '\n');
   cout << "Enter home number (EX: 141-92)___: ";
   getline(in, a.home);
   cout << "Enter street number (EX: 70th RD): ";
   getline(in, a.street);
 
   if (choice == 'a')
   {
      cout << "Enter Apartment Number: (EX: 1A)_: ";
      getline(in, a.apt);
   }
   else
      a.apt = "none";

   cout << "Enter city (Ex: Flushing)________: ";
   getline(in, a.city);

   cout << "Enter state (EX: NY)_____________: ";  
   getline(in, a.state);

   cout << "Enter zip code (EX: 11367)_______: ";
   getline(in, a.zip);
   return in;
}

std::string Address::stringify() const {
	return home + "|" + street + "|" + apt + "|" + city + "|" + state + "|" + zip;
}

void Address::setAll(const std::string loadData) {
	using std::size_t;
	size_t location = loadData.find('|');
	home = loadData.substr(0, location);
	size_t location2 = loadData.find('|', location + 1);
	street = loadData.substr(location + 1, location2 - location - 1);
	size_t location3 = loadData.find('|', location2 + 1);
	apt = loadData.substr(location2 + 1, location3 - location2 - 1);
	size_t location4 = loadData.find('|', location3 + 1);
	city = loadData.substr(location3 + 1, location4 - location3 - 1);
	size_t location5 = loadData.find('|', location4 + 1);
	state = loadData.substr(location4 + 1, location5 - location4 - 1);
	size_t location6 = loadData.find('|', location5 + 1);
	zip = loadData.substr(location5 + 1, location6 - location5 - 1);
}

