#ifndef PHONEBOOK_PHONEBOOK_H
#define PHONEBOOK_PHONEBOOK_H
#include "dinamicyarray.h"

class Phonebook {
private:
    DinamicArray d;
public:
    Phonebook() {}
    ~Phonebook() {}
    void addContact();
    void listAllContact(std::ostream &os);
    void removeContact(std::ostream &os);
    void searchContact(std::ostream &os);
    void modifyContact(std::ostream& os);
    void saveToFile();
    void loadFromFile(const std::string& filename);
};


#endif //PHONEBOOK_PHONEBOOK_H
