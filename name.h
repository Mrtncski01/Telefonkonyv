#ifndef TELEFONKONYV_NAME_H
#define TELEFONKONYV_NAME_H
#include <iostream>
class Name {
private:
    std::string firstname;
    std::string lastname;
    std::string nickname;
public:
    Name()=default;
    Name(const std::string& newfirstname, const std::string& newlastname, std::string  newnickname) : firstname(newfirstname), lastname(newlastname), nickname(newnickname) {}
    std::string getFirstname() const;
    std::string getLastname() const;
    std::string getNickname() const;
    std::string setFirstname(std::string& newFirstname);
    std::string setLastname(std::string& newLastname);
    std::string setNickname(std::string& newNickname);
    void nameprint(std::ostream& os) const;
    ~Name() {}
};
std::ostream& operator<<(std::ostream& os, const Name& n);

#endif //TELEFONKONYV_NAME_H
