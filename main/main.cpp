#include "constructor_work.h"

int main(){ 

  StdIO io;
  DateInput birthdayInput(io);

  birthdayInput.requestYear("Enter birth year \n");
  birthdayInput.requestMonth("Enter birth month \n");
  birthdayInput.requestDay("Enter birth day \n");  

  auto birthday = birthdayInput.getDateInt();

  AgeCalculator calculator;

  auto age = calculator.calculate(birthday.year,birthday.month,birthday.day);  

  std::cout << age;


  return 0;
}

