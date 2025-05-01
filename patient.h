#ifndef TELEFONKONYV_PATIENT_H
#define TELEFONKONYV_PATIENT_H
#include "contact.h"

class Patient : public Contact {
private:
    std::string doctorName;
    std::string condition;
public:
    Patient(const Name& newName, const std::string& newPrivatePhone,
    const std::string& newWorkPhone, const std::string& newAddress,
    const std::string& newCondition, const std::string& newDoctorName) : Contact(newName, newPrivatePhone, newWorkPhone, newAddress),
    doctorName(newDoctorName), condition(newCondition) {}
    std::string getCondition() const {
        return condition;
    }
    std::string getdoctorName() const {
        return doctorName;
    }
    ool operator==(const Contact& c) const override;
    void print(std::ostream& os) const override;
};
#endif //TELEFONKONYV_PATIENT_H
