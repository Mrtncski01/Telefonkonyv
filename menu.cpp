#include "menu.h"
#include <iostream>
void Menu::displayMainMenu() const {
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * *\n"
              << "T   E   L   E   F   O   N   K   O   N   Y   V\n"
              << "* * * * * * * * * * * * * * * * * * * * * * *\n"
              << "UJ KONTAKT LETRHOZASA                     [1]\n"
              << "KONTAKT MODOSITASA                        [2]\n"
              << "OSSZES KONTAKT LISTAZASA                  [3]\n"
              << "KONTAKT KERESESE                          [4]\n"
              <<"KONTAKT TORLESE                           [5]\n"
              <<"MENTES ES KILEPES                         [6]\n"
              << "* * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
}

void Menu::run() {
    int userChoice;
    do {
        displayMainMenu();
        std::cout << "OPTION:";
        std::cin >> userChoice;
        switch(userChoice) {
            case 1:
                std::cout << "kontakt letrehozasa, ezt meg kell csinalni\n";
                break;
            case 2:
                std::cout << "kontakt modositasa, ezt meg kell csinalni\n";
                break;
            case 3:
                std::cout << "osszes kontakt listazasa, ezt meg kell csinalni\n";
                break;
            case 4:
                std::cout << "kontakt keresese, ezt meg kell csinalni\n";
                break;
            case 5:
                std::cout << "kontakt torlese, ezt meg kell csinalni\n";
                break;
            case 6:
                break;
            default:
                std::cout << "ERVENYTELEN VALASZTAS\n";
                break;
        }
    }while(userChoice!=6);
    std::cout << "VISZONT LATASRA\n";
}
