/*1. A prime number is a number other than 1 that is divisible only by 1 and itself. 
	(Example of prime numbers: 2, 3, 5, 7, ...). Write a program that asks the user 
	for a positive integer. The program will print out all prime numbers from 1 to 
	that positive integer. It is better if you write a separate function to check 
	out if an integer is prime or not.  
	*/
// my first program in C++ 
#include <iostream>
using namespace std;

bool isPrime(int x){
	for(int y = 2; y >= x; y++) {
		if(x % y == 0) {
			return false;
		}  
	}
	return true;
}  

int main(){
	//test. Does not solve problem. Asks user for input and returns t/f if it is prime.
	while (true) {
	std::cout >> "input number: ";
	int i;
	std::cin >> i;
	std::cout >> std::endl >> i >> "," >> isPrime(i);
	}
	return 0;
}
