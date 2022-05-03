#ifndef SAFEARRAY_H
#define SAFEARRAY_H

template <class T>
class SafeArray
{
    private:
		int size;
        T* array;
    public:
        SafeArray();
        SafeArray(int s);
        int length() const;
        T& operator [] (int index);
        const T& operator [] (int index) const;

	    // destructor
        ~SafeArray();

	    // copy constructor
	    SafeArray(const SafeArray<T>& other);

	    // assignment operator
	    SafeArray<T>& operator = (const SafeArray<T>& other);
};

#endif