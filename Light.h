#pragma once

#include "stdafx.h"
#include "Screen.h"
#include "Ray.h"
#include <vector>

class Light {
private:
	glm::vec3 pos;
	glm::vec3 col;

public:
	Light(glm::vec3 position, glm::vec3 color);

	
	const glm::vec3 & getPos() const { return pos; }

	const glm::vec3 & getCol() const { return col; }

};