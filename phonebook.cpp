#include "Phonebook.h"
#include <iostream>
#include "dinamicyarray.h"
#include "memtrace.h"

void Phonebook::listAllContact(std::ostream& os) {
    if(d.getsize()==0) {
        std::cout << "NINCS KONTAKT!";
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
    std::cout <<"OPCIO:";
    std::cin >> choice;
    std::cout << "VEZETEKNEV:"; std::cin >> newLast;
    std::cout << "KERESZTNEV:"; std::cin >> newFirst;
    std::cout << "BECENEV:"; std::cin >> newNick;
    std::cout << "CIM:"; std::cin >> newAddr;
    std::cout << "PRIVAT SZAM:"; std::cin >> newPrivateP;
    std::cout << "MUNKAHELYI SZAM:"; std::cin >> newWorkP;

    Name NewN(newFirst, newLast, newNick);
    if(choice==1) {
        std::string newWorkPl, newSpec;
        std::cout << "MUNKAHELY:"; std::cin >> newWorkPl;
        std::cout << "SPECIALIZACIO:"; std::cin >> newSpec;
        d.add(new Doctor(NewN, newPrivateP, newWorkP, newAddr, newWorkP, newSpec));
    }
    else if(choice==2) {
        std::string newDoc, newCond;
        std::cout << "KEZELOORVOS:"; std::cin >> newDoc;
        std::cout << "EGESZSEGUGYI ALLAPOT:"; std::cin >> newCond;
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
        std::cout << "VALASZTASOD:"; std::cin >> choice;
        d.remove(choice);
    }
}

void Phonebook::searchContact(std::ostream &os) {
    if(d.getsize()==0)
        std::cout << "NINCS KONTAKT!\n";
    else {
        std::string findingContact;
        std::cout << "ADJ MEG VALAMILYEN ADATOT\n";//itt nem tudom hogyan kene esetekre szetbonatni, mert akkor ugye az ==operatornak nem lenne ertelme, esetekre meg nem tudom mennyi ertelme van mert az operator || esetekkel foglalkozik
        std::cout << "ADAT:";
        std::cin >> findingContact;
        d.search(findingContact, os);
    }
}

void Phonebook::modifyContact(std::ostream &os) {
    if(d.getsize()==0)
        std::cout << "NINCS KONTAKT!\n";
    else {
        int index;
        int choosingAttribute;
        d.list(os);
        std::cout << "MELYIK KONTAKTOT MODOSITANAD?:";
        std::cin >> index;
        Contact& c=d[index-1];
        std::cout << "MIT MODOSITANAL RAJTA?\n"
                  << "VEZETEKNEV         [1]\n"
                  << "KERESZTNEV         [2]\n"
                  << "BECENEV            [3]\n"
                  << "CIM                [4]\n"
                  << "MUNKAHElY SZAM     [5]\n"
                  << "PRIVAT SZAM        [6]\n";
        if(dynamic_cast<Patient*>(&c))
            std::cout <<"KEZELOORVOS NEVE   [7]\n"
                      <<"EG.GUGYI ALLAPOTA  [8]\n";
        else if(dynamic_cast<Doctor*>(&c))
            std::cout <<"MUNKAHELY NEVE     [7]\n"
                      <<"SPECIALIZACIO      [8]\n";
        std::cout << "VALASZTAS:"; std::cin >> choosingAttribute;
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
        std::cerr << "Nem sikerült megnyitni a fájlt!\n";
        return;
    }

    std::string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        try {
            Contact* c = Contact::deserialize(line);
            d.add(c);
        } catch (const std::exception& e) {
            std::cerr << "Hibás sor: " << e.what() << '\n';
        }
    }
    file.close();
}
