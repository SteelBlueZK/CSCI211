#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include "Rat.h"

int Rat::lcm(int first, int second){
	assert(first >= 0 && second >= 0);
	int a = abs(first), b = abs(second);

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

int Rat::gcf(int a, int b) {
	int x = lcm(a,b);
	if (x == 0){
		std::cerr << "ERROR: gcf calculates number divided by 0\n";
		exit(1);
	}
	return (a * b) / x;
}

const int Rat::compare( const Rat& r1, const Rat& r2) {
	int n1 = r1.getNum() * r2.getDenom();
	int n2 = r2.getNum() * r2.getDenom();
	return n1 - n2;
}

Rat::Rat(): numerator(0), denomonator(1){
}

Rat::Rat(int num) : numerator(num), denomonator(1){
}

Rat::Rat(int num, int den): numerator(num), denomonator(den){
}

void Rat::input() {	
	std::cout << "New Rational number." << std::endl;
	std::cout << "numerator: ";
	std::cin >> numerator;	
	std::cout << "denominator: ";
	std::cin >> denomonator;
	std::cout << std::endl;
	reduce();
}
void Rat::output() const {	
	std::cout << numerator << " / " << denomonator << std::endl;
}
const int Rat::getNum() const {
	return numerator;
}
const int Rat::getDenom() const {
	return denomonator;
}
void Rat::setNum(int n){
	numerator = n;
}
void Rat::setDenom(int d){
	denomonator = d;
}
void Rat::reduce(){
	if (numerator < 0)
		numerator = numerator * -1;
	if (denomonator == 0){
		std::cerr << "ERROR: denomonator of rational number := 0 error\n";
		exit(1);
	}
	if (denomonator < 1)
		denomonator = denomonator * -1;
	int x = gcf(numerator,denomonator);
	if (x == 0) {
		std::cout << "error in reduce function: gcf == 0";
		exit(1);
	}
	numerator = numerator / x;
	denomonator = denomonator / x;
}
Rat Rat::add(const Rat& r) const{
	Rat ret;
	ret.denomonator = lcm(denomonator , r.getDenom());
	ret.numerator = ( numerator * ( ret.getDenom() / denomonator) ) + ( r.getNum() * ( ret.getDenom() / r.getDenom() ));
	ret.reduce();
	return ret;
}
Rat Rat::sub(const Rat& r) const{
	Rat ret;
	ret.setDenom(lcm(denomonator , r.getDenom()));
	ret.setNum(( numerator * ( ret.getDenom() / denomonator) ) - ( r.getNum() * ( ret.getDenom() / r.getDenom() )));
	ret.reduce();
	return ret;
}
Rat Rat::mult(const Rat& r) const{
	Rat ret;
	ret.setNum(numerator * r.getNum());
	ret.setDenom(denomonator * r.getDenom());
	ret.reduce();
	return ret;
}
Rat Rat::div(const Rat& r) const{
	Rat ret;
	ret.numerator = numerator * r.getDenom();
	ret.denomonator = denomonator * r.getNum();
	ret.reduce();
	return ret;
}
