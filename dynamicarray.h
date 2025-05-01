
#ifndef TELEFONKONYV_DYNAMICARRAY_H
#define TELEFONKONYV_DYNAMICARRAY_H

template <typename T>
class DynamicArray {
private:
    T* array;
    int size;
public:
    DynamicArray() {}
    DynamicArray(const DynamicArray& d) {}
    DynamicArray& operator=(const DynamicArray& d);
    ~DynamicArray() {}

    void add(const T& newContact);
    void remove(int index);
    int getsize() const;
    T& operator[](int index);
    const T& operator[](int index) const;
};

#endif //TELEFONKONYV_DYNAMICARRAY_H
