// Copyright 2024 Raphaël Faure

#include "./logger.hpp"
#include <iostream>
#include <stdio.h>

#define _RESET "\033[0m"
#define _WARNING "\033[33m"
#define _ERROR "\033[31m"
#define _SUCCESS "\033[32m"

LEVEL &operator<<(LEVEL &level, const char log[]) {
  switch (level) {
  case INFO:
    std::cout << _RESET << "[INFO] " << _RESET << log << "\n";
    break;
  case WARNING:
    std::cout << _WARNING << "[WARNING] " << _RESET << log << "\n";
    break;
  case ERROR:
    std::cout << _ERROR << "[ERROR] " << _RESET << log << "\n";
    break;
  case SUCCESS:
    std::cout << _SUCCESS << "[SUCCESS] " << _RESET << log << "\n";
    break;
  }
  return level;
}

Logger::Logger() {
  info = INFO;
  warning = WARNING;
  error = ERROR;
  success = SUCCESS;
}
