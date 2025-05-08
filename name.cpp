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

void Name::setFirstname(const std::string &newFirstname) {
    firstname=newFirstname;
}

void Name::setLastname(const std::string &newLastname) {
    lastname=newLastname;
}

void Name::setNickname(const std::string &newNickname) {
    nickname=newNickname;
}
