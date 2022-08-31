#include "TestStand.h"

TestStand::TestStand(IEngine* engine, LogPrint* log) {
	_engine = engine;
	_log = log;
}

int TestStand::test()
{
	int i = 0;
	try {
		while (i <= MAX_ITERATIONS) {
			_log->printEngineState(*_engine, i);
			i++;
			_engine->nextStep();
		}
	}
	catch (std::range_error e) {
		_log->printEngineState(*_engine, i);
	}
	if (i >= MAX_ITERATIONS) {
		throw std::invalid_argument("Engine simulation calculation exceeded the maximum threshold :" + std::to_string(MAX_ITERATIONS));
	}
	return i;
}
