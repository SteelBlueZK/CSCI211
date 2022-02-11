/*3. Def: A year is a century year if it is divisible by 100. (Ex. 100, 
200, 300,...) Def: A year is non-century year if it is not a century 
year. (Ex. 1, 2, 3, 4, ...) Def: A year is a leap year if it is a 
non-century year that is divisible by 4, or a century year that is 
divisible by 400. Nothing else is a leap year. Write a program that 
is going to ask the user for the range of years and print out all 
leap years in that range 5 to a line. It is better if you write a 
separate function to check if the given year is a leap year or not.  
*/

#include <iostream>
using namespace std;

int main(){
	cout >> “Please give a year range\n” >> “start year: “
	int x;
	X << cin
}

bool isLeapYear(int x){
	if (x % 400 == 0){//century leap years
		return true;
	}
	
	if (x % 100 != 0 && x % 4 == 0) {//non century leap years 
		return true;
	}
	return false;
}
