#pragma once
#define GLM_SWIZZLE

#include "stdafx.h"
#include "Screen.h"
#include "Ray.h"
#include "Intersection.h"
#include "Geometry.h"
#include <vector>

class Sphere : public Geometry {

private:
	glm::vec3 pos;
	int rad;
	glm::vec3 amb;
	glm::vec3 dif;
	glm::vec3 spec;
	float shi;

public:
	//constructor declaration
	Sphere(glm::vec3 position, int radius, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess);

	//function for testing intersection
	Intersection testIntersection(Ray myray);

	//glm::vec3 calcNormal(Intersection myintersection);

	glm::vec3 getPos() {
		return pos;
	}
	int getRad() {
		return rad;
	}
	glm::vec3 getAmb() {
		return amb;
	}
	glm::vec3 getDif() {
		return dif;
	}
	glm::vec3 getSpec() {
		return spec;
	}
	float getShi() {
		return shi;
	}
	//void printS(std::vector<Sphere> s);
};
