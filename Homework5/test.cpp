#include <iostream>

#include "Contact.h"

int main(){
	std::string first("a"), second("z");
	std::cout << "baseline a compare z " << first.compare(second) << std::endl;
	Contact a,b;
	std::cout << "enter 2 contacts\n";
	std::cin >> a >> b;
	std::cout << "<  " << (a < b) << std::endl;
	std::cout << ">  " << (a > b) << std::endl;
	std::cout << "== " << (a == b) << std::endl;
	std::cout << "!= " << (a != b) << std::endl;
	std::cout << "<= " << (a <= b) << std::endl;
	std::cout << ">= " << (a >= b) << std::endl;
	return 0;
}
