// Copyright 2024 Raphaël Faure

#include "./logger.hpp"
#include <fstream>
#include <iostream>
#include <unistd.h>

#define _RESET "\033[0m"
#define _WARNING "\033[33m"
#define _ERROR "\033[31m"
#define _SUCCESS "\033[32m"

using std::ofstream;

Pipe &operator<<(Pipe &pipe, const char log[]) {
  Logger *parent = pipe.parent;
  switch (pipe.level) {
  case INFO:
    *parent << _RESET << "[INFO] " << _RESET << log << "\n";
    break;
  case WARNING:
    *parent << _WARNING << "[WARNING] " << _RESET << log << "\n";
    break;
  case ERROR:
    *parent << _ERROR << "[ERROR] " << _RESET << log << "\n";
    break;
  case SUCCESS:
    *parent << _SUCCESS << "[SUCCESS] " << _RESET << log << "\n";
    break;
  }
  return pipe;
}

Logger &operator<<(Logger &logger, const char data[]) {
  for (ofstream *s : logger.streams) {
    *s << data;
    s->flush();
  }
  std::cout << data;
  return logger;
}

Logger::Logger() {
  info = Pipe{INFO, this};
  warning = Pipe{WARNING, this};
  error = Pipe{ERROR, this};
  success = Pipe{SUCCESS, this};
}

Logger::~Logger() {
  for (ofstream *s : streams) {
    s->close();
  }
}

int Logger::link_output_file(const char *filename) {
  ofstream *stream = new ofstream();
  stream->open(filename);
  if (stream->fail()) {
    return -1;
  } else {
    streams.insert(streams.end(), stream);
    return 0;
  }
}
