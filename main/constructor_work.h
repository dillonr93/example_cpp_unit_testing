#include "abstractio.h"
#include "abstractnumberconverter.h"

struct DateInt{
  const int year,month,day;
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
