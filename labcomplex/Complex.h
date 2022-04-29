#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>


class Complex {
	private:
		double real, imag;
	public:
		//constructors
		Complex();//starts at 0
		Complex(double a); //starts with real part
		Complex(double a, double b); //starts with real and imaginary part
		// getters/ setters
		double getReal() const;
		double getImag() const;
		void setReal(const double a);
		void setImag(const double a);
		// overload operators;
		const Complex operator +(const Complex& a) const;
		const Complex operator -(const Complex& a) const;
		const Complex operator *(const Complex& a) const;
		const Complex operator /(const Complex& a) const;
		bool operator ==(const Complex& a) const;
		bool operator !=(const Complex& a) const;
		double operator [](const Complex& a) const;
		void operator =(const Complex& a) const;
		friend std::ostream& operator <<(std::ostream& out, const Complex& a);
		friend std::istream& operator >>(std::istream& in, const Complex& a);
		
};

#endif
