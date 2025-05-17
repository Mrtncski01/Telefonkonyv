#include "contact.h"
#include "doctor.h"
#include "patient.h"
#include <iostream>
#include <sstream>
#include "memtrace.h"

Name& Contact::getName()  {
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

Contact* Contact::deserialize(const std::string& line) {
    std::istringstream iss(line);
    std::string type;
    getline(iss, type, '|');

    std::string ln, fn, nick, addr, workP, privP, extra1, extra2;
    getline(iss, ln, '|');
    getline(iss, fn, '|');
    getline(iss, nick, '|');
    getline(iss, addr, '|');
    getline(iss, workP, '|');
    getline(iss, privP, '|');
    getline(iss, extra1, '|');
    getline(iss, extra2, '|');

    if (type == "1") {
        return new Doctor(Name(fn, ln, nick), privP, workP, addr, extra2, extra1);
    } else if (type == "2") {
        return new Patient(Name(fn, ln, nick), privP, workP, addr, extra1, extra2);
    } else {
        throw std::runtime_error("ISMERETLEN TIPUS: " + type);
    }
}

