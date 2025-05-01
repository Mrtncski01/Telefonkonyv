#include <iostream>
#include "name.h"

std::string Name::getFirstname() const {
    return firstname;
}

std::string Name::getLastname() const {
    return lastname;
}

std::string Name::getNickname() const {
    return nickname;
}

void Name::nameprint(std::ostream &os) const {
    os<< firstname << " " << lastname << "(" << nickname << ")";
}

std::ostream& operator<<(std::ostream& os, const Name& n) {
    n.nameprint(os);

    return os;
}