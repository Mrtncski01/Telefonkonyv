#include "menu.h"
#include "memtrace.h"

void Menu::displayMainMenu() const {
    std::cout << "\n* * * * * * * * * * * * * * * * * * * * * * *\n"
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
    std::ostream& os = std::cout;
    Phonebook pb;
    pb.loadFromFile("contact_database.txt");
    int userChoice;
    do {
        displayMainMenu();
        std::cout << "OPCIO:";
        std::cin >> userChoice;
        switch(userChoice) {
            case 1:
                pb.addContact();
                break;
            case 2:
                pb.modifyContact(os);
                break;
            case 3:
                pb.listAllContact(os);
                break;
            case 4:
                pb.searchContact(os); //itt az eseteket kéne szétbontani, de nem jut semmi eszembe
                break;
            case 5:
                pb.removeContact(os);
                break;
            case 6:
                break;
            default:
                std::cout << "ERVENYTELEN VALASZTAS!\n";
                break;
        }
    }while(userChoice!=6);
    pb.saveToFile();
    std::cout << "VISZONT LATASRA!\n"; /*filekezelés*/ /*teszteket meg kéne írni*/
}
