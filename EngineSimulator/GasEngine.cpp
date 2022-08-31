#include "GasEngine.h"

GasEngine::GasEngine(Config& cfg, double t_out)
{
	// при старте начинает с нулевой скорости вращения.
	_currentV = 0;
	//Температура двигателя до момента старта должна равняться температуре окружающей среды. 
	_currentT = t_out;
	_cfg = cfg;
	_cfg.setTOut(t_out);
}

void GasEngine::nextStep()
{
	// нахождение М через уравнение прямой по 2м точкам.
	double M = _cfg.getM(_currentV);

	// V = V0 + at 
	// V0 = 0; a = M/I; t = 1;
	// V = V + M/I;
	_currentV += M / _cfg._I;

	// Скорость нагрева двигателя рассчитывать как 
	// VH = M × HM + V^2 × HV (С/сек);
	double Vh = (M * _cfg._Hm) + (_currentV * _currentV * _cfg._Hv);

	// Скорость охлаждения двигателя рассчитывать как 
	// VC = C × (Tсреды - Тдвигателя) (С/сек)
	double Vc = _cfg._C * (_cfg._t_over - _currentT);

	// Нагрев и охлаждение, действуют на двигатель одновременно и независимо
	_currentT += Vh + Vc;

	if (_currentT >= _cfg._t_over) {
		throw std::range_error("the current temperature exceeds the critical: Tcur = " +
			std::to_string(_currentT) + " Tcr = " + std::to_string(_cfg._t_over));
	}
}

double GasEngine::getT()
{
	return _currentT;
}

double GasEngine::getV()
{
	return _currentV;
}

std::string GasEngine::toString() const
{
	std::stringstream ss;
	ss << "[GasEngine]\tT = " << _currentT <<
		"\tV = " << _currentV;
	return ss.str();
}
