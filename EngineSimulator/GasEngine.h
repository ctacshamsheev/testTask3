#pragma once
#include <iostream>
#include <string>

#include "Config.h"
#include "IEngine.h"

class GasEngine : public IEngine {
 private:
  Config _cfg;
  double _currentT;
  double _currentV;

 public:
  GasEngine(const Config &cfg, double t_out);

  // Унаследовано через IEngine
  virtual void nextStep() override;

  virtual double getT() const override;
  virtual double getV() const override;

  virtual std::string toString() const override;
};
