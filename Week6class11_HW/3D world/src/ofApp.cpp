#include "ofApp.h"

ofPoint a[5050],b[5050],c[600500];
ofPlanePrimitive grass[505000];
ofImage texture;
int order=0;
//--------------------------------------------------------------
void ofApp::setup(){
    order++;
	ofBackground(ofColor(135,206,235));
    texture.load("timg.jpeg");
    texture.getTexture().setTextureWrap( GL_REPEAT, GL_REPEAT );

    for (int i=0;i<=800;i++)
    {
        a[i].x=ofRandom(-6000,6000);
        a[i].y=-200;
        a[i].z=ofRandom(-6000,6000);
    }
    for (int i=0;i<=500;i++)
    {
        b[i].x=ofRandom(-4000,4000);
        b[i].y=ofRandom(800,2500);
        b[i].z=ofRandom(-4000,4000);
    }
    for (int i=0;i<=60000;i++)
    {
        c[i].x=ofRandom(-3000,3000);
        c[i].y=-200;
        c[i].z=ofRandom(-3000,3000);
    }
	
	ofSetSmoothLighting(true);
	ofSetFrameRate(40);
	volcano.set(250, 400, 80, 70);
    volcano.rotateDeg(180, glm::vec3(1,0,0));
	
	auto& coneVerts = volcano.getMesh().getVertices();
    ground.enableColors();
	ground.set(10000, 10000, 1000, 1000);
    ground.rotateDeg(-90, glm::vec3(1,0,0));
    ground.move(0, -200, 0);
	gravity = ofVec3f(0,-.9,0);

	firelight.setPointLight();
	firelight.setPosition(0,200,0);
    firelight.setDiffuseColor( ofColor::white );
	sunlight.setDirectional();
	sunlight.setPosition(100,100,-400);
    sunlight.lookAt(glm::vec3(0));
	sunlight.setDiffuseColor( ofColor::white);
    
    for (int i=0;i<5000;i++)
    {
    
        grass[i].set(20, 150);
        grass[i].setPosition(c[i]);
        grass[i].rotateDeg(ofRandom(0,180),0.0,1.0,0.0);
        
    }
	
	
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
    
    ofBackgroundGradient(ofColor(255),ofColor(103,180,255));
	
	//ofEnableLighting();
	cam.begin();
	ofEnableDepthTest();
	
    
	//firelight.enable();
	
 //   ofSetColor(ofColor(239,187,101));
    
  
        
    
	for (int i=0; i<eruption.size(); i++)
	{
		eruption[i].draw();
	}
	
	//sunlight.enable();
	
    ofSetColor(ofColor(36,16,0)) ;//ofColor(70,120,10));
        ground.draw();
    ofSetColor(255);

	firelight.disable();
	sunlight.disable();
    for (int i=0;i<=800;i++)
    {
        ofSetColor(102,51,0);
    
        ofDrawCylinder(a[i], 30,170);
        ofSetColor(0,66,0);
        ofDrawCone(a[i].x, 0, a[i].z, 100, -230);
        ofDrawCone(a[i].x, 120, a[i].z, 50, -140);
    }
    for (int i=0;i<=100;i++)
    {
        ofSetColor(ofColor::white);
    
        ofDrawBox(b[i], 1000, 100, 100);
       
    }
    texture.bind();
    for (int i=0;i<5000;i++)
    {
       
        grass[i].drawWireframe();
    }
    texture.unbind();

	cam.end();
    
    
    stringstream ss;
    
    ss
    <<"Press any key to rain"<<endl;
    
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
