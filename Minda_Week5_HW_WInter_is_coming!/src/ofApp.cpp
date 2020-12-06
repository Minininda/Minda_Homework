#include "ofApp.h"

ofPoint a[5050];
int order=0;
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);

    for (int i=0;i<=500;i++)
    {
        a[i].x=ofRandom(-6000,6000);
        a[i].y=-200;
        a[i].z=ofRandom(-6000,6000);
    }
    
    ofSetSmoothLighting(true);
    ofSetFrameRate(40);
    volcano.set(250, 400, 80, 70);
    volcano.rotateDeg(180, glm::vec3(1,0,0));
    
    auto& coneVerts = volcano.getMesh().getVertices();
    ground.set(10000, 10000, 1000, 1000);
    ground.rotateDeg(-90, glm::vec3(1,0,0));
    ground.move(0, -200, 0);
    gravity = ofVec3f(0,-.1,0);

    firelight.setPointLight();
    firelight.setPosition(0,200,0);
    firelight.setDiffuseColor( ofColor::white );
    sunlight.setDirectional();
    sunlight.setPosition(100,100,-400);
    sunlight.lookAt(glm::vec3(0));
    sunlight.setDiffuseColor( ofColor::white);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if (order%2==0)
    {
    for (int i=0; i<25; i++)
    {
        Particle p;
        p.vel.x = ofRandom(-10,10);
        p.vel.y = ofRandom(0,0);
        p.vel.z = ofRandom(-10,10);
        p.lifespan = ofRandom(1,3);
        p.mass = ofRandom(.7,1.3);
        eruption.push_back(p);
    }
    }
    
    while (eruption.size()>3800)
    {
        eruption.erase(eruption.begin());
    }
    
    for (int i=0; i<eruption.size(); i++)
    {
        eruption[i].applyForce(gravity);
        eruption[i].update();
    }

    firelight.setDiffuseColor(255);
   sunlight.rotateDeg(.2, 0,1,0);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(ofColor::gray, ofColor(255));
    
    ofEnableLighting();
    
    cam.begin();
    ofEnableDepthTest();
    
    firelight.enable();
    
    for (int i=0; i<eruption.size(); i++)
    {
        eruption[i].draw();
    }
    
    sunlight.enable();
    
    ofSetColor( ofColor(73, 48, 35) );
    ofSetColor( ofColor::white) ;
    ground.draw();
    ofSetColor(255);
    
    firelight.disable();
    sunlight.disable();
    for (int i=0;i<=500;i++)
    {
        ofSetColor(102,51,0);
    
        ofDrawCylinder(a[i], 30,170);
        ofSetColor(0,150,0);
        ofDrawCone(a[i].x, 0, a[i].z, 100, -230);
        ofDrawCone(a[i].x, 120, a[i].z, 50, -140);
    }
    cam.end();
    
    stringstream ss;
    
    ss
    <<"Press Any Key To Control the Snow!"<<endl;
    
    ofDrawBitmapStringHighlight(ss.str(), ofVec2f(20,20));
        

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    order++;

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
