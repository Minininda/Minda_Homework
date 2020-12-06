#include "Particle.h"

Particle::Particle()
{
    pos			= glm::vec3(ofRandom(-2000,2000),ofRandom(700,700),ofRandom(-2000,2000));
	vel.x		= ofRandom(-.1,.1);
	vel.y		= ofRandom(-.1,.1);
	vel.z		= ofRandom(-.1,.1);
	lifespan		= ofRandom(3,6); // seconds
	mass		    = ofRandom(1,3);
	lastUpdateTime  = ofGetElapsedTimef();
}

Particle::Particle(glm::vec3 _pos, glm::vec3 _vel, float _life, float _mass)
{
	pos			= _pos;
	vel			= _vel;
	lifespan    = _life;
	mass		= _mass;
	lastUpdateTime = ofGetElapsedTimef();
}

void Particle::applyForce(glm::vec3 force)
{
	acc += force / mass;
}

void Particle::applyDrag(float amt)
{
    float speed = glm::length(vel);
    if (speed > 0) {
        applyForce( -vel / speed * amt );
    }
}

void Particle::update()
{
	vel += acc;
	pos += vel;
	acc *= 0;
	
    // update age
	age += ofGetElapsedTimef() - lastUpdateTime;    // + time diff
	lastUpdateTime = ofGetElapsedTimef();
}

void Particle::draw()
{
	ofPushStyle();
	
	ofColor fire	= ofColor(255, 255, 255);
	ofColor smoke	= ofColor(96,96,96);

	float lerp		= ofClamp(age/lifespan, 0, 1);
    ofColor color	= ofColor(0,0,255);
	ofSetColor( color );
	
	material.setEmissiveColor( color );
	material.begin();
	
	float radius		= lifespan;
	
	ofDrawSphere(pos, radius);
	
	material.end();
	
	ofPopStyle();
}

