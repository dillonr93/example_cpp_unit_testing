#ifndef ABSTRACTIO_H
#define ABSTRACTIO_H
#pragma once

#include <string>
#include <iostream>

struct AbstractOutput{
  virtual void output(std::string data) = 0;
};

struct AbstractInput{
  virtual std::string input() = 0;  
};


struct ConsoleInput : public AbstractInput{

  std::string input() override{
    std::string data;
    std::cin >> data;
    return data;
  }

};

struct ConsoleOutput : public AbstractOutput{

  void output(std::string data) override{
    std::cout << data;
  }

};



#endif