#include "constructor_work.h"

int main(){ 

  ConsoleIO io;
  IntConverter converter;
  ConsoleDateInputter dateInputter(io,converter);

  io.output("Enter birth year \n");
  dateInputter.requestYear();

  io.output("Enter birth month \n");
  dateInputter.requestMonth();

  io.output("Enter birth day \n");
  dateInputter.requestDay();

  auto birthday = dateInputter.getInputtedDate();

  AgeCalculator calculator;

  auto age = calculator.calculate(birthday.year,birthday.month,birthday.day);  

  return 0;
}

