#include "constructor_work.h"

int main(){ 

  StdIO io;
  IntConverter converter;
  DateInput dateInput(io,converter);

  dateInput.requestYear("Enter birth year \n");
  dateInput.requestMonth("Enter birth month \n");
  dateInput.requestDay("Enter birth day \n");  

  auto birthday = dateInput.getDateInt();

  AgeCalculator calculator;

  auto age = calculator.calculate(birthday.year,birthday.month,birthday.day);  

  return 0;
}

