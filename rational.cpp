#include <iostream>
#include <string>

struct Rat {
	int numerator;
	int denomonator;
};

void input(int r[]) {
	std::cout << "Please enter numerator: ";
	std::cin >> r[0];	
	std::cout << "\n" << "Please enter denominator: ";
	std::cin >> r[1];	
}

Rat input(Rat& var) {	
	std::cout << "Please enter numerator: ";
	std::cin >> var.numerator;	
	std::cout << "\n" << "Please enter denominator: ";
	std::cin >> var.denomonator;
	return var;
}
Rat input() {	
	Rat var;
	std::cout << "Please enter numerator: ";
	std::cin >> var.numerator;	
	std::cout << "\n" << "Please enter denominator: ";
	std::cin >> var.denomonator;
	return var;
}

void output(int r[]){
	std::cout << "Your rational number is:\n"
	       	<< r[0] << " / " << r[1] << std::endl;
}
Rat& output(Rat &r){	
	std::cout << "Your rational number is:\n"
	       	<< r.numerator << " / " << r.denomonator << std::endl;
	return r;
}
int lcm(int a, int b){
	/*if (a < 1 || b < 1) {
		return -1;
	}*/
	int amult = a, bmult = b;
	while (amult != bmult){
		if (amult > bmult) {
			bmult = bmult + b;
		} else {
			amult = amult + a;
		}
	}
	return amult;
}
int lcm(Rat r){
	int amult = r.numerator, bmult = r.denomonator;
	while (amult != bmult){
		if (amult > bmult) {
			bmult = bmult + r.denomonator;
		} else {
			amult = amult + r.numerator;
		}
	}
	return amult;
}
int gcf(int a, int b) {
	return (a * b) / lcm(a,b);
}
int gcf(Rat r) {
	return (r.numerator * r.denomonator) / lcm(r);
}

void reduce(int r[]){
	int x = gcf(r[0],r[1]);
	r[0] = r[0] / x;
	r[1] = r[1] / x;
}
Rat reduce(Rat r){
	int x = gcf(r);
	r.numerator = r.numerator / x;
	r.denomonator = r.denomonator / x;
	return r;
}
void add(int ret[], int r1[], int r2[]) {
	ret[1] = lcm(r1[1],r2[1]);
	ret[0] = (r1[0]*(ret[1]/r1[1])) + (r2[0]*(ret[1]/r2[1]));
	reduce(ret);
}
Rat add(Rat r1, Rat r2) {
	Rat ret;
	ret.denomonator = lcm(r1.denomonator , r2.denomonator);
	ret.numerator = ( r1.numerator * ( ret.denomonator / r1.denomonator) ) + ( r2.numerator * ( ret.denomonator / r2.denomonator ));
	return reduce(ret);
}
void sub(int ret[], int r1[], int r2[]) {
	ret[1] = lcm(r1[1],r2[1]);
	ret[0] = (r1[0]*(ret[1]/r1[1])) - (r2[0]*(ret[1]/r2[1]));
	reduce(ret);
}
Rat sub(Rat r1, Rat r2) {
	Rat ret;
	ret.denomonator = lcm(r1.denomonator , r2.denomonator);
	ret.numerator = ( r1.numerator * ( ret.denomonator / r1.denomonator) ) - ( r2.numerator * ( ret.denomonator / r2.denomonator ));
	return reduce(ret);
}
void mult(int ret[], int r1[], int r2[]) {
	ret[0] = r1[0] * r2[0];
	ret[1] = r1[1] * r2[1];
	reduce(ret);
}
Rat mult(Rat r1, Rat r2) {
	Rat ret;
	ret.numerator = r1.numerator * r2.numerator;
	ret.denomonator = r1.denomonator * r2.denomonator;
	return reduce(ret);
}
void div(int ret[], int r1[], int r2[]){
	ret[0] = r1[0] * r2[1];
	ret[1] = r1[1] * r2[0];
	reduce(ret);
}
Rat div(Rat r1, Rat r2){
	Rat ret;
	ret.numerator = r1.numerator * r2.denomonator;
	ret.denomonator = r1.denomonator * r2.numerator;
	return reduce(ret);
}
int main(){
	Rat r1, r2, temp;
	std::cout << "Enter rational number. \n";
	input(r1);
	std::cout << "Enter 2nd rational number. \n";
	input(r2);
	output(r1);
	output(r2);
	std::cout << "addition is :" << std::endl;
	temp = add(r1,r2);
	output(temp);
	std::cout << "subtraction is :" << std::endl;
	temp = sub(r1,r2);
	output(temp);
	std::cout << "multiplication is :" << std::endl;
	temp = mult(r1,r2);
	output(temp);
	std::cout << "division is :" << std::endl;
	temp = div(r1,r2);
	output(temp);
	std::cout << "\nProgram end.";
	return 0;
}
