// RayTraceYourLifeAway.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "Screen.h"
#include "Sphere.h"
#include "Plane.h"
#include "Camera.h"
#include "Light.h"
#include "Geometry.h"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"


#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>



using namespace std; 
using namespace cimg_library;

Screen myscreen(640, 640);

CImg<unsigned char> image(myscreen.width, myscreen.height, 1, 3, 0);


//print method for sphere array
//void printG(vector<Geometry> g) {
//	for (auto i = g.begin(); i != g.end(); ++i) {
//		if (i)
//		std::cout << glm::to_string(i->getPos()) << i->getRad() << glm::to_string(i->getAmb()) << glm::to_string(i->getDif()) << glm::to_string(i->getSpec()) << (i->getShi()) << " " << endl;
//	}
//}

void printL(vector<Light*> l) {
	for (std::vector<Light*>::const_iterator i = l.begin(); i != l.end(); ++i){
		std::cout << "first variable from lights: ";
		std::cout << glm::to_string((*i)->getPos()) << glm::to_string((*i)->getCol()) << endl;
	}
	if (l.size() == 0) cout << "empty ass array homey " << endl;
}

string readfile(string myfile, vector<Geometry*> &g, vector<Light*> &l, Camera* &mycamera) {


	//create new stream with file, 
	//ifstream istr(myfile.c_str());
	ifstream istr("scene2.txt");

	//check if input file is good

	if (istr.fail()) return "failed to open file for read";

	if (istr.is_open()) std::cout << "this file IS OPEN " << endl;

	string line;

	//iterator testing debug
	int j = 0;

	while (std::getline(istr, line)) {
		//debugging iterator prints line number each loop
		j = j++;

		getline(istr, line);
		istringstream iss(line);
		vector<string> words{ istream_iterator<string>{iss},
			istream_iterator<string>{} };

		if (words.empty()) continue;
		if (words.at(0) == "camera") {
			glm::vec3 pos;
			int fov;
			int f;
			float a;

			////go to next line
			continue;
			if (words.at(0) == "pos:") {
				pos = glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
				//go to next line
				continue;
			}
			if (words.at(0) == "fov:") {
				fov = stoi(words.at(1));
				//go to next line
				continue;
			}
			if (words.at(0) == "f:") {
				f = stoi(words.at(1));
				//go to next line
				continue;
			}
			if (words.at(0) == "a:") {
				a = stof(words.at(1));
				//go to next line
				continue;
			}
			//construct camera object with these parameters 
			Camera* mycamera = new Camera(pos, fov, f, a);

		}
		if (words.at(0) == "Sphere") {
			glm::vec3 pos;
			int rad;
			glm::vec3 amb;
			glm::vec3 dif;
			glm::vec3 spec;
			float shi;

			//go to next line
			continue;

			if (words.at(0) == "pos:") {
				pos = glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
				//go to next line
				continue;
			}
			if (words.at(0) == "rad:") {
				rad = stoi(words.at(1));
				//go to next line
				continue;
			}
			if (words.at(0) == "amb:") {
				amb = glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
				//go to next line
				continue;
			}
			if (words.at(0) == "dif:") {
				dif = glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
				//go to next line
				continue;
			}
			if (words.at(0) == "spe:") {
				spec = glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
				//go to next line
				continue;
			}
			if (words.at(0) == "shi:") {
				shi = stof(words.at(1));
				//go to next line
				continue;
			}
			Sphere* mysphere = new Sphere(pos, rad, amb, dif, spec, shi);
			//push object into spheres object array
			g.push_back(mysphere);
		}
		if (words.at(0) == "plane") {
			glm::vec3 nor;
			glm::vec3 pos;
			glm::vec3 amb;
			glm::vec3 dif;
			glm::vec3 spec;
			float shi;

			//go to next line
			continue;
			if (words.at(0) == "nor:") {
				nor = glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
				//go to next line
				continue;
			}
			if (words.at(0) == "pos:") {
				pos = glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
				//go to next line
				continue;
			}
			if (words.at(0) == "amb:") {
				amb = glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
				//go to next line
				continue;
			}
			if (words.at(0) == "dif:") {
				dif = glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
				//go to next line
				continue;
			}
			if (words.at(0) == "spe:") {
				spec = glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
				//go to next line
				continue;
			}
			if (words.at(0) == "shi:") {
				shi = stof(words.at(1));
				//go to next line
				continue;
			}
			Plane* myplane = new Plane(nor, pos, amb, dif, spec, shi);
			//push plane into object array of planes
			g.push_back(myplane);


		}
		if (words.at(0) == "Light") {
			glm::vec3 pos;
			glm::vec3 col;

			//go to next line
			continue;
			if (words.at(0) == "pos:") {
				pos = glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
				//go to next line
				continue;
			}
			if (words.at(0) == "col:") {
				col = glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
				//go to next line
				continue;
			}
			Light* mylight = new Light(pos, col);
			//push light into array of lights
			l.push_back(mylight);
		}
		std::cout << line << " " << "the line number is " << j <<endl;
	}
	return "success"; 
}

