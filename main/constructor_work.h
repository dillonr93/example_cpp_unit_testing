#include "abstractio.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/numbers.h"

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

  ConsoleDateInputter(AbstractInput& abstractInput, AbstractNumberConverter<int>& numberConverter):abstractInput(abstractInput), numberConverter(numberConverter) {}
  
  void requestDay(){    
    day = numberConverter.fromString(abstractInput.input());
  }

  void requestMonth(){    
    month = numberConverter.fromString(abstractInput.input());
  }

  void requestYear(){    
    year = numberConverter.fromString(abstractInput.input());
  }

  DateInt getInputtedDate(){
    return DateInt({year,month,day});
  }

private:
  int month,day,year;
  AbstractInput& abstractInput;
  AbstractNumberConverter<int>& numberConverter;

};

struct AgeCalculator{
  // TODO: implement with abseil time library
  int calculate(int year, int month, int day){
    return year+month+day;
  }
};
