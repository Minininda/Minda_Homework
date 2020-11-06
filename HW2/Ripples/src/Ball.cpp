#include "Ball.h"


Ball::Ball()
{
    radius=10;
    pos.x = 450;
    pos.y = 450;
}
void Ball::update(ofVec2f force) {
    radius+=2;
}

void Ball::draw() {
    ofNoFill();
    ofDrawCircle(pos, radius);
}
