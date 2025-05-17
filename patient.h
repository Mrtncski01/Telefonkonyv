#ifndef PHONEBOOK_PATIENT_H
#define PHONEBOOK_PATIENT_H
#include "contact.h"

//paciens osztaly, ami a kontakt osztalybol szarmazik, orokli a tulajdonsagait
class Patient : public Contact {
private:
    std::string doctorName; //kez.orvos neve
    std::string condition; //eg.ugyi allapota
public:
    Patient(const Name& newName, const std::string& newPrivatePhone,
            const std::string& newWorkPhone, const std::string& newAddress,
            const std::string& newCondition, const std::string& newDoctorName) : Contact(newName, newPrivatePhone, newWorkPhone, newAddress),
                                                                                 doctorName(newDoctorName), condition(newCondition) {} //konstruktora
    std::string getCondition() const; //visszakuldi az eg.ugyi allapotat
    std::string getdoctorName() const; //visszakuldi a doktor nevet
    void setCondition(std::string newCondition); //beallitja az eg.allapotat, ez a modositas funkciohoz kell
    void setdoctorName(std::string newdoctorName); //szinten
    void print(std::ostream& os) const; // override, kiiratja a a paciens adatait
    std::string serialize() const; //filebamenteshez kell
    ~Patient() {} //destruktor
};
std::ostream& operator<<(std::ostream& os, const Patient& p);

#endif //PHONEBOOK_PATIENT_H
