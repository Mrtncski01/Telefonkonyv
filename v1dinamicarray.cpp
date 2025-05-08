#ifndef TELEFONKONYV_V1DINAMICARRAY_HPP
#define TELEFONKONYV_V1DINAMICARRAY_HPP
#include <iostream>

template <typename T>
class DynamicArray {
private:
    T* array;
    int size;
public:
    DynamicArray() : array(nullptr), size(0)    {}
    ~DynamicArray() {
        delete[] array;
    }

    void add(const T& newContact);
    T& operator[](int index);
    const T& operator[](int index) const;
};


#endif //TELEFONKONYV_V1DINAMICARRAY_HPP
