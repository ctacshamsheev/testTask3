#include "Config.h"
#include <iostream>

Config::Config() : _M{20, 75, 100, 105, 75, 0}, _V{0, 75, 150, 200, 250, 300} {
  _I = 10.0;
  _t_over = 110.0;
  _Hm = 0.01;
  _Hv = 0.0001;
  _C = 0.1;
}

Config::Config(std::string inputFile) {
  std::ifstream fin(inputFile);
  std::string line;
  bool i, m, v, t, hm, hv, c;
  i = m = v = t = hm = hv = c = false;

  if (fin.is_open()) {
    while (getline(fin, line)) {
      std::istringstream sin(line.substr(line.find("=") + 1));
      if (line.find("I") != -1) {
        sin >> _I;
        i = true;
      } else if (line.find("M") != -1) {
        _M = parseArray(sin);
        m = true;
      } else if (line.find("V ") != -1) {
        _V = parseArray(sin);
        v = true;
      } else if (line.find("T") != -1) {
        sin >> _t_over;
        t = true;
      } else if (line.find("Hm") != -1) {
        sin >> _Hm;
        hm = true;
      } else if (line.find("Hv") != -1) {
        sin >> _Hv;
        hv = true;
      } else if (line.find("C") != -1) {
        sin >> _C;
        c = true;
      }
    }
  } else {
    throw std::invalid_argument("file does not exist: " + inputFile);
  }
  fin.close();
  if (_M.size() != _V.size()) {
    throw std::invalid_argument("invalid array read: M.size() != V.size(). " +
                                inputFile);
  }
  if (!(i && m && v && t && hm && hv && c)) {
      std::cout << i<< m<< v<< t<<hm << hv<<c;
    throw std::invalid_argument("missing configuration variables: " +
                                inputFile);
  }
}

void Config::setTOut(double t_out) { _t_out = t_out; }

double Config::getM(double V) {
  if (V < _V.front() || V > _V.back()) {
    return 0.0;
    // throw std::invalid_argument("speed out of range");
  }
  long unsigned int i = 0;
  while (i < _M.size()) {
    if (V == _V[i]) {
      return _M[i];
    } else if (V < _V[i]) {
      return ((V - _V[i - 1]) / (_V[i] - _V[i - 1])) * (_M[i] - _M[i - 1]) +
             _M[i - 1];
    } else {
      i++;
    }
  }
  return 0.0;
}

std::vector<double> Config::parseArray(std::istringstream& sin) {
  std::vector<double> arr;
  sin.ignore(2);
  while (sin) {
    double f = -1.0;
    sin >> f;
    sin.ignore(1, ' ');
    if (f >= 0.0) arr.push_back(f);
  }
  return arr;
}

std::ostream& operator<<(std::ostream& out, const Config& cfg) {
  out << "I = " << cfg._I << std::endl;

  out << "M = {";
  bool first = true;
  for (auto p : cfg._M) {
    if (first)
      first = false;
    else
      out << ", ";
    out << p;
  }
  out << "}" << std::endl;

  out << "V = {";
  first = true;
  for (auto p : cfg._V) {
    if (first)
      first = false;
    else
      out << ", ";
    out << p;
  }
  out << "}" << std::endl;

  out << "T = " << cfg._t_over << std::endl;
  out << "Hm = " << cfg._Hm << std::endl;
  out << "Hv = " << cfg._Hv << std::endl;
  out << "C = " << cfg._C << std::endl;
  return out;
}