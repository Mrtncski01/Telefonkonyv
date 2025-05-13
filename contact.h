#ifndef PHONEBOOK_CONTACT_H
#define PHONEBOOK_CONTACT_H
#include "name.h"
#include <iostream>

class Contact {
protected:
    Name name;
    std::string privatePhone;
    std::string workPhone;
    std::string address;
public:
    Contact(const Name& newName,
            const std::string& newPrivatePhone,
            const std::string& newWorkPhone,
            const std::string& newAddress) : name(newName), privatePhone(newPrivatePhone), workPhone(newWorkPhone), address(newAddress) {}
    Name& getName() ;
    std::string getAddress() const;
    std::string getWorkPhone() const;
    std::string getPrivatePhone() const;
    void setAddress(std::string newAddress);
    void setWorkPhone(std::string newWorkPhone);
    void setPrivatePhone(std::string newPrivatePhone);
    bool operator==(const std::string& s) const;
    virtual void print(std::ostream& os) const = 0;
    virtual std::string serialize() const = 0;
    static Contact* deserialize(const std::string& line);
    virtual ~Contact() {}
};


#endif // PHONEBOOK_CONTACT_H
