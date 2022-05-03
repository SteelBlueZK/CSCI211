#include "safematrix.h"
#include "safearray.h"

template <class T>
SafeMatrix<T>::SafeMatrix() {
	rows = 0;
	matrix = new SafeArray<T>();
}

template <class T>
SafeMatrix<T>::SafeMatrix(int s, int colunms) : rows(s) {
	matrix = new SafeArray<T>[colunms];
}

template <class T>
int SafeMatrix<T>::length() const {
}

template <class T>
SafeArray<T>& SafeMatrix<T>::operator [](int index) {
}

template <class T>
const SafeArray<T>& SafeMatrix<T>::operator [](int index) const {
}

template <class T>
SafeMatrix<T>::~SafeMatrix() {
}

template <class T>
SafeMatrix<T>::SafeMatrix(const SafeMatrix<T>& other) {
}

template <class T>
SafeArray<T>& SafeMatrix<T>::operator =(const SafeArray<T>& other) {
}

