#include "phonebook.h"
#include "doctor.h"
#include "patient.h"
#include <iostream>

void Phonebook::listContacts() const {
    if(contacts.getsize()==0) {
        std::cout << "nincs contact";
    }
    else {
        contacts.list(std::cout);
    }
}

void Phonebook::addContact() {
    int valasztas;
    std::string newfirst, newlast, newnick, newprivate, newwork, newaddr;
    std::cout << "uj keresztnevnev";
    std::cin >> newfirst;
    std::cout << "uj vezeteknev\n";
    std::cin >> newlast;
    std::cout << "uj becenev\n";
    std::cin >> newnick;
    std::cout << "uj cim\n";
    std::cin >> newaddr;
    std::cout << "uj privatszam\n";
    std::cin >> newprivate;
    std::cout << "uj munkahelyiszam\n";
    std::cin >> newwork;
    std::cout << "orvost(1) vagy pacienst(2) szeretnél?\n";
    std::cin >> valasztas;
    switch(valasztas) {
        case 1:
            std::cout << "uj spec\n";
            std::cout << "uj munkaehely\n";
            break;
        case 2:
            std::cout << "uj orvos";
            std::cout << "uj allapot\n";
            break;
        default:
            break;
    }
}
