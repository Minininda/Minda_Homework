#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	ofSetFrameRate(5);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	float l;
	l = 38;
	ofTranslate(1080 / 2 + 40, 768 / 2 + 100);
	ofRotateX(180);


	vector<ofPoint> p(1500);
	
	p[0] = l * ofVec2f(-7.5,4.5);
	p[1] = l * ofVec2f(-7.5,6.5);
	p[2] = l * ofVec2f(-6.5,3.7);
	p[3] = l * ofVec2f(-2.5,10.5);
	p[4] = l * ofVec2f(-3.3,8);
	p[5] = l * ofVec2f(1.6,9.5);
	p[6] = l * ofVec2f(1,6.7);
	p[7] = l * ofVec2f(2.2,5.2);
	p[8] = l * ofVec2f(1.7,4.7);
	p[9] = l * ofVec2f();
	p[10] = l * ofVec2f();
	p[11] = l * ofVec2f(-0.2, -0.6);
	p[12] = l * ofVec2f(-2, -.2);
	p[13] = l * ofVec2f(0, 0);
	p[14] = l * ofVec2f(-.4, 3.5);
	p[20] = l * ofVec2f(-6.5,1.4);
	p[21] = l * ofVec2f(-7.5,1.4);
	p[22] = p[2];
	p[23] = l * ofVec2f(-8,3.5);
	p[24] = p[0];
	p[30] = l * ofVec2f(-1.5,3.1);
	p[31] = l * ofVec2f(-2.5,2.9);
	p[32] = l * ofVec2f(-2.3,3.7);
	p[33] = l * ofVec2f(-3.5,3.5);
	p[34] = l * ofVec2f(.3,2.7);
	p[35] = l * ofVec2f(1.3,2.9);
	p[36] = l * ofVec2f(1.2,2.1);
	p[37] = l * ofVec2f(1.5,2.5);
	p[40] = l * ofVec2f(-3.6,5);
	p[41] = l * ofVec2f(-2.4,5.2);
	p[42] = l * ofVec2f(-.6,3.7);
	p[43] = l * ofVec2f(-.7,4.1);
	p[44] = l * ofVec2f(.15,3.8);
	p[45] = l * ofVec2f(.2,3.55);
	p[46] = l * ofVec2f(1.7,4.2);
	p[47] = l * ofVec2f(1.8,3.7);
	p[50] = l * ofVec2f(-2.25,-1.7);
	p[51] = l * ofVec2f(-1.5,-1.4);
	p[52] = l * ofVec2f(-1.3,-2.35);
	p[53] = l * ofVec2f(-.05,-2);
	p[54] = l * ofVec2f(-.25,-2.3);
	p[99] = p[20];
	p[100] = l * ofVec2f(-6.5, -0.5);
	p[101] = l * ofVec2f(-3.4,-4.2);
	p[102] = l * ofVec2f(-1.7,-4.3);
	p[103] = p[54];
	p[104] = p[53];
	p[105] = l * ofVec2f(1.2,0);
	p[106] = p[46];
	p[110] = l * ofVec2f(-1,-.6);
	p[111] = l * ofVec2f(-1.5,-1.2);
	p[112] = l * ofVec2f(-2.7,-.7);
	p[113] = l * ofVec2f(-3.2,-1.6);
	p[114] = l * ofVec2f(-.2,-.75);
	p[115] = l * ofVec2f(-.6,-1.2);
	p[116] = l * ofVec2f(.6,-1.55);
	p[117] = l * ofVec2f(.7,-2.25);
	
	
	//draw hair
	for (int i = 0; i < 7; i = i + 1)
	{
		ofSetColor(ofRandom(100),ofRandom(120,230));
		ofDrawTriangle(p[i], p[i + 1], p[i + 2]);
	}

	//draw nose
	for (int i = 11; i < 13; i = i + 1)
	{
		ofSetColor(ofRandom(30), ofRandom(40), ofRandom(200,255), ofRandom(50,190));
		ofDrawTriangle(p[i], p[i + 1], p[i + 2]);
	}

	//draw ear
	for (int i = 20; i < 23; i = i + 1)
	{
		ofSetColor(ofRandom(200,255), ofRandom(200,255), ofRandom(50), ofRandom(100, 190));
		ofDrawTriangle(p[i], p[i + 1], p[i + 2]);
	}

	//draw eyes
	for (int i = 30; i < 32; i = i + 1)
	{
		ofSetColor(ofRandom(60), ofRandom(200, 255), ofRandom(50), ofRandom(100, 190));
		ofDrawTriangle(p[i], p[i + 1], p[i + 2]);
	}
	for (int i = 34; i < 36; i = i + 1)
	{
		ofSetColor(ofRandom(200, 255), ofRandom(65), ofRandom(50), ofRandom(100, 190));
		ofDrawTriangle(p[i], p[i + 1], p[i + 2]);
	}
	for (int i = 40; i < 42; i = i + 1)
	{
		ofSetColor(ofRandom(60,70), ofRandom(80,150), ofRandom(60,70), ofRandom(200,255));
		ofDrawTriangle(p[i], p[i + 1], p[i + 2]);
	}
	for (int i = 44; i < 46; i = i + 1)
	{
		ofSetColor(ofRandom(80, 160), ofRandom(60, 70), ofRandom(60, 70), ofRandom(200, 255));
		ofDrawTriangle(p[i], p[i + 1], p[i + 2]);
	}

	//draw mouth
	for (int i = 50; i < 53; i = i + 1)
	{
		ofSetColor(ofRandom(50,100), ofRandom(40), ofRandom(200, 255), ofRandom(50, 190));
		ofDrawTriangle(p[i], p[i + 1], p[i + 2]);
	}

	ofSetColor(ofRandom(180, 200), ofRandom(200, 255), ofRandom(40), ofRandom(60, 110));
	ofDrawTriangle(p[20], p[22], p[4]);

	ofSetColor(ofRandom(70, 100), ofRandom(180, 255), ofRandom(70, 100), ofRandom(60, 80));
	ofDrawTriangle(p[2], p[6], p[4]);

	ofSetColor(ofRandom(100, 170), ofRandom(70, 130), ofRandom(160, 255), ofRandom(70, 190));
	ofDrawTriangle(p[103], p[104], p[105]);

	ofSetColor(ofRandom(180, 255), ofRandom(70, 130), ofRandom(100, 130), ofRandom(50, 90));
	ofDrawTriangle(p[106], p[104], p[105]);

	ofSetColor(ofRandom(180, 255), ofRandom(70, 130), ofRandom(100, 130), ofRandom(50, 90));
	ofDrawTriangle(p[47], p[6], p[8]);

	ofSetColor(ofRandom(100, 170), ofRandom(70, 130), ofRandom(160, 255), ofRandom(70, 90));
	ofDrawTriangle(p[4], p[6], p[8]);

	ofSetColor(ofRandom(120, 150), ofRandom(180, 255), ofRandom(70, 100), ofRandom(60, 80));
	ofDrawTriangle(p[20], p[100], p[4]);

	if (ofGetMousePressed())
	{
		ofSetColor(ofRandom(100), ofRandom(120, 230));
		ofDrawTriangle(p[100], p[101], p[102]);

		ofSetColor(ofRandom(100), ofRandom(120, 230));
		ofDrawTriangle(p[103], p[101], p[102]);

		ofSetColor(ofRandom(100), ofRandom(120, 230));
		ofDrawTriangle(p[100], p[101], p[99]);

		ofSetColor(ofRandom(100), ofRandom(120, 230));
		ofDrawTriangle(p[20], p[101], p[2]);

		for (int i = 110; i < 112; i = i + 1)
		{
			ofSetColor(ofRandom(100), ofRandom(120, 230));
			ofDrawTriangle(p[i], p[i + 1], p[i + 2]);
		}
		for (int i = 114; i < 116; i = i + 1)
		{
			ofSetColor(ofRandom(100), ofRandom(120, 230));
			ofDrawTriangle(p[i], p[i + 1], p[i + 2]);
		}
	}
	else {
		ofSetColor(ofRandom(120, 150), ofRandom(180, 255), ofRandom(70, 100), ofRandom(60, 80));
		ofDrawTriangle(p[20], p[100], p[4]);

		ofSetColor(ofRandom(70, 130), ofRandom(160, 255), ofRandom(100, 200), ofRandom(70, 190));
		ofDrawTriangle(p[100], p[101], p[102]);

		ofSetColor(ofRandom(100, 170), ofRandom(70, 130), ofRandom(160, 255), ofRandom(70, 190));
		ofDrawTriangle(p[103], p[101], p[102]);

		ofSetColor(ofRandom(180, 205), ofRandom(200, 255), ofRandom(40), ofRandom(50, 190));
		ofDrawTriangle(p[100], p[101], p[99]);

		ofSetColor(ofRandom(120, 150), ofRandom(180, 255), ofRandom(70, 100), ofRandom(60, 80));
		ofDrawTriangle(p[20], p[101], p[2]);
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
