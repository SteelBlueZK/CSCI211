#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T>
vector<T> vectorfy(T* a, int size);
template<class T>
void OutputEven(vector<T> v);
template<class T>
void OutputOdd(vector<T> v);

int main(){
	int arraysize = 5;
	int array[arraysize] = {25,15,0,3,18};
	vector<int> vector = vectorfy(array, arraysize);
	cout << "whole vector\n";
	for (int i : vector)
		cout << i << " ";
	cout << endl;
	cout << "vector even\n";
	OutputEven(vector);
	cout << endl;
	cout << "vector odd\n";
	OutputOdd(vector);
	cout << endl;
	return 0;
}

template<class T>
vector<T> vectorfy(T* a, int size) {
	vector<T> t;
	t.reserve(size);
	for(int i = 0; i < size; i++) {
		t.push_back(a[i]);
	}
	return t;
}

template<class T>
void OutputEven(vector<T> v) {
	int i;
	bool b = false;
	if (v.size() == 0)
		return;
	if (v.back()%2 == 0) {
		i = v.back();
		b = true;
	}
	v.pop_back();
	OutputEven(v);
	if (b)
		cout << i << " ";
}

template<class T>
void OutputOdd(vector<T> v) {
	int i;
	bool b = false;
	if (v.size() == 0)
		return;
	if (v.back()%2 == 1) {
		i = v.back();
		b = true;
	}
	v.pop_back();
	OutputOdd(v);
	if (b)
		cout << i << " ";
}

