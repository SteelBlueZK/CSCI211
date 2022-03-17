#include "Complex.h"

Complex::Complex() : real(0.0), imag(0.0) {}

Complex::Complex(double a) : real(a), imag(0.0) {}

Complex::Complex(double a, double b) : real(a), imag(b) {}

const Complex operator +(const Complex r) {
	Complex x;
	return x;
}

const Complex operator -(const Complex r) {}

const Complex operator *(const Complex r) {}

const Complex operator /(const Complex r) {}


