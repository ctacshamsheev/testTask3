#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>

class Config
{
private:
	std::vector<double> _M;
	std::vector<double> _V;

public:
	double _I=.0;
	double _t_over = .0;
	double _Hm = .0;
	double _Hv = .0;
	double _C = .0;
	double _t_out = 100;

public:
	Config();
	Config(std::string inputFile);

	friend std::ostream& operator<<(std::ostream& out, const Config& cfg);

	void setTOut(double t_out) {
		_t_out = t_out;
	}

private: 
	std::vector<double> parseArray(std::istringstream& sin);
};

