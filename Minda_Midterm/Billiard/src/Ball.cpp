#include "Ball.h"

Ball::Ball() {

	radius = 5;
	color = ofColor(255, 255, 255);

}


// draw the ball
void Ball::draw() {

	ofSetColor(color);				
	ofDrawCircle(pos, radius);
}
