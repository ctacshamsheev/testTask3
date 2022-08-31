#pragma once
#include "IEngine.h"
#include "LogPrint.h"

constexpr int MAX_ITERATIONS = 10000;

class TestStand {
 private:
  IEngine* _engine;
  LogPrint* _log;

 public:
  TestStand(IEngine* engine, LogPrint* log);
  int test();
};
