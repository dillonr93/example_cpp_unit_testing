#include <gtest/gtest.h>
#include "absl/strings/str_join.h"
#include "absl/time/civil_time.h"

TEST(HelloTest,BasicAssertions){

  EXPECT_DOUBLE_EQ(2, 2);
  absl::CivilMinute j;

  std::cout << j.day();
}