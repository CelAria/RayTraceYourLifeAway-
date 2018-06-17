// RayTraceYourLifeAway.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Screen.h"
#include "Sphere.h"
#include "Plane.h"
#include "Filereader.h"
#include "Camera.h"
#include "Light.h"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"



using namespace std; 
using namespace cimg_library;

Screen myscreen(640, 640);

CImg<unsigned char> image(myscreen.width, myscreen.height, 1, 3, 0);


class RayTracer {
private:
	int numobjects;

	void setnumobject(int x) {
		numobjects = x;
	};

	void createObjects(string filename) {

		ifstream myfile("\" + filename + \"");
		cout << "reading in scene file" << " " << filename;

		if (myfile.is_open()) {
			//loop through for each "object" and create the appropriate object
			for (int i = 0; i < numobjects; i++) {
				
				cout << "i got nothing";
			}
		}
		else cout << "unable to open file";
	}
};

//print method for sphere array
void printS(vector<Sphere> s) {
	for (auto i = s.begin(); i != s.end(); ++i) {
		std::cout << glm::to_string(i->getPos()) << i->getRad() << glm::to_string(i->getAmb()) << glm::to_string(i->getDif()) << glm::to_string(i->getSpec()) << (i->getShi()) << " " << endl;
	}
}


int main()
{
	Camera* camera;
	vector<Geometry*> sceneobjects;
	vector<Light*> lights;

	string myfile;
	myfile = "scene2.txt";
	readfile(myfile, sceneobjects, lights, camera);

	//printS(spheres);


	cimg_forXY(image, x, y) {
	image(x, y, 0, 0) = 255;
	image(x, y, 0, 1) = 0;
	image(x, y, 0, 2) = 255;
	}

	image.save("result.bmp");
	
	CImgDisplay draw_disp(image, "myimage");
	getchar();
}
