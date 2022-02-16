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
	int result = 0, temp;
	for (int c = 0; c < 99; c++) {
		result = result + input % 10;
		input = input / 10;
		if (input <= 0)
			break;
		result = result * 10;
	}
	return result;
}

int main(){
	int var;
	std::cout << "Yo have launched the Reverse Number Program!\n"
		<< "Input positive intergers and I will output its reverse.\n"
		<< "To close the program input a negative number.\n";
	while (true) {
		std::cout << "\nInput a number: ";
		std::cin >> var;
		if (var < 0)
			return 0;
		var = reverse(var);
		std::cout << "Reverse of num: " << var << "\n";
	}
}
