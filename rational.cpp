#include <iostream>
#include <stdlib.h>

int lcm(int,int);
int gcf(int,int);

class Rat {
	private:
		int numerator;
		int denomonator;
		void setNum(int n);
		void setDenom(int d);
		void reduce();
	public:
		Rat();
		void input();
		void output();
		Rat add(Rat r);
		Rat sub(Rat r);
		Rat mult(Rat r);
		Rat div(Rat r);
		int getNum();
		int getDenom();
};


int main(){
	/*
	int a,b,out,end;
	while (end != 0) {
	std::cout << "compute lcm. Input 2 numbers.";
	std::cin >> a >> b;
	std::cout << "computing lcm. \n";
	out = lcm(a,b);
	std::cout << "lcm is: " << out << "\n enter 0 to exit, else enter any int other than 0: ";
	std::cin >> end;
	}
	*/
	Rat r1, r2;
	r1.input();
	r1.output();
	r2.input();
	r2.output();
	Rat sum, dif, prod, quot;
	std::cout << "addition is :" << std::endl;
	sum = r1.add(r2);
	sum.output();
	std::cout << "subtraction is :" << std::endl;
	dif = r1.sub(r2);
	dif.output();
	std::cout << "multiplication is :" << std::endl;
	prod = r1.mult(r2);
	prod.output();
	std::cout << "division is :" << std::endl;
	quot = r1.div(r2);
	quot.output();

	std::cout << "\nProgram end.\n";
	return 0;
}

int lcm(int i1, int i2){
	int a = abs(i1), b = abs(i2);
	if (a == 0 || b == 0) {
		return 0;
	}
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
int gcf(int a, int b) {
	return (a * b) / lcm(a,b);
}

Rat::Rat(){
}
void Rat::input() {	
	std::cout << "Input Rational number." << std::endl;
	std::cout << "Please enter numerator: ";
	std::cin >> numerator;	
	std::cout << "\n" << "Please enter denominator: ";
	std::cin >> denomonator;
}
void Rat::output(){	
	std::cout << "Your rational number is:\n"
	       	<< numerator << " / " << denomonator << std::endl;
}
int Rat::getNum(){
	return numerator;
}
int Rat::getDenom(){
	return denomonator;
}
void Rat::setNum(int n){
	numerator = n;
}
void Rat::setDenom(int d){
	denomonator = d;
}
void Rat::reduce(){
	int x = gcf(numerator,denomonator);
	numerator = numerator / x;
	denomonator = denomonator / x;
}
Rat Rat::add(Rat r) {
	Rat ret;
	ret.denomonator = lcm(denomonator , r.getDenom());
	ret.numerator = ( numerator * ( ret.getDenom() / denomonator) ) + ( r.getNum() * ( ret.getDenom() / r.getDenom() ));
	ret.reduce();
	return ret;
}
Rat Rat::sub(Rat r) {
	Rat ret;
	ret.setDenom(lcm(denomonator , r.getDenom()));
	ret.setNum(( numerator * ( ret.getDenom() / denomonator) ) - ( r.getNum() * ( ret.getDenom() / r.getDenom() )));
	ret.reduce();
	return ret;
}
Rat Rat::mult(Rat r) {
	Rat ret;
	ret.setNum(numerator * r.getNum());
	ret.setDenom(denomonator * r.getDenom());
	ret.reduce();
	return ret;
}
Rat Rat::div(Rat r){
	Rat ret;
	ret.numerator = numerator * r.getDenom();
	ret.denomonator = denomonator * r.getNum();
	ret.reduce();
	return ret;
}
