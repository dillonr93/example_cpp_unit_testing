cmake_minimum_required(VERSION 3.10)
project(unit_testing VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(abseil-cpp)

enable_testing()

add_executable(hello_test hello_test.cc)
target_link_libraries(hello_test GTest::gtest_main absl::base absl::strings)

add_executable(main main.cpp)
target_link_libraries(main absl::base absl::strings absl::time)



include(GoogleTest)
gtest_discover_tests(hello_test)
