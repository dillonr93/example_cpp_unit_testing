#include <cmath>
#include <gtest/gtest.h>
#include <list>
#include "consoledateinputter.h"
#include "absl/time/time.h"
#include "absl/time/clock.h"

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

int age(int nowYear, int nowMonth, int nowDay, int birthYear, int birthMonth, int birthDay){
  
  int ageCounter = nowYear - birthYear;

  if(nowMonth <= birthMonth && nowDay < birthDay){
    ageCounter = ageCounter-1;
  }

  return ageCounter;
}

struct AbstractDate{

  virtual int year() = 0;
  virtual int month() = 0;
  virtual int day() = 0;

};

struct AbslDate : public AbstractDate{

  AbslDate(absl::Time nowTime, absl::TimeZone timeZone) : nowTime(nowTime), timeZone(timeZone){}

  int year() override{
    return nowTime.In(timeZone).year;
  }

  int month() override{
    return nowTime.In(timeZone).year;
  }

  int day() override{
    return nowTime.In(timeZone).year;
  }

private:
  absl::TimeZone timeZone;
  absl::Time nowTime;
};


TEST(DATECOMPARE, DATE){

  AbslDate nowDate(absl::Now(),absl::UTCTimeZone());

  int ageCounter = age(nowDate.year(), nowDate.month(), nowDate.day(), 1993, 8, 1);

  std::cout << ageCounter << std::endl;

}

struct User{};
struct Network{};

/// Direct network effects occur when users can communicate with each other. More users increase the value of the network.
/// More users increases direct value to other users.
struct DirectNetwork : public Network{

  DirectNetwork(std::list<User> users): users(users){}
  
  int size(){
    return users.size();
  }

  void communicate(User a, User b){
  }

  std::list<User> users;
};


/// Complementary goods/service increases as the number of users increase.
struct IndirectNetwork{

};

struct NetworkValueCalculator{

  double valueOfNetwork(int networkSize){
    return std::pow(networkSize, 2);
  }

};


struct Distribution{

  void leverageExistingNetwork(Network network){
    std::cout << "Using other networks" << std::endl;
  }  

  void virality(User a){
    std::cout << "User invites and brings other users. May provide incentive for users." << std::endl;
  }

};

struct GrossMargins{
  
};

struct OperationalScalability{

};

TEST(DIRECT,NETWORK_EFFECT){

  User a,b,c;
  DirectNetwork network({a,b,c});

  EXPECT_EQ(network.size(),3);

  NetworkValueCalculator calculator;

  EXPECT_EQ(calculator.valueOfNetwork(network.size()),9);

  Distribution distribution;
  distribution.leverageExistingNetwork(Network());
  distribution.virality(User());

}