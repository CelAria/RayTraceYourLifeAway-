#pragma once
#include "stdafx.h"
#include "Screen.h"
#include "Ray.h"
#include "Geometry.h"
#include <vector>
#include <cmath>
#include <string>
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"


using namespace std;

class Camera {

public:
	
	//constructor declaration
	Camera(glm::vec3, int, int, float);
	Camera() {}

private:
	glm::vec3 pos;
	glm::vec3 cameraspace;
	glm::vec3 raydirection;
	int fov;
	int f;
	float a;

public:

	void changeAspect(Screen* &myscreen);

	// creates ray going from cop through screen pixel and returns a ray 
	Ray viewRay(double x, double y, Screen* &myscreen);

	//iterate through geometry array and call the testIntersection function on each one. If the ray hits an object return true. 
	boolean trace(Ray myray, vector<Geometry*> &objects, float &tNear, const Geometry *&hitObject);

	//declaration of castray function 
	glm::vec3 castRay(Ray myray, std::vector<class Sphere> &spheres, std::vector<class Plane> &planes, std::vector<class Light> &lights);

};