#ifndef TELEFONKONYV_CONTACT_H
#define TELEFONKONYV_CONTACT_H
#include "name.h"
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
    std::string getAddress() const {
        return address;
    }
    std::string getWorkPhone() const {
        return workPhone;
    }
    std::string getPrivatePhone() const {
        return privatePhone;
    }
    virtual bool operator==(const Contact& c) const=0;
    virtual void print(std::ostream& os) const = 0;
    virtual ~Contact()=0;
};
std::ostream& operator<<(std::ostream& os, const Contact& c);
#endif //TELEFONKONYV_CONTACT_H
