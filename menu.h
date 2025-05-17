#ifndef PHONEBOOK_MENU_H
#define PHONEBOOK_MENU_H
#include <iostream>
#include "phonebook.h"

//menu osztaly. ez mutatja a felhasznalonak a menut, ahonnan tud opciokat valasztani.
class Menu {
private:
    void displayMainMenu() const; //a menut mutatja
public:
    Menu() {} //menu osztaly konstruktora
    void run(); //a program futasaert felel, ennek a fuggvenynek az inditasakor kezd el a felhasznalo eloszor kommunikalni a programmal
    ~Menu() {} //menu osztaly destruktora
};


#endif //PHONEBOOK_MENU_H
