#include <iostream>
#include <string>

void input(int r[]) {
	std::cout << "Please enter numerator: ";
	std::cin >> r[0];	
	std::cout << "\n" << "Please enter denominator: ";
	std::cin >> r[1];	
}
void output(int r[]){
	std::cout << "Your rational number is:\n"
	       	<< r[0] << "\nover\n" << r[1] << std::endl;
}
int lcm(int a, int b){
	/*if (a < 1 || b < 1) {
		return -1;
	}*/
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
int gcf(int a, int b) {
	return (a * b) / lcm(a,b);
}
void reduce(int r[]){
	int x = gcf(r[0],r[1]);
	r[0] = r[0] / x;
	r[1] = r[1] / x;
}
void add(int ret[], int r1[], int r2[]) {
	ret[1] = lcm(r1[1],r2[1]);
	ret[0] = (r1[0]*(ret[1]/r1[1])) + (r2[0]*(ret[1]/r2[1]));
	reduce(ret);
}
void sub(int ret[], int r1[], int r2[]) {
	ret[1] = lcm(r1[1],r2[1]);
	ret[0] = (r1[0]*(ret[1]/r1[1])) - (r2[0]*(ret[1]/r2[1]));
	reduce(ret);
}
void mult(int ret[], int r1[], int r2[]) {
	ret[0] = r1[0] * r2[0];
	ret[1] = r1[1] * r2[1];
	reduce(ret);
}
void div(int ret[], int r1[], int r2[]){
	// You don't nessisarilly always end up with a rational number.
	reduce(ret);
}
int main(){
	int test1[2] = {7,6}, test2[2] = {9,2};
	int r[2];
	//std::cout << "Enter rational number. \n";
	//input(r);
	//output(r);
	//std::cout << "outputing gcd then lcm for the num and den of your rational number\n" << lcm(r[0],r[1]) << std::endl << gcd(r[0],r[1]) << std::endl;
	add(r,test1,test2);
	std::cout << r[0] << std::endl << r[1] << std::endl;
	return 0;
}
