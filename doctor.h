#ifndef PHONEBOOK_DOCTOR_H
#define PHONEBOOK_DOCTOR_H
#include "contact.h"

class Doctor : public Contact {
private:
    std::string specialization;
    std::string workplace;
public:
    Doctor(const Name& newName, const std::string& newPrivatePhone,
           const std::string& newWorkPhone, const std::string& newAddress,
           const std::string& newWorkplace, const std::string& newSpecialization) : Contact(newName, newPrivatePhone, newWorkPhone, newAddress),
                                                                                    specialization(newSpecialization), workplace(newWorkplace) {}
    std::string getSpecialization() const;
    std::string getWorkplace() const;
    void setSpecialization(const std::string newSpecialization);
    void setWorkplace(const std::string newWorkplace);
    void print(std::ostream& os) const;
    std::string serialize() const;
    //~Doctor() {}
};
std::ostream& operator<<(std::ostream& os, const Doctor& d);

#endif //PHONEBOOK_DOCTOR_H
