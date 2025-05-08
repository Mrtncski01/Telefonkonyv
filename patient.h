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
    std::string getCondition() const;
    std::string getdoctorName() const;
    void setCondition(std::string newCondition);
    void setdoctorName(std::string newdoctorName);
    void print(std::ostream& os) const;
};
std::ostream& operator<<(std::ostream& os, const Patient& p);
#endif //TELEFONKONYV_PATIENT_H
