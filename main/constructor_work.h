#include <string>
#include "absl/strings/str_cat.h"

struct Kitchen{
  std::string color;
  void longSetupMethod(){}
};

struct Bedroom{
  std::string color;
  void longSetupMethod(){}
};

/// This class creates objects inside the constructor, which makes it locked to the created kitchen and bedroom.
struct HouseWithWorkInConstructor{
  
  HouseWithWorkInConstructor(){
    kitchen = Kitchen();
    bedroom = Bedroom();
  }

  Kitchen kitchen;
  Bedroom bedroom;
};

/// Passes objects into the constructor, easier to test.
struct HouseWithBetterTestability{

  HouseWithBetterTestability(Kitchen kitchen, Bedroom bedroom) : kitchen(kitchen), bedroom(bedroom){}

  const Kitchen kitchen;
  const Bedroom bedroom;
};

// Constructor that setups object preventing tests from changing them.
struct ConstructorWithSetup{

  ConstructorWithSetup(Kitchen kitchen){
    kitchen.longSetupMethod();
    this->kitchen = kitchen;
  }

  Kitchen kitchen;
};

// Setup of an object should not be the responsiblity of another class.
struct ConstructorWithTestableSetup{
  ConstructorWithTestableSetup(Kitchen kitchenThatIsAlreadySetup) : kitchen(kitchenThatIsAlreadySetup){}

  const Kitchen kitchen;
};