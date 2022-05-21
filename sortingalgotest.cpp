#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;
void selectionSort(int *const a, int size);
void bubbleSort(int *const a, int size);
void insertionSort(int *const a, int size);
void printArray(const int *const a, int size);
void newArray(int *const a, int size);

int main() {
	int array[50];
	
	newArray(array, 50);
	selectionSort(array, 50);

	newArray(array, 50);
	bubbleSort(array, 50);

	newArray(array, 50);
	insertionSort(array, 50);
}
 
void newArray(int *const a, int size) {
	static unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	static std::default_random_engine generator(seed);
	static std::uniform_int_distribution<int> distribution(1,1000);
	cout << "creating random array\n";
	for (int i = 0; i < size; i++){
		a[i] = distribution(generator);
	}
	printArray(a,size);
}

void selectionSort(int *const a, int size) {
	cout << "seleciton sort\n";
	int i, i2, v;
	for ( i = 1; i < size; ++i){
		v = a[i];
		i2 = i-1;
		while (i2 >= 0 && a[i2] > v) {
			a[i2 + 1] = a[i2];
			i2 -= 1;
		}
		a[i2+1] = v;
	}
	printArray(a,size);
}

void bubbleSort(int *const a, int size) {
	cout << "bubble sort\n";
	int i, j, temp;
	for(i = size; i > 1; --i) {
		for( j = 1; j < i; ++j) {
			if (a[j - 1] > a[j]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
	printArray(a,size);
}

void insertionSort(int *const a, int size) {
	cout << "insertion sort\n";
	int i,j,tempindex(0),temp;

	for (i = 0; i < size; i++) {
		for (j = i; j < size; j++) {
			if( a[tempindex] > a[j] ) {
				tempindex = j;
			}
		}
		temp = a[i];
		a[i] = a[tempindex];
		a[tempindex] = temp;
	}
	printArray(a,size);
}

void printArray(const int *const a, int size) {
	int i(0), c(0);
	while (i < size) {
		if (c > 10) {
			cout << endl;
			c = 0;
		}
		c++;
		cout << a[i++] << '\t';
	}
	cout << endl;
}

