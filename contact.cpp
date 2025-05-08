#include "contact.h"
#include <iostream>

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