//test if pixel is in shadow for each light
void inShadow(Intersection myintersection, Ray myray, vector<Light> &l, vector<Geometry*> g, unsigned char* &colorarray) {

	//declaring direction vector for shadowray 
	glm::vec3 dirvec;

	//for each light object
	for (auto i : l) {
		dirvec = glm::normalize(i.getPos() - myintersection.pos);
		//create shadowray
		Ray shadowray(myintersection.pos, dirvec);

		//for each object in geometry array 
		for (auto j : g) {

			//returns intersection object if there is an intersection
			Intersection shadowintersection = (j)->testIntersection(shadowray);
			if (shadowintersection.is_intersection == true) {

				////its contribution to pixel color is ZERO 
				//image(x, y, 0, 0) = l.getCol(); 
				//image(x, y, 0, 1)=
				//image(x, y, 0, 2)=
				//	color.RGBA{ 85, 165, 34, 255 })
			}
		}
	}
}

void render(Screen* &myscreen, Camera* &mycamera, vector<Light*> &light, vector<Geometry*> &geo){

	//make sure aspect ratio is same as file 
	//mycamera->changeAspect(myscreen);

	//call view ray for every pixel in screen 
	for (int j = 0; j <= myscreen->width; ++j) {

		for (int k = 0; k <= myscreen->height; ++k) {

			//for each pixel create a ray from COP through pixel(j,k) 
			Ray thisray = mycamera->viewRay(j, k, myscreen);
			
			//for every object in geometry array test intersection
			for (auto n : geo) {
				//if ray intersects with object enter loop
				if (n->testIntersection(thisray).is_intersection == true) {
					//create new intersection object
					Intersection myintersection = n->testIntersection(thisray);

					//for each light object in light array cast shadow ray 
					for (auto eachlight : light) {
						glm::vec3 dirvec;
						//direction vector for shadow ray from point of intersection to light
						dirvec = glm::normalize(eachlight->getPos() - myintersection.pos);
						//create shadowray
						Ray shadowray(myintersection.pos, dirvec);
						//for each object test if shadow ray intersects 
						for (auto m : geo) {
							//returns intersection object if there is an intersection with shadow ray
							Intersection shadowintersection = (m)->testIntersection(shadowray);
							if (shadowintersection.is_intersection == true) {
								//shadow ray intersected with object, so colour added is (0,0,0)
								//do nothing
							}
							if (shadowintersection.is_intersection == false) {
								//shadow ray did not intersect with object, so color added is color of light
								// swizzle to get colour from light 
								image(j, k, 0, 0) += eachlight->getCol().x * 255;
								image(j, k, 0, 1) += eachlight->getCol().y * 255;
								image(j, k, 0, 2) += eachlight->getCol().z * 255;
							}

						}
					}
				}
			}
		}
	}
}

int main() {
	//create file name 
	std::string myfile("scene2.txt");

	//create vectors to hold hold all the objects being read in readfile()
	
	Light* light1 = new Light(glm::vec3(0.0f, 60.0f, -50.0f), glm::vec3(0.2f,0.2f, 0.2f));

	Sphere* sphere1 = new Sphere(glm::vec3(0.0f, 30.0f, - 50.0f), 3, glm::vec3(0.1, 0.5,0.5), glm::vec3(0.4, 0.6, 0.2), glm::vec3(0.4, 0.6, 0.2), 1);

	Plane* plane1 = new Plane(glm::vec3(0,1,0), glm::vec3(0, -5, 0), glm::vec3(0.3,0.5,0.2), glm::vec3(0.3, 0.5, 0.2), glm::vec3(0.3, 0.5, 0.2), 5);

	//vector that holds all light objects
	vector<Light*> lights;
	//holds both Sphere and Plane objects
	vector<Geometry*> sceneobjects;

	//push light into array


	//push into arrays
	lights.push_back(light1);
	sceneobjects.push_back(sphere1);
	sceneobjects.push_back(plane1);

	//holds singular camera
	Camera* mycamera= new Camera(glm::vec3(0.0f, 0.0f, 0.0f), 60, 500, 1.67);
	
	//run file parser function
	//readfile(myfile, sceneobjects, lights, mycamera);

	//debugging print to test if lights vector is being populated 
	printL(lights);

	/* comment the rest of main out to test the readfile function only */

	////create screen
	Screen* myscreen = new Screen(640, 640);
	//array for color of pixels 
	//
	////dynamically allocate array for color
	//unsigned char* color = NULL;
	//color = new unsigned char[arraysize];

	//render scene
	render(myscreen, mycamera, lights, sceneobjects);

	CImgDisplay main_disp(image, "myimage");
	image.normalize(0, 255);
	image.save("outputedimage.bmp");

	////delete color array
	//delete[]color;
	//color = NULL;

}

