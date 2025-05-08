#include "contact.h"
#include <iostream>

Name Contact::getName() const {
    return name;
}

std::string Contact::getAddress() const {
    return address;
}

std::string Contact::getWorkPhone() const {
    return workPhone;
}

std::string Contact::getPrivatePhone() const {
    return privatePhone;
}

void Contact::setAddress(std::string newAddress) {
    address=newAddress;
}

void Contact::setWorkPhone(std::string newWorkPhone) {
    workPhone=newWorkPhone;
}
void Contact::setPrivatePhone(std::string newPrivatePhone) {
    privatePhone=newPrivatePhone;
}

bool Contact::operator==(const std::string& s) const {
    return name.getFirstname()==s || name.getLastname()==s || name.getNickname()==s || getPrivatePhone()==s;
}

std::ostream& operator<<(std::ostream& os, const Contact& c) {
    os << "Name: " << c.getName() << '\n'
       << "Private Phone: " << c.getPrivatePhone() << '\n'
       << "Work Phone: " << c.getWorkPhone() << '\n'
       << "Address: " << c.getAddress() << '\n';
    return os;
}
