#ifndef SAFEMATRIX_H
#define SAFEMATRIX_H
#include "safearray.h"

template<class T>
class SafeMatrix {
	private:
		SafeArray<SafeArray<T>> matrix;
	public:
		SafeMatrix();
		SafeMatrix(int rows, int colunms);
		int length() const;
		SafeArray<T>& operator [](int index);
		const SafeArray<T>& operator [](int index) const;

		~SafeMatrix();
		SafeMatrix(const SafeMatrix<T>& other);
		SafeMatrix<T>& operator =(const SafeMatrix<T>& other);
};

template <class T>
SafeMatrix<T>::SafeMatrix() : matrix(){
}

template <class T>
SafeMatrix<T>::SafeMatrix(int rows, int colunms) : matrix(rows) {
	for (int i = 0; i < rows; i++) {
		matrix[i] = SafeArray<T>(colunms);
	}
}

template <class T>
int SafeMatrix<T>::length() const {
	return matrix.length();
}

template <class T>
SafeArray<T>& SafeMatrix<T>::operator [](int index) {
	return matrix[index];
}

template <class T>
const SafeArray<T>& SafeMatrix<T>::operator [](int index) const {
	return matrix[index];
}

template <class T>
SafeMatrix<T>::~SafeMatrix() {
}

template <class T>
SafeMatrix<T>::SafeMatrix(const SafeMatrix<T>& other) : matrix(other.matrix){
}

template <class T>
SafeMatrix<T>& SafeMatrix<T>::operator =(const SafeMatrix<T>& other) {
	matrix = other.matrix;
	return this;
}


#endif
