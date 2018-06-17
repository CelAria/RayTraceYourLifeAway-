#pragma once
#include "stdafx.h"


class Ray {
public:
	glm::vec3 pos;
	glm::vec3 dir;


	Ray(glm::vec3 position, glm::vec3 direction) {
		pos = position;
		dir = direction;
	}


};
