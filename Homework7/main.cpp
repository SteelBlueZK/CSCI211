#include "safematrix.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main(){
	cout << setprecision(4);
	int ROWS, COLS;
	cout << "enter number of rows: ";
	cin >> ROWS;
	cout << "enter number of colunms:";
	cin >> COLS;
	cout << endl;
	SafeMatrix<int> x(ROWS,COLS);
	cout << "number of rows is " << ROWS
		<< " and number of colunms is "<< COLS << endl;
	cout << "matrix.length is " << x.length() << '\n'
		<< "matrix[0].length is " << x[0].length() << "\n";
	for (int i = 0; i < ROWS; i++) {
		cout << "R#" << i << "\t|";
		for (int j = 0; j < COLS; j++) {
			if (i%2 == 0)
				x[i][j] = j*i;
			else
				x[i][j] = i + j;
			cout << x[i][j]<< "\t|";
		}
		cout << endl;
	}
	cout << "Odd rows are Row# + Colunm#, even rows are Row# * Colunm#.\n";
	int tempr = ROWS-1, tempc = COLS-1;
	tempr = tempr - tempr/3;
       	tempc = tempc - tempc/3;
	cout << "the value of row "<<tempr<<", colunm "<<tempc<<" is: " << x[tempr][tempc] << "\n";
	tempr = fmin(tempr + 1, ROWS - 1);//implicit double to int cast
	cout << "the value of row "<<tempr<<", colunm "<<tempc<<" is: " << x[tempr][tempc] << "\n";
	cout << "example of double:\n";
	SafeMatrix<double> y(ROWS,COLS);
	cout << "number of rows is " << ROWS
		<< " and number of colunms is "<< COLS << endl;
	cout << "matrix.length is " << y.length() << '\n'
		<< "matrix[0].length is " << y[0].length() << "\n";
	for (int i = 0; i < ROWS; i++) {
		cout << "R#" << i << "\t|";
		for (int j = 0; j < COLS; j++) {
			y[i][j] = sqrt(i) * 2 * j;
			cout << y[i][j]<< "\t|";
		}
		cout << endl;
	}
	cout << "Values should be (sqrt(row) *2colunm).\n";
	cout << "the value of row "<<tempr<<", colunm "<<tempc<<" is: " << y[tempr][tempc] << "\n";

	return 0;
}
