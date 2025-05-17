#ifndef PHONEBOOK_INPUTMANAGING_H
#define PHONEBOOK_INPUTMANAGING_H
#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include <sstream>

inline int readIndexInput(const std::string& prompt, int minInterval, int maxInterval) { //ez felel a helyes index beviteleert
    int value;
    std::cout << prompt;
    if (!(std::cin >> value)) { //megvizsgalja hogy egyaltalan szam-e
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("HIBAS A BEMENET, SZAMOT VAROK!");
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (value < minInterval || value > maxInterval) //megvizsgalja hogy megfelelo tartomanyba valasztott-e szamot
        throw std::out_of_range("HIBAS INDEX!");
    return value;
}


inline std::string readStringInput(const std::string& prompt) { //string beviteleert felel
    std::string value;
    const std::string forbiddenChars = "|$";
    bool valueIsValid = false;

    while (!valueIsValid) {
        std::cout << prompt;
        std::getline(std::cin, value);

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("OLVASASI HIBA");
        } else if (value.empty()) {
            throw std::invalid_argument("URES BEMENET!");
        } else if (value.find_first_of(forbiddenChars) != std::string::npos) {
            throw std::invalid_argument("TILTOTT KARAKTERT HASZNALTAL: | vagy $"); //megvizsgalja hogy nem irt-e bele tiltott karatkereket, azokat amit filebeolvasahoz hasznaltunk
        } else {
            valueIsValid = true;
        }
    }

    return value;
}




#endif //PHONEBOOK_INPUTMANAGING_H
