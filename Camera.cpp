#include "stdafx.h"
#include "Camera.h"

/* Camera Rays generation: modified from:http://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/generating-camera-rays */
/*trace function modified from: http://www.scratchapixel.com/code.php?id=10&origin=/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes*/

//constructor
Camera::Camera(glm::vec3 position, int fieldofview, int focallength, float aspectratio) : pos(position), fov(fieldofview), f(focallength), a(aspectratio) {}


	// takes in x, y position from "screen" 
	Ray	Camera::viewRay(double x, double y, Screen myscreen) {

		float aspectratio = a;
		double width;
		double height;

		//test if aspect ratio is 1, if not, adjust "height and width" to be aspect ratio 
		if (myscreen.width / myscreen.height != a) {
			std::cout << "ASPECT RATIO DOES NOT MATCH SCREEN WIDTH HEIGHT aspect ratio is" << a << " " << "screenheight is" << myscreen.height<< "screen is being resized";
			width = 640 *a;
			height = 640;
		};

		// normalize pixel position using screen dimensions, adjust by 0.5 so ray goes through center of pixel
		double pixel_NDC_x = (x + 0.5) / width;
		double pixel_NDC_y = (y + 0.5) / height;
		
		//remap to range -1, 1
		double screen_x = 2 * pixel_NDC_x - 1.0;
		double screen_y = 1- 2 * pixel_NDC_y;
		
		//convert focal length from pixels to units (divide by screen height/2)
		double normalize_f = f / (height / 2);

		// find the height value of half the screen 
		double opposite = normalize_f * tan(fov);

		//find normalized pixel coordinates in camera space
		float camera_x = (2 * screen_x - 1.0)*aspectratio*opposite;
		float camera_y = 1 - 2 * screen_y*opposite;

		cameraspace = glm::vec3(camera_x, camera_y, -1.0f);
		
		//calculate ray direction
		raydirection = glm::normalize(cameraspace - pos);

		//make new ray object and return it
		Ray ray(pos, raydirection);
		return ray;
	}

	//boolean Camera::trace(Ray myray, const std::vector < std::unique_ptr<class Object>> &objects, float &tNear, const Object *&hitObject) {

	//tNear = INFINITY;
	////iterate through object vector
	//std::vector<std::unique_ptr<class Object>>::const_iterator iter = objects.begin();
	////while true, iterate through objects vector 
	//	for (; iter != objects.end(); ++iter) {
	//		float t = INFINITY;
	//		//use the intersect function for each child class of object
	//		if ((*iter).Intersect(myray) && t < tNear) {
	//			hitObject = *iter;
	//			}
	//	}
	//}



	// takes in ray object (from viewray), takes in objects, lights, options
	glm::vec3 Camera::castRay(Ray myray, std::vector<class Sphere> &spheres, std::vector<class Plane> &planes, std::vector<class Light> &lights) {
	
	
		return myray.dir;
	

	}


