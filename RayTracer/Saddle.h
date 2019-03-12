//
//Saddle
//Ax^2 - By^2 - z = 0;
#pragma once
#include "RayTracer/Surface.h"

class Saddle : public Surface
{
public:
    void SetParameters(const vector<double>& _param);

private:
};
