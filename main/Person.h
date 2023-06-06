#ifndef PERSON_H
#define PERSON_H
#include <string>

#pragma once

struct Name{

  Name(std::string string) : _string(string){}

  Name operator=(const Name &name);
  const std::string _string;
};

bool operator==(const Name &a, const Name &b);
std::ostream &operator<<(std::ostream &os, const Name &name);

struct Animal{
  virtual const Name getName() = 0;
  virtual const Name setName(const Name name) = 0;
};

struct Person : public Animal{

  Person(const Name name) : name(name){}

  const Name getName() override;
  const Name setName(const Name name) override;

private:
  Name name;

};


struct NamePrinter{
  void print(const Name name);
};


#endif