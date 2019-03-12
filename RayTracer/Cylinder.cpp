#include "Cylinder.h"

void Cylinder::SetParameters(const vector<double>& _param)
{
    int index = _param[0];
    switch(index)
    {
    case 0:
        param[0] = 1.0 / (_param[1] * _param[1]);
        param[1] = -1.0 / (_param[2] * _param[2]);
        param[9] = -1;
        zMax = _param[3];
        yMax = _param[4];
        break;
    case 1:
        param[0] = 1.0 / (_param[1] * _param[1]);
        param[1] = 1.0 / (_param[2] * _param[2]);
        param[9] = -1;
        zMax = _param[3];
        break;
    case 2:
        param[0] = 1;
        param[7] = 2 * _param[1];
        zMax = _param[2];
        yMax = _param[3];
        break;
    }
}
