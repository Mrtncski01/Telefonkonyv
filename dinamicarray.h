#ifndef PHONEBOOK_DINAMICARRAY_H
#define PHONEBOOK_DINAMICARRAY_H
#include <iostream>
#include "contact.h"
#include "doctor.h"
#include "patient.h"
#include "inputmanaging.h"

//Heterogen kollekciohoz osztaly, dinamikus tombbel megvalositva
class DinamicArray {
private:
    size_t size; //tomb felhasznalt terulete
    size_t capacity; //teljes kapacitas, beleertve a meg fel nem hasznalt memoriateruletet
    Contact **array;
public:
    DinamicArray() : array(nullptr),  size(0),  capacity(0){} //konstruktor
    size_t getsize() const; //visszaadja a meretet
    Contact& operator[](int index) const; //visszaadja a tomb egy elemet
    void add(Contact* c); //egy uj kontaktot ad hozza a heterogen kollekciohoz
    void list(std::ostream& os); //kiirja az osszes elemet
    void remove(size_t index); //torol elemet, index segitsegevel
    void resize(); //ujrameretez, ha a size==capacityvel, hogy ne kelljen minden egyes kontakt hozzaadasakor ujrameretezni a tombot
    bool search(std::string find, int userChoice, std::ostream& os) const; //a felhasznalo itt eldontheti milyen funkcio alapjan akar valasztani, es az alapjan megkeresi az osszes olyan kontaktot, es kiiratja, aminek a valasztott attributuma megegyezik  az inputtal
    void modify(int modifyingAttribution, Contact& c); //kontakt modositasa
    ~DinamicArray(); // destruktor
};


#endif //PHONEBOOK_DINAMICARRAY_H
