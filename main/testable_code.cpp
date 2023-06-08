#include <gtest/gtest.h>
#include "constructor_work.h"

TEST(CONSTRUCTOR_WORK, CONSTRUCTOR){

  HouseWithWorkInConstructor houseWithWorkInConstructor;

  HouseWithBetterTestability houseWithBetterTestability = HouseWithBetterTestability(Kitchen({"Grey"}), Bedroom({"White"}));
}

TEST(CONSTRUCTOR_SETUP, CONSTRUCTOR){
  auto kitchen = Kitchen();
  kitchen.longSetupMethod();

  ConstructorWithTestableSetup setupGood(kitchen);  
}