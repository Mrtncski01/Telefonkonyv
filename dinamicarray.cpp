#include "dinamicyarray.h"
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
    return *array[index];
}

void DinamicArray::resize() {
    Contact **newArray= new Contact *[capacity+10];
    for(size_t i=0; i<capacity; i++) {
        newArray[i]=array[i];
    }
    capacity+=10;
    delete[] array;
    array=newArray;
}

void DinamicArray::list(std::ostream& os) {
    if(size==0) {
        std::cout << "NINCS KONTAKT!";
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
    delete array[index-1];
    Contact **newArray=new Contact *[size-1];
    for(size_t i=0; i<size; i++) {
        if(i!=(index-1))
            newArray[i]=array[i];
    }
    size-=1;
    delete[] array;
    array=newArray;
}

void DinamicArray::search(std::string find, std::ostream& os) const {
    int index=0;
    for(size_t i=0; i<size; i++) {
        if(*array[i] == find) {
            std::cout << '[' << index+1 << "]. SZEMELY:\n";
            array[i]->print(os);
            std::cout << '\n';
            index++;
        }
    }
}

void DinamicArray::modify(int modifyingAttribution, Contact& c) {
    switch (modifyingAttribution) {
        case 1: {
            std::string newLast;
            std::cout << "UJ VEZETEKNEV: "; std::cin >> newLast;
            c.getName().setLastname(newLast);
            break;
        }
        case 2: {
            std::string newFirst;
            std::cout << "UJ KERESZTNEV: "; std::cin >> newFirst;
            c.getName().setLastname(newFirst);
            break;
        }
        case 3: {
            std::string newNick;
            std::cout << "UJ BECENEV: ";
            std::cin >> newNick;
            c.getName().setNickname(newNick);
            break;
        }
        case 4: {
            std::string newAddr;
            std::cout << "Uj CIM: ";
            std::cin >> newAddr;
            c.setAddress(newAddr);
            break;
            }
        case 5: {
            std::string newWorkP;
            std::cout << "Uj MUNKAHELYI SZAM: ";
            std::cin >> newWorkP;
            c.setWorkPhone(newWorkP);
            break;
        }
        case 6: {
            std::string newPrivateP;
            std::cout << "UJ PRIVAT SZAM: ";
            std::cin >> newPrivateP;
            c.setPrivatePhone(newPrivateP);
            break;
        }
        case 7: {
            std::string newCastSpec;
            if (Patient *p = dynamic_cast<Patient *>(&c)) {
                std::cout << "UJ EGESZSEGUGYI ALLAPOT: ";
                std::cin >> newCastSpec;
                p->setCondition(newCastSpec);
            } else if (Doctor *d = dynamic_cast<Doctor *>(&c)) {
                std::cout << "UJ SPECIALIZACIO: ";
                std::cin >> newCastSpec;
                d->setSpecialization(newCastSpec);
            }
            break;
        }
        case 8: {
            std::string newCastSpec2;
            if (Patient *p = dynamic_cast<Patient *>(&c)) {
                std::cout << "UJ KEZELOORVOS NEVE: ";
                std::cin >> newCastSpec2;
                p->setdoctorName(newCastSpec2);
            } else if (Doctor *d = dynamic_cast<Doctor *>(&c)) {
                std::cout << "UJ MUNKAHELY: ";
                std::cin >> newCastSpec2;
                d->setWorkplace(newCastSpec2);
            }
            break;
        }
        default:
            std::cout << "ROSSZ OPCIO!\n";
    }
}

