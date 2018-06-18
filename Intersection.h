#pragma once

#include "stdafx.h"
#include "Ray.h"


struct Intersection {

	glm::vec3 pos;
	boolean is_intersection;
	glm::vec3 unitnormal;

	// returns point on surface of intersection if there is an intersection
	Intersection(glm::vec3 position, glm::vec3 normal) {
		pos = position;
		is_intersection = true;
		unitnormal = normal;
	}

	//sets intersection to false if no intersection 
	Intersection() {
		is_intersection = false;
	}

};
