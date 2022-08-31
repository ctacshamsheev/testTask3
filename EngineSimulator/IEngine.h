#pragma once

#include <iostream>
#include <string>

class IEngine {
 public:
  virtual void nextStep() = 0;
  virtual double getT() const = 0;
  virtual double getV() const = 0;
  virtual std::string toString() const = 0;

  friend std::ostream& operator<<(std::ostream& out, const IEngine& data);
};