#ifndef PHONEBOOK_NAME_H
#define PHONEBOOK_NAME_H
#include <iostream>

class Name {
private:
    std::string firstname;
    std::string lastname;
    std::string nickname;
public:
    Name() {}
    Name(const std::string& newfirstname, const std::string& newlastname,const std::string& newnickname) : firstname(newfirstname), lastname(newlastname), nickname(newnickname) {}
    std::string getFirstname() const;
    std::string getLastname() const;
    std::string getNickname() const;
    void setFirstname(const std::string& newFirstname);
    void setLastname(const std::string& newLastname);
    void setNickname(const std::string& newNickname);
    void namePrint(std::ostream& os) const;
    ~Name() {}
};
std::ostream& operator<<(std::ostream& os, const Name& name);

#endif //PHONEBOOK_NAME_H
