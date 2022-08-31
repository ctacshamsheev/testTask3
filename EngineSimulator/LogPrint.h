#pragma once
#include <fstream>
#include "IEngine.h"

class LogPrint
{
private:
	std::ofstream out;
public:
	LogPrint(std::string outputFile);
	std::ofstream& getOutputStream();

	void printEngineState(IEngine &engine, int iterations);
};

