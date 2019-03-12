#include "Paraboloid.h"

void Paraboloid::SetParameters(const vector<double>& _param)
{
    param[0] = 1.0 / (_param[0] * _param[0]);
    param[1] = 1.0 / (_param[1] * _param[1]);
    param[8] = -1;
    zMax = _param[2];

}
