
#ifndef TELEFONKONYV_MENU_H
#define TELEFONKONYV_MENU_H
#include "phonebook.h"

class Menu {
private:
    Phonebook phonebook;
    void displayMainMenu() const;
public:
    void run();
};
#endif //TELEFONKONYV_MENU_H
