#include <string>
#include <iostream>
#include "Contact.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main(){
	string loop;
	Contact 
		zero("Sirname", "Givenname", "123 Wallaby Way Sidney Australia", "1234567890", "givenname.sirname23@self.info"),
		one,
		two;
	one.setLast("Greene");
	one.setFirst("Matthew");
	one.setAddr("1 Great Street");
	one.setPhone("MyPhoneNumberLOL");
	one.setEmail("What could my email be? I don't remember.");
	cout << zero.getID() << zero.getFirst() << zero.getLast() 
		<< zero.getAddr() << zero.getPhone() 
		<< zero.getEmail() <<endl;
	one.Output();
	two.Output();
	do {
		Contact free;	
		free.Input();
		free.Output();
		
		cout << "Continue? Y/N";
		cin >> loop;
	} while (loop == "Y" || loop == "y");
	return 0;
}