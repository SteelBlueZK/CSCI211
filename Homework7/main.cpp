#include "safematrix.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main(){
	cout << setprecision(4);
	int ROWS(10), COLS(15);
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
	cout << "the value of row 5(odd), colunm 10 should be row + colunm: " << x[5][10] << "\n";
	cout << "the value of row 6(even), colunm 10 should be row * colunm: " << x[6][10] << "\n";
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
	cout << "the value of row 6, colunm 10 should be (sqrt(row) *2colunm): " << y[6][10] << "\n";

	return 0;
}
