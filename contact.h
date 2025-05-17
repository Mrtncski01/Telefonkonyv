#ifndef PHONEBOOK_CONTACT_H
#define PHONEBOOK_CONTACT_H
#include "name.h"
#include <iostream>

//contact osztaly, ebbol szarmazik le a doctor es a patient, alapadatokat tartalmaz, absztrakt osztaly
class Contact {
protected:
    Name name; //nev
    std::string privatePhone; //privat szam
    std::string workPhone; //munkaelyi szam
    std::string address; //cim
public:
    Contact(const Name& newName,
            const std::string& newPrivatePhone,
            const std::string& newWorkPhone,
            const std::string& newAddress) : name(newName), privatePhone(newPrivatePhone), workPhone(newWorkPhone), address(newAddress) {} //konstruktor
    Name& getName() ; //visszaadja a nevet
    std::string getAddress() const; //visszaadja cimet
    std::string getWorkPhone() const; //visszaadja a munkahelyi szamot
    std::string getPrivatePhone() const; //visszaadja a privat szamot
    void setAddress(std::string newAddress); //modositashoz kell beallitja a cimet
    void setWorkPhone(std::string newWorkPhone); //ugyanez
    void setPrivatePhone(std::string newPrivatePhone); //ugyanez
    bool contactMatches(const std::string& s, int userChoice) const; //kereseshez, kell, visszaadja hogy megegyezik-e a string, a contact valamelyik attributumaval a valasztott opcionak megfeleloen
    virtual void print(std::ostream& os) const = 0; //contact adatai kiiratasa, virtualis, a patient meg a doctor felulirja
    virtual std::string serialize() const = 0; // filebamentes, ezt is felulirjak a leszarmazottak
    static Contact* deserialize(const std::string& line); //fuggvenybol kiolvasas sorszamnak megfeleloen, contact-0 doctor-1
    virtual ~Contact() {} //destruktor
};


#endif // PHONEBOOK_CONTACT_H
