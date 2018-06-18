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
		//debugging iterator
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

int main() {

	std::string myfile("scene2.txt");

	vector<Geometry*> sceneobjects;
	vector<Light*> lights;
	Camera* mycamera;

	std::cout << "made it this far" << endl;

	readfile(myfile, sceneobjects, lights, mycamera);

	std::cout << "here too" << endl;

	printL(lights);
}

