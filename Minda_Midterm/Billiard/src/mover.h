#pragma once
#include "ofMain.h"

class mover {

public:
	void setup(float m, float x, float y,float c);
	void applyForce(ofPoint force);
	void update();
	void display();
	void checkEdges();

	ofPoint location,Lastpos;
	ofPoint velocity;
	ofPoint acceleration;
	ofPoint friction;
	float mass;
    glm::vec3 col;

};
