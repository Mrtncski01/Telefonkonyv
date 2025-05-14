#include "doctor.h"
#include <sstream>

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
    name.namePrint(os);
    os << "CIM: " << getAddress() << '\n'
       << "MUNKAHELYI SZAM: " << getWorkPhone() << '\n'
       << "PRIVAT SZAM:" << getPrivatePhone() << '\n'
       << "MUNKAHELY: " << getWorkplace() << '\n'
       << "SPECIALIZACIOJA:" << getSpecialization() << '\n';
}

std::ostream& operator<<(std::ostream& os, const Doctor& d) {
    d.print(os);
    return os;
}

std::string Doctor::serialize() const {
    std::ostringstream oss;
    oss << '1' << "|" << name.getLastname() << " | " << name.getFirstname() << " | " << name.getNickname() << " | " << address << " | " << workPhone << " | " << privatePhone << " | " << specialization << " | " << workplace << " | $";
    return oss.str();
}
