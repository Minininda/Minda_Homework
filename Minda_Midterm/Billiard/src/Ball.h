#pragma once
#include "ofMain.h"		

class Ball {

public:

	Ball();
	void update();
	void draw();
	float radius;
    glm::vec2 pos;
	float dirX, dirY;
	ofColor color;

};
