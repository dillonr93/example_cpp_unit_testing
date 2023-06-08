#include <string>
#include "absl/strings/str_cat.h"

#include <iostream>
#include <istream>
#include <ostream>
#include "absl/strings/numbers.h"

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


struct AbstractIO{
  virtual void output(std::string data) = 0;
  virtual std::string input() = 0;
};

struct DateInt{
  const int year,month,day;
};

struct DateInput{

  DateInput(AbstractIO& abstractIO):abstractIO(abstractIO){}
  
  void requestDay(std::string message){
    abstractIO.output(message);

    //TODO: wrap static method in an interface.
    absl::SimpleAtoi(abstractIO.input(),&day);
  }

  void requestMonth(std::string message){
    abstractIO.output(message);
    absl::SimpleAtoi(abstractIO.input(),&month);
  }

  void requestYear(std::string message){
    abstractIO.output(message);
    absl::SimpleAtoi(abstractIO.input(),&year);
  }

  DateInt getDateInt(){
    return DateInt({year,month,day});
  }

private:
  int month,day,year;
  AbstractIO& abstractIO;

};

struct AgeCalculator{
  // TODO: implement with abseil time library
  int calculate(int year, int month, int day){
    return year+month+day;
  }
};


struct StdIO : public AbstractIO{

  void output(std::string data) override{
    std::cout << data;
  }

  std::string input() override{
    std::string data;
    std::cin >> data;
    return data;
  }

};
