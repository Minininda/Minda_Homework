#include "ofApp.h"
#include "ofApp.h"

int w,h;
bool f=true;
//--------------------------------------------------------------
void ofApp::setup(){
    
	
	ofBackground(0);
    bC=true;
	img.load("sea.jpg");
    img.resize( 1024, 1024);
    w = img.getWidth();
    h = img.getHeight();
    
    unsigned char* srcArray = img.getPixels().getData();
    img2.allocate(w, h, OF_IMAGE_COLOR);
    unsigned char* b = img2.getPixels().getData();
    
    
    
    redImg.allocate(w, h, OF_IMAGE_COLOR);
    greenImg.allocate(w, h, OF_IMAGE_COLOR);
    blueImg.allocate(w, h, OF_IMAGE_COLOR);
    
	
	ofVec2f size		= ofVec2f( 1024, 1024 );
	
	int cols			= 50;
	int rows			= 50;
	
	float xGap		= size.x / (cols-1);
	float yGap		= size.y / (rows-1);
	
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < cols; x++) {
			ofVec3f vertex		= ofVec2f( x * xGap, y * yGap );
			mesh.addVertex( vertex - (size * .5));
			ofVec2f texCoord;
			texCoord.x			= ofMap(vertex.x, 0, size.x, 0, img.getWidth());
			texCoord.y			= ofMap(vertex.y, 0, size.y, img.getHeight(), 0);
			mesh.addTexCoord( texCoord );
			mesh.addColor(ofColor::white);
			if (x < cols - 1 && y < rows - 1)
			{
				int index	= x + y * cols;
					
				// triangle 1
				mesh.addIndex (index);
				mesh.addIndex (index + 1);
				mesh.addIndex (index + cols);
				
				// triangle 2
				mesh.addIndex (index + 1);
				mesh.addIndex (index + 1 + cols);
				mesh.addIndex (index + cols);
			}
		}
	}
	
	
	// set up the lighting
	
	ofSetSmoothLighting(true);
	light.setPosition( 0,0,0 );
	light.setPointLight();
	light.setDiffuseColor( ofColor(255) );
    light.setAttenuation( 0.5,0,0 );

	
}


//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0;i<w;i++)
        for (int j=0;j<h;j++)
        {
            ofColor color = img.getPixels().getColor(i,j);
            //if (color.r+255>=255) color.r=255;
            //if (color.g+75>=255) color.g=255;
            //    if (color.b+20>=255) color.b=255;
            //    color.r+=255;
            //    color.g+=75;
            if (color.b+110<=255)color.b+=110;else color.b=255;
            if(color.r-10>=0)color.r-=10;
            //color.g-=1;
            img2.setColor(i,j,color);
        }
    img2.update();
    img2.resize( 1024, 1024);
	float time = ofGetElapsedTimef();
	
	for (int i=0; i < mesh.getVertices().size(); i++)
	{
		ofVec3f vert	= mesh.getVertex(i);
		float noise		= ofSignedNoise( vert.x * .004, vert.y * .004, time );
		vert.z			= noise * 50.;
		mesh.setVertex(i, vert);
	}
	float radius		= 512;
	ofVec3f center = ofVec3f (0,0,0);
	float x = cos(ofGetElapsedTimef()*0.5) * radius;
	float y = sin(ofGetElapsedTimef()*0.5) * radius;
	panCam.setPosition(x,y,200);
    panCam.lookAt(center, ofVec3f(0,0,1));
	light.setPosition( panCam.getPosition() * .5 );
}

//--------------------------------------------------------------
void ofApp::draw(){
    panCam.begin();
	light.enable();
	if (f)
    {
        img.bind();
        mesh.draw();
        img.unbind();
    }
    else
    {
        img2.bind();
        mesh.draw();
        img2.unbind();
    }
    panCam.end();
    
    stringstream ss;
    
    ss
    <<"Try To Press Any Key"<<endl;
    ofDrawBitmapStringHighlight(ss.str(), ofVec2f(20,20));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	

	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    f=!f;

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
