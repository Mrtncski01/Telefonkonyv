#include "Phonebook.h"
#include <iostream>
#include "dinamicarray.h"
#include "inputmanaging.h"
#include "memtrace.h"

void Phonebook::listAllContact(std::ostream& os) {
    if(d.getsize()==0) {
        std::cout << "NINCS KONTAKT!\n";
    }
    else {
        d.list(os);
    }
}

void Phonebook::addContact() {
    std::string newFirst, newLast, newNick, newPrivateP, newWorkP, newAddr;
    int choice;
    std::cout << "UJ KONTAKT HOZZAADASA\n";
    std::cout << "ORVOST(1), VAGY PACIENST(2) SZERETNEL?\n";
    choice= readIndexInput("OPCIO:", 1, 2);
    newLast= readStringInput("VEZETEKNEV:");
    newFirst= readStringInput("KERESZTNEV:");
    newNick= readStringInput("BECENEV:");
    newAddr= readStringInput("CIM:");
    newPrivateP= readStringInput("PRIVAT SZAM:");
    newWorkP=readStringInput("MUNKAHELYI SZAM:");

    Name NewN(newFirst, newLast, newNick);
    if (choice == 1) {
        std::string newWorkPl, newSpec;
        newWorkPl= readStringInput("MUNKAHELY:");
        newSpec= readStringInput("SPECIALIZACIO:");
        d.add(new Doctor(NewN, newPrivateP, newWorkP, newAddr, newWorkP, newSpec));
    } else if (choice == 2) {
        std::string newDoc, newCond;
        newDoc= readStringInput("KEZELOORVOS:");
        newCond= readStringInput("EGESZSEGUGYI ALLAPOT:");
        d.add(new Patient(NewN, newPrivateP, newWorkP, newAddr, newCond, newDoc));
        }
}

void Phonebook::removeContact(std::ostream& os) {
    if(d.getsize()==0)
        std::cout << "NINCS KONTAKT!\n";
    else {
        int choice;
        d.list(os);
        std::cout << "MELYIKET SZERETNED TOROLNI?\n";
        choice= readIndexInput("VALASZTASOD:", 1, d.getsize());
        d.remove(choice);
    }
}

void Phonebook::searchContact(std::ostream &os) {
    if(d.getsize()==0)
        std::cout << "NINCS KONTAKT!\n";
    else {
        int choice;
        std::string findingContact;
        std::cout << "KERESESI LEHETOSEGEK:VEZETEKNEV(1), KERESZTNEV(2), BECENEV(3), PRIVAT SZAM(4)\n";
        choice= readIndexInput("VALASZTASOD:", 1, 4);
        findingContact=readStringInput("ADAT:");

        if(!d.search(findingContact, choice, os))
            std::cout << "NINCS ILYEN KONTAKT!\n";
    }
}

void Phonebook::modifyContact(std::ostream &os) {
    if(d.getsize()==0)
        std::cout << "NINCS KONTAKT!\n";
    else {
        int index;
        int choosingAttribute;
        d.list(os);
        index= readIndexInput("MELYIK KONTAKTOT MODOSITANAD?:", 1, d.getsize());
        Contact& c=d[index-1];
        std::cout << "MIT MODOSITANAL RAJTA?\n"
                  << "VEZETEKNEV         [1]\n"
                  << "KERESZTNEV         [2]\n"
                  << "BECENEV            [3]\n"
                  << "CIM                [4]\n"
                  << "MUNKAHElY SZAM     [5]\n"
                  << "PRIVAT SZAM        [6]\n";
        if(dynamic_cast<Patient*>(&c))
            std::cout <<"EG.GUGYI ALLAPOTA  [7]\n"
                      <<"KEZELOORVOS NEVE   [8]\n";
        else if(dynamic_cast<Doctor*>(&c))
            std::cout <<"SPECIALIZACIO      [7]\n"
                      <<"MUNKAHELY NEVE     [8]\n";
        choosingAttribute= readIndexInput("VALASZTAS:", 1, 8);
        d.modify(choosingAttribute, c);
    }
}

void Phonebook::saveToFile() {
    std::ofstream file("contact_database.txt");
    for (size_t i=0; i<d.getsize(); ++i) {
        file << d[i].serialize() << std::endl;
    }
}

void Phonebook::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "NEM SIKERULT A FAJL MEGNYITASA!\n";
        return;
    }

    std::string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        try {
            Contact* c = Contact::deserialize(line);
            d.add(c);
        } catch (const std::exception& e) {
            std::cerr << "HIBAS SOR: " << e.what() << '\n';
        }
    }
    file.close();
}
