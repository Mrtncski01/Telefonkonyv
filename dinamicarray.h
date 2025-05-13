#ifndef PHONEBOOK_DINAMICYARRAY_H
#define PHONEBOOK_DINAMICYARRAY_H
#include <iostream>
#include "contact.h"
#include "doctor.h"
#include "patient.h"


class DinamicArray {
private:
    size_t size;
    size_t capacity;
    Contact **array;
public:
    DinamicArray() : array(nullptr),  size(0),  capacity(0){}
    ~DinamicArray();
    size_t getsize() const;
    Contact& operator[](int index) const;
    void add(Contact* c);
    void list(std::ostream& os);
    void remove(size_t index);
    void resize();
    void search(std::string find, std::ostream& os) const;
    void modify(int modifyingAttribution, Contact& c);
};


#endif //PHONEBOOK_DINAMICYARRAY_H
