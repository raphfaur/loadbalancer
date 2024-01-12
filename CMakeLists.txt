cmake_minimum_required(VERSION 3.14)
project(LOADBALANCER VERSION 0.0.1)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Generate compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # does not produce the json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") # works

# Add log library
add_library(logger src/log/logger.cpp src/log/logger.hpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(loadbalancer src/main.cpp)
target_link_libraries(logger)

enable_testing()

add_executable(
  logger_test
  test/log_test.cpp
)
target_link_libraries(
  logger_test
  GTest::gtest_main
  logger
)

include(GoogleTest)
gtest_discover_tests(logger_test)
