#include <string>
#include "absl/strings/str_cat.h"

#include <iostream>
#include <istream>
#include <ostream>
#include "absl/strings/numbers.h"


/// TODO: separate input from output
struct AbstractIO{
  virtual void output(std::string data) = 0;
  virtual std::string input() = 0;
};

struct DateInt{
  const int year,month,day;
};

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

struct ConsoleDateInputter{

  ConsoleDateInputter(AbstractIO& abstractIO, AbstractNumberConverter<int>& numberConverter):abstractIO(abstractIO), numberConverter(numberConverter) {}
  
  void requestDay(){    
    day = numberConverter.fromString(abstractIO.input());
  }

  void requestMonth(){    
    month = numberConverter.fromString(abstractIO.input());
  }

  void requestYear(){    
    year = numberConverter.fromString(abstractIO.input());
  }

  DateInt getInputtedDate(){
    return DateInt({year,month,day});
  }

private:
  int month,day,year;
  AbstractIO& abstractIO;
  AbstractNumberConverter<int>& numberConverter;

};

struct AgeCalculator{
  // TODO: implement with abseil time library
  int calculate(int year, int month, int day){
    return year+month+day;
  }
};


struct ConsoleIO : public AbstractIO{

  void output(std::string data) override{
    std::cout << data;
  }

  std::string input() override{
    std::string data;
    std::cin >> data;
    return data;
  }

};
