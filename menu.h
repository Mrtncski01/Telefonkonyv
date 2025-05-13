#ifndef PHONEBOOK_MENU_H
#define PHONEBOOK_MENU_H
#include <iostream>
#include "phonebook.h"


class Menu {
private:
    void displayMainMenu() const;
public:
    Menu() {}
    void run();
    ~Menu() {}
};


#endif //PHONEBOOK_MENU_H
