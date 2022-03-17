#ifndef COMPLEX_H
#define COMPLEX_H

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
};

#endif
