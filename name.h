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
    void setFirstname(const std::string& newFirstname);
    void setLastname(const std::string& newLastname);
    void setNickname(const std::string& newNickname);
    ~Name() {}
};

std::ostream& operator<<(std::ostream& os, const Name& name);

#endif //TELEFONKONYV_NAME_H
