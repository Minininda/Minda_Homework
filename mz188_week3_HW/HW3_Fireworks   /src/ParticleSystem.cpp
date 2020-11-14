#include "ParticleSystem.hpp"
#include "Ball.h"

ParticleSystem::ParticleSystem()
{
    pos = glm::vec2(0,0);
    col=ofRandom(50,255);
}

ParticleSystem::ParticleSystem(glm::vec2 _pos)
{
    pos = _pos;
    col=ofRandom(50,255);
}

void ParticleSystem::applyForce(glm::vec2 force)
{
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].applyForce(force);
    }
    
}

void ParticleSystem::update(int numNewParticles, int maxParticles)
{
    
    for (int i=0; i<numNewParticles; i++)
    {
        if (ofGetElapsedTimef()-borntime>2) continue;
        for (int j=0;j<=6-6*abs(ofGetElapsedTimef()-borntime-1);j++)
        {
            glm::vec2 vel   = glm::vec2(ofRandom(-5,5), ofRandom(-10,-2));
            float mass      = ofRandom(.01, 5);
            Particle particle = Particle(pos,vel,mass);    
            particles.push_back(particle);
        }
    }
    
    // update particles:
    
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].update();
    }
    
    // erase old particles:
    
    while (particles.size() > maxParticles) particles.erase(particles.begin());
    
}

void ParticleSystem::draw()
{
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].draw(col);
    }
}

