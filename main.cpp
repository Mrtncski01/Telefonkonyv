#include <iostream>
#include "Name.h"
#include "Doctor.h"
#include "Patient.h"
#include "Phonebook.h"

int main() {
    Name name1("John", "Doe", "Johnny");
    std::cout << "Firstname: " << name1.getFirstname() << std::endl;
    std::cout << "Lastname: " << name1.getLastname() << std::endl;
    std::cout << "Nickname: " << name1.getNickname() << std::endl;

    Doctor doc(name1, "12345", "54321", "Budapest", "Kardiológia", "Kórház");
    std::cout << "\nDoctor info:\n";
    doc.print(std::cout);

    Name name2("Jane", "Smith", "Janie");
    Patient pat(name2, "98765", "56789", "Szeged", "Asztma", "Dr. House");
    std::cout << "\nPatient info:\n";
    pat.print(std::cout);

    Phonebook pb;
    pb.addContact(new Doctor(name1, "11111", "22222", "Budapest", "Sebészet", "Kórház2"));
    pb.addContact(new Patient(name2, "33333", "44444", "Pécs", "Allergia", "Dr. Wilson"));

    std::cout << "\nPhonebook list:\n";
    pb.listContacts();

    return 0;
}