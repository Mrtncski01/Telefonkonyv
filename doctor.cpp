#include "doctor.h"

std::string Doctor::getSpecialization() const {
    return specialization;
}

std::string Doctor::getWorkplace() const {
    return workplace;
}

void Doctor::setSpecialization(const std::string newSpecialization) {
    specialization=newSpecialization;
}

void Doctor::setWorkplace(const std::string newWorkplace) {
    workplace=newWorkplace;
}

void Doctor::print(std::ostream &os) const {
    os << name.getFirstname() << " " << name.getLastname()<< " " << '(' << name.getNickname()<< ')' <<" " << specialization << " " << workplace << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Doctor& d) {
    d.print(os);
    return os;
}
