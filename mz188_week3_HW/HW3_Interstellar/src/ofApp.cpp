#include "ofApp.h"

void ofApp::setup(){
	
	ofBackground(0);
	ofSetFrameRate(60.);
    ofSetBackgroundAuto(false);
	
    int cur=5;
	while(cur--)
		movers.push_back(Mover());
	
    glm::vec2 center = glm::vec2( ofGetWidth() *.5, ofGetHeight() * .5 );

		Attractor attractor;
		attractor.pos   = center;
		
		attractors.push_back(attractor);

}

//--------------------------------------------------------------
void ofApp::update(){
	
    for (int a=0; a<attractors.size(); a++)
	{
		for (int m=0; m<30; m++)
		{
			glm::vec2 force = attractors[a].getForce(movers[m]);
			movers[m].applyForce(force);
		}
	}
	
	for (int m=0; m<movers.size(); m++)
	{
		movers[m].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,255,255);
    ofDrawCircle(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()),2);
	ofSetColor(0, 0, 0, 20);
	ofDrawRectangle(0,0, ofGetWidth(),ofGetHeight());
	
	
	for (int a=0; a<attractors.size(); a++)
	{
		attractors[a].draw();
	}
	
	for (int m=0; m<movers.size(); m++)
	{
		movers[m].draw();
	}

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
    int cur=2;
    while(cur--)
        movers.push_back(Mover());
    glm::vec2 pos2 = glm::vec2(x, y);

    Attractor attractor;
    attractor.pos   = pos2;
    attractors.push_back(attractor);


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
