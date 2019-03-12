#include "RayTracer/Ellipsoid.h"

void Ellipsoid::SetParameters(const vector<double>& _param)
{
    param[0] = 1.0 / (_param[0] * _param[0]);
    param[1] = 1.0 / (_param[1] * _param[1]);
    param[2] = 1.0 / (_param[2] * _param[2]);
    param[9] = -1;
}
