#include <gtest/gtest.h>
#include "constructor_work.h"

TEST(AGE,AgeCalculator){

  AgeCalculator calculator;
  auto age = calculator.calculate(2001, 12, 1);

  EXPECT_EQ(age, 2014);
}