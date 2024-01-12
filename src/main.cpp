// "Copyright 2024 Raphaël Faure"

#include "log/logger.hpp"
#include <iostream>
#include <ostream>
#include <valarray>

int main(int argc, char *argv[]) {
  Logger *logger = new Logger();
  logger->info << "bb";
}


