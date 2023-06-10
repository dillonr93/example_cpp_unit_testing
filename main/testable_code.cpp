#include <gtest/gtest.h>
#include "constructor_work.h"

TEST(ConsoleInput,CONSOLE){  
}

TEST(AGE,AgeCalculator){

  AgeCalculator calculator;
  auto age = calculator.calculate(2001, 12, 1);

  EXPECT_EQ(age, 2014);
}

TEST(INTCONVERTER,CONVERTER){

  IntConverter converter;
  auto number = converter.fromString("788");

  EXPECT_EQ(number, 788);

  auto string = converter.toString(number);  

  EXPECT_EQ(string, "788");
}