#include "stdafx.h"

#include "Filereader.h"


using namespace std;

//public:
//
//	inline Camera get_camera() const { return camera; }
//	inline vector<Light> get_lights() const { return lights; }
//	inline vector<Sphere> get_spheres() const { return spheres; }
//	inline vector<Plane> get_planes() const { return planes; }
//


//function that parses file
string readfile(string myfile, vector<Geometry*> &g, vector<Light*> &l, Camera* &mycamera){

	
	//create new stream with file, 
	ifstream istr(myfile.c_str());

	//check if input file is good

	if (istr.fail()) return "failed to open file for read";

		string line; 
		
		while (istr.eof() == false) {
			getline(istr, line);
			istringstream iss(line);
			vector<string> words{ istream_iterator<string>{iss},
				istream_iterator<string>{}};

			if (words.empty()) continue;

			if (words.at(0) == "camera") {
				glm::vec3 pos;
				int fov;
				int f;
				int a;

				//go to next line
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
				if (words.at(0) == "a") {
					a = stof(words.at(1));
					//go to next line
					continue;
				}
				//construct camera object with these parameters 
				Camera* mycamera= new Camera(pos, fov, f, a);
				
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
					amb= glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
					//go to next line
					continue;
				}
				if (words.at(0) == "dif:") {
					dif = glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
					//go to next line
					continue;
				}
				if (words.at(0) == "spec:") {
					spec = glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
					//go to next line
					continue;
				}
				if (words.at(0) == "spec:") {
					spec = glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
					//go to next line
					continue;
				}
				if (words.at(0) == "shi:") {
					shi = stoi(words.at(1));
					//go to next line
					continue;
				}
				Sphere* mysphere= new Sphere(pos, rad, amb, dif, spec, shi);
				//push object into spheres object array
				g.push_back(mysphere);
			}
			if (words.at(0) == "Plane") {
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
				if (words.at(0) == "spec:") {
					spec = glm::vec3(stof(words.at(1)), stof(words.at(2)), stof(words.at(3)));
					//go to next line
					continue;
				}
				if (words.at(0) == "shi:") {
					shi = stoi(words.at(1));
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
				Light* mylight= new Light(pos, col);
				//push light into array of lights
				l.push_back(mylight);
			}
		}
		return "success";
	}

