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
#ifdef CPORTA
int main() {
TEST(ContactTest, EqualityOperator) {
    Name name("Anna", "Kovacs", "Anci");
    Doctor d(name, "123", "321", "Budapest", "Korhaz", "Sebesz");
    EXPECT_TRUE(d == "Anna");
    EXPECT_TRUE(d == "Kovacs");
    EXPECT_TRUE(d == "Anci");
    EXPECT_TRUE(d == "123");
    EXPECT_FALSE(d == "nemletezo");
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
    EXPECT_THROW(arr.remove(1), const char*);
} END

TEST(SerializationTest, SerializeDeserializeDoctor) {
    Doctor doc(Name("Erika", "Kiss", "Eri"), "999", "888", "Miskolc", "Korhaz", "Radiologus");
    std::string line = doc.serialize();
    Contact* c = Contact::deserialize(line);
    EXPECT_TRUE(c != nullptr);
    EXPECT_TRUE(*c == "Erika");
    delete c;
} END

TEST(EdgeCases, NullArrayAccess) {
    DinamicArray arr;
    EXPECT_THROW(arr[0], const char*);
} END
}
#else
int main() {
    Menu m;
    m.run();
    return 0;
}
#endif
