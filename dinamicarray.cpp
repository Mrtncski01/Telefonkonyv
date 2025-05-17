#include "dinamicarray.h"
#include "memtrace.h"

DinamicArray::~DinamicArray() {
    for(size_t i=0; i<size; i++) {
        delete array[i];
    }
    delete[] array;
}

size_t DinamicArray::getsize() const {
    return size;
}

Contact& DinamicArray::operator[](int index) const {
    if(index<0 || index>=size)
        throw "HIBAS INDEX!";
    return *array[index];
}

void DinamicArray::resize() {
    size_t newCapacity = capacity+10;
    Contact **newArray= new Contact *[newCapacity];
    for(size_t i=0; i<size; i++) {
        newArray[i]=array[i];
    }
    delete[] array;
    array=newArray;
    capacity = newCapacity;
}

void DinamicArray::list(std::ostream& os) {
    if(size==0) {
        std::cout << "NINCS KONTAKT!\n";
    }
    for(size_t i=0; i<size; i++) {
        os << '[' << i+1 <<"]. SZEMELY:\n";
        array[i]->print(os);
        os << '\n';
    }
}

void DinamicArray::add(Contact *c) {
    if(size==capacity) {
        resize();
    }
    array[size]=c;
    size++;
}

void DinamicArray::remove(size_t index) {
    if (index<1 || index>size)
        throw std::out_of_range("HIBAS INDEX!");
    delete array[index-1];
    for (size_t i=index; i<size; ++i) {
        array[i-1] = array[i];
    }
    size--;
}

bool DinamicArray::search(std::string find, std::ostream& os) const {
    int index=0;
    for(size_t i=0; i<size; i++) {
        if(*array[i] == find) {
            std::cout << '[' << index+1 << "]. SZEMELY:\n";
            array[i]->print(os);
            std::cout << '\n';
            index++;
            return true;
        }
    }
    return false;
}

void DinamicArray::modify(int modifyingAttribution, Contact& c) {
    switch (modifyingAttribution) {
        case 1: {
            std::string newLast;
            newLast= readStringInput("UJ VEZETEKNEV:");
            c.getName().setLastname(newLast);
            break;
        }
        case 2: {
            std::string newFirst;
            newFirst= readStringInput("UJ KERESZTNEV:");
            c.getName().setFirstname(newFirst);
            break;
        }
        case 3: {
            std::string newNick;
            newNick= readStringInput("UJ BECENEV:");
            c.getName().setNickname(newNick);
            break;
        }
        case 4: {
            std::string newAddr;
            newAddr= readStringInput("UJ CIM:");
            c.setAddress(newAddr);
            break;
            }
        case 5: {
            std::string newWorkP;
            newWorkP= readStringInput("UJ MUNKAHELYI SZAM:");
            c.setWorkPhone(newWorkP);
            break;
        }
        case 6: {
            std::string newPrivateP;
            newPrivateP= readStringInput("UJ PRIVAT SZAM:");
            c.setPrivatePhone(newPrivateP);
            break;
        }
        case 7: {
            std::string extra1;
            if (Patient *p = dynamic_cast<Patient *>(&c)) {
                extra1= readStringInput("UJ EGESZSEGUGYI ALLAPOT:");
                p->setCondition(extra1);
            } else if (Doctor *d = dynamic_cast<Doctor *>(&c)) {
                extra1= readStringInput("UJ SPECIALIZACIO:");
                d->setSpecialization(extra1);
            }
            break;
        }
        case 8: {
            std::string extra2;
            if (Patient *p = dynamic_cast<Patient *>(&c)) {
                std::cout << "UJ KEZELOORVOS NEVE: ";
                extra2= readStringInput("UJ KEZELOORVOS NEVE: ");
                p->setdoctorName(extra2);
            } else if (Doctor *d = dynamic_cast<Doctor *>(&c)) {
                extra2= readStringInput("UJ MUNKAHELY: ");
                d->setWorkplace(extra2);
            }
            break;
        }
    }
}

