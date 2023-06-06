cc_binary(
  name = "main",
  srcs = ["main.cpp"],
  deps = [":person"],
  visibility = ["//visibility:public"],
)

cc_library(
  name = "person",  
  srcs = ["Person.cpp"],
  hdrs = ["Person.h"],
  deps = ["@com_google_absl//absl/strings","@com_google_googletest//:gtest_main"],
  visibility = ["//visibility:public"],
)

cc_test(
  name = "person_test",
  size = "small",
  srcs = ["person_test.cpp"],
  deps = [":person"],
  visibility = ["//visibility:public"],
)