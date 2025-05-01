#ifndef TELEFONKONYV_DOCTOR_H
#define TELEFONKONYV_DOCTOR_H
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
    std::string getSpecialization() const {
        return specialization;
    }
    std::string getWorkplace() const {
        return workplace;
    }
    bool operator==(const Contact& c) const override;
    void print(std::ostream& os) const override;
};
#endif //TELEFONKONYV_DOCTOR_H
