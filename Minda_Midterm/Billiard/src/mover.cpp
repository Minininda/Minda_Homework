
#include "mover.h"
#include "ofApp.h"

void mover::setup(float m, float x, float y,float c) {
	mass = m;
	location.set(x, y);
    Lastpos=location;
	velocity.set(0, 0);
	acceleration.set(0, 0);
	friction.set(1.03);
    col=glm::vec3(ofRandom(10,255),ofRandom(10,255),ofRandom(10,255));
}

void mover::applyForce(ofPoint force) {
	ofPoint a;
	a = force / mass;
	acceleration += a;
}

void mover::update() {
	velocity += acceleration;
    Lastpos=location;
	location += velocity;
	acceleration *= 0;
	velocity /= friction;
}

//emulate friction


void mover::display() {

	ofSetColor(col.x,col.y,col.z);
	ofDrawCircle(location.x, location.y, mass );

}

void mover::checkEdges() {
    Lastpos=location;
	if (location.x > ofGetWidth()) {
		location.x = ofGetWidth();
		velocity.x *= -1;
	}
	else if (location.x < 0) {
		velocity.x *= -1;
		location.x = 0;
	}

	if (location.y > ofGetHeight()) {
		velocity.y *= -1;
		location.y = ofGetHeight();
	}
	else if (location.y < 0) {
		velocity.y *= -1;
		location.y = 0;
	}
}
