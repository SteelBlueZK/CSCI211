/*4. Write a program that will continuously ask the user for positive 
integers (until the user enters a negative integer at which the 
program will be terminated). Every time the user inputs a positive 
integer the program will print out this integer in reverse. Your 
program should have a function that accepts and integer and returns 
an integer in reverse. To convert the integer to its reverse, your 
program will call this function.  
  */

#include <iostream>

int reverse(int input) {
	int result = 0;
	int loopVar = 10;
	int temp;
	do {
		temp = input - result;
		result = result * 10;
		temp = temp % loopVar;
		result = result + temp;
	} while (loopVar <= input);
	return -1;
}

int main(){
	int var;
	std::cout << "Input positive intergers and I will output its reverse. \n To close the program input a negative number.\n";
	while (true) {
		std::cout << "Input a number: ";
		std::cin >> var;
		if (var < 0)
			return 0;
		var = reverse(var);
		std::cout << "Reverse of num: " << var << "\n\n";
	}
}
