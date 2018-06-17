#include "stdafx.h"
#include "Ray.h"
#include "Intersection.h"
#include <vector>
#include "Sphere.h"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

using namespace std;


	Sphere::Sphere(glm::vec3 position, int radius, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess) {
		pos = position;
		rad = radius;
		amb = ambient;
		dif = diffuse;
		spec = specular;
		shi = shininess;
	}

	// writing a function to compute if there's an intersection 
	Intersection Sphere::testIntersection(Ray myray) {


		//delta-X, delta-Y, delta-Z values for the ray. 
		// ray (X0 + Xdt - sphere position)
		double u= (myray.pos.x) -pos.x;
		double v= (myray.pos.y) -pos.y;
		double w= (myray.pos.z) -pos.z;

		double c = u * u + v * v + w * w - rad * rad;
		double b = 2*((u*myray.dir.x) + (v*myray.dir.y) + (w*myray.dir.z));
		double a = pow(myray.dir.x, 2.0) + pow(myray.dir.y, 2.0) + pow(myray.dir.z, 2.0);
		
		double determinate = b * b -(4 * a*c);

		// no intersection 
		if (determinate < 0) return Intersection();

		double alpha_1 = (-b + sqrt(determinate)) / (2 * a);
		double alpha_2 = (-b - sqrt(determinate)) / (2 * a);

		if (alpha_2 < 0) return Intersection(myray.pos + (float(alpha_1)* myray.dir));

		//return point on surface if there is an intersection 
		else return Intersection(myray.pos + (float(alpha_2)* myray.dir));
	}

	////print method for sphere array
	//void printS(vector<Sphere> s) {
	//	for (auto i = s.begin(); i != s.end(); ++i) {
	//		std::cout << glm::to_string(i->pos) << i->rad << glm::to_string(i->amb) << glm::to_string(i->dif) << glm::to_string(i->spec) << (i->shi) << " " << endl;
	//	}
	//}