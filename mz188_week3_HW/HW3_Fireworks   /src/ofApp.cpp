#include "ofApp.h"
#include "Ball.h"

//--------------------------------------------------------------
int st_num[10100000];

void ofApp::setup()
{
    ofBackground(0);
    ofSetFrameRate(60.);
    ofSetBackgroundAuto(false);
    glm::vec2 pos= glm::vec2(ofRandom(ofGetWidth() * 0.5-120,ofGetWidth() * 0.5+120), ofGetHeight()*0.5);
    ParticleSystem particleSystem = ParticleSystem(pos);
    particleSystems.push_back(particleSystem);
    particleSystems[particleSystems.size()-1].st.pos=glm::vec2(pos.x,ofGetHeight());
    st_num[0]=5;
    gravity = glm::vec2(0, .95);

}

//--------------------------------------------------------------
void ofApp::update()
{
    for (int i=0; i<particleSystems.size(); i++)
    {
        if (ofGetFrameNum() % 3 == 0 && st_num[i])
        {
            st_num[i]--;
            glm::vec2 pos2 = glm::vec2(ofRandom(particleSystems[i].pos.x-120,particleSystems[i].pos.x+120), particleSystems[i].pos.y);
            particleSystems.push_back( ParticleSystem(pos2) );
            particleSystems[particleSystems.size()-1].st.pos=glm::vec2(pos2.x, ofGetHeight());
            
        }
        if (particleSystems[i].st.pos.y>=particleSystems[i].pos.y)
        {
            glm::vec2 cur = glm::vec2(0,-15);
            particleSystems[i].st.pos+=cur;
            if (particleSystems[i].st.pos.y<=particleSystems[i].pos.y)
                particleSystems[i].borntime=ofGetElapsedTimef();
            continue;
        }
        if (ofGetElapsedTimef()-particleSystems[i].borntime>5)
        {
            st_num[i]=0;
            particleSystems.erase(particleSystems.begin());
            continue;
        }
        particleSystems[i].applyForce(gravity);
        particleSystems[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  
    ofSetColor(255,255,255);
    ofDrawCircle(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()),2);
    ofSetColor(0, 0, 0, 20);
    ofDrawRectangle(0,0, ofGetWidth(),ofGetHeight());
    for (int i=0; i<particleSystems.size(); i++)
    if (particleSystems[i].st.pos.y<=particleSystems[i].pos.y)
        particleSystems[i].draw();
    else
        particleSystems[i].st.draw();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
        glm::vec2 pos2 = glm::vec2( ofRandom(x-120,x+120), y);
        particleSystems.push_back( ParticleSystem(pos2) );
        particleSystems[particleSystems.size()-1].st.pos=glm::vec2(pos2.x, ofGetHeight());
        st_num[particleSystems.size()-1]=5;
}
