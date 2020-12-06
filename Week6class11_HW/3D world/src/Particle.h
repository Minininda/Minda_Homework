#pragma once
#include "ofMain.h"

class Particle {
	
public:

	Particle();
	~Particle(){}
	
    Particle(glm::vec3 _pos, glm::vec3 _vel, float _life, float _mass);
	
    void applyForce(glm::vec3 force);
	void applyDrag(float amt);
	
	void update();
	void draw();
	
    glm::vec3 pos, vel, acc;
	
	float age = 0;
	
	float lifespan;
	
	float mass;
	

private:
	
	ofMaterial material;
	
	float lastUpdateTime = 0;	
	
};
