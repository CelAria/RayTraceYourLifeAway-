#pragma once
#include "stdafx.h"
#include "Screen.h"
#include "Ray.h"
#include <vector>

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
	// declaration of viewray function
	Ray viewRay(double x, double y, Screen myscreen);

	//declaration of trace function
	//boolean trace(Ray myray, const std::vector < std::unique_ptr<class Object>> &objects, float &tNear, const Object *&hitObject);

	//declaration of castray function 
	glm::vec3 castRay(Ray myray, std::vector<class Sphere> &spheres, std::vector<class Plane> &planes, std::vector<class Light> &lights);

};