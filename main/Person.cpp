#include "Person.h"
#include <iostream>

std::ostream &operator<< (std::ostream & os, const Name &name)
{
  // write obj to stream
  os << name._string;
  return os;
}

Name Name::operator=(const Name &name) {
  return Name(name._string);
}

const Name Person::getName() {
  return name;
}

const Name Person::setName(const Name name) {
  this->name = name;
  return this->name;
}

void NamePrinter::print(const Name name) {
  std::cout << name << std::endl;
}

bool operator==(const Name &a, const Name &b) {
  return a._string == b._string;
}
