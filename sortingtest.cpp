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

void selectionSort(int *const a, int size) {
	cout << "seleciton sort\n";
	//TODO YOUR ALGORITHM HERE
	printArray(a,size);
}

void bubbleSort(int *const a, int size) {
	cout << "bubble sort\n";
	//TODO YOUR ALGORITHM HERE
	printArray(a,size);
}

void insertionSort(int *const a, int size) {
	cout << "insertion sort\n";
	//TODO YOUR ALGORITHM HERE
	printArray(a,size);
}

