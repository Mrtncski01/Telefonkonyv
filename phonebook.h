#ifndef PHONEBOOK_PHONEBOOK_H
#define PHONEBOOK_PHONEBOOK_H
#include "dinamicarray.h"

//Phonebook osztaly
class Phonebook {
private:
    DinamicArray d;  //a phonebook osztaly leginkabb a felhasznalo-program kommunikacioert felel. a dinamicarray osztaly peldanyat hasznalja fel magaert a modositasokert, konrket muveletekert
public:
    Phonebook() {} //phonebook osztaly konstruktora
    ~Phonebook() {} //phonebook osztaly desktruktora
    void addContact(); //uj kontaktot ad hozza a felhasznalohoz
    void listAllContact(std::ostream &os); //ha a heterogen kollekcio mar tartalmaz adatokat, akkor kiiratja az osszeset egymas ala, ha nincs kiirja hogy nincs kontkakt
    void removeContact(std::ostream &os); //a felhasznalo valasztasaval torol egy tetszoleges adatot
    void searchContact(std::ostream &os); //a felhasznalo beuthet keresztnevet, vezeteknevet, becenevet, vagy privat szamot, es kiiratja az osszes ilyen kontaktot, ami tartalmazza ezt
    void modifyContact(std::ostream& os); //modosit egy tetszoleges adatot
    void saveToFile(); //filebamentesert felel
    void loadFromFile(const std::string& filename); //filebol kiolvasasaert felel
};


#endif //PHONEBOOK_PHONEBOOK_H
