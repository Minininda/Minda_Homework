//
//  ParticleSystem.hpp
//  wk06_particle_system
//
//  Created by Tyler Henry on 10/2/18.
//

#pragma once
#include "ofMain.h"
#include "Particle.hpp"
#include "Ball.h"

class ParticleSystem {
public:

    ParticleSystem();
    ParticleSystem(glm::vec2 _pos);
    
    void applyForce(glm::vec2 force);
    
    void update(int numNewParticles = 10, int maxParticles = 7000);

    void draw();
    
    glm::vec2 pos;
    int borntime,col;
    
    vector<Particle> particles;
    Ball st;
};
