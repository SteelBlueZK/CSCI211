/*1. A prime number is a number other than 1 that is divisible only by 1 and itself. 
	(Example of prime numbers: 2, 3, 5, 7, ...). Write a program that asks the user 
	for a positive integer. The program will print out all prime numbers from 1 to 
	that positive integer. It is better if you write a separate function to check 
	out if an integer is prime or not.  
	*/
// my first program in C++ 
#include <iostream>

bool isPrime(int x){
	if (x < 0)
		exit(0);
	for(int loop = 2; loop < x; loop++) {
		if((x % loop) == 0) {
			return false;
		}
	}
	return true;
}  

int main(){
	std::cout << "You have launched the Prime number lister.\nEnter a positive number and I will output all\nprime numbers between 0 and your number!\n"
		<< "input number: ";
	int input, counter = 2;
	std::cin >> input;
	std::cout << "All the prime numbers between 0 and " << input << " are as follows:\n";
	while (counter < input) {
		if (isPrime(counter))
			std::cout << counter << ", ";
		counter++;
	}
	return 0;
}
