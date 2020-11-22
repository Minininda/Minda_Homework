#include "ofApp.h"
#include<iostream>

int or1=0,or2=3;


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    camera.begin();
    ofEnableDepthTest();
    
    ofTranslate(-500, 300);
    
    ofSetColor(0);
    float angle = ofGetElapsedTimef()+3.1415926f/2;
    ofPoint o1=ofVec3f(400,-1*(100),-100);ofPoint o2;
    if (or1==0) o2=ofVec3f(400+300*cos(angle),-1*(100+300*sin(angle)),-100);
    else
        if (or1==1) o2=ofVec3f(400+300*sin(angle+3.1415926f/2),-1*(100+300*cos(angle+3.1415926f/2)),-100);
        else o2=ofVec3f(400,-400,-100);
    if (o2.x<=100||o2.y>=-100) or1=1;
    else
         if (or1==1&&o2.x>=400) or1=2,or2=4;
    ofDrawLine(o1,o2);
    ofPoint o3=ofVec3f(450,-100,-100);
    ofPoint o4=ofVec3f(450,-400,-100);
    ofDrawLine(o3,o4);
    ofPoint o5=ofVec3f(500,-100,-100);
    ofPoint o6=ofVec3f(500,-400,-100);
    ofDrawLine(o5,o6);
    ofPoint o7=ofVec3f(550,-100,-100);
    ofPoint o8=ofVec3f(550,-400,-100);
    ofDrawLine(o7,o8);
    ofPoint o9=ofVec3f(600,-100,-100);
    ofPoint o10;
    if (or2==4) o10=ofVec3f(600+300*sin(angle+3.1415926f/2),-1*(100+300*cos(angle+3.1415926f/2)),-100);
    else
        if (or2==5) o10=ofVec3f(600+300*cos(angle),-1*(100+300*sin(angle)),-100);
        else o10=ofVec3f(600,-400,-100);
    if (o10.x>=900||o10.y>=-100) or2=5;
    else
         if (or2==5&&o10.x<=600) or2=6,or1=0;
    ofDrawLine(o9,o10);
            
    ofSetColor(169);
    ofDrawSphere(o2, 25);
    ofDrawSphere(o4, 25);
    ofDrawSphere(o6, 25);
    ofDrawSphere(o8, 25);
    ofDrawSphere(o10, 25);
    ofSetColor(102,51,0);
    ofDrawBox(glm::vec3(500,-87.5,-100), 350, 25, 25);
    
    ofDisableDepthTest();
    camera.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
