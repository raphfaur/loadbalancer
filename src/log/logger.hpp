// Copyright 2024 Raphaël Faure

#include <fstream>
#include <vector>

using std::ofstream;

class Logger;

enum LEVEL { INFO, ERROR, WARNING, SUCCESS };

class Pipe {
public:
  LEVEL level;
  Logger *parent;
};

class Logger {
public:
  Pipe info;
  Pipe error;
  Pipe warning;
  Pipe success;

  std::vector<ofstream *> streams;

  Logger();
  ~Logger();

  /**
   * Link logger output to a new file
   *
   * @param filename The path to the log file
   * @return 0 if successful
   */
  int link_output_file(const char *filename);
};

Pipe &operator<<(Pipe &pipe, const char log[]);
Logger &operator<<(Logger &logger, const char log[]);
