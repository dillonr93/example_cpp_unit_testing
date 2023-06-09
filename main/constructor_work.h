#include <string>
#include "absl/strings/str_cat.h"

#include <iostream>
#include <istream>
#include <ostream>
#include "absl/strings/numbers.h"

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

struct DateInput{

  DateInput(AbstractIO& abstractIO, AbstractNumberConverter<int>& numberConverter):abstractIO(abstractIO), numberConverter(numberConverter) {}
  
  /// TODO: move ouput to different method. 
  void requestDay(std::string message){
    abstractIO.output(message);
    day = numberConverter.fromString(abstractIO.input());
  }

  void requestMonth(std::string message){
    abstractIO.output(message);
    month = numberConverter.fromString(abstractIO.input());
  }

  void requestYear(std::string message){
    abstractIO.output(message);
    year = numberConverter.fromString(abstractIO.input());
  }

  DateInt getDateInt(){
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


struct StdIO : public AbstractIO{

  void output(std::string data) override{
    std::cout << data;
  }

  std::string input() override{
    std::string data;
    std::cin >> data;
    return data;
  }

};
