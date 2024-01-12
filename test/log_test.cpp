// Copyright 2024 Raphaêl Faure

#include "../src/log/logger.hpp"
#include <fstream>
#include <gtest/gtest.h>
#include <sstream>
#include <string>

// This test aims to ensure that the logger can log correctly to both a file and
// stdout
TEST(logger_test, file_logger) {
  // Begin stdout capture
  testing::internal::CaptureStdout();
  Logger *logger = new Logger();

  // Create log file
  int out_result = logger->link_output_file("test.log");
  EXPECT_EQ(out_result, 0);

  // Trigger logger
  logger->warning << "test";

  // Assert stdout
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("\033[33m[WARNING] \033[0mtest\n", output);

  // Open file
  std::ifstream logfile;
  logfile.open("test.log");
  std::stringstream buffer;

  delete logger;

  buffer << logfile.rdbuf();

  ASSERT_TRUE(logfile);
  EXPECT_EQ("\033[33m[WARNING] \033[0mtest\n", buffer.str());
}
