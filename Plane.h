#pragma once
#include "stdafx.h"
#include "Screen.h"
#include "Ray.h"
#include "Intersection.h"
#include "Geometry.h"
#include <vector>


class Plane : public Geometry{
private:
	glm::vec3 nor;
	glm::vec3 pos;
	glm::vec3 amb;
	glm::vec3 dif;
	glm::vec3 spec;
	float shi;

public:
	//constructor
	Plane(glm::vec3 normal, glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess);

	//declare intersection method
	Intersection testIntersection(Ray myray);
};
