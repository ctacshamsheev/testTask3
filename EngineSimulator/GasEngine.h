#pragma once
#include "IEngine.h"
#include "Config.h"
#include <string>
#include <iostream>

class GasEngine :
    public IEngine
{
private:
    Config _cfg;
    double _currentT;
    double _currentV;

public:
    GasEngine(Config &cfg , double t_out);

    // Унаследовано через IEngine
    virtual void nextStep() override;

    virtual double getT() override;
    virtual double getV() override;

    virtual std::string toString() const override;
};
