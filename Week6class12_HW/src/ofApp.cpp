#include "ofApp.h"
#define _USE_LIVE_VIDEO

//--------------------------------------------------------------
void ofApp::setup(){

        vidGrabber.setVerbose(true);
        vidGrabber.setup(320,240);


	bLearnBakground = true;
	threshold = 80;
}

//--------------------------------------------------------------
void ofApp::update(){
	ofBackground(100,100,100);

    bool bNewFrame = false;

       vidGrabber.update();
	   bNewFrame = vidGrabber.isFrameNew();

	if (bNewFrame){
            colorImg.setFromPixels(vidGrabber.getPixels());

        grayImage = colorImg;
		if (bLearnBakground == true){
			grayBg = grayImage;
			bLearnBakground = false;
		}

		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(threshold);

		contourFinder.findContours(grayDiff, 20, (340*240)/3, 10, true);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetHexColor(0xffffff);
	colorImg.draw(0,0);
	ofFill();

    for (int i = 0; i < contourFinder.nBlobs; i++){
        contourFinder.blobs[i].draw(0,0);
		ofSetColor(255);
		if(contourFinder.blobs[i].hole){
			ofDrawBitmapString("There",
				contourFinder.blobs[i].boundingRect.getCenter().x ,
				contourFinder.blobs[i].boundingRect.getCenter().y );
		}
    }
	ofSetHexColor(0xffffff);
	

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
