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

friend std::ostream& operator <<(std::ostream& out, const Address& a){
   out << a.home << " " << a.street;
   if (a.apt != "none")
      out << ", Apt# " << a.apt;
   out << endl;
   out << a.city << ", " << a.state << " " << a.zip << endl;
}

friend std::istream& operator >>(std::istream& in, Address& a){
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
}
