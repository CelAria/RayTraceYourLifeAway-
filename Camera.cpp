#include "stdafx.h"
#include "Camera.h"

/* Camera Rays generation: modified from:http://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/generating-camera-rays */
/*trace function modified from: http://www.scratchapixel.com/code.php?id=10&origin=/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes*/

//constructor
Camera::Camera(glm::vec3 position, int fieldofview, int focallength, float aspectratio) : pos(position), fov(fieldofview), f(focallength), a(aspectratio) {}

void Camera::changeAspect(Screen* &myscreen) {
	double z = (myscreen)->width/(myscreen)->height;
	
	z = std::floor((z * 100) + 0.5) / 100.0;
		if ((std::floor((z * 100.0) + 0.5) / 100) != (std::floor((a * 100.0) + 0.5) / 100)) {
			std::cout << "ASPECT RATIO DOES NOT MATCH SCREEN WIDTH HEIGHT aspect ratio is" << a << " " << "screen width is" << myscreen->width << " screenheight is" << myscreen->height << "z is " << z << "screen is being resized";
			(myscreen)->width = ceil(20.0 *a);
			(myscreen)->height = ceil(20.0);

			cout << (myscreen)->width << endl;
			cout << (myscreen)->height<< endl;
		}
	}

// takes in x, y position from "screen" 
	Ray Camera::viewRay(double x, double y, Screen* &myscreen) {

		float aspectratio = a;
		double width= (myscreen)->width;
		double height= (myscreen)->height;

		// normalize pixel position using screen dimensions, adjust by 0.5 so ray goes through center of pixel
		double pixel_NDC_x = (x + 0.5) / width;
		double pixel_NDC_y = (y + 0.5) / height;
		
		//remap to range -1, 1
		double screen_x = 2 * pixel_NDC_x - 1.0;
		double screen_y = 1- 2 * pixel_NDC_y;
		
		//convert focal length from pixels to units (divide by screen height/2)
		double normalize_f = f / (myscreen->height / 2);

		// find the height value of half the screen 
		double opposite = normalize_f * tan(fov);

		//find normalized pixel coordinates in camera space
		double camera_x = (2 * screen_x - 1.0)*aspectratio*opposite;
		double camera_y = 1 - 2 * screen_y*opposite;

		cameraspace = glm::vec3(camera_x, camera_y, -1.0f);
		
		//calculate ray direction
		raydirection = glm::normalize(cameraspace - pos);

		//make new ray object and return it
		Ray ray(pos, raydirection);
		std::cout << glm::to_string(pos) << glm::to_string(raydirection) << endl;
		return ray;
	}

	//boolean Camera::trace(Ray myray, vector<Geometry*> &objects, float &tNear, const Geometry *&hitObject) {

	//tNear = INFINITY;
	////iterate through object vector

	//vector<Geometry*>::const_iterator iter = objects.begin();

	////while true, iterate through objects vector 
	//	for (; iter != objects.end(); ++iter) {
	//		float t = INFINITY;
	//		//use the intersect function for each child class of object
	//		if ((*iter)->testIntersection(myray).is_intersection && t < tNear) {
	//			hitObject = *iter;
	//			
	//			//we want the return value of the testIntersection 
	//			Intersection inter = (*iter)->testIntersection(myray);
	//			//return point of intersection into t
	//			tNear= inter.pos;
	//			return true;
	//			}
	//	}
	//}

	////glm::vec3 castRay(Ray* &myray, vector<Geometry*> &objects, Camera* &mycamera)
	////{
	////	glm::vec3 hitColor = glm::vec3(0, 0, 0);
	////	const Geometry *hitObject = nullptr; // this is a pointer to the hit object 
	////	float t; // this is the intersection distance from the ray origin to the hit point 
	////	if (mycamera->trace(*myray, objects, t, hitObject)) {
	////		glm::vec3 Phit= myray->pos + myray->dir * t;
	////		glm::vec3 Nhit;
	////		
	////		Vec2f tex;
	////		hitObject->getSurfaceData(Phit, Nhit, tex);
	////		// Use the normal and texture coordinates to shade the hit point.
	////		// The normal is used to compute a simple facing ratio and the texture coordinate
	////		// to compute a basic checker board pattern
	////		float scale = 4;
	////		float pattern = (fmodf(tex.x * scale, 1) > 0.5) ^ (fmodf(tex.y * scale, 1) > 0.5);

	//		//confirm if you can make myray->dir negative by putting sign in front? 
	//		hitColor = std::max(0.f, glm::dot(Nhit, -(myray->dir))) * mix(hitObject->color, hitObject->color * 0.8, pattern);
	//	}

	//	return hitColor;
	//}
	//// takes in ray object (from viewray), takes in objects, lights, options
	//glm::vec3 Camera::castRay(Ray myray, std::vector<class Sphere> &spheres, std::vector<class Plane> &planes, std::vector<class Light> &lights) {
	//
	//
	//	return myray.dir;
	//

	//}


