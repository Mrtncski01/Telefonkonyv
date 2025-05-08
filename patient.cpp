#include "patient.h"

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
    os << name.getFirstname() << " " << name.getLastname()<< " " << '(' << name.getNickname()<< ')' <<" " << condition << " " << doctorName << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Patient& p) {
    p.print(os);
    return os;
}
