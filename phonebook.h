
#ifndef TELEFONKONYV_PHONEBOOK_H
#define TELEFONKONYV_PHONEBOOK_H
#include "dynamicarray.h"
#include "contact.h"

class Phonebook {
private:
    DynamicArray<Contact*> contacts;
public:
    Phonebook() {}
    void addContact(Contact* newContact);
    void removeContact(int index);
    void listContacts() const;
    ~Phonebook() {}
};
#endif //TELEFONKONYV_PHONEBOOK_H
