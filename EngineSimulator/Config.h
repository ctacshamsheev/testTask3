#pragma once

#include <string>
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
	double _t_out =.0;

public:
	// конструктор с дефолтными значениями
	Config(); 
	// конструктор со значениями из файла
	Config(std::string inputFile);
	// установка наружней температуры
	void setTOut(double t_out);
	// получение момента от скорости, через уравнение прямой 
	double getM(double V);
	// вывод
	friend std::ostream& operator<<(std::ostream& out, const Config& cfg);

private: 
	std::vector<double> parseArray(std::istringstream& sin);
};

