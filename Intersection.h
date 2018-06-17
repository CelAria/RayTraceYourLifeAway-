#pragma once

#include "stdafx.h"

struct Intersection {

	glm::vec3 pos;
	boolean is_intersection;

	// returns point on surface of intersection if there is an intersection
	Intersection(glm::vec3 position) {
		pos = position;
		is_intersection = true;
		
	}

	//sets intersection to false if no intersection 
	Intersection() {
		is_intersection = false;
	}

};
