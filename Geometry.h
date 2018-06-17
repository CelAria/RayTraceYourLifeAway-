#pragma once
#include "stdafx.h"
#include "Ray.h"
#include "Intersection.h"

// abstract class Geometry base class for Sphere and Plane 
class Geometry {

public:
	virtual Intersection testIntersection(Ray myray)= 0;
	
};