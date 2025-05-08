#include "phonebook.h"
#include "doctor.h"
#include "patient.h"
#include <iostream>

void Phonebook::listContacts() const {
    if(contacts.getsize()==0) {
        std::cout << "nincs contact";
    }
    else {
        contacts.list();
    }
}

void Phonebook::addContact() {
    int valasztas;
    std::string newfirst, newlast, newnick, newprivate, newwork, newaddr;
    std::cout << "uj keresztnevnev";
    std::cin >> newfirts;
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
    std::cout << "orvost(1) vagy pacienst(2) szeretnél?\n"
    std::cin >> valasztas;
    switch(valasztas) {
        case 1:
            std::string ujspec, ujmunkahely;
            std::cout << "uj spec";
            std::cin >> ujspec;
            std::cout << "uj munkaehely\n";
            std::cin >> ujmunkahely;
            break:
        case 2:
            std::string ujorvos, ujallapot;
            std::cout << "uj orvos";
            std::cin >> ujorvos;
            std::cout << "uj allapot\n";
            std::cin >> ujallapot;
    }
}
