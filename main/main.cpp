#include "Person.h"


int main(){ 
  NamePrinter printer;
  Person person = Person(Name("Dillon Ramadhar"));

  printer.print(person.getName());

  return 0;
}

