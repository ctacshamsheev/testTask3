#pragma once

#include <string>

#include <iostream>

class IEngine
{
public:
	virtual void nextStep() = 0;
	virtual double getT() = 0;
	virtual double getV() = 0;
	virtual std::string toString() const  = 0;
	
	friend std::ostream& operator<<(std::ostream& out, const IEngine& data);

};