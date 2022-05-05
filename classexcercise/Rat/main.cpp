#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include "Rat.h"

int main(){
	Rat r1, r2;
	Rat sum, dif, prod, quot;
	int compa;
	
	r1.input();
	r1.output();
	r2.input();
	r2.output();
	sum = r1.add(r2);
	dif = r1.sub(r2);
	prod = r1.mult(r2);
	quot = r1.div(r2);
	std::cout << "r1 + r2 = ";
	sum.output();
	std::cout << "\nr1 - r2 = ";
	dif.output();
	std::cout << "\nr1 * r2 = ";
	prod.output();
	std::cout << "\nr1 / r2 = ";
	quot.output();
	compa = Rat::compare(r1,r2);
	std::cout << "\nComparison is: " 
		<< compa;

	std::cout << "\nProgram end.\n";
	return 0;
}

