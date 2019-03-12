//
//Paraboloid
//Ax^2 + By^2 - Cz = 0

#pragma once
#include "RayTracer/Surface.h"

class Paraboloid :public Surface
{
public:
    void SetParameters(const vector<double>& _param);

private:
};
