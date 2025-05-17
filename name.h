#ifndef PHONEBOOK_NAME_H
#define PHONEBOOK_NAME_H
#include <iostream>

//name osztaly, ez felel a contactok neveert
class Name {
private:
    std::string firstname; //keresztnev
    std::string lastname; //vezeteknev
    std::string nickname; //becenev
public:
    Name(const std::string& newfirstname, const std::string& newlastname,const std::string& newnickname) : firstname(newfirstname), lastname(newlastname), nickname(newnickname) {} //konstruktor
    std::string getFirstname() const; //visszaadja a keresztnevet
    std::string getLastname() const; //visszaadja a vezeteknevet
    std::string getNickname() const; //visszaadja a becenevet
    void setFirstname(const std::string& newFirstname); //beallitja, a keresztnevet, modositashoz kell
    void setLastname(const std::string& newLastname); //ugyanez
    void setNickname(const std::string& newNickname); //ugyanez
    void namePrint(std::ostream& os) const; //kiirj a felhasznalo vezetek, kereszt, illetve becenevet
    ~Name() {} //destruktor
};
std::ostream& operator<<(std::ostream& os, const Name& name);

#endif //PHONEBOOK_NAME_H
