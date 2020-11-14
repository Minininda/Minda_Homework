#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    pos1=glm::vec2(ofGetWidth()*0.78, ofGetHeight()*0.7);
    pos2=glm::vec2(ofGetWidth()*0.02, ofGetHeight()*0.02);
    ofBackground(255);
    myImage.load("1.jpg");
    myImage.setImageType(OF_IMAGE_GRAYSCALE);
    myImage2.load("2.jpeg");
    myImage2.setImageType(OF_IMAGE_GRAYSCALE);
    
    glm::vec2 centerScreen =
        glm::vec2(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    
    
    particle1.mass = 10.0;
    particle1.pos  = pos1;
    
    particle2.mass = 10.0;
    particle2.pos  = pos2;

}

//--------------------------------------------------------------
void ofApp::update(){

    glm::vec2 mousePos = glm::vec2(ofGetMouseX(), ofGetMouseY());
    
    glm::vec2 diff1 = particle2.pos - particle1.pos;     // direction vector to target (mouse)
    glm::vec2 diff2 = particle1.pos - particle2.pos;
    
    particle1.addForce(diff1 * 0.05);               // attraction force (push in the direction of target)
    particle2.addForce(diff2 * 0.05);
    
    particle1.addDampingForce(0.1);                 // slow down the particle so it doesn't go crazy
    particle2.addDampingForce(0.1);
    
    particle1.update();
    particle2.update();
    if (glm::length(particle1.pos-particle2.pos)<=10)
    {
        pos1+=(pos2-pos1)/glm::length(pos1-pos2)*30;
        pos2+=(pos1-pos2)/glm::length(pos1-pos2)*30;
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    int imgWidth = myImage.getWidth();
    int imgHeight = myImage.getHeight();
    myImage.draw(pos1, imgWidth*0.5, imgHeight*0.5);
    myImage2.draw(pos2, imgWidth*0.5, imgHeight*0.5);
    particle1.draw();
    particle2.draw();

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
