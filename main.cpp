#include <iostream>
#include "absl/strings/str_cat.h"
#include "absl/time/clock.h"
#include "absl/time/time.h"

int main(int, char**){

    auto time = absl::Now();
    absl::TimeZone i;

    std::cout << "Hello, from unit_testing!\n";
    std::cout << i.At(time).cs << std::endl;

    std::cout << absl::StrCat(2,3983) << std::endl;
}
