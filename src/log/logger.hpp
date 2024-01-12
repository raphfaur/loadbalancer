// Copyright 2024 Raphaël Faure

enum LEVEL { INFO, ERROR, WARNING, SUCCESS };

class Logger {
public:
  LEVEL info;
  LEVEL error;
  LEVEL warning;
  LEVEL success;
  Logger();
};

LEVEL &operator<<(LEVEL &level, const char log[]);
