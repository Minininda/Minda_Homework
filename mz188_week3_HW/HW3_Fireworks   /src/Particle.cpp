#include "Particle.hpp"
Particle::Particle()
{

    pos = glm::vec2(0,0);
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    bornTime = ofGetElapsedTimef();
}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass)
{
    pos = _pos;
    vel = _vel;
    mass = _mass;
    bornTime = ofGetElapsedTimef();
}

void Particle::applyForce(glm::vec2 force)
{
    acc += force / mass;
}

void Particle::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
    
}

void Particle::draw(int col)
{
    ofPushStyle();
    float hue = ofRandom(col-12,col+12);
    float sat = 255;
    float brt = 255;
    
    float aliveTime = ofGetElapsedTimef() - bornTime;
    float alpha = ofMap(aliveTime, 0, 2, 255, 0, true);
    
    ofColor color = ofColor::fromHsb(hue,sat,alpha,alpha);
    ofSetColor(color);
    
    ofDrawCircle(pos, mass * 2.0);
    ofPopStyle();
}

