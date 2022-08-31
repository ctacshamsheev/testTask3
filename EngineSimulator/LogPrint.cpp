#include "LogPrint.h"

LogPrint::LogPrint(std::string outputFile) {
  out.open(outputFile);
  if (!out.is_open())
    throw std::invalid_argument("file write error: " + outputFile);
}

std::ofstream& LogPrint::getOutputStream() { return out; }

void LogPrint::printEngineState(const IEngine& engine, int iterations) {
  out << iterations << "\t " << engine << std::endl;
}
