/*2. A perfect number is such a number where all of its proper divisors add up to 
the number itself. (Examples of perfect numbers: 6 is a perfect number. Proper 
divisors of 6 are 1, 2, and 3. 1 + 2 + 3=6. 28 is a perfect number. Proper 
divisors of 28 are 1, 2, 4, 7, 14. 1 + 2 + 4 + 7 + 14 = 28.) Write a program 
that asks the user for a positive integer. The program will print all perfect 
numbers from 1 to that positive integer. It is better if you write a separate 
function to check out perfectness of an integer. 
  */
// my first program in C++
#include <iostream>
#include <string>

bool isPerfect(int x) {
	//MAX_INT is 2147483647
	//https://en.wikipedia.org/wiki/List_of_Mersenne_primes_and_perfect_numbers states perfect numbers within this bound are:
	//6, 28, 496, 8128, 33550336, next is 8589869056 which is out of bounds for int.
	int foo [5] = { 6, 28, 496, 8128, 33550336};
	for (int i : foo ) {
		if (x == i)  {
			return true;
		}
	}
	return false;
}

int main(){
	int input = 0;
	std::cout << "Please enter a positive Interger: ";
	std::cin >> input;
	std::cout << "\n";

	//TODO: print all positive intergers between 0 and that are perfect numbers.
	std::cout << "All the perfect numbers between 0 and " << i << " inclusive are";
	int temp = 0;
	while ( temp < input ) {
		if (isPerfect(temp)) {
			std::cout << ", " << i ;
		}
		temp++;
	}
	std::cout << "" ;
	return 0;
}
