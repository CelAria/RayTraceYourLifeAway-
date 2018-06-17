#include "stdafx.h"
#include "Ray.h"
#include "Intersection.h"
#include "Plane.h"


	Plane::Plane(glm::vec3 normal, glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess) {
		nor = normal;
		pos = position;
		amb = ambient;
		dif = diffuse;
		spec = specular;
		shi = shininess;
	}
	
	//test for intersection with ray
	Intersection Plane::testIntersection(Ray myray) {
	
	//normalize value for normal
	normalize(nor);

	float denom; 
	//MIGHT BE PROBLEMS HERE with the cast
	denom= glm::dot(glm::vec3(nor), glm::vec3(myray.dir));
	
	//if denominator is smaller than a very small value
	if (denom > 1e-6) {
		glm::vec3 p0l0 =pos - myray.dir; 
		float t = glm::dot(p0l0, nor) / denom;

		return(Intersection(myray.pos + t * myray.dir));
	}
	return Intersection();
	}
