#pragma once
#include "IEngine.h"

constexpr int MAX_ITERATIONS = 10000;

class TestStand
{
public:
	IEngine* _engine;

	TestStand(IEngine* engine) {
		_engine = engine;
	}

	int test() {
		int i = 0;
		try {
			std::cout << i << "\t " << *_engine << std::endl;
			while (i < MAX_ITERATIONS) {
				_engine->nextStep();
				i++;
				std::cout << i << "\t "<< *_engine << std::endl;
			}
		}
		catch (std::range_error e) {
			std::cout << e.what() << std::endl;
		}
		return i;
	}

};

