#pragma once
#include "Surface.h"
#include "Ellipsoid.h"
#include "Quadratic.h"
#include "Saddle.h"
#include "Cylinder.h"
#include "Paraboloid.h"
#include <vector>

class QuadraticCreator
{
public:
    Surface* Create(int i) {
		switch (i) {
        case 0:
            return new Ellipsoid();		//create ellipsoid
			break;
        case 1:
            return new Quadratic();		//create quadratic
			break;
        case 2:
            return new Paraboloid();	//create paraboloid
			break;
        case 3:
            return new Saddle();		//create saddle
			break;
        case 4:
            return new Cylinder();		//create cylinder
			break;
		default:
			return NULL;
			break;
		}
	}

};

