//
//Ellipsoid
//Ax^2 + By^2 + Cz^2 = D
//

#pragma once
#include "RayTracer/Surface.h"

class Ellipsoid :public Surface
{
public:
    void SetParameters(const vector<double>& _param);
private:
};
