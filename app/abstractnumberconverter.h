#ifndef ABSTRACTNUMBERCONVERTER_H
#define ABSTRACTNUMBERCONVERTER_H
#pragma once

#include <string>
#include "absl/strings/numbers.h"
#include "absl/strings/str_cat.h"

template <typename T>
struct AbstractNumberConverter{

  virtual T fromString(std::string string) = 0;
  virtual std::string toString(T number) = 0;
  
};

struct IntConverter : public AbstractNumberConverter<int>{

  int fromString(std::string string) override{
    int number;

    if(absl::SimpleAtoi(string,&number)){
      return number;
    }      

    return 0;
  }

  std::string toString(int number) override{
    return absl::StrCat(number);
  }
};



#endif