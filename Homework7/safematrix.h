#ifndef SAFEMATRIX_H
#define SAFEMATRIX_H
#include "safearray.h"

template<class T>
class SafeMatrix {
	private:
		SafeArray<T> **matrix;
		int rows;
	public:
		SafeMatrix();
		SafeMatrix(int rows, int colunms);
		int length() const;
		SafeArray<T>& operator [](int index);
		const SafeArray<T>& operator [](int index) const;

		~SafeMatrix();
		SafeMatrix(const SafeMatrix<T>& other);
		SafeArray<T>& operator =(const SafeArray<T>& other);
};

#endif
