#include "ofApp.h"
#include "Ball.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    Ball b2;
    balls.push_back(b2);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0;i<balls.size();i++) balls[i].update();
    if (ofGetFrameNum() % 200 == 0)
    {
        Ball b;
        b.draw();
        balls.push_back(b);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0;i<balls.size();i++) balls[i].draw();

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
