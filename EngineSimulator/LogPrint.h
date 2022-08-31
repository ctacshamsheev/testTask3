#pragma once
#include <fstream>

#include "IEngine.h"

class LogPrint {
 private:
  std::ofstream out;

 public:
  explicit LogPrint(std::string outputFile);
  std::ofstream& getOutputStream();

  void printEngineState(const IEngine& engine, int iterations);
};
