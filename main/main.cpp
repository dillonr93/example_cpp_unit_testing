#include "constructor_work.h"

int main(){ 

  ConsoleInput consoleInput;
  ConsoleOutput consoleOutput;
  
  IntConverter converter;
  ConsoleDateInputter dateInputter(consoleInput,converter);

  consoleOutput.output("Enter birth year \n");
  dateInputter.requestYear();

  consoleOutput.output("Enter birth month \n");
  dateInputter.requestMonth();

  consoleOutput.output("Enter birth day \n");
  dateInputter.requestDay();

  auto birthday = dateInputter.getInputtedDate();

  AgeCalculator calculator;

  auto age = calculator.calculate(birthday.year,birthday.month,birthday.day);  

  return 0;
}

