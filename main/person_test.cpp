#include <gtest/gtest.h>
#include "Person.h"

TEST(EQUALS,NameTest){
  auto name1 = Name("Dillon Ramadhar");
  auto name2 = Name("Dillon Ramadhar");

  EXPECT_EQ(name1,name2);
}

TEST(NOTEQUALS,NameTest){
  auto name1 = Name("Dillon Ramadhar");
  auto name2 = Name("Not matching Name");

  EXPECT_FALSE(name1 == name2);

}