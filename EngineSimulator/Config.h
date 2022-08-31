#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Config {
 private:
  std::vector<double> _M;
  std::vector<double> _V;

 public:
  double _I = .0;
  double _t_over = .0;
  double _Hm = .0;
  double _Hv = .0;
  double _C = .0;
  double _t_out = .0;

 public:
  Config();
  explicit Config(std::string inputFile);

  void setTOut(double t_out);
  double getM(double V);
  friend std::ostream& operator<<(std::ostream& out, const Config& cfg);

 private:
  std::vector<double> parseArray(std::istringstream& sin);
};
