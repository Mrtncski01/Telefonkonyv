#include "patient.h"
#include <sstream>

std::string Patient::getCondition() const {
    return condition;
}

std::string Patient::getdoctorName() const {
    return doctorName;
}
void Patient::setCondition(std::string newCondition) {
    condition=newCondition;
}
void Patient::setdoctorName(std::string newdoctorName) {
    doctorName=newdoctorName;
}

void Patient::print(std::ostream &os) const {
    name.namePrint(os);
    os << "CIM: " << getAddress() << '\n'
       << "MUNKAHELYI SZAM: " << getWorkPhone() << '\n'
       << "PRIVAT SZAM:" << getPrivatePhone() << '\n'
       << "EGESZSEGUGYI ALLAPOT: " << getCondition() << '\n'
       << "KEZELOORVOS NEVE:" << getdoctorName() << '\n';
}

std::ostream& operator<<(std::ostream& os, const Patient& p) {
    p.print(os);
    return os;
}

std::string Patient::serialize() const {
    std::ostringstream oss;
    oss << '0' << '|' << name.getLastname() << " | " << name.getFirstname() << " | " << name.getNickname() << " | " << address << " | " << workPhone << " | " << privatePhone << " | " << condition << " | " << doctorName << " | $";
    return oss.str();
}
