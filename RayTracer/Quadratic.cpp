#include "Quadratic.h"

void Quadratic::SetParameters(const vector<double>& _param)
{
    param[0] = 1.0 / (_param[0] * _param[0]);
    param[1] = 1.0 / (_param[1] * _param[1]);
    param[2] = -1.0 / (_param[2] * _param[2]);
    param[9] = -_param[3];
    zMax = _param[4];

}


