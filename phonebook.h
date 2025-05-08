
#ifndef TELEFONKONYV_PHONEBOOK_H
#define TELEFONKONYV_PHONEBOOK_H
#include "v1dynamicarray.hpp"
#include "contact.h"

class Phonebook {
private:
    DynamicArray<Contact*> contacts;
public:
    Phonebook() {}
    void addContact();
    void listContacts() const;
    ~Phonebook() {}
};
#endif //TELEFONKONYV_PHONEBOOK_H
