#ifndef PHONEBOOK_DOCTOR_H
#define PHONEBOOK_DOCTOR_H
#include "contact.h"

//doctor osztaly contactbol szarmazva
class Doctor : public Contact {
private:
    std::string specialization; //specializacio
    std::string workplace; //munkahely
public:
    Doctor(const Name& newName, const std::string& newPrivatePhone,
           const std::string& newWorkPhone, const std::string& newAddress,
           const std::string& newWorkplace, const std::string& newSpecialization) : Contact(newName, newPrivatePhone, newWorkPhone, newAddress),
                                                                                    specialization(newSpecialization), workplace(newWorkplace) {} //konstruktor
    std::string getSpecialization() const; //visszaadja a specializaciot
    std::string getWorkplace() const; //visszaadja a munkahelyet
    void setSpecialization(const std::string newSpecialization); //beallitas, modositashoz
    void setWorkplace(const std::string newWorkplace); //ugyanaz
    void print(std::ostream& os) const; //kiirja a doctor adatait
    std::string serialize() const; //filebamentes
    //~Doctor() {}
};
std::ostream& operator<<(std::ostream& os, const Doctor& d);

#endif //PHONEBOOK_DOCTOR_H
