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
    void list(std::ostream& os) const;
    int getsize() const;
    T& operator[](int index);
    const T& operator[](int index) const;
};


template <typename T>
int DynamicArray<T>::getsize() const {
    return size;
}

template <typename T>
void DynamicArray<T>::list(std::ostream& os) const {
    for (int i = 0; i < size; ++i)
        os << *array[i] << '\n';
}

#endif //TELEFONKONYV_V1DINAMICARRAY_HPP
