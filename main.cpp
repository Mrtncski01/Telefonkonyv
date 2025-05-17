#include "gtest_lite.h"
#include "dinamicarray.h"
#include "doctor.h"
#include "patient.h"
#include "inputmanaging.h"
#include "phonebook.h"
#include "menu.h"
#include <sstream>
#include "memtrace.h"
#define CPORTA


#ifdef CPORTA //tesztek futnak le
int main() {
TEST(ContactTest, GettersAndSetters) {
    Name name("Anna", "Kovacs", "Anci");
    Doctor d(name, "123", "321", "Budapest", "Korhaz", "Sebesz");
    EXPECT_TRUE(d.getName().getFirstname() == "Anna");
    EXPECT_TRUE(d.getName().getLastname() == "Kovacs");
    EXPECT_TRUE(d.getName().getNickname() == "Anci");
    EXPECT_TRUE(d.getPrivatePhone() == "123");
    EXPECT_TRUE(d.getWorkPhone() == "321");
    EXPECT_TRUE(d.getAddress() == "Budapest");
    EXPECT_TRUE(d.getWorkplace() == "Korhaz");
    EXPECT_TRUE(d.getSpecialization() == "Sebesz");

    d.setPrivatePhone("456");
    d.setWorkPhone("654");
    d.setAddress("Szeged");
    d.setWorkplace("Repter");
    d.setSpecialization("Legiutaskisero");

    EXPECT_TRUE(d.getPrivatePhone() == "456");
    EXPECT_TRUE(d.getWorkPhone() == "654");
    EXPECT_TRUE(d.getAddress() == "Szeged");
    EXPECT_TRUE(d.getWorkplace() == "Repter");
    EXPECT_TRUE(d.getSpecialization() == "Legiutaskisero");
} END

TEST(ContactTest, Compare) {
    Name name("Anna", "Kovacs", "Anci");
    Doctor d(name, "123", "321", "Budapest", "Korhaz", "Sebesz");

    EXPECT_TRUE(d.contactMatches("Kovacs" , 1));
    EXPECT_TRUE(d.contactMatches("Anna" , 2));
    EXPECT_TRUE(d.contactMatches("Anci" , 3));
    EXPECT_TRUE(d.contactMatches("123", 4));
    EXPECT_FALSE(d.contactMatches("Lena", 1));
} END

TEST(ContactTest, Deserialization) {
    std::string doc_line = "1|Kiss|Ferenc|Feri|Pest|234|123|Agysebesz|Korhaz|$";
    Contact* doc = Contact::deserialize(doc_line);

    EXPECT_TRUE(doc->getName().getFirstname() == "Ferenc");
    EXPECT_TRUE(doc->getName().getLastname() == "Kiss");
    EXPECT_TRUE(doc->getName().getNickname() == "Feri");
    EXPECT_TRUE(doc->getPrivatePhone() == "123");
    EXPECT_TRUE(doc->getWorkPhone() == "234");
    EXPECT_TRUE(doc->getAddress() == "Pest");
    
    std::string pac_line = "0|Nagy|Pista|Pisti|Szeged|654|456|Beteg|Kiss Ferenc|$";
    Contact* pac = Contact::deserialize(pac_line);

    EXPECT_TRUE(pac->getName().getFirstname() == "Pista");
    EXPECT_TRUE(pac->getName().getLastname() == "Nagy");
    EXPECT_TRUE(pac->getName().getNickname() == "Pisti");
    EXPECT_TRUE(pac->getPrivatePhone() == "456");
    EXPECT_TRUE(pac->getWorkPhone() == "654");
    EXPECT_TRUE(pac->getAddress() == "Szeged");

} END


TEST(DynamicArrayTest, AddAndGetSize) {
    DinamicArray arr;
    EXPECT_EQ(arr.getsize(), (size_t)0);
    arr.add(new Doctor(Name("Eva", "Szabo", "Evike"), "1234", "5678", "Debrecen", "Rendelő", "Fogorvos"));
    EXPECT_EQ(arr.getsize(), (size_t)1);
} END

TEST(DynamicArrayTest, IndexOperator) {
    DinamicArray arr;
    arr.add(new Doctor(Name("Peter", "Nagy", "Peti"), "111", "222", "Szeged", "Korhaz", "Ortoped"));
    EXPECT_NO_THROW(arr[0]);
    EXPECT_THROW(arr[-1], const char*);
    EXPECT_THROW(arr[1], const char*);
} END

TEST(DynamicArrayTest, RemoveValidAndInvalid) {
    DinamicArray arr;
    arr.add(new Doctor(Name("Tamas", "Feher", "Tomi"), "000", "111", "Pecs", "Korhaz", "Urologus"));
    EXPECT_EQ(arr.getsize(), (size_t)1);
    EXPECT_NO_THROW(arr.remove(1));
    EXPECT_EQ(arr.getsize(), (size_t)0);
    EXPECT_THROW(arr.remove(1), std::out_of_range);
} END

TEST(SerializationTest, SerializeDeserializeDoctor) {
    Doctor doc(Name("Erika", "Kiss", "Eri"), "999", "888", "Miskolc", "Korhaz", "Radiologus");
    std::string line = doc.serialize();
    Contact* c = Contact::deserialize(line);
    EXPECT_TRUE(c != nullptr);
    EXPECT_TRUE(c->getName().getFirstname() == "Erika");
    delete c;
} END

TEST(EdgeCases, NullArrayAccess) {
    DinamicArray arr;
    EXPECT_THROW(arr[0], const char*);
} END
}
#else
int main() { //felhasznaloi modban fut le a menu
    Menu m;
    m.run(); //a menu objektuma elinditja magát a programot
    return 0;
}
#endif
