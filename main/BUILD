cc_binary(
  name = "app",
  srcs = ["main.cpp"],
  deps = [":testable_code"],
  visibility = ["//visibility:public"],
)

cc_library(
  name = "testable_code",
  hdrs = ["constructor_work.h","abstractio.h","abstractnumberconverter.h"],
  srcs = ["abstractio.cpp","abstractnumberconverter.cpp"],
  deps = ["@com_google_absl//absl/strings","@com_google_googletest//:gtest_main"],
  visibility = ["//visibility:public"],
)

cc_test(
  name = "tests",
  size = "small",
  srcs = ["testable_code.cpp"],
  deps = [":testable_code"],
  visibility = ["//visibility:public"],
)